#include "common.h"

//u16 draw_buffer;

u32 D_800CFD40 = 0;
u32 D_800CFD44 = 0;
u8 D_800CFD48 = TRUE;
u8 D_800CFD4C = TRUE;

s32 screen_1_width  = 320;
s32 screen_1_height = 240;
s32 screen_2_width  = SCREEN_WD;
s32 screen_2_height = SCREEN_HT;
s32 screen_3_width  = 320;
s32 screen_3_height = 240;
s32 screen_4_width  = 320;
s32 screen_4_height = 240;

static u32 D_800CFD70[44] = {
  0xE7000000, 0x00000000,
  0xE2001E01, 0x00000000,
  0xE2001D00, 0x00000000,
  0xE3001A01, 0x00000020,
  0xE3001801, 0x00000080,
  0xE3001700, 0x00000000,
  0xE3001402, 0x00000C00,
  0xE3001201, 0x00002000,
  0xE3000F00, 0x00010000,
  0xE3001001, 0x00000000,
  0xE3000D01, 0x00000000,
  0xE3000C00, 0x00080000,
  0xE3000A01, 0x00000000,
  0xE200001C, 0x00552078,
  0xFA000000, 0xFFFFFF80,
  0xFCFFFFFF, 0xFFFE793C,
  0xE3000800, 0x00000000,
  0xDB040004, 0x00000003,
  0xDB04000C, 0x00000003,
  0xDB040014, 0x0000FFFD,
  0xDB04001C, 0x0000FFFD,
  0xDF000000, 0x00000000
};

static u8 D_800CFE20 = FALSE;
u8 D_800CFE24 = TRUE;
static u32 D_800CFE28 = 1; // unused

static void   four_arguments_get_debug_printed(void);

void FUN_80048020_eightliner(void) {
  register s32 tmp;

  if (D_800E20C4 != 0) {
    tmp = ((intptr_t) g_gdl - (intptr_t) D_800E20B8[draw_buffer]) >> 3;
    if (D_800CFD40 < tmp) {
      D_800CFD40 = tmp;
    }
  }

  if (D_800E20D4 != 0) {
    tmp = ((intptr_t) D_800E20D0 - (intptr_t) D_800E20C8[draw_buffer]) >> 4;
    if (D_800CFD44 < tmp) {
      D_800CFD44 = tmp;
    }
  }
}

void func_800480D8_nevercalled(void) {
}

void FUN_800480E0_threeliner_glist(void) {
  char sp18[16];

  if ((intptr_t) g_gdl > ((intptr_t) D_800E20B8[draw_buffer] + D_800E20C4)) {
    sprintf(sp18, "glistEntries %d", D_800E20C4 >> 3);
    debug_print_reason_routine("glist assert", sp18);
  }
}

void FUN_80048150_threeliner_vlist(void) {
  char sp18[16];

  if ((intptr_t) D_800E20D0 > ((intptr_t) D_800E20C8[draw_buffer] + D_800E20D4)) {
    sprintf(sp18, "vlistEntries %d", D_800E20D4 >> 4);
    debug_print_reason_routine("vlist assert", sp18);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/FUN_800481C0_allocs_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/FUN_8004831C_allocs_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/FUN_800483E8_allocs_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/inits_bunch_of_stuff_q_allocs_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/FUN_80048934_inits_struct_q.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/FUN_80048A6C_inits_struct_q.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/has_rounds_and_floors_large_liner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00E2A0/has_rounds_and_floors_2_large_liner.s")

static void four_arguments_get_debug_printed(void) {
  OSMesg msg;

  msg = NULL;
  func_800614A8();
  rmonPrintf("Arg1\n");
  osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
  rmonPrintf("Arg2\n");
  D_800CFE20 = TRUE;
  rmonPrintf("Arg3\n");
  n64HeapInit(main_BSS_END, D_80120EB4 - main_BSS_END);
  func_800A9E44(&D_A8190, &D_ADAE0);
  func_8007CF40(1);
  rmonPrintf("Arg4\n");
  func_80061124();
  func_80060D10(osViModeNtscLan1);
  screen_1_width  = SCREEN_WD;
  screen_1_height = SCREEN_HT;
  screen_3_width  = 0;
  screen_3_height = 0;
  screen_4_width  = SCREEN_WD;
  screen_4_height = SCREEN_HT;
  rmonPrintf("Arg\n");
  func_8006110C(SCREEN_WD, SCREEN_HT);
  func_80060E30();
  for (;;) {
    osRecvMesg(&D_8010BB08, &msg, OS_MESG_BLOCK);
    rmonPrintf("Arg\n");
  }
}
