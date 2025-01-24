#include "common.h"

static u8 D_800D0560 = 0;
static Gfx D_800D0568[] = {
  gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
  gsDPPipeSync(),
  gsDPSetTextureLUT(G_TT_NONE),
  gsDPSetAlphaCompare(G_AC_NONE),
  gsDPSetTexturePersp(G_TP_NONE),
  gsDPSetTextureFilter(G_TF_AVERAGE),
  gsDPSetTextureConvert(G_TC_FILT),
  gsDPSetTextureDetail(G_TD_CLAMP),
  gsDPSetTextureLOD(G_TL_TILE),
  gsSPEndDisplayList(),
};

UnkStruct_0 *D_8011FC10;
static s32 D_8011FC14;  // unused
static UnkStruct_22 D_8011FC18;
static u8 D_8011FC54;

static void   Minos_8006f260_eightliner_calls_8007641c_4_times(Mino *);
static void   Minos_8006f300_eightliner_calls_80076458_4_times(Mino *);
static void   func_8006F39C(UnkStruct_8 *);
static void   Minos_8006f4b4_thirtyliner_interesting(UnkStruct_8 *);
static void   func_8006F7E8(UnkStruct_8 *);
static void   Minos_8006f7f0_sets_struct_0_to_0x11(s8 *);
static void   Minos_8006f994_sets_struct_0_to_0x23(s8 *, s8 *);
static void   Minos_8006fc8c_twentyfive_liner(u8, u8);
static void   Minos_800704e0_threeliner_sets_0x130(Mino *);

static void Minos_8006f260_eightliner_calls_8007641c_4_times(Mino *arg0) {
  register UnkStruct_22 *var_s0 = &D_8011FC18;
  register UnkStruct_24 *var_s1 = &D_8011FC18.unk28->unk14;

  var_s1->unk0 = &arg0->unk24;
  var_s1->unk4 = &arg0->unkB0;

  func_8007641C(&var_s0->unk0[0], &var_s1->unk24[0]);
  func_8007641C(&var_s0->unk0[1], &var_s1->unk24[1]);
  func_8007641C(&var_s0->unk0[2], &var_s1->unk24[2]);
  func_8007641C(&var_s0->unk0[3], &var_s1->unk24[3]);

  D_8011FC18.unk28->unk58(D_8011FC18.unk28);
}

static void Minos_8006f300_eightliner_calls_80076458_4_times(Mino *arg0) {
  register UnkStruct_22 *var_s0 = &D_8011FC18;
  register UnkStruct_24 *var_s1 = &D_8011FC18.unk28->unk14;

  var_s1->unk0 = &arg0->unk24;
  var_s1->unk4 = &arg0->unkF0;

  func_80076458(&var_s0->unk0[0], &var_s1->unk24[0]);
  func_80076458(&var_s0->unk0[1], &var_s1->unk24[1]);
  func_80076458(&var_s0->unk0[2], &var_s1->unk24[2]);
  func_80076458(&var_s0->unk0[3], &var_s1->unk24[3]);

  var_s0->unk28->unk58(var_s0->unk28);
}

static void func_8006F39C(UnkStruct_8 *arg0) {
  register UnkStruct_14 *var_a1 = D_8011FC18.unk0;
  register s32 temp_a2;
  register s32 temp_a3;
  register UnkStruct_22 *temp_t0 = &D_8011FC18;
  register u16 temp_t1;
  register u16 temp_t2;
  register s32 temp_t3;
  register s32 temp_t4;
  register s32 temp_t5;
  register s32 unused;

  temp_t0->unk2C = 1;
  temp_t0->unk2E = D_8011FC10->unkA.x;
  temp_t0->unk30 = D_8011FC10->unkA.y;

  temp_t1 = D_8011FC10->unk8;

  temp_a2 = arg0->unk6.p.x + arg0->unk0.p.x - D_8011FC10->unkE.x;
  temp_a3 = arg0->unk6.p.y + arg0->unk0.p.y - D_8011FC10->unkE.y;

  var_a1[0].unk0.p.x = (u32)temp_a2 - temp_t1; var_a1[0].unk0.p.y = (u32)temp_a3 - temp_t1;
  var_a1[1].unk0.p.x = (u32)temp_a2 + temp_t1; var_a1[1].unk0.p.y = (u32)temp_a3 - temp_t1;
  var_a1[2].unk0.p.x = (u32)temp_a2 - temp_t1; var_a1[2].unk0.p.y = (u32)temp_a3 + temp_t1;
  var_a1[3].unk0.p.x = (u32)temp_a2 + temp_t1; var_a1[3].unk0.p.y = (u32)temp_a3 + temp_t1;

  temp_t2 = D_8011FC10->unk2;

  temp_t4 = (((u32)temp_a2 * temp_t2) >> 14) + D_8011FC10->unk12.x;
  temp_t5 = (((u32)temp_a3 * temp_t2) >> 14) + D_8011FC10->unk12.y;

  temp_t3 = (u32)temp_t2 >> 7;
  var_a1[0].p.x = temp_t4 - temp_t3;
  var_a1[0].p.y = temp_t5 - temp_t3;
  var_a1[3].p.x = temp_t4 + temp_t3;
  var_a1[3].p.y = temp_t5 + temp_t3;
}

static void Minos_8006f4b4_thirtyliner_interesting(UnkStruct_8 *arg0) {
  register UnkStruct_14 *var_s0 = D_8011FC18.unk0;
  register s32 temp_s1;
  register s32 temp_s2;
  register s32 temp_s3;
  register s32 temp_s4;
  register s32 temp_s5;
  register u16 temp_s6;
  register s16 temp_s7;
  register s16 sp42;
  register s16 sp40;
  register s32 sp3C;  // unused
  register s16 sp3A;  // unused
  register s16 sp38;

  D_8011FC18.unk2C = 2;
  temp_s1 = sins(arg0->unkC.angle);
  temp_s2 = coss(arg0->unkC.angle);
  temp_s5 = D_8011FC10->scale;
  sp40 = arg0->unk6.p.x - D_8011FC10->unkE.x;
  sp42 = arg0->unk6.p.y - D_8011FC10->unkE.y;
  temp_s3 = arg0->unk0.p.x - D_8011FC10->unk8;
  temp_s4 = arg0->unk0.p.y - D_8011FC10->unk8;
  var_s0[0].unk0.p.x = (((temp_s3 * temp_s2) - (temp_s4 * temp_s1)) >> 15) + sp40;
  var_s0[0].unk0.p.y = (((temp_s3 * temp_s1) + (temp_s4 * temp_s2)) >> 15) + sp42;
  temp_s3 += temp_s5;
  var_s0[1].unk0.p.x = (((temp_s3 * temp_s2) - (temp_s4 * temp_s1)) >> 15) + sp40;;
  var_s0[1].unk0.p.y = (((temp_s3 * temp_s1) + (temp_s4 * temp_s2)) >> 15) + sp42;
  temp_s4 += temp_s5;
  var_s0[3].unk0.p.x = (((temp_s3 * temp_s2) - (temp_s4 * temp_s1)) >> 15) + sp40;;
  var_s0[3].unk0.p.y = (((temp_s3 * temp_s1) + (temp_s4 * temp_s2)) >> 15) + sp42;
  temp_s3 -= temp_s5;
  var_s0[2].unk0.p.x = (((temp_s3 * temp_s2) - (temp_s4 * temp_s1)) >> 15) + sp40;;
  var_s0[2].unk0.p.y = (((temp_s3 * temp_s1) + (temp_s4 * temp_s2)) >> 15) + sp42;
  temp_s6 = D_8011FC10->unk2;
  temp_s7 = D_8011FC10->unk12.x;
  sp38 = D_8011FC10->unk12.y;
  var_s0[0].p.x = ((u32)(var_s0[0].unk0.p.x * temp_s6) >> 14) + temp_s7;
  var_s0[0].p.y = ((u32)(var_s0[0].unk0.p.y * temp_s6) >> 14) + sp38;
  var_s0[1].p.x = ((u32)(var_s0[1].unk0.p.x * temp_s6) >> 14) + temp_s7;
  var_s0[1].p.y = ((u32)(var_s0[1].unk0.p.y * temp_s6) >> 14) + sp38;
  var_s0[2].p.x = ((u32)(var_s0[2].unk0.p.x * temp_s6) >> 14) + temp_s7;
  var_s0[2].p.y = ((u32)(var_s0[2].unk0.p.y * temp_s6) >> 14) + sp38;
  var_s0[3].p.x = ((u32)(var_s0[3].unk0.p.x * temp_s6) >> 14) + temp_s7;
  var_s0[3].p.y = ((u32)(var_s0[3].unk0.p.y * temp_s6) >> 14) + sp38;
}

static void func_8006F7E8(UnkStruct_8 *arg0) {
}

static void Minos_8006f7f0_sets_struct_0_to_0x11(s8 *arg0) {
  register Gfx *gdl;

  gdl = g_gdl;

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

  gDPLoadSync(gdl++);

  gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 4096, arg0);

  gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 31, 2048);

  gSPTexture(gdl++, 0x8000, 0x8000, 0, D_800D0560, G_ON);

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x0000, D_800D0560, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);

  gDPSetTileSize(gdl++, D_800D0560, 0, 0, 28, 28);

  D_8011FC54 = D_800D0560;
  D_800D0560 ^= 2;

  g_gdl = gdl;
}

static void Minos_8006f994_sets_struct_0_to_0x23(s8 *arg0, s8 *arg1) {
  register Gfx *gdl;

  gdl = g_gdl;

  gDPLoadSync(gdl++);

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

  gDPLoadSync(gdl++);

  gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 4096, arg0);

  gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 31, 2048);

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0008, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

  gDPLoadSync(gdl++);

  gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 4096, arg1);

  gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 31, 2048);

  gSPTexture(gdl++, 0x8000, 0x8000, 0, D_800D0560, G_ON);

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x0000, D_800D0560, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);

  gDPSetTileSize(gdl++, D_800D0560, 0, 0, 28, 28);

  gDPTileSync(gdl++);

  gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x0008, D_800D0560 + 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);

  gDPSetTileSize(gdl++, D_800D0560 + 1, 0, 0, 28, 28);

  D_8011FC54 = D_800D0560;
  D_800D0560 ^= 2;

  g_gdl = gdl;
}

static void Minos_8006fc8c_twentyfive_liner(u8 arg0, u8 is_transparent) {
  register Gfx *gdl;

  if ((arg0 != D_8011FC18.unk38) || (is_transparent != D_8011FC18.is_transparent)) {
    gdl = g_gdl;
    gDPPipeSync(gdl++);
    if (arg0 != D_8011FC18.unk38) {
      switch (arg0) {
      case 1:
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetCombineLERP(gdl++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, PRIMITIVE, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        break;
      case 2:
        gDPSetCycleType(gdl++, G_CYC_2CYCLE);
        gDPSetCombineLERP(gdl++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, 0, 0, 0, SHADE, ENVIRONMENT, PRIMITIVE, COMBINED, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        break;
      }
      D_8011FC18.unk38 = arg0;
    }
    if (is_transparent != D_8011FC18.is_transparent) {
      if (is_transparent) {
        gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
      } else {
        gDPSetRenderMode(gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
      }
      D_8011FC18.is_transparent = is_transparent;
    }
    g_gdl = gdl;
  }
}

void Minos_Mino_Render(Mino *arg0, UnkStruct_8 *arg1) {
  register u8 temp_s0;
  register u8 alpha;
  register u8 unused_s2;
  register u8 unused_s3;
  register u8 unused_s4;
  register Gfx *gdl;

  temp_s0 = arg0->unk20.c.lo;
  if (arg0->unk1C == 0xFF) {
    alpha = D_8011FC18.alpha;
  } else if (D_8011FC18.alpha == 0xFF) {
    alpha = arg0->unk1C;
  } else {
    alpha = arg0->unk1C * D_8011FC18.alpha / 0x100U;
  }
  if (alpha != 0) {
    D_8011FC18.unk34(arg1);
    if ((arg0->unk1 & 0x1) || (temp_s0 > 0)) {
      if (temp_s0 < 0xFF) {
        Minos_8006f260_eightliner_calls_8007641c_4_times(arg0);
      }
      if (temp_s0 > 0) {
        Minos_8006f300_eightliner_calls_80076458_4_times(arg0);
      }
      arg0->unk1 &= ~0x1;
    }
    if (temp_s0 == 0) {
      Minos_8006f7f0_sets_struct_0_to_0x11(&arg0->unkB0);
    } else if (temp_s0 == 0xFF) {
      Minos_8006f7f0_sets_struct_0_to_0x11(&arg0->unkF0);
    } else {
      Minos_8006f994_sets_struct_0_to_0x23(&arg0->unkB0, &arg0->unkF0);
    }
    if ((temp_s0 == 0) || (temp_s0 == 0xFF)) {
      (alpha == 0xFF) ? Minos_8006fc8c_twentyfive_liner(1, FALSE) : Minos_8006fc8c_twentyfive_liner(1, TRUE);
    } else {
      (alpha == 0xFF) ? Minos_8006fc8c_twentyfive_liner(2, FALSE) : Minos_8006fc8c_twentyfive_liner(2, TRUE);
    }

    gdl = g_gdl;

    gDPSetPrimColor(gdl++, 0, 0, arg0->unk4.diffuse_red >> 4, arg0->unk4.diffuse_green >> 4, arg0->unk4.diffuse_blue >> 4, alpha);
    gDPSetEnvColor(gdl++, arg0->unk4.specular_red >> 4, arg0->unk4.specular_green >> 4, arg0->unk4.specular_blue >> 4, temp_s0);
    gDPPipeSync(gdl++);

    if (TRUE) {
      register UnkStruct_22 *var_s6 = &D_8011FC18;

      switch (var_s6->unk2C) {
      case 1:
        // gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)
        gSPTextureRectangle(gdl++, var_s6->unk0[0].p.x, var_s6->unk0[0].p.y, var_s6->unk0[3].p.x, var_s6->unk0[3].p.y, D_8011FC54, 0, 0, var_s6->unk2E, var_s6->unk30);
        break;
      case 2:
        gSPModifyVertex(gdl++, 0, G_MWO_POINT_XYSCREEN, (var_s6->unk0[0].p.x << 0x10) | var_s6->unk0[0].p.y);
        gSPModifyVertex(gdl++, 1, G_MWO_POINT_XYSCREEN, (var_s6->unk0[1].p.x << 0x10) | var_s6->unk0[1].p.y);
        gSPModifyVertex(gdl++, 2, G_MWO_POINT_XYSCREEN, (var_s6->unk0[2].p.x << 0x10) | var_s6->unk0[2].p.y);
        gSPModifyVertex(gdl++, 3, G_MWO_POINT_XYSCREEN, (var_s6->unk0[3].p.x << 0x10) | var_s6->unk0[3].p.y);
        // 2 Triangles - gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1)
        gSP2Triangles(gdl++, 0, 1, 2, 0, 1, 3, 2, 0);
        break;
      }
    }

    g_gdl = gdl;
  }
}

void Minos_800702e4_nineliner(Mino *arg0) {
  Minos_80070818_oneliner_sets_arg0_0x130_to_arg1(arg0, g_cubeTiles_ptr->unkDC00[0x0]);
  func_800A2F30(&arg0->unk24, arg0->unk130);
  arg0->unk1C = 0xFF;
  arg0->unk1E = arg0->unk1C;
  arg0->unk1D = 0;
  arg0->unk20.s = 0;
  arg0->unk22 = 0;
  arg0->unk0 = 1;
  arg0->unk1 |= 1;
}

void Minos_80070398_fourteenliner(Mino *arg0, Mino *arg1) {
  arg0->unk0 = arg1->unk0;
  arg0->unk1 = arg1->unk1;
  arg0->unk20.s = arg1->unk20.s;
  arg0->unk22 = arg1->unk22;
  arg0->unk130 = arg1->unk130;
  arg0->unk1C = arg1->unk1C;
  arg0->unk2 = arg1->unk2;
  arg0->unk4 = arg1->unk4;
  arg0->unk10 = arg1->unk10;
  func_800A2F30(&arg0->unk24, &arg1->unk24);
}

static void Minos_800704e0_threeliner_sets_0x130(Mino *arg0) {
  register s32 var_s0 = func_800A2F50(arg0->unk130, &arg0->unk24);

  if (var_s0 == 0) {
    arg0->unk130 = NULL;
  }
}

void Minos_80070528_Morph(Mino *arg0) {
  if (arg0->unk130 != NULL) {
    if (((u32)arg0->unk130 > 0x80000000) && ((u32)arg0->unk130 < 0x80400000)) {
      Minos_800704e0_threeliner_sets_0x130(arg0);
      arg0->unk1 |= 1;
    } else {
      rmonPrintf("****Morph: %x %x\n", arg0->unk130, arg0);
      Minos_80070818_oneliner_sets_arg0_0x130_to_arg1(arg0, g_cubeTiles_ptr->unkDC00[0xF]);
      Minos_800704e0_threeliner_sets_0x130(arg0);
      arg0->unk1 |= 1;
    }
  }

  if (arg0->unk2 != 0) {
    arg0->unk4.diffuse_red    += arg0->unk10.diffuse_red;
    arg0->unk4.diffuse_green  += arg0->unk10.diffuse_green;
    arg0->unk4.diffuse_blue   += arg0->unk10.diffuse_blue;
    arg0->unk4.specular_red   += arg0->unk10.specular_red;
    arg0->unk4.specular_green += arg0->unk10.specular_green;
    arg0->unk4.specular_blue  += arg0->unk10.specular_blue;
    arg0->unk2 -= 1;
  }

  if (arg0->unk1C != arg0->unk1E) {
    register u8 var_s0 = arg0->unk1C;
    register u8 var_s1 = arg0->unk1E;

    if (arg0->unk1D > 0) {
      if ((arg0->unk1D + var_s0) >= var_s1) {
        arg0->unk1C = arg0->unk1E;
        arg0->unk1D = 0;
      } else {
        arg0->unk1C += arg0->unk1D;
      }
    }
    if (arg0->unk1D < 0) {
      if ((arg0->unk1D + var_s0) <= var_s1) {
        arg0->unk1C = arg0->unk1E;
        arg0->unk1D = 0;
      } else {
        arg0->unk1C += arg0->unk1D;
      }
    }
  }

  if (arg0->unk22 != 0) {
    arg0->unk20.s += arg0->unk22;
    if (arg0->unk20.s < 0) {
      arg0->unk20.s = 0;
      arg0->unk22 = 0;
    }
    if (arg0->unk20.s > 0xFF) {
      arg0->unk20.s = 0xFF;
      arg0->unk22 = 0;
    }
  }
}

void Minos_80070818_oneliner_sets_arg0_0x130_to_arg1(Mino *arg0, s8 *arg1) {
  arg0->unk130 = arg1;
}

void Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(Mino *arg0, Color *arg1) {
  arg0->unk4 = *arg1;
  arg0->unk2 = 0;
}

void Minos_80070860_fortyliner(Mino *arg0, Color *arg1, s32 arg2) {
  arg0->unk10.diffuse_red    = (arg1->diffuse_red    - arg0->unk4.diffuse_red)    / arg2;
  arg0->unk10.diffuse_green  = (arg1->diffuse_green  - arg0->unk4.diffuse_green)  / arg2;
  arg0->unk10.diffuse_blue   = (arg1->diffuse_blue   - arg0->unk4.diffuse_blue)   / arg2;
  arg0->unk10.specular_red   = (arg1->specular_red   - arg0->unk4.specular_red)   / arg2;
  arg0->unk10.specular_green = (arg1->specular_green - arg0->unk4.specular_green) / arg2;
  arg0->unk10.specular_blue  = (arg1->specular_blue  - arg0->unk4.specular_blue)  / arg2;
  arg0->unk2 = arg2;
}

void Minos_800709d8_threeliner_sets_arg0_1c_1e_1d(Mino *arg0, u8 arg1) {
  arg0->unk1C = arg1;
  arg0->unk1E = arg1;
  arg0->unk1D = 0;
}

void Minos_800709EC(Mino *arg0, u8 arg1, s32 arg2) {
  arg0->unk1E = arg1;
  arg0->unk1D = (arg1 - arg0->unk1C) / arg2;
}

void Minos_80070a34_twentyliner(void) {
  register UnkStruct_0 *var_a0 = D_8011FC10;
  register u32 var_a1;

  if (var_a0->pattern & 0x8) {
    var_a0->unkE = var_a0->unk16;
  }

  if (var_a0->pattern & 0xD) {
    var_a0->unk12.x = var_a0->unk1A.x + ((var_a0->unkE.x * var_a0->unk2) >> 14) + (var_a0->unk2 >> 7);
    var_a0->unk12.y = var_a0->unk1A.y + ((var_a0->unkE.y * var_a0->unk2) >> 14) + (var_a0->unk2 >> 7);
  }

  if (var_a0->pattern & 0x1) {
    var_a0->unk4 = (float)0x1000000 / var_a0->unk2 + 0.5f;
  }

  if (var_a0->pattern & 0x3) {
    var_a1 = var_a0->unk2 * var_a0->scale;
    var_a1 >>= 8;
    var_a0->unk8 = var_a0->scale >> 1;
    var_a0->unkA.x = 0x200000 / var_a1;
    var_a0->unkA.y = 0x200000 / var_a1;
  }

  var_a0->pattern = 0x0;
}

void Minos_80070c40_twoliner_set_OR_1(u16 arg0) {
  D_8011FC10->unk2 = arg0;
  D_8011FC10->pattern |= 0x1;
}

void Minos_80070c70_threeliner_set_OR_8(s16 x, s16 y) {
  D_8011FC10->unk16.x = x;
  D_8011FC10->unk16.y = y;
  D_8011FC10->pattern |= 0x8;
}

void Minos_80070cb8_threeliner_set_OR_4(s16 x, s16 y) {
  D_8011FC10->unk1A.x = x;
  D_8011FC10->unk1A.y = y;
  D_8011FC10->pattern |= 0x4;
}

void Minos_SetScale(u16 scale) {
  D_8011FC10->scale = scale;
  D_8011FC10->pattern |= 0x2;
}

void Minos_SetAlpha(u8 alpha) {
  D_8011FC18.alpha = alpha;
}

void Minos_Init(UnkStruct_0 *arg0, void *arg1) {
  D_8011FC18.unk28 = arg1;
  arg0->unk20[0].v.ob[0] = 0;
  arg0->unk20[0].v.ob[1] = 0;
  arg0->unk20[0].v.ob[2] = 0;
  arg0->unk20[1].v.ob[0] = 0;
  arg0->unk20[1].v.ob[1] = 0;
  arg0->unk20[1].v.ob[2] = 0;
  arg0->unk20[2].v.ob[0] = 0;
  arg0->unk20[2].v.ob[1] = 0;
  arg0->unk20[2].v.ob[2] = 0;
  arg0->unk20[3].v.ob[0] = 0;
  arg0->unk20[3].v.ob[1] = 0;
  arg0->unk20[3].v.ob[2] = 0;
  arg0->unk20[0].v.flag = 0;
  arg0->unk20[0].v.tc[0] = 0;
  arg0->unk20[0].v.tc[1] = 0;
  arg0->unk20[1].v.flag = 0;
  arg0->unk20[1].v.tc[0] = 0x380;
  arg0->unk20[1].v.tc[1] = 0;
  arg0->unk20[2].v.flag = 0;
  arg0->unk20[2].v.tc[0] = 0;
  arg0->unk20[2].v.tc[1] = 0x380;
  arg0->unk20[3].v.flag = 0;
  arg0->unk20[3].v.tc[0] = 0x380;
  arg0->unk20[3].v.tc[1] = 0x380;
  Minos_80070c40_twoliner_set_OR_1(0x100);
  Minos_80070c70_threeliner_set_OR_8(0x500, 0xA00);
  Minos_80070cb8_threeliner_set_OR_4(0, 0);
  Minos_SetScale(0x100);
  Minos_SetVtxTransform(0);
  Minos_SetAlpha(0xFF);
  Minos_80070a34_twentyliner();
}

void Minos_Deinit_doesnothing(UnkStruct_0 *arg0) {
}

void Minos_BeginRender(UnkStruct_0 *arg0) {
  gSPDisplayList(g_gdl++, &D_800D0568);
  gSPVertex(g_gdl++, &arg0->unk20, 4, 0);
  D_8011FC18.unk38 = 2;
  D_8011FC18.is_transparent = TRUE;
  Minos_8006fc8c_twentyfive_liner(1, FALSE);
  D_800D0560 = 0;
}

void Minos_EndRender(UnkStruct_0 *arg0) {
  gDPPipeSync(g_gdl++);
  gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
}

void Minos_80070fd8_notcalled_q(PointAngle *arg0, Point *arg1, u16 arg2) {
  register UnkStruct_0 *var_a3 = D_8011FC10;
  register s32 tmp_x = arg1->x - var_a3->unk12.x;
  register s32 tmp_y = arg1->y - var_a3->unk12.y;

  tmp_x = (tmp_x * var_a3->unk4) >> 10;
  tmp_y = (tmp_y * var_a3->unk4) >> 10;

  arg0->p.x = tmp_x + var_a3->unkE.x;
  arg0->p.y = tmp_y + var_a3->unkE.y;
  arg0->angle = 0;
}

void Minos_8007104c_fiveliner_nuts(Point *arg0, s16 x, s16 y) {
  register UnkStruct_0 *var_a3 = D_8011FC10;

  x -= var_a3->unk12.x;
  y -= var_a3->unk12.y;

  x = (x * var_a3->unk4) >> 10;
  y = (y * var_a3->unk4) >> 10;

  arg0->x = x + var_a3->unkE.x;
  arg0->y = y + var_a3->unkE.y;
}

void Minos_80071100_fiveliner_nuts2(Point *arg0, PointAngle *arg1) {
  register UnkStruct_0 *var_a2 = D_8011FC10;
  register s32 tmp_x = arg1->p.x - var_a2->unkE.x;
  register s32 tmp_y = arg1->p.y - var_a2->unkE.y;

  tmp_x = (tmp_x * var_a2->unk2) >> 14;
  tmp_y = (tmp_y * var_a2->unk2) >> 14;

  arg0->x = tmp_x + var_a2->unk12.x;
  arg0->y = tmp_y + var_a2->unk12.y;
}

void Minos_SetVtxTransform(u8 arg0) {
  D_8011FC10->unk1E = arg0;
  switch (arg0) {
  case 0:
    D_8011FC18.unk34 = func_8006F39C;
    break;
  case 1:
    D_8011FC18.unk34 = Minos_8006f4b4_thirtyliner_interesting;
    break;
  default:
    D_8011FC18.unk34 = func_8006F7E8;
  }
}
