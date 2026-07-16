#ifndef _008050_H_
#define _008050_H_

typedef struct {
  /* 0x0 */ s16             unk0;
  /* 0x2 */ UnkStruct_108   unk2;
  /* 0x5 */ u8              unk5;
  /* 0x6 */ u8              unk6;
} UnkStruct_99; // 0x8 bytes

extern UnkStruct_99 **D_800E1F40;

extern void   FUN_008050_80041dd0_alloc_heap_4_and_x640(void);
extern void   FUN_008050_80041e24_maybe_calls_unalloc_heap(void);
extern void   FUN_008050_80041e88_loops_200_times(void);
extern void   FUN_008050_800423f0_uses_dat_800e1f40_ptr(u8);
extern void   FUN_008050_80042738_passes_dat_800e1f40_ptr(UnkStruct_108 *);  // unused
extern void   FUN_008050_800427b8_passes_dat_800e1f40_ptr(u8, UnkStruct_108 *);

#endif /* !_008050_H_ */
