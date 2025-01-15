#include "common.h"

UnkStruct_12 *D_8011FBA0;

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/Multisquare_8006a050_extralarge_manyloops_interesting.s")

void Multisquare_8006a3ec_twoliner(UnkStruct_11 *arg0) {
  arg0->square_type = 0;
  D_8011FBA0->unk3--;
}

void Multisquare_8006a410_fourliner(UnkStruct_11 *arg0, u8 *arg1) {
  if (arg0->square_type == 0) {
    return;
  }

  arg0->unk1--;
  if (arg0->unk1 == 0) {
    Multisquare_8006a3ec_twoliner(arg0);
  }
}

Color *Multisquare_pGetColor(UnkStruct_11 *arg0) {
  switch (arg0->square_type) {
  case 1:
    return &g_color_silver;
  case 2:
    return &g_color_gold;
  default:
    debug_print_reason_routine("Multisquare:pGetColor", "invalid type, multisquare.c");
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/Multisquares_Test4x4byType.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/Multisquare_8006a6bc_oneliner_calls_fun.s")

void Multisquare_8006a6f0_threeliner_sets_arg0_stuff(UnkStruct_12 *arg0) {
  arg0->unk2 = 45;  // square formation delay
  arg0->unk0 = 2;
  arg0->unk1 = 0;
}

void Multisquare_8006a708_fiveliner_sets_arg0_stuff(UnkStruct_12 *arg0) {
  if (arg0->unk2 == 0) {
    arg0->unk0 = 0;
    arg0->unk1 = 2;
    return;
  }

  arg0->unk1 = 0;
  arg0->unk2--;
}
