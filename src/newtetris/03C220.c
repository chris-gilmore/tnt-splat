#include "common.h"

static s16 *D_8011FCD0;
static UnkStruct_38 *D_8011FCD4;

static void   func_80075FA0(s16 *);
static void   func_80075FAC(UnkStruct_38 *);
static void   func_800760F4(UnkStruct_38 *);
static void   func_800761D0(UnkStruct_38 *, u32);
static void   func_800762EC(UnkStruct_38 *, s16, s16, UnkStruct_23 *);

static void func_80075FA0(s16 *arg0) {
  arg0[0] = 0;
  arg0[1] = 0;
}

static void func_80075FAC(UnkStruct_38 *arg0) {
  s32 j;
  s32 i;
  s32 tmp;

  for (i = 0; i < 24; i++) {
    for (j = 0; j < 16; j++) {
      tmp = (FUN_026900_PRNG_1() & 0x1FFFFF) + 0xFFF00000;
      tmp += ((j << 24) + 0x07000000) / 24;
      arg0->unk0[2][i][j] = (tmp - arg0->unk0[0][i][j]) / 32;

      tmp = (FUN_026900_PRNG_1() & 0x1FFFFF) + 0xFFF00000;
      tmp += ((i << 24) + 0x02000000) / 24;
      arg0->unk0[3][i][j] = (tmp - arg0->unk0[1][i][j]) / 32;
    }
  }
}

static void func_800760F4(UnkStruct_38 *arg0) {
  s32 j;
  s32 i;

  for (i = 0; i < 24; i++) {
    for (j = 0; j < 16; j++) {
      arg0->unk0[0][i][j] = ((j << 24) + 0x07000000) / 24;
      arg0->unk0[1][i][j] = ((i << 24) + 0x02000000) / 24;
    }
  }
  func_80075FAC(arg0);
  arg0->unk1800 = 32;
}

static void func_800761D0(UnkStruct_38 *arg0, u32 arg1) {
  s32 j;
  s32 i;
  s32 f;

  for (f = arg1; f > 0; f--) {
    for (i = 0; i < 24; i++) {
      for (j = 0; j < 16; j++) {
        arg0->unk0[0][i][j] += arg0->unk0[2][i][j];
        arg0->unk0[1][i][j] += arg0->unk0[3][i][j];
      }
    }
    arg0->unk1800--;
    if (arg0->unk1800 == 0) {
      func_80075FAC(arg0);
      arg0->unk1800 = 32;
    }
  }
}

static void func_800762EC(UnkStruct_38 *arg0, s16 arg1, s16 arg2, UnkStruct_23 *arg3) {
  s32 j;
  s32 i;

  j = (arg1 >> 8) + 6;
  i = (arg2 >> 8) + 11;
  arg3->unk0 = arg0->unk0[0][i][j];
  arg3->unk4 = arg0->unk0[1][i][j];
}

void func_8007635C(void) {
  D_8011FCD0 = (s16 *) n64HeapAlloc(2 * sizeof(s16));
  func_80075FA0(D_8011FCD0);
  D_8011FCD4 = (UnkStruct_38 *) n64HeapAlloc(sizeof(UnkStruct_38));
  func_800760F4(D_8011FCD4);
}

void func_800763B4(void) {
  n64HeapUnalloc(D_8011FCD0);
  n64HeapUnalloc(D_8011FCD4);
}

void func_800763EC(u32 arg0) {
  func_800761D0(D_8011FCD4, arg0);
}

void func_8007641C(UnkStruct_14 *arg0, UnkStruct_23 *arg1) {
  arg1->unk0 = (arg0->unk0.p.x * 0xA00) + 0x800000;
  arg1->unk4 = (arg0->unk0.p.y * 0xA00) + 0x800000;
}

void func_80076458(UnkStruct_14 *arg0, UnkStruct_23 *arg1) {
  register UnkStruct_38 *ptr = D_8011FCD4;
  s32 unused[2];

  func_800762EC(D_8011FCD4, arg0->unk0.p.x, arg0->unk0.p.y, arg1);

  if (FALSE) {
    rmonPrintf(NULL, NULL, NULL, NULL, NULL);
  }
}
