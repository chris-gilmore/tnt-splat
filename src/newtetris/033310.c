#include "common.h"

void FUN_033310_setPieceDef(UnkStruct_16 *arg0, u8 piece_type) {
  arg0->pieceDef_ptr = g_pieceDef_ptr_arr[piece_type];
}

Point *FUN_033310_getPhysicalCurPieceSpawnPos(Point *arg0, UnkStruct_16 *arg1) {
  Point sp1C;

  getCurPieceSpawnOffsetAsPoint(&sp1C, arg1->pieceDef_ptr);
  sp1C.x += (arg1->board_width >> 1) << 8;
  sp1C.y -= 0x100;
  *arg0 = sp1C;
  return arg0;
}

Point *FUN_033310_getPhysicalStartingRotOrigin(Point *arg0, UnkStruct_16 *arg1) {
  Point sp1C;

  getStartingRotOriginAsPoint(&sp1C, arg1->pieceDef_ptr);
  sp1C.x += 0x80;
  sp1C.y += 0x80;
  *arg0 = sp1C;
  return arg0;
}

void FUN_033310_Init(UnkStruct_16 *arg0, u8 board_width, u8 board_height) {
  arg0->board_width = board_width;
  arg0->board_height = board_height;
  arg0->pieceDef_ptr = NULL;
}

void FUN_033310_Deinit(UnkStruct_16 *arg0) {
  arg0->board_width = 0;
  arg0->board_height = 0;
  arg0->pieceDef_ptr = NULL;
}
