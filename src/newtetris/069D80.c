#include "common.h"

// static
Vec3 D_800D61F0 = { 1, 0, 0 };

void func_800A3B00(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  arg0->unkC.m30 = arg1;
  arg0->unkC.m31 = arg2;
  arg0->unkC.m32 = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3B58.s")

void func_800A3BF8(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  func_800B036C(&arg0->unkC, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A3FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A40A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A40B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A40C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A40D8.s")

void func_800A40FC(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
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

  arg0->unk4C.m00 = sp38.x;
  arg0->unk4C.m01 = sp38.y;
  arg0->unk4C.m02 = sp38.z;

  arg0->unk4C.m10 = sp2C.x;
  arg0->unk4C.m11 = sp2C.y;
  arg0->unk4C.m12 = sp2C.z;

  arg0->unk4C.m20 = sp44.x;
  arg0->unk4C.m21 = sp44.y;
  arg0->unk4C.m22 = sp44.z;

  arg0->unk4C.m30 = arg1;
  arg0->unk4C.m31 = arg2;
  arg0->unk4C.m32 = arg3;

  arg0->unk4C.m03 = 0;
  arg0->unk4C.m13 = 0;
  arg0->unk4C.m23 = 0;
  arg0->unk4C.m33 = 1;
}

void func_800A4304(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
  func_800A40FC(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0, 1, 0);
}

void func_800A4364(UnkStruct_32 *arg0, f32 fovy) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk4 = fovy;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4384.s")

void func_800A43B0(UnkStruct_32 *arg0, f32 near, f32 far) {
  if (arg0->unk8->unk10.unk24 != NULL) {
    arg0->unk8->unk10.unk24->unk10.unk8 = near;
    arg0->unk8->unk10.unk24->unk10.unkC = far;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A43E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A440C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A44A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A44C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4570.s")

void func_800A4590(UnkStruct_32 *arg0) {
  arg0->unk0 |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A45A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A45B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A45C4.s")

void func_800A45D8(UnkStruct_32 *arg0) {
  arg0->unk0 |= 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A45E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A45FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A460C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A468C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4698.s")
/*
void func_800A4698(UnkStruct_32 *arg0) {
  arg0->unk6 = 1;
  arg0->unk5 = 0;
  func_800A6DD8(arg0);
}
*/

void func_800A46C0(UnkStruct_32 *arg0, s32 arg1) {
  arg0->unk5 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A46C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A46DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A484C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A48CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A492C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A49B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069D80/func_800A4B68.s")
