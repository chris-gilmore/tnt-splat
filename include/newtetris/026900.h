#ifndef _026900_H_
#define _026900_H_

typedef struct {
  /* 0x0 */ s32   sin;
  /* 0x4 */ s32   cos;
} Trig; // 0x8 bytes

typedef struct {
  /* 0x0 */ f32   alpha;
  /* 0x4 */ f32   unk4;
  /* 0x8 */ f32   unk8;
} UnkStruct_2; // 0xC bytes

typedef struct {
  /* 0x0 */ s16   x_min;
  /* 0x2 */ s16   y_min;
  /* 0x4 */ s16   x_max;
  /* 0x6 */ s16   y_max;
} BoundingBox; // 0x8 bytes

extern Trig g_trig_tbl[];

extern void   FUN_026900_sets_arg0_struct_to_arg1_arg2(BoundingBox *, s32, s32);
extern u8     FUN_026900_80060770_sevenliner(UnkStruct_2 *, f32);
extern u32    FUN_026900_PRNG_1(void);
extern u32    FUN_026900_PRNG_2(u32);
extern s16    FUN_026900_800608f4_oneliner_shift6_1(u16);
extern s16    FUN_026900_80060914_oneliner_shift6_2(u16);
extern void   FUN_026900_8006093c_rounds_floors_loops_1024t(void);

#endif /* !_026900_H_ */
