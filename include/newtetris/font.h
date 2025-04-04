#ifndef _FONT_H_
#define _FONT_H_

typedef struct {
  /* 0x0  */ u8   *image;
  /* 0x4  */ s16   char_widths[56];
  /* 0x74 */ s16   width;
  /* 0x76 */ s16   height;
} Font; // 0x78 bytes

extern void   Font_Deinit(Font *);
extern void   Font_Init46Char(Font *, u32);  // init for font_a, font_b, or font_c
extern void   Font_Init51Char(Font *, u32);  // init for font_d
extern void   displayText_XY_RGBA_1(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32);
extern void   displayText_XY_RGBA_2(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32);
extern s32    get_text_width(Font *, char *);

#endif /* !_FONT_H_ */
