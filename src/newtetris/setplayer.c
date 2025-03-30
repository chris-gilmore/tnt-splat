#include "common.h"

void Game_SetGlobalPointers(u8 playerNum) {
  register Game *game_ptr = &g_game;

  g_currentplayer    = playerNum;

  g_tetris_ptr       =  game_ptr->tetris_ptr_arr[playerNum];
  g_cubeTiles_ptr    = &game_ptr->cubeTiles;
  g_landfill_ptr     = &game_ptr->landfill;

  g_garbage_ptr      =  g_tetris_ptr->garbage_ptr;
  g_frameAct_ptr     = &g_tetris_ptr->frameAct;
  g_minos_ptr        = &g_tetris_ptr->minos;
  g_lineScan_ptr     = &g_tetris_ptr->lineScan;
  g_squares_ptr      = &g_tetris_ptr->squares;
  D_8011FBC0         = &g_tetris_ptr->unk768;
  g_pfGfx_ptr        = &g_tetris_ptr->pfGfx;
  g_gameStats_ptr    = &g_tetris_ptr->gameStats;

  g_mobileCubes_ptr  = &g_tetris_ptr->board.mobileCubes;
  g_fallingCubes_ptr = &g_tetris_ptr->board.fallingCubes;
  g_next_cell_id_ptr = &g_tetris_ptr->board.next_cell_id;
  g_boardPieces_ptr  = &g_tetris_ptr->board.boardPieces;
  g_currentPiece_ptr = &g_tetris_ptr->board.currentPiece;
  g_nextPieces_ptr   = &g_tetris_ptr->board.nextPieces;
}

void PlayerVars_SetGlobalPointers(u8 playerNum) {
  g_PV_ptr = &g_PV_arr[playerNum];
}
