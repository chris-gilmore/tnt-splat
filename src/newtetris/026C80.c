#include "common.h"

void FUN_026900_80060a00_fourliner_sets_arg0_e0123(UnkStruct_25 *arg0, u8 arg1, u8 arg2) {
  arg0->unk0 = 0;
  arg0->unk1 = 0;
  arg0->unk2 = arg1;
  arg0->unk3 = arg2;
}

void FUN_026900_80060a1c_twoliner_sets_arg0_e01(UnkStruct_25 *arg0) {
  arg0->unk0 = 0;
  arg0->unk1 = 0;
}

s32 FUN_026900_80060a28_twelveliner_retbool(UnkStruct_25 *arg0, s32 arg1) {
  if (arg0->unk0 == 0) {
    arg0->unk0 = arg1;
    return TRUE;
  }

  if (arg0->unk0 <= arg0->unk2) {
    arg0->unk0 += arg1;
    if (arg0->unk0 > arg0->unk2) {
      return TRUE;
    }
  } else {
    arg0->unk1 += arg1;
  }

  if (arg0->unk1 >= arg0->unk3) {
    arg0->unk1 -= arg0->unk3;
    return TRUE;
  }

  return FALSE;
}

void FUN_026900_80060ad4_oneliner_calls_fun(UnkStruct_1 *arg0) {
  FUN_026900_80060b04_twelveliner_loops_32t(arg0, 0xFFFFFFFF, 0, 0);
}

// arg2: how many frames to wait until firing the second time
// arg3: how many frames to wait thereafter
void FUN_026900_80060b04_twelveliner_loops_32t(UnkStruct_1 *arg0, u32 arg1, u8 arg2, u8 arg3) {
  register UnkStruct_25 *var_s0 = arg0->unk0;
  register u32 var_s1 = 1;
  register u32 i;

  for (i = 0; i < 32; i++) {
    if (arg1 & var_s1) {
      FUN_026900_80060a00_fourliner_sets_arg0_e0123(var_s0, arg2, arg3);
    }
    var_s0++;
    var_s1 *= 2;
  }

  if (arg3 != 0) {
    arg0->unk80 |= arg1;
  } else {
    arg0->unk80 &= ~arg1;
  }
}

void FUN_026900_GU_or_ControllerRepeat_Update(UnkStruct_1 *arg0, u32 arg1, u32 arg2) {
  register UnkStruct_25 *var_s0 = arg0->unk0;
  register u32 var_s1 = 1;
  register u32 i;

  arg0->unk84 = 0;
  arg1 &= arg0->unk80;
  for (i = 0; i < 32; i++) {
    if (arg1 & var_s1) {
      if (FUN_026900_80060a28_twelveliner_retbool(var_s0, arg2)) {
        arg0->unk84 |= var_s1;
      }
    } else {
      FUN_026900_80060a1c_twoliner_sets_arg0_e01(var_s0);
    }
    var_s0++;
    var_s1 *= 2;
  }
}

void FUN_026900_nineliner_loops_32t(UnkStruct_1 *arg0) {
  register UnkStruct_25 *var_s0 = arg0->unk0;
  register u32 i;

  arg0->unk84 = 0;
  for (i = 0; i < 32; i++) {
    FUN_026900_80060a1c_twoliner_sets_arg0_e01(var_s0);
    var_s0++;
  }
  arg0->unk88 = 0;
  arg0->unk8C = 0;
}
