#include "common.h"

void Game_SetGlobalPointers(u8 playerNum) {
  register Game *game_ptr = &g_game;

  g_currentplayer    = playerNum;

  g_tetris_ptr       =  game_ptr->tetris_ptr_arr[playerNum];
  g_cubeTiles_ptr    = &game_ptr->cubeTiles;
  g_landfill_ptr     = &game_ptr->landfill;

  g_garbage_ptr      =  g_tetris_ptr->garbage_ptr;
  D_8011F220         = &g_tetris_ptr->unk8;
  D_8011FC10         = &g_tetris_ptr->unk7D0;
  g_lineScan_ptr     = &g_tetris_ptr->lineScan;
  D_8011FBA0         = &g_tetris_ptr->unk44C;
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
