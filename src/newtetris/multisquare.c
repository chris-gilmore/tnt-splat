#include "common.h"

Squares *g_squares_ptr;

static Square  *Multisquare_8006a050_extralarge_manyloops_interesting(s32, s32, u8);
static void     Multisquare_8006a3ec_twoliner(Square *);
static s32      Multisquares_Test4x4byType(s32, s32, u8);
static s32      Multisquare_8006a6bc_oneliner_calls_fun(Cell *);
static void     Multisquare_8006a6f0_threeliner_sets_arg0_stuff(Squares *);
static void     Multisquare_8006a708_fiveliner_sets_arg0_stuff(Squares *);
static void     MultisquareGlow_8006a740_thirtyfiveliner(Squares *);
static void     func_8006A9A4(Squares *);  // unused
static void     MultisquareGlow_8006a9bc_fiveliner_sets_arg0_struct(Squares *);
static void     MultisquareGlow_8006a9f4_twentyliner_loops_t7_t17(Squares *);
static s32      MultisquareGlow_8006aba4_loops_44_times_1(void);
static void     MultisquareGlow_8006abf4_loops_44_times_2(void);

static Square *Multisquare_8006a050_extralarge_manyloops_interesting(s32 x, s32 y, u8 square_type) {
  register Square *square_ptr;
  Color color;
  register s32 i;
  Point sp70;
  PointAngle sp68;
  register s32 col;
  register s32 row;
  register u8 square_id;
  register Cell *temp_s5;
  register Cell *temp_s6;
  register Cell **var_s7;
  s32 sp4C;
  s32 sp48;
  s32 sp44;
  s32 sp40;

  for (i = 0, square_ptr = g_squares_ptr->arr; square_ptr->type != SQUARETYPE_NONE && i < 44; square_ptr++, i++);
  if (i == 44) {
    debug_print_reason_routine("Multisquares:", "Out of multisquares");
  }

  square_ptr->type = square_type;
  switch (square_type) {
  case SQUARETYPE_MONO:
    color = g_color_gold;
    break;
  case SQUARETYPE_MULTI:
    color = g_color_silver;
    break;
  }

  setPointAngle(sp68, (x << 8) - 0x80, (y << 8) - 0x80, 0);
  Minos_80071100_fiveliner_nuts2(&sp70, &sp68);
  MultisquareGlow_Init(&square_ptr->glow, sp70, D_8011FC10->unk2 >> 8);
  square_id = square_ptr->id;
  for (row = y; row < y + 4; row++) {
    for (col = x; col < x + 4; col++) {
      temp_s5 = g_boardPieces_ptr->cell_ptr_arr[col + (row * 10)];
      temp_s5->square_id = square_id;
      temp_s5->cubeInfo.cube_ptr->mino.unk22 = (0xFF - temp_s5->cubeInfo.cube_ptr->mino.unk20.s) / 16;
      Minos_80070860_fortyliner(&temp_s5->cubeInfo.cube_ptr->mino, &color, 16);
    }
  }

  var_s7 = &g_boardPieces_ptr->cell_ptr_arr[x + (y * 10)];
  temp_s6 = *var_s7;
  sp48 = 4;
  do {
    sp4C = 4;
    do {
      BoardP_8006d450_fourteenliner_pf_logic_cell_loops(temp_s6, *var_s7);
      sp44 = (*var_s7)->cubeInfo.pos.x;
      sp40 = (*var_s7)->cubeInfo.pos.y;
      BoardP_8006e64c_calls_UpdateQueue_AddEntry(sp44, sp40);
      var_s7++;
    } while (--sp4C > 0);
    var_s7 += 6;
  } while (--sp48 > 0);

  square_ptr->unk1 = 16;
  g_squares_ptr->cnt++;

  if (square_type == SQUARETYPE_MULTI) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 3);
  } else if (square_type == SQUARETYPE_MONO) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 3);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 4);
  }

  return square_ptr;
}

static void Multisquare_8006a3ec_twoliner(Square *square_ptr) {
  square_ptr->type = SQUARETYPE_NONE;
  g_squares_ptr->cnt--;
}

void Multisquare_8006a410_fourliner(Square *square_ptr, u8 *cell_id_ptr) {
  if (square_ptr->type == SQUARETYPE_NONE) {
    return;
  }

  square_ptr->unk1--;
  if (square_ptr->unk1 == 0) {
    Multisquare_8006a3ec_twoliner(square_ptr);
  }
}

Color *Multisquare_pGetColor(Square *square_ptr) {
  switch (square_ptr->type) {
  case SQUARETYPE_MULTI:
    return &g_color_silver;
  case SQUARETYPE_MONO:
    return &g_color_gold;
  default:
    debug_print_reason_routine("Multisquare:pGetColor", "invalid type, multisquare.c");
  }
}

static s32 Multisquares_Test4x4byType(s32 x, s32 y, u8 piece_type) {
  register s32 i;
  register Cell **cell_ptr_ptr;
  register Cell *cell_ptr;
  register u8 is_monosquare;
  u8 piece_ids[4];
  register u8 *piece_id_ptr;
  register u8 piece_id;

  if (x < 0 || y < 0 || x >= 7 || y >= 17) {
    debug_print_reason_routine("Multisquares_Test4x4byType()", "Bad x,y");
  }

  piece_id_ptr = piece_ids;
  for (i = 4; i > 0; i--) {
    *piece_id_ptr++ = 0;
  }

  is_monosquare = TRUE;
  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[x + (y * 10)];
  for (y = 4; y > 0; y--) {
    for (x = 4; x > 0; x--) {
      cell_ptr = *cell_ptr_ptr;
      if (cell_ptr->properties & 3) {
        return SQUARETYPE_NONE;
      }
      if (cell_ptr->square_id != 0xFF) {
        return SQUARETYPE_NONE;
      }
      if (cell_ptr->piece_type != piece_type) {
        is_monosquare = FALSE;
      }
      piece_id = cell_ptr->piece_id;
      for (i = 0;;) {
        if (piece_ids[i] == 0) {
          piece_ids[i] = piece_id;
          break;
        }
        if (piece_ids[i] == piece_id) {
          break;
        }
        if (++i == 4) return SQUARETYPE_NONE;
      }
      cell_ptr_ptr++;
    }
    cell_ptr_ptr += 6;
  }

  if (is_monosquare) return SQUARETYPE_MONO;  // monosquare (gold)
  return SQUARETYPE_MULTI;                    // multisquare (silver)
}

static s32 Multisquare_8006a6bc_oneliner_calls_fun(Cell *cell_ptr) {
  return Multisquares_Test4x4byType(cell_ptr->cubeInfo.pos.x, cell_ptr->cubeInfo.pos.y, cell_ptr->piece_type);
}

static void Multisquare_8006a6f0_threeliner_sets_arg0_stuff(Squares *squares_ptr) {
  squares_ptr->delay = 45;  // square formation delay
  squares_ptr->unk0 = 2;
  squares_ptr->unk1 = 0;
}

static void Multisquare_8006a708_fiveliner_sets_arg0_stuff(Squares *squares_ptr) {
  if (squares_ptr->delay == 0) {
    squares_ptr->unk0 = 0;
    squares_ptr->unk1 = 2;
    return;
  }

  squares_ptr->unk1 = 0;
  squares_ptr->delay--;
}

static void MultisquareGlow_8006a740_thirtyfiveliner(Squares *arg0) {
  BoundingBox unused;
  BoundingBox sp30;
  s16 sp2E;
  s16 sp2C;
  s16 sp2A;
  s16 sp28;
  s32 x;
  s32 y;
  u8 square_type;

  CurrentPiece_80067c1c_fifteenliner_loops3times(g_currentPiece_ptr, &sp30);
  sp28 = sp30.x_max - 3;
  sp2A = sp30.y_max - 3;
  sp2C = sp30.x_min;
  sp2E = sp30.y_min;
  if (sp28 < 0) sp28 = 0;
  if (sp2C > 6) sp2C = 6;
  if (sp2A < 0) sp2A = 0;
  if (sp2E > 16) sp2E = 16;

  for (y = sp2A; y <= sp2E; y++) {
    for (x = sp28; x <= sp2C; x++) {
      square_type = Multisquares_Test4x4byType(x, y, g_currentPiece_ptr->pieceType);
      if (square_type == SQUARETYPE_MONO) break;
    }
    if (square_type == SQUARETYPE_MONO) break;
  }
  if (square_type == SQUARETYPE_MONO) {
    Multisquare_8006a050_extralarge_manyloops_interesting(x, y, SQUARETYPE_MONO);
    Multisquare_8006a6f0_threeliner_sets_arg0_stuff(arg0);
    return;
  }

  for (y = sp2A; y <= sp2E; y++) {
    for (x = sp28; x <= sp2C; x++) {
      square_type = Multisquares_Test4x4byType(x, y, g_currentPiece_ptr->pieceType);
      if (square_type == SQUARETYPE_MULTI) break;
    }
    if (square_type == SQUARETYPE_MULTI) break;
  }
  if (square_type == SQUARETYPE_MULTI) {
    Multisquare_8006a050_extralarge_manyloops_interesting(x, y, SQUARETYPE_MULTI);
    Multisquare_8006a6f0_threeliner_sets_arg0_stuff(arg0);
    return;
  }

  arg0->unk1 = 1;
}

// unused
static void func_8006A9A4(Squares *squares_ptr) {
  squares_ptr->delay = 45;
  squares_ptr->unk0 = 4;
  squares_ptr->unk1 = 0;
}
  
static void MultisquareGlow_8006a9bc_fiveliner_sets_arg0_struct(Squares *arg0) {
  if (arg0->delay == 0) {
    arg0->unk0 = 0;
    arg0->unk1 = 3;
    return;
  }

  arg0->unk1 = 0;
  arg0->delay--;
}

static void MultisquareGlow_8006a9f4_twentyliner_loops_t7_t17(Squares *arg0) {
  register Cell *cell_ptr;
  register s32 col;
  register s32 row;

  for (row = 0; row < 17; row++) {
    for (col = 0; col < 7; col++) {
      cell_ptr = g_boardPieces_ptr->cell_ptr_arr[col + (row * 10)];
      if (cell_ptr->piece_type != EMPTY_CELL &&
          cell_ptr->square_id == 0xFF &&
          Multisquare_8006a6bc_oneliner_calls_fun(cell_ptr) == SQUARETYPE_MONO) {
        Multisquare_8006a050_extralarge_manyloops_interesting(col, row, SQUARETYPE_MONO);
      }
    }
  }

  for (row = 0; row < 17; row++) {
    for (col = 0; col < 7; col++) {
      cell_ptr = g_boardPieces_ptr->cell_ptr_arr[col + (row * 10)];
      if (cell_ptr->piece_type != EMPTY_CELL &&
          cell_ptr->square_id == 0xFF &&
          Multisquare_8006a6bc_oneliner_calls_fun(cell_ptr) == SQUARETYPE_MULTI) {
        Multisquare_8006a050_extralarge_manyloops_interesting(col, row, SQUARETYPE_MULTI);
      }
    }
  }

  arg0->unk1 = 3;
}

u8 MultisquareGlow_isArg0_lessthan_44(u32 arg0) {
  if (arg0 < 44) {
    return TRUE;
  }

  return FALSE;
}

static s32 MultisquareGlow_8006aba4_loops_44_times_1(void) {
  register Squares *squares_ptr = g_squares_ptr;
  register Square *square_ptr;
  register u32 i;
  register s32 var_a3;

  var_a3 = 0;
  square_ptr = squares_ptr->arr;
  for (i = 0; i < 44; i++, square_ptr++) {
    if (square_ptr->unk3) {
      var_a3++;
    }
  }
  return var_a3;
}

static void MultisquareGlow_8006abf4_loops_44_times_2(void) {
  register Squares *squares_ptr = g_squares_ptr;
  register Square *square_ptr;
  register u32 i;

  square_ptr = squares_ptr->arr;
  for (i = 0; i < 44; i++, square_ptr++) {
    square_ptr->unk3 = FALSE;
  }
}

s32 MultisquareGlow_8006ac2c_loops_10_times(s32 row, s32 type) {
  register Cell **cell_ptr_ptr;
  register Cell *cell_ptr;
  register Square *square_ptr;
  register s32 col;
  register u8 square_id;

  MultisquareGlow_8006abf4_loops_44_times_2();
  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[row * 10];
  for (col = 0; col < 10; col++) {
    cell_ptr = *cell_ptr_ptr;
    square_id = cell_ptr->square_id;
    if (MultisquareGlow_isArg0_lessthan_44(square_id)) {
      square_ptr = &g_squares_ptr->arr[square_id];
      if (square_ptr->type == type) {
        square_ptr->unk3 = TRUE;
      }
    }
    cell_ptr_ptr++;
  }
  return MultisquareGlow_8006aba4_loops_44_times_1();
}

u8 MultisquareGlow_8006ad0c_checks_1_2_3_4(void) {
  register Squares *squares_ptr = g_squares_ptr;

  switch (squares_ptr->unk0) {
  case 1:
    // either sets unk1 to 1 or 0
    MultisquareGlow_8006a740_thirtyfiveliner(squares_ptr);
    break;
  case 2:
    // sets unk1 to either 2 or 0
    Multisquare_8006a708_fiveliner_sets_arg0_stuff(squares_ptr);
    break;
  case 3:
    // sets unk1 to 3
    MultisquareGlow_8006a9f4_twentyliner_loops_t7_t17(squares_ptr);
    break;
  case 4:
    // sets unk1 to either 3 or 0
    MultisquareGlow_8006a9bc_fiveliner_sets_arg0_struct(squares_ptr);
    break;
  }
  return squares_ptr->unk1;
}

void MultisquareGlow_8006ada4_Init2(void) {
  register Squares *squares_ptr = g_squares_ptr;
  register Square *square_ptr;
  register u32 i;

  squares_ptr->cnt = 0;
  square_ptr = squares_ptr->arr;
  for (i = 0; i < 44; i++, square_ptr++) {
    square_ptr->id = i;
    square_ptr->type = SQUARETYPE_NONE;
  }
}

void MultisquareGlow_Deinit_doesnothing(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/Multisquares_UpdateGlows.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/Multisquares_RenderGlows.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/multisquare/MultisquareGlow_8006aebc_loops_44_times_4.s")
