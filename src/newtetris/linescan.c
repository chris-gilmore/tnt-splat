#include "common.h"

LineScan *g_lineScan_ptr;

static void   LineScan_80069830_elevenliner_loops_20_times(LineScan *);
// static
extern void   LineScan_800698e0_largeliner_loops_20_times_plays_sfx(LineScan *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/linescan/LineScan_800698e0_largeliner_loops_20_times_plays_sfx.s")
/*
// static
void LineScan_800698e0_largeliner_loops_20_times_plays_sfx(LineScan *arg0) {
  s32 temp_s2;
  s32 temp_s3;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 var_s4;
  u32 temp_t1;
  u32 var_s1;
  void *var_s0;

  if ((arg0->unk3F0 == 4) && (g_currentPiece_ptr->pieceType == 5)) {
    var_s4 = 1;
    updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, 1);
  } else {
    var_s4 = 0;
  }
  temp_t1 = arg0->unk3F0;
  if (temp_t1 < 4U) {
    if (temp_t1 >= 2U) {
      func_80073030(temp_t1 - 1);
    }
  } else {
    func_80073030(arg0->unk3F0);
  }
  var_s1 = 0;
  var_s0 = arg0 + 3;
  if (0U < 0x14U) {
    do {
      LineEffect_80069668_fourliner_sets_arg0_struct_v1(arg0 + (var_s1 * 0x30) + 0x2C);
      if (var_s0->unk1 != 0) {
        updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, 1);
        temp_v0 = MultisquareGlow_8006ac2c_loops_10_times(var_s1, 1);
        updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, temp_v0 * 5);
        temp_s2 = temp_v0 > 0;
        temp_v0_2 = MultisquareGlow_8006ac2c_loops_10_times(var_s1, 2);
        updateLinesToBeAdded(&g_gameStats_ptr->linesInfo, temp_v0_2 * 0xA);
        temp_s3 = temp_v0_2 > 0;
        if ((temp_s2 != 0) || (temp_s3 != 0)) {
          D_800D0540 += 1;
          func_80073030(1U);
        }
        if (temp_s3 != 0) {
          LineEffect_Init(arg0 + (var_s1 * 0x30) + 0x2C, var_s1, 3);
        } else if (temp_s2 != 0) {
          LineEffect_Init(arg0 + (var_s1 * 0x30) + 0x2C, var_s1, 2);
        } else if (var_s4 != 0) {
          LineEffect_Init(arg0 + (var_s1 * 0x30) + 0x2C, var_s1, 4);
        } else {
          LineEffect_Init(arg0 + (var_s1 * 0x30) + 0x2C, var_s1, 1);
        }
      }
      var_s1 += 1;
      var_s0 += 2;
    } while (var_s1 < 0x14U);
  }
  switch (D_800D0540) {
  case 1:
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xFU);
  default:
  block_31:
    D_800D0540 = 0;
    break;
  case 2:
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xFU);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11U);
    goto block_31;
  case 3:
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xFU);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11U);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x13U);
    goto block_31;
  case 4:
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xFU);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x11U);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x12U);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0x13U);
    goto block_31;
  }
  func_80072300(g_currentplayer);
  arg0->unk0 = 3;
  arg0->unk2 = 0;
}
*/

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
  register UnkStruct_5 *var_s1; // u8 to Position
  register s32 i;

  var_s0 = 0;
  var_s1 = lineScan_ptr->pad3;
  for (i = 0; i < 20; i++, var_s1++) { // += from 2 to ++
    var_s1->y = 0;
    if ((var_s1->x != 0) && (lineScan_ptr->unk3F4 >= i)) {
      if (FALSE);
      if (LineScan_80069cf0_eighliner_loops_10_times_retbool(lineScan_ptr, i)) {
        var_s1->y = 1;
        var_s0++;
      }
      var_s1->x = 0;
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
    lineScan_ptr->pad3[i].x = 1; //
  }
}

void LineScan_80069ec0_sevenliner_loops_4_times(void) {
  register LineScan *lineScan_ptr = g_lineScan_ptr;
  register Position *var_a1;
  register s32 i;

  var_a1 = g_currentPiece_ptr->minoLockedPos_arr;
  for (i = 4; i > 0; i--, var_a1++) {
    g_lineScan_ptr->pad3[var_a1->y].x = 1;  // remove *2 and added .x
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
    lineScan_ptr->pad3[i].x = 0;  // remove *2 and added .x
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
