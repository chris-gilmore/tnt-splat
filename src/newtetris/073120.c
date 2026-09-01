#include "common.h"

static Mtx D_800D9110 = {
  {
    { 0x00010000, 0x00000000,
      0x00000001, 0x00000000 },
    { 0x00000000, 0x00010000,
      0x00000000, 0x00000001 },

    { 0x00000000, 0x00000000,
      0x00000000, 0x00000000 },
    { 0x00000000, 0x00000000,
      0x00000000, 0x00000000 }
  }
};

static Gfx  *func_800AD2FC(Gfx *, UnkStruct_86 *, UnkStruct_32 *);

UnkStruct_86 *func_800ACEA0(u32 arg0, UnkStruct_44 *arg1) {
  UnkStruct_86 *sp2C;
  UnkStruct_87 *var_v0;
  Mtx *var_v1;
  s32 sp1C;
  u8 *ptr;
  s16 sc;
  s16 tc;

  sp1C = (sizeof(UnkStruct_86) + arg0 * sizeof(UnkStruct_87) + 0xF) & ~0xF;
  ptr = n64HeapAlloc(sp1C + arg0 * 2 * sizeof(Mtx));
  if (ptr == NULL) {
    return NULL;
  }

  sp2C = (UnkStruct_86 *) ptr;
  sp2C->unkC0 = arg0;
  sp2C->unkC4 = (UnkStruct_87 *) (ptr + sizeof(UnkStruct_86));
  sp2C->unkC8 = 0;
  sp2C->unkCC = sp2C->unkC4;
  sp2C->unk11C = 0;

  if (arg1 == NULL) {
    sp2C->unkD0 = func_800B303C();
  } else {
    sp2C->unkD0 = arg1;
  }

  sp2C->unkD4 = 60;
  sp2C->unkDC = 1;
  sp2C->unkEC = 1;
  sp2C->unk104 = 0.5;
  sp2C->unk108 = 0.5;
  sp2C->unkD8 = 0;
  sp2C->unkE0 = 0;
  sp2C->unkE8 = 0;
  sp2C->unkF0 = 0;
  sp2C->unk10C = 16;
  sp2C->unk110 = 16;
  sp2C->unk114 = 0.995;
  sp2C->unk118 = 0;
  sp2C->unkF8.x = 0;
  sp2C->unkF8.y = 0;
  sp2C->unkF8.z = 0;

  sc = sp2C->unkD0->unk8.unk2;
  tc = sp2C->unkD0->unk8.unk4;

  var_v1 = (Mtx *) (sp1C + ptr);
  var_v0 = sp2C->unkC4;

  sp2C->unk80[0].v.ob[0] = -256;
  sp2C->unk80[0].v.ob[1] = 256;
  sp2C->unk80[0].v.ob[2] = 0;
  sp2C->unk80[0].v.flag = 0;
  sp2C->unk80[0].v.tc[0] = 0;
  sp2C->unk80[0].v.tc[1] = 0;

  sp2C->unk80[1].v.ob[0] = 256;
  sp2C->unk80[1].v.ob[1] = 256;
  sp2C->unk80[1].v.ob[2] = 0;
  sp2C->unk80[1].v.flag = 0;
  sp2C->unk80[1].v.tc[0] = sc << 6;
  sp2C->unk80[1].v.tc[1] = 0;

  sp2C->unk80[2].v.ob[0] = 256;
  sp2C->unk80[2].v.ob[1] = -256;
  sp2C->unk80[2].v.ob[2] = 0;
  sp2C->unk80[2].v.flag = 0;
  sp2C->unk80[2].v.tc[0] = sc << 6;
  sp2C->unk80[2].v.tc[1] = tc << 6;

  sp2C->unk80[3].v.ob[0] = -256;
  sp2C->unk80[3].v.ob[1] = -256;
  sp2C->unk80[3].v.ob[2] = 0;
  sp2C->unk80[3].v.flag = 0;
  sp2C->unk80[3].v.tc[0] = 0;
  sp2C->unk80[3].v.tc[1] = tc << 6;

  for (sp1C = sp2C->unkC0; sp1C != 0; sp1C--, var_v0++) {
    var_v0->unk20[0] = var_v1++;
    var_v0->unk1C = -1;
    var_v0->unk0 = 1;
  }

  var_v0 = sp2C->unkC4;

  for (sp1C = sp2C->unkC0; sp1C != 0; sp1C--, var_v0++) {
    var_v0->unk20[1] = var_v1++;
  }

  return sp2C;
}

void func_800AD120(UnkStruct_86 *arg0) {
  n64HeapUnalloc(arg0);
}

void func_800AD140(UnkStruct_86 *arg0, Vec3 *arg1, Vec3 *arg2) {
  UnkStruct_87 *temp_v0 = arg0->unkCC;

  if (arg2 != NULL) {
    temp_v0->unk10 = *arg2;
  } else {
    temp_v0->unk10.x = 0;
    temp_v0->unk10.y = 0;
    temp_v0->unk10.z = 0;
  }

  if (arg1 != NULL) {
    temp_v0->unk4 = *arg1;
  } else {
    temp_v0->unk4.x = 0;
    temp_v0->unk4.y = 0;
    temp_v0->unk4.z = 0;
  }

  temp_v0->unk1C = 0;
  arg0->unkC8++;
  arg0->unkCC++;
  if (arg0->unkC8 == arg0->unkC0) {
    arg0->unkC8 = 0;
    arg0->unkCC = arg0->unkC4;
  }
}

void func_800AD1E4(UnkStruct_86 *arg0) {
  s32 var_s2;
  UnkStruct_87 *var_s0;

  for (var_s2 = arg0->unkC0, var_s0 = arg0->unkC4; var_s2 != 0; var_s2--, var_s0++) {
    if (var_s0->unk1C != -1) {
      var_s0->unk1C++;
      if (var_s0->unk1C == arg0->unkD4) {
        var_s0->unk1C = -1;
      } else {
        var_s0->unk4.x += var_s0->unk10.x;
        var_s0->unk4.y += var_s0->unk10.y;
        var_s0->unk4.z += var_s0->unk10.z;

        if (arg0->unk11C != NULL) {
          arg0->unk11C(var_s0);
        } else {
          var_s0->unk10.x += arg0->unkF8.x;
          var_s0->unk10.y += arg0->unkF8.y;
          var_s0->unk10.z += arg0->unkF8.z;
        }

        var_s0->unk10.x *= arg0->unk114;
        var_s0->unk10.y *= arg0->unk114;
        var_s0->unk10.z *= arg0->unk114;
      }
    }
  }
}

static Gfx *func_800AD2FC(Gfx *gdl, UnkStruct_86 *arg1, UnkStruct_32 *arg2) {
  UnkStruct_87 *var_s2;
  s32 var_s4;
  s32 sp11C;
  s32 var_s6;
  f32 temp_fs0;
  f32 temp_fs1;
  f32 var_fv0;
  f32 tmp;
  UnkStruct_84 spF8;
  UnkStruct_84 spE8;
  Mtx4 spA8;
  u8 r, g, b, a;

  if (arg1->unk118 & 0x4) {
    sp11C = 0;
  } else {
    sp11C = 1;
  }

  gdl = func_800A4B98(gdl, arg1->unkD0);
  if (arg2->unk0 & 0x100) {
    gSPDisplayList(gdl++, D_800D9248);
  } else {
    gSPDisplayList(gdl++, D_800D9208);
  }

  var_s2 = arg1->unkCC;
  var_s4 = arg1->unkC8;
  for (var_s6 = arg1->unkC0; var_s6 != 0; var_s6--) {
    if (var_s4 == 0) {
      var_s4 = arg1->unkC0;
      var_s2 = arg1->unkC4 + var_s4;
    }
    var_s2--;
    var_s4--;
    if (var_s2->unk1C != -1) {
      temp_fs0 = (f32) var_s2->unk1C / arg1->unkD4;
      temp_fs1 = 1.0 - temp_fs0;
      spA8 = arg2->unk4C;
      spA8.a14 = var_s2->unk4.x * 16;
      spA8.a24 = var_s2->unk4.y * 16;
      spA8.a34 = var_s2->unk4.z * 16;
      if (arg1->unk118 & 0x1) {
        var_fv0 = var_s2->unk0;
      } else {
        var_fv0 = (arg1->unk10C * temp_fs1) + (arg1->unk110 * temp_fs0);
      }
      var_fv0 *= 0.0625;
      spA8.a11 *= var_fv0;
      spA8.a12 *= var_fv0;
      spA8.a13 *= var_fv0;
      spA8.a21 *= var_fv0;
      spA8.a22 *= var_fv0;
      spA8.a23 *= var_fv0;
      spA8.a31 *= var_fv0;
      spA8.a32 *= var_fv0;
      spA8.a33 *= var_fv0;
      guMtxF2L((f32 (*)[4]) &spA8, var_s2->unk20[sp11C]);
      spF8.unk0 = (arg1->unkD8 * temp_fs1) + (arg1->unkE8 * temp_fs0);
      spF8.unk4 = (arg1->unkDC * temp_fs1) + (arg1->unkEC * temp_fs0);
      spF8.unk8 = (arg1->unkE0 * temp_fs1) + (arg1->unkF0 * temp_fs0);
      func_800B11C4(&spF8, &spE8);

      tmp = (arg1->unk104 * temp_fs1) + (arg1->unk108 * temp_fs0);

      r = spE8.unk0 * 255.0;
      g = spE8.unk4 * 255.0;
      b = spE8.unk8 * 255.0;
      a = tmp * 255.0;

      gSPMatrix(gdl++, var_s2->unk20[sp11C], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
      gDPPipeSync(gdl++);
      gDPSetPrimColor(gdl++, 0, 0, r, g, b, a);

      gSPVertex(gdl++, arg1->unk80, 4, 0);
      gSP1Triangle(gdl++, 0, 1, 2, 0);
      gSP1Triangle(gdl++, 2, 3, 0, 0);

      gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    }
  }
  arg1->unk118 ^= 0x4;

  return gdl;
}

Gfx *func_800AD970(Gfx *gdl, UnkStruct_86 *arg1, UnkStruct_32 *arg2) {
  gSPMatrix(gdl++, &D_800D9110, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

  return func_800AD2FC(gdl, arg1, arg2);
}

Gfx *func_800AD9AC(Gfx *gdl, UnkStruct_86 *arg1, UnkStruct_32 *arg2, Mtx4 *arg3) {
  s32 i = (arg1->unk118 & 0x4) ? 1 : 0;

  guMtxF2L((f32 (*)[4]) arg3, &arg1->unk0[i]);
  gSPMatrix(gdl++, &arg1->unk0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

  return func_800AD2FC(gdl, arg1, arg2);
}

void func_800ADA34(UnkStruct_86 *arg0, f32 arg1, f32 arg2) {
  arg0->unk10C = arg1;
  arg0->unk110 = arg2;
}

void func_800ADA48(UnkStruct_86 *arg0, f32 arg1, f32 arg2) {
  arg0->unk104 = arg1;
  arg0->unk108 = arg2;
}

void func_800ADA5C(UnkStruct_86 *arg0, f32 arg1, f32 arg2) {
  arg0->unkD8 = arg1;
  arg0->unkE8 = arg2;
}

void func_800ADA70(UnkStruct_86 *arg0, f32 arg1, f32 arg2) {
  arg0->unkDC = arg1;
  arg0->unkEC = arg2;
}

void func_800ADA84(UnkStruct_86 *arg0, f32 arg1, f32 arg2) {
  arg0->unkE0 = arg1;
  arg0->unkF0 = arg2;
}

void func_800ADA98(UnkStruct_86 *arg0, s32 arg1) {
  arg0->unkD4 = arg1;
}

void func_800ADAA0(UnkStruct_86 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unkF8.x = arg1;
  arg0->unkF8.y = arg2;
  arg0->unkF8.z = arg3;
}

void func_800ADAC0(UnkStruct_86 *arg0, f32 arg1) {
  arg0->unk114 = arg1;
}
