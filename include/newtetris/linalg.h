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
  f32 a11, a12, a13; // Row 1
  f32 a21, a22, a23; // Row 2
  f32 a31, a32, a33; // Row 3
} Mtx3;

typedef struct {
  f32 a11, a21, a31, a41; // Col 1
  f32 a12, a22, a32, a42; // Col 2
  f32 a13, a23, a33, a43; // Col 3
  f32 a14, a24, a34, a44; // Col 4
} Mtx4;

extern void   func_800AE880(Mtx4 *, Mtx4 *);
extern f32    func_800AEA80(Mtx3 *, s32, s32);
extern f32    func_800AEC54(Mtx3 *);  // determinant
extern void   func_800AECFC(Mtx3 *, Mtx3 *);
extern void   func_800AEE4C(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AF0C4(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AF3A4(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   mtx4_mult(Mtx4 *, Mtx4 *, Mtx4 *);
extern void   func_800AF95C(Mtx3 *, Mtx4 *, Mtx3 *);
extern void   func_800AFB10(Vec3 *, Mtx4 *, Vec3 *);
extern void   func_800AFBBC(Vec3 *, Mtx4 *, Vec3 *);
extern void   func_800AFC50(Mtx3 *, const char *);
extern void   func_800AFD1C(Mtx4 *, const char *);
extern void   func_800AFE4C(Mtx4 *, Mtx *);
extern f32    vec3_dot(Vec3 *, Vec3 *);
extern void   vec3_cross(Vec3 *, Vec3 *, Vec3 *);
extern f32    vec3_squared(Vec3 *);
extern f32    vec3_length(Vec3 *);
extern f32    func_800AFFF0(Vec3 *, Vec3 *, Vec3 *);
extern f32    vec3_normalize(Vec3 *);
extern f32    func_800B00BC(Vec3 *);
extern void   func_800B0140(Mtx4 *, Vec3 *, f32);
extern void   func_800B02F0(Mtx4 *, Vec3 *);
extern void   func_800B036C(Mtx4 *, f32, f32, f32);
extern void   func_800B04BC(Mtx4 *, f32, f32, f32);
extern void   func_800B051C(Mtx4 *, f32, f32, f32);
extern void   func_800B05A4(Mtx4 *);
extern void   func_800B0700(Mtx4 *, Vec3 *, Vec3 *, Vec3 *);
extern void   func_800B0890(Mtx3 *, Mtx3 *, Mtx3 *);  // M1 = M2 * M3
extern void   func_800B0914(Vec3 *, Mtx3 *, Vec3 *);  // a = M * b
extern f32    func_800B09A8(Vec3 *, Vec3 *, Vec3 *, Vec3 *);
extern void   func_800B0A2C(Vec3 *, Vec3 *);
extern void   func_800B0A98(Mtx4 *, Vec3 *, Vec3 *, Vec3 *, Vec3 *);
extern void   func_800B0D9C(Mtx4 *, Vec3 *);
extern u8     func_800B0E50(f32);
extern void   func_800B0F08(Mtx4 *, f32 );
extern void   func_800B0F74(Vec4 *, Mtx4 *, Vec4 *);
extern f32    vec4_dot(Vec4 *, Vec4 *);

#endif /* !_LINALG_H_ */
