#include "common.h"

#define G_CC_H2O_A  TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0
#define G_CC_H2O_A2 COMBINED, 0, SHADE, 0, COMBINED, 0, PRIMITIVE, 0
#define G_CC_H2O_B  PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0

static UnkStruct_69 D_80129390;
static UnkStruct_69 D_801293F0;
static u8 D_80129450[0x30];  // padding; what is this?
static MtxF D_80129480;
static MtxF D_801294C0;  // unused
static MtxF D_80129500;
static MtxF D_80129540;

static s32 D_800D6200 = 0;
static UnkStruct_44 *D_800D6204 = NULL;
static Light D_800D6208 = {
  {
    { 0xFF, 0xFF, 0xFF },  // col[3]
    0,                     // pad1
    { 0xFF, 0xFF, 0xFF },  // colc[3]
    0,                     // pad2
    { 0, 120, 0 },         // dir[3]
    0                      // pad3
  }
};

extern /* static */ void   func_800A4CF0(UnkStruct_49 *, MtxF *);
extern /* static */ void   func_800A4EC0(UnkStruct_49 *, MtxF *);
static void   func_800A5114(UnkStruct_49 *, MtxF *);
static void   func_800A52E4(UnkStruct_49 *, MtxF *);
static void   func_800A53E0(UnkStruct_49 *, MtxF *);
static void   func_800A5660(UnkStruct_49 *, MtxF *);
static void   func_800A56E4(MtxF *, MtxF *);
static void   func_800A57A4(MtxF *, MtxF *);
static void   func_800A57FC(UnkStruct_49 *, MtxF *);
static void   func_800A58A4(UnkStruct_32 *);
static void   func_800A59C0(UnkStruct_32 *, MtxF *);
static void   func_800A652C(UnkStruct_32 *, UnkStruct_50 *);
static void   func_800A6AC8(UnkStruct_52 *);
static void   func_800A6B14(UnkStruct_51 *, f32);
static void   func_800A6B60(UnkStruct_51 *, f32);
static void   func_800A6BB0(UnkStruct_51 *, f32);
static void   func_800A6D08(UnkStruct_51 *);
static void   func_800A6E48(UnkStruct_51 *);
static void   func_800A70A8(UnkStruct_32 *);
static Gfx   *func_800A7374(Gfx *);
static Gfx   *func_800A74DC(Gfx *);
static Gfx   *func_800A7EFC(Gfx *, UnkStruct_32 *);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4B8C.s")

Gfx *func_800A4B98(Gfx *gdl, UnkStruct_44 *arg1) {
  gSPSegment(gdl++, 0x0B, osVirtualToPhysical(&arg1->unk8));
  gSPDisplayList(gdl++, osVirtualToPhysical(arg1->unk8.unk8));

  D_800D6204 = arg1;

  return gdl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4EC0.s")

/*
  The formulas used to fill the matrix match a rotation matrix constructed from three Euler angles (likely in ZYX or XYZ order), followed by translation.

  The function is creating a 4x4 transformation matrix (rotation + translation) from an array of floats.
*/
static void func_800A5114(UnkStruct_49 *arg0, MtxF *arg1) {
  f32 *ptr;
  f32 sp48;
  f32 sp44;
  f32 sp40;
  f32 sp3C;
  f32 sp38;
  f32 sp34;

  ptr = arg0->unk10;

  sp38 = sinf(-*ptr * DEG2RAD);
  sp44 = cosf(-*ptr * DEG2RAD);
  ptr++;

  sp3C = sinf(-*ptr * DEG2RAD);
  sp48 = cosf(-*ptr * DEG2RAD);
  ptr++;

  sp34 = sinf(-*ptr * DEG2RAD);
  sp40 = cosf(-*ptr * DEG2RAD);
  ptr++;

  arg1->m00 = sp40 * sp44;
  arg1->m10 = (sp34 * sp48) + (sp40 * sp38 * sp3C);
  arg1->m20 = (sp34 * sp3C) - (sp40 * sp38 * sp48);

  arg1->m01 = -sp34 * sp44;
  arg1->m11 = (sp40 * sp48) - (sp34 * sp38 * sp3C);
  arg1->m21 = (sp40 * sp3C) + (sp34 * sp38 * sp48);

  arg1->m02 = sp38;
  arg1->m12 = -sp44 * sp3C;
  arg1->m22 = sp44 * sp48;

  arg1->m30 = *ptr++;
  arg1->m31 = *ptr++;
  arg1->m32 = *ptr++;

  arg1->m03 = *ptr++;
  arg1->m13 = *ptr++;
  arg1->m23 = *ptr;

  arg1->m33 = 1;
}

static void func_800A52E4(UnkStruct_49 *arg0, MtxF *arg1) {
  f32 sp24;
  f32 sp20;
  f32 sp1C;

  sp24 = arg0->unk10[0];
  sp20 = arg0->unk10[1];
  sp1C = arg0->unk10[2];

  if ((sp24 == 0.0) && (sp20 == 0.0) && (sp1C == 0.0)) {
    sp20 = 1;
  }

  guNormalize(&sp24, &sp20, &sp1C);

  arg1->m00 = 0;
  arg1->m01 = 0;
  arg1->m02 = 0;

  arg1->m10 = 0;
  arg1->m11 = 0;
  arg1->m12 = 0;

  arg1->m20 = sp24;
  arg1->m21 = sp20;
  arg1->m22 = sp1C;

  arg1->m30 = 0;
  arg1->m31 = 0;
  arg1->m32 = 0;

  arg1->m03 = 1;
  arg1->m13 = 1;
  arg1->m23 = 1;
  arg1->m33 = 1;
}

/*
  This is a "look-at" matrix with an additional roll (rotation about the forward axis).
  It's commonly used for camera orientation in 3D graphics, where you specify:

  Eye position (camera location)

  Target position (where the camera looks)

  Roll (camera's tilt around its viewing direction)
*/
static void func_800A53E0(UnkStruct_49 *arg0, MtxF *arg1) {
  f32 temp_fv0;
  f32 temp_fv1;
  f32 temp_fa0;
  f32 sp90;
  f32 sp8C;
  f32 sp88;
  f32 sp84;
  f32 sp80;
  f32 sp7C;
  f32 sp78;
  f32 sp74;
  f32 sp70;
  f32 sp6C;
  MtxF sp2C;
  f32 sp28;
  f32 sp24;

  temp_fv0 = arg0->unk10[0];
  temp_fv1 = arg0->unk10[1];
  temp_fa0 = arg0->unk10[2];
  sp88 = arg0->unk10[3];
  sp8C = arg0->unk10[4];
  sp90 = arg0->unk10[5];
  sp6C = arg0->unk10[6];

  sp2C.m30 = temp_fv0;
  sp2C.m31 = temp_fv1;
  sp2C.m32 = temp_fa0;

  sp88 = temp_fv0 - sp88;
  sp8C = temp_fv1 - sp8C;
  sp90 = temp_fa0 - sp90;
  if ((sp88 == 0.0) && (sp8C == 0.0) && (sp90 == 0.0)) {
    sp90 = -1;
  }
  guNormalize(&sp88, &sp8C, &sp90);

  sp7C = sp90;
  sp80 = 0;
  sp84 = -sp88;
  guNormalize(&sp7C, &sp80, &sp84);

  sp2C.m20 = sp88;
  sp2C.m21 = sp8C;
  sp2C.m22 = sp90;

  sp70 = (sp8C * sp84) - (sp80 * sp90);
  sp74 = (sp90 * sp7C) - (sp84 * sp88);
  sp78 = (sp88 * sp80) - (sp7C * sp8C);

  sp28 = cosf(sp6C * DEG2RAD);
  sp24 = sinf(sp6C * DEG2RAD);

  sp2C.m00 = (sp7C * sp28) + (sp70 * sp24);
  sp2C.m01 = (sp80 * sp28) + (sp74 * sp24);
  sp2C.m02 = (sp84 * sp28) + (sp78 * sp24);

  sp2C.m10 = (-sp7C * sp24) + (sp70 * sp28);
  sp2C.m11 = (-sp80 * sp24) + (sp74 * sp28);
  sp2C.m12 = (-sp84 * sp24) + (sp78 * sp28);

  sp2C.m03 = 1;
  sp2C.m13 = 1;
  sp2C.m23 = 1;
  sp2C.m33 = 1;

  *arg1 = sp2C;
}

static void func_800A5660(UnkStruct_49 *arg0, MtxF *arg1) {
  switch (arg0->unk2) {
  case 0:
    func_800A4CF0(arg0, arg1);
    break;
  case 1:
    func_800A4EC0(arg0, arg1);
    break;
  case 2:
    func_800A5114(arg0, arg1);
    break;
  case 3:
    func_800A52E4(arg0, arg1);
    break;
  case 4:
    func_800A53E0(arg0, arg1);
    break;
  }
}

/*
  Multiplies each axis of the input matrix by the corresponding value in the fourth column, effectively applying non-uniform scaling or perspective division, and writes the result to an output matrix.
*/
static void func_800A56E4(MtxF *arg0, MtxF *arg1) {
  f32 w, x, y, z;

  w = arg0->m03;
  x = arg0->m00;
  y = arg0->m01;
  z = arg0->m02;
  x *= w;
  y *= w;
  z *= w;
  arg1->m00 = x;
  arg1->m01 = y;
  arg1->m02 = z;

  w = arg0->m13;
  x = arg0->m10;
  y = arg0->m11;
  z = arg0->m12;
  x *= w;
  y *= w;
  z *= w;
  arg1->m10 = x;
  arg1->m11 = y;
  arg1->m12 = z;

  w = arg0->m23;
  x = arg0->m20;
  y = arg0->m21;
  z = arg0->m22;
  x *= w;
  y *= w;
  z *= w;
  arg1->m20 = x;
  arg1->m21 = y;
  arg1->m22 = z;

  arg1->m30 = arg0->m30;
  arg1->m31 = arg0->m31;
  arg1->m32 = arg0->m32;

  arg1->m03 = 0;
  arg1->m13 = 0;
  arg1->m23 = 0;

  arg1->m33 = 1;
}

static void func_800A57A4(MtxF *arg0, MtxF *arg1) {
  if (arg1 != arg0) {
    *arg1 = *arg0;
  }

  arg1->m03 = 1;
  arg1->m13 = 1;
  arg1->m23 = 1;
}

static void func_800A57FC(UnkStruct_49 *arg0, MtxF *arg1) {
  UnkStruct_49 **var_s1;
  s32 i;
  s32 unused[4];
  MtxF sp28;

  func_800A5660(arg0, &D_80129480);
  func_800AF0C4(&sp28, arg1, &D_80129480);
  func_800A56E4(&sp28, &arg0->unkC->unkC0);

  arg0->unk0 &= 0xFFFD;
  arg0->unk0 |= 0x10;

  var_s1 = arg0->unk4;
  for (i = arg0->unk3; i != 0; i--) {
    func_800A57FC(*var_s1, &sp28);
    var_s1++;
  }
}

static void func_800A58A4(UnkStruct_32 *arg0) {
  if (arg0->unk0 & 4) {
    D_80129500 = arg0->unkC;
  } else {
    guMtxIdentF((f32 (*)[4]) &D_80129500);
  }
  func_800A59C0(arg0, &D_80129500);
}

// unused
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5930.s")

static void func_800A59C0(UnkStruct_32 *arg0, MtxF *arg1) {
  MtxF *var_s0;
  UnkStruct_49 *var_s1;
  s32 unused;
  s32 var_s3;
  UnkStruct_45 *temp_s0;
  UnkStruct_75 *sp220;
  MtxF sp1E0;
  MtxF sp1A0;
  MtxF sp160;
  MtxF sp120;
  MtxF spE0;
  MtxF spA0;
  f32 var_fv0;
  f32 var_fv1;
  s32 i;
  MtxF sp54;

  sp220 = &arg0->unk8->unk10;
  sp1E0 = *arg1;
  func_800A57A4(&sp1E0, &sp1E0);
  var_s1 = sp220->unk18;
  var_s3 = sp220->unk0;
  if (sp220->unk24 != NULL) {
    if (!(arg0->unk0 & 0x40)) {
      if (arg0->unk0 & 0x8) {
        if (arg0->unk0 & 0x10) {
          var_s0 = &arg0->unk4C;
          func_800A57A4(var_s0, &spE0);
        } else {
          func_800A5660(var_s1, &sp160);
          var_s0 = &arg0->unk4C;
          func_800A57A4(var_s0, &sp1A0);
          func_800AF0C4(&spE0, &sp160, &sp1A0);
        }
      } else {
        if (arg0->unk0 & 0x10) {
          func_800A5660(var_s1, &spE0);
        } else {
          func_800A5660(var_s1, &sp160);
          func_800AF0C4(&spE0, &sp1E0, &sp160);
        }
        var_s0 = &arg0->unk4C;
      }
      func_800A56E4(&spE0, &var_s1->unkC->unkC0);
      sp54 = var_s1->unkC->unkC0;
      var_s1->unkC->unk80 = sp54;
      *var_s0 = sp54;
      func_800AE880(&var_s1->unkC->unkC0, &arg0->unk8C);
      var_s1->unkC->unk80.m30 *= 16;
      var_s1->unkC->unk80.m31 *= 16;
      var_s1->unkC->unk80.m32 *= 16;
      func_800AE880(&var_s1->unkC->unk80, &arg0->unkCC);
      var_s1->unk0 |= 0x2;
      temp_s0 = sp220->unk24;
      var_fv0 = temp_s0->unk10.unk8 * 16;
      if (var_fv0 < 2) {
        var_fv0 = 2;
      }
      if (var_fv0 > 4) {
        var_fv0 = 4;
      }
      var_fv1 = temp_s0->unk10.unkC * 16;
      if (var_fv1 > 32000) {
        var_fv1 = 32000;
      }
      guPerspectiveF((f32 (*)[4]) &spA0, &temp_s0->unk8[arg0->unk4], temp_s0->unk10.unk4, temp_s0->unk10.unk14, var_fv0, var_fv1, 2.0);
      arg0->unk10C = spA0;
      mtx4_mult(&sp120, &spA0, &arg0->unkCC);
      if (arg0->unk0 & 0x4000) {
        guMtxF2L((f32 (*)[4]) &spA0, &temp_s0->unk10.unk1C->unk0[arg0->unk4]);
      } else {
        guMtxF2L((f32 (*)[4]) &sp120, &temp_s0->unk10.unk1C->unk0[arg0->unk4]);
      }
    }
    var_s1++;
    var_s3--;
  }

  if (sp220->unk4 != 0) {
    for (i = sp220->unk4 - 1; i != 0; i--) {
      if (arg0->unk0 & 0x20) {
        func_800A5660(var_s1, &sp120);
      } else {
        func_800A5660(var_s1, &sp160);
        func_800AF0C4(&sp120, &sp1E0, &sp160);
      }
      func_800A56E4(&sp120, &var_s1->unkC->unk80);
      var_s1->unkC->unkC0 = var_s1->unkC->unk80;
      var_s1->unk0 |= 0x2;
      var_s1++;
      var_s3--;
    }
  }

  for (i = var_s3; i != 0; i--) {
    if (var_s1->unk0 & 0x100) {
      func_800A57FC(var_s1, &sp1E0);
    }
    var_s1++;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A60FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6360.s")

static void func_800A652C(UnkStruct_32 *arg0, UnkStruct_50 *arg1) {
  s32 temp_s4;
  UnkStruct_51 *var_s0;
  int i;
  void *temp_v0;
  UnkStruct_49 *temp_v0_3;
  UnkStruct_46 *tmp;

  if (arg1 == NULL) {
    return;
  }

  if (arg1->unk14 & 1) {
    return;
  }

  arg1->unk20.unk0 = arg0->unk8;
  arg1->unk10 = arg0;
  temp_s4 = arg1->unk20.unk4;
  var_s0 = arg1->unk20.unk8;
  for (i = 0; i < temp_s4; i++, var_s0++) {
    temp_v0 = func_800AA134((intptr_t)var_s0->unk0);
    switch (var_s0->unkC) {
    case 0:
      switch (func_800AA038((intptr_t)var_s0->unk0)) {
      case 0:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 1:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 2:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 3:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 4:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 5:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 6:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x20);
        break;
      }
      var_s0->unk0 = temp_v0;
      break;
    case 1:
      // UnkStruct_49*
      temp_v0_3 = &arg1->unk20.unk0->unk10.unk18[(intptr_t)var_s0->unk10];
      var_s0->unk10 = temp_v0_3;
      var_s0->unk0 = temp_v0_3;
      break;
    case 2:
      tmp = temp_v0;
      var_s0->unk10 = &tmp->unk10.unk1C[(intptr_t)var_s0->unk10].unk4;
      var_s0->unk0 = temp_v0;
      break;
    case 3:
      // UnkStruct_68*
      var_s0->unk10 = &arg1->unk20.unk0->unk10.unk34[(intptr_t)var_s0->unk10];
      // or is it this?
      // f32*
      // var_s0->unk10 = &arg1->unk20.unk0->unk10.unk34[(intptr_t)var_s0->unk10].unk0;
      var_s0->unk0 = temp_v0;
      break;
    }
  }

  arg1->unk14 |= 1;
}

void func_800A6734(UnkStruct_32 *arg0) {
  UnkStruct_50 *var_s0;

  var_s0 = arg0->unk1D0;
  rmonPrintf("Animation list\n");
  while (var_s0 != NULL) {
    rmonPrintf("anim : 0x%08X\n", var_s0);
    var_s0 = var_s0->unkC;
  }
}

// push
void func_800A678C(UnkStruct_32 *arg0, UnkStruct_50 *arg1) {
  register UnkStruct_50 *temp_v0;

  if (!(arg1->unk14 & 1)) {
    func_800A652C(arg0, arg1);
  }
  temp_v0 = arg0->unk1D0;
  if (temp_v0 == NULL) {
    arg0->unk1D0 = arg1;
  } else {
    arg1->unkC = temp_v0;
    arg0->unk1D0->unk8 = arg1;
    arg0->unk1D0 = arg1;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A67EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A689C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6974.s")

// arg0 is fx_id
UnkStruct_32 *func_800A6990(s32 arg0) {
  register UnkStruct_32 *temp_v0;

  temp_v0 = n64HeapAlloc(0x1E8);
  if (temp_v0 == NULL) {
    return NULL;
  }

  func_800A9D50();
  temp_v0->unk8 = func_800AA14C(arg0);
  func_800A9D60();
  if (temp_v0->unk8 == NULL) {
    n64HeapUnalloc(temp_v0);
    return NULL;
  }

  temp_v0->unk0 = 0;
  temp_v0->unk4 = 0;
  temp_v0->unk6 = 1;
  temp_v0->unk5 = 0;
  temp_v0->unk1D0 = NULL;
  guMtxIdentF((f32 (*)[4]) &temp_v0->unkC);
  guMtxIdentF((f32 (*)[4]) &temp_v0->unk4C);
  return temp_v0;
}

void func_800A6A2C(UnkStruct_32 *arg0) {
  if (arg0 == NULL) {
    rmonPrintf("BorgAnimFreeScene : NULL handle\n");
    return;
  }

  func_800AB5E0(arg0->unk8);
  n64HeapUnalloc(arg0);
}

// arg0 is fx_id
UnkStruct_50 *func_800A6A74(s32 arg0) {
  register UnkStruct_50 *temp_v0;

  func_800A9D50();
  temp_v0 = func_800AA14C(arg0);
  func_800A9D60();
  return temp_v0;
}

void func_800A6AA8(UnkStruct_50 *obj) {
  func_800AB934(obj);
}

static void func_800A6AC8(UnkStruct_52 *arg0) {
  UnkStruct_53 *temp_v0;
  s32 var_v1;
  f32 *var_a2;
  f32 *var_a1;

  temp_v0 = arg0->unkC;
  arg0->unk6 = 1;
  arg0->unk8 = temp_v0;
  var_v1 = temp_v0->unk2;
  var_a1 = temp_v0->unk4;
  var_a2 = arg0->unk10;
  while (var_v1 != 0) {
    if (var_v1 & 1) {
      *var_a2 = *var_a1;
      var_a1++;
    }
    var_a2++;
    var_v1 >>= 1;
  }
}

static void func_800A6B14(UnkStruct_51 *arg0, f32 arg1) {
  if (arg0->unkC == 1) {
    func_800A6BB0(arg0, arg1);
  } else {
    func_800A6B60(arg0, arg1);
  }
}

static void func_800A6B60(UnkStruct_51 *arg0, f32 arg1) {
  UnkStruct_52 *var_v0;
  s32 var_v1;
  f32 *var_a1;

  var_v0 = arg0->unk1C;
  var_v1 = arg0->unk14;
  var_a1 = arg0->unk10;
  while (var_v1 != 0) {
    if (var_v1 & 1) {
      *var_a1 += var_v0->unk10[0] * arg1;
      var_v0++;
    }
    var_a1++;
    var_v1 >>= 1;  // (bug?) this seems dangerous to do on a signed int, which may lead to the while loop never ending
  }
}

static void func_800A6BB0(UnkStruct_51 *arg0, f32 arg1) {
  UnkStruct_49 *temp_v0;
  UnkStruct_52 *var_t0;
  s32 var_t1;
  s32 var_t2;
  f32 *var_v1;
  f32 *var_a1;
  f32 *var_a3;

  temp_v0 = arg0->unk10;
  var_v1 = temp_v0->unk10;
  var_a1 = temp_v0->unkC->unk158;
  var_a3 = temp_v0->unkC->unk164;
  var_t0 = arg0->unk1C;
  var_t1 = arg0->unk14;

  for (var_t2 = 3; var_t2 != 0; var_t2--, var_t1 >>= 1) {
    if (var_t1 & 1) {
      *var_v1 += var_t0->unk10[0] * arg1;
      *var_a1 += var_t0->unk10[1] * arg1;
      *var_a3 += var_t0->unk10[2] * arg1;
      var_t0++;
    }
    var_v1++;
    var_a1++;
    var_a3++;
  }

  var_a1 = temp_v0->unkC->unk140;
  var_a3 = temp_v0->unkC->unk14C;
  for (var_t2 = 3; var_t2 != 0; var_t2--, var_t1 >>= 1) {
    if (var_t1 & 1) {
      *var_v1 += var_t0->unk10[0] * arg1;
      *var_a1 += var_t0->unk10[1] * arg1;
      *var_a3 += var_t0->unk10[2] * arg1;
      var_t0++;
    }
    var_v1++;
    var_a1++;
    var_a3++;
  }

  for (var_t2 = 3; var_t2 != 0; var_t2--, var_t1 >>= 1) {
    if (var_t1 & 1) {
      *var_v1 += var_t0->unk10[0] * arg1;
      var_t0++;
    }
    var_v1++;
  }
}

static void func_800A6D08(UnkStruct_51 *arg0) {
  UnkStruct_49 *temp_v0;
  UnkStruct_63 *temp_a1;
  f32 *var_v1;
  s32 var_v0;

  if (arg0->unkC == 1) {
    temp_v0 = arg0->unk10;
    var_v1 = temp_v0->unk10;
    temp_a1 = temp_v0->unkC;
    temp_a1->unk164[2] = 0;
    temp_a1->unk164[1] = 0;
    temp_a1->unk164[0] = 0;
    temp_a1->unk158[2] = 0;
    temp_a1->unk158[1] = 0;
    temp_a1->unk158[0] = 0;
    temp_a1->unk14C[2] = 0;
    temp_a1->unk14C[1] = 0;
    temp_a1->unk14C[0] = 0;
    temp_a1->unk140[2] = 0;
    temp_a1->unk140[1] = 0;
    temp_a1->unk140[0] = 0;
  } else {
    var_v1 = arg0->unk10;
  }

  var_v0 = arg0->unk14;
  while (var_v0 != 0) {
    if (var_v0 & 1) {
      *var_v1 = 0;
    }
    var_v1++;
    var_v0 >>= 1;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6DD8.s")

static void func_800A6E48(UnkStruct_51 *arg0) {
  UnkStruct_52 *var_s0;
  s32 var_s1;
  UnkStruct_53 *temp_a2;
  s32 var_a1;
  f32 *var_v0;
  f32 *var_a0;
  s32 var_v1;

  var_s0 = arg0->unk1C;
  for (var_s1 = arg0->unk18; var_s1 != 0; var_s1--) {
    if (var_s0->unk6 == var_s0->unk4) {
      switch (var_s0->unk0) {
      case 0:
        func_800A6AC8(var_s0);
        break;
      case 1:
        func_800A6AC8(var_s0);
        break;
      case 2:
        func_800A6AC8(var_s0);
        break;
      }
    } else {
      temp_a2 = var_s0->unk8;
      var_a1 = 4;
      temp_a2++;
      if (temp_a2->unk0 == var_s0->unk6) {
        var_s0->unk8 = temp_a2;
        var_v0 = var_s0->unk10;
        var_a0 = var_s0->unk8->unk4;
        var_v1 = var_s0->unk8->unk2;
        while (var_a1 != 0) {
          if (var_v1 & 1) {
            break;
          }
          var_v0++;
          var_v1 >>= 1;
          var_a1--;
        }
        while (var_a1 != 0) {
          if (var_v1 & 1) {
            *var_v0 = *var_a0;
            var_a0++;
          } else {
            *var_v0 = 0;
          }
          var_v0++;
          var_v1 >>= 1;
          var_a1--;
        }
      }

      temp_a2 = var_s0->unk8;
      var_v1 = temp_a2->unk2;
      var_v0 = var_s0->unk10;
      var_a0 = var_v0 + 1;
      if (var_v1 & 0x2) {
        *var_v0 += *var_a0;
        if (var_v1 & 0x4) {
          var_v0++;
          var_a0++;
          *var_v0 += *var_a0;
          if (var_v1 & 0x8) {
            var_v0++;
            var_a0++;
            *var_v0 += *var_a0;
          }
        }
      }

      var_s0->unk6++;
    }

    var_s0++;
  }
}

static void func_800A70A8(UnkStruct_32 *arg0) {
  s32 var_s0;
  UnkStruct_51 *var_s1;
  s32 var_s2;
  UnkStruct_50 *var_s3;
  f32 temp_fs0;

  if (arg0->unk5 != 0) {
    if (arg0->unk1D0 != NULL) {
      for (var_s3 = arg0->unk1D0; var_s3 != NULL; var_s3 = var_s3->unkC) {
        var_s1 = var_s3->unk20.unk8;
        for (var_s2 = var_s3->unk20.unk4; var_s2 != 0; var_s2--) {
          for (var_s0 = arg0->unk5; var_s0 != 0; var_s0--) {
            func_800A6E48(var_s1);
          }
          func_800A6D08(var_s1);
          var_s1++;
        }
      }

      for (var_s3 = arg0->unk1D0; var_s3 != NULL; var_s3 = var_s3->unkC) {
        temp_fs0 = var_s3->unk18;
        if (temp_fs0 != 0.0) {
          var_s1 = var_s3->unk20.unk8;
          for (var_s0 = var_s3->unk20.unk4; var_s0 != 0; var_s0--) {
            func_800A6B14(var_s1, temp_fs0);
            var_s1++;
          }
        }
      }

      arg0->unk6 += arg0->unk5;
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A71DC.s")

Gfx *func_800A724C(Gfx *gdl, UnkStruct_32 *arg1) {
  func_800A70A8(arg1);
  func_800A58A4(arg1);
  return func_800A7EFC(gdl, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A7288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A72B8.s")

static Gfx *func_800A7374(Gfx *gdl) {
  D_801293F0.gm_set = G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH;
  D_801293F0.gm_clr = G_FOG | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR;
  D_801293F0.unk4C = G_CYC_1CYCLE;
  D_801293F0.red = 0;
  D_801293F0.green = 0;
  D_801293F0.blue = 0;
  D_801293F0.alpha = 0;
  D_801293F0.mode1 = G_RM_AA_ZB_OPA_SURF;
  D_801293F0.mode2 = G_RM_AA_ZB_OPA_SURF2;
  D_801293F0.unk44 = G_TF_BILERP;

  gSPClearGeometryMode(gdl++, D_801293F0.gm_clr);
  gSPSetGeometryMode(gdl++, D_801293F0.gm_set);
  gDPSetCycleType(gdl++, D_801293F0.unk4C);
  gDPSetPrimColor(gdl++, 0, 0, D_801293F0.red, D_801293F0.green, D_801293F0.blue, D_801293F0.alpha);
  gDPSetRenderMode(gdl++, D_801293F0.mode1, D_801293F0.mode2);
  gDPSetTextureFilter(gdl++, D_801293F0.unk44);

  D_80129390 = D_801293F0;

  return gdl;
}

static Gfx *func_800A74DC(Gfx *gdl) {
  s32 temp_a2;
  s32 red;
  s32 green;
  s32 blue;
  s32 alpha;

  temp_a2 = D_801293F0.unk14->unk0;

  if (D_801293F0.unk10 != NULL) {
    if (temp_a2 & 0x1) {
      gSPTexture(gdl++, D_801293F0.unk10->unk8.unk2 << 6, D_801293F0.unk10->unk8.unk4 << 6, D_801293F0.unk10->unk8.unk7, G_TX_RENDERTILE, G_ON);
    } else {
      u16 level;

      if (D_801293F0.unk10->unk8.unk6 & 0x40) {
        level = D_801293F0.unk10->unk8.unk7 - 1;
      } else {
        level = D_801293F0.unk10->unk8.unk7;
      }

      gSPTexture(gdl++, 0x8000, 0x8000, level, G_TX_RENDERTILE, G_ON);
    }
  }

  gDPPipeSync(gdl++);

  D_801293F0.gm_set = G_SHADE;
  D_801293F0.gm_clr = 0;

  if (temp_a2 & 0x200) {
    D_801293F0.gm_clr |= G_ZBUFFER;
  } else {
    D_801293F0.gm_set |= G_ZBUFFER;
  }

  if (temp_a2 & 0x10) {
    D_801293F0.gm_set |= G_SHADING_SMOOTH;
  } else {
    D_801293F0.gm_clr |= G_SHADING_SMOOTH;
  }

  if (temp_a2 & 0x4) {
    D_801293F0.gm_set |= G_CULL_BACK;
  } else {
    D_801293F0.gm_clr |= G_CULL_BACK;
  }

  if (temp_a2 & 0x8) {
    D_801293F0.gm_clr |= G_LIGHTING;
  } else {
    D_801293F0.gm_set |= G_LIGHTING;
  }

  if (temp_a2 & 0x1) {
    D_801293F0.gm_set |= G_TEXTURE_GEN;
    if (temp_a2 & 0x2) {
      D_801293F0.gm_set |= G_TEXTURE_GEN_LINEAR;
    } else {
      D_801293F0.gm_clr |= G_TEXTURE_GEN_LINEAR;
    }
  } else {
    D_801293F0.gm_clr |= G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR;
  }

  if ((D_801293F0.unk4->unk20 != NULL) && !(temp_a2 & 0x400)) {
    s32 fog_min;
    s32 fog_max;

    red = D_801293F0.unk4->unk20->red * 255;
    green = D_801293F0.unk4->unk20->green * 255;
    blue = D_801293F0.unk4->unk20->blue * 255;
    alpha = D_801293F0.unk4->unk20->alpha * 255;

    if (red < 0)      red = 0;
    if (red > 0xFF)   red = 0xFF;

    if (green < 0)    green = 0;
    if (green > 0xFF) green = 0xFF;

    if (blue < 0)     blue = 0;
    if (blue > 0xFF)  blue = 0xFF;

    if (alpha < 0)    alpha = 0;
    if (alpha > 0xFF) alpha = 0xFF;

    gDPSetFogColor(gdl++, red, green, blue, alpha);

    fog_min = D_801293F0.unk4->unk20->min;
    fog_max = D_801293F0.unk4->unk20->max;
    if (fog_min != fog_max) {
      gSPFogPosition(gdl++, fog_min, fog_max);
    }

    D_801293F0.gm_set |= G_FOG;
  } else {
    D_801293F0.gm_clr |= G_FOG;
  }

  if (D_80129390.gm_clr != D_801293F0.gm_clr) {
    gSPClearGeometryMode(gdl++, D_801293F0.gm_clr);
  }

  if (D_80129390.gm_set != D_801293F0.gm_set) {
    gSPSetGeometryMode(gdl++, D_801293F0.gm_set);
  }

  if (temp_a2 & 0x80) {
    D_801293F0.unk44 = G_TF_POINT;
  } else {
    D_801293F0.unk44 = G_TF_BILERP;
  }

  if (D_80129390.unk44 != D_801293F0.unk44) {
    gDPSetTextureFilter(gdl++, D_801293F0.unk44);
  }

  red = D_801293F0.unk14->unk4 * 255;
  green = D_801293F0.unk14->unk8 * 255;
  blue = D_801293F0.unk14->unkC * 255;
  alpha = (1 - D_801293F0.unk14->unk10) * (1 - D_801293F0.unkC->unk10.unk0) * 255;

  if (red < 0)      red = 0;
  if (red > 0xFF)   red = 0xFF;

  if (green < 0)    green = 0;
  if (green > 0xFF) green = 0xFF;

  if (blue < 0)     blue = 0;
  if (blue > 0xFF)  blue = 0xFF;

  if (alpha < 0)    alpha = 0;
  if (alpha > 0xFF) alpha = 0xFF;

  D_801293F0.red = red;
  D_801293F0.green = green;
  D_801293F0.blue = blue;
  D_801293F0.alpha = alpha;
  if ((D_801293F0.red != D_80129390.red) || (D_801293F0.green != D_80129390.green) || (D_801293F0.blue != D_80129390.blue) || (D_801293F0.alpha != D_80129390.alpha)) {
    gDPSetPrimColor(gdl++, 0, 0, D_801293F0.red, D_801293F0.green, D_801293F0.blue, D_801293F0.alpha);
  }

  if (D_801293F0.alpha < 0xFF) {
    if (temp_a2 & 0x100) {
      D_801293F0.mode1 = G_RM_AA_ZB_XLU_DECAL;
      D_801293F0.mode2 = G_RM_AA_ZB_XLU_DECAL2;
    } else {
      D_801293F0.mode1 = G_RM_AA_ZB_XLU_SURF | Z_UPD;
      D_801293F0.mode2 = G_RM_AA_ZB_XLU_SURF2 | Z_UPD;
    }
  } else if (D_801293F0.unk10 != NULL) {
    s16 temp_t3;

    temp_t3 = D_801293F0.unk10->unk8.unk0;

    if (D_801293F0.unk10->unk8.unk6 & 0x20) {
      if (temp_a2 & 0x100) {
        D_801293F0.mode1 = G_RM_AA_ZB_XLU_DECAL;
        D_801293F0.mode2 = G_RM_AA_ZB_XLU_DECAL2;
      } else if ((temp_t3 == 1) || (temp_t3 == 3) || (temp_t3 == 8)) {
        D_801293F0.mode1 = G_RM_AA_ZB_XLU_SURF | Z_UPD;
        D_801293F0.mode2 = G_RM_AA_ZB_XLU_SURF2 | Z_UPD;
      } else {
        D_801293F0.mode1 = G_RM_AA_ZB_TEX_EDGE;
        D_801293F0.mode2 = G_RM_AA_ZB_TEX_EDGE2;
      }
    } else if (temp_a2 & 0x100) {
      D_801293F0.mode1 = G_RM_AA_ZB_OPA_DECAL;
      D_801293F0.mode2 = G_RM_AA_ZB_OPA_DECAL2;
    } else {
      D_801293F0.mode1 = G_RM_AA_ZB_OPA_SURF;
      D_801293F0.mode2 = G_RM_AA_ZB_OPA_SURF2;
    }
  } else if (temp_a2 & 0x100) {
    D_801293F0.mode1 = G_RM_AA_ZB_OPA_DECAL;
    D_801293F0.mode2 = G_RM_AA_ZB_OPA_DECAL2;
  } else {
    D_801293F0.mode1 = G_RM_AA_ZB_OPA_SURF;
    D_801293F0.mode2 = G_RM_AA_ZB_OPA_SURF2;
  }

  if (!(temp_a2 & 0x40)) {
    D_801293F0.mode1 &= ~AA_EN;
    D_801293F0.mode2 &= ~AA_EN;
  }

  if (temp_a2 & 0x200) {
    D_801293F0.mode1 &= ~(Z_CMP | Z_UPD);
    D_801293F0.mode2 &= ~(Z_CMP | Z_UPD);
  }

  D_801293F0.unk4C = G_CYC_1CYCLE;
  if (D_801293F0.unk10 != NULL) {
    if ((D_801293F0.unk10->unk8.unk7 != 0) || (D_801293F0.unk10->unk8.unk6 & 0x40)) {
      D_801293F0.mode1 = G_RM_PASS;
      D_801293F0.unk4C = G_CYC_2CYCLE;
    } else if (temp_a2 & 0x1) {
      D_801293F0.mode1 = G_RM_PASS;
      D_801293F0.unk4C = G_CYC_2CYCLE;
    }
  }
  if ((D_801293F0.unk4->unk20 != NULL) && !(temp_a2 & 0x400)) {
    D_801293F0.mode1 = G_RM_FOG_SHADE_A;
    D_801293F0.unk4C = G_CYC_2CYCLE;
  }

  if (D_801293F0.unk10 != NULL) {
    if (temp_a2 & 0x1) {
      gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_H2O_A2);
    } else if ((D_801293F0.unk10->unk8.unk7 != 0) || (D_801293F0.unk10->unk8.unk6 & 0x40)) {
      if (temp_a2 & 0x100) {
        gDPSetCombineMode(gdl++, G_CC_TRILERP, G_CC_H2O_A2);
      } else {
        gDPSetCombineMode(gdl++, G_CC_TRILERP, G_CC_H2O_A2);
      }
    } else if ((D_801293F0.unk4->unk20 != NULL) && !(temp_a2 & 0x400)) {
      if (temp_a2 & 0x100) {
        gDPSetCombineMode(gdl++, G_CC_H2O_A, G_CC_DECALRGB2);
      } else {
        gDPSetCombineMode(gdl++, G_CC_H2O_A, G_CC_H2O_A2);
      }
    } else if (temp_a2 & 0x100) {
      gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
      gDPSetCombineMode(gdl++, G_CC_H2O_A, G_CC_H2O_A);
    }
  } else if ((D_801293F0.unk4->unk20 != NULL) && !(temp_a2 & 0x400)) {
    gDPSetCombineMode(gdl++, G_CC_PASS2, G_CC_H2O_B);
  } else {
    gDPSetCombineMode(gdl++, G_CC_H2O_B, G_CC_H2O_B);
  }

  gDPSetCycleType(gdl++, D_801293F0.unk4C);
  gDPSetRenderMode(gdl++, D_801293F0.mode1, D_801293F0.mode2);

  D_80129390 = D_801293F0;

  return gdl;
}

static Gfx *func_800A7EFC(Gfx *gdl, UnkStruct_32 *arg1) {
  static s32 D_80129580;
  static s32 D_80129584;  // padding; what is this?
  static s32 D_80129588;
  static s32 D_8012958C;  // padding; what is this?
  static UnkStruct_45 *D_80129590;
  static UnkStruct_49 *D_80129594;
  static u8 D_80129598[0x40];  // padding; what is this?
  static MtxF *D_801295D8;
  static s16 *D_801295DC;

  s32 tmp;
  s32 temp_t6;
  f32 red, green, blue;
  u32 color;
  s32 var_a2;
  s32 var_s0;
  UnkStruct_39 **var_a0;
  MtxF *temp_v1_2;
  s8 *dir;
  f32 temp_fv0_4;

  temp_t6 = arg1->unk4 & 1;

  D_801293F0.unk0 = arg1;
  D_801293F0.unk4 = &arg1->unk8->unk10;
  D_801293F0.unkC = NULL;
  D_801293F0.unk10 = NULL;
  D_801293F0.unk14 = NULL;

  D_80129594 = arg1->unk8->unk10.unk18;
  gDPPipeSync(gdl++);
  if (D_801293F0.unk4->unk24 != NULL) {
    if (!(D_801293F0.unk0->unk0 & 0x40)) {
      D_80129590 = D_801293F0.unk4->unk24;
      gDPSetAlphaCompare(gdl++, G_AC_NONE);
      gDPSetDepthSource(gdl++, G_ZS_PIXEL);
      gDPSetAlphaDither(gdl++, G_AD_NOISE);
      gDPSetColorDither(gdl++, G_CD_NOISE);
      gDPSetCombineKey(gdl++, G_CK_NONE);
      gDPSetTextureConvert(gdl++, G_TC_FILT);
      gDPSetTextureFilter(gdl++, G_TF_BILERP);
      gDPSetTextureLOD(gdl++, G_TL_LOD);
      gDPSetTextureLUT(gdl++, G_TT_NONE);
      gDPSetTextureDetail(gdl++, G_TD_CLAMP);
      gDPSetTexturePersp(gdl++, G_TP_PERSP);
      gDPSetCycleType(gdl++, G_CYC_1CYCLE);
      gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
      gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x80);
      gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
      gDPPipelineMode(gdl++, G_PM_NPRIMITIVE);
      gSPMatrix(gdl++, &D_80129590->unk10.unk1C->unk0[temp_t6], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
      gSPPerspNormalize(gdl++, D_80129590->unk8[temp_t6]);
      gSPViewport(gdl++, D_80129590->unk10.unk18);
    }
    D_80129594++;
  }

  D_80129588 = 0;
  if ((D_801293F0.unk4->unk28 != NULL) && !(D_801293F0.unk0->unk0 & 0x80)) {
    var_a0 = D_801293F0.unk4->unk28;
    for (D_80129580 = D_801293F0.unk4->unk4; D_80129580 != 0; D_80129580--) {
      temp_v1_2 = &D_80129594->unkC->unkC0;
      dir = ((*var_a0)->unk8.unk10->lights + temp_t6)->l.dir;
      *dir++ = temp_v1_2->m20 * 90;
      *dir++ = temp_v1_2->m21 * 90;
      *dir = temp_v1_2->m22 * 90;

      red = (*var_a0)->unk8.red;
      if (red > 1.0) {
        red = 1.0;
      } else if (red < 0.0) {
        red = 0.0;
      }

      green = (*var_a0)->unk8.green;
      if (green > 1.0) {
        green = 1.0;
      } else if (green < 0.0) {
        green = 0.0;
      }

      blue = (*var_a0)->unk8.blue;
      if (blue > 1.0) {
        blue = 1.0;
      } else if (blue < 0.0) {
        blue = 0.0;
      }

      color = ((*var_a0)->unk8.unk0 * red) * 255.0;
      (*var_a0)->unk8.unk10->lights[temp_t6].l.colc[0] = (s8) color;  // (bug?) why s8?  shouldn't it have been u8?
      (*var_a0)->unk8.unk10->lights[temp_t6].l.col[0] = (s8) color;

      color = ((*var_a0)->unk8.unk0 * green) * 255.0;
      (*var_a0)->unk8.unk10->lights[temp_t6].l.colc[1] = (s8) color;
      (*var_a0)->unk8.unk10->lights[temp_t6].l.col[1] = (s8) color;

      color = ((*var_a0)->unk8.unk0 * blue) * 255.0;
      (*var_a0)->unk8.unk10->lights[temp_t6].l.colc[2] = (s8) color;
      (*var_a0)->unk8.unk10->lights[temp_t6].l.col[2] = (s8) color;

      D_801293F0.unk1C[D_80129588] = *var_a0++;
      D_80129594++;
      D_80129588++;
    }

    if (D_801293F0.unk4->unk4 == 1) {
      gSPLight(gdl++, D_801293F0.unk4->unk28[0]->unk8.unk10->lights + temp_t6, 2);
      gSPLight(gdl++, &D_800D6208, 1);
    } else {
      var_a2 = 1;
      var_a0 = D_801293F0.unk4->unk28;
      for (D_80129580 = D_801293F0.unk4->unk4; D_80129580 != 0; D_80129580--) {
        gSPLight(gdl++, (*var_a0)->unk8.unk10->lights + temp_t6, var_a2);
        var_a2++;
        var_a0++;
      }
    }

    switch (D_80129588) {
    case 1:
      gSPNumLights(gdl++, 1);
      break;
    case 2:
      gSPNumLights(gdl++, 1);
      break;
    case 3:
      gSPNumLights(gdl++, 2);
      break;
    case 4:
      gSPNumLights(gdl++, 3);
      break;
    case 5:
      gSPNumLights(gdl++, 4);
      break;
    case 6:
      gSPNumLights(gdl++, 5);
      break;
    case 7:
      gSPNumLights(gdl++, 6);
      break;
    case 8:
      gSPNumLights(gdl++, 7);
      break;
    }
  } else if (D_801293F0.unk4->unk4 != 0) {
    for (D_80129580 = D_801293F0.unk4->unk4; D_80129580 != 0; D_80129580--) {
      D_80129594++;
    }
  }

  for (D_80129580 = D_80129588; D_80129580 < 8; D_80129580++) {
    D_801293F0.unk1C[D_80129580] = NULL;
  }

  gdl = func_800A7374(gdl);

  for (D_80129580 = D_801293F0.unk4->unk14, D_801295DC = D_801293F0.unk4->unk38; D_80129580 != 0; D_80129580--, D_801295DC++) {
    tmp = *D_801295DC >> 8;
    var_s0 = *D_801295DC & 0xFF;
    switch (tmp) {
    case 3:
      tmp = var_s0;
      var_s0 = D_801293F0.unk4->unk34[tmp].unk0;
      if (D_801293F0.unk4->unk34[tmp].unk6 < var_s0) {
        var_s0 = D_801293F0.unk4->unk34[tmp].unk6;
      }
      var_s0 += D_801293F0.unk4->unk34[tmp].unk4;
      /* fallthrough */
    case 1:
      if (var_s0 == 0xFF) {
        D_801293F0.unk10 = NULL;

        gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
      } else {
        D_801293F0.unk10 = D_801293F0.unk4->unk30[var_s0];

        gdl = func_800A4B98(gdl, D_801293F0.unk10);
      }
      break;
    case 2:
      D_801293F0.unk8 = &D_801293F0.unk4->unk18[var_s0];

      gSPMatrix(gdl++, &D_801293F0.unk8->unkC->unk0[temp_t6], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

      if (D_801293F0.unk8->unk0 & 0x2) {
        break;
      }

      D_801295D8 = &D_801293F0.unk8->unkC->unk80;

      if (D_801293F0.unk8->unk0 & 0x200) {
        Vec3 sp110;
        Vec3 sp104;
        Vec3 spF8;
        MtxF *temp_s0;
        UnkStruct_49 *temp_s1;

        temp_s0 = &D_801293F0.unk8->unkC->unkC0;
        temp_s1 = D_801293F0.unk8;

        sp110.x = arg1->unk4C.m30 - temp_s0->m30;
        sp110.y = arg1->unk4C.m31 - temp_s0->m31;
        sp110.z = arg1->unk4C.m32 - temp_s0->m32;

        guNormalize(&sp110.x, &sp110.y, &sp110.z);

        sp104.x = temp_s0->m10;
        sp104.y = temp_s0->m11;
        sp104.z = temp_s0->m12;

        vec3_cross(&spF8, &sp104, &sp110);

        guNormalize(&spF8.x, &spF8.y, &spF8.z);

        vec3_cross(&sp110, &spF8, &sp104);

        D_801295D8->m00 = temp_s1->unk10[6] * spF8.x;
        D_801295D8->m01 = temp_s1->unk10[6] * spF8.y;
        D_801295D8->m02 = temp_s1->unk10[6] * spF8.z;
        D_801295D8->m10 = temp_s1->unk10[7] * sp104.x;
        D_801295D8->m11 = temp_s1->unk10[7] * sp104.y;
        D_801295D8->m12 = temp_s1->unk10[7] * sp104.z;
        D_801295D8->m20 = temp_s1->unk10[8] * sp110.x;
        D_801295D8->m21 = temp_s1->unk10[8] * sp110.y;
        D_801295D8->m22 = temp_s1->unk10[8] * sp110.z;
        D_801295D8->m30 = temp_s0->m30;
        D_801295D8->m31 = temp_s0->m31;
        D_801295D8->m32 = temp_s0->m32;
        D_801295D8->m33 = 1;
        D_801295D8->m03 = 0;
        D_801295D8->m13 = 0;
        D_801295D8->m23 = 0;
      } else {
        D_801293F0.unk8->unkC->unk80 = D_801293F0.unk8->unkC->unkC0;
      }

      temp_fv0_4 = D_801293F0.unkC->unk10.unk8;
      D_801295D8->m00 *= temp_fv0_4;
      D_801295D8->m10 *= temp_fv0_4;
      D_801295D8->m20 *= temp_fv0_4;
      D_801295D8->m01 *= temp_fv0_4;
      D_801295D8->m11 *= temp_fv0_4;
      D_801295D8->m21 *= temp_fv0_4;
      D_801295D8->m02 *= temp_fv0_4;
      D_801295D8->m12 *= temp_fv0_4;
      D_801295D8->m22 *= temp_fv0_4;
      D_801295D8->m30 *= 16;
      D_801295D8->m31 *= 16;
      D_801295D8->m32 *= 16;

      guMtxF2L((f32 (*)[4]) D_801295D8, &D_801293F0.unk8->unkC->unk0[temp_t6]);

      D_801293F0.unk8->unk0 |= 2;
      break;
    case 4:
      D_801293F0.unkC = D_801293F0.unk4->unk2C[var_s0];

      gSPSegment(gdl++, 0x0A, osVirtualToPhysical(D_801293F0.unkC->unk10.unk10));
      break;
    case 5:
      D_801293F0.unk14 = &D_801293F0.unkC->unk10.unk1C[var_s0];

      if (D_801293F0.unk14 != NULL) {
        if (D_801293F0.unkC->unk10.unk0 < 1.0f) {
          if (D_801293F0.unk14->unk10 < 1.0f) {

            gdl = func_800A74DC(gdl);

            if (D_801293F0.unk14->unk0 & 1) {
              Mtx spA8;

              guLookAtReflect(&spA8, D_801293F0.unkC->unk8->unk0 + temp_t6, arg1->unk4C.m30, arg1->unk4C.m31, arg1->unk4C.m32, D_801293F0.unk8->unkC->unkC0.m30, D_801293F0.unk8->unkC->unkC0.m31, D_801293F0.unk8->unkC->unkC0.m32, 0.0, 1.0, 0.0);
              gSPLookAt(gdl++, D_801293F0.unkC->unk8->unk0 + temp_t6);
            }
            gSPDisplayList(gdl++, osVirtualToPhysical(D_801293F0.unkC->unk10.unkC[var_s0]));
          }
        }
      }
      break;
    }
  }

  arg1->unk4 ^= 1;
  D_801293F0.unk4 = NULL;

  return gdl;
}
