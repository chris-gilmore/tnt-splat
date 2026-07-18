#include "common.h"

static void func_80073BD0(UnkStruct_29 *);
static void func_80073C60(UnkStruct_29 *);

static void func_80073BD0(UnkStruct_29 *arg0) {
  register u8 var_a1 = arg0->unk0;
  register u8 playercount = g_playercount;

  do {
    arg0->unk0 = (arg0->unk0 + 1) % playercount;
    if (g_landfill_ptr->list[arg0->unk0].unk0) {
      break;
    }
  } while (arg0->unk0 != var_a1);
}

static void func_80073C60(UnkStruct_29 *arg0) {
  register u32 var_s0;
  register u32 var_s1;
  register s32 var_s2;
  register s32 var_s3;
  register s32 var_s4;

  var_s0 = func_8007232C();
  if (var_s0 > 1) {
    if (var_s0 == 2) {
      func_80073BD0(arg0);
    } else {
      var_s1 = func_8007232C() - 1;
      var_s2 = FUN_026900_PRNG_1() % var_s1;
      for (var_s3 = 0; var_s3 <= var_s2; var_s3++) {
        func_80073BD0(arg0);
      }
    }

    for (var_s4 = 0; var_s4 < g_playercount; var_s4++) {
      Landfill_8007240c_fiveliner(var_s4, arg0->unk0);
    }

    arg0->unk1 = FALSE;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/hotpotato/func_80073D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/hotpotato/func_80074024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/hotpotato/func_8007434C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/hotpotato/func_800743F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/hotpotato/func_800744C0.s")
