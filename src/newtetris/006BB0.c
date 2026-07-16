#include "common.h"

//extern u8 D_800C5DD0[4];
static u8 D_800C5DD0[4] = { 1, 4, 8, 12 };

//extern s8 D_800C5DD4[5];
static s8 D_800C5DD4[5] = { 0, 12, 32, 72, 144 };

//extern s8 D_800C5DDC[20];
static s8 D_800C5DDC[20] = {
  -4, -4, -3, -2, -1,
   1,  2,  3,  4,  5,
   6,  8, 10, 12, 14,
  16, 20, 24, 28, 32,
};

static s16 FUN_006BB0_80040930_large_eightyliner(u8, s8);

static s16 FUN_006BB0_80040930_large_eightyliner(u8 arg0, s8 arg1) {
  register s8 var_s0;
  register u8 var_s1;
  register u8 var_s2;
  register u8 var_s3;
  register u8 var_s4;
  register s16 var_s5 = 0;
  u8 sp37;
  u8 sp36;
  u8 sp35;
  u8 sp34;
  u8 sp30[4];

  FUN_006930_80040784_nested_loop_20t_inside_loop_10t(&sp37, &sp36, &sp35, &sp34);
  if (sp34 > 3) {
    sp35 = sp34 - 3;
  } else {
    sp35 = 0;
  }
  if (sp35 > 3) {
    var_s2 = sp35 - 3;
  } else {
    var_s2 = 0;
  }

  if ((var_s2 + 3) == sp35) {
    for (var_s1 = sp37; var_s1 <= sp36; var_s1++) {
      if (D_800E1F30->unk0[var_s1 + (var_s2 * 10)].unk0 == 8) {
        var_s5 -= 4;
      }
    }
    var_s2++;
  }

  for (var_s0 = var_s2; var_s0 < sp35; var_s0++) {
    for (var_s1 = sp37; var_s1 <= sp36; var_s1++) {
      if (D_800E1F30->unk0[var_s1 + (var_s0 * 10)].unk0 == 8) {
        var_s5 -= 1;
      }
    }
  }

  var_s3 = TRUE;
  var_s4 = 0;
  for (var_s0 = sp35; var_s0 <= sp34; var_s0++) {
    sp30[var_s0 - sp35] = TRUE;
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
      if (D_800E1F30->unk0[var_s1 + (var_s0 * 10)].unk0 == EMPTY_CELL) {
        sp30[var_s0 - sp35] = FALSE;
        break;
      }
    }

    if (sp30[var_s0 - sp35]) {
      var_s4++;
    }

    for (var_s1 = sp37; var_s1 <= sp36; var_s1++) {
      if (D_800E1F30->unk0[var_s1 + (var_s0 * 10)].unk0 == 8) {
        var_s5 += D_800C5DD0[var_s0 - sp35] + D_800C5DDC[var_s0];
        if (arg0) {
          var_s5 += D_800C5DDC[var_s0];
        }
        if (!sp30[var_s0 - sp35]) {
          for (var_s2 = var_s0 + 1; var_s2 <= sp34; var_s2++) {
            if (D_800E1F30->unk0[var_s1 + (var_s2 * 10)].unk0 == EMPTY_CELL) {
              var_s5 -= D_800C5DD0[var_s2 - sp35];
              if (var_s1 == arg1) {
                var_s5 -= D_800C5DD0[var_s2 - sp35];
              }
              var_s3 = FALSE;
            }
          }
        }
      }
    }
  }

  var_s5 += D_800C5DD4[var_s4];
  if (arg0) {
    var_s5 += var_s4 * 16;
  }

  for (var_s1 = sp37; var_s1 <= sp36; var_s1++) {
    for (var_s0 = sp35; var_s0 <= sp34; var_s0++) {
      if (!sp30[var_s0 - sp35] && (D_800E1F30->unk0[var_s1 + (var_s0 * 10)].unk0 == 8)) {
        for (var_s2 = sp34 + 1; var_s2 < 20; var_s2++) {
          if (D_800E1F30->unk0[var_s1 + (var_s2 * 10)].unk0 == EMPTY_CELL) {
            var_s5 -= 12;
            if (var_s1 == arg1) {
              var_s5 -= 12;
            }
            var_s3 = FALSE;
          } else {
            break;
          }
        }
        break;
      }
    }
  }

  if (var_s3) {
    var_s5 += 16;
  }

  return var_s5;
}

void FUN_006BB0_80040f9c_twentyfiveliner_loops_200t(u8 arg0, u8 arg1, s8 arg2) {
  register u8 temp_s0;
  register u8 temp_s1;
  register u8 temp_s2;
  register u8 var_s3;
  register u8 var_s4;
  register u8 unused;
  register UnkStruct_99 *temp_s6;
  register UnkStruct_108 *temp_s7;

  FUN_008050_80041e88_loops_200_times();

  var_s4 = 0;
  for (var_s3 = 0; var_s3 < D_800E1F20->unk0[arg1]; var_s3++) {
    if (var_s4 >= 200) {
      var_s4 = 200;
      break;
    }

    temp_s7 = &D_800E1F20->unk2[arg1][var_s3];
    temp_s0 = temp_s7->unk0;
    temp_s1 = temp_s7->unk1;
    temp_s2 = temp_s7->unk2;
    FUN_800413c0_twentyfive_liner(temp_s0, temp_s1, temp_s2, 8);

    temp_s6 = &(*D_800E1F40)[var_s4];
    temp_s6->unk2.unk0 = temp_s0;
    temp_s6->unk2.unk1 = temp_s1;
    temp_s6->unk2.unk2 = temp_s2;
    temp_s6->unk0 = FUN_006BB0_80040930_large_eightyliner(arg0, arg2);
    if (!arg0 && !aisquarelist_8003e55c_eightliner_loops_arg0_t_1(&D_800C5E04->unk2E)) {
      temp_s6->unk0 -= 50;
    }
    FUN_006930_80040784_nested_loop_20t_inside_loop_10t(&temp_s6->unk5, NULL, NULL, &temp_s6->unk6);

    var_s4++;
    FUN_800413c0_twentyfive_liner(temp_s0, temp_s1, temp_s2, 7);
  }

  FUN_008050_800423f0_uses_dat_800e1f40_ptr(var_s4);
}
