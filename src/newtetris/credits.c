#include "common.h"

extern u8 D_800CFD48;
extern s32 D_800D3CF4;
extern s32 D_800D3CF8;
extern s32 D_800D3CFC;
extern u8 D_800D5378;
extern u8 D_800D53C8;
extern u8 D_800D6128;
extern u8 D_800D6138;
extern u8 D_801290D0;
extern s32 D_801291E4;

extern void   EndScroller_Init(u8 *, u8 *);
extern void   EndScroller_Deinit(u8 *);
extern u32    EndScroller_8008023c_line_452(u8 *, u32);
extern void   EndScroller_80080400_line_502(u8 *);
extern void   func_8008F280(u8 *, s32, u32, u32, void *);
extern void   func_8008F360(u8 *, u8 *, u8 *);
extern void   func_8009035C(void *, void *);
extern void   func_80090A44(void);
extern void   func_8009D5E4(void);
extern u16   *func_800A8FC8(u8 *, u32, u16);

////////////////////////////////////////

static u8 *D_80120240;
static u8 D_80120248[0x188];

static void   Credits_Init(void);
static void   Credits_80083450_oneliner_calls_80090a44(void);

static void Credits_Init(void) {
  main_8004A34C_threeliner();
  D_80120240 = n64HeapAlloc(240008);
  D_80120240[0] = 1;
  D_80120240[1] = 0x90;
  D_80120240[2] = 1;
  D_80120240[3] = 0x2C;
  D_80120240[4] = 0;
  D_80120240[5] = 0;
  D_80120240[6] = 0;
  D_80120240[7] = 0;
  func_800A8FC8(D_80120240, 120004, 0);
  func_8008F280(&D_801290D0, -1, 400, 300, D_80120240);
  func_8008F360(&D_801290D0, &D_800D6138, &D_800D6128);
  D_800D3CF4 = 0;
  D_800D3CF8 = 0;
  D_800D3CFC = 0;
  D_801291E4 = 0;
  EndScroller_Init(D_80120248, ptr_s_credits);
}

static void Credits_80083450_oneliner_calls_80090a44(void) {
  func_80090A44();
}

void Credits_StateMachine_q(void) {
  static u32 D_800D3330 = 0;

  switch (D_800D3330) {
  case 0:
    Credits_Init();
    D_800D3330 = 1;
    return;
  case 1:
    func_8009D5E4();
    if (EndScroller_8008023c_line_452(D_80120248, 1) == 1) {
      D_800D3330 = 2;
      return;
    }
    EndScroller_80080400_line_502(D_80120248);
    return;
  case 2:
    EndScroller_Deinit(D_80120248);
    Credits_80083450_oneliner_calls_80090a44();
    func_8009035C(&D_800D53C8, &D_800D5378);
    D_800CFEE8 = 4;
    D_800CFD48 = 1;
    D_800D3330 = 0;
    return;
  }
}
