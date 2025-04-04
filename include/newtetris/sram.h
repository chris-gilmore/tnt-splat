#ifndef _SRAM_H_
#define _SRAM_H_

typedef struct {
  /* 0x0  */ u8    pad0[0xC0];
  /* 0xC0 */ u16   time_in_seconds;
  /* 0xC2 */ u16   lines;
} UnkStruct_34; // 0xC4 bytes


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


extern u8     FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(UnkStruct_34 *);  // calculating rank
extern u8     FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(u16, u16);        // calculating rank, too

extern u32    get_total_wonder_lines(Sram *);
extern void   load_from_sram(u8);
extern void   func_8007C5CC(Sram *);  // save_to_sram?

#endif /* !_SRAM_H_ */
