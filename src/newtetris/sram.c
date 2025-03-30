#include "common.h"

extern u8 D_273A00;  // image_lut

////////////////////////////////////////

// Sram *g_sram_ptr;

/* static */ extern u8 D_800D2D00[64];  // font lut

static void   set_total_wonder_lines(Sram *, u32);

void FUN_SRAM_n64HeapUnalloc_and_set_to_NULL(Font *p_font) {
  n64HeapUnalloc(p_font->image);
  p_font->image = NULL;
}

void FUN_SRAM_80077408_twentyliner_loops_46t(Font *p_font, s32 img_id) {
  s32 i;

  if (img_id != 0) {
    main_8004A34C_threeliner();
    p_font->image = (u8 *) n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, img_id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, p_font->image, img_id);
    p_font->width = ((u16 *) p_font->image)[0];
    p_font->height = ((u16 *) p_font->image)[1] / 46;
    for (i = 0; i < 46; i++) {
      for (p_font->char_widths[i] = p_font->width - 1; (p_font->image[p_font->char_widths[i] + (i * p_font->width * p_font->height) + 8] & 0xF0) == 0xF0; p_font->char_widths[i]--);
      p_font->char_widths[i]++;
      if (p_font->char_widths[i] < 2) {
        p_font->char_widths[i] = p_font->width - 1;
      }
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80077610_twentyliner_loops_51t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_XY_RGBA_1.s")

void displayText_XY_RGBA_2(Gfx **p_gdl, Font *p_font, s32 x, s32 y, char *str, s32 red, s32 green, s32 blue, s32 alpha) {
  s32 i;
  s32 sp38;

  if (p_font->image != NULL) {
    i = 0;
    sp38 = x;
    while (str[i] != 0) {
      display_one_text_character_rgb(p_gdl,
                                     p_font->image,
                                     0,  // sl
                                     D_800D2D00[str[i] - 48] * p_font->height,  // tl
                                     p_font->char_widths[D_800D2D00[str[i] - 48]] - 1,  // sh
                                     D_800D2D00[str[i] - 48] * p_font->height + p_font->height - 1,  // th
                                     x,
                                     y,
                                     red,
                                     green,
                                     blue,
                                     alpha);
      x += p_font->char_widths[D_800D2D00[str[i] - 48]];
      i++;
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_XY_RGBA_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_XY_RGBA_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80077d38_fourliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/string_do_something_weird.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80077e18_fifteenliner_has_traps.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_80077ee0_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_8007802c_fiveliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_80078094_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_800781a8_elevenliner_loops_arg2_t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/displayText_80078244_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80078300_twelveliner_div60_loop_30t_a.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80078424_twelveliner_div60_loop_30t_b.s")

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
