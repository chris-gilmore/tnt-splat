#ifndef _001050_H_
#define _001050_H_

#define STACKSIZE 0x2000

typedef struct {
  /* 0x0 */ u16   cmd;
} EepromMsg; // 0x2 bytes

typedef struct {
  /* 0x0  */ u16           cmd;
  /* 0x4  */ u32           cont_no;
  /* 0x8  */ s32           unk8;
  /* 0xC  */ u8           *unkC;
  /* 0x10 */ OSMesgQueue  *synchMsgQ_ptr;
} MotorMsg; // 0x14 bytes

typedef struct {
  /* 0x0 */ OSMesgQueue   *synchMsgQ_ptr;
  /* 0x4 */ u16            cmd;
  /* 0x8 */ OSContStatus  *contstat_ptr;
} ControllerMsg; // 0xC bytes

typedef struct {
  /* 0x0  */ u8            cont_no;
  /* 0x1  */ u8            file_descriptor;  // game note number
  /* 0x4  */ u8           *data_buffer;      // for calls to osPfsReadWriteFile
  /* 0x8  */ u16           cmd;              // used in the cpak (cpakMsgQ) handler, switch/case on it
  /* 0xC  */ s32           offset;           // for calls to osPfsReadWriteFile
  /* 0x10 */ s32           tmpval;           // return val from osPfs calls, file_no, free_blocks, num_bytes, other stuff?
  /* 0x14 */ OSMesgQueue  *synchMsgQ_ptr;
  /* 0x18 */ OSPfsState   *pfsState_ptr;     // game_name (note name), ext_name (note extension)
} CpakMsg; // 0x1C bytes

typedef struct {
  /* 0x0  */ u16           cmd;
  /* 0x2  */ u8            cont_no;
  /* 0x4  */ s32           tmpval;
  /* 0x8  */ u32           unk8;
  /* 0xC  */ u8           *unkC;
  /* 0x10 */ u8            status;  // (bug?) overloaded with read/write flag?
  /* 0x14 */ OSMesgQueue  *synchMsgQ_ptr;
} GbpakMsg; // 0x18 bytes

typedef struct {
  /* 0x0    */ OSThread          thread;
  /* 0x1B0  */ OSMesgQueue       schedMsgQ;
  /* 0x1C8  */ OSMesgQueue       eepromMsgQ;
  /* 0x1E0  */ OSMesgQueue       motorMsgQ;
  /* 0x1F8  */ OSMesgQueue       cpakMsgQ;
  /* 0x210  */ OSMesgQueue       controllerMsgQ;
  /* 0x228  */ OSMesgQueue       gbpakMsgQ;
  /* 0x240  */ OSMesgQueue       synchMsgQ;
  /* 0x258  */ OSMesgQueue       siMsgQ;
  /* 0x270  */ OSMesg            schedMsgBuf[8];
  /* 0x290  */ OSMesg            eepromMsgBuf[8];
  /* 0x2B0  */ OSMesg            motorMsgBuf[8];
  /* 0x2D0  */ OSMesg            cpakMsgBuf[8];
  /* 0x2F0  */ OSMesg            controllerMsgBuf[8];
  /* 0x310  */ OSMesg            gbpakMsgBuf[8];
  /* 0x330  */ OSMesg            synchMsgBuf[1];
  /* 0x334  */ OSMesg            siMsgBuf[8];
  /* 0x354  */ OSScClient        client;
  /* 0x360  */ u64               threadStack[0x2000/sizeof(u64)];  // STACKSIZE/sizeof(u64)
  /* 0x2360 */ u8                bitpattern;  // controller flags populated by osContInit
  /* 0x2362 */ OSContStatus      contstat_arr[4];
  /* 0x2372 */ OSContPad         contpad_arr[4];
  /* 0x238C */ OSPfs             pfs_arr[4];
  /* 0x252C */ u16               unk252C;
  /* 0x252E */ u8                pad252E[0x1E];
  /* 0x254C */ MotorMsg          motorMsg;
  /* 0x2560 */ EepromMsg         eepromMsg;
  /* 0x2564 */ ControllerMsg     controllerMsg;
  /* 0x2570 */ CpakMsg           cpakMsg;
  /* 0x258C */ u8                pad258C[4];
  /* 0x2590 */ GbpakMsg          gbpakMsg;
  /* 0x25A8 */ OSSched          *sched;
  /* 0x25AC */ u8                maxControllers;
  /* 0x25AE */ u16               unk25AE;  // (bitfield) eeprom and controller motor init flags
  /* 0x25B0 */ u8               *eepCache;
  /* 0x25B4 */ u8               *eepDirtyBlks;
  /* 0x25B8 */ u8                eepRead;
  /* 0x25B9 */ u8                eepWrite;
  /* 0x25BC */ u8               *eepRWBuf;
  /* 0x25C0 */ OSGbpakId         gbpakId;
  /* 0x2610 */ ControllerQueue **controller_queues;
} SuperThread; // 0x2618 bytes

extern s32 g_eepromSize;

extern s16    createSuperThread(SuperThread *, OSSched *, ControllerQueue **, u8);

extern s32    FUN_001050_checkEepromSize_and_AllocHeap(SuperThread *);
extern void   FUN_001050_eepromWrite(SuperThread *, u8 *);
extern void   FUN_001050_eepromRead(SuperThread *, u8 *);

extern void   FUN_001500_motorInit(SuperThread *);
extern s32    FUN_001050_8003b3e4_motor_sendrecvmsg_3(SuperThread *, s32);
extern void   FUN_001050_8003b468_motor_sendmsg_0(SuperThread *, s32);
extern void   FUN_001050_8003b4d4_motor_sendmsg_1(SuperThread *, s32);
extern void   FUN_001050_8003b544_motor_sendmsg_2(SuperThread *, s32, s32, u8 *);

extern void   FUN_001050_8003b5d0_controller_sendrecvmsg(SuperThread *);
extern u16    FUN_001050_getControllerType(SuperThread *, u8);
extern u8     FUN_001050_getControllerStatus(SuperThread *, u8);
extern u8     FUN_001050_getControllerErrNo(SuperThread *, u8);

extern s32    FUN_001050_cpakInit(SuperThread *, s32);
extern s32    FUN_001050_cpakRead(SuperThread *, u8, s32, s32, u8 *, u8);
extern s32    FUN_001050_cpakWrite(SuperThread *, u8, s32, s32, u8 *, u8);
extern s32    FUN_001050_cpakAllocFile(SuperThread *, OSPfsState *, u8);
extern s32    FUN_001050_cpakFindFile(SuperThread *, OSPfsState *, u8);
extern s32    FUN_001050_cpakDeleteFile(SuperThread *, OSPfsState *, u8);
extern s32    FUN_001050_cpakNumFiles(SuperThread *, u8);
extern s32    FUN_001050_cpakFileState(SuperThread *, OSPfsState *, u8, u8);
extern s32    FUN_001050_cpakRepairId(SuperThread *, OSPfsState *, u8);
extern s32    FUN_001050_cpakFreeBlocks(SuperThread *, OSPfsState *, u8);

extern s32    FUN_001050_gbpakInit(SuperThread *, u8);
extern s32    FUN_001050_gbpakReadId(SuperThread *, u8);
extern s32    FUN_001050_gbpakReadWrite_a(SuperThread *, u8);
extern s32    FUN_001050_gbpakReadWrite_b(SuperThread *, u8);
extern s32    FUN_001050_gbpakReadWrite_c(SuperThread *, u8, u32, u8 *, s32);
extern s32    FUN_001050_gbpakReadWrite_d(SuperThread *, u8, u32, u8 *, s32);

extern void   FUN_001050_Create_and_Start_ControllerThread(SuperThread *, OSId, OSPri);

#endif /* !_001050_H_ */
