#include "common.h"

u8 FUN_0073F0_80041170_fifteenliner_pf_logic_cell(UnkStruct_27 *arg0, u8 arg1) {
  register u8 ret;
  register Cell *cell_ptr;

  if (arg0 == NULL || g_boardPieces_ptr == NULL) {
    return FALSE;
  }

  cell_ptr = g_boardPieces_ptr->cell_ptr_arr[arg1];
  if (cell_ptr->piece_type == EMPTY_CELL) {
    arg0->unk0 = EMPTY_CELL;
    arg0->unk1 = EMPTY_CELL;
    ret = FALSE;
  } else {
    if (Multisquare_isArg0_lessthan_44(cell_ptr->square_id)) {
      arg0->unk0 = 10;
    } else {
      arg0->unk0 = 9;
    }
    arg0->unk1 = cell_ptr->piece_type;
    ret = TRUE;
  }
  arg0->unk2 = cell_ptr->piece_id;
  return ret;
}
