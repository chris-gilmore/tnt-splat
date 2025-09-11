#include "common.h"

#define G_CC_H2O_C PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0

static u8 D_8012CB80[256];

static UnkStruct_44 D_800D91A0 = {
  { -1, 0 },
  { 4, 16, 16, 10, 0, NULL, NULL }
};

static Gfx D_800D91B8[] = {
  gsDPLoadTextureBlock(0x00000000, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
  gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
  gsSPEndDisplayList(),
};

static s32 D_800D9200 = 1;

Gfx D_800D9208[] = {
  gsDPPipeSync(),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH),
  gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
  gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
  gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsSPEndDisplayList(),
};

Gfx D_800D9248[] = {
  gsDPPipeSync(),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH),
  gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
  gsDPSetCombineMode(G_CC_H2O_C, G_CC_H2O_C),
  gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
  gsDPSetCycleType(G_CYC_2CYCLE),
  gsSPEndDisplayList(),
};

Gfx D_800D9288[] = {
  gsDPPipeSync(),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH),
  gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
  gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
  gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsSPEndDisplayList(),
};

Gfx D_800D92C8[] = {
  gsDPPipeSync(),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH),
  gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
  gsDPSetCombineMode(G_CC_H2O_C, G_CC_H2O_C),
  gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
  gsDPSetCycleType(G_CYC_2CYCLE),
  gsSPEndDisplayList(),
};

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/078FE0/func_800B2D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/078FE0/func_800B303C.s")
