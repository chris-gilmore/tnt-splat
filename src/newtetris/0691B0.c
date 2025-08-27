#include "common.h"

/*
  The functions in this file are handwritten assembly.
  The best we can do is to provide functionally equivalent versions in c,
  being highly unlikely to match the handwritten assembly.
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0691B0/func_800A2F30.s")
/*
void func_800A2F30(s16 *arg0, s16 *arg1) {
  s16 *end = arg1 + 64;

  do {
    *arg0 = *arg1;

    arg0++;
  } while (++arg1 != end);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0691B0/func_800A2F50.s")
/*
s32 func_800A2F50(s8 *arg0, s8 *arg1) {
  s32 ret = 0;
  s8 *end = arg1 + 128;

  do {
    if (*arg1 != *arg0) {
      ret = 1;
      if (*arg1 < *arg0) {
        (*arg1)++;
      } else {
        (*arg1)--;
      }
    }

    arg0++;
  } while (++arg1 != end);

  return ret;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0691B0/func_800A2FB0.s")
/*
void func_800A2FB0(UnkStruct_0 *arg0) {
  Gradient2D *var_a2;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_s6;
  s32 temp_s7;
  s32 temp_t6;
  s32 temp_t7;
  u8 *temp_t0;
  u8 *temp_t1;
  u8 *var_a3;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  s32 var_t2;
  s32 var_t3;

  var_s0 = arg0->unk14.unk24[0].unk0;
  var_s1 = arg0->unk14.unk24[0].unk4;
  var_s2 = arg0->unk14.unk24[1].unk0;
  var_s3 = arg0->unk14.unk24[1].unk4;

  temp_s4 = (arg0->unk14.unk24[2].unk0 - var_s0) >> 3;
  temp_s5 = (arg0->unk14.unk24[2].unk4 - var_s1) >> 3;
  temp_s6 = (arg0->unk14.unk24[3].unk0 - var_s2) >> 3;
  temp_s7 = (arg0->unk14.unk24[3].unk4 - var_s3) >> 3;

  var_a3 = arg0->unk14.unk4;
  var_a2 = arg0->unk14.unk0;

  temp_t0 = var_a3 + 64;
  do {
    var_t2 = var_s0;
    var_t3 = var_s1;

    temp_t1 = var_a3 + 8;
    do {
      temp_t6 = (var_t2 >> 16) + (var_a2->x << 2);
      temp_t7 = (var_t3 >> 16) + (var_a2->y << 2);
      if (((temp_t6 >> 8) == 0) && ((temp_t7 >> 8) == 0)) {
        *var_a3 = arg0->unk0[((temp_t6 >> 1) << 7) | (temp_t7 >> 1)];
      } else {
        *var_a3 = 0;
      }
      var_t2 += (var_s2 - var_s0) >> 3;
      var_t3 += (var_s3 - var_s1) >> 3;

      var_a2++;
    } while (++var_a3 != temp_t1);

    var_s0 += temp_s4;
    var_s1 += temp_s5;
    var_s2 += temp_s6;
    var_s3 += temp_s7;
  } while (var_a3 != temp_t0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0691B0/func_800A30F0.s")
/*
void func_800A30F0(UnkStruct_0 *arg0) {
  Gradient2D *var_a3;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  u32 temp_t0;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_s6;
  s32 temp_s7;
  u8 *var_a1;
  u16 *var_a2;
  u8 *temp_t0_2;
  u32 temp_v0;
  s32 var_t2;
  s32 var_t3;
  u8 *temp_t1;
  s32 temp_t6;
  s32 temp_t7;
  u8 var_t9;

  var_s0 = arg0->unk14.unk24[0].unk0;
  var_s1 = arg0->unk14.unk24[0].unk4;
  var_s2 = arg0->unk14.unk24[1].unk0;
  var_s3 = arg0->unk14.unk24[1].unk4;

  temp_t0 = arg0->unk14.unk20;
  temp_s4 = ((s64) (arg0->unk14.unk24[2].unk0 - var_s0) * temp_t0) >> 32;
  temp_s5 = ((s64) (arg0->unk14.unk24[2].unk4 - var_s1) * temp_t0) >> 32;
  temp_s6 = ((s64) (arg0->unk14.unk24[3].unk0 - var_s2) * temp_t0) >> 32;
  temp_s7 = ((s64) (arg0->unk14.unk24[3].unk4 - var_s3) * temp_t0) >> 32;

  var_a1 = arg0->unk14.unk8;  // src
  var_a2 = arg0->unk14.unk4;  // dest
  var_a3 = arg0->unk14.unk0;  // gradients

  temp_t0_2 = var_a1 + arg0->unk14.unk18;
  do {
    temp_v0 = arg0->unk14.unk1C;
    var_t2 = var_s0;
    var_t3 = var_s1;

    temp_t1 = var_a1 + arg0->unk14.unkC;
    do {
      temp_t6 = (var_t2 >> 16) + var_a3->x;
      temp_t7 = (var_t3 >> 16) + var_a3->y;
      if (((temp_t6 >> 8) == 0) && ((temp_t7 >> 8) == 0)) {
        var_t9 = arg0->unk0[((temp_t6 >> 1) << 7) | (temp_t7 >> 1)];
      } else {
        var_t9 = arg0->unk0[0];
      }
      *var_a2 = arg0->unk8.unk0[(var_t9 << 8) | *var_a1];

      var_t2 += ((s64) (var_s2 - var_s0) * temp_v0) >> 32;
      var_t3 += ((s64) (var_s3 - var_s1) * temp_v0) >> 32;

      var_a2++;
      var_a3++;
    } while (++var_a1 != temp_t1);

    var_s0 += temp_s4;
    var_s1 += temp_s5;
    var_s2 += temp_s6;
    var_s3 += temp_s7;
  } while (var_a1 != temp_t0_2);
}
*/
