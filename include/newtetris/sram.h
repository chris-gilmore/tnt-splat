#ifndef _SRAM_H_
#define _SRAM_H_

typedef struct {
  /* 0x0  */ u8   *image;
  /* 0x4  */ s16   char_widths[56];
  /* 0x74 */ s16   width;
  /* 0x76 */ s16   height;
} Font; // 0x78 bytes

typedef struct {
  /* 0x0    */ u8    pad0[0xF04];
  /* 0xF04  */ u32   total_wonder_lines_odd_bits;
  /* 0xF08  */ u32   total_wonder_lines_even_bits;
  /* 0xF0C  */ u8    padF0C[0x9D8];
  /* 0x18E4 */ u32   music_level;
  /* 0x18E8 */ u32   sfx_level;
  /* 0x18EC */ u32   song;
  /* 0x18F0 */ u32   music_mode;
  /* 0x18F4 */ u32   unk18F4;
  /* 0x18F8 */ u8    pad18F8[0x8];
} Sram; // 0x1900 bytes

extern Sram *g_sram_ptr;

extern void   FUN_SRAM_n64HeapUnalloc_and_set_to_NULL(Font *);       // deinit font
extern void   FUN_SRAM_80077408_twentyliner_loops_46t(Font *, s32);  // init font
extern void   displayText_XY_RGBA_2(Gfx **, Font *, s32, s32, char *, s32, s32, s32, s32);
extern u32    get_total_wonder_lines(Sram *);
extern void   load_from_sram(u8);
extern void   func_8007C5CC(Sram *);  // save_to_sram?

#endif /* !_SRAM_H_ */
