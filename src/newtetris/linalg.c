#include "common.h"

#pragma intrinsic(sqrtf);

extern f64 fabs(f64);
#pragma intrinsic(fabs);

void func_800AE880(Mtx4 *m1, Mtx4 *m2) {
  f32 a;
  f32 b;
  f32 c;

  a = (m1->a11 * m1->a11) + (m1->a21 * m1->a21) + (m1->a31 * m1->a31);
  b = (m1->a12 * m1->a12) + (m1->a22 * m1->a22) + (m1->a32 * m1->a32);
  c = (m1->a13 * m1->a13) + (m1->a23 * m1->a23) + (m1->a33 * m1->a33);

  a = 1.0 / a;
  b = 1.0 / b;
  c = 1.0 / c;

  m2->a11 = m1->a11 * a;
  m2->a12 = m1->a21 * a;
  m2->a13 = m1->a31 * a;

  m2->a21 = m1->a12 * b;
  m2->a22 = m1->a22 * b;
  m2->a23 = m1->a32 * b;

  m2->a31 = m1->a13 * c;
  m2->a32 = m1->a23 * c;
  m2->a33 = m1->a33 * c;

  m2->a14 = - m2->a11 * m1->a14 - m2->a12 * m1->a24 - m2->a13 * m1->a34;
  m2->a24 = - m2->a21 * m1->a14 - m2->a22 * m1->a24 - m2->a23 * m1->a34;
  m2->a34 = - m2->a31 * m1->a14 - m2->a32 * m1->a24 - m2->a33 * m1->a34;

  m2->a41 = 0;
  m2->a42 = 0;
  m2->a43 = 0;
  m2->a44 = 1;
}

f32 func_800AEA80(Mtx3 *m, s32 r, s32 c) {
  switch (r) {
  case 0:
    switch (c) {
    case 0:
      return m->a22 * m->a33 - m->a23 * m->a32;
    case 1:
      return m->a23 * m->a31 - m->a21 * m->a33;
    case 2:
      return m->a21 * m->a32 - m->a22 * m->a31;
    }
    /* fallthrough */
  case 1:
    switch (c) {
    case 0:
      return - m->a12 * m->a33 + m->a13 * m->a32;
    case 1:
      return - m->a13 * m->a31 + m->a11 * m->a33;
    case 2:
      return - m->a11 * m->a32 + m->a12 * m->a31;
    }
    /* fallthrough */
  case 2:
    switch (c) {
    case 0:
      return m->a12 * m->a23 - m->a13 * m->a22;
    case 1:
      return m->a13 * m->a21 - m->a11 * m->a23;
    case 2:
      return m->a11 * m->a22 - m->a12 * m->a21;
    }
  }
}

// determinant
f32 func_800AEC54(Mtx3 *m) {
  f32 det;

  det  = m->a11 * m->a22 * m->a33;
  det -= m->a11 * m->a23 * m->a32;
  det += m->a12 * m->a23 * m->a31;
  det -= m->a12 * m->a21 * m->a33;
  det += m->a13 * m->a21 * m->a32;
  det -= m->a13 * m->a22 * m->a31;

  return det;
}

void func_800AECFC(Mtx3 *m1, Mtx3 *m2) {
  f32 det;
  f32 a;

  det = func_800AEC54(m1);
  if (!(fabs(det) < 1e-15)) {
    a = 1.0 / det;
    m2->a11 = func_800AEA80(m1, 0, 0) * a;
    m2->a12 = func_800AEA80(m1, 1, 0) * a;
    m2->a13 = func_800AEA80(m1, 2, 0) * a;
    m2->a21 = func_800AEA80(m1, 0, 1) * a;
    m2->a22 = func_800AEA80(m1, 1, 1) * a;
    m2->a23 = func_800AEA80(m1, 2, 1) * a;
    m2->a31 = func_800AEA80(m1, 0, 2) * a;
    m2->a32 = func_800AEA80(m1, 1, 2) * a;
    m2->a33 = func_800AEA80(m1, 2, 2) * a;
  }
}

void func_800AEE4C(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->a11 = (b->a11 * c->a11) + (b->a12 * c->a21) + (b->a13 * c->a31);
  a->a12 = (b->a11 * c->a12) + (b->a12 * c->a22) + (b->a13 * c->a32);
  a->a13 = (b->a11 * c->a13) + (b->a12 * c->a23) + (b->a13 * c->a33);
  a->a14 = (b->a11 * c->a14) + (b->a12 * c->a24) + (b->a13 * c->a34) + b->a14;

  a->a21 = (b->a21 * c->a11) + (b->a22 * c->a21) + (b->a23 * c->a31);
  a->a22 = (b->a21 * c->a12) + (b->a22 * c->a22) + (b->a23 * c->a32);
  a->a23 = (b->a21 * c->a13) + (b->a22 * c->a23) + (b->a23 * c->a33);
  a->a24 = (b->a21 * c->a14) + (b->a22 * c->a24) + (b->a23 * c->a34) + b->a24;

  a->a31 = (b->a31 * c->a11) + (b->a32 * c->a21) + (b->a33 * c->a31);
  a->a32 = (b->a31 * c->a12) + (b->a32 * c->a22) + (b->a33 * c->a32);
  a->a33 = (b->a31 * c->a13) + (b->a32 * c->a23) + (b->a33 * c->a33);
  a->a34 = (b->a31 * c->a14) + (b->a32 * c->a24) + (b->a33 * c->a34) + b->a34;

  a->a41 = 0;
  a->a42 = 0;
  a->a43 = 0;
  a->a44 = 1;
}

void func_800AF0C4(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->a11 = (b->a11 * c->a11) + (b->a12 * c->a21) + (b->a13 * c->a31);
  a->a12 = (b->a11 * c->a12) + (b->a12 * c->a22) + (b->a13 * c->a32);
  a->a13 = (b->a11 * c->a13) + (b->a12 * c->a23) + (b->a13 * c->a33);
  a->a14 = (b->a11 * c->a14 * b->a41) + (b->a12 * c->a24 * b->a42) + (b->a13 * c->a34 * b->a43) + b->a14;

  a->a21 = (b->a21 * c->a11) + (b->a22 * c->a21) + (b->a23 * c->a31);
  a->a22 = (b->a21 * c->a12) + (b->a22 * c->a22) + (b->a23 * c->a32);
  a->a23 = (b->a21 * c->a13) + (b->a22 * c->a23) + (b->a23 * c->a33);
  a->a24 = (b->a21 * c->a14 * b->a41) + (b->a22 * c->a24 * b->a42) + (b->a23 * c->a34 * b->a43) + b->a24;

  a->a31 = (b->a31 * c->a11) + (b->a32 * c->a21) + (b->a33 * c->a31);
  a->a32 = (b->a31 * c->a12) + (b->a32 * c->a22) + (b->a33 * c->a32);
  a->a33 = (b->a31 * c->a13) + (b->a32 * c->a23) + (b->a33 * c->a33);
  a->a34 = (b->a31 * c->a14 * b->a41) + (b->a32 * c->a24 * b->a42) + (b->a33 * c->a34 * b->a43) + b->a34;

  a->a41 = b->a41 * c->a41;
  a->a42 = b->a42 * c->a42;
  a->a43 = b->a43 * c->a43;
  a->a44 = 1;
}

void func_800AF3A4(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->a11 = (b->a11 * c->a11) + (b->a12 * c->a21) + (b->a13 * c->a31);
  a->a12 = (b->a11 * c->a12) + (b->a12 * c->a22) + (b->a13 * c->a32);
  a->a13 = (b->a11 * c->a13) + (b->a12 * c->a23) + (b->a13 * c->a33);
  a->a21 = (b->a21 * c->a11) + (b->a22 * c->a21) + (b->a23 * c->a31);
  a->a22 = (b->a21 * c->a12) + (b->a22 * c->a22) + (b->a23 * c->a32);
  a->a23 = (b->a21 * c->a13) + (b->a22 * c->a23) + (b->a23 * c->a33);
  a->a31 = (b->a31 * c->a11) + (b->a32 * c->a21) + (b->a33 * c->a31);
  a->a32 = (b->a31 * c->a12) + (b->a32 * c->a22) + (b->a33 * c->a32);
  a->a33 = (b->a31 * c->a13) + (b->a32 * c->a23) + (b->a33 * c->a33);
}

void mtx4_mult(Mtx4 *a, Mtx4 *b, Mtx4 *c) {
  a->a11 = (b->a11 * c->a11) + (b->a12 * c->a21) + (b->a13 * c->a31) + (b->a14 * c->a41);
  a->a12 = (b->a11 * c->a12) + (b->a12 * c->a22) + (b->a13 * c->a32) + (b->a14 * c->a42);
  a->a13 = (b->a11 * c->a13) + (b->a12 * c->a23) + (b->a13 * c->a33) + (b->a14 * c->a43);
  a->a14 = (b->a11 * c->a14) + (b->a12 * c->a24) + (b->a13 * c->a34) + (b->a14 * c->a44);

  a->a21 = (b->a21 * c->a11) + (b->a22 * c->a21) + (b->a23 * c->a31) + (b->a24 * c->a41);
  a->a22 = (b->a21 * c->a12) + (b->a22 * c->a22) + (b->a23 * c->a32) + (b->a24 * c->a42);
  a->a23 = (b->a21 * c->a13) + (b->a22 * c->a23) + (b->a23 * c->a33) + (b->a24 * c->a43);
  a->a24 = (b->a21 * c->a14) + (b->a22 * c->a24) + (b->a23 * c->a34) + (b->a24 * c->a44);

  a->a31 = (b->a31 * c->a11) + (b->a32 * c->a21) + (b->a33 * c->a31) + (b->a34 * c->a41);
  a->a32 = (b->a31 * c->a12) + (b->a32 * c->a22) + (b->a33 * c->a32) + (b->a34 * c->a42);
  a->a33 = (b->a31 * c->a13) + (b->a32 * c->a23) + (b->a33 * c->a33) + (b->a34 * c->a43);
  a->a34 = (b->a31 * c->a14) + (b->a32 * c->a24) + (b->a33 * c->a34) + (b->a34 * c->a44);

  a->a41 = (b->a41 * c->a11) + (b->a42 * c->a21) + (b->a43 * c->a31) + (b->a44 * c->a41);
  a->a42 = (b->a41 * c->a12) + (b->a42 * c->a22) + (b->a43 * c->a32) + (b->a44 * c->a42);
  a->a43 = (b->a41 * c->a13) + (b->a42 * c->a23) + (b->a43 * c->a33) + (b->a44 * c->a43);
  a->a44 = (b->a41 * c->a14) + (b->a42 * c->a24) + (b->a43 * c->a34) + (b->a44 * c->a44);
}

void func_800AF95C(Mtx3 *m1, Mtx4 *m2, Mtx3 *m3) {
  m1->a11 = (m2->a11 * m3->a11) + (m2->a12 * m3->a21) + (m2->a13 * m3->a31);
  m1->a12 = (m2->a11 * m3->a12) + (m2->a12 * m3->a22) + (m2->a13 * m3->a32);
  m1->a13 = (m2->a11 * m3->a13) + (m2->a12 * m3->a23) + (m2->a13 * m3->a33);
  m1->a21 = (m2->a21 * m3->a11) + (m2->a22 * m3->a21) + (m2->a23 * m3->a31);
  m1->a22 = (m2->a21 * m3->a12) + (m2->a22 * m3->a22) + (m2->a23 * m3->a32);
  m1->a23 = (m2->a21 * m3->a13) + (m2->a22 * m3->a23) + (m2->a23 * m3->a33);
  m1->a31 = (m2->a31 * m3->a11) + (m2->a32 * m3->a21) + (m2->a33 * m3->a31);
  m1->a32 = (m2->a31 * m3->a12) + (m2->a32 * m3->a22) + (m2->a33 * m3->a32);
  m1->a33 = (m2->a31 * m3->a13) + (m2->a32 * m3->a23) + (m2->a33 * m3->a33);
}

void func_800AFB10(Vec3 *a, Mtx4 *m, Vec3 *b) {
  a->x = (m->a11 * b->x) + (m->a12 * b->y) + (m->a13 * b->z) + m->a14;
  a->y = (m->a21 * b->x) + (m->a22 * b->y) + (m->a23 * b->z) + m->a24;
  a->z = (m->a31 * b->x) + (m->a32 * b->y) + (m->a33 * b->z) + m->a34;
}

void func_800AFBBC(Vec3 *a, Mtx4 *m, Vec3 *b) {
  a->x = (m->a11 * b->x) + (m->a12 * b->y) + (m->a13 * b->z);
  a->y = (m->a21 * b->x) + (m->a22 * b->y) + (m->a23 * b->z);
  a->z = (m->a31 * b->x) + (m->a32 * b->y) + (m->a33 * b->z);
}

void func_800AFC50(Mtx3 *m, const char *str) {
  rmonPrintf("%s\n", str);
  rmonPrintf("a11:%15.8f a12:%15.8f a13:%15.8f\n", m->a11, m->a12, m->a13);
  rmonPrintf("a21:%15.8f a22:%15.8f a23:%15.8f\n", m->a21, m->a22, m->a23);
  rmonPrintf("a31:%15.8f a32:%15.8f a33:%15.8f\n", m->a31, m->a32, m->a33);
}

void func_800AFD1C(Mtx4 *m, const char *str) {
  rmonPrintf("%s\n", str);
  rmonPrintf("a11:%9.3f a12:%9.3f a13:%9.3f a14:%9.3f\n", m->a11, m->a12, m->a13, m->a14);
  rmonPrintf("a21:%9.3f a22:%9.3f a23:%9.3f a24:%9.3f\n", m->a21, m->a22, m->a23, m->a24);
  rmonPrintf("a31:%9.3f a32:%9.3f a33:%9.3f a34:%9.3f\n", m->a31, m->a32, m->a33, m->a34);
  rmonPrintf("a41:%9.3f a42:%9.3f a43:%9.3f a44:%9.3f\n", m->a41, m->a42, m->a43, m->a44);
}

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

f32 func_800AFFF0(Vec3 *a, Vec3 *b, Vec3 *c) {
  c->x = b->x - a->x;
  c->y = b->y - a->y;
  c->z = b->z - a->z;

  return vec3_length(c);
}

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

  m->a11 = (cos_a * cos_c) + (sin_a * sin_b * sin_c);
  m->a12 = (-cos_a * sin_c) + (sin_a * sin_b * cos_c);
  m->a13 = sin_a * cos_b;

  m->a21 = cos_b * sin_c;
  m->a22 = cos_b * cos_c;
  m->a23 = -sin_b;

  m->a31 = (-sin_a * cos_c) + (cos_a * sin_b * sin_c);
  m->a32 = (sin_a * sin_c) + (cos_a * sin_b * cos_c);
  m->a33 = cos_a * cos_b;
}

void func_800B04BC(Mtx4 *m, f32 a, f32 b, f32 c) {
  func_800B036C(m, a, b, c);
  m->a14 = 0;
  m->a24 = 0;
  m->a34 = 0;
  m->a41 = 0;
  m->a42 = 0;
  m->a43 = 0;
  m->a44 = 1;
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
  a->x = (m->a11 * b->x) + (m->a12 * b->y) + (m->a13 * b->z) + (m->a14 * b->w);
  a->y = (m->a21 * b->x) + (m->a22 * b->y) + (m->a23 * b->z) + (m->a24 * b->w);
  a->z = (m->a31 * b->x) + (m->a32 * b->y) + (m->a33 * b->z) + (m->a34 * b->w);
  a->w = (m->a41 * b->x) + (m->a42 * b->y) + (m->a43 * b->z) + (m->a44 * b->w);
}

f32 vec4_dot(Vec4 *a, Vec4 *b) {
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
}
