#include "common.h"

extern u16 draw_buffer;

////////////////////////////////////////

static Gfx D_800D0610[] = {
  gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
  gsDPPipeSync(),
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsDPSetTextureLUT(G_TT_NONE),
  gsDPSetAlphaCompare(G_AC_NONE),
  gsDPSetTexturePersp(G_TP_NONE),
  gsDPSetTextureFilter(G_TF_AVERAGE),
  gsDPSetTextureConvert(G_TC_FILT),
  gsDPSetTextureDetail(G_TD_CLAMP),
  gsDPSetTextureLOD(G_TL_TILE),
  gsDPSetCombineMode(_G_CC_BLENDPEDECALA, _G_CC_BLENDPEDECALA),
  gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
  gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
  gsDPSetEnvColor(0xFF, 0xFF, 0x00, 0xFF),
  gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
  gsSPEndDisplayList(),
};

static void   func_800749A0(UnkStruct_33 *, s32, s32);
static void   func_80074B80(UnkStruct_33 *, u32, s32, s32);
static void   func_80074C80(UnkStruct_33 *, u32, s32, s32, u8 *);
static void   func_80074D7C(UnkStruct_30 *);
static void   func_80074E3C(UnkStruct_30 *);

static void func_800749A0(UnkStruct_33 *arg0, s32 arg1, s32 arg2) {
  register s16 temp_s0;
  register s32 temp_s1;

  temp_s0 = (FUN_026900_PRNG_1() % 120) + 0xF;
  arg0->unk12 = temp_s0;
  arg0->unk4 = (arg2 - 1) << 8;
  temp_s1 = (arg0->unk4 - (FUN_026900_PRNG_1() % (arg2 << 5)));
  arg0->unk6 = -temp_s1 / temp_s0;
  arg0->unk0 = (FUN_026900_PRNG_1() & 0xFF) << 8;
  arg0->unk2 = -arg0->unk0 / temp_s0;
  arg0->unk8 = FUN_026900_PRNG_1() & 0xFFFF;
  arg0->unkA = (FUN_026900_PRNG_1() & 0x3FF) - 0x200;
  arg0->unkC = FUN_026900_PRNG_1() % (arg1 * 120);
  arg0->unkE = -arg0->unkC / temp_s0;
  arg0->unk10 = (FUN_026900_PRNG_1() & 0x3F) - 0x1F;
}

static void func_80074B80(UnkStruct_33 *arg0, u32 arg1, s32 arg2, s32 arg3) {
  while (arg1 > 0) {
    arg0->unk0 += arg0->unk2;
    arg0->unkC += arg0->unkE;
    arg0->unk4 += arg0->unk6;
    arg0->unk8 += arg0->unkA;
    arg0->unk12--;
    if (arg0->unk12 == 0) {
      func_800749A0(arg0, arg2, arg3);
    }
    arg0++;
    arg1--;
  }
}

static void func_80074C80(UnkStruct_33 *arg0, u32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
  register s32 temp_s0 = 0;
  register s32 temp_t3;

  while (arg1 > 0) {
    temp_s0 = sins(arg0->unk8) * arg0->unkC;
    temp_s0 >>= 23;
    temp_s0 += arg2 >> 1;
    temp_t3 = arg0->unk4 >> 8;
    if ((temp_s0 < 0) || (temp_s0 >= arg2) || (temp_t3 < 0) || (temp_t3 >= arg3)) {
      return;
    }

    arg4[temp_s0 + (temp_t3 * arg2)] = arg0->unk0 >> 8;
    arg0++;
    arg1--;
  }
}

static void func_80074D7C(UnkStruct_30 *arg0) {
  register u8 *var_a1 = arg0->unkC[draw_buffer ^ 1] + 1;
  register u8 *var_a2 = arg0->unkC[draw_buffer] + 1;
  register s32 i;
  register s32 j;
  register s32 temp_t1 = arg0->unk14.width;
  register s32 var_t2;

  for (j = arg0->unk14.height - 1; j > 0; j--, var_a1 += 2, var_a2 += 2) {
    for (i = arg0->unk14.width - 2; i > 0; i--, var_a1++, var_a2++) {
      var_t2 = ((var_a1[temp_t1 - 1] + var_a1[temp_t1 + 1] + var_a1[temp_t1] + *var_a1) >> 2) - 4;
      if (var_t2 < 0) {
        var_t2 = 0;
      }
      *var_a2 = var_t2;
    }
  }
}

static void func_80074E3C(UnkStruct_30 *arg0) {
  register u8 *var_s0;
  register s32 i;

  var_s0 = arg0->unkC[draw_buffer ^ 1];
  var_s0 += arg0->unk14.width * (arg0->unk14.height - 1) + 1;
  for (i = arg0->unk14.width - 2; i > 0; i--, var_s0++) {
    *var_s0 = FUN_026900_PRNG_1() & 0xFF;
  }
}

void func_80074EC4(UnkStruct_30 *arg0) {
  func_80074D7C(arg0);
  func_80074B80(arg0->unk8, arg0->unk4, arg0->unk14.width, arg0->unk14.height);
  func_80074C80(arg0->unk8, arg0->unk4, arg0->unk14.width, arg0->unk14.height, arg0->unkC[draw_buffer]);
}

void func_80074F3C(UnkStruct_30 *arg0) {
  register Gfx *gdl = g_gdl;

  gDPLoadTextureTile(gdl++, (u32) arg0->unkC[draw_buffer], G_IM_FMT_I, G_IM_SIZ_8b, arg0->unk14.width, arg0->unk14.height, 0, 0, arg0->unk14.width - 1, arg0->unk14.height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

  // gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)
  gSPTextureRectangle(gdl++, arg0->unk0.x << 2, arg0->unk0.y << 2, (arg0->unk0.x + arg0->unk14.width) << 2, (arg0->unk0.y + arg0->unk14.height - 3) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

  g_gdl = gdl;
}

void func_80075180(void) {
  register Gfx *gdl = g_gdl;

  gSPDisplayList(gdl++, &D_800D0610);

  g_gdl = gdl;
}

void func_800751C0(void) {
  register Gfx *gdl = g_gdl;

  gDPPipeSync(gdl++);
  gDPSetCycleType(gdl++, G_CYC_1CYCLE);

  g_gdl = gdl;
}

void func_80075218(UnkStruct_30 *arg0, s32 arg1, s32 arg2) {
  arg0->unk0.x = arg1 - (arg0->unk14.width >> 1);
  arg0->unk0.y = (arg2 - arg0->unk14.height) + 3;
}

u8 func_8007523C(UnkStruct_30 *arg0, UnkStruct_31 *arg1) {
  register s32 i;
  register UnkStruct_33 *var_s1;

  arg1->unk0.height += 3;
  arg0->unk14 = arg1->unk0;
  arg0->unk16 = arg0->unk14.width * arg0->unk14.height;
  arg0->unk18 = arg0->unk16;
  if (arg0->unk18 >= 0x1000) {
    return FALSE;
  }

  arg0->unkC[0] = n64HeapAlloc(arg0->unk18);
  arg0->unkC[1] = n64HeapAlloc(arg0->unk18);
  bzero(arg0->unkC[0], arg0->unk18);
  bzero(arg0->unkC[1], arg0->unk18);
  arg0->unk4 = arg1->unk6;
  arg0->unk8 = n64HeapAlloc(arg0->unk4 * sizeof(UnkStruct_33));
  var_s1 = arg0->unk8;
  for (i = arg0->unk4; i > 0; i--) {
    func_800749A0(var_s1, arg0->unk14.width, arg0->unk14.height);
    var_s1++;
  }
  func_80075218(arg0, arg1->unk2.x, arg1->unk2.y);
  return TRUE;
}

void func_80075400(UnkStruct_30 *arg0) {
  n64HeapUnalloc(arg0->unk8);
  arg0->unk8 = NULL;
  n64HeapUnalloc(arg0->unkC[0]);
  n64HeapUnalloc(arg0->unkC[1]);
  arg0->unkC[0] = NULL;
  arg0->unkC[1] = NULL;
}
