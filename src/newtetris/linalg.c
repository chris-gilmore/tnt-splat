#include "common.h"

#pragma intrinsic(sqrtf);

extern f64 fabs(f64);
#pragma intrinsic(fabs);

void func_800AE880(Mtx4 *m1, Mtx4 *m2) {
  f32 a;
  f32 b;
  f32 c;

  a = (m1->m00 * m1->m00) + (m1->m01 * m1->m01) + (m1->m02 * m1->m02);
  b = (m1->m10 * m1->m10) + (m1->m11 * m1->m11) + (m1->m12 * m1->m12);
  c = (m1->m20 * m1->m20) + (m1->m21 * m1->m21) + (m1->m22 * m1->m22);

  a = 1.0 / a;
  b = 1.0 / b;
  c = 1.0 / c;

  m2->m00 = m1->m00 * a;
  m2->m10 = m1->m01 * a;
  m2->m20 = m1->m02 * a;

  m2->m01 = m1->m10 * b;
  m2->m11 = m1->m11 * b;
  m2->m21 = m1->m12 * b;

  m2->m02 = m1->m20 * c;
  m2->m12 = m1->m21 * c;
  m2->m22 = m1->m22 * c;

  m2->m30 = - m2->m00 * m1->m30 - m2->m10 * m1->m31 - m2->m20 * m1->m32;
  m2->m31 = - m2->m01 * m1->m30 - m2->m11 * m1->m31 - m2->m21 * m1->m32;
  m2->m32 = - m2->m02 * m1->m30 - m2->m12 * m1->m31 - m2->m22 * m1->m32;

  m2->m03 = 0;
  m2->m13 = 0;
  m2->m23 = 0;
  m2->m33 = 1;
}

f32 func_800AEA80(Mtx3 *m, s32 r, s32 c) {
  switch (r) {
  case 0:
    switch (c) {
    case 0:
      return m->m11 * m->m22 - m->m12 * m->m21;
    case 1:
      return m->m12 * m->m20 - m->m10 * m->m22;
    case 2:
      return m->m10 * m->m21 - m->m11 * m->m20;
    }
  case 1:
    switch (c) {
    case 0:
      return - m->m01 * m->m22 + m->m02 * m->m21;
    case 1:
      return - m->m02 * m->m20 + m->m00 * m->m22;
    case 2:
      return - m->m00 * m->m21 + m->m01 * m->m20;
    }
  case 2:
    switch (c) {
    case 0:
      return m->m01 * m->m12 - m->m02 * m->m11;
    case 1:
      return m->m02 * m->m10 - m->m00 * m->m12;
    case 2:
      return m->m00 * m->m11 - m->m01 * m->m10;
    }
  }
}

// determinant
f32 func_800AEC54(Mtx3 *m) {
  f32 det;

  det  = m->m00 * m->m11 * m->m22;
  det -= m->m00 * m->m12 * m->m21;
  det += m->m01 * m->m12 * m->m20;
  det -= m->m01 * m->m10 * m->m22;
  det += m->m02 * m->m10 * m->m21;
  det -= m->m02 * m->m11 * m->m20;

  return det;
}

void func_800AECFC(Mtx3 *m1, Mtx3 *m2) {
  f32 det;
  f32 a;

  det = func_800AEC54(m1);
  if (!(fabs(det) < 1e-15)) {
    a = 1.0 / det;
    m2->m00 = func_800AEA80(m1, 0, 0) * a;
    m2->m01 = func_800AEA80(m1, 1, 0) * a;
    m2->m02 = func_800AEA80(m1, 2, 0) * a;
    m2->m10 = func_800AEA80(m1, 0, 1) * a;
    m2->m11 = func_800AEA80(m1, 1, 1) * a;
    m2->m12 = func_800AEA80(m1, 2, 1) * a;
    m2->m20 = func_800AEA80(m1, 0, 2) * a;
    m2->m21 = func_800AEA80(m1, 1, 2) * a;
    m2->m22 = func_800AEA80(m1, 2, 2) * a;
  }
}

void func_800AEE4C(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->m00 = (b->m00 * c->m00) + (b->m10 * c->m01) + (b->m20 * c->m02);
  a->m10 = (b->m00 * c->m10) + (b->m10 * c->m11) + (b->m20 * c->m12);
  a->m20 = (b->m00 * c->m20) + (b->m10 * c->m21) + (b->m20 * c->m22);
  a->m30 = (b->m00 * c->m30) + (b->m10 * c->m31) + (b->m20 * c->m32) + b->m30;

  a->m01 = (b->m01 * c->m00) + (b->m11 * c->m01) + (b->m21 * c->m02);
  a->m11 = (b->m01 * c->m10) + (b->m11 * c->m11) + (b->m21 * c->m12);
  a->m21 = (b->m01 * c->m20) + (b->m11 * c->m21) + (b->m21 * c->m22);
  a->m31 = (b->m01 * c->m30) + (b->m11 * c->m31) + (b->m21 * c->m32) + b->m31;

  a->m02 = (b->m02 * c->m00) + (b->m12 * c->m01) + (b->m22 * c->m02);
  a->m12 = (b->m02 * c->m10) + (b->m12 * c->m11) + (b->m22 * c->m12);
  a->m22 = (b->m02 * c->m20) + (b->m12 * c->m21) + (b->m22 * c->m22);
  a->m32 = (b->m02 * c->m30) + (b->m12 * c->m31) + (b->m22 * c->m32) + b->m32;

  a->m03 = 0;
  a->m13 = 0;
  a->m23 = 0;
  a->m33 = 1;
}

void func_800AF0C4(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->m00 = (b->m00 * c->m00) + (b->m10 * c->m01) + (b->m20 * c->m02);
  a->m10 = (b->m00 * c->m10) + (b->m10 * c->m11) + (b->m20 * c->m12);
  a->m20 = (b->m00 * c->m20) + (b->m10 * c->m21) + (b->m20 * c->m22);
  a->m30 = (b->m00 * c->m30 * b->m03) + (b->m10 * c->m31 * b->m13) + (b->m20 * c->m32 * b->m23) + b->m30;

  a->m01 = (b->m01 * c->m00) + (b->m11 * c->m01) + (b->m21 * c->m02);
  a->m11 = (b->m01 * c->m10) + (b->m11 * c->m11) + (b->m21 * c->m12);
  a->m21 = (b->m01 * c->m20) + (b->m11 * c->m21) + (b->m21 * c->m22);
  a->m31 = (b->m01 * c->m30 * b->m03) + (b->m11 * c->m31 * b->m13) + (b->m21 * c->m32 * b->m23) + b->m31;

  a->m02 = (b->m02 * c->m00) + (b->m12 * c->m01) + (b->m22 * c->m02);
  a->m12 = (b->m02 * c->m10) + (b->m12 * c->m11) + (b->m22 * c->m12);
  a->m22 = (b->m02 * c->m20) + (b->m12 * c->m21) + (b->m22 * c->m22);
  a->m32 = (b->m02 * c->m30 * b->m03) + (b->m12 * c->m31 * b->m13) + (b->m22 * c->m32 * b->m23) + b->m32;

  a->m03 = b->m03 * c->m03;
  a->m13 = b->m13 * c->m13;
  a->m23 = b->m23 * c->m23;
  a->m33 = 1;
}

void func_800AF3A4(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->m00 = (b->m00 * c->m00) + (b->m10 * c->m01) + (b->m20 * c->m02);
  a->m10 = (b->m00 * c->m10) + (b->m10 * c->m11) + (b->m20 * c->m12);
  a->m20 = (b->m00 * c->m20) + (b->m10 * c->m21) + (b->m20 * c->m22);
  a->m01 = (b->m01 * c->m00) + (b->m11 * c->m01) + (b->m21 * c->m02);
  a->m11 = (b->m01 * c->m10) + (b->m11 * c->m11) + (b->m21 * c->m12);
  a->m21 = (b->m01 * c->m20) + (b->m11 * c->m21) + (b->m21 * c->m22);
  a->m02 = (b->m02 * c->m00) + (b->m12 * c->m01) + (b->m22 * c->m02);
  a->m12 = (b->m02 * c->m10) + (b->m12 * c->m11) + (b->m22 * c->m12);
  a->m22 = (b->m02 * c->m20) + (b->m12 * c->m21) + (b->m22 * c->m22);
}

void mtx4_mult(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->m00 = (b->m00 * c->m00) + (b->m10 * c->m01) + (b->m20 * c->m02) + (b->m30 * c->m03);
  a->m10 = (b->m00 * c->m10) + (b->m10 * c->m11) + (b->m20 * c->m12) + (b->m30 * c->m13);
  a->m20 = (b->m00 * c->m20) + (b->m10 * c->m21) + (b->m20 * c->m22) + (b->m30 * c->m23);
  a->m30 = (b->m00 * c->m30) + (b->m10 * c->m31) + (b->m20 * c->m32) + (b->m30 * c->m33);

  a->m01 = (b->m01 * c->m00) + (b->m11 * c->m01) + (b->m21 * c->m02) + (b->m31 * c->m03);
  a->m11 = (b->m01 * c->m10) + (b->m11 * c->m11) + (b->m21 * c->m12) + (b->m31 * c->m13);
  a->m21 = (b->m01 * c->m20) + (b->m11 * c->m21) + (b->m21 * c->m22) + (b->m31 * c->m23);
  a->m31 = (b->m01 * c->m30) + (b->m11 * c->m31) + (b->m21 * c->m32) + (b->m31 * c->m33);

  a->m02 = (b->m02 * c->m00) + (b->m12 * c->m01) + (b->m22 * c->m02) + (b->m32 * c->m03);
  a->m12 = (b->m02 * c->m10) + (b->m12 * c->m11) + (b->m22 * c->m12) + (b->m32 * c->m13);
  a->m22 = (b->m02 * c->m20) + (b->m12 * c->m21) + (b->m22 * c->m22) + (b->m32 * c->m23);
  a->m32 = (b->m02 * c->m30) + (b->m12 * c->m31) + (b->m22 * c->m32) + (b->m32 * c->m33);

  a->m03 = (b->m03 * c->m00) + (b->m13 * c->m01) + (b->m23 * c->m02) + (b->m33 * c->m03);
  a->m13 = (b->m03 * c->m10) + (b->m13 * c->m11) + (b->m23 * c->m12) + (b->m33 * c->m13);
  a->m23 = (b->m03 * c->m20) + (b->m13 * c->m21) + (b->m23 * c->m22) + (b->m33 * c->m23);
  a->m33 = (b->m03 * c->m30) + (b->m13 * c->m31) + (b->m23 * c->m32) + (b->m33 * c->m33);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AF95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AFB10.s")

void func_800AFBBC(Vec3 *a, Mtx4 *m, Vec3 *b) {
  a->x = (m->m00 * b->x) + (m->m10 * b->y) + (m->m20 * b->z);
  a->y = (m->m01 * b->x) + (m->m11 * b->y) + (m->m21 * b->z);
  a->z = (m->m02 * b->x) + (m->m12 * b->y) + (m->m22 * b->z);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AFC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AFD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AFE4C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800AFFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B00BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B02F0.s")

void func_800B036C(Mtx4 *m, f32 a, f32 b, f32 c) {
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

  m->m00 = (cos_a * cos_c) + (sin_a * sin_b * sin_c);
  m->m10 = (-cos_a * sin_c) + (sin_a * sin_b * cos_c);
  m->m20 = sin_a * cos_b;

  m->m01 = cos_b * sin_c;
  m->m11 = cos_b * cos_c;
  m->m21 = -sin_b;

  m->m02 = (-sin_a * cos_c) + (cos_a * sin_b * sin_c);
  m->m12 = (sin_a * sin_c) + (cos_a * sin_b * cos_c);
  m->m22 = cos_a * cos_b;
}

void func_800B04BC(Mtx4 *m, f32 a, f32 b, f32 c) {
  func_800B036C(m, a, b, c);
  m->m30 = 0;
  m->m31 = 0;
  m->m32 = 0;
  m->m03 = 0;
  m->m13 = 0;
  m->m23 = 0;
  m->m33 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B051C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B05A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B09A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linalg/func_800B0F08.s")

void func_800B0F74(Vec4 *a, Mtx4 *m, Vec4 *b) {
  a->x = (m->m00 * b->x) + (m->m10 * b->y) + (m->m20 * b->z) + (m->m30 * b->w);
  a->y = (m->m01 * b->x) + (m->m11 * b->y) + (m->m21 * b->z) + (m->m31 * b->w);
  a->z = (m->m02 * b->x) + (m->m12 * b->y) + (m->m22 * b->z) + (m->m32 * b->w);
  a->w = (m->m03 * b->x) + (m->m13 * b->y) + (m->m23 * b->z) + (m->m33 * b->w);
}

f32 vec4_dot(Vec4 *a, Vec4 *b) {
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
}
