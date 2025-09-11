#include "common.h"

extern f64 fabs(f64);
#pragma intrinsic(fabs);

static f32   func_800B10C0(void);
static f32   func_800B110C(f32 arg0);

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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/077340/func_800B13A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/077340/func_800B16D8.s")
