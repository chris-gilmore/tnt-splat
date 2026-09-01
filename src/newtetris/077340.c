#include "common.h"

extern f64 fabs(f64);
#pragma intrinsic(fabs);

static f32 func_800B10C0(void);
static f32 func_800B110C(f32);

static f32 func_800B10C0(void) {
  return 2.0 * (((f32) guRandom() / 0x40000000) - 0.5);
}

static f32 func_800B110C(f32 arg0) {
  arg0 = fabs((func_800B10C0() * 0.01) + arg0);
  if (arg0 > 1.0) {
    return 0;
  }
  if (arg0 < 0.5) {
    return 1;
  }
  arg0 -= 0.5;
  return 1.0 - (2.0 * arg0);
}

// HSL to RGB
void func_800B11C4(UnkStruct_84 *arg0, UnkStruct_84 *arg1) {
  UnkStruct_84 unused;
  f32 sp2C;
  f32 sp28;
  f32 sp24;
  f32 temp_fv0;
  f32 var_fa0;
  f32 temp_fa1;

  var_fa0 = arg0->unk0 * 3.0;
  while (var_fa0 > 3.0) {
    var_fa0 -= 3.0;
  }
  while (var_fa0 < 0.0) {
    var_fa0 += 3.0;
  }

  sp24 = func_800B110C(var_fa0);
  sp28 = func_800B110C(var_fa0 - 3.0) + sp24;
  sp2C = func_800B110C(var_fa0 - 1.0);
  temp_fv0 = func_800B110C(var_fa0 - 2.0);

  var_fa0 = arg0->unk4;
  if (var_fa0 <= 0.5) {
    var_fa0 *= 2.0 * arg0->unk8;
    arg1->unk0 = sp28 * var_fa0;
    arg1->unk4 = sp2C * var_fa0;
    arg1->unk8 = temp_fv0 * var_fa0;
  } else {
    temp_fa1 = 2.0 * (arg0->unk4 - 0.5);
    var_fa0 = (1.0 - temp_fa1) * arg0->unk8;
    arg1->unk0 = sp28 * var_fa0 + temp_fa1;
    arg1->unk4 = sp2C * var_fa0 + temp_fa1;
    arg1->unk8 = temp_fv0 * var_fa0 + temp_fa1;
  }
  arg1->unkC = arg0->unkC;
}

// unused
// RGB to HSL
void func_800B13A8(UnkStruct_84 *arg0, UnkStruct_84 *arg1) {
  f32 max = 0.0;
  f32 min = 1.0;
  s32 max_chan;

  if (arg0->unk0 > 1.0) { arg0->unk0 = 1.0; }
  if (arg0->unk4 > 1.0) { arg0->unk4 = 1.0; }
  if (arg0->unk8 > 1.0) { arg0->unk8 = 1.0; }

  if (arg0->unk0 < 0.0) { arg0->unk0 = 0.0; }
  if (arg0->unk0 < 0.0) { arg0->unk4 = 0.0; }  // (bug?) should be "if (arg0->unk4 < 0.0) ..."
  if (arg0->unk8 < 0.0) { arg0->unk8 = 0.0; }

  if (arg0->unk0 > max) { max = arg0->unk0; max_chan = 0; }
  if (arg0->unk4 > max) { max = arg0->unk4; max_chan = 1; }
  if (arg0->unk8 > max) { max = arg0->unk8; max_chan = 2; }

  if (arg0->unk0 < min) { min = arg0->unk0; }
  if (arg0->unk4 < min) { min = arg0->unk4; }
  if (arg0->unk8 < min) { min = arg0->unk8; }

  arg1->unk4 = (max + min) * 0.5;

  if (max - min < 0.001) {
    arg1->unk8 = 0.0;
    arg1->unk0 = 0.0;
  } else {
    if (arg1->unk4 <= 0.5) {
      arg1->unk8 = (max - min) / (max + min);
    } else {
      arg1->unk8 = (max - min) / (2.0 + max + min);  // (bug?) should be "... / (2.0 - (max + min));"
    }

    max -= min;
    switch (max_chan) {
    case 0:
      arg1->unk0 = (arg0->unk4 - arg0->unk8) / max;
      break;
    case 1:
      arg1->unk0 = 2.0 + (arg0->unk8 - arg0->unk0) / max;
      break;
    case 2:
      arg1->unk0 = 4.0 + (arg0->unk0 - arg0->unk4) / max;
      break;
    }

    arg1->unk0 /= 6.0;
    if (arg1->unk0 < 0.0) {
      arg1->unk0 += 1.0;
    }
  }

  arg0->unkC = arg1->unkC;  // (bug?) should arg0 and arg1 be swapped?
}

// unused
void func_800B16D8(UnkStruct_84 *arg0, UnkStruct_84 *arg1, UnkStruct_84 *arg2, f32 arg3) {
  f32 temp_fv0 = 1.0 - arg3;

  arg0->unk0 = (arg1->unk0 * temp_fv0) + (arg2->unk0 * arg3);
  arg0->unk4 = (arg1->unk4 * temp_fv0) + (arg2->unk4 * arg3);
  arg0->unk8 = (arg1->unk8 * temp_fv0) + (arg2->unk8 * arg3);
  arg0->unkC = (arg1->unkC * temp_fv0) + (arg2->unkC * arg3);
}
