#include "common.h"

static void   func_800AE70C(UnkStruct_88 *);

// unused
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/073D50/func_800ADAD0.s")

UnkStruct_88 *func_800ADE5C(s32 w, s32 h) {
  UnkStruct_88 *temp_v0;
  UnkStruct_89 *var_v1;
  u8 *ptr;
  s32 alloc_sz;
  s32 sp24;
  s32 temp_s0;
  s32 var_v0;
  s32 var_t0;
  s32 var_ra;
  s32 var_a2;
  s32 var_t3;

  sp24 = w / 64;
  if ((w % 64) > 0) {
    var_v0 = 1;
  } else {
    var_v0 = 0;
  }
  sp24 += var_v0;

  temp_s0 = (h / 30);
  if ((h % 30) > 0) {
    var_v0 = 1;
  } else {
    var_v0 = 0;
  }
  temp_s0 += var_v0;

  alloc_sz = sp24 * sizeof(UnkStruct_89) * temp_s0 + sizeof(UnkStruct_88);
  ptr = n64HeapAlloc(alloc_sz);
  temp_v0 = (UnkStruct_88 *) ptr;
  ptr += sizeof(UnkStruct_88);

  temp_v0->unk0 = w;
  temp_v0->unk4 = h;
  temp_v0->unk8 = sp24;
  temp_v0->unkC = temp_s0;
  temp_v0->unk10 = 0;

  temp_v0->unk118.vp.vscale[0] = w * 2;
  temp_v0->unk118.vp.vscale[1] = h * 2;
  temp_v0->unk118.vp.vscale[2] = 1023;
  temp_v0->unk118.vp.vscale[3] = 0;
  temp_v0->unk118.vp.vtrans[0] = w * 2;
  temp_v0->unk118.vp.vtrans[1] = h * 2;
  temp_v0->unk118.vp.vtrans[2] = 0;
  temp_v0->unk118.vp.vtrans[3] = 0;

  var_v1 = (UnkStruct_89 *) ptr;
  temp_v0->unk14 = var_v1;

  guMtxIdent(&temp_v0->unk18[0]);
  guMtxIdent(&temp_v0->unk18[1]);

  temp_v0->unk128.x = 0;
  temp_v0->unk128.y = 0;
  temp_v0->unk128.z = 0;
  temp_v0->unk134.x = 1;
  temp_v0->unk134.y = 1;
  temp_v0->unk134.z = 1;
  temp_v0->unk140 = 0;

  for (var_t0 = 0, var_ra = 0; var_ra < temp_s0; var_ra++, var_t0 += 30) {
    for (var_a2 = 0, var_t3 = 0; var_t3 < sp24; var_t3++, var_a2 += 64) {
      var_v1->vlist[0].v.ob[0] = var_a2;
      var_v1->vlist[0].v.ob[1] = var_t0;
      var_v1->vlist[0].v.ob[2] = 0;
      var_v1->vlist[0].v.flag = 0;
      var_v1->vlist[0].v.tc[0] = -63;
      var_v1->vlist[0].v.tc[1] = -63;
      var_v1->vlist[0].v.cn[0] = 0xFF;
      var_v1->vlist[0].v.cn[1] = 0xFF;
      var_v1->vlist[0].v.cn[2] = 0xFF;
      var_v1->vlist[0].v.cn[3] = 0xFF;

      var_v1->vlist[1].v.ob[0] = var_a2 + 64;
      var_v1->vlist[1].v.ob[1] = var_t0;
      var_v1->vlist[1].v.ob[2] = 0;
      var_v1->vlist[1].v.flag = 0;
      var_v1->vlist[1].v.tc[0] = 4033;
      var_v1->vlist[1].v.tc[1] = -63;
      var_v1->vlist[1].v.cn[0] = 0xFF;
      var_v1->vlist[1].v.cn[1] = 0xFF;
      var_v1->vlist[1].v.cn[2] = 0xFF;
      var_v1->vlist[1].v.cn[3] = 0xFF;

      var_v1->vlist[2].v.ob[0] = var_a2 + 64;
      var_v1->vlist[2].v.ob[1] = var_t0 + 30;
      var_v1->vlist[2].v.ob[2] = 0;
      var_v1->vlist[2].v.flag = 0;
      var_v1->vlist[2].v.tc[0] = 4033;
      var_v1->vlist[2].v.tc[1] = 1857;
      var_v1->vlist[2].v.cn[0] = 0xFF;
      var_v1->vlist[2].v.cn[1] = 0xFF;
      var_v1->vlist[2].v.cn[2] = 0xFF;
      var_v1->vlist[2].v.cn[3] = 0xFF;

      var_v1->vlist[3].v.ob[0] = var_a2;
      var_v1->vlist[3].v.ob[1] = var_t0 + 30;
      var_v1->vlist[3].v.ob[2] = 0;
      var_v1->vlist[3].v.flag = 0;
      var_v1->vlist[3].v.tc[0] = -63;
      var_v1->vlist[3].v.tc[1] = 1857;
      var_v1->vlist[3].v.cn[0] = 0xFF;
      var_v1->vlist[3].v.cn[1] = 0xFF;
      var_v1->vlist[3].v.cn[2] = 0xFF;
      var_v1->vlist[3].v.cn[3] = 0xFF;

      var_v1++;
    }
  }

  return temp_v0;
}

Gfx *func_800AE220(UnkStruct_88 *arg0, Gfx *gdl, u16 *arg2, u8 r, u8 g, u8 b, u8 a) {
  s32 var_t4;
  s32 var_a2;
  UnkStruct_89 *var_t5;
  s32 var_t1;
  s32 var_a0;
  s32 tmp;

  gSPClearGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN);

  gSPViewport(gdl++, &arg0->unk118);

  gDPSetCycleType(gdl++, G_CYC_1CYCLE);

  gDPSetTexturePersp(gdl++, G_TP_PERSP);

  gDPSetTextureFilter(gdl++, G_TF_BILERP);

  gDPSetColorDither(gdl++, G_CD_NOISE);

  gDPSetBlendColor(gdl++, 0x00, 0x00, 0x00, 0x00);

  gDPSetAlphaCompare(gdl++, G_AC_NONE);

  gDPSetFogColor(gdl++, 0xFF, 0xFF, 0xFF, 0xFF);

  gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

  if (a == 0xFF) {
    gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
  } else {
    gDPSetRenderMode(gdl++, IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);
  }

  gDPSetPrimColor(gdl++, 0, 0, r, g, b, a);

  tmp = 0;
  guOrtho(&arg0->unk98[arg0->unk10], tmp, arg0->unk0, arg0->unk4, 0, 1, -1, 2);

  func_800AE70C(arg0);

  gSPMatrix(gdl++, &arg0->unk98[arg0->unk10], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

  gSPMatrix(gdl++, &arg0->unk18[arg0->unk10], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

  var_t5 = arg0->unk14;
  for (var_a2 = 0, var_a0 = 0; var_a0 < arg0->unkC; var_a0++, var_a2 += 30) {
    for (var_t1 = 0, var_t4 = 0; var_t4 < arg0->unk8; var_t4++, var_t1 += 64, var_t5++) {
      gDPLoadTextureTile(gdl++, arg2, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg0->unk0, arg0->unk4, var_t1, var_a2, var_t1 + 63, var_a2 + 29, NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

      gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 512 << 2, 240 << 2);

      gDPPipeSync(gdl++);

      gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);

      gSPVertex(gdl++, var_t5->vlist, 4, 0);

      gSP1Triangle(gdl++, 0, 1, 2, 0);

      gSP1Triangle(gdl++, 0, 2, 3, 0);
    }
  }

  return gdl;
}

// unused
void func_800AE6C8(UnkStruct_88 *arg0, Vec3 *arg1) {
  arg0->unk128 = *arg1;
}

void func_800AE6E4(UnkStruct_88 *arg0, Vec3 *arg1) {
  arg0->unk134 = *arg1;
}

void func_800AE700(UnkStruct_88 *arg0, f32 arg1) {
  arg0->unk140 = arg1;
}

static void func_800AE70C(UnkStruct_88 *arg0) {
  MtxF sp50;
  Vec3 sp44;
  Vec3 sp38;
  f32 sp34;
  f32 sp30;
  f32 sp2C;
  f32 sp28;

  sp34 = cosf(arg0->unk140);
  sp30 = sinf(arg0->unk140);

  sp2C = arg0->unk0 * 0.5f;
  sp28 = arg0->unk4 * 0.5f;

  sp44.x = sp34 * arg0->unk134.x;
  sp44.y = sp30 * arg0->unk134.x;

  sp38.x = -sp30 * arg0->unk134.y;
  sp38.y = sp34 * arg0->unk134.y;

  func_800A8FC8((s16 *) &sp50, 0, 32);

  sp50.m00 = sp44.x;
  sp50.m01 = sp44.y;
  sp50.m10 = sp38.x;
  sp50.m11 = sp38.y;
  sp50.m22 = 1;
  sp50.m33 = 1;

  sp50.m30 = (-sp44.x * sp2C) - (sp38.x * sp28) + arg0->unk128.x + sp2C - 0.5;
  sp50.m31 = (-sp44.y * sp2C) - (sp38.y * sp28) + arg0->unk128.y + sp28 - 0.5;

  guMtxF2L((f32 (*)[4]) &sp50, &arg0->unk18[arg0->unk10]);
}
