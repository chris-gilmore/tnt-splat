#ifndef _00E440_H_
#define _00E440_H_

extern s32 screen_1_width;
extern s32 screen_1_height;
extern s32 screen_2_width;
extern s32 screen_2_height;
extern s32 screen_3_width;
extern s32 screen_3_height;
extern s32 screen_4_width;
extern s32 screen_4_height;
extern u8 D_800CFE24;

extern Gfx *g_gdl;

extern void   inits_bunch_of_stuff_q_allocs_heap(void);
extern void   has_rounds_and_floors_large_liner(void);


extern u8 *D_80120EB4;
extern u8 main_TEXT_START[];
extern u8 main_TEXT_END[];
extern u8 main_BSS_END[];
extern u8 audioheap_BASE[];
extern u8 D_A8190;
extern u8 D_ADAE0;

#endif /* !_00E440_H_ */
