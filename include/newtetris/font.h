#ifndef _FONT_H_
#define _FONT_H_

typedef struct {
  /* 0x0  */ void  *image;
  /* 0x4  */ s16    char_widths[56];
  /* 0x74 */ s16    width;
  /* 0x76 */ s16    height;
} Font; // 0x78 bytes

extern void   Font_Deinit(Font *);
extern void   Font_Init46Char(Font *, u32);  // init for font_a, font_b, or font_c
extern void   Font_Init51Char(Font *, u32);  // init for font_d
extern void   displayText_XY_RGBA_1(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32);
extern void   displayText_XY_RGBA_2(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32);
extern s32    displayText_XY_RGBA_3(Gfx **, Font *, s32, s32, char, s32, s32, s32, s32);
extern void   displayText_XY_RGBA_4(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32, s16);
extern s32    get_text_width(Font *, char *);
extern s32    Font_80077e18_fifteenliner(Font *, char *);
extern void   displayText_80077ee0_5(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32, s32, s32);
extern s32    Font_800781a8_elevenliner_loops_arg2_t(Font *, char *, s32);
extern void   displayText_80078244_7(Font *, char *, s32, Gfx **, s32, s32, s32, s32, s32, s32);

#endif /* !_FONT_H_ */
