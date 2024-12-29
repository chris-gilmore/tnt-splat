#include "common.h"

extern u8 D_800CFD4C;

////////////////////////////////////////

static s32 D_8011FCA0;
static s32 D_8011FCA4;
static s32 D_8011FCA8;
static s32 D_8011FCAC;
static s32 D_800D0600 = 0;

void func_800744D0(u32 arg0, u8 *arg1, u32 arg2) {
  u32 sp34;
  Dram_u sp28;
  Dram_u sp18[2];

  D_8011FCA0 = 0;
  while (D_800D0600) {
    if (D_8011FCA0 == 30) {
      break;
    }
    D_8011FCA0++;
  }
  D_800D0600 = TRUE;
  osWritebackDCacheAll();
  func_800ABFF0(arg0, &sp28, 2);
  func_800ABFF0((u32)&((u32 *)arg0)[arg2] + 2, &sp18[0], 4);
  func_800ABFF0((u32)&((u32 *)arg0)[arg2 + 1] + 2, &sp18[1], 4);
  sp34 = sp18[1].data - sp18[0].data;
  func_800ABFF0(sp18[0].data + arg0, arg1, sp34);
  osWritebackDCacheAll();
  D_800D0600 = FALSE;
}

u32 func_800745DC(u32 arg0, u32 arg1) {
  Dram_u sp28;
  Dram_u sp18[2];

  D_8011FCA4 = 0;
  while (D_800D0600) {
    if (D_8011FCA4 == 30) {
      break;
    }
    D_8011FCA4++;
  }
  D_800D0600 = TRUE;
  osWritebackDCacheAll();
  func_800ABFF0(arg0, &sp28, 2);
  func_800ABFF0((u32)&((u32 *)arg0)[arg1] + 2, &sp18[0], 4);
  func_800ABFF0((u32)&((u32 *)arg0)[arg1 + 1] + 2, &sp18[1], 4);
  D_800D0600 = FALSE;
  return sp18[1].data - sp18[0].data;
}

void FUN_03A750_800746c0_twentyliner(u32 arg0, u8 *arg1, u32 arg2) {
  u32 sp4C;
  Dram_u sp40;
  Dram_u sp30[2];
  Dram_u sp28;
  Dram_u sp20;
  u32 sp1C;
  u8 *sp18;

  D_800CFD4C = FALSE;
  D_8011FCA8 = 0;
  while (D_800D0600) {
    if (D_8011FCA8 == 30) {
      break;
    }
    D_8011FCA8++;
  }
  D_800D0600 = TRUE;
  osWritebackDCacheAll();
  func_800ABFF0(arg0, &sp40, 2);
  func_800ABFF0((u32)&((u32 *)arg0)[arg2] + 2, &sp30[0], 4);
  func_800ABFF0((u32)&((u32 *)arg0)[arg2 + 1] + 2, &sp30[1], 4);
  func_800ABFF0(sp30[0].data + arg0 + 4, &sp28, 4);
  func_800ABFF0(sp30[0].data + arg0, &sp20, 4);
  sp4C = sp30[1].data - sp30[0].data;
  sp18 = (u8 *)LZOBUF;
  if ((sp20.data & 0xFF) == 'S') {  // as in 'H2OS'
    func_800ABFF0(sp30[0].data + arg0, sp18, sp4C);
    func_80080EC8(arg1, &sp1C, sp18 + 8, sp4C - 8);
  } else {
    func_800ABFF0(sp30[0].data + arg0 + 8, arg1, sp4C - 8);
  }
  D_800D0600 = FALSE;
  osWritebackDCacheAll();
  main_8004A34C_threeliner();
  D_800CFD4C = TRUE;
}

u32 FUN_03A750_80074888_twelveliner(u32 arg0, u32 arg1) {
  Dram_u sp38;
  Dram_u sp28[2];
  Dram_u sp20;
  Dram_u sp18;

  D_8011FCAC = 0;
  while (D_800D0600) {
    if (D_8011FCAC == 30) {
      break;
    }
    D_8011FCAC++;
  }
  D_800D0600 = TRUE;
  osWritebackDCacheAll();
  func_800ABFF0(arg0, &sp38, 2);
  func_800ABFF0((u32)&((u32 *)arg0)[arg1] + 2, &sp28[0], 4);
  func_800ABFF0((u32)&((u32 *)arg0)[arg1 + 1] + 2, &sp28[1], 4);
  func_800ABFF0(sp28[0].data + arg0 + 4, &sp20, 4);
  func_800ABFF0(sp28[0].data + arg0, &sp18, 4);
  D_800D0600 = FALSE;
  return sp20.data;
}
