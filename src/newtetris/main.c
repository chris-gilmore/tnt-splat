#include "common.h"

extern u16 draw_buffer;
extern OSMesg D_80120A70;
extern OSMesg D_80122010;

////////////////////////////////////////

static u32 D_800CFE30 = 0; // unused
u8 D_800CFE34 = FALSE;
static u32 D_800CFE38 = 0;
static u32 D_800CFE3C = 0;
static u32 D_800CFE40 = 0;
static OSThread thread_1;
static OSThread idleThread;
static OSThread thread_2;
u64 bootStack[STACKSIZE/sizeof(u64)];
static u64 thread_1_Stack[STACKSIZE/sizeof(u64)];
static u64 idleThreadStack[STACKSIZE/sizeof(u64)];
static u64 thread_2_Stack[STACKSIZE/sizeof(u64)];
static OSMesg D_8010B6D0[256];
static OSMesgQueue D_8010BAD0;
static OSMesgQueue D_8010BAE8;
static OSMesg D_8010BB00[1];
OSMesgQueue D_8010BB08;
static OSMesg D_8010BB20[32];
OSSched scheduler;
static u64 schedulerStack[STACKSIZE/sizeof(u64)];
static OSScClient D_8010DE28;
static ControllerQueue *controller_queues[4];
SuperThread superThread;
static OSMesg D_80110458[64];
static OSMesgQueue D_80110558;

static void main_infinite_loop_at_end(void);
static void idle(void *);
static void main_infinite_loop_at_end_3(void *);
static void main_maybe_audio_related(void);
static void main_another_but_diff_400x300(void);

static void main_infinite_loop_at_end(void) {
  OSMesg msg = NULL;
  OSIntMask mask;

  D_800CFE34 = FALSE;
  osRecvMesg(&D_80110558, &msg, OS_MESG_BLOCK);
  mask = osSetIntMask(OS_IM_VI);
  D_800CFE34 = TRUE;
  func_80061198();
  osSetIntMask(mask);
  for (;;);
}

void boot(void *arg) {
  osInitialize();
  osCreateMesgQueue(&D_80110558, D_80110458, 64);
  osSetEventMesg(OS_EVENT_PRENMI, &D_80110558, (OSMesg)777);
  func_80061134(SCREEN_WD, SCREEN_HT);
  osCreateThread(&idleThread, 1, idle, arg, idleThreadStack + STACKSIZE/sizeof(u64), 10);
  osStartThread(&idleThread);
}

static void idle(void *arg) {
  osCreateThread(&thread_2, 50, (void (*)(void *))main_infinite_loop_at_end, NULL, thread_2_Stack + STACKSIZE/sizeof(u64), OS_PRIORITY_APPMAX);
  osStartThread(&thread_2);
  osCreatePiManager(OS_PRIORITY_PIMGR, &D_8010BAD0, D_8010B6D0, 256);
  func_800611E0();
  if (osTvType == OS_TV_NTSC) {
    func_80060D10(osViModeNtscLan1);
  }
  if (osTvType == OS_TV_MPAL) {
    func_80060D10(osViModeMpalLan1);
  }
  if (osTvType == OS_TV_PAL) {
    func_80060D10(osViModePalLan1);
  }
  osCreateViManager(OS_PRIORITY_VIMGR);
  func_80061134(SCREEN_WD, SCREEN_HT);
  if (osTvType == OS_TV_NTSC) {
    osCreateScheduler(&scheduler, schedulerStack + STACKSIZE/sizeof(u64), 13, OS_VI_NTSC_LAN1, 1);
  }
  if (osTvType == OS_TV_MPAL) {
    osCreateScheduler(&scheduler, schedulerStack + STACKSIZE/sizeof(u64), 13, OS_VI_MPAL_LAN1, 1);
  }
  if (osTvType == OS_TV_PAL) {
    osCreateScheduler(&scheduler, schedulerStack + STACKSIZE/sizeof(u64), 13, OS_VI_PAL_LAN1, 1);
  }
  func_80084630(NULL, cfb[0], 0, 0);
  osCreateThread(&thread_1, 6, main_infinite_loop_at_end_3, arg, thread_1_Stack + STACKSIZE/sizeof(u64), 10);
  osStartThread(&thread_1);
  osSetThreadPri(NULL, OS_PRIORITY_IDLE);
  for(;;);
}

static void main_infinite_loop_at_end_3(void *arg) {
  OSMesg msg = NULL;
  u32 i;

  func_800AC06C(20, 5);
  main_another_but_diff_400x300();
  func_800AC0F8();
  load_from_sram(FALSE);
  for (i = 0; i < main_TEXT_END - main_TEXT_START; i++) {
    D_800CFE3C += main_TEXT_START[i];
  }
  func_80060E30();
  while (TRUE) {
    osRecvMesg(&D_8010BB08, &msg, OS_MESG_BLOCK);
    switch (*(s16 *)msg) {
    case 1:
      if (D_800CFE38 < 2) {
        has_rounds_and_floors_large_liner();
        D_800CFE38 += 1;
        draw_buffer ^= 1;
        D_800CFE40 = 0;
      }
      break;
    case 2:
      D_800CFEEC += 1;
      D_800CFE38 -= 1;
      break;
    case 4:
      func_80061198();
      Audio2_GFXDone_SendStopMessage(&D_801235B0);
      Audio2_8008780c_sixliner_v1(&D_80122010);
      Audio2_8008780c_sixliner_v1(&D_80120A70);
      D_800CFE38 += 999999;
      break;
    }
  }
}

static void main_maybe_audio_related(void) {
  OSMesg msg = NULL;

  osRecvMesg(&D_8010BB08, &msg, OS_MESG_BLOCK);
  switch (*(s16 *)msg) {
  case 2:
    D_800CFEEC += 1;
    D_800CFE38 -= 1;
    break;
  case 4:
    D_800CFE38 += 999999;
    func_80061198();
    Audio2_GFXDone_SendStopMessage(&D_801235B0);
    Audio2_8008780c_sixliner_v1(&D_80122010);
    Audio2_8008780c_sixliner_v1(&D_80120A70);
    break;
  }
}

void main_8004A34C_threeliner(void) {
  while (D_800CFEF0 > D_800CFEEC) {
    main_maybe_audio_related();
  } 
}

static void main_another_but_diff_400x300(void) {
  s16 i;

  osCreateMesgQueue(&D_8010BAE8, D_8010BB00, 1);
  osCreateMesgQueue(&D_8010BB08, D_8010BB20, 32);
  osScAddClient(&scheduler, &D_8010DE28, &D_8010BB08);
  screen_1_width  = SCREEN_WD;
  screen_1_height = SCREEN_HT;
  screen_3_width  = 0;
  screen_3_height = 0;
  screen_4_width  = SCREEN_WD;
  screen_4_height = SCREEN_HT;
  func_8006110C(SCREEN_WD, SCREEN_HT);
  n64HeapInit(main_BSS_END, audioheap_BASE - main_BSS_END);
  func_800A9E44(&D_A8190, &D_ADAE0);
  FUN_80053538_fiveliner();
  FUN_80053500_fiveliner();
  inits_bunch_of_stuff_q_allocs_heap();
  for (i = 0; i < 4; i++) {
    g_PV_ptr = &g_PV_arr[i];
    FUN_069580_800A34A8_tenliner_allocs_heap(&g_PV_ptr->contQ);  // init contpad buttons and something else (8 * 300)
    PV_set_controller_no(i);
  }
  for (i = 0; i < 4; i++) {
    controller_queues[i] = &g_PV_arr[i].contQ;
  }
  createSuperThread(&superThread, &scheduler, controller_queues, 4);
  FUN_001500_motorInit(&superThread);
  FUN_001050_Create_and_Start_ControllerThread(&superThread, 5, 11);
  Audio_InitAudio();
}
