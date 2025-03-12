#include "common.h"

/*
static Gfx D_800D7B90[] = {
  gsSPEndDisplayList(),
};
*/

// static
extern OSThread D_8012A860;
// (bug) should have been declared as:
// static u64 D_8012AA10[STACKSIZE/sizeof(u64)]
extern u8 D_8012AA10[STACKSIZE];
extern OSMesgQueue D_8012CA10;  // ioMsgQ
extern OSMesg D_8012CA28[8];    // ioMsgBuf
extern OSMesgQueue D_8012CA48;  // dmaMsgQ
extern OSMesg D_8012CA60[1];    // dmaMsgBuf
extern OSPiHandle *D_8012CADC;  // carthandle

static void func_800ABE00();

static void func_800ABE00() {
  OSIoMesg mb;
  OSMesg dummyMesg;
  IoMsg *ioMsg_ptr;
  OSIoMesg dmaIoMesgBuf;

  for (;;) {
    osRecvMesg(&D_8012CA10, (OSMesg *) &ioMsg_ptr, OS_MESG_BLOCK);
    switch (ioMsg_ptr->type) {
    case 0:
      osInvalDCache(ioMsg_ptr->addr[1], (s32) ioMsg_ptr->len);
      osPiStartDma(&mb, OS_MESG_PRI_NORMAL, OS_READ, (u32) ioMsg_ptr->addr[0], ioMsg_ptr->addr[1], ioMsg_ptr->len, &D_8012CA48);
      osRecvMesg(&D_8012CA48, &dummyMesg, OS_MESG_BLOCK);
      break;
    case 1:
      osWritebackDCache(ioMsg_ptr->addr[0], (s32) ioMsg_ptr->len);
      dmaIoMesgBuf.hdr.pri = 0;
      dmaIoMesgBuf.hdr.retQueue = &D_8012CA48;
      dmaIoMesgBuf.dramAddr = ioMsg_ptr->addr[0];
      dmaIoMesgBuf.devAddr = (u32) ioMsg_ptr->addr[1];
      dmaIoMesgBuf.size = ioMsg_ptr->len;
      ioMsg_ptr->len = (u32) osEPiStartDma(D_8012CADC, &dmaIoMesgBuf, OS_READ);
      osRecvMesg(&D_8012CA48, NULL, OS_MESG_BLOCK);
      break;
    case 2:
      osWritebackDCache(ioMsg_ptr->addr[0], (s32) ioMsg_ptr->len);
      dmaIoMesgBuf.hdr.pri = 0;
      dmaIoMesgBuf.hdr.retQueue = &D_8012CA48;
      dmaIoMesgBuf.dramAddr = ioMsg_ptr->addr[0];
      dmaIoMesgBuf.devAddr = (u32) ioMsg_ptr->addr[1];
      dmaIoMesgBuf.size = ioMsg_ptr->len;
      ioMsg_ptr->len = (u32) osEPiStartDma(D_8012CADC, &dmaIoMesgBuf, OS_WRITE);
      osRecvMesg(&D_8012CA48, NULL, OS_MESG_BLOCK);
      break;
    }
    osSendMesg(ioMsg_ptr->retQueue, (OSMesg) ioMsg_ptr, OS_MESG_BLOCK);
  }
}

void func_800ABFF0(u32 devAddr, void *dramAddr, u32 len) {
  OSMesgQueue retQ;
  OSMesg msgBuf[1];
  s32 unused;
  IoMsg ioMsg;

  osCreateMesgQueue(&retQ, msgBuf, 1);
  ioMsg.addr[0] = (void *) devAddr;
  ioMsg.addr[1] = dramAddr;
  ioMsg.len = len;
  ioMsg.retQueue = &retQ;
  ioMsg.type = 0;
  osSendMesg(&D_8012CA10, (OSMesg) &ioMsg, OS_MESG_BLOCK);
  osRecvMesg(&retQ, (OSMesg *) &ioMsg, OS_MESG_BLOCK);
}

void func_800AC06C(OSId id, OSPri pri) {
  osCreateMesgQueue(&D_8012CA48, D_8012CA60, 1);
  osCreateMesgQueue(&D_8012CA10, D_8012CA28, 8);
  osCreateThread(&D_8012A860, id, (void (*)(void *)) func_800ABE00, NULL, D_8012AA10 + STACKSIZE/sizeof(u64), pri);
  osStartThread(&D_8012A860);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC0F8.s")

u32 func_800AC1A8(void *dramAddr, u32 devAddr, u32 len) {
  OSMesgQueue retQ;
  OSMesg msgBuf[1];
  IoMsg ioMsg;

  osCreateMesgQueue(&retQ, msgBuf, 1);
  ioMsg.addr[0] = dramAddr;
  ioMsg.addr[1] = (void *) devAddr;
  ioMsg.len = len;
  ioMsg.type = 1;
  ioMsg.retQueue = &retQ;
  osSendMesg(&D_8012CA10, (OSMesg) &ioMsg, OS_MESG_BLOCK);
  osRecvMesg(&retQ, (OSMesg *) &ioMsg, OS_MESG_BLOCK);
  return ioMsg.len;
}

u32 func_800AC22C(void *dramAddr, u32 devAddr, u32 len) {
  OSMesgQueue retQ;
  OSMesg msgBuf[1];
  IoMsg ioMsg;

  osCreateMesgQueue(&retQ, msgBuf, 1);
  ioMsg.addr[0] = dramAddr;
  ioMsg.addr[1] = (void *) devAddr;
  ioMsg.len = len;
  ioMsg.type = 2;
  ioMsg.retQueue = &retQ;
  osSendMesg(&D_8012CA10, (OSMesg) &ioMsg, OS_MESG_BLOCK);
  osRecvMesg(&retQ, (OSMesg *) &ioMsg, OS_MESG_BLOCK);
  return ioMsg.len;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/072080/func_800AC950.s")
