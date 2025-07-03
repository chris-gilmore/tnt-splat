#include "common.h"

static void LineEffect_80068ff0_elevenliner(LineEffect *, u8);
static void LineEffect_800690e4_eightliner_loops_10_times(LineEffect *, u8);
static void LineEffect_80069160_seventeen_liner(LineEffect *, u8);
static void LineEffect_800692fc_sixteenliner_loops_10_times(LineEffect *, u8);
static void LineEffect_8006942c_sixliner(LineEffect *, u8);
static void LineEffect_800694b0_sevenliner_loops_10_times(LineEffect *, u8);
static void LineEffect_80069684_threeliner_sets_arg0_struct_v2(LineEffect *);
static void LineEffect_8006969c_fourliner_sets_arg0_struct_v3(LineEffect *, s32);
static void LineEffect_800696b8_fiveliner_sets_arg0_struct_v4(LineEffect *, s32);
static void LineEffect_800696d8_fourliner_sets_arg0_struct_v5(LineEffect *, s32);

static void LineEffect_80068ff0_elevenliner(LineEffect *lineEffect_ptr, u8 arg1) {
  if (lineEffect_ptr->col_step < 5) {
    BoardP_8006d674_tenliner_alloc_fallingcubes(lineEffect_ptr->cells[4 - lineEffect_ptr->col_step]);
    BoardP_8006d674_tenliner_alloc_fallingcubes(lineEffect_ptr->cells[5 + lineEffect_ptr->col_step]);
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, func_800A35EC(9, 12));
    lineEffect_ptr->col_step++;
    lineEffect_ptr->unk3 = TRUE;
    lineEffect_ptr->unk2 = FALSE;
  } else {
    lineEffect_ptr->state = 3;
    lineEffect_ptr->unk3 = TRUE;
    lineEffect_ptr->unk2 = FALSE;
  }
}

static void LineEffect_800690e4_eightliner_loops_10_times(LineEffect *lineEffect_ptr, u8 arg1) {
  register s32 col;

  for (col = 0; col < 10; col++) {
    BoardP_8006e288_adds_8_entries_and_swaps_cubes(lineEffect_ptr->cells[col]);
  }
  lineEffect_ptr->unk2 = TRUE;
  lineEffect_ptr->state = 0;
  lineEffect_ptr->unk3 = TRUE;
}

static void LineEffect_80069160_seventeen_liner(LineEffect *lineEffect_ptr, u8 arg1) {
  if (lineEffect_ptr->unk4 < 3) {
    lineEffect_ptr->unk4++;
    return;
  }

  lineEffect_ptr->unk4 = 0;
  if (lineEffect_ptr->col_step < 5) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, func_800A35EC(9, 12));
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 8);
    BoardP_8006d674_tenliner_alloc_fallingcubes(lineEffect_ptr->cells[4 - lineEffect_ptr->col_step]);
    BoardP_8006d674_tenliner_alloc_fallingcubes(lineEffect_ptr->cells[5 + lineEffect_ptr->col_step]);
    BoardP_8006e288_adds_8_entries_and_swaps_cubes(lineEffect_ptr->cells[4 - lineEffect_ptr->col_step]);
    BoardP_8006e288_adds_8_entries_and_swaps_cubes(lineEffect_ptr->cells[5 + lineEffect_ptr->col_step]);
    lineEffect_ptr->col_step++;
    lineEffect_ptr->unk3 = TRUE;
    lineEffect_ptr->unk2 = FALSE;
  } else {
    lineEffect_ptr->unk2 = TRUE;
    lineEffect_ptr->state = 0;
    lineEffect_ptr->unk3 = TRUE;
  }
}

static void LineEffect_800692fc_sixteenliner_loops_10_times(LineEffect *lineEffect_ptr, u8 arg1) {
  register Cell *cell_ptr;
  register s32 col;

  lineEffect_ptr->unk4 = 24;  // line clearing delay (containing gold or silver)
  BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(lineEffect_ptr->cells[0]);
  for (col = 1; col < 10; col++) {
    BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(lineEffect_ptr->cells[col]);
    BoardP_8006d450_fourteenliner_pf_logic_cell_loops(lineEffect_ptr->cells[col], lineEffect_ptr->cells[0]);
  }
  for (col = 0; col < 10; col++) {
    cell_ptr = lineEffect_ptr->cells[col];
    cell_ptr->cubeInfo.cube_ptr->mino.unk22 = (0xFF - cell_ptr->cubeInfo.cube_ptr->mino.unk20) / 24;
    Minos_80070860_fortyliner(&cell_ptr->cubeInfo.cube_ptr->mino, &g_color_metal, 24);
  }
  lineEffect_ptr->state = 6;
  lineEffect_ptr->unk3 = FALSE;
  lineEffect_ptr->unk2 = FALSE;
}

static void LineEffect_8006942c_sixliner(LineEffect *lineEffect_ptr, u8 arg1) {
  if (--lineEffect_ptr->unk4 == 0) {
    lineEffect_ptr->state = 7;
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 16);
  }
  lineEffect_ptr->unk3 = TRUE;
  lineEffect_ptr->unk2 = FALSE;
}

static void LineEffect_800694b0_sevenliner_loops_10_times(LineEffect *lineEffect_ptr, u8 arg1) {
  register s32 col;

  for (col = 0; col < 10; col++) {
    BoardP_8006e288_adds_8_entries_and_swaps_cubes(lineEffect_ptr->cells[col]);
  }
  lineEffect_ptr->unk2 = TRUE;
  lineEffect_ptr->state = 0;
  lineEffect_ptr->unk3 = TRUE;
}

u8 LineEffect_Update(LineEffect *lineEffect_ptr, u8 arg1) {
  do {
    //rmonPrintf("LineEffect state: %d\n", lineEffect_ptr->state);
    switch (lineEffect_ptr->state) {
    case 0:
    case 1:
      lineEffect_ptr->state = 0;
      lineEffect_ptr->unk2 = TRUE;
      lineEffect_ptr->unk3 = TRUE;
      break;
    case 2:
      // falling cubes
      LineEffect_80068ff0_elevenliner(lineEffect_ptr, arg1);
      break;
    case 3:
      // swap cubes (drop cubes from above line being cleared)
      LineEffect_800690e4_eightliner_loops_10_times(lineEffect_ptr, arg1);
      break;
    case 4:
      // clearing a tetris
      LineEffect_80069160_seventeen_liner(lineEffect_ptr, arg1);
      break;
    case 5:
      //rmonPrintf("---------- LineEffect_Update -- case 5 ------------\n");
      LineEffect_800692fc_sixteenliner_loops_10_times(lineEffect_ptr, arg1);
      break;
    case 6:
      //rmonPrintf("---------- LineEffect_Update -- case 6 ------------\n");
      LineEffect_8006942c_sixliner(lineEffect_ptr, arg1);
      break;
    case 7:
      //rmonPrintf("---------- LineEffect_Update -- case 7 ------------\n");
      LineEffect_800694b0_sevenliner_loops_10_times(lineEffect_ptr, arg1);
      break;
    default:
      debug_print_reason_routine("Invalid state", "LineEffect_Update(), lineeffect.c");
      break;
    }
  } while (lineEffect_ptr->unk3 == FALSE);
  return lineEffect_ptr->unk2;
}

void LineEffect_80069668_fourliner_sets_arg0_struct_v1(LineEffect *lineEffect_ptr) {
  lineEffect_ptr->type = 0;
  lineEffect_ptr->state = 0;
  lineEffect_ptr->unk2 = TRUE;
  lineEffect_ptr->unk3 = TRUE;
}

static void LineEffect_80069684_threeliner_sets_arg0_struct_v2(LineEffect *lineEffect_ptr) {
  lineEffect_ptr->state = 0;
  lineEffect_ptr->unk2 = TRUE;
  lineEffect_ptr->unk3 = TRUE;
}

static void LineEffect_8006969c_fourliner_sets_arg0_struct_v3(LineEffect *lineEffect_ptr, s32 row) {
  lineEffect_ptr->state = 2;
  lineEffect_ptr->unk2 = FALSE;
  lineEffect_ptr->unk3 = FALSE;
  lineEffect_ptr->col_step = 0;
}

static void LineEffect_800696b8_fiveliner_sets_arg0_struct_v4(LineEffect *lineEffect_ptr, s32 row) {
  lineEffect_ptr->state = 4;
  lineEffect_ptr->unk2 = FALSE;
  lineEffect_ptr->unk3 = FALSE;
  lineEffect_ptr->col_step = 0;
  lineEffect_ptr->unk4 = 0;
}

static void LineEffect_800696d8_fourliner_sets_arg0_struct_v5(LineEffect *lineEffect_ptr, s32 row) {
  lineEffect_ptr->state = 5;
  lineEffect_ptr->unk2 = FALSE;
  lineEffect_ptr->unk3 = FALSE;
  lineEffect_ptr->unk4 = 0;
}

void LineEffect_Init(LineEffect *lineEffect_ptr, s32 row, u8 type) {
  register s32 col;
  register Cell **cell_ptr_ptr;

  lineEffect_ptr->type = type;
  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[row * 10];
  for (col = 0; col < 10; col++) {
    lineEffect_ptr->cells[col] = *cell_ptr_ptr;
    cell_ptr_ptr++;
  }
  switch (type) {
  case 0:
    LineEffect_80069684_threeliner_sets_arg0_struct_v2(lineEffect_ptr);
    break;
  case 1:
    LineEffect_8006969c_fourliner_sets_arg0_struct_v3(lineEffect_ptr, row);
    break;
  case 4:
    LineEffect_800696b8_fiveliner_sets_arg0_struct_v4(lineEffect_ptr, row);
    break;
  case 2:
  case 3:
    LineEffect_800696d8_fourliner_sets_arg0_struct_v5(lineEffect_ptr, row);
    break;
  default:
    debug_print_reason_routine("Invalid type", "LineEffect_Init(), lineeffect.c");
  }
}
