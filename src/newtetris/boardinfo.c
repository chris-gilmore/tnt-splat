#include "common.h"

static Point  *get_board_size(Point *, BoardInfo *);
static Point  *get_board_location(Point *, BoardInfo *);

void BoardInfo_Init(BoardInfo *boardInfo_ptr, Point location, s16 unitSize) {
  boardInfo_ptr->location = location;
  boardInfo_ptr->unitSize = unitSize;
}

static Point *get_board_size(Point *pnt_ptr, BoardInfo *boardInfo_ptr) {
  Point pnt;

  pnt.x = boardInfo_ptr->unitSize * 10;
  pnt.y = boardInfo_ptr->unitSize * 20;
  *pnt_ptr = pnt;
  return pnt_ptr;
}

static Point *get_board_location(Point *pnt_ptr, BoardInfo *boardInfo_ptr) {
  *pnt_ptr = boardInfo_ptr->location;
  return pnt_ptr;
}

Point *get_board_center(Point *pnt_ptr, BoardInfo *boardInfo_ptr) {
  Point center;
  Point size;
  Point location;

  get_board_location(&location, boardInfo_ptr);
  get_board_size(&size, boardInfo_ptr);
  center.x = location.x + (size.x >> 1);
  center.y = location.y + (size.y >> 1);
  *pnt_ptr = center;
  return pnt_ptr;
}
