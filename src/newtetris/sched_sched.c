#include "common.h"

#define VIDEO_MSG      666
#define RSP_DONE_MSG   667
#define RDP_DONE_MSG   668
#define PRE_NMI_MSG    669

#define OS_SC_DP        0x0001
#define OS_SC_SP        0x0002
#define OS_SC_YIELD     0x0010
#define OS_SC_YIELDED   0x0020

#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)

static void __scMain(void *);
static void __scHandleRetrace(OSSched *);
static void __scHandleRSP(OSSched *);
static void __scHandleRDP(OSSched *);
static void __scAppendList(OSSched *, OSScTask *);
static OSScTask *__scTaskReady(OSScTask *);
static s32 __scTaskComplete(OSSched *, OSScTask *);
static void __scExec(OSSched *, OSScTask *, OSScTask *);
static void __scYield(OSSched *);
static s32 __scSchedule(OSSched *, OSScTask **, OSScTask **, s32);

static u8 D_800D0180 = TRUE;

void osCreateScheduler(OSSched *sc, void *stack, OSPri priority, u8 mode, u8 numFields) {
  s32 unused;

  sc->curRSPTask = NULL;
  sc->curRDPTask = NULL;
  sc->clientList = NULL;
  sc->frameCount = 0;
  sc->audioListHead = NULL;
  sc->gfxListHead = NULL;
  sc->audioListTail = NULL;
  sc->gfxListTail = NULL;
  sc->retraceMsg.type = OS_SC_RETRACE_MSG;
  sc->prenmiMsg.type = OS_SC_PRE_NMI_MSG;

  osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);
  osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, OS_SC_MAX_MESGS);

  osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg)RSP_DONE_MSG);
  osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg)RDP_DONE_MSG);

  osViSetEvent(&sc->interruptQ, (OSMesg)VIDEO_MSG, numFields);

  osCreateThread(&sc->thread, 4, __scMain, sc, stack, priority);
  osStartThread(&sc->thread);

  frametime_clear();
  D_800D0180 = TRUE;
}

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ) {
  OSIntMask mask;

  mask = osSetIntMask(OS_IM_NONE);

  c->msgQ = msgQ;
  c->next = sc->clientList;
  sc->clientList = c;

  osSetIntMask(mask);
}

void osScRemoveClient(OSSched *sc, OSScClient *c) {
  OSScClient *client = sc->clientList;
  OSScClient *prev = NULL;
  OSIntMask mask;

  mask = osSetIntMask(OS_IM_NONE);

  while (client != NULL) {
    if (client == c) {
      if (prev != NULL) {
        prev->next = c->next;
      } else {
        sc->clientList = c->next;
      }
      break;
    }

    prev = client;
    client = client->next;
  }

  osSetIntMask(mask);
}

OSMesgQueue *osScGetCmdQ(OSSched *sc) {
  return &sc->cmdQ;
}

static void __scMain(void *arg) {
  OSMesg msg;
  OSSched *sc = arg;
  OSScClient *client;
  s32 sp28 = 0x802C6598;  // what is this?
  static s32 count = 0;

  while (TRUE) {
    osRecvMesg(&sc->interruptQ, (OSMesg *)&msg, OS_MESG_BLOCK);
    if (D_800D0180) {
      switch ((s32) msg) {
      case VIDEO_MSG:
        __scHandleRetrace(sc);
        break;
      case RSP_DONE_MSG:
        __scHandleRSP(sc);
        break;
      case RDP_DONE_MSG:
        __scHandleRDP(sc);
        break;
      case PRE_NMI_MSG:
        func_80061198();

        for (client = sc->clientList; client != NULL; client = client->next) {
          osSendMesg(client->msgQ, (OSMesg)&sc->prenmiMsg, OS_MESG_NOBLOCK);
        }

        D_800D0180 = FALSE;
        break;
      }
    }
  }
}

static s32 dp_busy = 0;
static s32 dpCount = 0;

static void __scHandleRetrace(OSSched *sc) {
  OSScTask *rspTask;
  OSScClient *client;
  s32 state;
  OSScTask *sp = NULL;
  OSScTask *dp = NULL;

  sc->frameCount++;

  while (osRecvMesg(&sc->cmdQ, (OSMesg *)&rspTask, OS_MESG_NOBLOCK) != -1) {
    __scAppendList(sc, rspTask);
  }

  if ((sc->doAudio != 0) && (sc->curRSPTask != NULL)) {
    __scYield(sc);
  } else {
    state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
    if (__scSchedule(sc, &sp, &dp, state) != state) {
      __scExec(sc, sp, dp);
    }
  }

  for(client = sc->clientList; client != NULL; client = client->next) {
    osSendMesg(client->msgQ, (OSMesg)&sc->retraceMsg, OS_MESG_NOBLOCK);
  }
}

static void __scHandleRSP(OSSched *sc) {
  OSScTask *t;
  OSScTask *sp = NULL;
  OSScTask *dp = NULL;
  s32 state;

  t = sc->curRSPTask;
  sc->curRSPTask = NULL;
  if ((t->state & OS_SC_YIELD) && (osSpTaskYielded(&t->list) != 0)) {
    t->state |= OS_SC_YIELDED;

#ifndef _FINALROM
    t->totalTime += osGetTime() - t->startTime;
#endif

    if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
      t->next = sc->gfxListHead;
      sc->gfxListHead = t;
      if (sc->gfxListTail == NULL) {
        sc->gfxListTail = t;
      }
    }
  } else {
    t->state &= ~OS_SC_NEEDS_RSP;
    __scTaskComplete(sc, t);
  }

  state = ((sc->curRSPTask == NULL) << 1) | (sc->curRDPTask == NULL);
  if (__scSchedule(sc, &sp, &dp, state) != state) {
    __scExec(sc, sp, dp);
  }
}

static void __scHandleRDP(OSSched *sc) {
  OSScTask *t;
  OSScTask *sp = NULL;
  OSScTask *dp = NULL;
  s32 state;

  t = sc->curRDPTask;
  sc->curRDPTask = NULL;

  t->state &= ~OS_SC_NEEDS_RDP;

  __scTaskComplete(sc, t);

  state = ((sc->curRSPTask == NULL) << 1) | (sc->curRDPTask == NULL);
  if (__scSchedule(sc, &sp, &dp, state) != state) {
    __scExec(sc, sp, dp);
  }
}

static OSScTask *__scTaskReady(OSScTask *t) {
  void *a;
  void *b;

  if (t != NULL) {
    if ((a = osViGetCurrentFramebuffer()) != (b = osViGetNextFramebuffer())) {
      return NULL;
    }

    return t;
  }

  return NULL;
}

static u8 D_800D0190 = 0;

static s32 __scTaskComplete(OSSched *sc, OSScTask *t) {
  s32 rv;
  static s32 firsttime = 1;

  if ((t->state & OS_SC_RCP_MASK) == 0) {

#ifndef _FINALROM
    t->totalTime += osGetTime() - t->startTime;
#endif

    rv = osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);

    if (t->list.t.type == M_GFXTASK) {
      D_800D0190++;
      if ((t->flags & OS_SC_SWAPBUFFER) && (t->flags & OS_SC_LAST_TASK)) {
        if (firsttime != 0) {
          firsttime = 0;
        }
        osViSwapBuffer(t->framebuffer);
      }
    }
    return 1;
  }

  return 0;
}

static void __scAppendList(OSSched *sc, OSScTask *t) {
  s32 type = t->list.t.type;

  if (type == M_AUDTASK) {
    if (sc->audioListTail != NULL) {
      sc->audioListTail->next = t;
    } else {
      sc->audioListHead = t;
    }

    sc->audioListTail = t;
    sc->doAudio = 1;
  } else {
    if (sc->gfxListTail != NULL) {
      sc->gfxListTail->next = t;
    } else {
      sc->gfxListHead = t;
    }

    sc->gfxListTail = t;
  }

  t->next = NULL;
  t->state = t->flags & OS_SC_RCP_MASK;
}

static void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp) {
  s32 rv;

  if (sp != NULL) {
    if (sp->list.t.type == M_AUDTASK) {
      osWritebackDCacheAll();
    }

    sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);

#ifndef _FINALROM
    sp->startTime = osGetTime();
#endif

    osSpTaskLoad(&sp->list);
    osSpTaskStartGo(&sp->list);
    sc->curRSPTask = sp;
    if (sp == dp) {
      sc->curRDPTask = dp;
    }
  }

  if ((dp != NULL) && (dp != sp)) {
    rv = osDpSetNextBuffer(dp->list.t.output_buff, *dp->list.t.output_buff_size);

    dp_busy = 1;
    dpCount = 0;

    sc->curRDPTask = dp;
  }
}

static void __scYield(OSSched *sc) {
  if (sc->curRSPTask->list.t.type == M_GFXTASK) {
    sc->curRSPTask->state |= OS_SC_YIELD;
    osSpTaskYield();
  }
}

static s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP) {
  s32 avail = availRCP;
  OSScTask *gfx = sc->gfxListHead;
  OSScTask *audio = sc->audioListHead;

  if ((sc->doAudio != 0) && (avail & OS_SC_SP)) {
    if ((gfx != NULL) && (gfx->flags & OS_SC_PARALLEL_TASK)) {
      *sp = gfx;
      avail &= ~OS_SC_SP;
    } else {
      *sp = audio;
      avail &= ~OS_SC_SP;
      sc->doAudio = 0;
      sc->audioListHead = sc->audioListHead->next;
      if (sc->audioListHead == NULL) {
        sc->audioListTail = NULL;
      }
    }
  } else {
    if (__scTaskReady(gfx) != NULL) {
      switch (gfx->flags & OS_SC_TYPE_MASK) {
      case OS_SC_XBUS:
        if (gfx->state & OS_SC_YIELDED) {
          if (avail & OS_SC_SP) {
            *sp = gfx;
            avail &= ~OS_SC_SP;
            if (gfx->state & OS_SC_DP) {
              *dp = gfx;
              avail &= ~OS_SC_DP;
            }

            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == NULL) {
              sc->gfxListTail = NULL;
            }
          }
        } else {
          if (avail == (OS_SC_SP | OS_SC_DP)) {
            *sp = *dp = gfx;
            avail &= ~(OS_SC_SP | OS_SC_DP);
            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == NULL) {
              sc->gfxListTail = NULL;
            }
          }
        }
        break;
      case OS_SC_DRAM:
      case OS_SC_DP_DRAM:
      case OS_SC_DP_XBUS:
        if (gfx->state & OS_SC_SP) {
          if (avail & OS_SC_SP) {
            *sp = gfx;
            avail &= ~OS_SC_SP;
          }
        } else if (gfx->state & OS_SC_DP) {
          if (avail & OS_SC_DP) {
            *dp = gfx;
            avail &= ~OS_SC_DP;
            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == NULL) {
              sc->gfxListTail = NULL;
            }
          }
        }
        break;
      case OS_SC_SP_DRAM:
      case OS_SC_SP_XBUS:
      default:
        break;
      }
    }
  }

  if (avail != availRCP) {
    avail = __scSchedule(sc, sp, dp, avail);
  }

  return avail;
}
