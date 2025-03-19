#include "common.h"

s32 g_eepromSize;
static u8 D_800E1F14[4];  // gbpak related
static SuperThread *superThread_ptr;

static u8 PWM_Modulate = FALSE;
static u8 PWM_Width = 0;
static u8 PWM_Pulse = 0;

static void   FUN_001050_ControllerThread(void *);

s16 createSuperThread(SuperThread *superThd, OSSched *sched, ControllerQueue **controller_queues, u8 maxControllers) {
  s16 ret;

  superThd->sched = sched;
  superThd->unk252C = 5;  // is this OS_EVENT_SI?  or is it an OSScMsg type mask (1 | 4)?
  superThd->controller_queues = controller_queues;
  superThd->maxControllers = maxControllers;  // set to 4
  superThd->unk25AE = 0;  // (bitfield) eeprom and controller motor init flags
  osCreateMesgQueue(&superThd->schedMsgQ, superThd->schedMsgBuf, 8);
  osCreateMesgQueue(&superThd->motorMsgQ, superThd->motorMsgBuf, 8);
  osCreateMesgQueue(&superThd->eepromMsgQ, superThd->eepromMsgBuf, 8);
  osCreateMesgQueue(&superThd->cpakMsgQ, superThd->cpakMsgBuf, 8);
  osCreateMesgQueue(&superThd->controllerMsgQ, superThd->controllerMsgBuf, 8);
  osCreateMesgQueue(&superThd->gbpakMsgQ, superThd->gbpakMsgBuf, 8);
  osCreateMesgQueue(&superThd->synchMsgQ, superThd->synchMsgBuf, 1);
  osCreateMesgQueue(&superThd->siMsgQ, superThd->siMsgBuf, 8);
  osSetEventMesg(OS_EVENT_SI, &superThd->siMsgQ, superThd->siMsgBuf);
  ret = osContInit(&superThd->siMsgQ, &superThd->bitpattern, superThd->contstat_arr);
  return ret;
}

s32 FUN_001050_checkEepromSize_and_AllocHeap(SuperThread *superThd) {
  s32 sp24;

  sp24 = osEepromProbe(&superThd->siMsgQ);
  if (sp24 != 0) {
    switch (sp24) {
    case EEPROM_TYPE_4K:
      g_eepromSize = 0x200;
      break;
    case EEPROM_TYPE_16K:
      g_eepromSize = 0x800;
      break;
    }
    superThd->eepCache = (u8 *) n64HeapAlloc(g_eepromSize);
    superThd->eepDirtyBlks = (u8 *) n64HeapAlloc(g_eepromSize / EEPROM_BLOCK_SIZE);
    superThd->unk25AE |= 0x10;
    for (sp24 = 0; sp24 < g_eepromSize; sp24++) {
      superThd->eepCache[sp24] = 0;
    }
    for (sp24 = 0; sp24 < g_eepromSize / EEPROM_BLOCK_SIZE; sp24++) {
      superThd->eepDirtyBlks[sp24] = 0;
    }
  }
  return superThd->unk25AE & ~0x10;
}

void FUN_001050_eepromWrite(SuperThread *superThd, u8 *data) {
  s32 sp1C;
  s32 sp18;

  for (sp1C = 0; sp1C < g_eepromSize / EEPROM_BLOCK_SIZE; sp1C++) {
    for (sp18 = 0; sp18 < 8; sp18++) {
      if (data[(sp1C * 8) + sp18] != superThd->eepCache[(sp1C * 8) + sp18]) {
        superThd->eepDirtyBlks[sp1C] = 1;
        break;
      }
    }
  }
  for (sp1C = 0; sp1C < g_eepromSize; sp1C++) {
    superThd->eepCache[sp1C] = data[sp1C];
  }
  if (superThd->unk25AE & 0x10) {
    superThd->eepRWBuf = data;
    superThd->eepromMsg.cmd = 1;
    superThd->eepWrite = 1;
    osSendMesg(&superThd->eepromMsgQ, (OSMesg *)&superThd->eepromMsg, OS_MESG_NOBLOCK);
  }
}

void FUN_001050_eepromRead(SuperThread *superThd, u8 *data) {
  if (superThd->unk25AE & 0x10) {
    superThd->eepRWBuf = data;
    superThd->eepromMsg.cmd = 2;
    superThd->eepRead = 1;
    osSendMesg(&superThd->eepromMsgQ, (OSMesg *)&superThd->eepromMsg, OS_MESG_NOBLOCK);
  }
}

void FUN_001500_motorInit(SuperThread *superThd) {
  s32 ret;
  u8 i;

  for (i = 0; i < 4; i++) {
    if ((superThd->bitpattern >> i) & 1) {
      if ((superThd->contstat_arr[i].type & CONT_JOYPORT) != 0 && (superThd->contstat_arr[i].type & CONT_JOYPORT) != 0) {  // (bug?) was second clause supposed to have been ".status & CONT_CARD_ON"?
        ret = osPfsInitPak(&superThd->siMsgQ, &superThd->pfs_arr[i], i);
        if (ret == PFS_ERR_ID_FATAL || ret == PFS_ERR_DEVICE) {
          ret = osMotorInit(&superThd->siMsgQ, &superThd->pfs_arr[i], i);
          if (ret == 0) {
            superThd->unk25AE |= 1 << i;
            rmonPrintf("Init Motor: %d Flags: %x\n", i, superThd->unk25AE & 0xF);
          }
        }
      }
    }
  }
}

s32 FUN_001050_8003b3e4_motor_sendrecvmsg_3(SuperThread *superThd, s32 cont_no) {
  superThd->motorMsg.cmd = 3;
  superThd->motorMsg.cont_no = cont_no;
  superThd->motorMsg.unk8 = 0;
  superThd->motorMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->motorMsgQ, (OSMesg *)&superThd->motorMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->motorMsg.unk8;
}

void FUN_001050_8003b468_motor_sendmsg_0(SuperThread *superThd, s32 cont_no) {
  if (superThd->unk25AE & 0xF) {
    superThd->motorMsg.cmd = 0;
    superThd->motorMsg.cont_no = cont_no;
    superThd->motorMsg.unk8 = 0;
    osSendMesg(&superThd->motorMsgQ, (OSMesg *)&superThd->motorMsg, OS_MESG_NOBLOCK);
  }
}

void FUN_001050_8003b4d4_motor_sendmsg_1(SuperThread *superThd, s32 cont_no) {
  if (superThd->unk25AE & 0xF) {
    superThd->motorMsg.cmd = 1;
    superThd->motorMsg.cont_no = cont_no;
    superThd->motorMsg.unk8 = 0;
    osSendMesg(&superThd->motorMsgQ, (OSMesg *)&superThd->motorMsg, OS_MESG_NOBLOCK);
  }
}

void FUN_001050_8003b544_motor_sendmsg_2(SuperThread *superThd, s32 cont_no, s32 arg2, u8 *arg3) {
  if (superThd->unk25AE & 0xF) {
    superThd->motorMsg.cmd = 2;
    superThd->motorMsg.cont_no = cont_no;
    superThd->motorMsg.unk8 = arg2;
    superThd->motorMsg.unkC = arg3;
    osSendMesg(&superThd->motorMsgQ, (OSMesg *)&superThd->motorMsg, OS_MESG_BLOCK);
  }
}

void FUN_001050_8003b5d0_controller_sendrecvmsg(SuperThread *superThd) {
  superThd->controllerMsg.cmd = 0;
  superThd->controllerMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->controllerMsg.contstat_ptr = superThd->contstat_arr;
  osSendMesg(&superThd->controllerMsgQ, (OSMesg *)&superThd->controllerMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
}

u16 FUN_001050_getControllerType(SuperThread *superThd, u8 cont_no) {
  return superThd->contstat_arr[cont_no].type;
}

u8 FUN_001050_getControllerStatus(SuperThread *superThd, u8 cont_no) {
  return superThd->contstat_arr[cont_no].status;
}

u8 FUN_001050_getControllerErrNo(SuperThread *superThd, u8 cont_no) {
  return superThd->contstat_arr[cont_no].errno;
}

s32 FUN_001050_cpakInit(SuperThread *superThd, s32 cont_no) {
  superThd->cpakMsg.cmd = 0;
  superThd->cpakMsg.cont_no = cont_no;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakRead(SuperThread *superThd, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, u8 cont_no) {
  superThd->cpakMsg.cmd = 1;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.file_descriptor = arg1;
  superThd->cpakMsg.tmpval = arg2;
  superThd->cpakMsg.data_buffer = arg4;
  superThd->cpakMsg.offset = arg3;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakWrite(SuperThread *superThd, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, u8 cont_no) {
  superThd->cpakMsg.cmd = 2;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.file_descriptor = arg1;
  superThd->cpakMsg.tmpval = arg2;
  superThd->cpakMsg.data_buffer = arg4;
  superThd->cpakMsg.offset = arg3;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakAllocFile(SuperThread *superThd, OSPfsState *arg1, u8 cont_no) {
  superThd->cpakMsg.cmd = 3;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakFindFile(SuperThread *superThd, OSPfsState *arg1, u8 cont_no) {
  superThd->cpakMsg.cmd = 4;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakDeleteFile(SuperThread *superThd, OSPfsState *arg1, u8 cont_no) {
  superThd->cpakMsg.cmd = 5;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakNumFiles(SuperThread *superThd, u8 cont_no) {
  superThd->cpakMsg.cmd = 6;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakFileState(SuperThread *superThd, OSPfsState *arg1, u8 arg2, u8 cont_no) {
  superThd->cpakMsg.cmd = 7;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  superThd->cpakMsg.file_descriptor = arg2;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakRepairId(SuperThread *superThd, OSPfsState *arg1, u8 cont_no) {
  superThd->cpakMsg.cmd = 8;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_cpakFreeBlocks(SuperThread *superThd, OSPfsState * arg1, u8 cont_no) {
  superThd->cpakMsg.cmd = 9;
  superThd->cpakMsg.cont_no = cont_no;
  superThd->cpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  superThd->cpakMsg.pfsState_ptr = arg1;
  osSendMesg(&superThd->cpakMsgQ, (OSMesg *)&superThd->cpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->cpakMsg.tmpval;
}

s32 FUN_001050_gbpakInit(SuperThread *superThd, u8 cont_no) {
  superThd->gbpakMsg.cmd = 0;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

s32 FUN_001050_gbpakReadId(SuperThread *superThd, u8 cont_no) {
  superThd->gbpakMsg.cmd = 1;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

s32 FUN_001050_gbpakReadWrite_a(SuperThread *superThd, u8 cont_no) {
  superThd->gbpakMsg.cmd = 2;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

s32 FUN_001050_gbpakReadWrite_b(SuperThread *superThd, u8 cont_no) {
  superThd->gbpakMsg.cmd = 4;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

s32 FUN_001050_gbpakReadWrite_c(SuperThread *superThd, u8 cont_no, u32 arg2, u8 *arg3, s32 arg4) {
  superThd->gbpakMsg.cmd = 3;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.unkC = arg3;
  superThd->gbpakMsg.unk8 = arg2;
  superThd->gbpakMsg.tmpval = arg4;
  superThd->gbpakMsg.status = OS_READ;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

s32 FUN_001050_gbpakReadWrite_d(SuperThread *superThd, u8 cont_no, u32 arg2, u8 *arg3, s32 arg4) {
  superThd->gbpakMsg.cmd = 3;
  superThd->gbpakMsg.cont_no = cont_no;
  superThd->gbpakMsg.unkC = arg3;
  superThd->gbpakMsg.unk8 = arg2;
  superThd->gbpakMsg.tmpval = arg4;
  superThd->gbpakMsg.status = OS_WRITE;
  superThd->gbpakMsg.synchMsgQ_ptr = &superThd->synchMsgQ;
  osSendMesg(&superThd->gbpakMsgQ, (OSMesg *)&superThd->gbpakMsg, OS_MESG_NOBLOCK);
  osRecvMesg(&superThd->synchMsgQ, NULL, OS_MESG_BLOCK);
  return superThd->gbpakMsg.tmpval;
}

static void FUN_001050_ControllerThread(void *arg) {
  OSContPad *contpad_ptr;
  s16 spA2                         = 0;
  OSScMsg *scMsg_ptr               = NULL;
  MotorMsg *motorMsg_ptr           = NULL;
  EepromMsg *eepromMsg_ptr         = NULL;
  ControllerMsg *controllerMsg_ptr = NULL;
  CpakMsg *cpakMsg_ptr             = NULL;
  GbpakMsg *gbpakMsg_ptr           = NULL;
  u8 sp87                          = TRUE;
  s16 sp84;
  MotorMsg savedMotorMsg;
  s32 sp6C;  // unused
  s32 sp68;
  s32 sp64;
  s32 sp60;
  s32 sp5C;
  s32 sp58;
  u8 sp38[BLOCKSIZE];
  u8 sp37;

  superThread_ptr = arg;
  osScAddClient(superThread_ptr->sched, &superThread_ptr->client, &superThread_ptr->schedMsgQ);

  for (;;) {
    osRecvMesg(&superThread_ptr->schedMsgQ, (OSMesg *)&scMsg_ptr, OS_MESG_BLOCK);
    switch (scMsg_ptr->type) {
    case OS_SC_RETRACE_MSG:
      if (sp87) {
        sp87 = FALSE;

        if (osContStartReadData(&superThread_ptr->siMsgQ) == 0) {
          osRecvMesg(&superThread_ptr->siMsgQ, superThread_ptr->siMsgBuf, OS_MESG_BLOCK);
          for (sp84 = 0; sp84 < superThread_ptr->maxControllers; sp84++) {
            osContGetReadData(superThread_ptr->contpad_arr);
            contpad_ptr = &superThread_ptr->contpad_arr[sp84];
            if (&superThread_ptr->controller_queues[sp84] != NULL) {  // (bug?) why ampersand?
              FUN_069580_800A3300_nineliner_mod300(superThread_ptr->controller_queues[sp84], contpad_ptr);
            }
          }
        }

        if ((osRecvMesg(&superThread_ptr->controllerMsgQ, (OSMesg *)&controllerMsg_ptr, OS_MESG_NOBLOCK) == 0)) {
          switch (controllerMsg_ptr->cmd) {
          case 0:
            osContStartQuery(&superThread_ptr->siMsgQ);
            osRecvMesg(&superThread_ptr->siMsgQ, NULL, OS_MESG_BLOCK);
            osContGetQuery(controllerMsg_ptr->contstat_ptr);
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          }
        }

        if (osRecvMesg(&superThread_ptr->motorMsgQ, (OSMesg *)&motorMsg_ptr, OS_MESG_NOBLOCK) == 0) {
          switch (motorMsg_ptr->cmd) {
          case 3:
            motorMsg_ptr->unk8 = osMotorInit(&superThread_ptr->siMsgQ, &superThread_ptr->pfs_arr[motorMsg_ptr->cont_no], motorMsg_ptr->cont_no);
            if (motorMsg_ptr->unk8 != 0) {
              motorMsg_ptr->unk8 = ((motorMsg_ptr->unk8 << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 1:
            sp84 = osMotorStart(&superThread_ptr->pfs_arr[motorMsg_ptr->cont_no]);
            sp84 = osMotorStart(&superThread_ptr->pfs_arr[motorMsg_ptr->cont_no]);
            PWM_Modulate = TRUE;
            break;
          case 0:
            PWM_Modulate = FALSE;
            sp84 = osMotorStop(&superThread_ptr->pfs_arr[motorMsg_ptr->cont_no]);
            sp84 = osMotorStop(&superThread_ptr->pfs_arr[motorMsg_ptr->cont_no]);
            break;
          case 2:
            savedMotorMsg.cont_no = motorMsg_ptr->cont_no;
            savedMotorMsg.unk8 = motorMsg_ptr->unk8;
            savedMotorMsg.unkC = motorMsg_ptr->unkC;
            PWM_Modulate = TRUE;
            PWM_Pulse = 0;
            PWM_Width = 0;
            break;
          }
        }

        if (PWM_Modulate) {
          if (PWM_Width == 0) {
            PWM_Width = savedMotorMsg.unkC[PWM_Pulse++];
            if (savedMotorMsg.unk8 != 0) {
              if (PWM_Pulse > savedMotorMsg.unk8) {
                PWM_Pulse = 0;
                PWM_Width = savedMotorMsg.unkC[PWM_Pulse++];
              }
            } else {
              if (PWM_Width == 0) {
                if (savedMotorMsg.unkC[PWM_Pulse] == 0) {
                  PWM_Modulate = FALSE;
                  osMotorStop(&superThread_ptr->pfs_arr[motorMsg_ptr->cont_no]);  // (bug?) was this supposed to have been "savedMotorMsg.cont_no"?
                }
                PWM_Pulse = 0;
                PWM_Width = savedMotorMsg.unkC[PWM_Pulse++];
              }
            }
            if (PWM_Modulate) {
              if (PWM_Pulse % 2) {
                osMotorStart(&superThread_ptr->pfs_arr[savedMotorMsg.cont_no]);
                osMotorStart(&superThread_ptr->pfs_arr[savedMotorMsg.cont_no]);
              } else {
                osMotorStop(&superThread_ptr->pfs_arr[savedMotorMsg.cont_no]);
                osMotorStop(&superThread_ptr->pfs_arr[savedMotorMsg.cont_no]);
              }
            }
          }
          PWM_Width--;
        }

        if (osRecvMesg(&superThread_ptr->eepromMsgQ, (OSMesg *)&eepromMsg_ptr, OS_MESG_NOBLOCK) == 0) {
          switch (eepromMsg_ptr->cmd) {
          case 1:
            for (sp68 = 0; sp68 < g_eepromSize / EEPROM_BLOCK_SIZE; sp68++) {
              if (superThread_ptr->eepDirtyBlks[sp68] == 1) {
                superThread_ptr->eepDirtyBlks[sp68] = 0;
                if (osEepromWrite(&superThread_ptr->siMsgQ, sp68, &superThread_ptr->eepRWBuf[sp68 * 8]) != 0) {
                  break;
                }
                osRecvMesg(&superThread_ptr->siMsgQ, (OSMesg *)&eepromMsg_ptr, OS_MESG_BLOCK);
              }
            }
            superThread_ptr->eepWrite = 0;
            break;
          case 2:
            for (sp68 = 0; sp68 < g_eepromSize / EEPROM_BLOCK_SIZE; sp68++) {
              if (osEepromRead(&superThread_ptr->siMsgQ, sp68, &superThread_ptr->eepRWBuf[sp68 * 8]) != 0) {
                break;
              }
              osRecvMesg(&superThread_ptr->siMsgQ, (OSMesg *)&eepromMsg_ptr, OS_MESG_BLOCK);
            }
            for (sp68 = 0; sp68 < g_eepromSize; sp68++) {
              superThread_ptr->eepCache[sp68] = superThread_ptr->eepRWBuf[sp68];
            }
            superThread_ptr->eepRead = 0;
            break;
          }
        }
        
        if (osRecvMesg(&superThread_ptr->cpakMsgQ, (OSMesg *)&cpakMsg_ptr, OS_MESG_NOBLOCK) == 0) {
          switch (cpakMsg_ptr->cmd) {
          case 0:
            cpakMsg_ptr->tmpval = osPfsInitPak(&superThread_ptr->siMsgQ, &superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->cont_no);
            if (cpakMsg_ptr->tmpval != 0) {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 1:
            cpakMsg_ptr->tmpval = osPfsReadWriteFile(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->file_descriptor, PFS_READ, cpakMsg_ptr->offset, cpakMsg_ptr->tmpval, cpakMsg_ptr->data_buffer);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 2:
            cpakMsg_ptr->tmpval = osPfsReadWriteFile(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->file_descriptor, PFS_WRITE, cpakMsg_ptr->offset, cpakMsg_ptr->tmpval, cpakMsg_ptr->data_buffer);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 3:
            cpakMsg_ptr->tmpval = osPfsAllocateFile(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->pfsState_ptr->company_code, cpakMsg_ptr->pfsState_ptr->game_code, cpakMsg_ptr->pfsState_ptr->game_name, cpakMsg_ptr->pfsState_ptr->ext_name, cpakMsg_ptr->pfsState_ptr->file_size, &sp64);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 4:
            cpakMsg_ptr->tmpval = osPfsFindFile(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->pfsState_ptr->company_code, cpakMsg_ptr->pfsState_ptr->game_code, cpakMsg_ptr->pfsState_ptr->game_name, cpakMsg_ptr->pfsState_ptr->ext_name, &sp64);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 5:
            cpakMsg_ptr->tmpval = osPfsDeleteFile(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->pfsState_ptr->company_code, cpakMsg_ptr->pfsState_ptr->game_code, cpakMsg_ptr->pfsState_ptr->game_name, cpakMsg_ptr->pfsState_ptr->ext_name);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 6:
            cpakMsg_ptr->tmpval = osPfsNumFiles(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], &sp60, &sp64);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = ((sp60 << 16) & 0xFF00) | (sp64 & 0xFF);
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 7:
            cpakMsg_ptr->tmpval = osPfsFileState(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], cpakMsg_ptr->file_descriptor, cpakMsg_ptr->pfsState_ptr);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 8:
            cpakMsg_ptr->tmpval = osPfsRepairId(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no]);
            if (cpakMsg_ptr->tmpval == 0) {
              cpakMsg_ptr->tmpval = sp64;
            } else {
              cpakMsg_ptr->tmpval = ((cpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 9:
            osPfsFreeBlocks(&superThread_ptr->pfs_arr[cpakMsg_ptr->cont_no], &cpakMsg_ptr->tmpval);
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          }
        }

        if (osRecvMesg(&superThread_ptr->gbpakMsgQ, (OSMesg *)&gbpakMsg_ptr, OS_MESG_NOBLOCK) == 0) {
          switch (gbpakMsg_ptr->cmd) {
          case 0:
            rmonPrintf("GBPACK INIT\n");
            gbpakMsg_ptr->tmpval = osGbpakInit(&superThread_ptr->siMsgQ, &superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], gbpakMsg_ptr->cont_no);
            if (gbpakMsg_ptr->tmpval != 0) {
              gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 1:
            osGbpakPower(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_GBPAK_POWER_ON);
            gbpakMsg_ptr->tmpval = osGbpakReadId(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &superThread_ptr->gbpakId, &gbpakMsg_ptr->status);
            if (gbpakMsg_ptr->tmpval != 0) {
              gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
            }
            osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            break;
          case 2:
            osGbpakPower(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_GBPAK_POWER_ON);
            gbpakMsg_ptr->tmpval = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
            if (gbpakMsg_ptr->tmpval != 0) {
              gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
              osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            } else {
              for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                sp38[sp5C] = 0x1;
              }
              gbpakMsg_ptr->tmpval = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x6000, sp38, BLOCKSIZE);
              if (gbpakMsg_ptr->tmpval != 0) {
                gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
              } else {
                for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                  sp38[sp5C] = 0xA;
                }
                sp38[31] = 0xA;
                gbpakMsg_ptr->tmpval = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x0, sp38, BLOCKSIZE);
                if (gbpakMsg_ptr->tmpval != 0) {
                  gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                  osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                } else {
                  D_800E1F14[gbpakMsg_ptr->cont_no] = 0xFF;
                  gbpakMsg_ptr->tmpval = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
                  if (gbpakMsg_ptr->tmpval != 0) {
                    gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                    osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                  } else {
                    osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                  }
                }
              }
            }
            break;
          case 4:
            osGbpakPower(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_GBPAK_POWER_ON);
            gbpakMsg_ptr->tmpval = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
            if (gbpakMsg_ptr->tmpval != 0) {
              gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
              osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            } else {
              for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                sp38[sp5C] = 0x0;
              }
              gbpakMsg_ptr->tmpval = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x5000, sp38, BLOCKSIZE);
              if (gbpakMsg_ptr->tmpval != 0) {
                gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
              } else {
                for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                  sp38[sp5C] = 0xA;
                }
                sp38[31] = 0xA;
                gbpakMsg_ptr->tmpval = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x0, sp38, BLOCKSIZE);
                if (gbpakMsg_ptr->tmpval != 0) {
                  gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                  osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                } else {
                  D_800E1F14[gbpakMsg_ptr->cont_no] = 0xFF;
                  gbpakMsg_ptr->tmpval = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
                  if (gbpakMsg_ptr->tmpval != 0) {
                    gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
                    osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                  } else {
                    osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                  }
                }
              }
            }
            break;
          case 3:
            sp5C = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
            if (sp5C != 0) {
              gbpakMsg_ptr->tmpval = ((sp5C << 4) & 0xF0) | 0xF;
              osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
              break;
            }

            sp37 = gbpakMsg_ptr->unk8 >> 13;
            if (D_800E1F14[gbpakMsg_ptr->cont_no] != sp37) {
              for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                sp38[sp5C] = sp37;
              }
              sp5C = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x4000, sp38, BLOCKSIZE);
              if (sp5C != 0) {
                gbpakMsg_ptr->tmpval = ((sp5C << 4) & 0xF0) | 0xF;
                osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                break;
              }

              D_800E1F14[gbpakMsg_ptr->cont_no] = sp37;
            }

            gbpakMsg_ptr->unk8 = gbpakMsg_ptr->unk8 & 0x1FFF;
            sp58 = gbpakMsg_ptr->unk8 + gbpakMsg_ptr->tmpval;
            while (TRUE) {
              if (sp58 > 0x2000) {
                sp58 -= 0x2000;
                sp5C = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], gbpakMsg_ptr->status, gbpakMsg_ptr->unk8 + 0xA000, gbpakMsg_ptr->unkC, 0x2000 - gbpakMsg_ptr->unk8);
                if (sp5C == 0) {
                  gbpakMsg_ptr->unkC += 0x2000 - gbpakMsg_ptr->unk8;
                  sp37++;
                  for (sp5C = 0; sp5C < BLOCKSIZE; sp5C++) {
                    sp38[sp5C] = sp37;
                  }
                  sp5C = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], OS_WRITE, 0x4000, sp38, BLOCKSIZE);
                  if (sp5C != 0) {
                    gbpakMsg_ptr->tmpval = ((sp5C << 4) & 0xF0) | 0xF;
                    osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                  } else {
                    D_800E1F14[gbpakMsg_ptr->cont_no] = sp37;
                    gbpakMsg_ptr->tmpval = sp58;
                    gbpakMsg_ptr->unk8 = 0x0;
                    continue;
                  }
                }
              } else {
                sp5C = osGbpakReadWrite(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], gbpakMsg_ptr->status, gbpakMsg_ptr->unk8 + 0xA000, gbpakMsg_ptr->unkC, gbpakMsg_ptr->tmpval);
                if (sp5C != 0) {
                  gbpakMsg_ptr->tmpval = ((sp5C << 4) & 0xF0) | 0xF;
                  osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
                }
              }
              break;
            }

            gbpakMsg_ptr->tmpval = osGbpakGetStatus(&superThread_ptr->pfs_arr[gbpakMsg_ptr->cont_no], &gbpakMsg_ptr->status);
            if (gbpakMsg_ptr->tmpval != 0) {
              gbpakMsg_ptr->tmpval = ((gbpakMsg_ptr->tmpval << 4) & 0xF0) | 0xF;
              osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            } else {
              osSendMesg(&superThread_ptr->synchMsgQ, NULL, OS_MESG_BLOCK);
            }
            break;
          }
        }

        sp87 = TRUE;
      }
      break;
    case OS_SC_PRE_NMI_MSG:
      spA2 = 1;
      break;
    }
  }
}

void FUN_001050_Create_and_Start_ControllerThread(SuperThread *superThd, OSId arg1, OSPri arg2) {
  osCreateThread(&superThd->thread, arg1, FUN_001050_ControllerThread, superThd, superThd->threadStack + STACKSIZE/sizeof(u64), arg2);
  osStartThread(&superThd->thread);
}
