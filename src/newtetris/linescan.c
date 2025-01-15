#include "common.h"

u8 D_800D0540 = 0;
LineScan *g_lineScan_ptr;

static void   LineScan_80069830_elevenliner_loops_20_times(LineScan *);
static void   LineScan_800698e0_largeliner_loops_20_times_plays_sfx(LineScan *);
static s32    LineScan_80069cf0_eighliner_loops_10_times_retbool(LineScan *, s32);
static void   LineScan_80069d60_fifteenliner_loops_20_times(LineScan *);
static void   LineScan_80069e2c_fiveliner(LineScan *);


static void LineScan_80069830_elevenliner_loops_20_times(LineScan *lineScan_ptr) {
  register u32 i;
  register u32 var_s1 = TRUE;
  register u32 var_s2;

  for (i = 0; i < 20; i++) {
    var_s2 = LineEffect_Update(&lineScan_ptr->unk2C[i], 1);
    if (var_s2 != 1) {
      var_s1 = FALSE;
    }
  }
  if (var_s1) {
    lineScan_ptr->unk0 = 0;
    lineScan_ptr->unk1 = 2;
    lineScan_ptr->unk2 = 1;
  }
}

static void LineScan_800698e0_largeliner_loops_20_times_plays_sfx(LineScan *lineScan_ptr) {
  register UnkStruct_5 *var_s0;
  register u32 i;
  register s32 temp_s2;
  register s32 temp_s3;
  register s32 var_s4;
  register s32 temp_v0;

  if ((lineScan_ptr->unk3F0 == 4) && (g_currentPiece_ptr->pieceType == 5)) {  // blue stick
    var_s4 = 1;
    updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, 1);
  } else {
    var_s4 = 0;
  }
  if (lineScan_ptr->unk3F0 < 4) {
    if (lineScan_ptr->unk3F0 >= 2) {
      func_80073030(lineScan_ptr->unk3F0 - 1);  // 2 or 3
    }
  } else {
    func_80073030(lineScan_ptr->unk3F0);  // 4 or more
  }
  var_s0 = lineScan_ptr->unk3;
  for (i = 0; i < 20; i++) {
    LineEffect_80069668_fourliner_sets_arg0_struct_v1(&lineScan_ptr->unk2C[i]);
    if (var_s0->unk1) {
      updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, 1);
      temp_v0 = MultisquareGlow_8006ac2c_loops_10_times(i, 1);          // 1 (square_type) : silver
      updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, temp_v0 * 5);   // 5 points for silver
      temp_s2 = temp_v0 > 0;
      temp_v0 = MultisquareGlow_8006ac2c_loops_10_times(i, 2);          // 2 (square_type) : gold
      updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, temp_v0 * 10);  // 10 points for gold
      temp_s3 = temp_v0 > 0;
      if ((temp_s2 != 0) || (temp_s3 != 0)) {
        D_800D0540++;
        func_80073030(1);
      }
      if (temp_s3) {
        LineEffect_Init(&lineScan_ptr->unk2C[i], i, 3);
      } else if (temp_s2 != 0) {
        LineEffect_Init(&lineScan_ptr->unk2C[i], i, 2);
      } else if (var_s4 != 0) {
        LineEffect_Init(&lineScan_ptr->unk2C[i], i, 4);
      } else {
        LineEffect_Init(&lineScan_ptr->unk2C[i], i, 1);
      }
    }
    var_s0++;
  }
  if (D_800D0540 != 0) {
    switch (D_800D0540) {
    case 1:
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xF);
      break;
    case 2:
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xF);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11);
      break;
    case 3:
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xF);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x13);
      break;
    case 4:
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xF);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x12);
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x13);
      break;
    }
    D_800D0540 = 0;
  }
  func_80072300(g_currentplayer);
  lineScan_ptr->unk0 = 3;
  lineScan_ptr->unk2 = 0;
}

static s32 LineScan_80069cf0_eighliner_loops_10_times_retbool(LineScan *lineScan_ptr, s32 lineno) {
  register s32 i;
  register Cell **cell_ptr_ptr;

  cell_ptr_ptr = g_boardPieces_ptr->cell_ptr_arr + (lineno * 10);
  for (i = 0; i < 10; i++) {
    if ((*cell_ptr_ptr)->piece_type == EMPTY_CELL) {
      return FALSE;
    }
    cell_ptr_ptr++;
  }
  return TRUE;
}

static void LineScan_80069d60_fifteenliner_loops_20_times(LineScan *lineScan_ptr) {
  register s32 var_s0;
  register UnkStruct_5 *var_s1;
  register s32 i;

  var_s0 = 0;
  var_s1 = lineScan_ptr->unk3;
  for (i = 0; i < 20; i++, var_s1++) {
    var_s1->unk1 = 0;
    if ((var_s1->unk0 != 0) && (lineScan_ptr->unk3F4 >= i)) {
      if (FALSE);
      if (LineScan_80069cf0_eighliner_loops_10_times_retbool(lineScan_ptr, i)) {
        var_s1->unk1 = 1;
        var_s0++;
      }
      var_s1->unk0 = 0;
    }
  }
  lineScan_ptr->unk3F0 = var_s0;
  lineScan_ptr->unk3EC += var_s0;
}

static void LineScan_80069e2c_fiveliner(LineScan *lineScan_ptr) {
  LineScan_80069d60_fifteenliner_loops_20_times(lineScan_ptr);
  if (lineScan_ptr->unk3F0 == 0) {
    lineScan_ptr->unk1 = 1;
  } else {
    lineScan_ptr->unk0 = 2;
  }
}

void LineScan_80069e84_sevenliner_loops_20_times(void) {
  register LineScan *lineScan_ptr = g_lineScan_ptr;
  register s32 i;

  for (i = 0; i < 20; i++) {
    lineScan_ptr->unk3[i].unk0 = 1;
  }
}

void LineScan_80069ec0_sevenliner_loops_4_times(void) {
  register LineScan *lineScan_ptr = g_lineScan_ptr;
  register Position *var_a1;
  register s32 i;

  var_a1 = g_currentPiece_ptr->minoLockedPos_arr;
  for (i = 4; i > 0; i--, var_a1++) {
    g_lineScan_ptr->unk3[var_a1->y].unk0 = 1;
  }
}

void LineScan_80069f10_threeliner_lowestscanableline(u8 arg0) {
  if (arg0 >= 20) {
    debug_print_reason_routine_linenum("lowestScanableLine invalid", "linescan.c", 297);
  }
  g_lineScan_ptr->unk3F4 = arg0;
}

void LineScan_Init(void) {
  register LineScan *lineScan_ptr = g_lineScan_ptr;
  register s32 i;

  lineScan_ptr->unk3F4 = 19;
  lineScan_ptr->unk3EC = 0;
  lineScan_ptr->unk3F0 = 0;
  lineScan_ptr->unk0 = 0;
  lineScan_ptr->unk1 = 0;
  for (i = 0; i < 20; i++) {
    lineScan_ptr->unk3[i].unk0 = 0;
  }
}

void LineScan_80069fb8_elevenliner_case_and_loop_interesting(void) {
  register LineScan *lineScan_ptr = g_lineScan_ptr;

  lineScan_ptr->unk1 = 0;
  do {
    lineScan_ptr->unk2 = 1;
    switch (lineScan_ptr->unk0) {
    case 1:
      LineScan_80069e2c_fiveliner(lineScan_ptr);
      break;
    case 2:
      LineScan_800698e0_largeliner_loops_20_times_plays_sfx(lineScan_ptr);
      break;
    case 3:
      LineScan_80069830_elevenliner_loops_20_times(lineScan_ptr);
      break;
    }
  } while (lineScan_ptr->unk2 == 0);
}
