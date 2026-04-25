#ifndef _00E2A0_H_
#define _00E2A0_H_

typedef struct {
  /* 0x0  */ s16        unk0;
  /* 0x2  */ s16        unk2;
  /* 0x4  */ OSScTask  *unk4;
  /* 0x8  */ OSTime     unk8;
  /* 0x10 */ OSTime     unk10;
  /* 0x18 */ u8         pad18[0x8];
} UnkStruct_91; // 0x20 bytes

extern u16 draw_buffer;
extern Gfx *g_gdl;

extern u8 D_800CFD48;
extern u8 D_800CFD4C;
extern s32 screen_1_width;
extern s32 screen_1_height;
extern s32 screen_2_width;
extern s32 screen_2_height;
extern s32 screen_3_width;
extern s32 screen_3_height;
extern s32 screen_4_width;
extern s32 screen_4_height;
extern u8 D_800CFE24;

extern void   FUN_80048020_eightliner(void);
extern void   func_800480D8_nevercalled(void);
extern void   FUN_800480E0_threeliner_glist(void);
extern void   FUN_80048150_threeliner_vlist(void);
extern void   FUN_800481C0_allocs_heap(s32, s32);
extern void   FUN_8004831C_allocs_heap(s32);
extern void   FUN_800483E8_allocs_heap(s32);
extern void   inits_bunch_of_stuff_q_allocs_heap(void);
extern Gfx   *FUN_80048934_inits_struct_q(Gfx *, s32);
extern Gfx   *FUN_80048A6C_inits_struct_q(Gfx *, s32);
extern void   has_rounds_and_floors_large_liner(void);
extern void   has_rounds_and_floors_2_large_liner(void);
extern void   four_arguments_get_debug_printed(void);


extern u8 *D_80120EB4;
extern u8 main_TEXT_START[];
extern u8 main_TEXT_END[];
extern u8 main_BSS_END[];
extern u8 audioheap_BASE[];
extern u8 D_A8190;
extern u8 D_ADAE0;

#endif /* !_00E2A0_H_ */
