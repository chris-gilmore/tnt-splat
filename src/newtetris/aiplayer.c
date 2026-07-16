#include "common.h"

u8 D_800E1F50;
static u8 D_800E1F51;
static s8 D_800E1F52;
static u8 D_800E1F53;
static u8 D_800E1F54;
static s8 D_800E1F55;

static u8 D_800C5DF0[15] = {
  0x49, 0x50, 0x0E,  // EASY
  0x49, 0x48, 0x0C,  // MEDIUM
  0x41, 0x40, 0x0A,  // HARD
  0xC1, 0x38, 0x07,  // VERY HARD
  0xC1, 0x30, 0x05,  // MASTER
};

// cheat code "AI2EZ4U?"
static u8 D_800C5E00[3] = {
  0xF1, 0x30, 0x00,
};

UnkStruct_85 *D_800C5E04 = NULL;

static void aiplayer_80042b88_largefunction(void);

void aiplayer_gameinit_related(u8 arg0, u8 arg1, u8 ai_rank) {
  register u8 i;
  register u8 j;
  u8 sp30[4];
  u8 sp2C[4];

  D_800C5E04 = n64HeapAlloc(sizeof(UnkStruct_85));
  if (D_800C5E04 == NULL) {
    return;
  }

  for (i = 0; i < 4; i++) {
    if (arg0 & (1 << i)) {
      sp30[i] = TRUE;
    } else {
      sp30[i] = FALSE;
    }
    sp2C[i] = FALSE;
  }

  for (j = 0; !sp30[j] || sp2C[j]; j++) {}

  D_800C5E04->player_idx = j;

  if (ai_rank == 6) {
    ai_rank = func_800A35EC(0, 4);
  }

  if (ai_rank > 4) {
    debug_print_reason_routine("INVALID AI RANK", "AIPLAYER.C");
  }

  if (D_800E1F50) {  // cheat code "AI2EZ4U?"
    D_800C5E04->unk1 = D_800C5E00[0];
  } else {
    D_800C5E04->unk1 = D_800C5DF0[ai_rank * 3];
  }

  if (arg1 == 2) {
    D_800C5E04->unk1 = D_800C5E04->unk1 & ~8;
  }

  if (D_800E1F50) {  // cheat code "AI2EZ4U?"
    D_800C5E04->unk2 = D_800C5E00[1];
    D_800C5E04->unk3 = D_800C5E00[2];
  } else {
    D_800C5E04->unk2 = D_800C5DF0[ai_rank * 3 + 1];
    D_800C5E04->unk3 = D_800C5DF0[ai_rank * 3 + 2];
  }

  if (arg0 == 1) {
    D_800C5E04->unk1 |= 0x10 | 0x08;
    D_800C5E04->unk3 = 5;
  }

  D_800C5E04->unk4 = 0;

  FUN_005580_8003f760_twoliner_calls_fun(&D_800C5E04->unk5, 0, -1, 4, 6);

  if (D_800C5E04->unk1 & 0x08) {
    aisquarelist_8003e1e0_sevenliner_loops_6t(&D_800C5E04->unk2E);
  }

  FUN_008050_80041dd0_alloc_heap_4_and_x640();

  FUN_004220_8003dfa0_sixliner_allocs_heap_x962();

  D_800E1F52 = 0;
  D_800E1F51 = 0;
  D_800E1F55 = -1;
}

void aiplayer_80042b3c_calls_heap_unalloc(void) {
  if (D_800C5E04 != NULL) {
    FUN_004220_8003e004_threeliner_unallocs_heap();
    FUN_008050_80041e24_maybe_calls_unalloc_heap();
    n64HeapUnalloc(D_800C5E04);
    D_800C5E04 = NULL;
  }
}

static void aiplayer_80042b88_largefunction(void) {
  register u8 var_s0;
  register u8 var_s1;
  register u8 temp_s2;
  register s8 var_s3;
  register s8 var_s4;
  register s16 var_s5;
  register UnkStruct_105 *temp_s6;
  register UnkStruct_108 *temp_s7;
  u8 sp4F;
  u8 sp4E;
  UnkStruct_108 sp48;
  UnkStruct_108 sp44;

  sp4E = FUN_800412e0_fifteenliner_logic_cell(&sp4F);
  var_s0 = sp4E > D_800C5E04->unk2;
  if (!var_s0) {
    if ((sp4F < 7) || (D_800E1F55 != -1)) {
      var_s0 = TRUE;
    }
  }

  D_800E1F53 = sp4F < 4;
  D_800E1F54 = sp4E > 90 || D_800E1F53;

  if (D_800C5E04->unk1 & 0x01) {
    var_s3 = 0;
  } else if (D_800C5E04->unk1 & 0x02) {
    var_s3 = 1;
  } else {
    var_s3 = 2;
  }

  var_s4 = 0;

  if (var_s0) {
    var_s3 = 0;
  }

  sp4F = 0;
  sp4E = g_currentPiece_ptr->pieceType;
  temp_s2 = g_tetris_ptr->pieceHold.buf[g_tetris_ptr->pieceHold.buf_idx].piece_type;
  var_s1 = FALSE;
  FUN_004220_8003e038_twentytwoliner_nested_loops(0, D_800E1F53);
  CurrentPiece_80067dd8_big_fiftyliner(temp_s2);
  FUN_004220_8003e038_twentytwoliner_nested_loops(1, D_800E1F53);
  CurrentPiece_80067dd8_big_fiftyliner(sp4E);

  if ((D_800C5E04->unk1 & 0x08) && !var_s0) {
    var_s1 = FUN_006780_80040500_twentyfiveliner_loops(0, D_800E1F53);
    var_s5 = 0;
    if (var_s1) {
      FUN_008050_800427b8_passes_dat_800e1f40_ptr(var_s4, &sp44);
      var_s5 = (*D_800E1F40)[var_s4].unk0;
    }

    if ((var_s5 != 0x7FFF) && (sp4E != temp_s2)) {
      CurrentPiece_80067dd8_big_fiftyliner(temp_s2);
      if (FUN_006780_80040500_twentyfiveliner_loops(1, D_800E1F53)) {
        if (var_s5 < (*D_800E1F40)[var_s4].unk0) {
          FUN_008050_800427b8_passes_dat_800e1f40_ptr(var_s4, &sp44);
          sp4F = 1;
          var_s1 = TRUE;
        } else {
          CurrentPiece_80067dd8_big_fiftyliner(sp4E);
        }
      } else {
        CurrentPiece_80067dd8_big_fiftyliner(sp4E);
      }
    }
  }

  if (var_s0 || !var_s1) {
    FUN_006BB0_80040f9c_twentyfiveliner_loops_200t(var_s0, 0, D_800E1F55);
    FUN_008050_800427b8_passes_dat_800e1f40_ptr(var_s3, &sp48);
    var_s5 = (*D_800E1F40)[var_s3].unk0;
    if (sp4E != temp_s2) {
      CurrentPiece_80067dd8_big_fiftyliner(temp_s2);
      FUN_006BB0_80040f9c_twentyfiveliner_loops_200t(var_s0, 1, D_800E1F55);
      if (var_s5 < (*D_800E1F40)[var_s3].unk0) {
        FUN_008050_800427b8_passes_dat_800e1f40_ptr(var_s3, &sp48);
        sp4F = 1;
      } else {
        CurrentPiece_80067dd8_big_fiftyliner(sp4E);
      }
    }
  }

  temp_s6 = &D_800C5E04->unk5;
  FUN_005580_8003f760_twoliner_calls_fun(temp_s6, 0, -1, 4, 6);
  temp_s6->unk0 = 1;
  temp_s6->unk1[1].unk3 = 0;
  temp_s7 = &temp_s6->unk1[1].unk0;

  if (var_s1) {
    FUN_80041da0_threeliner(temp_s7, &sp44);
  } else {
    FUN_80041da0_threeliner(temp_s7, &sp48);
  }

  if (D_800C5E04->unk1 & 0x08) {
    FUN_800413c0_twentyfive_liner(temp_s7->unk0, temp_s7->unk1, temp_s7->unk2, 8);
    for (var_s4 = 0; var_s4 < 20; var_s4++) {
      for (var_s3 = 0; var_s3 < 10; var_s3++) {
        if (D_800E1F30->unk0[var_s3 + (var_s4 * 10)].unk0 == EMPTY_CELL) {
          break;
        }
      }
      if (var_s3 == 10) {
        aisquarelist_8003e608_eightliner_loops_arg0_t_2(&D_800C5E04->unk2E, var_s4);
      }
    }
    FUN_800413c0_twentyfive_liner(temp_s7->unk0, temp_s7->unk1, temp_s7->unk2, 7);
  }

  var_s3 = g_currentPiece_ptr->logicalPos.x;
  var_s4 = g_currentPiece_ptr->logicalPos.y;
  var_s5 = g_currentPiece_ptr->logicalRotCkwState;
  FUN_005580_800400fc_largefun_more_currpiece_stuff(temp_s6, D_800E1F53);
  g_currentPiece_ptr->logicalPos.x = var_s3;
  g_currentPiece_ptr->logicalPos.y = var_s4;
  g_currentPiece_ptr->logicalRotCkwState = var_s5;

  if (sp4F != 0) {
    CurrentPiece_80067dd8_big_fiftyliner(sp4E);
    temp_s6->unk0++;
    temp_s6->unk1[temp_s6->unk0].unk3 = 5;
    temp_s6->unk1[temp_s6->unk0].unk0.unk0 = sp4E;
  }
}

void aiplayer_8004311c_largefunction(void) {
  register s8 temp_s0;
  register UnkStruct_98 *temp_s1;
  register s16 temp_s2;
  register UnkStruct_1 *temp_s3 = &g_PV_ptr->unk28;

  if ((D_800C5E04 != NULL) && (&g_PV_arr[D_800C5E04->player_idx] == g_PV_ptr) && g_game.tetris_ptr_arr[D_800C5E04->player_idx]->unk2) {
    if (D_800C5E04->unk4 == 0) {
      return;
    }

    if (D_800C5E04->unk4 == 1) {
      aiplayer_80042b88_largefunction();
      D_800C5E04->unk4 = 2;
    }

    // START_BUTTON / CONT_START
    if ((temp_s3->unk88 != 0x1000) && (temp_s3->unk8C != 0x1000)) {
      FUN_026C80_nineliner_loops_32t(temp_s3);
    }

    temp_s1 = &D_800C5E04->unk5.unk1[D_800C5E04->unk5.unk0];
    if (D_800E1F51 < D_800C5E04->unk3) {
      D_800E1F51 += frametime_delta();
      return;
    }
    D_800E1F51 = 0;

    temp_s2 = g_currentPiece_ptr->fallVelocityCopy;
    switch (temp_s1->unk3) {
    case 5:
      if ((g_currentPiece_ptr->state == 1) && (g_currentPiece_ptr->pieceType == temp_s1->unk0.unk0)) {
        PieceHold_Swap(&g_tetris_ptr->pieceHold, g_currentPiece_ptr);
      } else if (g_currentPiece_ptr->state == 1) {
        D_800C5E04->unk5.unk0--;
      }
      break;
    case 6:
      if (D_800E1F54 || (D_800C5E04->unk1 & 0x10)) {
        // pressing Up (drop the piece to the bottom)
        CurrentPiece_800676ac_fourliner_looper(g_currentPiece_ptr);
      } else if ((temp_s2 < 0x3C) && (g_currentPiece_ptr->logicalPos.y < temp_s1->unk0.unk1)) {
        if (D_800C5E04->unk1 & 0x20) {
          g_currentPiece_ptr->fallVelocity = 0x100;
        } else if (D_800C5E04->unk1 & 0x40) {
          g_currentPiece_ptr->fallVelocityCopy = 0x40;
          g_currentPiece_ptr->fallVelocity = g_currentPiece_ptr->fallVelocityCopy;
        }
      }
      break;
    case 0:
      if ((temp_s2 < 0x3C) && (D_800E1F54 || (D_800C5E04->unk1 & 0x40)) && (g_currentPiece_ptr->logicalPos.y < temp_s1->unk0.unk1)) {
        g_currentPiece_ptr->fallVelocityCopy = 0x40;
        g_currentPiece_ptr->fallVelocity = g_currentPiece_ptr->fallVelocityCopy;
      } else if (g_currentPiece_ptr->logicalPos.y >= temp_s1->unk0.unk1) {
        D_800C5E04->unk5.unk0--;
      }
      break;
    case 1:
      temp_s0 = temp_s1->unk0.unk0 - g_currentPiece_ptr->logicalPos.x;
      if ((D_800E1F54 || (D_800C5E04->unk1 & 0x80)) && (temp_s0 > 1)) {
        CurrentPiece_80067254_twelveliner_plays_SFX(g_currentPiece_ptr);  // RIGHT
        CurrentPiece_80067254_twelveliner_plays_SFX(g_currentPiece_ptr);  // RIGHT
      } else if (temp_s0 > 0) {
        CurrentPiece_80067254_twelveliner_plays_SFX(g_currentPiece_ptr);  // RIGHT
      } else {
        D_800C5E04->unk5.unk0--;
      }
      break;
    case 2:
      temp_s0 = g_currentPiece_ptr->logicalPos.x - temp_s1->unk0.unk0;
      if ((D_800E1F54 || (D_800C5E04->unk1 & 0x80)) && (temp_s0 > 1)) {
        CurrentPiece_8006715c_twelveliner_plays_SFX(g_currentPiece_ptr);  // LEFT
        CurrentPiece_8006715c_twelveliner_plays_SFX(g_currentPiece_ptr);  // LEFT
      } else if (temp_s0 > 0) {
        CurrentPiece_8006715c_twelveliner_plays_SFX(g_currentPiece_ptr);  // LEFT
      } else {
        D_800C5E04->unk5.unk0--;
      }
      break;
    case 3:
      if (g_currentPiece_ptr->logicalRotCkwState != temp_s1->unk0.unk2) {
        CurrentPiece_8006734c_thirtyliner_looks_interesting(g_currentPiece_ptr, 1);  // clockwise
      } else {
        D_800C5E04->unk5.unk0--;
      }
      break;
    case 4:
      if (g_currentPiece_ptr->logicalRotCkwState != temp_s1->unk0.unk2) {
        CurrentPiece_8006734c_thirtyliner_looks_interesting(g_currentPiece_ptr, -1);  // counterclockwise
      } else {
        D_800C5E04->unk5.unk0--;
      }
      break;
    }
  }
}

void aiplayer_8004370c_threeliner(void) {
  if ((D_800C5E04 == NULL) || &g_PV_arr[D_800C5E04->player_idx] != g_PV_ptr) {
    return;
  }

  D_800C5E04->unk4 = 1;
}

void aiplayer_8004376c_fiveliner(void) {
  if (D_800C5E04 != NULL) {
    if (&g_PV_arr[D_800C5E04->player_idx] != g_PV_ptr) {
      D_800E1F55 = -1;
      return;
    }

    D_800E1F55 = g_game.tetris_ptr_arr[D_800C5E04->player_idx]->garbage_ptr->pad0[0x15];
  }
}
