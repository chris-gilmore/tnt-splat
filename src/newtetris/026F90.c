#include "common.h"

/*
extern s32 D_8000030C;
extern ? D_8000031C;

static s32 D_800D0280 = 0x50A;
static s32 D_800D0284 = 0x280;
static s32 D_800D0288 = 0;
static s32 D_800D028C[2] = { 0x190, 0xF0 };
static s32 D_800D0294[3] = { 0x320, 0x4089A728, 0 };
*/


// static OSViMode D_8011FA80;
extern OSViMode D_8011FA80;


// static s32 D_800D0288 = 0;
extern s32 D_800D0288;


void func_80060D10(OSViMode arg0) {
  D_800D0288 = 1;
  bcopy(&arg0, &D_8011FA80, sizeof(OSViMode));
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026F90/FUN_026900_80060d58_elevenliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026F90/func_80060E30.s")

void func_8006110C(s32 arg0, s32 arg1) {
  D_800D0288 = 1;
}

void func_80061124(void) {
  D_800D0288 = 1;
}

// clears cfb[][]
void func_80061134(s32 width, s32 height) {
  s32 i;

  for (i = 0; i < width * height; i++) {
    cfb[0][i] = 0;
    cfb[1][i] = 0;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026F90/func_80061198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026F90/func_800611E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026F90/func_800614A8.s")
