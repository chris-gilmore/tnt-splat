#include "common.h"

static OSScTask D_800E1FA0[2];
static UnkStruct_91 D_800E2070[2];
u16 draw_buffer;
static Gfx *D_800E20B8[2];
Gfx *g_gdl;
static u32 D_800E20C4;
Vtx *D_800E20C8[2];
static Vtx *D_800E20D0;
static u32 D_800E20D4;
static OSMesgQueue D_800E20D8;
static OSMesgQueue D_800E20F0;
static OSMesgQueue D_800E2108;
static OSMesg D_800E2120[1];
static OSMesg D_800E2124[1];
static OSMesg D_800E2128[1];
static u64 D_800E2130[0x12];  // unused
static u64 D_800E21C0[0x80];
static u64 D_800E25C0[0x180];
static u64 D_800E31C0[0x4000];

static u32 D_800CFD40 = 0;
static u32 D_800CFD44 = 0;
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
static Gfx D_800CFD70[] = {
  gsDPPipeSync(),
  gsDPSetAlphaCompare(G_AC_NONE),
  gsDPSetDepthSource(G_ZS_PIXEL),
  gsDPSetAlphaDither(G_AD_NOISE),
  gsDPSetColorDither(G_CD_NOISE),
  gsDPSetCombineKey(G_CK_NONE),
  gsDPSetTextureConvert(G_TC_FILT),
  gsDPSetTextureFilter(G_TF_BILERP),
  gsDPSetTextureLOD(G_TL_LOD),
  gsDPSetTextureLUT(G_TT_NONE),
  gsDPSetTextureDetail(G_TD_CLAMP),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
  gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0x80),
  gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
  gsDPPipelineMode(G_PM_NPRIMITIVE),
  gsSPClipRatio(FRUSTRATIO_3),
  gsSPEndDisplayList(),
};
static u8 D_800CFE20 = FALSE;
u8 D_800CFE24 = TRUE;
static u32 D_800CFE28 = 1; // unused

void FUN_80048020_eightliner(void) {
  register s32 tmp;

  if (D_800E20C4 > 0) {
    tmp = ((intptr_t) g_gdl - (intptr_t) D_800E20B8[draw_buffer]) >> 3;
    if (D_800CFD40 < tmp) {
      D_800CFD40 = tmp;
    }
  }

  if (D_800E20D4 > 0) {
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

void FUN_800481C0_allocs_heap(s32 arg0, s32 arg1) {
  D_800CFD40 = 0;
  D_800CFD44 = 0;
  D_800E20C4 = arg0 << 3;
  D_800E20D4 = arg1 << 4;
  main_8004A34C_threeliner();
  n64HeapUnalloc(D_800E20B8[0]);
  n64HeapUnalloc(D_800E20B8[1]);
  n64HeapUnalloc(D_800E20C8[0]);
  n64HeapUnalloc(D_800E20C8[1]);
  if (D_800E20C4 > 0) {
    D_800E20B8[0] = n64HeapAlloc(D_800E20C4);
    D_800E20B8[1] = n64HeapAlloc(D_800E20C4);
  }
  if (D_800E20D4 > 0) {
    D_800E20C8[0] = n64HeapAlloc(D_800E20D4);
    D_800E20C8[1] = n64HeapAlloc(D_800E20D4);
  }
  g_gdl = D_800E20B8[draw_buffer];
  D_800E20D0 = D_800E20C8[draw_buffer];
}

void FUN_8004831C_allocs_heap(s32 arg0) {
  D_800CFD40 = 0;
  D_800E20C4 = arg0 << 3;
  main_8004A34C_threeliner();
  n64HeapUnalloc(D_800E20B8[0]);
  n64HeapUnalloc(D_800E20B8[1]);
  if (D_800E20C4 == 0) {
    return;
  }

  D_800E20B8[0] = n64HeapAlloc(D_800E20C4);
  D_800E20B8[1] = n64HeapAlloc(D_800E20C4);
  g_gdl = D_800E20B8[draw_buffer];
}

void FUN_800483E8_allocs_heap(s32 arg0) {
  D_800CFD44 = 0;
  D_800E20D4 = arg0 << 4;
  main_8004A34C_threeliner();
  n64HeapUnalloc(D_800E20C8[0]);
  n64HeapUnalloc(D_800E20C8[1]);
  if (D_800E20D4 == 0) {
    return;
  }

  D_800E20C8[0] = n64HeapAlloc(D_800E20D4);
  D_800E20C8[1] = n64HeapAlloc(D_800E20D4);
  D_800E20D0 = D_800E20C8[draw_buffer];
}

void inits_bunch_of_stuff_q_allocs_heap(void) {
  s32 sp1C;
  u16 *sp18;

  D_800E20B8[0] = n64HeapAlloc(0x4000 * sizeof(Gfx));
  D_800E20B8[1] = n64HeapAlloc(0x4000 * sizeof(Gfx));
  D_800CFD40 = 0;
  D_800E20C4 = 0x4000 * sizeof(Gfx);
  D_800CFD44 = 0;
  D_800E20D4 = 0;
  sp18 = cfb[0];
  for (sp1C = screen_1_height * screen_1_width; sp1C != 0; sp1C--) {
    *sp18++ = 0;
  }
  osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
  osViSwapBuffer(cfb[0]);

  D_800E2070[0].unk0 = 2;
  D_800E2070[0].unk2 = 0;
  D_800E2070[0].unk4 = &D_800E1FA0[0];
  D_800E2070[1].unk0 = 2;
  D_800E2070[1].unk2 = 1;
  D_800E2070[1].unk4 = &D_800E1FA0[1];

  D_800E1FA0[0].next = NULL;
  D_800E1FA0[0].state = 0;
  D_800E1FA0[0].flags = OS_SC_SWAPBUFFER | OS_SC_LAST_TASK | OS_SC_RCP_MASK;
  D_800E1FA0[0].framebuffer = cfb[0];
  D_800E1FA0[0].msgQ = &D_8010BB08;
  D_800E1FA0[0].msg = &D_800E2070[0];

  D_800E1FA0[0].list.t.type = M_GFXTASK;
  D_800E1FA0[0].list.t.flags = 0;
  D_800E1FA0[0].list.t.ucode_boot = (u64 *) rspbootTextStart;
  D_800E1FA0[0].list.t.ucode_boot_size = (intptr_t) gspF3DEX2_NoN_fifoTextStart - (intptr_t) rspbootTextStart;
  D_800E1FA0[0].list.t.ucode = (u64 *) gspF3DEX2_NoN_fifoTextStart;
  D_800E1FA0[0].list.t.ucode_size = 0x1000;
  D_800E1FA0[0].list.t.ucode_data = (u64 *) gspF3DEX2_NoN_fifoDataStart;
  D_800E1FA0[0].list.t.ucode_data_size = 0x800;
  D_800E1FA0[0].list.t.dram_stack = D_800E21C0;
  D_800E1FA0[0].list.t.dram_stack_size = 0x400;
  D_800E1FA0[0].list.t.output_buff = D_800E31C0;
  D_800E1FA0[0].list.t.output_buff_size = D_800E31C0 + 0x4000;
  D_800E1FA0[0].list.t.yield_data_ptr = D_800E25C0;
  D_800E1FA0[0].list.t.yield_data_size = 0xC00;
  D_800E1FA0[0].list.t.data_ptr = (u64 *) D_800E20B8[0];
  D_800E1FA0[0].list.t.data_size = 0;

  D_800E1FA0[1].next = NULL;
  D_800E1FA0[1].state = 0;
  D_800E1FA0[1].flags = OS_SC_SWAPBUFFER | OS_SC_LAST_TASK | OS_SC_RCP_MASK;
  D_800E1FA0[1].framebuffer = cfb[1];
  D_800E1FA0[1].msgQ = &D_8010BB08;
  D_800E1FA0[1].msg = &D_800E2070[1];

  D_800E1FA0[1].list.t.type = M_GFXTASK;
  D_800E1FA0[1].list.t.flags = 0;
  D_800E1FA0[1].list.t.ucode_boot = (u64 *) rspbootTextStart;
  D_800E1FA0[1].list.t.ucode_boot_size = (intptr_t) gspF3DEX2_NoN_fifoTextStart - (intptr_t) rspbootTextStart;
  D_800E1FA0[1].list.t.ucode = (u64 *) gspF3DEX2_NoN_fifoTextStart;
  D_800E1FA0[1].list.t.ucode_size = 0x1000;
  D_800E1FA0[1].list.t.ucode_data = (u64 *) gspF3DEX2_NoN_fifoDataStart;
  D_800E1FA0[1].list.t.ucode_data_size = 0x800;
  D_800E1FA0[1].list.t.dram_stack = D_800E21C0;
  D_800E1FA0[1].list.t.dram_stack_size = 0x400;
  D_800E1FA0[1].list.t.output_buff = D_800E31C0;
  D_800E1FA0[1].list.t.output_buff_size = D_800E31C0 + 0x4000;
  D_800E1FA0[1].list.t.yield_data_ptr = D_800E25C0;
  D_800E1FA0[1].list.t.yield_data_size = 0xC00;
  D_800E1FA0[1].list.t.data_ptr = (u64 *) D_800E20B8[1];
  D_800E1FA0[1].list.t.data_size = 0;
  func_80076EA0(0);
}

Gfx *FUN_80048934_inits_struct_q(Gfx *gdl, s32 arg1) {
  gDPSetCycleType(gdl++, G_CYC_FILL);
  gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
  gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 399, 299);
  gDPSetFillColor(gdl++, 0x00010001);
  gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 400, OS_K0_TO_PHYSICAL(cfb[arg1]));
  gDPFillRectangle(gdl++, 0, 0, 399, 299);
  gDPPipeSync(gdl++);
  return gdl;
}

Gfx *FUN_80048A6C_inits_struct_q(Gfx *gdl, s32 arg1) {
  gDPSetCycleType(gdl++, G_CYC_FILL);
  gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
  gDPSetFillColor(gdl++, 0xFFFCFFFC);
  gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_K0_TO_PHYSICAL(lzobuf));
  gDPFillRectangle(gdl++, 0, 0, 399, 299);
  gDPPipeSync(gdl++);
  return gdl;
}

void has_rounds_and_floors_large_liner(void) {
  OSScTask *sp6C;

  frametime_update(scheduler.frameCount);
  D_801295E8 = osGetCount();
  sp6C = &D_800E1FA0[draw_buffer];
  ((UnkStruct_91 *) sp6C->msg)->unk8 = osGetTime();

  g_gdl = D_800E20B8[draw_buffer];
  if (TRUE) {
    D_800E20D0 = D_800E20C8[draw_buffer];
  }

  gSPSegment(g_gdl++, 0, 0);
  gSPSegment(g_gdl++, 0x02, OS_K0_TO_PHYSICAL(cfb[draw_buffer]));
  gSPSegment(g_gdl++, 0x03, OS_K0_TO_PHYSICAL(lzobuf));

  g_gdl = FUN_80048A6C_inits_struct_q(g_gdl, draw_buffer);
  g_gdl = FUN_80048934_inits_struct_q(g_gdl, draw_buffer);

  gDPPipeSync(g_gdl++);
  gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_K0_TO_PHYSICAL(cfb[draw_buffer]));
  gDPSetScissor(g_gdl++, G_SC_NON_INTERLACE, screen_3_width, screen_3_height, screen_4_width - 1, screen_4_height - 1);
  gDPSetDepthImage(g_gdl++, OS_K0_TO_PHYSICAL(lzobuf));
  gSPClipRatio(g_gdl++, FRUSTRATIO_3);
  gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
  gSPSetGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
  gSPDisplayList(g_gdl++, D_800CFD70);

  if (TRUE) {
    s32 sp30;
    s32 sp2C = 0;

    if (D_800CFE5C != 0) {
      for (sp30 = 0; sp30 < 4; sp30++) {
        g_PV_ptr = &g_PV_arr[sp30];
        FUN_010870_interesting_stuff_large_liner();
      }
      D_800CFE24 = FALSE;
    } else {
      for (sp30 = 0; sp30 < D_800CFED4; sp30++) {
        g_PV_ptr = &g_PV_arr[sp30];
        FUN_010870_interesting_stuff_large_liner();
      }
    }
  }

  FUN_032F00_MVC_control_menu_choice_process();

  D_801295F0 = sp6C->totalTime;
  D_801295E4 = osGetCount();
  D_801295EC = D_801295E4;
  if (D_800CFEE0 != 0) {
    func_800A9010(&g_gdl);  // display fps measurement
  }
  D_801295E0 = D_801295E4;

  gDPFullSync(g_gdl++);
  gSPEndDisplayList(g_gdl++);

  FUN_80048020_eightliner();
  FUN_800480E0_threeliner_glist();
  FUN_80048150_threeliner_vlist();

  sp6C->list.t.data_size = (intptr_t) g_gdl - (intptr_t) D_800E20B8[draw_buffer];
  sp6C->state = 0;
  sp6C->next = NULL;
  sp6C->totalTime = 0;
  osSendMesg(osScGetCmdQ(&scheduler), sp6C, OS_MESG_BLOCK);
  D_800CFEF0++;
  ((UnkStruct_91 *) sp6C->msg)->unk10 = osGetTime();

  // TODO: investigate this
  D_800CFED8++;  // used in FUN_027BF0_8006332c_thirtyfiveliner() from 027BF0.c
}

void has_rounds_and_floors_2_large_liner(void) {
  OSScTask *sp5C;

  osCreateMesgQueue(&D_800E20D8, D_800E2120, 1);
  osSetEventMesg(OS_EVENT_SP, &D_800E20D8, NULL);
  osCreateMesgQueue(&D_800E20F0, D_800E2124, 1);
  osSetEventMesg(OS_EVENT_DP, &D_800E20F0, NULL);
  osCreateMesgQueue(&D_800E2108, D_800E2128, 1);
  osViSetEvent(&D_800E2108, NULL, 1);

  for (;;) {
    sp5C = &D_800E1FA0[draw_buffer];
    ((UnkStruct_91 *) sp5C->msg)->unk8 = osGetTime();
    g_gdl = D_800E20B8[draw_buffer];
    D_800E20D0 = D_800E20C8[draw_buffer];

    gSPSegment(g_gdl++, 0, 0);
    gSPSegment(g_gdl++, 0x02, OS_K0_TO_PHYSICAL(cfb[draw_buffer]));
    gSPSegment(g_gdl++, 0x03, OS_K0_TO_PHYSICAL(lzobuf));

    if (D_800CFD4C) {
      g_gdl = FUN_80048A6C_inits_struct_q(g_gdl, draw_buffer);
    }
    if (D_800CFD48) {
      g_gdl = FUN_80048934_inits_struct_q(g_gdl, draw_buffer);
    }

    gDPPipeSync(g_gdl++);
    gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_K0_TO_PHYSICAL(cfb[draw_buffer]));
    gDPSetScissor(g_gdl++, G_SC_NON_INTERLACE, screen_3_width, screen_3_height, screen_4_width - 1, screen_4_height - 1);
    gDPSetDepthImage(g_gdl++, OS_K0_TO_PHYSICAL(lzobuf));
    gSPClipRatio(g_gdl++, FRUSTRATIO_3);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gSPSetGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPDisplayList(g_gdl++, D_800CFD70);

    g_gdl = func_8007DA00(g_gdl);  // haluci_update

    gDPFullSync(g_gdl++);
    gSPEndDisplayList(g_gdl++);

    FUN_80048020_eightliner();
    FUN_800480E0_threeliner_glist();
    FUN_80048150_threeliner_vlist();

    sp5C->list.t.data_size = (intptr_t) g_gdl - (intptr_t) D_800E20B8[draw_buffer];
    sp5C->state = 0;
    sp5C->next = NULL;
    sp5C->totalTime = 0;

    osWritebackDCacheAll();
    osSpTaskLoad(&sp5C->list);
    osSpTaskStartGo(&sp5C->list);
    osRecvMesg(&D_800E20D8, NULL, OS_MESG_BLOCK);
    osDpSetNextBuffer(D_800E31C0, D_800E31C0[1]);
    osRecvMesg(&D_800E20F0, NULL, OS_MESG_BLOCK);
    osViSwapBuffer(cfb[draw_buffer]);
    if (D_800E2108.validCount >= D_800E2108.msgCount) {
      osRecvMesg(&D_800E2108, NULL, OS_MESG_BLOCK);
    }
    osRecvMesg(&D_800E2108, NULL, OS_MESG_BLOCK);

    draw_buffer ^= 1;
    ((UnkStruct_91 *) sp5C->msg)->unk10 = osGetTime();
    D_800CFED8++;
  }
}

void four_arguments_get_debug_printed(void) {
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
  func_8007CF40(1);  // haluci_init(1)
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
