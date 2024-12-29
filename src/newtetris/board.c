#include "common.h"

static void   Board_8006D1E0_doesnothing1(Board *, s32);
static void   Board_8006D1EC_doesnothing2(Board *, s32);
static void   Board_8006D1F8_doesnothing3(Board *);

void Board_Update(Board *board_ptr, s32 arg1) {
  BoardPieces_Update(&board_ptr->boardPieces, arg1);
}

static void Board_8006D1E0_doesnothing1(Board *board_ptr, s32 arg1) {
}

static void Board_8006D1EC_doesnothing2(Board *board_ptr, s32 arg1) {
}

static void Board_8006D1F8_doesnothing3(Board *board_ptr) {
}

void Board_Init(Board *board_ptr, Bag63 *bag63_ptr, UnkStruct_0 *arg2) {
  MobileCubes_Init(220, arg2);
  FallingCubes_Init(200);
  *g_next_cell_id_ptr = 0;
  BoardPieces_Init(&board_ptr->boardPieces);
  NextPieces_Init(bag63_ptr);
  CurrentPiece_80068090_oneliner_sets_0x538_to_1(&board_ptr->currentPiece);
  board_ptr->currentPiece.state = 0;
}

void Board_Deinit(Board *board_ptr) {
  NextPieces_Deinit();
  BoardPieces_Deinit(&board_ptr->boardPieces);
  FallingCubes_Deinit();
  MobileCubes_Deinit();
}
