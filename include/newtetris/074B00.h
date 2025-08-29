#ifndef _074B00_H_
#define _074B00_H_

// PI/180
#define DEG2RAD 0.017453293

extern void   func_800AE880(MtxF *, MtxF *);
extern void   func_800AF0C4(MtxF *, MtxF *, MtxF *);
extern void   mtx4_mult(MtxF *, MtxF *, MtxF *);
extern void   func_800AFBBC(Vec3 *, MtxF *, Vec3 *);
extern f32    vec3_dot(Vec3 *, Vec3 *);
extern void   vec3_cross(Vec3 *, Vec3 *, Vec3 *);
extern f32    vec3_squared(Vec3 *);
extern f32    vec3_length(Vec3 *);
extern void   func_800B036C(MtxF *, f32, f32, f32);
extern void   func_800B04BC(MtxF *, f32, f32, f32);

#endif /* !_074B00_H_ */
