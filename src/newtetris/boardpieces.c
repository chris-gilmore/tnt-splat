#include "common.h"

BoardPieces *g_boardPieces_ptr;

static void   BoardP_8006d500_tenliner_pf_logic_cells_loops(Cell *);
static void   BoardP_8006d728_checkAndSetSurroundingCells(Cell *);
static void   BoardP_8006d910_sevenliner_loopThroughConnectedMinos(Cell *);
static void   BoardP_8006d998_sixliner_loops(Cell *);
static void   BoardP_8006da8c_sixliner_sets_stuff_9(Cell *);
static void   BoardP_8006daf0_sixliner_sets_stuff_7(Cell *);
static void   BoardP_UpdateQueueEntry_Update(TypedEntry *, s32);
static void   BoardP_8006dbb8_eightliner_calls_UPDQueueEntry_Update_loops(TypedQueue *, s32);
static void   BoardP_UpdateQueue_AddEntry(TypedQueue *, Entry, u8);
static void   BoardP_8006dcc0_twoliner_sets_to_600_0(TypedQueue *);

Color *BoardP_8006d3c0_fourliner(Cell *cell_ptr) {
  register Square *square_ptr;

  if (!MultisquareGlow_isArg0_lessthan_44(cell_ptr->square_id)) {
    return g_pieceDef_ptr_arr[cell_ptr->piece_type]->color_ptr;
  }

  square_ptr = &g_squares_ptr->arr[cell_ptr->square_id];
  return Multisquare_pGetColor(square_ptr);
}

void BoardP_8006d450_fourteenliner_pf_logic_cell_loops(Cell *arg0, Cell *arg1) {
  register Cell *cell_ptr;
  register u8 temp_s1 = arg0->piece_id;

  if (temp_s1 == arg1->piece_id) {
    return;
  }

  cell_ptr = arg1;
  do {
    FUN_80050840_fiveliner(&g_boardPieces_ptr->pieceIds, cell_ptr->piece_id);
    cell_ptr->piece_id = temp_s1;
    FUN_80050800_oneliner(&g_boardPieces_ptr->pieceIds, temp_s1);
    cell_ptr = cell_ptr->next;
  } while (cell_ptr != arg1);

  // arg0 and arg1 are nodes in two circular linked lists.
  // By swapping their next pointers, we create a single circular linked list.
  cell_ptr = arg1->next;
  arg1->next = arg0->next;
  arg0->next = cell_ptr;
}

static void BoardP_8006d500_tenliner_pf_logic_cells_loops(Cell *arg0) {
  register Cell *var_s0;

  if (arg0->next == arg0) {
    return;
  }

  FUN_80050840_fiveliner(&g_boardPieces_ptr->pieceIds, arg0->piece_id);
  arg0->piece_id = can_run_out_of_ids(&g_boardPieces_ptr->pieceIds);
  FUN_80050800_oneliner(&g_boardPieces_ptr->pieceIds, arg0->piece_id);

  // break apart arg0 from its circular linked list
  var_s0 = arg0;
  do {
    var_s0 = var_s0->next;
  } while (var_s0->next != arg0);
  var_s0->next = arg0->next;
  arg0->next = arg0;
}

void BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(Cell *arg0) {
  register Square *square_ptr;
  register s32 x;
  register s32 y;

  if (MultisquareGlow_isArg0_lessthan_44(arg0->square_id)) {
    square_ptr = &g_squares_ptr->arr[arg0->square_id];
    Multisquare_8006a410_fourliner(square_ptr, &arg0->cubeInfo.cell_id);
    arg0->square_id = 0xFF;
  }
  BoardP_8006d998_sixliner_loops(arg0);
  BoardP_8006d500_tenliner_pf_logic_cells_loops(arg0);
  x = arg0->cubeInfo.pos.x;
  y = arg0->cubeInfo.pos.y;
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, y);
}

void BoardP_8006d674_tenliner_alloc_fallingcubes(Cell *arg0) {
  if (arg0->piece_type == EMPTY_CELL) {
    return;
  }

  BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(arg0);
  FUN_80050840_fiveliner(&g_boardPieces_ptr->pieceIds, arg0->piece_id);
  arg0->properties = 2;
  arg0->piece_type = EMPTY_CELL;
  arg0->piece_id = 0;
  arg0->square_id = 0xFF;
  arg0->next = arg0;
  *FallingCubes_Alloc() = arg0->cubeInfo.cube_ptr;
  arg0->cubeInfo.cube_ptr = NULL;
}

static void BoardP_8006d728_checkAndSetSurroundingCells(Cell *cell_ptr) {
  register u8 piece_id;
  register s32 x;
  register s32 y;
  register u8 surround_bitfield;

  if (cell_ptr->cubeInfo.cube_ptr == NULL) {
    return;
  }

  surround_bitfield = 0;
  x = cell_ptr->cubeInfo.pos.x;
  y = cell_ptr->cubeInfo.pos.y;
  piece_id = cell_ptr->piece_id;
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x - 1, y - 1)->piece_id == piece_id) {
    surround_bitfield |= 0x80;   // NW
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x, y - 1)->piece_id == piece_id) {
    surround_bitfield |= 0x1;   // N
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x + 1, y - 1)->piece_id == piece_id) {
    surround_bitfield |= 0x10;  // NE
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x - 1, y)->piece_id == piece_id) {
    surround_bitfield |= 0x8;   // W
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x + 1, y)->piece_id == piece_id) {
    surround_bitfield |= 0x2;   // E
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x - 1, y + 1)->piece_id == piece_id) {
    surround_bitfield |= 0x40;  // SW
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x, y + 1)->piece_id == piece_id) {
    surround_bitfield |= 0x4;   // S
  }
  if (BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x + 1, y + 1)->piece_id == piece_id) {
    surround_bitfield |= 0x20;  // SE
  }
  Minos_80070818_oneliner_sets_arg0_0x130_to_arg1(&cell_ptr->cubeInfo.cube_ptr->mino, g_cubeTiles_ptr->unkDC00[surround_bitfield]);
}

static void BoardP_8006d910_sevenliner_loopThroughConnectedMinos(Cell *first_cell_ptr) {
  register Cell *cell_ptr;

  if (first_cell_ptr->piece_type == EMPTY_CELL) {
    return;
  }

  Audio2_Play_SFX(&D_801235B0, &D_800D3A90, func_800A35EC(5, 7));
  cell_ptr = first_cell_ptr;
  do {
    BoardP_8006d728_checkAndSetSurroundingCells(cell_ptr);
    cell_ptr = cell_ptr->next;
  } while (cell_ptr != first_cell_ptr);
}

// break apart connected cells
static void BoardP_8006d998_sixliner_loops(Cell *first_cell_ptr) {
  register Cell *cell_ptr;

  // if cell is not empty and not broken
  if (!(first_cell_ptr->properties & 3)) {
    cell_ptr = first_cell_ptr;
    do {
      // break apart cell
      cell_ptr->properties |= 1;
      cell_ptr = cell_ptr->next;
    } while (cell_ptr != first_cell_ptr);
  }
}

u8 BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(Cell *first_cell_ptr, s32 delta_x, s32 delta_y) {
  register Cell *cell_ptr;
  register Cell *adjacent_cell_ptr;
  register s32 x;
  register s32 y;
  register u8 piece_id;

  piece_id = first_cell_ptr->piece_id;
  cell_ptr = first_cell_ptr;
  do {
    x = cell_ptr->cubeInfo.pos.x;
    y = cell_ptr->cubeInfo.pos.y;
    adjacent_cell_ptr = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x + delta_x, y + delta_y);
    if ((adjacent_cell_ptr->piece_type != EMPTY_CELL) && (adjacent_cell_ptr->piece_id != piece_id)) {
      return FALSE;
    }
    cell_ptr = cell_ptr->next;
  } while (cell_ptr != first_cell_ptr);
  return TRUE;
}

static void BoardP_8006da8c_sixliner_sets_stuff_9(Cell *cell_ptr) {
  cell_ptr->properties = 1;     // broken cell
  cell_ptr->piece_type = 9;     // piece_type is 9?
  cell_ptr->piece_id = 0;
  cell_ptr->square_id = 0xFE;   // square_id is 0xFE?
  cell_ptr->next = cell_ptr;
  Cube_NewCellInfo(&cell_ptr->cubeInfo);
}

static void BoardP_8006daf0_sixliner_sets_stuff_7(Cell *cell_ptr) {
  cell_ptr->properties = 2;           // empty cell
  cell_ptr->piece_type = EMPTY_CELL;
  cell_ptr->piece_id = 0;
  cell_ptr->square_id = 0xFF;
  cell_ptr->next = cell_ptr;
  Cube_NewCellInfo(&cell_ptr->cubeInfo);
}

static void BoardP_UpdateQueueEntry_Update(TypedEntry *entry_ptr, s32 arg1) {
  switch (entry_ptr->type) {
  case 1:
    BoardP_8006d728_checkAndSetSurroundingCells(entry_ptr->entry);
    break;
  default:
    debug_print_reason_routine("invalid type, boardpieces.c", "UpdateQueueEntry:Update");
  }
}

static void BoardP_8006dbb8_eightliner_calls_UPDQueueEntry_Update_loops(TypedQueue *updQ_ptr, s32 arg1) {
  register s32 i;
  register TypedEntry *entry_ptr;

  for (i = updQ_ptr->curlen, entry_ptr = updQ_ptr->entries; i > 0; entry_ptr++, i--) {
    BoardP_UpdateQueueEntry_Update(entry_ptr, arg1);
  }
  updQ_ptr->curlen = 0;
}

static void BoardP_UpdateQueue_AddEntry(TypedQueue *updQ_ptr, Entry entry, u8 type) {
  if (updQ_ptr->curlen >= updQ_ptr->maxlen) {
    debug_print_reason_routine("out of entries, boardpieces.c", "BoardPieceUpdateQueue:AddEntry");
  }
  updQ_ptr->entries[updQ_ptr->curlen].type = type;
  updQ_ptr->entries[updQ_ptr->curlen].entry = entry;
  updQ_ptr->curlen++;
}

static void BoardP_8006dcc0_twoliner_sets_to_600_0(TypedQueue *updQ_ptr) {
  updQ_ptr->maxlen = 600;
  updQ_ptr->curlen = 0;
}

s32 BoardP_8006dcd0_eightliner_loops_upto_19_times_increment(void) {
  register s32 i = 0;

  do {
    if (BoardP_8006dd64_check_for_nonempty_cell_downwards(i)) {
      return i;
    }
  } while (++i < 19);

  return 19;
}

s32 BoardP_8006dd1c_eightliner_loops_upto_19_times_decrement(void) {
  register s32 i = 19;

  do {
    if (BoardP_8006dd64_check_for_nonempty_cell_downwards(i)) {
      return i;
    }
  } while (--i > 0);

  return 0;
}

u8 BoardP_8006dd64_check_for_nonempty_cell_downwards(s32 y) {
  register Cell **cell_ptr_ptr;
  register s32 i;

  for (i = 0, cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[y * 10]; i < 10; cell_ptr_ptr++, i++) {
    if ((*cell_ptr_ptr)->piece_type != EMPTY_CELL) {
      return TRUE;
    }
  }

  return FALSE;
}

u8 BoardP_8006ddd0_check_for_nonempty_cell_upwards(s32 y) {
  register Cell **cell_ptr_ptr;
  register s32 i;

  if (y <= 0) {
    return FALSE;
  }

  cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[y * 10 - 1];
  i = y * 10;
  do {
    if ((*cell_ptr_ptr)->piece_type != EMPTY_CELL) {
      return TRUE;
    }
    cell_ptr_ptr--;
  } while (--i != 0);

  return FALSE;
}

void BoardP_8006de40_nineliner(s32 x, s32 y, u8 piece_type) {
  register  Cell *cell_ptr;

  if ((x < 0) || (x > 9) || (y < 0) || (y > 19)) {
    return;
  }

  cell_ptr = g_boardPieces_ptr->cell_ptr_arr[x + (y * 10)];
  cell_ptr->piece_type = piece_type;
  cell_ptr->piece_id = can_run_out_of_ids(&g_boardPieces_ptr->pieceIds);
  FUN_80050800_oneliner(&g_boardPieces_ptr->pieceIds, cell_ptr->piece_id);
  cell_ptr->properties &= ~2;  // not empty cell
  Cube_Alloc(&cell_ptr->cubeInfo, x, y, g_pieceDef_ptr_arr[piece_type]->color_ptr);
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, y);
}

void BoardP_8006df38_twentyfiveliner_3_loops(UnkStruct_4 *arg0) {
  register Cell *cell_ptr;
  register Position *minoLockedPos_ptr;
  register u8 numMinos = arg0->numMinos;
  register s32 i;
  Color *color_ptr;
  register Cell *first_cell_ptr;

  if (numMinos == 0) {
    return;
  }

  for (i = numMinos, minoLockedPos_ptr = arg0->minoLockedPos_ptr; i > 0; i--, minoLockedPos_ptr++) {
    if ((minoLockedPos_ptr->x < 0) || (minoLockedPos_ptr->x > 9) || (minoLockedPos_ptr->y < 0) || (minoLockedPos_ptr->y > 19)) {
      return;
    }
  }

  color_ptr = g_pieceDef_ptr_arr[arg0->pieceType]->color_ptr;  // unused

  for (i = numMinos, minoLockedPos_ptr = arg0->minoLockedPos_ptr; i > 0; i--, minoLockedPos_ptr++) {
    BoardP_8006de40_nineliner(minoLockedPos_ptr->x, minoLockedPos_ptr->y, arg0->pieceType);
  }

  if (numMinos > 1) {
    minoLockedPos_ptr = arg0->minoLockedPos_ptr;
    first_cell_ptr = g_boardPieces_ptr->cell_ptr_arr[minoLockedPos_ptr->x + 10 * minoLockedPos_ptr->y];
    for (i = numMinos - 1, minoLockedPos_ptr++; i > 0; i--, minoLockedPos_ptr++) {
      cell_ptr = g_boardPieces_ptr->cell_ptr_arr[minoLockedPos_ptr->x + 10 * minoLockedPos_ptr->y];
      BoardP_8006d450_fourteenliner_pf_logic_cell_loops(first_cell_ptr, cell_ptr);
    }
    BoardP_8006d910_sevenliner_loopThroughConnectedMinos(first_cell_ptr);
  }
}

void BoardPieces_SwapCubes(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  register Cell **temp_s0;
  register Cell **temp_s1;
  register Cell *temp_s2;
  register Cell *temp_s3;

  if ((arg0 < 0) || (arg0 > 9) || (arg1 < 0) || (arg1 > 19)) {
    debug_print_reason_routine("BoardPieces:SwapCubes", "Invalid source");
  }
  if ((arg2 < 0) || (arg2 > 9) || (arg3 < 0) || (arg3 > 19)) {
    debug_print_reason_routine("BoardPieces:SwapCubes", "Invalid dest");
  }

  temp_s0 = &g_boardPieces_ptr->cell_ptr_arr[arg0 + (arg1 * 10)];
  temp_s1 = &g_boardPieces_ptr->cell_ptr_arr[arg2 + (arg3 * 10)];
  temp_s2 = *temp_s0;
  *temp_s0 = *temp_s1;
  *temp_s1 = temp_s2;

  temp_s3 = g_boardPieces_ptr->cell_ptr_arr[arg0 + (arg1 * 10)];
  Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros(&temp_s3->cubeInfo, arg0, arg1);

  temp_s3 = g_boardPieces_ptr->cell_ptr_arr[arg2 + (arg3 * 10)];
  Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros(&temp_s3->cubeInfo, arg2, arg3);
}

void BoardP_8006e288_adds_8_entries_and_swaps_cubes(Cell *cell_ptr) {
  register s32 x = cell_ptr->cubeInfo.pos.x;
  register s32 y = cell_ptr->cubeInfo.pos.y;

  BoardP_8006d674_tenliner_alloc_fallingcubes(cell_ptr);

  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x - 1, y - 1);  // NW
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x - 1, y);      // W
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x - 1, y + 1);  // SW
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, y - 1);      // N
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, y + 1);      // S
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x + 1, y - 1);  // NE
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x + 1, y);      // E
  BoardP_8006e64c_calls_UpdateQueue_AddEntry(x + 1, y + 1);  // SE

  for (; y > 0; y--) {
    BoardPieces_SwapCubes(x, y, x, y - 1);
  }
}

void BoardPieces_RemoveLine(s32 dropy) {
  register s32 x;
  register s32 y;
  register Cell **cell_ptr_ptr;

  if ((dropy < 0) || (dropy > 19)) {
    debug_print_reason_routine("BoardPieces:RemoveLine", "Invalid dropy");
  }
  for (x = 10, cell_ptr_ptr = &g_boardPieces_ptr->cell_ptr_arr[dropy * 10]; x > 0; cell_ptr_ptr++, x--) {
    BoardP_8006d674_tenliner_alloc_fallingcubes(*cell_ptr_ptr);
  }
  for (x = 0; x < 10; x++) {
    BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, dropy - 1);
  }
  for (x = 0; x < 10; x++) {
    BoardP_8006e64c_calls_UpdateQueue_AddEntry(x, dropy + 1);
  }
  for (y = dropy; y > 0; y--) {
    for (x = 0; x < 10; x++) {
      BoardPieces_SwapCubes(x, y, x, y - 1);
    }
  }
}

u8 BoardP_IsPositionEmpty(s32 x, s32 y) {
  register Cell *cell_ptr = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(x, y);

  if (cell_ptr->piece_type == EMPTY_CELL) {
    return TRUE;
  }
  return FALSE;
}

u8 BoardP_IsPointEmpty(s32 point_x, s32 point_y) {
  s32 pos_x = point_x >> 8;
  s32 pos_y = point_y >> 8;

  if (!BoardP_IsPositionEmpty(pos_x, pos_y)) {
    return FALSE;
  }
  if ((point_x & 0xFF) && !BoardP_IsPositionEmpty(pos_x + 1, pos_y)) {
    return FALSE;
  }
  if (point_y & 0xFF) {
    if (!BoardP_IsPositionEmpty(pos_x, pos_y + 1)) {
      return FALSE;
    }
    if ((point_x & 0xFF) && !BoardP_IsPositionEmpty(pos_x + 1, pos_y + 1)) {
      return FALSE;
    }
  }
  return TRUE;
}

Cell *BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(s32 x, s32 y) {
  register BoardPieces *boardPieces_ptr = g_boardPieces_ptr;

  if ((x < 0) || (x > 9) || (y > 19)) {
    return &boardPieces_ptr->cell_201;
  }

  if (y < 0) {
    return &boardPieces_ptr->cell_200;
  }

  return g_boardPieces_ptr->cell_ptr_arr[x + (y * 10)];
}

void BoardP_8006e64c_calls_UpdateQueue_AddEntry(s32 x, s32 y) {
  register Cell *cell_ptr;

  if ((x < 0) || (x > 9) || (y < 0) || (y > 19)) {
    return;
  }

  cell_ptr = g_boardPieces_ptr->cell_ptr_arr[x + (y * 10)];
  if (cell_ptr->piece_type == EMPTY_CELL) {
    return;
  }

  BoardP_UpdateQueue_AddEntry(&g_boardPieces_ptr->updQ, cell_ptr, 1);
}

void BoardPieces_Update(BoardPieces *boardPieces_ptr, s32 arg1) {
  BoardP_8006dbb8_eightliner_calls_UPDQueueEntry_Update_loops(&boardPieces_ptr->updQ, arg1);
}

void BoardPieces_Init(BoardPieces *boardPieces_ptr) {
  register Cell *var_s0;
  register s32 var_s1;
  register Cell **var_s2;
  register Cell *var_s3;
  register s32 var_s4;

  boardPieces_ptr->num_cells = 200;
  BoardP_8006dcc0_twoliner_sets_to_600_0(&boardPieces_ptr->updQ);
  Ids_Init(&boardPieces_ptr->pieceIds, boardPieces_ptr->num_cells + 1);
  FUN_80050800_oneliner(&boardPieces_ptr->pieceIds, 0);
  boardPieces_ptr->cell_list = (Cell *)n64HeapAlloc(boardPieces_ptr->num_cells * sizeof(Cell));
  for (var_s1 = boardPieces_ptr->num_cells, var_s0 = boardPieces_ptr->cell_list; var_s1 > 0; var_s0++, var_s1--) {
    BoardP_8006daf0_sixliner_sets_stuff_7(var_s0);
  }
  BoardP_8006da8c_sixliner_sets_stuff_9(&boardPieces_ptr->cell_200);
  boardPieces_ptr->cell_200.piece_type = EMPTY_CELL;
  boardPieces_ptr->cell_200.properties |= 2;
  BoardP_8006da8c_sixliner_sets_stuff_9(&boardPieces_ptr->cell_201);
  boardPieces_ptr->cell_201.piece_type = 8;
  for (var_s4 = boardPieces_ptr->num_cells, var_s3 = boardPieces_ptr->cell_list, var_s2 = boardPieces_ptr->cell_ptr_arr; var_s4 > 0; var_s2++, var_s3++, var_s4--) {
    *var_s2 = var_s3;
  }
}

void BoardPieces_Deinit(BoardPieces *boardPieces_ptr) {
  n64HeapUnalloc(boardPieces_ptr->cell_list);
  boardPieces_ptr->cell_list = NULL;
  Ids_Deinit(&boardPieces_ptr->pieceIds);
}
