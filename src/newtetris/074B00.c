#include "common.h"

#pragma intrinsic(sqrtf);

void func_800AE880(MtxF *m1, MtxF *m2) {
  f32 a;
  f32 b;
  f32 c;

  a = (m1->mf[0][2] * m1->mf[0][2]) + ((m1->mf[0][1] * m1->mf[0][1]) + (m1->mf[0][0] * m1->mf[0][0]));
  b = (m1->mf[1][2] * m1->mf[1][2]) + ((m1->mf[1][1] * m1->mf[1][1]) + (m1->mf[1][0] * m1->mf[1][0]));
  c = (m1->mf[2][2] * m1->mf[2][2]) + ((m1->mf[2][1] * m1->mf[2][1]) + (m1->mf[2][0] * m1->mf[2][0]));

  a = 1.0 / a;
  b = 1.0 / b;
  c = 1.0 / c;

  m2->mf[0][0] = m1->mf[0][0] * a;
  m2->mf[1][0] = m1->mf[0][1] * a;
  m2->mf[2][0] = m1->mf[0][2] * a;

  m2->mf[0][1] = m1->mf[1][0] * b;
  m2->mf[1][1] = m1->mf[1][1] * b;
  m2->mf[2][1] = m1->mf[1][2] * b;

  m2->mf[0][2] = m1->mf[2][0] * c;
  m2->mf[1][2] = m1->mf[2][1] * c;
  m2->mf[2][2] = m1->mf[2][2] * c;

  m2->mf[3][0] = (-m2->mf[0][0] * m1->mf[3][0]) - (m2->mf[1][0] * m1->mf[3][1]) - (m1->mf[3][2] * m2->mf[2][0]);
  m2->mf[3][1] = (-m2->mf[0][1] * m1->mf[3][0]) - (m2->mf[1][1] * m1->mf[3][1]) - (m1->mf[3][2] * m2->mf[2][1]);
  m2->mf[3][2] = (-m2->mf[0][2] * m1->mf[3][0]) - (m2->mf[1][2] * m1->mf[3][1]) - (m1->mf[3][2] * m2->mf[2][2]);

  m2->mf[0][3] = 0;
  m2->mf[1][3] = 0;
  m2->mf[2][3] = 0;
  m2->mf[3][3] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AEA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AEC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AECFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AEE4C.s")

void func_800AF0C4(MtxF *a, MtxF *b, MtxF *c) {
  a->mf[0][0] = (b->mf[2][0] * c->mf[0][2]) + ((b->mf[1][0] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][0]));
  a->mf[1][0] = (b->mf[2][0] * c->mf[1][2]) + ((b->mf[1][0] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][0]));
  a->mf[2][0] = (b->mf[2][0] * c->mf[2][2]) + ((b->mf[1][0] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][0]));
  a->mf[3][0] = b->mf[3][0] + ((b->mf[2][0] * c->mf[3][2] * b->mf[2][3]) + ((b->mf[1][0] * c->mf[3][1] * b->mf[1][3]) + (b->mf[0][3] * (c->mf[3][0] * b->mf[0][0]))));

  a->mf[0][1] = (b->mf[2][1] * c->mf[0][2]) + ((b->mf[1][1] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][1]));
  a->mf[1][1] = (b->mf[2][1] * c->mf[1][2]) + ((b->mf[1][1] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][1]));
  a->mf[2][1] = (b->mf[2][1] * c->mf[2][2]) + ((b->mf[1][1] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][1]));
  a->mf[3][1] = b->mf[3][1] + ((b->mf[2][1] * c->mf[3][2] * b->mf[2][3]) + ((b->mf[1][1] * c->mf[3][1] * b->mf[1][3]) + (b->mf[0][3] * (c->mf[3][0] * b->mf[0][1]))));

  a->mf[0][2] = (b->mf[2][2] * c->mf[0][2]) + ((b->mf[1][2] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][2]));
  a->mf[1][2] = (b->mf[2][2] * c->mf[1][2]) + ((b->mf[1][2] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][2]));
  a->mf[2][2] = (b->mf[2][2] * c->mf[2][2]) + ((b->mf[1][2] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][2]));
  a->mf[3][2] = b->mf[3][2] + ((b->mf[2][2] * c->mf[3][2] * b->mf[2][3]) + ((b->mf[1][2] * c->mf[3][1] * b->mf[1][3]) + (b->mf[0][3] * (c->mf[3][0] * b->mf[0][2]))));

  a->mf[0][3] = c->mf[0][3] * b->mf[0][3];
  a->mf[1][3] = c->mf[1][3] * b->mf[1][3];
  a->mf[2][3] = c->mf[2][3] * b->mf[2][3];
  a->mf[3][3] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AF3A4.s")

void mtx4_mult(MtxF *a, MtxF *b, MtxF *c) {
  a->mf[0][0] = (b->mf[3][0] * c->mf[0][3]) + ((b->mf[2][0] * c->mf[0][2]) + ((b->mf[1][0] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][0])));
  a->mf[1][0] = (b->mf[3][0] * c->mf[1][3]) + ((b->mf[2][0] * c->mf[1][2]) + ((b->mf[1][0] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][0])));
  a->mf[2][0] = (b->mf[3][0] * c->mf[2][3]) + ((b->mf[2][0] * c->mf[2][2]) + ((b->mf[1][0] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][0])));
  a->mf[3][0] = (b->mf[3][0] * c->mf[3][3]) + ((b->mf[2][0] * c->mf[3][2]) + ((b->mf[1][0] * c->mf[3][1]) + (c->mf[3][0] * b->mf[0][0])));

  a->mf[0][1] = (b->mf[3][1] * c->mf[0][3]) + ((b->mf[2][1] * c->mf[0][2]) + ((b->mf[1][1] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][1])));
  a->mf[1][1] = (b->mf[3][1] * c->mf[1][3]) + ((b->mf[2][1] * c->mf[1][2]) + ((b->mf[1][1] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][1])));
  a->mf[2][1] = (b->mf[3][1] * c->mf[2][3]) + ((b->mf[2][1] * c->mf[2][2]) + ((b->mf[1][1] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][1])));
  a->mf[3][1] = (b->mf[3][1] * c->mf[3][3]) + ((b->mf[2][1] * c->mf[3][2]) + ((b->mf[1][1] * c->mf[3][1]) + (c->mf[3][0] * b->mf[0][1])));

  a->mf[0][2] = (b->mf[3][2] * c->mf[0][3]) + ((b->mf[2][2] * c->mf[0][2]) + ((b->mf[1][2] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][2])));
  a->mf[1][2] = (b->mf[3][2] * c->mf[1][3]) + ((b->mf[2][2] * c->mf[1][2]) + ((b->mf[1][2] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][2])));
  a->mf[2][2] = (b->mf[3][2] * c->mf[2][3]) + ((b->mf[2][2] * c->mf[2][2]) + ((b->mf[1][2] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][2])));
  a->mf[3][2] = (b->mf[3][2] * c->mf[3][3]) + ((b->mf[2][2] * c->mf[3][2]) + ((b->mf[1][2] * c->mf[3][1]) + (c->mf[3][0] * b->mf[0][2])));

  a->mf[0][3] = (b->mf[3][3] * c->mf[0][3]) + ((b->mf[2][3] * c->mf[0][2]) + ((b->mf[1][3] * c->mf[0][1]) + (c->mf[0][0] * b->mf[0][3])));
  a->mf[1][3] = (b->mf[3][3] * c->mf[1][3]) + ((b->mf[2][3] * c->mf[1][2]) + ((b->mf[1][3] * c->mf[1][1]) + (c->mf[1][0] * b->mf[0][3])));
  a->mf[2][3] = (b->mf[3][3] * c->mf[2][3]) + ((b->mf[2][3] * c->mf[2][2]) + ((b->mf[1][3] * c->mf[2][1]) + (c->mf[2][0] * b->mf[0][3])));
  a->mf[3][3] = (b->mf[3][3] * c->mf[3][3]) + ((b->mf[2][3] * c->mf[3][2]) + ((b->mf[1][3] * c->mf[3][1]) + (c->mf[3][0] * b->mf[0][3])));
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AF95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFE4C.s")

f32 vec3_dot(Vec3 *a, Vec3 *b) {
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

void vec3_cross(Vec3 *a, Vec3 *b, Vec3 *c) {
  a->x = (b->y * c->z) - (c->y * b->z);
  a->y = (b->z * c->x) - (c->z * b->x);
  a->z = (b->x * c->y) - (c->x * b->y);
}

f32 vec3_squared(Vec3 *a) {
  return (a->x * a->x) + (a->y * a->y) + (a->z * a->z);
}

f32 vec3_length(Vec3 *a) {
  return sqrtf(vec3_squared(a));
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800AFFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B00BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B02F0.s")

void func_800B036C(MtxF *m, f32 a, f32 b, f32 c) {
  f32 cos_b;
  f32 sin_a;
  f32 cos_a;
  f32 sin_b;
  f32 cos_c;
  f32 sin_c;

  a *= DEG2RAD;
  b *= DEG2RAD;
  c *= DEG2RAD;

  cos_a = cosf(a);
  cos_b = cosf(b);
  cos_c = cosf(c);

  sin_a = sinf(a);
  sin_b = sinf(b);
  sin_c = sinf(c);

  m->mf[0][0] = (cos_a * cos_c) + (sin_a * sin_b * sin_c);
  m->mf[1][0] = (-cos_a * sin_c) + (sin_a * sin_b * cos_c);
  m->mf[2][0] = sin_a * cos_b;

  m->mf[0][1] = cos_b * sin_c;
  m->mf[1][1] = cos_b * cos_c;
  m->mf[2][1] = -sin_b;

  m->mf[0][2] = (-sin_a * cos_c) + (cos_a * sin_b * sin_c);
  m->mf[1][2] = (sin_a * sin_c) + (cos_a * sin_b * cos_c);
  m->mf[2][2] = cos_a * cos_b;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B04BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B051C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B05A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B09A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0F08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B0F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/074B00/func_800B1078.s")
