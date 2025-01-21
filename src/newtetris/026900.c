#include "common.h"

static s16 D_8011F270[1024];  // sin lut
static u32 D_8011FA70;        // prng seed

Trig g_trig_tbl[] = {
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
  { -1,  0 },
};

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026900/func_80060680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026900/func_80060704.s")

void FUN_026900_sets_arg0_struct_to_arg1_arg2(BoundingBox *arg0, s32 arg1, s32 arg2) {
  register s16 var_a3;

  var_a3 = arg1;
  arg0->x_max = var_a3;
  arg0->x_min = var_a3;

  var_a3 = arg2;
  arg0->y_max = var_a3;
  arg0->y_min = var_a3;
}

u8 FUN_026900_80060770_sevenliner(UnkStruct_2 *arg0, f32 arg1) {
    arg0->alpha += arg0->unk4 * arg1;
    if (((arg0->unk4 < 0.0f) && (arg0->alpha < arg0->unk8)) || ((arg0->unk4 > 0.0f) && (arg0->alpha > arg0->unk8))) {
        arg0->alpha = arg0->unk8;
        arg0->unk4 = 0.0f;
        return FALSE;
    }
    return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026900/FUN_026900_PRNG_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/026900/FUN_026900_sets_g8011FA70_to_arg0.s")

// next_rand(seed)
u32 FUN_026900_PRNG_2(u32 seed) {
  register s32 retVal;
  register s32 i;

  seed++;
  retVal = 0;
  for (i = 0; i < 32; i++) {
    seed = ((seed << 3) | ((seed >> 29) & 7)) ^ 0x80500000;
    retVal |= (seed & 1) << i;
  }
  return retVal;
}

// sin
s16 FUN_026900_800608f4_oneliner_shift6_1(u16 arg0) {
  return D_8011F270[arg0 >> 6];
}

// cos
s16 FUN_026900_80060914_oneliner_shift6_2(u16 arg0) {
  return D_8011F270[(u16)(arg0 + 0x4000) >> 6];
}

// sin lut with 1024 entries
void FUN_026900_8006093c_rounds_floors_loops_1024t(void) {
  register u32 i;
  register f32 temp_ft2;

  for (i = 0; i < 1024; i++) {
    temp_ft2 = (i * 3.1415927f) / 512;
    D_8011F270[i] = sinf(temp_ft2) * 16384;
  }
}
