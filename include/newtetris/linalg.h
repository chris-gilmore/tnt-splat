#ifndef _LINALG_H_
#define _LINALG_H_

// PI/180
#define DEG2RAD 0.017453293

typedef struct {
  f32 x, y, z;
} Vec3;

typedef struct {
  f32 x, y, z, w;
} Vec4;

typedef struct {
  f32 m00, m01, m02; // Row 0
  f32 m10, m11, m12; // Row 1
  f32 m20, m21, m22; // Row 2
} Mtx3;

typedef struct {
  f32 m00, m01, m02, m03; // Row 0
  f32 m10, m11, m12, m13; // Row 1
  f32 m20, m21, m22, m23; // Row 2
  f32 m30, m31, m32, m33; // Row 3
} Mtx4;

extern void   func_800AE880(Mtx4 *, Mtx4 *);
extern f32    func_800AEA80(Mtx3 *, s32, s32);
extern f32    func_800AEC54(Mtx3 *);  // determinant
extern void   func_800AECFC(Mtx3 *, Mtx3 *);
extern void   func_800AEE4C(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AF0C4(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AF3A4(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   mtx4_mult(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AFBBC(Vec3 *, Mtx4 *, Vec3 *);
extern f32    vec3_dot(Vec3 *, Vec3 *);
extern void   vec3_cross(Vec3 *, Vec3 *, Vec3 *);
extern f32    vec3_squared(Vec3 *);
extern f32    vec3_length(Vec3 *);
extern void   func_800B036C(Mtx4 *, f32, f32, f32);
extern void   func_800B04BC(Mtx4 *, f32, f32, f32);
extern void   func_800B0F74(Vec4 *, Mtx4 *, Vec4 *);
extern f32    vec4_dot(Vec4 *, Vec4 *);

#endif /* !_LINALG_H_ */
