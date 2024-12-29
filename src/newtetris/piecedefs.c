#include "common.h"

static PieceDefinition pieceDefinition_L = {
  0,
  { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
  { 0x100, 0x180 },
  { { 1, 1 }, { 1, 1 }, { 0, 1 }, { 0, 1 } },
  &g_color_L,
  { 0, 0 },
  3,
};

static PieceDefinition pieceDefinition_J = {
  1,
  { { 2, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
  { 0x200, 0x180 },
  { { 1, 1 }, { 2, 1 }, { 2, 1 }, { 1, 1 } },
  &g_color_J,
  { 0, 0 },
  1,
};

static PieceDefinition pieceDefinition_Z = {
  2,
  { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
  { 0x180, 0x100 },
  { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 1 } },
  &g_color_Z,
  { 0, 0 },
  0,
};

static PieceDefinition pieceDefinition_S = {
  3,
  { { 2, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } },
  { 0x180, 0x100 },
  { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 0 } },
  &g_color_S,
  { 0, 0 },
  0,
};

static PieceDefinition pieceDefinition_T = {
  4,
  { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 } },
  { 0x180, 0x100 },
  { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 } },
  &g_color_T,
  { 0, 0 },
  2,
};

static PieceDefinition pieceDefinition_I = {
  5,
  { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
  { 0x200, 0x80 },
  { { 1, 0 }, { 2, 0 }, { 2, 0 }, { 1, 0 } },
  &g_color_I,
  { -1, 0 },
  0,
};

static PieceDefinition pieceDefinition_O = {
  6,
  { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } },
  { 0x100, 0x100 },
  { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } },
  &g_color_O,
  { -1, -1 },
  0,
};

PieceDefinition *g_pieceDef_ptr_arr[7] = {
  &pieceDefinition_L,
  &pieceDefinition_J,
  &pieceDefinition_Z,
  &pieceDefinition_S,
  &pieceDefinition_T,
  &pieceDefinition_I,
  &pieceDefinition_O,
};

static char piece_names[] = "LJZSTIO";

Point *getCurPieceSpawnOffsetAsPoint(Point *point_ptr, PieceDefinition *pieceDef_ptr) {
  Point point;

  point.x = pieceDef_ptr->curpiece_spawn_offset_pos.x << 8;
  point.y = pieceDef_ptr->curpiece_spawn_offset_pos.y << 8;
  *point_ptr = point;
  return point_ptr;
}

Point *getStartingRotOriginAsPoint(Point *point_ptr, PieceDefinition *pieceDef_ptr) {
  Point point;

  point.x = pieceDef_ptr->rot_origin_pos_arr[pieceDef_ptr->starting_rot_state].x << 8;
  point.y = pieceDef_ptr->rot_origin_pos_arr[pieceDef_ptr->starting_rot_state].y << 8;
  *point_ptr = point;
  return point_ptr;
}

void initPieceColorsScale16(void) {
  register PieceDefinition *pieceDef_ptr;
  register Color *color_ptr;
  register u32 i;

  for (i = 0; i < 7; i++) {
    color_ptr = g_pieceDef_ptr_arr[i]->color_ptr;
    color_ptr->diffuse_red <<= 4;
    color_ptr->diffuse_green <<= 4;
    color_ptr->diffuse_blue <<= 4;
    color_ptr->specular_red <<= 4;
    color_ptr->specular_green <<= 4;
    color_ptr->specular_blue <<= 4;
    pieceDef_ptr = g_pieceDef_ptr_arr[i];
  }
}
