#include "common.h"

UnkStruct_6 *D_800E1F30;

void FUN_80041260_twoliner(void) {
  D_800E1F30 = (UnkStruct_6 *)n64HeapAlloc(sizeof(UnkStruct_6));
  Ids_Init(&D_800E1F30->unk258, 1);
}

void FUN_8004129c_fourliner(void) {
  if (D_800E1F30 != NULL) {
    Ids_Deinit(&D_800E1F30->unk258);
    n64HeapUnalloc(D_800E1F30);
    D_800E1F30 = NULL;
  }
}

u8 FUN_800412e0_fifteenliner_logic_cell(u8 *arg0) {
  register u8 var_s0;
  register u8 var_s1;

  var_s0 = 0;
  if (D_800E1F30 != NULL) {
    for (var_s1 = 0; var_s1 < 200; var_s1++) {
      if (FUN_0073F0_80041170_fifteenliner_pf_logic_cell(&D_800E1F30->unk0[var_s1], var_s1)) {
        if (var_s0 == 0) {
          *arg0 = var_s1 / 10;
        }
        var_s0++;
      }
    }
    if (var_s0 == 0) {
      *arg0 = 20;
    }
    FUN_800508ec_fifteen_liner_allocs_heap(&D_800E1F30->unk258, &g_boardPieces_ptr->pieceIds);
  }
  return var_s0;
}

u8 FUN_800413c0_twentyfive_liner(u8 x, u8 y, u8 rot, u8 arg3) {
  register UnkStruct_28 *temp_s0;
  register s8 i;
  register s8 temp_s2;
  register s8 temp_s3;
  register UnkStruct_27 *temp_s4;
  register u8 var_s5;

  if (g_currentPiece_ptr->pieceType >= EMPTY_CELL) {
    return FALSE;
  }

  temp_s0 = &D_800C5CF0[g_currentPiece_ptr->pieceType][rot];
  for (i = 0; i < 4; i++) {
    temp_s2 = temp_s0->unk0[i] + x;
    temp_s3 = temp_s0->unk4[i] + y;
    if (temp_s2 < 0 || temp_s2 >= 10 || temp_s3 < 0 || temp_s3 >= 20) {
      return FALSE;
    }
    if (arg3 == 8 && D_800E1F30->unk0[temp_s2 + (temp_s3 * 10)].unk0 != EMPTY_CELL) {
      return FALSE;
    }
  }

  if (arg3 == 8) {
    var_s5 = can_run_out_of_ids(&D_800E1F30->unk258);
    FUN_80050800_oneliner(&D_800E1F30->unk258, var_s5);
  } else if (arg3 == EMPTY_CELL) {
    temp_s2 = temp_s0->unk0[0] + x;
    temp_s3 = temp_s0->unk4[0] + y;
    temp_s4 = &D_800E1F30->unk0[temp_s2 + (temp_s3 * 10)];
    FUN_80050840_fiveliner(&D_800E1F30->unk258, temp_s4->unk2);
    var_s5 = 0;
  }

  for (i = 0; i < 4; i++) {
    temp_s2 = temp_s0->unk0[i] + x;
    temp_s3 = temp_s0->unk4[i] + y;
    temp_s4 = &D_800E1F30->unk0[temp_s2 + (temp_s3 * 10)];
    temp_s4->unk0 = arg3;
    temp_s4->unk1 = (arg3 == 8) ? g_currentPiece_ptr->pieceType : EMPTY_CELL;
    temp_s4->unk2 = var_s5;
  }

  return TRUE;
}

u8 FUN_800416cc_fourliner(u8 arg0, u8 arg1, u8 arg2) {
  register u8 temp_s0;

  temp_s0 = FUN_800413c0_twentyfive_liner(arg0, arg1, arg2, 8);
  if (temp_s0) {
    FUN_800413c0_twentyfive_liner(arg0, arg1, arg2, 7);
  }
  return temp_s0;
}

u8 FUN_8004172c_twentyliner(s8 arg0, s8 arg1, s8 arg2) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;

  currentPiece_ptr->logicalPos.x += arg0;
  currentPiece_ptr->logicalPos.y += arg1;
  currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState + arg2) & 3;

  if (FUN_006B30_800408b0_fiveliner_loops_4t(currentPiece_ptr->logicalPos.y, currentPiece_ptr->logicalRotCkwState, currentPiece_ptr->pieceType)) {
    return TRUE;
  }

  if (!FUN_800416cc_fourliner(currentPiece_ptr->logicalPos.x, currentPiece_ptr->logicalPos.y, currentPiece_ptr->logicalRotCkwState)) {
    currentPiece_ptr->logicalPos.x -= arg0;
    currentPiece_ptr->logicalPos.y -= arg1;
    currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState - arg2) & 3;
    return FALSE;
  }

  return TRUE;
}

u8 FUN_80041810_twentyliner(u8 arg0, u8 arg1, u8 arg2) {
  register s8 temp_s0;
  register s8 temp_s1;
  register s8 temp_s2;
  register u8 ret = FALSE;

  temp_s0 = g_currentPiece_ptr->logicalPos.x;
  temp_s1 = g_currentPiece_ptr->logicalPos.y;
  temp_s2 = g_currentPiece_ptr->logicalRotCkwState;

  g_currentPiece_ptr->logicalPos.x = arg0;
  g_currentPiece_ptr->logicalPos.y = arg1;
  g_currentPiece_ptr->logicalRotCkwState = arg2;

  if ((FUN_8004172c_twentyliner(-1,  0, 0)) ||
      (FUN_8004172c_twentyliner( 1,  0, 0)) ||
      (FUN_8004172c_twentyliner( 0, -1, 0)) ||
      (FUN_8004172c_twentyliner( 0,  1, 0))) {
    ret = TRUE;
  }

  g_currentPiece_ptr->logicalPos.x = temp_s0;
  g_currentPiece_ptr->logicalPos.y = temp_s1;
  g_currentPiece_ptr->logicalRotCkwState = temp_s2;

  return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0074E0/FUN_8004191c_sixliner_loop_shift_right.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0074E0/FUN_8004199c_twentyliner_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0074E0/FUN_80041ab4_tenliner_loop.s")

u8 check_square_completion(u8 arg0, u8 arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
  register u8 var_t0;
  register u8 var_t1;
  register u8 var_t2;
  register u8 var_t3;
  register u8 var_t4;
  register u8 var_t5;
  UnkStruct_27 *spC;
  u8 sp8[4];
  u8 sp4[4];
  u8 sp3;
  u8 sp2;

  if (arg0 > 6 || arg1 > 16) {
    return FALSE;
  }

  sp3 = TRUE;
  *arg2 = FALSE;
  var_t3 = 0;
  var_t5 = 0;
  spC = &D_800E1F30->unk0[arg0 + (arg1 * 10)];
  for (var_t1 = arg1; var_t1 < arg1 + 4; spC += 6, var_t1++) {
    for (var_t0 = arg0; var_t0 < arg0 + 4; var_t0++, spC++) {
      if (spC->unk0 == 10) {
        return FALSE;
      }

      if (spC->unk0 != EMPTY_CELL) {
        if (!sp3 && var_t4 != (u8)spC->unk1) {
          *arg2 = TRUE;
        }
        sp2 = TRUE;
        for (var_t2 = 0; var_t2 < var_t3; var_t2++) {
          if (sp8[var_t2] == spC->unk2) {
            sp4[var_t2]++;
            sp2 = FALSE;
          }
        }
        if (sp2) {
          if (var_t3 == 4) {
            return FALSE;
          }

          sp8[var_t3] = spC->unk2;
          sp4[var_t3] = 1;
          sp3 = FALSE;
          var_t3++;
          var_t4 = spC->unk1;
          var_t5 |= 1 << var_t4;
        }
      }
    }
  }

  for (var_t2 = 0; var_t2 < var_t3; var_t2++) {
    if (sp4[var_t2] < 4) {
      return FALSE;
    }
  }

  *arg3 = var_t3;
  *arg4 = var_t5;
  return TRUE;
}

void FUN_80041da0_threeliner(UnkStruct_27 *arg0, UnkStruct_29 *arg1) {
  arg0->unk0 = arg1->unk0;
  arg0->unk1 = arg1->unk1;
  arg0->unk2 = arg1->unk2;
}
