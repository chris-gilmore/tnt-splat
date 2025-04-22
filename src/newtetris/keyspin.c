#include "common.h"

UnkStruct_9 *D_8011FBC0;

static void   KeySpin_8006b3b0_tenliner_nested_loop_10t(UnkStruct_37 *);
static void   KeySpin_8006b454_fourliner_sets_arg0_struct(UnkStruct_37 *);
static void   KeySpin_8006b478_eightliner(UnkStruct_37 *, s32);
static void   KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(UnkStruct_36 *, s32);
static void   KeySpin_8006b608_uses_pf_logic_cell_loops_10t_2(UnkStruct_36 *, s32);
static void   KeySpin_8006b6b4_twelveliner_ifs_elses_1(UnkStruct_36 *, s32);
static void   KeySpin_8006b7b4_twelveliner_ifs_elses_2(UnkStruct_36 *, s32);
static void   KeySpin_8006b8b8_fiveliner_calls_b6b4_b7b4(UnkStruct_36 *, s32);
static void   KeySpin_8006b938_thirteenliner_sets_arg0_struct(UnkStruct_36 *, s32, s32, s32, s32);
static void   KeySpin_8006ba24_thirtysixliner_sets_arg0_struct(UnkStruct_19 *, s16, CurrentPiece *);
static void   KeySpin_8006bc8c_twelveliner_uses_pf_logic_cell_1(UnkStruct_19 *, s32);
static void   KeySpin_8006bd94_twelveliner_uses_pf_logic_cell_2(UnkStruct_19 *, s32);
static void   KeySpin_8006be9c_fifteenliner_uses_pflcell_loopts_10t(UnkStruct_19 *);
static void   KeySpin_8006BF90(UnkStruct_19 *, s32);
static void   KeySpin_8006c09c_tenliner_loops_lcv_arg0_unk58(UnkStruct_9 *);
static void   KeySpin_8006c160_twentyfiveliner_loops_lcv_arg0_unk58(UnkStruct_9 *, s32);
static void   KeySpin_InitVPulse(UnkStruct_9 *);
static void   KeySpin_8006c5c4_sevenliner_sets_arg0_struct_1(UnkStruct_9 *, s32);
static void   KeySpin_8006c644_fourliner_sets_arg0_struct(UnkStruct_9 *);
static void   KeySpin_8006c690_sevenliner_sets_arg0_struct_2(UnkStruct_9 *, s32);
static u8     KeySpin_8006c710_medliner_interesting_calls_pf_xy_to_lgc(UnkStruct_9 *);
static void   KeySpin_8006ca90_nineliner_sets_arg0_struct(UnkStruct_9 *);

static void KeySpin_8006b3b0_tenliner_nested_loop_10t(UnkStruct_37 *arg0) {
  register s32 unused;
  register s32 x;
  register s32 y;

  for (x = 0; x < 10; x++) {
    for (y = arg0->unk1; BoardP_IsPositionEmpty(x, y + 1); y++);
    if (y != arg0->unk1) {
      BoardPieces_SwapCubes(x, arg0->unk1, x, y);
    }
  }
}

static void KeySpin_8006b454_fourliner_sets_arg0_struct(UnkStruct_37 *arg0) {
  arg0->unk0 = TRUE;
  arg0->unk1 = arg0->unk5;
  arg0->unk2 = arg0->unk5;
  arg0->unk3 = 4;
}

static void KeySpin_8006b478_eightliner(UnkStruct_37 *arg0, s32 arg1) {
  if (!arg0->unk0) {
    return;
  }

  if (arg0->unk3 > arg1) {
    arg0->unk3 -= arg1;
    return;
  }

  arg0->unk3 += 4 - arg1;
  arg0->unk1--;
  if (arg0->unk1 < arg0->unk4) {
    arg0->unk0 = FALSE;
    return;
  }

  KeySpin_8006b3b0_tenliner_nested_loop_10t(arg0);
}

static void KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(UnkStruct_36 *arg0, s32 arg1) {
  register Cell **cell_ptr_ptr;
  register Cell *cell_ptr;
  register s32 i;

  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[arg1 * 10];
  for (i = 10; i > 0; i--) {
    cell_ptr = *cell_ptr_ptr;
    if (cell_ptr->piece_type != EMPTY_CELL) {
      BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(cell_ptr);
      Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, &g_color_white, 8);
      cell_ptr->cubeInfo.cube_ptr->mino.unk22 = -cell_ptr->cubeInfo.cube_ptr->mino.unk20.s / 8;
    }
    cell_ptr_ptr++;
  }
}

static void KeySpin_8006b608_uses_pf_logic_cell_loops_10t_2(UnkStruct_36 *arg0, s32 arg1) {
  register Cell **cell_ptr_ptr;
  register Cell *cell_ptr;
  register Color *p_color;
  register s32 i;

  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[arg1 * 10];
  for (i = 10; i > 0; i--) {
    cell_ptr = *cell_ptr_ptr;
    if (cell_ptr->piece_type != EMPTY_CELL) {
      p_color = BoardP_8006d3c0_fourliner(cell_ptr);
      Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, p_color, 8);
    }
    cell_ptr_ptr++;
  }
}

static void KeySpin_8006b6b4_twelveliner_ifs_elses_1(UnkStruct_36 *arg0, s32 arg1) {
  if (!arg0->unk3) {
    return;
  }

  if (arg0->unk5 > arg1) {
    arg0->unk5 -= arg1;
    return;
  }

  arg0->unk5 += 6 - arg1;
  arg0->unk1--;
  if (arg0->unk1 == -3) {
    arg0->unk3 = FALSE;
    return;
  }

  if (arg0->unk1 >= 0) {
    KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(arg0, arg0->unk1);
  }

  if (arg0->unk7 >= arg0->unk1 + 2) {
    KeySpin_8006b608_uses_pf_logic_cell_loops_10t_2(arg0, arg0->unk1 + 2);
  }
}

static void KeySpin_8006b7b4_twelveliner_ifs_elses_2(UnkStruct_36 *arg0, s32 arg1) {
  if (!arg0->unk4) {
    return;
  }

  if (arg0->unk6 > arg1) {
    arg0->unk6 -= arg1;
    return;
  }

  arg0->unk6 += 6 - arg1;
  arg0->unk2++;
  if (arg0->unk2 == 22) {
    arg0->unk4 = FALSE;
    return;
  }

  if (arg0->unk2 < 20) {
    KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(arg0, arg0->unk2);
  }

  if (arg0->unk8 <= arg0->unk2 - 2) {
    KeySpin_8006b608_uses_pf_logic_cell_loops_10t_2(arg0, arg0->unk2 - 2);
  }
}

static void KeySpin_8006b8b8_fiveliner_calls_b6b4_b7b4(UnkStruct_36 *arg0, s32 arg1) {
  if (!arg0->unk0) {
    return;
  }

  KeySpin_8006b6b4_twelveliner_ifs_elses_1(arg0, arg1);
  KeySpin_8006b7b4_twelveliner_ifs_elses_2(arg0, arg1);
  if (!arg0->unk3 && !arg0->unk4) {
    arg0->unk0 = FALSE;
  }
}

static void KeySpin_8006b938_thirteenliner_sets_arg0_struct(UnkStruct_36 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
  arg0->unk0 = TRUE;

  arg0->unk3 = arg1;
  arg0->unk1 = arg2;
  arg0->unk7 = arg2;
  arg0->unk5 = 6;

  arg0->unk4 = arg3;
  arg0->unk2 = arg4;
  arg0->unk8 = arg4;
  arg0->unk6 = 6;

  if (arg1) {
    KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(arg0, arg2);
  }

  if (arg3) {
    KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1(arg0, arg4);
  }
}

static void KeySpin_8006ba24_thirtysixliner_sets_arg0_struct(UnkStruct_19 *arg0, s16 y, CurrentPiece *p_curpiece) {
  register s32 i;
  register s8 x;
  register Cell **cell_ptr_ptr;

  arg0->unk0 = TRUE;
  arg0->unk1 = FALSE;
  arg0->unk2 = y;
  arg0->unk3 = 10;
  arg0->unk4 = -1;
  for (i = 0; i < 4; i++) {
    if (p_curpiece->minoLockedPos_arr[i].y == y) {
      arg0->unk0 = FALSE;
      x = p_curpiece->minoLockedPos_arr[i].x;
      if (x < arg0->unk3) {
        arg0->unk3 = x;
      }
      if (arg0->unk4 < x) {
        arg0->unk4 = x;
      }
    }
  }
  if (arg0->unk0) {
    return;
  }

  arg0->unk1 = FALSE;

  arg0->unk6 = (arg0->unk3 << 8) + 0x80;
  arg0->unkA = (-0x100 - arg0->unk6) / 30;
  arg0->unkE = arg0->unk3;
  arg0->unk10 = TRUE;
  arg0->unk12 = FALSE;

  arg0->unk8 = (arg0->unk4 << 8) + 0x80;
  arg0->unkC = (0xA00 - arg0->unk8) / 30;
  arg0->unkF = arg0->unk4;
  arg0->unk11 = TRUE;
  arg0->unk13 = FALSE;

  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[arg0->unk3 + (arg0->unk2 * 10)];
  for (i = arg0->unk3; i <= arg0->unk4; i++) {
    Minos_80070860_fortyliner(&(*cell_ptr_ptr)->cubeInfo.cube_ptr->mino, &g_color_white, 8);
    cell_ptr_ptr++;
  }
}

static void KeySpin_8006bc8c_twelveliner_uses_pf_logic_cell_1(UnkStruct_19 *arg0, s32 arg1) {
  register Cell *cell_ptr;
  register s32 unused;
  register s32 temp_t5;

  if (!arg0->unk10) {
    return;
  }

  arg0->unk6 += arg0->unkA * arg1;  // source of the pause-spin bug
  temp_t5 = arg0->unk6 >> 8;
  if (arg0->unkE != temp_t5) {
    arg0->unkE = temp_t5;

    if (temp_t5 == -1) {
      arg0->unk12 = TRUE;
      arg0->unk10 = FALSE;
      return;
    }

    cell_ptr = g_boardPieces_ptr->cell_ptr_arr[temp_t5 + (arg0->unk2 * 10)];
    if (cell_ptr->piece_type == EMPTY_CELL) {
      arg0->unk12 = FALSE;
      arg0->unk10 = FALSE;
      return;
    }

    Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, &g_color_white, 8);
  }
}

static void KeySpin_8006bd94_twelveliner_uses_pf_logic_cell_2(UnkStruct_19 *arg0, s32 arg1) {
  register Cell *cell_ptr;
  register s32 unused;
  register s32 temp_t5;

  if (!arg0->unk11) {
    return;
  }

  arg0->unk8 += arg0->unkC * arg1;  // source of the pause-spin bug
  temp_t5 = arg0->unk8 >> 8;
  if (arg0->unkF != temp_t5) {
    arg0->unkF = temp_t5;

    if (temp_t5 == 10) {
      arg0->unk13 = TRUE;
      arg0->unk11 = FALSE;
      return;
    }

    cell_ptr = g_boardPieces_ptr->cell_ptr_arr[temp_t5 + (arg0->unk2 * 10)];
    if (cell_ptr->piece_type == EMPTY_CELL) {
      arg0->unk13 = FALSE;
      arg0->unk11 = FALSE;
      return;
    }

    Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, &g_color_white, 8);
  }
}

static void KeySpin_8006be9c_fifteenliner_uses_pflcell_loopts_10t(UnkStruct_19 *arg0) {
  register Cell **cell_ptr_ptr;
  register Cell *cell_ptr;
  register Color *p_color;
  register s32 i;

  arg0->unk0 = TRUE;
  arg0->unk1 = FALSE;
  arg0->unk10 = FALSE;
  arg0->unk12 = FALSE;
  arg0->unk11 = FALSE;
  arg0->unk13 = FALSE;
  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[arg0->unk2 * 10];
  for (i = 0; i < 10; i++) {
    cell_ptr = *cell_ptr_ptr;
    if (cell_ptr->piece_type != EMPTY_CELL) {
      p_color = BoardP_8006d3c0_fourliner(cell_ptr);
      Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, p_color, 16);
    }
    cell_ptr_ptr++;
  }
}

static void KeySpin_8006BF90(UnkStruct_19 *arg0, s32 arg1) {
  if (arg0->unk0) {
    return;
  }

  KeySpin_8006bc8c_twelveliner_uses_pf_logic_cell_1(arg0, arg1);
  KeySpin_8006bd94_twelveliner_uses_pf_logic_cell_2(arg0, arg1);
  if ((!arg0->unk10 && !arg0->unk12) || (!arg0->unk11 && !arg0->unk13)) {
    KeySpin_8006be9c_fifteenliner_uses_pflcell_loopts_10t(arg0);
  }
  if ((!arg0->unk10 && arg0->unk12) && (!arg0->unk11 && arg0->unk13)) {
    arg0->unk0 = TRUE;
    arg0->unk1 = TRUE;
  }
}

static void KeySpin_8006c09c_tenliner_loops_lcv_arg0_unk58(UnkStruct_9 *arg0) {
  register s32 i;
  register s32 y;

  y = CurrentPiece_80067bc0_sixliner_loops4times(arg0->currentPiece_ptr);
  arg0->unk58 = 4;
  for (i = 0; i < arg0->unk58; i++) {
    KeySpin_8006ba24_thirtysixliner_sets_arg0_struct(&arg0->unk8[i], y + i, arg0->currentPiece_ptr);
  }
  arg0->unk0 = 4;
  arg0->unk1 = 0;
  arg0->unk2 = 0;
}

static void KeySpin_8006c160_twentyfiveliner_loops_lcv_arg0_unk58(UnkStruct_9 *arg0, s32 arg1) {
  register s32 i;
  register s32 flag_0;
  register s32 flag_1;

  for (i = 0; i < arg0->unk58; i++) {
    KeySpin_8006BF90(&arg0->unk8[i], arg1);
  }

  flag_0 = TRUE;
  for (i = 0; i < arg0->unk58; i++) {
    if (!arg0->unk8[i].unk0) {
      flag_0 = FALSE;
    }
  }
  if (flag_0) {
    flag_1 = FALSE;
    for (i = 0; i < arg0->unk58; i++) {
      if (arg0->unk8[i].unk1) {
        flag_1 = TRUE;
      }
    }
    if (flag_1) {
      arg0->unk0 = 5;
      arg0->unk1 = 0;
      arg0->unk2 = 1;
      return;
    }

    arg0->unk0 = 0;
    arg0->unk1 = 1;
    arg0->unk2 = 1;
    return;
  }

  arg0->unk1 = 0;
  arg0->unk2 = 1;
}

static void KeySpin_InitVPulse(UnkStruct_9 *arg0) {
  register s32 temp_s0;
  register s32 temp_s1;
  register s32 var_s2;
  register s32 var_s3;
  register s32 var_s4;
  register s32 var_s5;

  temp_s0 = CurrentPiece_80067d1c_twoliner(arg0->currentPiece_ptr);
  temp_s1 = CurrentPiece_80067bc0_sixliner_loops4times(arg0->currentPiece_ptr);
  var_s2 = FALSE;
  var_s3 = FALSE;
  switch (temp_s0) {
  case 1:
    var_s3 = TRUE;
    var_s5 = temp_s1;
    break;
  case 2:
    if (arg0->unk8[0].unk1) {
      var_s2 = TRUE;
      var_s4 = temp_s1;
    }
    if (arg0->unk8[1].unk1) {
      var_s3 = TRUE;
      var_s5 = temp_s1 + 1;
    }
    break;
  case 3:
    if (arg0->unk8[0].unk1) {
      var_s2 = TRUE;
      var_s4 = temp_s1;
    }
    if (arg0->unk8[2].unk1) {
      var_s3 = TRUE;
      var_s5 = temp_s1 + 2;
    }
    if (arg0->unk8[1].unk1) {
      var_s3 = TRUE;
      var_s5 = temp_s1 + 1;
    }
    break;
  case 4:
    if (arg0->unk8[0].unk1) {
      var_s2 = TRUE;
      var_s4 = temp_s1;
    }
    if (arg0->unk8[1].unk1) {
      var_s2 = TRUE;
      var_s4 = temp_s1 + 1;
    }
    if (arg0->unk8[3].unk1) {
      var_s3 = TRUE;
      var_s5 = temp_s1 + 3;
    }
    if (arg0->unk8[2].unk1) {
      var_s3 = TRUE;
      var_s5 = temp_s1 + 2;
    }
    break;
  default:
    debug_print_reason_routine("KeySpin:InitVPulse", "keyspin.c");
    break;
  }

  KeySpin_8006b938_thirteenliner_sets_arg0_struct(&arg0->unk59, var_s2, var_s4, var_s3, var_s5);
  if (var_s2 && var_s3) {
    arg0->unk62.unk4 = BoardP_8006dcd0_eightliner_loops_upto_19_times_increment();
    arg0->unk62.unk5 = BoardP_8006dd1c_eightliner_loops_upto_19_times_decrement();
  } else if (var_s2) {
    arg0->unk62.unk4 = BoardP_8006dcd0_eightliner_loops_upto_19_times_increment();
    arg0->unk62.unk5 = var_s4;
  } else {
    arg0->unk62.unk4 = var_s5;
    arg0->unk62.unk5 = BoardP_8006dd1c_eightliner_loops_upto_19_times_decrement();
  }
  arg0->unk0 = 6;
  arg0->unk1 = 0;
  arg0->unk2 = 0;
}

static void KeySpin_8006c5c4_sevenliner_sets_arg0_struct_1(UnkStruct_9 *arg0, s32 arg1) {
  KeySpin_8006b8b8_fiveliner_calls_b6b4_b7b4(&arg0->unk59, arg1);
  if (arg0->unk59.unk0) {
    arg0->unk1 = 0;
    arg0->unk2 = 1;
  } else {
    arg0->unk0 = 7;
    arg0->unk1 = 0;
    arg0->unk2 = 1;
  }
}

static void KeySpin_8006c644_fourliner_sets_arg0_struct(UnkStruct_9 *arg0) {
  KeySpin_8006b454_fourliner_sets_arg0_struct(&arg0->unk62);
  arg0->unk0 = 8;
  arg0->unk1 = 0;
  arg0->unk2 = 0;
}

static void KeySpin_8006c690_sevenliner_sets_arg0_struct_2(UnkStruct_9 *arg0, s32 arg1) {
  KeySpin_8006b478_eightliner(&arg0->unk62, arg1);
  if (arg0->unk62.unk0) {
    arg0->unk1 = 0;
    arg0->unk2 = 1;
  } else {
    arg0->unk0 = 0;
    arg0->unk1 = 2;
    arg0->unk2 = 1;
  }
}

static u8 KeySpin_8006c710_medliner_interesting_calls_pf_xy_to_lgc(UnkStruct_9 *arg0) {
  register CurrentPiece *p_curpiece;
  register s32 i;
  register Cell *temp_s2;
  register Position sp50;
  register s32 var_s3;
  register u8 temp_s4;
  register s32 j;
  register Cell *temp_s6;
  register Position sp3C;
  register Cell *temp_s7;

  p_curpiece = arg0->currentPiece_ptr;
  for (i = 0; i < 4; i++) {
    sp50 = p_curpiece->minoLockedPos_arr[i];
    temp_s2 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp50.x - 1, sp50.y);
    temp_s2->properties &= ~4;
    temp_s2 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp50.x, sp50.y - 1);
    temp_s2->properties &= ~4;
    temp_s2 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp50.x + 1, sp50.y);
    temp_s2->properties &= ~4;
    temp_s2 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp50.x, sp50.y + 1);
    temp_s2->properties &= ~4;
  }

  temp_s4 = g_boardPieces_ptr->cell_ptr_arr[p_curpiece->minoLockedPos_arr[0].x + (p_curpiece->minoLockedPos_arr[0].y * 10)]->piece_id;
  var_s3 = 0;
  for (j = 0; j < 4; j++) {
    sp3C = p_curpiece->minoLockedPos_arr[j];
    temp_s6 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp3C.x - 1, sp3C.y);
    if ((temp_s6->piece_id != temp_s4) && !(temp_s6->properties & 4)) {
      var_s3++;
      temp_s6->properties |= 4;
    }
    temp_s6 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp3C.x, sp3C.y - 1);
    if ((temp_s6->piece_id != temp_s4) && !(temp_s6->properties & 4)) {
      var_s3++;
      temp_s6->properties |= 4;
    }
    temp_s6 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp3C.x + 1, sp3C.y);
    if ((temp_s6->piece_id != temp_s4) && !(temp_s6->properties & 4)) {
      var_s3++;
      temp_s6->properties |= 4;
    }
    temp_s6 = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(sp3C.x, sp3C.y + 1);
    if ((temp_s6->piece_id != temp_s4) && !(temp_s6->properties & 4)) {
      var_s3++;
      temp_s6->properties |= 4;
    }
  }
  if (var_s3 < 4) {
    return FALSE;
  }

  temp_s7 = g_boardPieces_ptr->cell_ptr_arr[p_curpiece->minoLockedPos_arr[0].x + (p_curpiece->minoLockedPos_arr[0].y * 10)];
  if (BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(temp_s7, -1, 0)) {
    return FALSE;
  }
  if (BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(temp_s7, 1, 0)) {
    return FALSE;
  }
  if (BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(temp_s7, 0, -1)) {
    return FALSE;
  }
  if (BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(temp_s7, 0, 1)) {
    return FALSE;
  }

  return TRUE;
}

static void KeySpin_8006ca90_nineliner_sets_arg0_struct(UnkStruct_9 *arg0) {
  if (KeySpin_8006c710_medliner_interesting_calls_pf_xy_to_lgc(arg0)) {
    arg0->unk0 = 3;
    arg0->unk1 = 0;
    arg0->unk2 = 0;
    D_800CFF50 = 0;
  } else {
    arg0->unk0 = 0;
    arg0->unk1 = 1;
    arg0->unk2 = 1;
  }
}

u8 KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35(UnkStruct_9 *arg0, s32 arg1) {
  do {
    switch (arg0->unk0) {
    case 2:
      KeySpin_8006ca90_nineliner_sets_arg0_struct(arg0);
      break;
    case 3:
      KeySpin_8006c09c_tenliner_loops_lcv_arg0_unk58(arg0);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 8);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 20);
      break;
    case 4:
      KeySpin_8006c160_twentyfiveliner_loops_lcv_arg0_unk58(arg0, arg1);
      break;
    case 5:
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 8);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 21);
      KeySpin_InitVPulse(arg0);
      break;
    case 6:
      KeySpin_8006c5c4_sevenliner_sets_arg0_struct_1(arg0, arg1);
      break;
    case 7:
      KeySpin_8006c644_fourliner_sets_arg0_struct(arg0);
      break;
    case 8:
      KeySpin_8006c690_sevenliner_sets_arg0_struct_2(arg0, arg1);
      break;
    }
  } while (arg0->unk2 == 0);

  return arg0->unk1;
}
