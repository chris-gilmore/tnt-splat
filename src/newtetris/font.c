#include "common.h"

extern u8 D_273A00;  // image_lut

////////////////////////////////////////

/* static */ extern u8 D_800D2D00[64];  // lut for font_a, font_b, or font_c
/* static */ extern u8 D_800D2D40[48];  // lut for font_d

void Font_Deinit(Font *p_font) {
  n64HeapUnalloc(p_font->image);
  p_font->image = NULL;
}

// init for font_a, font_b, or font_c
void Font_Init46Char(Font *p_font, u32 img_id) {
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

// init for font_d
void Font_Init51Char(Font *p_font, u32 img_id) {
  s32 i;

  if (img_id != 0) {
    main_8004A34C_threeliner();
    p_font->image = (u8 *) n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, img_id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, p_font->image, img_id);
    p_font->width = ((u16 *) p_font->image)[0];
    p_font->height = ((u16 *) p_font->image)[1] / 51;
    for (i = 0; i < 51; i++) {
      for (p_font->char_widths[i] = p_font->width - 1; (p_font->image[p_font->char_widths[i] + (i * p_font->width * p_font->height) + 8] & 0xF0) == 0xF0; p_font->char_widths[i]--);
      p_font->char_widths[i]++;
      if (p_font->char_widths[i] < 2) {
        p_font->char_widths[i] = p_font->width - 1;
      }
    }
  }
}

void displayText_XY_RGBA_1(Gfx **p_gdl, Font *p_font, s32 x, s32 y, char *str, s32 red, s32 green, s32 blue, s32 alpha) {
  s32 i;
  s32 sp38;

  if (p_font->image != NULL) {
    i = 0;
    sp38 = x;
    while (str[i] != 0) {
      display_one_text_character_rgb(p_gdl,
                                     p_font->image,
                                     0,  // sl
                                     D_800D2D40[str[i] - 48] * p_font->height,  // tl
                                     p_font->char_widths[D_800D2D40[str[i] - 48]] - 1,  // sh
                                     D_800D2D40[str[i] - 48] * p_font->height + p_font->height - 1,  // th
                                     x,
                                     y,
                                     red,
                                     green,
                                     blue,
                                     alpha);
      x += p_font->char_widths[D_800D2D40[str[i] - 48]];
      i++;
    }
  }
}

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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/displayText_XY_RGBA_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/displayText_XY_RGBA_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/Font_80077d38_fourliner.s")

s32 get_text_width(Font *p_font, char *str) {
  s32 i;
  s32 width;

  if (p_font->image == NULL) {
    return 0;
  }

  i = 0;
  width = 0;
  while (str[i] != 0) {
    width += p_font->char_widths[D_800D2D00[str[i] - 48]];
    i++;
  }

  return width;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/Font_80077e18_fifteenliner_has_traps.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/displayText_80077ee0_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/Font_8007802c_fiveliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/displayText_80078094_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/Font_800781a8_elevenliner_loops_arg2_t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/font/displayText_80078244_7.s")
