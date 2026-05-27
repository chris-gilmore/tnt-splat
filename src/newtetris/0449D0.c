#include "common.h"

static f32 D_801201E0;
static f32 D_801201E4;
static f32 D_801201E8;
static f32 D_801201EC;
static f32 D_801201F0;
static f32 D_801201F4;
static f32 D_801201F8;
static f32 D_801201FC;
static void *D_80120200;  // IMG_TETRIS_START
static void *D_80120204;  // IMG_TETRIS_START_PAL

static UnkStruct_11 D_800D31A0 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0.0, 0, 986
};
static s32 D_800D31D0 = 3950;
static s32 D_800D31D4 = 0;
static s32 D_800D31D8 = 0;
static s32 D_800D31DC = 0;
static s32 D_800D31E0 = 1;
static s32 D_800D31E4 = 0;

static void func_8007F2C0(void);
static void func_8007F320(void);
static void func_8007FD74(UnkStruct_94 *);

// fade to black
s32 func_8007E750(void) {
  if (D_801201E4 <= 1.0) {
    gDPPipeSync(g_gdl++);
    gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetRenderMode(g_gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(g_gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(g_gdl++, 0, 0, 0x00, 0x00, 0x00, D_801201E4 * 255);
    gDPFillRectangle(g_gdl++, 0, 0, 400, 300);
    gDPPipeSync(g_gdl++);

    D_801201E4 += D_801201E0 * frametime_delta();
    if (D_801201E4 >= 1.0) {
      return 1;
    }

    return 0;
  }

  return 1;
}

void func_8007E9F8(f32 arg0) {
  D_801201E0 = 1.0 / arg0;
  D_801201E4 = 0;
}

// fade from black
s32 func_8007EA2C(void) {
  if (D_801201EC >= 0.0) {
    gDPPipeSync(g_gdl++);
    gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetRenderMode(g_gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(g_gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(g_gdl++, 0, 0, 0x00, 0x00, 0x00, D_801201EC * 255);
    gDPFillRectangle(g_gdl++, 0, 0, 400, 300);
    gDPPipeSync(g_gdl++);

    D_801201EC -= D_801201E8 * frametime_delta();
    if (D_801201EC <= 0.0) {
      return 1;
    }

    return 0;
  }

  return 1;
}

void func_8007ECC8(f32 arg0) {
  D_801201E8 = 1.0 / arg0;
  D_801201EC = 1;
}

// fade to white
s32 func_8007ED00(void) {
  if (D_801201F4 <= 1.0) {
    gDPPipeSync(g_gdl++);
    gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetRenderMode(g_gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(g_gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(g_gdl++, 0, 0, 0xFF, 0xFF, 0xFF, D_801201F4 * 255);
    gDPFillRectangle(g_gdl++, 0, 0, 400, 300);
    gDPPipeSync(g_gdl++);

    D_801201F4 += D_801201F0 * frametime_delta();
    if (D_801201F4 >= 1.0) {
      return 1;
    }

    return 0;
  }

  return 1;
}

void func_8007EFB0(f32 arg0) {
  D_801201F0 = 1.0 / arg0;
  D_801201F4 = 0;
}

// fade from white
s32 func_8007EFE4(void) {
  if (D_801201FC >= 0.0) {
    gDPPipeSync(g_gdl++);
    gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetRenderMode(g_gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(g_gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(g_gdl++, 0, 0, 0xFF, 0xFF, 0xFF, D_801201FC * 255);
    gDPFillRectangle(g_gdl++, 0, 0, 400, 300);
    gDPPipeSync(g_gdl++);

    D_801201FC -= D_801201F8 * frametime_delta();
    if (D_801201FC <= 0.0) {
      return 1;
    }

    return 0;
  }

  return 1;
}

void func_8007F288(f32 arg0) {
  D_801201F8 = 1.0 / arg0;
  D_801201FC = 1;
}

static void func_8007F2C0(void) {
  D_800CFD4C = TRUE;
  func_80076EC0(&D_800D31A0, TRUE);
  func_800A4654(D_800D31A0.unk0);
  Audio2_GFXDone_SendPlayMessage(&D_80120A70);
  Audio_LoadSFX(&g_introSfxBank);
  D_800D31D8 = 0;
}

static void func_8007F320(void) {
  func_80077028(&D_800D31A0);
}

void func_8007F344(void) {
  switch (D_800D31DC) {
  case 1:
    if (D_800D31A0.unk0->unk6 >= 4) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_0);
      D_800D31DC = 2;
    }
    break;
  case 2:
    if (D_800D31A0.unk0->unk6 >= 816) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_1);
      D_800D31DC = 3;
    }
    break;
  case 3:
    if (D_800D31A0.unk0->unk6 >= 1067) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_2);
      D_800D31DC = 4;
    }
    break;
  case 4:
    if (D_800D31A0.unk0->unk6 >= 1272) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_3);
      D_800D31DC = 5;
    }
    break;
  case 5:
    if (D_800D31A0.unk0->unk6 >= 1605) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_4);
      D_800D31DC = 6;
    }
    break;
  case 6:
    if (D_800D31A0.unk0->unk6 >= 1885) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_5);
      D_800D31DC = 7;
    }
    break;
  case 7:
    if (D_800D31A0.unk0->unk6 >= 2060) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_6);
      D_800D31DC = 8;
    }
    break;
  case 8:
    if (D_800D31A0.unk0->unk6 >= 2733) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_7);
      D_800D31DC = 9;
    }
    break;
  case 9:
    if (D_800D31A0.unk0->unk6 >= 2789) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_8);  // (bug?) ropes falling, but can't be heard
      D_800D31DC = 10;
    }
    break;
  case 10:
    if (D_800D31A0.unk0->unk6 >= 2987) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_9);
      D_800D31DC = 11;
    }
    break;
  case 11:
    if (D_800D31A0.unk0->unk6 >= 3340) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_10);
      D_800D31DC = 12;
    }
    break;
  case 12:
    if (D_800D31A0.unk0->unk6 >= 3750) {
      Audio2_Play_SFX(&D_801235B0, &g_introSfxBank, SFX_INTRO_11);
      D_800D31DC = 13;
    }
    break;
  }

  if (D_800D31D8 == 0) {
    if (D_800D31E0 != 0) {
      func_8007F2C0();
      D_800D31DC = 1;
      D_800D31E0 = 0;
    }

    // A_BUTTON / CONT_A || START_BUTTON / CONT_START
    if ((g_PV_arr->unk24 & 0x8000) || (g_PV_arr->unk24 & 0x1000) || (D_800D31A0.unk0->unk6 >= D_800D31D0)) {
      func_8007EFB0(20);
      D_800D31DC = 13;
      Audio2_GFXDone_SendStopMessage(&D_801235B0);
      D_800D31E0 = 1;
      D_800D31D8 = 1;
    }

    func_80077098(&D_800D31A0);
  }

  if (D_800D31D8 == 1) {
    if (D_800D31E0 != 0) {
      D_800D31E0 = 0;
    } else {
      func_80077098(&D_800D31A0);
    }

    if (func_8007ED00() == 1) {
      main_8004A34C_threeliner();
      func_8007F320();
      D_800D31E0 = 1;
      D_800D31D8 = 2;
      return;
    }
  }

  if ((D_800D31D8 == 2) && (D_800D31E0 != 0)) {
    main_8004A34C_threeliner();
    D_80120200 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_TETRIS_START));
    FUN_03A750_800746c0_twentyliner(&D_273A00, D_80120200, IMG_TETRIS_START);
    D_80120204 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_TETRIS_START_PAL));
    FUN_03A750_800746c0_twentyliner(&D_273A00, D_80120204, IMG_TETRIS_START_PAL);
    D_800D31E0 = 1;
    D_800D31D8 = 3;
    func_8007F288(20);
    func_8007EFE4();
    return;
  }

  if (D_800D31D8 == 3) {
    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80120200, D_80120204, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
    if (func_8007EFE4() == 1) {
      D_800D31D8 = 4;
      D_800D31E4 = 0;
    }
  }

  if (D_800D31D8 == 4) {
    // A_BUTTON / CONT_A || START_BUTTON / CONT_START
    if (((g_PV_arr->unk24 & 0x8000) && (D_800D31E4 >= 60)) || ((g_PV_arr->unk24 & 0x1000) && (D_800D31E4 >= 60)) || (D_800D31E4 >= 300)) {
      FUN_026900_80060d58_elevenliner(1);
      main_8004A34C_threeliner();
      n64HeapUnalloc(D_80120200);
      n64HeapUnalloc(D_80120204);
      Audio_LoadSFX(&g_menuSfxBank);
      func_800905E8(0);
      D_800CFD48 = TRUE;
      func_80061134(400, 300);
      D_800D31D8++;
      return;
    }

    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80120200, D_80120204, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
    D_800D31E4 += 1;
  }

  switch (D_800D31D8) {
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    D_800D31D8++;
    break;
  case 10:
    D_800D31E4 = 0;
    FUN_026900_80060d58_elevenliner(0);
    D_800CFEE8 = 4;
    D_800D31D8 = 0;
    D_800D31D4 = 1;
    break;
  }
}

void func_8007FBB0(void **arg0, u32 arg1) {
  main_8004A34C_threeliner();
  *arg0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg1));
  FUN_03A750_800746c0_twentyliner(&D_273A00, *arg0, arg1);
}

// unused
void func_8007FC14(UnkStruct_94 *arg0, s32 arg1) {
  if (arg0->unk0 != NULL) {
    arg0->unk8 += arg0->unkC * arg1;
    if (arg0->unk8 < 0) {
      arg0->unk8 = 0;
    }
    if (arg0->unk8 >= 0xFF01) {
      arg0->unk8 = 0xFF00;
    }
  }
}

// unused
void func_8007FC74(UnkStruct_94 *arg0, Gfx **p_gdl) {
  if ((arg0->unk8 != 0) && (arg0->unk0 != NULL)) {
    func_8005BBFC(p_gdl);
    weird_lots_of_magic_number_setting_66xrefs(p_gdl, arg0->unk0, NULL, arg0->unk4.x, arg0->unk4.y, 0xFF, 0xFF, 0xFF, arg0->unk8 >> 8);
    func_8005BE40(p_gdl);
  }
}

// unused
void func_8007FD14(UnkStruct_94 *arg0, void *arg1, Point arg2, s32 arg3) {
  arg0->unk0 = arg1;
  arg0->unk4 = arg2;
  arg0->unk8 = 0xFF00;
  arg0->unkC = -arg0->unk8 / arg3;
}

static void func_8007FD74(UnkStruct_94 *arg0) {
  arg0->unk8 = 0;
  arg0->unkC = 0;
  arg0->unk0 = NULL;
}

// unused
void func_8007FD84(UnkStruct_94 *arg0) {
  func_8007FD74(arg0);
}
