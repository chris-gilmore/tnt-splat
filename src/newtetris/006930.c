#include "common.h"

void FUN_006930_800406b0_fifteenliner_two_loops(u8 arg0, u8 *arg1, u8 *arg2) {
  register s8 var_a3;
  register u8 var_t0;
  register u8 var_t1;

  var_a3 = arg0;
  for (var_t0 = 0; var_a3 != g_currentPiece_ptr->logicalRotCkwState; var_t0++) {
    var_a3++;
    if (var_a3 > 3) {
      var_a3 = 0;
    }
  }

  var_a3 = arg0;
  for (var_t1 = 0; var_a3 != g_currentPiece_ptr->logicalRotCkwState; var_t1++) {
    var_a3--;
    if (var_a3 < 0) {
      var_a3 = 3;
    }
  }

  *arg1 = var_t0;
  *arg2 = var_t1;
}

void FUN_006930_80040784_nested_loop_20t_inside_loop_10t(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
  register u8 var_t0;
  register u8 var_t1;

  *arg0 = 10;
  if (arg1 != NULL) {
    *arg1 = 0;
  }
  if (arg2 != NULL) {
    *arg2 = 20;
  }
  *arg3 = 0;

  for (var_t0 = 0; var_t0 < 10; var_t0++) {
    for (var_t1 = 0; var_t1 < 20; var_t1++) {
      if (D_800E1F30->unk0[var_t0 + (var_t1 * 10)].unk0 == 8) {
        if (var_t0 < *arg0) {
          *arg0 = var_t0;
        }
        if ((arg1 != NULL) && (*arg1 < var_t0)) {
          *arg1 = var_t0;
        }
        if ((arg2 != NULL) && (*arg2 > var_t1)) {
          *arg2 = var_t1;
        }
        if (*arg3 < var_t1) {
          *arg3 = var_t1;
        }
      }
    }
  }
}
