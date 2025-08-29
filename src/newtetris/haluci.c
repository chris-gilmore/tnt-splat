#include "common.h"

extern u16 draw_buffer;

////////////////////////////////////////

#define TWO_PI 6.2831853

static u8 D_8011FD10[256];
static UnkStruct_83 D_8011FE10[5];
static UnkStruct_32 *D_8011FE9C;
static s32 D_8011FEA0;  // unused
static s32 D_8011FEA4;  // unused
static UnkStruct_86 *D_8011FEA8;
static void *D_8011FEAC;
static Mtx D_8011FEB0[8];
static UnkStruct_84 D_801200B0;

static s32 D_800D3040 = 1;
static UnkStruct_44 D_800D3044 = {
  { -1, 0 },
  { 4, 16, 16, 10, 0, NULL, NULL }
};
static s32 D_800D305C = 0;  // unused
static Gfx D_800D3060[] = {
  gsDPLoadTextureBlock(0x00000000, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
  gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
  gsSPEndDisplayList(),
};
static f32 D_800D30A8 = 0;
static f32 D_800D30AC = 0;           // unused
static f32 D_800D30B0 = 0;           // unused
static f32 D_800D30B4 = -16;         // unused
static f32 D_800D30B8 = 0;           // unused
static f32 D_800D30BC = 0;           // unused
static f32 D_800D30C0 = 0.09142857;  // unused
static f32 D_800D30C4 = 0;           // unused
static Vtx D_800D30C8[] = {
  {{{     0,   256,   256 }, 0, {     0,     0 }, { 255, 255, 255,   0 }}},
  {{{     0,   256,  -256 }, 0, {     0,  8192 }, { 255, 255, 255,   0 }}},
  {{{     0,  -256,  -256 }, 0, {  8192,  8192 }, { 255, 255, 255,   0 }}},
  {{{     0,  -256,   256 }, 0, {  8192,     0 }, { 255, 255, 255,   0 }}},
};
static Gfx D_800D3108[] = {
  gsSPVertex(D_800D30C8, 4, 0),
  gsSP1Triangle(0, 1, 2, 0),
  gsSP1Triangle(0, 2, 3, 0),
  gsSPEndDisplayList(),
};
static s32 D_800D3128 = 0;
static s32 D_800D312C = 0;
static UnkStruct_85 D_800D3130 = {
  0,
  0.25,
  1,
  0,
  800, 600,
  511, 0,
  800, 600,
  511, 0,
};
static Vec3 D_800D3150 = { 1.1, 1.1, 1.0 };
static f32 D_800D315C = 0;
static f32 D_800D3160 = 0.00003;
static f32 D_800D3164 = 0;
static f32 D_800D3168 = 0.06749515;
static f32 D_800D316C = 0;
static f32 D_800D3170 = 0.003681554;
static f32 D_800D3174 = 0;
static f32 D_800D3178 = 0;
static f32 D_800D317C = 0.003;
static f32 D_800D3180 = 0.1;

static void   func_8007C650(void);
static void   func_8007C8B0(void);
static void   func_8007CAC4(void);
static void   func_8007CC14(void);
static void   func_8007D214(void);
static void   func_8007D25C(UnkStruct_86 *, f32, f32, f32, f32);
static void   func_8007D458(UnkStruct_86 *);
static void   func_8007D510(UnkStruct_86 *, f32, f32, f32, f32, f32);
static Gfx   *func_8007D6A8(Gfx *);

// unused
static void func_8007C650(void) {
  s32 sp34;
  s32 sp30;
  f32 sp2C;
  f32 sp28;
  f32 sp24;
  f32 sp20;
  u8 *sp1C;

  sp1C = D_8011FD10;
  for (sp30 = 0; sp30 < 16; sp30++) {
    sp28 = (f32) ((sp30 * 2) - 16) / 16;
    for (sp34 = 0; sp34 < 16; sp34++, sp1C++) {
      sp2C = (f32) ((sp34 * 2) - 16) / 16;
      sp24 = (sp2C * sp2C) + (sp28 * sp28);
      sp20 = 1.0 - sp24;
      if (sp20 < 0.0) {
        sp20 = 0;
      }
      sp24 = ((cosf((sp24 * 12) - D_800D30A8) * 0.3) + 0.7) * sp20;
      *sp1C = sp24 * 255.0;
    }
  }

  D_800D30A8 += 0.4;
  if (D_800D30A8 > TWO_PI) {
    D_800D30A8 -= TWO_PI;
  }
}

static void func_8007C8B0(void) {
  f32 sp2C;  // unused
  f32 sp28 = 0;
  s32 sp24;

  for (sp24 = 0; sp24 < 5; sp24++) {
    D_8011FE10[sp24].unk4 = func_800A36F0(0, 6.28);
    D_8011FE10[sp24].unk8 = func_800A36F0(0.01, 0.025) * ((func_800A35EC(1, 2) * 2) - 1);
    D_8011FE10[sp24].unk0 = TWO_PI;
    D_8011FE10[sp24].unkC = D_8011FE10[sp24].unk0 * cosf(D_8011FE10[sp24].unk4);
    D_8011FE10[sp24].unk10 = D_8011FE10[sp24].unk0 * sinf(D_8011FE10[sp24].unk4);
    D_8011FE10[sp24].unk14 = func_800A36F0(0, 6.28);
    D_8011FE10[sp24].unk18 = func_800A36F0(0.01, 0.03) * ((func_800A35EC(1, 2) * 2) - 1);
  }
}

static void func_8007CAC4(void) {
  s32 sp1C;
  UnkStruct_83 *sp18 = D_8011FE10;

  for (sp1C = 5; sp1C != 0; sp1C--, sp18++) {
    sp18->unk14 += sp18->unk18;
    if (sp18->unk14 > TWO_PI) {
      sp18->unk14 -= TWO_PI;
    }

    sp18->unk4 += sp18->unk8;
    if (sp18->unk4 > TWO_PI) {
      sp18->unk4 -= TWO_PI;
    }

    sp18->unkC = cosf(sp18->unk4) * sp18->unk0;
    sp18->unk10 = sinf(sp18->unk4) * sp18->unk0;
  }
}

static void func_8007CC14(void) {
  UnkStruct_83 *sp44;
  s32 sp40;
  s32 sp3C;
  s32 sp38;
  f32 sp34;
  f32 sp30;
  f32 sp2C;
  f32 sp28;
  u8 *sp24 = D_8011FD10;

  for (sp3C = 0; sp3C < 16; sp3C++) {
    sp30 = (f32) ((sp3C * 2) - 16) / 16;
    for (sp40 = 0; sp40 < 16; sp40++, sp24++) {
      sp34 = (f32) ((sp40 * 2) - 16) / 16;
      sp28 = sqrtf((sp34 * sp34) + (sp30 * sp30));
      if (sp28 > 0.6) {
        sp28 -= 0.6;
        sp28 = sp28 * -(0.6/0.4) + 0.6;
        sp28 *= 0.5/0.3;
      } else {
        sp28 *= 0.4/0.3;
        sp28 += 0.2;
      }
      if (sp28 < 0.0) {
        sp28 = 0;
      }

      // Is this unused code?
      ///////////////////////
      sp44 = D_8011FE10;
      sp2C = 0;
      for (sp38 = 0; sp38 < 5; sp38++, sp44++) {
        sp2C += sinf((sp34 * sp44->unkC) + (sp30 * sp44->unk10) + sp44->unk14);
      }
      sp2C /= 5;
      sp2C *= 0.5;
      sp2C += 0.5;
      ///////////////////////

      *sp24 = sp28 * 255.0;
    }
  }

  func_8007CAC4();
}

void func_8007CF40(u8 arg0) {
  Gfx *sp34;

  D_800D3040 = arg0;
  D_8011FE9C = func_800AC9C0();

  func_800A4364(D_8011FE9C, 110);       // set viewport's fovy
  func_800A43B0(D_8011FE9C, 0.01, 64);  // set viewport's near and far
  D_8011FEA8 = func_800ACEA0(350, &D_800D3044);

  D_8011FEA8->unk10C = 2;
  D_8011FEA8->unk110 = 0.25;
  D_8011FEA8->unk104 = 0.6;
  D_8011FEA8->unk108 = 0.6;
  D_8011FEA8->unkD8 = 0;
  D_8011FEA8->unkDC = 0.5;
  D_8011FEA8->unkE0 = 1;
  D_8011FEA8->unkE8 = 2;
  D_8011FEA8->unkEC = 0.5;
  D_8011FEA8->unkF0 = 1;
  D_8011FEA8->unkD4 = 350;
  D_8011FEA8->unk114 = 1;

  D_800D3044.unk8.unkC = D_8011FD10;
  D_800D3044.unk8.unk8 = D_800D3060;

  sp34 = D_800D3060;

  gDPLoadTextureBlock(sp34++, ((u32)D_8011FD10 - (u32)&D_800D3044.unk8) + 0x0B000000, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

  func_8007C8B0();
  func_8007D458(D_8011FEA8);
  D_8011FEAC = func_800ADE5C(400, 300);
}

// unused
static void func_8007D214(void) {
  main_8004A34C_threeliner();
  func_800AD120(D_8011FEA8);
  D_800D3CF0 = 0;
  func_800905E8(0);
  D_800CFEE8 = 4;
}

// unused
static void func_8007D25C(UnkStruct_86 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
  UnkStruct_87 *sp4C;
  u16 sp4A;
  f32 sp44;
  f32 sp40;
  f32 sp3C;
  Vec3 sp30;
  Vec3 sp24;
  f32 sp20;
  f32 sp1C;

  sp44 = arg4 * TWO_PI;
  sp40 = TWO_PI / arg0->unkC0;
  sp4C = arg0->unkC4;
  sp30.y = 0;
  arg4 = sp44;
  sp3C = (arg1 * TWO_PI) / arg0->unkC0;
  for (sp4A = arg0->unkC0; sp4A != 0; sp4A--, sp4C++, sp44 += sp40, arg4 += sp3C) {
    sp20 = cosf(sp44);
    sp1C = sinf(sp44);
    sp30.x = sp20 * arg2;
    sp30.z = sp1C * arg2;
    sp24.y = sinf(arg4) * arg3 * 2.7;
    sp24.z = cosf(arg4) * arg3;
    sp24.x = sp24.z;
    sp24.x *= sp20;
    sp24.z *= sp1C;
    sp4C->unk4.x = sp30.x + sp24.x;
    sp4C->unk4.y = sp30.y + sp24.y;
    sp4C->unk4.z = sp30.z + sp24.z;
    sp4C->unk1C = sp4A;
  }
}

static void func_8007D458(UnkStruct_86 *arg0) {
  s32 spC;
  f32 sp8;
  UnkStruct_87 *sp4;

  arg0->unk118 = 1;
  sp4 = arg0->unkC4;
  sp8 = 1.8;
  for (spC = 0; spC < arg0->unkC0; spC++, sp4++) {
    sp4->unk1C = spC;
    sp4->unk0 = sp8 + 0.1;
    sp8 *= 0.99006392;
  }
}

static void func_8007D510(UnkStruct_86 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
  s32 sp34;
  UnkStruct_87 *sp30;
  f32 sp2C;
  f32 sp28;
  f32 sp24;
  f32 sp20;
  f32 sp1C;

  sp30 = arg0->unkC4;
  sp2C = 1.0 / arg0->unkC0;
  sp28 = 0;
  sp24 = arg1 * TWO_PI * sp2C;
  sp1C = 1;
  for (sp34 = 0; sp34 < arg0->unkC0; sp34++, sp30++, sp28 += sp24) {
    sp20 = (sinf(sp28 * arg3) + 1.0) * arg5;
    sp30->unk4.x = cosf(sp28 + arg4) * arg2;
    sp30->unk4.z = sp20;
    sp30->unk4.y = sinf(sp28 + arg4) * arg2;
    arg2 *= 0.99006392;
  }
}

// unused
static Gfx *func_8007D6A8(Gfx *gdl) {
  MtxF spA0;
  MtxF sp60;
  Vec3 sp54;
  Vec3 sp48;
  s32 sp44;

  // calls gSPDisplayList
  gdl = func_800A4B98(gdl, &D_800D3044);

  D_800D3128++;
  D_800D3128 &= 0xFFF;
  gDPSetTileSize(gdl++, G_TX_RENDERTILE, D_800D3128, D_800D3128, 0, 0);

  gDPSetTexturePersp(gdl++, G_TP_PERSP);

  gSPClearGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH);

  gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);

  gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

  gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

  gDPSetCycleType(gdl++, G_CYC_2CYCLE);

  gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x80);

  func_800B04BC(&spA0, 0, 0, D_800D312C);

  sp60 = spA0;

  for (sp44 = 0; sp44 < 8; sp44++) {
    sp54.x = -64.0 + (16.0 * sp44);
    sp54.y = 0;
    sp54.z = -128;
    func_800AFBBC(&sp48, &spA0, &sp54);

    sp60.m30 = sp48.x;
    sp60.m31 = sp48.y;
    sp60.m32 = sp48.z;

    guMtxF2L((f32 (*)[4]) &sp60, &D_8011FEB0[sp44]);

    gSPMatrix(gdl++, &D_8011FEB0[sp44], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(gdl++, D_800D3108);
  }

  D_800D312C++;
  if (D_800D312C > 360) {
    D_800D312C -= 360;
  }

  return gdl;
}

Gfx *func_8007DA00(Gfx *gdl) {
  Vec3 sp44;
  Vec3 sp38;

  if (D_800D3040 != 0) {
    sp38 = D_800D3150;
    func_800AE6E4(D_8011FEAC, &sp38);
    func_800AE700(D_8011FEAC, D_800D3180);
    gdl = func_800AE220(D_8011FEAC, gdl, cfb[draw_buffer ^ 1], 0xFA, 0xFA, 0xFA, 0xC0);
  }

  if ((D_800CFEE8 == 13) && (g_PV_arr->unk1C->unk0 & 0x1000) && !(g_PV_arr->unk1C->unk4 & 0x1000)) {
    D_800D3040 ^= 1;
  }

  func_800A4304(D_8011FE9C, 0, 0, -5, 0, 0, 0);
  gdl = func_800A724C(gdl, D_8011FE9C);
  func_8007D510(D_8011FEA8, (D_800D315C * 20.0) + 50, 7, (sinf(D_800D316C) * 2.05) + 1.001, D_800D315C * 120.0, 2);

  // Is this unused code?
  ///////////////////////
  sp44.x = cosf(D_800D316C) * 5.0;
  sp44.y = cosf(D_800D3174) * 6.0;
  sp44.z = sinf(D_800D316C) * 5.0;
  ///////////////////////

  func_800B11C4(&D_800D3130, &D_801200B0);
  D_800D3130.unk0 += 0.023;
  if (D_800D3130.unk0 > 1.0) {
    D_800D3130.unk0 -= 1.0;
  }

  D_8011FEA8->unkD8 = D_800D3178;
  D_8011FEA8->unkE8 = D_800D3178 + 1.5;
  gdl = func_800AD970(gdl, D_8011FEA8, D_8011FE9C);

  D_800D315C += D_800D3160;
  if ((D_800D315C >= 1) || (D_800D315C < -1)) {
    D_800D315C -= D_800D3160;
    D_800D3160 *= -1.0;
  }

  D_800D3164 += D_800D3168;
  if ((D_800D3164 > 125.663706) || (D_800D3164 < -125.663706)) {
    D_800D3164 -= D_800D3168;
    D_800D3168 *= -1.0;
  }

  D_800D316C += D_800D3170;
  if (D_800D316C > TWO_PI) {
    D_800D316C -= TWO_PI;
  }

  D_800D3174 += 0.017951958;
  if (D_800D3174 > TWO_PI) {
    D_800D3174 -= TWO_PI;
  }

  D_800D3178 += D_800D317C;
  if (D_800D3178 > 1.0) {
    D_800D3178 -= 1.0;
  }

  func_8007CC14();

  return gdl;
}
