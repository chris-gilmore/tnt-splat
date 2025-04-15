#include "common.h"

// lut for font_a, font_b, or font_c
static u8 D_800D2CF0[64] = {
  16,
  45,
  13,
  44,
  45,
  11,
  45,
  13,
  14,
  15,
  45,
  45,
  45,
  45,
  45,
  45,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  10,
  14,
  45,
  15,
  12,
  45,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
  32,
  33,
  34,
  35,
  36,
  37,
  38,
  39,
  40,
  41,
  42,
  43,
  44,
  45,
  45,
  0
};

// lut for font_d
static u8 D_800D2D30[64] = {
  0,
  37,
  38,
  39,
  45,
  11,
  45,
  40,
  14,
  15,
  41,
  42,
  43,
  44,
  45,
  46,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  47,
  10,
  14,
  48,
  15,
  49,
  50,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
  32,
  33,
  34,
  35,
  36,
  43,
  44,
  45,
  45,
  0
};

static s16 D_800D2D70 = 0x400;

static s32    Font_8007802c_fiveliner(Font *, char);
static void   displayText_80078094_6(Font *, char, Gfx **, s32, s32, s32, s32, s32, s32);

void Font_Deinit(Font *p_font) {
  n64HeapUnalloc(p_font->image);
  p_font->image = NULL;
}

// init for font_a, font_b, or font_c
void Font_Init46Char(Font *p_font, u32 img_id) {
  s32 i;

  if (img_id != 0) {
    main_8004A34C_threeliner();
    p_font->image = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, img_id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, p_font->image, img_id);
    p_font->width = ((u16 *) p_font->image)[0];
    p_font->height = ((u16 *) p_font->image)[1] / 46;
    for (i = 0; i < 46; i++) {
      for (p_font->char_widths[i] = p_font->width - 1; (((u8 *) p_font->image)[p_font->char_widths[i] + (i * p_font->width * p_font->height) + 8] & 0xF0) == 0xF0; p_font->char_widths[i]--);
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
    p_font->image = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, img_id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, p_font->image, img_id);
    p_font->width = ((u16 *) p_font->image)[0];
    p_font->height = ((u16 *) p_font->image)[1] / 51;
    for (i = 0; i < 51; i++) {
      for (p_font->char_widths[i] = p_font->width - 1; (((u8 *) p_font->image)[p_font->char_widths[i] + (i * p_font->width * p_font->height) + 8] & 0xF0) == 0xF0; p_font->char_widths[i]--);
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
                                     D_800D2D30[str[i] - 32] * p_font->height,  // tl
                                     p_font->char_widths[D_800D2D30[str[i] - 32]] - 1,  // sh
                                     D_800D2D30[str[i] - 32] * p_font->height + p_font->height - 1,  // th
                                     x,
                                     y,
                                     red,
                                     green,
                                     blue,
                                     alpha);
      x += p_font->char_widths[D_800D2D30[str[i] - 32]];
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
                                     D_800D2CF0[str[i] - 32] * p_font->height,  // tl
                                     p_font->char_widths[D_800D2CF0[str[i] - 32]] - 1,  // sh
                                     D_800D2CF0[str[i] - 32] * p_font->height + p_font->height - 1,  // th
                                     x,
                                     y,
                                     red,
                                     green,
                                     blue,
                                     alpha);
      x += p_font->char_widths[D_800D2CF0[str[i] - 32]];
      i++;
    }
  }
}

s32 displayText_XY_RGBA_3(Gfx **p_gdl, Font *p_font, s32 x, s32 y, char c, s32 red, s32 green, s32 blue, s32 alpha) {
  s32 sp3C;

  if (p_font->image == NULL) {
    return 0;
  }

  sp3C = x;
  display_one_text_character_rgb(p_gdl,
                                 p_font->image,
                                 0,  // sl
                                 D_800D2CF0[c - 32] * p_font->height,  // tl
                                 p_font->char_widths[D_800D2CF0[c - 32]] - 1,  // sh
                                 D_800D2CF0[c - 32] * p_font->height + p_font->height - 1,  // th
                                 x,
                                 y,
                                 red,
                                 green,
                                 blue,
                                 alpha);
  x += p_font->char_widths[D_800D2CF0[c - 32]];

  return x;
}

void displayText_XY_RGBA_4(Gfx **p_gdl, Font *p_font, s32 x, s32 y, char *str, s32 red, s32 green, s32 blue, s32 alpha, s16 arg9) {
  s32 i;
  s32 sp48;

  if (p_font->image != NULL) {
    i = 0;
    sp48 = x;
    while (str[i] != 0) {
      FUN_8005aa9c_prob_display_text_rgb_as_well(p_gdl,
                                                 p_font->image,
                                                 NULL,
                                                 0,  // sl
                                                 D_800D2CF0[str[i] - 32] * p_font->height,  // tl
                                                 p_font->char_widths[D_800D2CF0[str[i] - 32]] - 1,  // sh
                                                 D_800D2CF0[str[i] - 32] * p_font->height + p_font->height - 1,  // th
                                                 x,
                                                 y,
                                                 red,
                                                 green,
                                                 blue,
                                                 alpha,
                                                 arg9,
                                                 arg9);
      x += (p_font->char_widths[D_800D2CF0[str[i] - 32]] << 0xC) / arg9;
      i++;
    }
  }
}

s32 get_char_width(Font *p_font, char c) {
  s32 i;
  s32 width;

  if (p_font->image == NULL) {
    return 0;
  }

  i = 0;
  width = 0;

  width = p_font->char_widths[D_800D2CF0[c - 32]];
  i++;

  return width;
}

s32 get_text_width(Font *p_font, char *str) {
  s32 i;
  s32 width;

  if (p_font->image == NULL) {
    return 0;
  }

  i = 0;
  width = 0;
  while (str[i] != 0) {
    width += p_font->char_widths[D_800D2CF0[str[i] - 32]];
    i++;
  }

  return width;
}

s32 Font_80077e18_fifteenliner(Font *p_font, char *str) {
  s32 i;
  s32 width;

  if (p_font->image == NULL) {
    return 0;
  }

  i = 0;
  width = 0;
  while (str[i] != 0) {
    width += (p_font->char_widths[D_800D2CF0[str[i] - 32]] << 0xC) / D_800D2D70;
    i++;
  }

  return width;
}

void displayText_80077ee0_5(Gfx **p_gdl, Font *p_font, s32 x, s32 y, char *str, s32 red, s32 green, s32 blue, s32 alpha, s32 arg9, s32 argA) {
  s32 i;
  s32 sp38;

  if (p_font->image != NULL) {
    i = 0;
    sp38 = x;
    while (str[i] != 0) {
      display_one_text_character_rgb(p_gdl,
                                     p_font->image,
                                     0,                                                 // sl
                                     D_800D2CF0[str[i] - 32] * p_font->height + arg9,   // tl
                                     p_font->char_widths[D_800D2CF0[str[i] - 32]] - 1,  // sh
                                     D_800D2CF0[str[i] - 32] * p_font->height + argA,   // th
                                     x,
                                     y,
                                     red,
                                     green,
                                     blue,
                                     alpha);
      x += p_font->char_widths[D_800D2CF0[str[i] - 32]];
      i++;
    }
  }
}

static s32 Font_8007802c_fiveliner(Font *p_font, char c) {
  if ((c >= 'a') && (c <= 'z')) {
    c -= 32;  // uppercase
  }

  if ((c < 32) || (c >= 96)) {
    return 0;
  }

  return p_font->char_widths[D_800D2CF0[c - 32]];
}

static void displayText_80078094_6(Font *p_font, char c, Gfx **p_gdl, s32 x, s32 y, s32 red, s32 green, s32 blue, s32 alpha) {
  if ((c >= 'a') && (c <= 'z')) {
    c -= 32;  // uppercase
  }

  if ((c < 32) || (c >= 96)) {
    return;
  }

  c -= 32;
  display_one_text_character_rgb(p_gdl,
                                 p_font->image,
                                 0,  // sl
                                 D_800D2CF0[c] * p_font->height,  // tl
                                 p_font->char_widths[D_800D2CF0[c]] - 1,  // sh
                                 D_800D2CF0[c] * p_font->height + p_font->height - 1,  // th
                                 x,
                                 y,
                                 red,
                                 green,
                                 blue,
                                 alpha);
}

s32 Font_800781a8_elevenliner_loops_arg2_t(Font *p_font, char *str, s32 len) {
  register s32 width = 0;

  if (p_font->image == NULL) {
    return 0;
  }

  while (len > 0) {
    width += Font_8007802c_fiveliner(p_font, *str);
    str++;
    len--;
 }

  return width;
}

void displayText_80078244_7(Font *p_font, char *str, s32 len, Gfx **p_gdl, s32 x, s32 y, s32 red, s32 green, s32 blue, s32 alpha) {
  register char c;

  while (len > 0) {
    c = *str;
    displayText_80078094_6(p_font, c, p_gdl, x, y, red, green, blue, alpha);
    x += Font_8007802c_fiveliner(p_font, c);
    str++;
    len--;
  }
}
