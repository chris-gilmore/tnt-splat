#include "common.h"

u8 D_800C55B0[5] = { 0x01, 0x02, 0x10, 0x20, 0x40 };

static u8 D_800C55B8[19] = {
  0x26,
  0x29,
  0x2B,
  0x27,
  0x32,
  0x31,
  0x62,
  0x61,
  0x63,
  0x42,
  0x41,
  0x1A,
  0x15,
  0x0A,
  0x05,
  0x60,
  0x22,
  0x21,
  0x03,
};

static u8 D_800C55CC[38] = {
  0, 3,
  4, 7,
  8, 15,
  16, 23,
  24, 31,
  32, 39,
  40, 47,
  48, 55,
  56, 63,
  64, 67,
  68, 71,
  72, 75,
  76, 79,
  80, 81,
  82, 83,
  84, 89,
  90, 95,
  96, 101,
  102, 105,
};

static s8 D_800C55F4[0x50] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};

static s8 D_800C5644[0x6A0] = {
  5, 1, 1, 1, 5, 2, 2, 1, 5, 1, 2, 2, 5, 1, 1, 1,
  5, 5, 5, 5, 1, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1,
  1, 1, 1, 5, 2, 2, 1, 5, 1, 2, 2, 5, 1, 1, 1, 5,
  1, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 5, 5, 5, 5,
  5, 0, 0, 0, 5, 0, 3, 3, 5, 3, 3, 0, 5, 0, 0, 0,
  5, 5, 5, 5, 0, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 0,
  0, 0, 0, 5, 0, 3, 3, 5, 3, 3, 0, 5, 0, 0, 0, 5,
  0, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 0, 5, 5, 5, 5,
  5, 3, 0, 0, 5, 3, 3, 0, 5, 1, 3, 0, 5, 1, 1, 1,
  5, 5, 5, 5, 1, 1, 3, 3, 1, 3, 3, 0, 1, 0, 0, 0,
  1, 1, 1, 5, 0, 3, 1, 5, 0, 3, 3, 5, 0, 0, 3, 5,
  0, 0, 0, 1, 0, 3, 3, 1, 3, 3, 1, 1, 5, 5, 5, 5,
  5, 1, 1, 1, 5, 0, 3, 1, 5, 0, 3, 3, 5, 0, 0, 3,
  5, 5, 5, 5, 0, 0, 0, 1, 0, 3, 3, 1, 3, 3, 1, 1,
  3, 0, 0, 5, 3, 3, 0, 5, 1, 3, 0, 5, 1, 1, 1, 5,
  1, 1, 3, 3, 1, 3, 3, 0, 1, 0, 0, 0, 5, 5, 5, 5,
  5, 1, 1, 2, 5, 1, 2, 2, 5, 1, 2, 0, 5, 0, 0, 0,
  5, 5, 5, 5, 0, 1, 1, 1, 0, 2, 2, 1, 0, 0, 2, 2,
  0, 0, 0, 5, 0, 2, 1, 5, 2, 2, 1, 5, 2, 1, 1, 5,
  2, 2, 0, 0, 1, 2, 2, 0, 1, 1, 1, 0, 5, 5, 5, 5,
  5, 0, 0, 0, 5, 0, 2, 1, 5, 2, 2, 1, 5, 2, 1, 1,
  5, 5, 5, 5, 2, 2, 0, 0, 1, 2, 2, 0, 1, 1, 1, 0,
  1, 1, 2, 5, 1, 2, 2, 5, 1, 2, 0, 5, 0, 0, 0, 5,
  0, 1, 1, 1, 0, 2, 2, 1, 0, 0, 2, 2, 5, 5, 5, 5,
  5, 4, 4, 4, 5, 4, 4, 1, 5, 4, 4, 1, 5, 4, 1, 1,
  5, 5, 5, 5, 4, 4, 4, 4, 1, 4, 4, 4, 1, 1, 1, 4,
  1, 1, 4, 5, 1, 4, 4, 5, 1, 4, 4, 5, 4, 4, 4, 5,
  4, 1, 1, 1, 4, 4, 4, 1, 4, 4, 4, 4, 5, 5, 5, 5,
  5, 1, 1, 4, 5, 1, 4, 4, 5, 1, 4, 4, 5, 4, 4, 4,
  5, 5, 5, 5, 4, 1, 1, 1, 4, 4, 4, 1, 4, 4, 4, 4,
  4, 4, 4, 5, 4, 4, 1, 5, 4, 4, 1, 5, 4, 1, 1, 5,
  4, 4, 4, 4, 1, 4, 4, 4, 1, 1, 1, 4, 5, 5, 5, 5,
  5, 4, 0, 0, 5, 4, 4, 0, 5, 4, 4, 0, 5, 4, 4, 4,
  5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0,
  4, 4, 4, 5, 0, 4, 4, 5, 0, 4, 4, 5, 0, 0, 4, 5,
  0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5,
  5, 4, 4, 4, 5, 0, 4, 4, 5, 0, 4, 4, 5, 0, 0, 4,
  5, 5, 5, 5, 0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 4, 4,
  4, 0, 0, 5, 4, 4, 0, 5, 4, 4, 0, 5, 4, 4, 4, 5,
  4, 4, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0, 5, 5, 5, 5,
  5, 6, 6, 1, 5, 6, 6, 1, 5, 1, 1, 1, 5, 1, 1, 1,
  5, 5, 5, 5, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 1, 1,
  1, 1, 1, 5, 1, 1, 1, 5, 1, 6, 6, 5, 1, 6, 6, 5,
  1, 1, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 5, 5, 5, 5,
  5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 6, 6, 5, 1, 6, 6,
  5, 5, 5, 5, 1, 1, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1,
  6, 6, 1, 5, 6, 6, 1, 5, 1, 1, 1, 5, 1, 1, 1, 5,
  1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 1, 1, 5, 5, 5, 5,
  5, 0, 6, 6, 5, 0, 6, 6, 5, 0, 0, 0, 5, 0, 0, 0,
  5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 6, 6,
  0, 0, 0, 5, 0, 0, 0, 5, 6, 6, 0, 5, 6, 6, 0, 5,
  6, 6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5,
  5, 0, 0, 0, 5, 0, 0, 0, 5, 6, 6, 0, 5, 6, 6, 0,
  5, 5, 5, 5, 6, 6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0,
  0, 6, 6, 5, 0, 6, 6, 5, 0, 0, 0, 5, 0, 0, 0, 5,
  0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 6, 6, 5, 5, 5, 5,
  5, 0, 0, 0, 5, 0, 6, 6, 5, 1, 6, 6, 5, 1, 1, 1,
  5, 5, 5, 5, 1, 1, 0, 0, 1, 6, 6, 0, 1, 6, 6, 0,
  1, 1, 1, 5, 6, 6, 1, 5, 6, 6, 0, 5, 0, 0, 0, 5,
  0, 6, 6, 1, 0, 6, 6, 1, 0, 0, 1, 1, 5, 5, 5, 5,
  5, 1, 1, 1, 5, 6, 6, 1, 5, 6, 6, 0, 5, 0, 0, 0,
  5, 5, 5, 5, 0, 6, 6, 1, 0, 6, 6, 1, 0, 0, 1, 1,
  0, 0, 0, 5, 0, 6, 6, 5, 1, 6, 6, 5, 1, 1, 1, 5,
  1, 1, 0, 0, 1, 6, 6, 0, 1, 6, 6, 0, 5, 5, 5, 5,
  6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 6, 6,
  1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1, 6, 6, 1, 1,
  6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 6, 6, 0, 0, 6, 6, 0, 0, 6, 6, 0, 0, 6, 6,
  0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 0, 0, 6, 6, 0, 0, 6, 6, 0, 0, 6, 6, 0, 0,
  1, 1, 3, 3, 1, 3, 3, 4, 1, 4, 4, 4, 4, 4, 4, 4,
  4, 1, 1, 1, 4, 4, 3, 1, 4, 4, 3, 3, 4, 4, 4, 3,
  4, 4, 4, 4, 4, 4, 4, 1, 4, 3, 3, 1, 3, 3, 1, 1,
  3, 4, 4, 4, 3, 3, 4, 4, 1, 3, 4, 4, 1, 1, 1, 4,
  2, 2, 0, 0, 4, 2, 2, 0, 4, 4, 4, 0, 4, 4, 4, 4,
  4, 4, 4, 2, 4, 4, 2, 2, 4, 4, 2, 0, 4, 0, 0, 0,
  4, 4, 4, 4, 0, 4, 4, 4, 0, 2, 2, 4, 0, 0, 2, 2,
  0, 0, 0, 4, 0, 2, 4, 4, 2, 2, 4, 4, 2, 4, 4, 4,
  //                               v  v
  1, 1, 3, 3, 1, 3, 3, 1, 1, 3, 3, 3, 1, 3, 1, 1,  // Bug
//1, 1, 3, 3, 1, 3, 3, 1, 1, 3, 3, 1, 3, 3, 1, 1,  // Corrected
  //                               ^  ^
  3, 1, 1, 1, 3, 3, 3, 1, 1, 3, 3, 3, 1, 1, 1, 3,
  2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 2, 2,
  0, 0, 0, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 0, 0, 0,
  5, 5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6,
  5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 5, 5,
  6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5,
  5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 5,
  5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5,
  5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1,
  5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5,
  1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5,
  5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5,
  5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5,
  5, 5, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0,
  5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 5, 5,
  0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5,
  5, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 5,
  5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5,
  0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
};

static void FUN_005580_8003f720_fiveliner_sets_arg0_elems_to_args1to4(UnkStruct_105 *, u8, s8, u8, u8);
static u8 FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(UnkStruct_105 *, u8, u8, u8);

u8 FUN_005580_8003f300_fourteenliner_recursive(s8 arg0[4][4], u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
  register u8 temp_s0;
  register u8 temp_s1;
  register u8 temp_s2 = arg3 + 3;
  register u8 temp_s3 = arg4 + 3;

  if ((arg1 < arg3) || (temp_s2 < arg1) || (arg2 < arg4) || (temp_s3 < arg2)) {
    return 0;
  }

  temp_s0 = arg1 - arg3;
  temp_s1 = arg2 - arg4;

  if ((arg0[temp_s0][temp_s1] == 0) && (D_800E1F30->unk0[arg1 + (arg2 * 10)].unk0 == EMPTY_CELL)) {
    arg0[temp_s0][temp_s1] = 1;
    return
      FUN_005580_8003f300_fourteenliner_recursive(arg0, arg1 - 1, arg2    , arg3, arg4) +
      FUN_005580_8003f300_fourteenliner_recursive(arg0, arg1 + 1, arg2    , arg3, arg4) +
      FUN_005580_8003f300_fourteenliner_recursive(arg0, arg1    , arg2 - 1, arg3, arg4) +
      FUN_005580_8003f300_fourteenliner_recursive(arg0, arg1    , arg2 + 1, arg3, arg4) +
      1;
  }

  return 0;
}

u8 FUN_005580_8003f4f4_thirtyliner_nested_loops(s8 arg0[4][4], u8 arg1, u8 arg2, u8 arg3) {
  register u8 var_t0;
  register u8 var_t1;
  register u8 var_t2;
  register u8 var_t3;
  register u8 var_t4 = 0;

  if (!arg1) {
    if (D_800C55B0[arg3] == arg2) {
      for (var_t2 = 0; var_t2 < 4; var_t2++) {
        for (var_t1 = 0; var_t1 < 4; var_t1++) {
          if ((arg0[var_t1][var_t2] != -1) && (arg0[var_t1][var_t2] != D_800C55F4[(arg3 * 16) + (var_t2 * 4) + var_t1])) {
            return var_t4;
          }
        }
      }
      var_t4 = 1;
    }
  } else if (D_800C55B8[arg3] & arg2) {
    var_t4 = 0;
    for (var_t0 = D_800C55CC[arg3 * 2]; var_t0 <= D_800C55CC[arg3 * 2 + 1]; var_t0++) {
      var_t3 = TRUE;
      for (var_t2 = 0; var_t2 < 4; var_t2++) {
        for (var_t1 = 0; var_t1 < 4; var_t1++) {
          if ((arg0[var_t1][var_t2] != -1) && (arg0[var_t1][var_t2] != D_800C5644[(var_t0 * 16) + (var_t2 * 4) + var_t1])) {
            var_t3 = FALSE;
            break;
          }
        }
        if (!var_t3) {
          break;
        }
      }
      if (var_t3) {
        var_t4++;
      }
    }
  }

  return var_t4;
}

static void FUN_005580_8003f720_fiveliner_sets_arg0_elems_to_args1to4(UnkStruct_105 *arg0, u8 arg1, s8 arg2, u8 arg3, u8 arg4) {
  register UnkStruct_98 *tmp = &arg0->unk1[arg0->unk0];

  tmp->unk0.unk0 = arg1;
  tmp->unk0.unk1 = arg2;
  tmp->unk0.unk2 = arg3;
  tmp->unk3 = arg4;
}

void FUN_005580_8003f760_twoliner_calls_fun(UnkStruct_105 *arg0, u8 arg1, s8 arg2, u8 arg3, u8 arg4) {
  arg0->unk0 = 0;
  FUN_005580_8003f720_fiveliner_sets_arg0_elems_to_args1to4(arg0, arg1, arg2, arg3, arg4);
}

static u8 FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(UnkStruct_105 *arg0, u8 arg1, u8 arg2, u8 arg3) {
  register u8 var_s0;
  register u8 var_s1;
  register s8 temp_s2;
  register s8 temp_s3;
  register s8 temp_s4;
  register UnkStruct_98 *var_s5;
  u8 sp43;
  u8 sp42;

  var_s5 = &arg0->unk1[arg0->unk0];
  g_currentPiece_ptr->logicalPos.x = var_s5->unk0.unk0;
  g_currentPiece_ptr->logicalPos.y = var_s5->unk0.unk1;
  g_currentPiece_ptr->logicalRotCkwState = var_s5->unk0.unk2;
  var_s5 = arg0->unk1;
  for (var_s1 = 0; var_s1 < arg0->unk0; var_s1++) {
    if ((g_currentPiece_ptr->logicalPos.x == var_s5->unk0.unk0) && (g_currentPiece_ptr->logicalPos.y == var_s5->unk0.unk1) && (g_currentPiece_ptr->logicalRotCkwState == var_s5->unk0.unk2)) {
      return FALSE;
    }
    var_s5++;
  }

  var_s5 = &arg0->unk1[arg0->unk0];

  var_s0 = FUN_006B30_800408b0_fiveliner_loops_4t(g_currentPiece_ptr->logicalPos.y, g_currentPiece_ptr->logicalRotCkwState, g_currentPiece_ptr->pieceType);

  switch (arg1) {
  case 0:
    do {} while (var_s1 = FUN_8004172c_twentyliner(0, -1, 0));
    break;
  case 1:
    do {
      if (var_s0 && (g_currentPiece_ptr->logicalPos.x == 5)) {
        var_s1 = FALSE;
      } else {
        var_s1 = FUN_8004172c_twentyliner(-1, 0, 0);
      }
    } while (var_s1);
    break;
  case 2:
    do {
      if (var_s0 && (g_currentPiece_ptr->logicalPos.x == 5)) {
        var_s1 = FALSE;
      } else {
        var_s1 = FUN_8004172c_twentyliner(1, 0, 0);
      }
    } while (var_s1);
    break;
  case 3:
    do {
      if (var_s0 && (g_currentPiece_ptr->logicalRotCkwState == arg2)) {
        var_s1 = FALSE;
      } else {
        var_s1 = FUN_8004172c_twentyliner(0, 0, 1);
        if (g_currentPiece_ptr->logicalRotCkwState == var_s5->unk0.unk2) {
          var_s1 = FALSE;
        }
      }
    } while (var_s1);
    break;
  case 4:
    do {
      if (var_s0 && (g_currentPiece_ptr->logicalRotCkwState == arg2)) {
        var_s1 = FALSE;
      } else {
        var_s1 = FUN_8004172c_twentyliner(0, 0, -1);
        if (g_currentPiece_ptr->logicalRotCkwState == var_s5->unk0.unk2) {
          var_s1 = FALSE;
        }
      }
    } while (var_s1);
    break;
  }

  if ((g_currentPiece_ptr->logicalPos.x == 5) && (g_currentPiece_ptr->logicalPos.y == 0) && (g_currentPiece_ptr->logicalRotCkwState == arg2)) {
    return TRUE;
  }

  if ((g_currentPiece_ptr->logicalPos.x == var_s5->unk0.unk0) && (g_currentPiece_ptr->logicalPos.y == var_s5->unk0.unk1) && (g_currentPiece_ptr->logicalRotCkwState == var_s5->unk0.unk2)) {
    switch (arg1) {
    case 0:
      var_s5->unk3 = 1;
      return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 1, arg2, arg3);
    case 1:
      var_s5->unk3 = 2;
      return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 2, arg2, arg3);
    case 2:
      return FALSE;
    }
  } else {
    arg0->unk0++;
    if (arg0->unk0 > 15) {
      return FALSE;
    }

    var_s5 = &arg0->unk1[arg0->unk0];
    var_s5->unk0.unk0 = g_currentPiece_ptr->logicalPos.x;
    var_s5->unk0.unk1 = g_currentPiece_ptr->logicalPos.y;
    var_s5->unk0.unk2 = g_currentPiece_ptr->logicalRotCkwState;

    if (FUN_006B30_800408b0_fiveliner_loops_4t(g_currentPiece_ptr->logicalPos.y, g_currentPiece_ptr->logicalRotCkwState, g_currentPiece_ptr->pieceType)) {
      FUN_006930_800406b0_fifteenliner_two_loops(arg2, &sp43, &sp42);

      if (arg3 == 0) {
        if (g_currentPiece_ptr->logicalPos.x < 5) {
          var_s5->unk3 = 2;
          return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 2, arg2, arg3);
        }
        if (g_currentPiece_ptr->logicalPos.x > 5) {
          var_s5->unk3 = 1;
          return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 1, arg2, arg3);
        }
        if ((sp43 != 0) || (sp42 != 0)) {
          if (sp43 <= sp42) {
            var_s5->unk3 = 3;
            return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 3, arg2, arg3);
          }
          var_s5->unk3 = 4;
          return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 4, arg2, arg3);
        }
        var_s5->unk3 = 0;
        return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 0, arg2, arg3);
      }

      if ((sp43 != 0) || (sp42 != 0)) {
        if (sp43 <= sp42) {
          var_s5->unk3 = 3;
          return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 3, arg2, arg3);
        }
        var_s5->unk3 = 4;
        return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 4, arg2, arg3);
      }
      if (g_currentPiece_ptr->logicalPos.x < 5) {
        var_s5->unk3 = 2;
        return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 2, arg2, arg3);
      }
      if (g_currentPiece_ptr->logicalPos.x > 5) {
        var_s5->unk3 = 1;
        return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 1, arg2, arg3);
      }
      var_s5->unk3 = 0;
      return FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 0, arg2, arg3);
    }

    if (arg1 != 0) {
      var_s5->unk3 = 0;
      temp_s2 = g_currentPiece_ptr->logicalPos.x;
      temp_s3 = g_currentPiece_ptr->logicalPos.y;
      temp_s4 = g_currentPiece_ptr->logicalRotCkwState;
      if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 0, arg2, arg3)) {
        return TRUE;
      }
      g_currentPiece_ptr->logicalPos.x = temp_s2;
      g_currentPiece_ptr->logicalPos.y = temp_s3;
      g_currentPiece_ptr->logicalRotCkwState = temp_s4;
    }

    if ((arg1 != 1) && (arg1 != 2)) {
      var_s5->unk3 = 1;
      temp_s2 = g_currentPiece_ptr->logicalPos.x;
      temp_s3 = g_currentPiece_ptr->logicalPos.y;
      temp_s4 = g_currentPiece_ptr->logicalRotCkwState;
      if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 1, arg2, arg3)) {
        return TRUE;
      }
      g_currentPiece_ptr->logicalPos.x = temp_s2;
      g_currentPiece_ptr->logicalPos.y = temp_s3;
      g_currentPiece_ptr->logicalRotCkwState = temp_s4;
      var_s5->unk3 = 2;
      if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 2, arg2, arg3)) {
        return TRUE;
      }
      g_currentPiece_ptr->logicalPos.x = temp_s2;
      g_currentPiece_ptr->logicalPos.y = temp_s3;
      g_currentPiece_ptr->logicalRotCkwState = temp_s4;
    }

    if ((arg1 != 3) && (arg1 != 4)) {
      FUN_006930_800406b0_fifteenliner_two_loops(arg2, &sp43, &sp42);
      temp_s2 = g_currentPiece_ptr->logicalPos.x;
      temp_s3 = g_currentPiece_ptr->logicalPos.y;
      temp_s4 = g_currentPiece_ptr->logicalRotCkwState;
      if (sp43 <= sp42) {
        var_s5->unk3 = 3;
        if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 3, arg2, arg3)) {
          return TRUE;
        }
      } else {
        var_s5->unk3 = 4;
        if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 4, arg2, arg3)) {
          return TRUE;
        }
      }
      g_currentPiece_ptr->logicalPos.x = temp_s2;
      g_currentPiece_ptr->logicalPos.y = temp_s3;
      g_currentPiece_ptr->logicalRotCkwState = temp_s4;
    }
  }

  return FALSE;
}

u8 FUN_005580_800400fc_largefun_more_currpiece_stuff(UnkStruct_105 *arg0, u8 arg1) {
  register u8 temp_s0;
  register u8 temp_s1;
  register u8 temp_s2;
  register u8 temp_s3;
  register u8 temp_s4;
  register UnkStruct_98 *temp_s5;
  u8 sp33;
  u8 sp32;

  temp_s5 = &arg0->unk1[arg0->unk0];
  temp_s1 = temp_s5->unk0.unk0;
  temp_s2 = temp_s5->unk0.unk1;
  temp_s3 = temp_s5->unk0.unk2;
  g_currentPiece_ptr->logicalPos.x = temp_s1;
  g_currentPiece_ptr->logicalPos.y = temp_s2;
  g_currentPiece_ptr->logicalRotCkwState = temp_s3;
  if (!FUN_80041810_twentyliner(temp_s1, temp_s2, temp_s3)) {
    return FALSE;
  }

  temp_s4 = g_pieceDef_ptr_arr[g_currentPiece_ptr->pieceType]->starting_rot_state;

  do {} while (temp_s0 = FUN_8004172c_twentyliner(0, -1, 0));

  if (!FUN_006B30_800408b0_fiveliner_loops_4t(g_currentPiece_ptr->logicalPos.y, temp_s3, g_currentPiece_ptr->pieceType)) {
    if (FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive(arg0, 0, temp_s4, arg1)) {
      return TRUE;
    } else {
      return FALSE;
    }
  }

  temp_s5->unk3 = 6;
  arg0->unk0++;
  temp_s5 = &arg0->unk1[arg0->unk0];
  temp_s5->unk0.unk0 = temp_s1;
  temp_s5->unk0.unk1 = g_currentPiece_ptr->logicalPos.y;
  temp_s5->unk0.unk2 = temp_s3;

  if (g_currentPiece_ptr->logicalPos.x < 5) {
    temp_s5->unk3 = 2;
    do {} while ((temp_s0 = FUN_8004172c_twentyliner(1, 0, 0)) && (g_currentPiece_ptr->logicalPos.x < 5));
    if (g_currentPiece_ptr->logicalPos.x != 5) {
      return FALSE;
    }
  } else if (g_currentPiece_ptr->logicalPos.x > 5) {
    temp_s5->unk3 = 1;
    do {} while ((temp_s0 = FUN_8004172c_twentyliner(-1, 0, 0)) && (g_currentPiece_ptr->logicalPos.x > 5));
    if (g_currentPiece_ptr->logicalPos.x != 5) {
      return FALSE;
    }
  }

  FUN_006930_800406b0_fifteenliner_two_loops(temp_s4, &sp33, &sp32);
  if ((sp33 != 0) || (sp32 != 0)) {
    arg0->unk0++;
    temp_s5 = &arg0->unk1[arg0->unk0];
    temp_s5->unk0.unk0 = g_currentPiece_ptr->logicalPos.x;
    temp_s5->unk0.unk1 = g_currentPiece_ptr->logicalPos.y;
    temp_s5->unk0.unk2 = temp_s3;

    if (sp33 <= sp32) {
      temp_s5->unk3 = 3;
      do {} while ((temp_s0 = FUN_8004172c_twentyliner(0, 0, 1)) && (g_currentPiece_ptr->logicalRotCkwState != temp_s4));
      if (g_currentPiece_ptr->logicalRotCkwState != temp_s4) {
        return FALSE;
      }
    } else {
      temp_s5->unk3 = 4;
      do {} while ((temp_s0 = FUN_8004172c_twentyliner(0, 0, -1)) && (g_currentPiece_ptr->logicalRotCkwState != temp_s4));
      if (g_currentPiece_ptr->logicalRotCkwState != temp_s4) {
        return FALSE;
      }
    }
  }

  return TRUE;
}
