#include "common.h"

Landfill *g_landfill_ptr;

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_80072300.s")

u32 func_8007232C(void) {
  register Landfill *var_a0 = g_landfill_ptr;
  register s32 var_a1;
  register s32 var_a2 = 0;

  for (var_a1 = 0; var_a1 < g_playercount; var_a1++) {
    if (g_landfill_ptr->list[var_a1].unk0) {
      var_a2++;
    }
  }

  // (bug?) Missing "return var_a2;"
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/Landfill_800723a0_calls_garbage_fun.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/Landfill_8007240c_fiveliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_80072494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_800724C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_80072508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_8007257C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_80072610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_800726A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/Landfill_Garbage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/Landfill_Init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/Landfill_Deinit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/landfill/func_80072A84.s")
