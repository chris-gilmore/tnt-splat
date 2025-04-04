#include "common.h"

// Sram *g_sram_ptr;

/* static */ extern u8 D_800D2DFC[30];

static void   set_total_wonder_lines(Sram *, u32);

// calculating rank
u8 FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(UnkStruct_34 *arg0) {
  s32 i;
  s32 lines_per_minute;

  if ((arg0->time_in_seconds != 0) && ((arg0->time_in_seconds / 60) != 0)) {
    lines_per_minute = arg0->lines / (f32) ((f32) arg0->time_in_seconds / 60.0);

    i = 0;
    do {
      if (lines_per_minute < D_800D2DFC[i]) {
        return i;
      }
    } while (++i < 30);

    return 29;
  }

  return 0;
}

// calculating rank, too
u8 FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(u16 time_in_seconds, u16 lines) {
  s32 i;
  s32 lines_per_minute;

  if ((time_in_seconds != 0) && ((time_in_seconds / 60) != 0)) {
    lines_per_minute = lines / (f32) ((f32) time_in_seconds / 60.0);

    i = 0;
    do {
      if (lines_per_minute < D_800D2DFC[i]) {
        return i;
      }
    } while (++i < 30);

    return 29;
  }

  return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80078534_tenliner_loops.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_800785e0_sixliner_loop_arg0_t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_8007868c_tenliner_loop_arg0_t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_8007875c_check_gameover_conditions.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_800795d8_fourteenliner_loops_8t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_800796C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_800798F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A5D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BB54.s")

static void set_total_wonder_lines(Sram *sram_ptr, u32 total_wonder_lines) {
  sram_ptr->total_wonder_lines_odd_bits = total_wonder_lines & 0xAAAAAAAA;
  sram_ptr->total_wonder_lines_even_bits = total_wonder_lines & 0x55555555;
}

u32 get_total_wonder_lines(Sram *sram_ptr) {
  return sram_ptr->total_wonder_lines_odd_bits | sram_ptr->total_wonder_lines_even_bits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BCC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BDD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/load_from_sram.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007C5CC.s")
