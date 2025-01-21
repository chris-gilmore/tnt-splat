#include "common.h"

// A return value of TRUE causes the ghost piece to blink (spin maneuver possible).
u8 FUN_003E40_8003dbc0_twentyliner_nested_loops(u8 arg0, s8 arg1, u8 arg2) {
  register s8 var_s0;
  register s8 var_s1;
  register s8 temp_s2;
  u8 ret;

  if (g_currentPiece_ptr->state != 1) {
    return FALSE;
  }

  ret = FALSE;
  temp_s2 = arg1 - g_currentPiece_ptr->logicalPos.y;
  for (var_s1 = temp_s2 - 1; var_s1 < temp_s2 + 2; var_s1++) {
    if (CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr, 0, var_s1, 0)) {
      for (var_s0 = -2; var_s0 < 2; var_s0++) {
        if ((var_s0 != 0) &&
            ( CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr,  0, var_s1,     var_s0)) &&
            (!CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr, -1, var_s1,     var_s0)) &&
            (!CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr,  1, var_s1,     var_s0)) &&
            (!CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr,  0, var_s1 - 1, var_s0)) &&
            (!CurrentPiece_80066d8c_maybeRotCkw_retbool(g_currentPiece_ptr,  0, var_s1 + 1, var_s0))) {
          ret = TRUE;
          break;
        }
      }
      if (ret) {
        break;
      }
    }
  }
  return ret;
}

// A return value of TRUE causes the ghost piece to blink (square completion possible).
u8 FUN_003E40_8003dda8_twentyfiveliner_nested_loops(u8 arg0, s8 arg1, u8 arg2) {
  register s8 var_s0;
  register s8 var_s1;
  register s8 ret;
  register s8 var_s3;
  u8 sp33;
  u8 sp32;
  u8 sp31;

  FUN_800412e0_fifteenliner_logic_cell(&sp33);
  ret = FALSE;
  for (var_s3 = arg1 - 1; var_s3 < arg1 + 4; var_s3++) {
    if (FUN_80041810_twentyliner(arg0, var_s3, arg2) && FUN_800416cc_fourliner(arg0, var_s3, arg2)) {
      FUN_800413c0_twentyfive_liner(arg0, var_s3, arg2, 8);
      for (var_s1 = (var_s3 - 3) > 0 ? var_s3 - 3 : 0; var_s1 <= var_s3; var_s1++) {
        for (var_s0 = arg0 - 3 > 0 ? arg0 - 3 : 0; var_s0 <= arg0; var_s0++) {
          if (check_square_completion(var_s0, var_s1, &sp33, &sp32, &sp31) && sp32 == 4) {
            ret = TRUE;
            break;
          }
        }
        if (ret) break;
      }
      FUN_800413c0_twentyfive_liner(arg0, var_s3, arg2, 7);
      if (ret) break;
    }
  }
  return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/003E40/FUN_003E40_8003dfa0_sixliner_allocs_heap_x962.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/003E40/FUN_003E40_8003e004_threeliner_unallocs_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/003E40/FUN_003E40_8003e038_twentytwoliner_nested_loops.s")
