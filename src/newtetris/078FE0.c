#include "common.h"

#define G_CC_H2O_C PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0

static void func_800B2D60(void);

static u8 D_8012CB80[256];

static UnkStruct_44 D_800D91A0 = {
  { -1, 0 },
  { 4, 16, 16, 10, 0, NULL, NULL }
};

static Gfx D_800D91B8[] = {
  gsDPLoadTextureBlock(NULL, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
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

static void func_800B2D60(void) {
  s32 i;
  s32 j;
  f32 x;
  f32 y;
  f32 val;
  u8 *img;
  Gfx *gdl;

  img = D_8012CB80;

  for (j = 0; j < 16; j++) {
    y = (j * 2) - 16;
    y /= 16;

    for (i = 0; i < 16; i++, img++) {
      x = (i * 2) - 16;
      x /= 16;
      val = (x * x) + (y * y);
      val = 1.0 - val;
      if (val < 0.0) {
        val = 0.0;
      }
      *img = val * 255.0;
    }
  }

  D_800D91A0.unk8.unkC = D_8012CB80;
  D_800D91A0.unk8.unk8 = D_800D91B8;

  gdl = D_800D91B8;
  gDPLoadTextureBlock(gdl++, SEGMENT_ADDR(G_MWO_SEGMENT_B, (u32)D_8012CB80 - (u32)&D_800D91A0.unk8), G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
}

UnkStruct_44 *func_800B303C(void) {
  if (D_800D9200 != 0) {
    func_800B2D60();
    D_800D9200 = 0;
  }

  return &D_800D91A0;
}
