#ifndef _00E2A0_H_
#define _00E2A0_H_

extern u32 D_800CFD40;
extern u32 D_800CFD44;
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

extern u16 draw_buffer;
extern Gfx *D_800E20B8[];
extern Gfx *g_gdl;
extern u32 D_800E20C4;
extern Vtx *D_800E20C8[];
extern Vtx *D_800E20D0;
extern u32 D_800E20D4;

extern void   FUN_80048020_eightliner(void);
extern void   func_800480D8_nevercalled(void);
extern void   FUN_800480E0_threeliner_glist(void);
extern void   FUN_80048150_threeliner_vlist(void);
extern void   inits_bunch_of_stuff_q_allocs_heap(void);
extern void   has_rounds_and_floors_large_liner(void);


extern u8 *D_80120EB4;
extern u8 main_TEXT_START[];
extern u8 main_TEXT_END[];
extern u8 main_BSS_END[];
extern u8 audioheap_BASE[];
extern u8 D_A8190;
extern u8 D_ADAE0;

#endif /* !_00E2A0_H_ */
