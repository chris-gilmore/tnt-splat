#include "common.h"

static void func_800A40FC(UnkStruct_32 *, f32, f32, f32, f32, f32, f32, f32, f32, f32);

void func_800A3B00(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unkC.a14 = arg1;
  arg0->unkC.a24 = arg2;
  arg0->unkC.a34 = arg3;
}

// unused
void func_800A3B20(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unkC.a14 += arg1;
  arg0->unkC.a24 += arg2;
  arg0->unkC.a34 += arg3;
}

// unused
void func_800A3B58(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unkC.a14 += (arg0->unkC.a11 * arg1) + (arg0->unkC.a12 * arg2) + (arg0->unkC.a13 * arg3);
  arg0->unkC.a24 += (arg0->unkC.a21 * arg1) + (arg0->unkC.a22 * arg2) + (arg0->unkC.a23 * arg3);
  arg0->unkC.a34 += (arg0->unkC.a31 * arg1) + (arg0->unkC.a32 * arg2) + (arg0->unkC.a33 * arg3);
}

void func_800A3BF8(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  func_800B036C(&arg0->unkC, arg1, arg2, arg3);
}

// unused
void func_800A3C30(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  Mtx4 sp60;
  Mtx4 sp20;

  func_800B04BC(&sp60, arg1, arg2, arg3);
  sp20 = arg0->unkC;
  mtx4_mult(&arg0->unkC, &sp60, &sp20);
}

// unused
void func_800A3CB4(UnkStruct_32 *arg0, Vec3 *arg1, f32 arg2) {
  func_800B0140(&arg0->unkC, arg1, arg2);
}

// unused
void func_800A3CDC(UnkStruct_32 *arg0, Vec3 *arg1, f32 arg2) {
  Mtx4 sp60;
  Mtx4 sp20;

  func_800B0140(&sp60, arg1, arg2);
  sp20 = arg0->unkC;
  func_800AF3A4(&arg0->unkC, &sp60, &sp20);
}

// unused
void func_800A3D54(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  guNormalize(&arg0->unkC.a11, &arg0->unkC.a21, &arg0->unkC.a31);
  guNormalize(&arg0->unkC.a12, &arg0->unkC.a22, &arg0->unkC.a32);
  guNormalize(&arg0->unkC.a13, &arg0->unkC.a23, &arg0->unkC.a33);
  func_800B051C(&arg0->unkC, arg1, arg2, arg3);
}

// unused
void func_800A3DD4(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  func_800B051C(&arg0->unkC, arg1, arg2, arg3);
}

// unused
void func_800A3E0C(UnkStruct_32 *arg0, f32 x, f32 y, f32 z, f32 a) {
  s32 unused;
  Mtx4 m;

  guAlignF((f32 (*)[4]) &m, a, x, y, z);
  arg0->unkC.a11 = m.a11;
  arg0->unkC.a12 = m.a12;
  arg0->unkC.a13 = m.a13;
  arg0->unkC.a21 = m.a21;
  arg0->unkC.a22 = m.a22;
  arg0->unkC.a23 = m.a23;
  arg0->unkC.a31 = m.a31;
  arg0->unkC.a32 = m.a32;
  arg0->unkC.a33 = m.a33;
}

// unused
void func_800A3EA0(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unk4C.a14 = arg1;
  arg0->unk4C.a24 = arg2;
  arg0->unk4C.a34 = arg3;
}

// unused
void func_800A3EC0(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unk4C.a14 += arg1;
  arg0->unk4C.a24 += arg2;
  arg0->unk4C.a34 += arg3;
}

// unused
void func_800A3EF8(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unk4C.a14 += (arg0->unk4C.a11 * arg1) + (arg0->unk4C.a12 * arg2) + (arg0->unk4C.a13 * arg3);
  arg0->unk4C.a24 += (arg0->unk4C.a21 * arg1) + (arg0->unk4C.a22 * arg2) + (arg0->unk4C.a23 * arg3);
  arg0->unk4C.a34 += (arg0->unk4C.a31 * arg1) + (arg0->unk4C.a32 * arg2) + (arg0->unk4C.a33 * arg3);
}

// unused
void func_800A3F98(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  func_800B036C(&arg0->unk4C, arg1, arg2, arg3);
}

// unused
void func_800A3FD0(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  Mtx4 sp60;
  Mtx4 sp20;

  func_800B04BC(&sp60, arg1, arg2, arg3);
  sp20 = arg0->unk4C;
  mtx4_mult(&arg0->unk4C, &sp60, &sp20);
}

// unused
void func_800A4054(UnkStruct_32 *arg0, Mtx4 *arg1) {
  arg0->unk4C = *arg1;
}

// unused
void func_800A4090(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x40;
}

// unused
void func_800A40A0(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x40;
}

// unused
void func_800A40B4(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x80;
}

// unused
void func_800A40C4(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x80;
}

// unused
UnkStruct_49 *func_800A40D8(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return NULL;
  } else {
    return arg0->unk8->unk10.unk18;
  }
}

static void func_800A40FC(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
  static Vec3 D_800D61F0 = { 1, 0, 0 };

  Vec3 sp44;
  Vec3 sp38;
  Vec3 sp2C;
  f32 norm;

  sp44.x = arg1 - arg4;
  sp44.y = arg2 - arg5;
  sp44.z = arg3 - arg6;

  guNormalize(&sp44.x, &sp44.y, &sp44.z);

  sp38.x = (arg8 * sp44.z) - (arg9 * sp44.y);
  sp38.y = (arg9 * sp44.x) - (arg7 * sp44.z);
  sp38.z = (arg7 * sp44.y) - (arg8 * sp44.x);

  norm = sqrtf((sp38.x * sp38.x) + (sp38.y * sp38.y) + (sp38.z * sp38.z));
  if (norm < 0.000001) {
    sp38 = D_800D61F0;
  } else {
    norm = 1.0 / norm;
    sp38.x *= norm;
    sp38.y *= norm;
    sp38.z *= norm;
    D_800D61F0 = sp38;
  }

  vec3_cross(&sp2C, &sp44, &sp38);

  arg0->unk4C.a11 = sp38.x;
  arg0->unk4C.a21 = sp38.y;
  arg0->unk4C.a31 = sp38.z;

  arg0->unk4C.a12 = sp2C.x;
  arg0->unk4C.a22 = sp2C.y;
  arg0->unk4C.a32 = sp2C.z;

  arg0->unk4C.a13 = sp44.x;
  arg0->unk4C.a23 = sp44.y;
  arg0->unk4C.a33 = sp44.z;

  arg0->unk4C.a14 = arg1;
  arg0->unk4C.a24 = arg2;
  arg0->unk4C.a34 = arg3;

  arg0->unk4C.a41 = 0;
  arg0->unk4C.a42 = 0;
  arg0->unk4C.a43 = 0;
  arg0->unk4C.a44 = 1;
}

void func_800A4304(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
  func_800A40FC(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0, 1, 0);
}

// set fovy
void func_800A4364(UnkStruct_32 *arg0, f32 fovy) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk4 = fovy;
  }
}

// get fovy
// unused
f32 func_800A4384(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return 75;
  } else {
    return arg0->unk8->unk10.unk24->unk10.unk4;
  }
}

// set near and far
void func_800A43B0(UnkStruct_32 *arg0, f32 near, f32 far) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk8 = near;
    arg0->unk8->unk10.unk24->unk10.unkC = far;
  }
}

// get far
// unused
f32 func_800A43E0(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return 16000;
  } else {
    return arg0->unk8->unk10.unk24->unk10.unkC;
  }
}

// get near
// unused
f32 func_800A440C(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return 16;
  } else {
    return arg0->unk8->unk10.unk24->unk10.unk8;
  }
}

// unused
void func_800A4438(UnkStruct_32 *arg0, f32 arg1) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk0 = arg1;
  }
}

// unused
f32 func_800A4458(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return 0;
  } else {
    return arg0->unk8->unk10.unk24->unk10.unk0;
  }
}

// set aspect
// unused
void func_800A4480(UnkStruct_32 *arg0, f32 arg1) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk14 = arg1;
  }
}

// get aspect
// unused
f32 func_800A44A0(UnkStruct_32 *arg0) {
  if (arg0->unk8->unk10.unk24 == NULL) {
    return 1.3;
  } else {
    return arg0->unk8->unk10.unk24->unk10.unk14;
  }
}

// set viewport
// unused
void func_800A44C8(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
  Vp *vp;

  if (arg0->unk8->unk10.unk24 != NULL) {
    vp = arg0->unk8->unk10.unk24->unk10.unk18;
    vp->vp.vtrans[0] = 2.0 * (arg1 + arg3);
    vp->vp.vtrans[1] = 2.0 * (arg2 + arg4);
    vp->vp.vscale[0] = 2.0 * (arg3 - arg1);
    vp->vp.vscale[1] = 2.0 * (arg4 - arg2);
  }
}

// unused
void func_800A4570(UnkStruct_32 *arg0, f32 arg1) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk10 = arg1;
  }
}

void func_800A4590(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x4;
}

// unused
void func_800A45A0(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x4;
}

// unused
void func_800A45B4(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x8;
}

// unused
void func_800A45C4(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x8;
}

void func_800A45D8(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x10;
}

// unused
void func_800A45E8(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x10;
}

// unused
void func_800A45FC(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x20;
}

// unused
void func_800A460C(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x20;
}

void func_800A4620(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x40;
}

void func_800A4630(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x40;
}

void func_800A4644(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x80;
}

void func_800A4654(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x80;
}

// unused
void func_800A4668(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x200;
}

// unused
void func_800A4678(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x200;
}

// unused
void func_800A468C(UnkStruct_32 *arg0, s32 arg1) {
  arg0->unk4 = arg1 & 1;
}

void func_800A4698(UnkStruct_32 *arg0) {
  arg0->unk6 = 1;
  arg0->unk5 = 0;
  func_800A6DD8(arg0);
}

void func_800A46C0(UnkStruct_32 *arg0, s32 arg1) {
  arg0->unk5 = arg1;
}

// unused
UnkStruct_49 *func_800A46C8(UnkStruct_32 *arg0, s32 arg1) {
  return &arg0->unk8->unk10.unk18[arg1];
}

// unused
void func_800A46DC(UnkStruct_32 *arg0, Vec3 *arg1, s32 arg2) {
  UnkStruct_49 *tmp;

  tmp = &arg0->unk8->unk10.unk18[arg2];
  arg1->x = tmp->unkC->unkC0.a14;
  arg1->y = tmp->unkC->unkC0.a24;
  arg1->z = tmp->unkC->unkC0.a34;
}

// unused
void func_800A4714(UnkStruct_32 *arg0, Vec3 *arg1, s32 arg2) {
  UnkStruct_49 *tmp;

  tmp = &arg0->unk8->unk10.unk18[arg2];
  tmp->unk10[3] = arg1->x;
  tmp->unk10[4] = arg1->y;
  tmp->unk10[5] = arg1->z;
}

// unused
void func_800A4740(UnkStruct_49 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
  f32 *var_a0;
  f32 *var_t0;
  f32 *var_v0;
  f32 temp_fv0;
  s16 var_t2;
  s32 var_t3;
  UnkStruct_52 *var_t1;
  UnkStruct_51 *var_v1;

  arg1[0] = 0;
  arg1[1] = 0;
  arg1[2] = 0;

  arg2[0] = 0;
  arg2[1] = 0;
  arg2[2] = 0;

  arg3[0] = 0;
  arg3[1] = 0;
  arg3[2] = 0;

  if (arg0->unk8 == NULL) {
    return;
  }

  for (var_v1 = arg0->unk8; var_v1 != NULL; var_v1 = var_v1->unk4) {
    var_v0 = arg1;
    var_a0 = arg2;
    var_t0 = arg3;

    var_t1 = var_v1->unk1C;
    var_t2 = var_v1->unk14;
    temp_fv0 = var_v1->unk20->unk18;

    for (var_t3 = 3; var_t3 != 0; var_t3--) {
      if (var_t2 & 1) {
        var_t1++;
      }
      var_t2 >>= 1;
    }

    for (var_t3 = 3; var_t3 != 0; var_t3--) {
      if (var_t2 & 1) {
        *var_v0 += var_t1->unk10[0] * temp_fv0;
        *var_a0 += var_t1->unk10[1] * temp_fv0;
        *var_t0 += var_t1->unk10[2] * temp_fv0;
        var_t1++;
      }
      var_t2 >>= 1;

      var_v0++;
      var_a0++;
      var_t0++;
    }
  }
}

// unused
void func_800A484C(UnkStruct_32 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
  UnkStruct_49 *tmp;
  s32 var_a0;
  UnkStruct_52 *var_a2;

  tmp = &arg0->unk8->unk10.unk18[arg2];

  if (tmp->unk8 == NULL) {
    *arg1 = 0;
    return;
  }

  if ((tmp->unk8->unk14 & arg3) == 0) {
    *arg1 = 0;
    return;
  }

  var_a0 = tmp->unk8->unk14;
  var_a2 = tmp->unk8->unk1C;
  while (arg3 != 0) {
    if (arg3 & 0x1) {
      *arg1 = var_a2->unk6;
      return;
    }

    arg3 >>= 1;

    if (var_a0 & 0x1) {
      var_a2++;
    }

    var_a0 >>= 1;
  }
}

// unused
void func_800A48CC(UnkStruct_32 *arg0, s32 arg1, f32 arg2) {
  UnkStruct_48 *temp_v0;

  if (arg1 < 0) {
    return;
  }

  temp_v0 = arg0->unk8;
  if (arg1 < temp_v0->unk10.unk8) {
    temp_v0->unk10.unk2C[arg1]->unk10.unk0 = arg2;
  }
}

// unused
void func_800A4908(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x100;
}

// unused
void func_800A4918(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x100;
}

// unused
void func_800A492C(UnkStruct_32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
  if (arg1 < 0)    { arg1 = 0; }
  if (arg1 > 0xFF) { arg1 = 0xFF; }
  if (arg2 < 0)    { arg2 = 0; }
  if (arg2 > 0xFF) { arg2 = 0xFF; }
  if (arg3 < 0)    { arg3 = 0; }
  if (arg3 > 0xFF) { arg3 = 0xFF; }
  if (arg4 < 0)    { arg4 = 0; }
  if (arg4 > 0xFF) { arg4 = 0xFF; }

  arg0->unk1D4 = arg1;
  arg0->unk1D5 = arg2;
  arg0->unk1D6 = arg3;
  arg0->unk1D7 = arg4;
}

// unused
void func_800A49B0(UnkStruct_32 *arg0, s32 arg1, s32 arg2) {
  if (arg1 < 0)    { arg1 = 0; }
  if (arg1 > 1000) { arg1 = 1000; }
  if (arg2 < 0)    { arg2 = 0; }
  if (arg2 > 1000) { arg2 = 1000; }

  if (arg1 == arg2) {
    arg1--;
    if (arg1 < 0) {
      arg1++;
      arg2++;
    }
  }

  arg0->unk1D8 = arg1;
  arg0->unk1DC = arg2;
  arg0->unk1E0 = 256 * (1000 / 2) / (arg2 - arg1);
  arg0->unk1E4 = 256 * ((1000 / 2) - arg1) / (arg2 - arg1);
}

// unused
void func_800A4A88(UnkStruct_32 *arg0, s32 arg1, s32 arg2, Vec4 *arg3) {
  UnkStruct_62 *temp_v0;

  temp_v0 = &arg0->unk8->unk10.unk2C[arg1]->unk10.unk1C[arg2];
  temp_v0->unk4 = arg3->x;
  temp_v0->unk8 = arg3->y;
  temp_v0->unkC = arg3->z;
  if (arg3->w == 0.0) {
    temp_v0->unk10 = 1.0;
  } else {
    temp_v0->unk10 = 1.0 - arg3->w;
  }
}

// unused
void func_800A4B58(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x4000;
}

// unused
void func_800A4B68(UnkStruct_32 *arg0) {
  arg0->unk0 &= ~0x4000;
}
