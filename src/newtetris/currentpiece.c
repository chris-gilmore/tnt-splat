#include "common.h"

CurrentPiece *g_currentPiece_ptr;
static Point curPieceSpawnBasePoint = { 0x0500, 0xFF00 };
static u8 D_800D0524 = 7;  // unused

static void   CurrentPiece_80066920_sixteenliner(CurrentPiece *, s32);
static u16    getStartingRotationAngle(u8);
static u8     getStartingRotationState(u8);
static void   CurrentPiece_8006705c_twoliner_setstuff_0x30_0x04(CurrentPiece *);
static u8     CurrentPiece_80066d0c_calls_pf_xy_2_struct_loops4times_retbool(CurrentPiece *);
static u8     CurrentPiece_80066ed4_maybeRotCCkw_retbool(CurrentPiece *, s32, s32, s32);
static u8     CurrentPiece_80067020_twoliner_retbool(CurrentPiece *);
static u8     CurrentPiece_80067078_twelveliner_retbool(CurrentPiece *);
static void   CurrentPiece_800675a8_fiveliner_loops4times(void);
static void   CurrentPiece_80067708_eightliner_interesting_1_2_8_10(CurrentPiece *);

static void CurrentPiece_80066920_sixteenliner(CurrentPiece *currentPiece_ptr, s32 arg1) {
  register u8 temp_t0;
  register u8 temp_t2;
  register u8 temp_t4;
  Point sp30;
  Point sp2C;

  sp30.x = currentPiece_ptr->piece.physicalPos.x;
  sp30.y = currentPiece_ptr->logicalPos.y << 8;
  sp2C.x = currentPiece_ptr->piece.physicalRotOrigin.x;
  sp2C.y = (currentPiece_ptr->logicalRotOrigin.y << 8) + 0x80;
  GhostPiece_800667dc_twelveliner_sets_struct(&currentPiece_ptr->ghostPiece, sp30, sp2C, currentPiece_ptr->logicalRotCkwState << 14);
  temp_t0 = currentPiece_ptr->ghostPiece.piece.physicalPos.x >> 8;
  temp_t2 = currentPiece_ptr->ghostPiece.piece.physicalPos.y >> 8;
  temp_t4 = currentPiece_ptr->ghostPiece.piece.physicalCkwRotValue >> 14;
  if (currentPiece_ptr->ghostPiece.unk52A) {
    if (FUN_003E40_8003dda8_twentyfiveliner_nested_loops(temp_t0, temp_t2, temp_t4) || FUN_003E40_8003dbc0_twentyliner_nested_loops(temp_t0, temp_t2, temp_t4)) {
      MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(&currentPiece_ptr->ghostPiece.flasher);
    } else {
      MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c(&currentPiece_ptr->ghostPiece.flasher);
    }
  }
  if (MobilePiece_80065154_sevenliner_loops_4_times_v1_retbool(&currentPiece_ptr->ghostPiece.piece, 0)) {
    MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(&currentPiece_ptr->flasher);
  } else {
    MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c(&currentPiece_ptr->flasher);
  }
  GhostPiece_800666d0_sixliner_loops_arg1_times(&currentPiece_ptr->ghostPiece, arg1);
}

Point *getCurPieceSpawnPoint(Point *point_ptr, u8 pieceType) {
  register PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[pieceType];
  Point spawnPoint;
  Point spawnOffsetPoint;

  getCurPieceSpawnOffsetAsPoint(&spawnOffsetPoint, pieceDef_ptr);
  spawnPoint.x = spawnOffsetPoint.x + curPieceSpawnBasePoint.x;
  getCurPieceSpawnOffsetAsPoint(&spawnOffsetPoint, pieceDef_ptr);
  spawnPoint.y = spawnOffsetPoint.y + curPieceSpawnBasePoint.y;
  *point_ptr = spawnPoint;
  return point_ptr;
}

Point *getStartingOriginOfRotationPoint(Point *point_ptr, u8 pieceType) {
  register PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[pieceType];
  Point rotOriginPoint;

  getStartingRotOriginAsPoint(&rotOriginPoint, pieceDef_ptr);
  rotOriginPoint.x += 0x80;
  rotOriginPoint.y += 0x80;
  *point_ptr = rotOriginPoint;
  return point_ptr;
}

static u16 getStartingRotationAngle(u8 pieceType) {
  register PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[pieceType];

  return pieceDef_ptr->starting_rot_state << 14;
}

static u8 getStartingRotationState(u8 pieceType) {
  PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[pieceType];

  return pieceDef_ptr->starting_rot_state;
}

void rotate_and_translate_mino(u8 mino_idx, Position *mino_pos) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;
  register s32 delta_x;
  register s32 delta_y;
  register s32 sin_val = g_trig_tbl[currentPiece_ptr->logicalRotCkwState].sin;
  register s32 cos_val = g_trig_tbl[currentPiece_ptr->logicalRotCkwState].cos;
  register Position *local_mino_pos = &currentPiece_ptr->piece.pieceDef_ptr->local_mino_pos_arr[mino_idx];

  delta_x = local_mino_pos->x - currentPiece_ptr->logicalRotOrigin.x;
  delta_y = local_mino_pos->y - currentPiece_ptr->logicalRotOrigin.y;

  mino_pos->x = ((delta_x * cos_val) - (delta_y * sin_val)) + currentPiece_ptr->logicalPos.x;
  mino_pos->y = ((delta_x * sin_val) + (delta_y * cos_val)) + currentPiece_ptr->logicalPos.y;
}

void CurrentPiece_80066cc8_fourliner(void) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;
  UnkStruct_4 sp24;

  sp24.pieceType = currentPiece_ptr->pieceType;
  sp24.numMinos = 4;
  sp24.minoLockedPos_ptr = currentPiece_ptr->minoLockedPos_arr;
  BoardP_8006df38_twentyfiveliner_3_loops(&sp24);
}

static u8 CurrentPiece_80066d0c_calls_pf_xy_2_struct_loops4times_retbool(CurrentPiece *currentPiece_ptr) {
  register s32 i;
  Position pos;
  register Cell *cell_ptr;

  for (i = 0; i < 4; i++) {
    rotate_and_translate_mino(i, &pos);
    cell_ptr = BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(pos.x, pos.y);
    if (cell_ptr->piece_type != EMPTY_CELL) {
      return FALSE;
    }
  }
  return TRUE;
}

u8 CurrentPiece_80066d8c_maybeRotCkw_retbool(CurrentPiece *currentPiece_ptr, s32 arg1, s32 arg2, s32 arg3) {
  register PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[currentPiece_ptr->pieceType];
  register u8 temp_s1;

  currentPiece_ptr->logicalPos.x += arg1;
  currentPiece_ptr->logicalPos.y += arg2;
  currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState + arg3) & 3;
  currentPiece_ptr->logicalRotOrigin = pieceDef_ptr->rot_origin_pos_arr[currentPiece_ptr->logicalRotCkwState];

  temp_s1 = CurrentPiece_80066d0c_calls_pf_xy_2_struct_loops4times_retbool(currentPiece_ptr);

  currentPiece_ptr->logicalPos.x -= arg1;
  currentPiece_ptr->logicalPos.y -= arg2;
  currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState - arg3) & 3;
  currentPiece_ptr->logicalRotOrigin = pieceDef_ptr->rot_origin_pos_arr[currentPiece_ptr->logicalRotCkwState];

  return temp_s1;
}

static u8 CurrentPiece_80066ed4_maybeRotCCkw_retbool(CurrentPiece *currentPiece_ptr, s32 arg1, s32 arg2, s32 arg3) {
  register PieceDefinition *pieceDef_ptr = g_pieceDef_ptr_arr[currentPiece_ptr->pieceType];

  currentPiece_ptr->logicalPos.x += arg1;
  currentPiece_ptr->logicalPos.y += arg2;
  currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState + arg3) & 3;
  currentPiece_ptr->logicalRotOrigin = pieceDef_ptr->rot_origin_pos_arr[currentPiece_ptr->logicalRotCkwState];
  if (!CurrentPiece_80066d0c_calls_pf_xy_2_struct_loops4times_retbool(currentPiece_ptr)) {
    currentPiece_ptr->logicalPos.x -= arg1;
    currentPiece_ptr->logicalPos.y -= arg2;
    currentPiece_ptr->logicalRotCkwState = (currentPiece_ptr->logicalRotCkwState - arg3) & 3;
    currentPiece_ptr->logicalRotOrigin = pieceDef_ptr->rot_origin_pos_arr[currentPiece_ptr->logicalRotCkwState];
    return FALSE;
  }
  return TRUE;
}

static u8 CurrentPiece_80067020_twoliner_retbool(CurrentPiece *currentPiece_ptr) {
  if (((currentPiece_ptr->logicalPos.x << 8) != currentPiece_ptr->piece.physicalPos.x) || ((currentPiece_ptr->logicalPos.y << 8) != currentPiece_ptr->piece.physicalPos.y)) {
    return FALSE;
  }
  return TRUE;
}

static void CurrentPiece_8006705c_twoliner_setstuff_0x30_0x04(CurrentPiece *currentPiece_ptr) {
  currentPiece_ptr->piece.physicalPos.y += currentPiece_ptr->fallVelocity;
  currentPiece_ptr->lockDelay = 20;
}

static u8 CurrentPiece_80067078_twelveliner_retbool(CurrentPiece *currentPiece_ptr) {
  if (currentPiece_ptr->piece.physicalPos.x == (currentPiece_ptr->logicalPos.x << 8)) {
    return CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 1, 0);
  }
  else if (currentPiece_ptr->piece.physicalPos.x < (currentPiece_ptr->logicalPos.x << 8)) {
    if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, -1, 1, 0)) {
      return CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 1, 0);
    }
  }
  else {  // currentPiece_ptr->piece.physicalPos.x > (currentPiece_ptr->logicalPos.x << 8)
    if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, 1, 1, 0)) {
      return CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 1, 0);
    }
  }
  return FALSE;
}

void CurrentPiece_8006715c_twelveliner_plays_SFX(CurrentPiece *currentPiece_ptr) {
  if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, -1, 0, 0)) {
    if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, -1, -1, 0)) {
      currentPiece_ptr->logicalPos.x -= 1;
      currentPiece_ptr->possibleMoves &= ~0x1;  // reset LEFT flag
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 1);
      return;
    }
    if (currentPiece_ptr->isLocked) {
      currentPiece_ptr->piece.physicalPos.y = currentPiece_ptr->logicalPos.y << 8;
      currentPiece_ptr->logicalPos.x -= 1;
      currentPiece_ptr->possibleMoves &= ~0x1;  // reset LEFT flag
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 1);
    }
  }
}

void CurrentPiece_80067254_twelveliner_plays_SFX(CurrentPiece *currentPiece_ptr) {
  if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, 1, 0, 0)) {
    if (CurrentPiece_80066d8c_maybeRotCkw_retbool(currentPiece_ptr, 1, -1, 0)) {
      currentPiece_ptr->logicalPos.x += 1;
      currentPiece_ptr->possibleMoves &= ~0x2;  // reset RIGHT flag
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 1);
      return;
    }
    if (currentPiece_ptr->isLocked) {
      currentPiece_ptr->piece.physicalPos.y = currentPiece_ptr->logicalPos.y << 8;
      currentPiece_ptr->logicalPos.x += 1;
      currentPiece_ptr->possibleMoves &= ~0x2;  // reset RIGHT flag
      Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 1);
    }
  }
}

// wall kick tests
void CurrentPiece_8006734c_thirtyliner_looks_interesting(CurrentPiece *currentPiece_ptr, s8 rotate_direction) {
  register u8 can_rotate;

  if (currentPiece_ptr->num_rotate_angle_steps != 0) {
    return;
  }

  can_rotate = CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 0, rotate_direction);
  if (rotate_direction == -1) {  // counterclockwise
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 1, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, -1, 0, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 1, 0, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, -1, rotate_direction);
    }
  } else {  // clockwise
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, 1, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 1, 0, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, -1, 0, rotate_direction);
    }
    if (!can_rotate) {
      can_rotate |= CurrentPiece_80066ed4_maybeRotCCkw_retbool(currentPiece_ptr, 0, -1, rotate_direction);
    }
  }
  if (can_rotate) {
    if (rotate_direction == -1) {  // counterclockwise
      currentPiece_ptr->rotate_angle_step = -0x1000;
      currentPiece_ptr->num_rotate_angle_steps = 4;
    } else {  // clockwise
      currentPiece_ptr->rotate_angle_step = 0x1000;
      currentPiece_ptr->num_rotate_angle_steps = 4;
    }
    Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0);
    currentPiece_ptr->possibleMoves &= ~0x8;   // reset A button
    currentPiece_ptr->possibleMoves &= ~0x10;  // reset B button
  }
}

static void CurrentPiece_800675a8_fiveliner_loops4times(void) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;
  register s32 i;

  for (i = 0; i < 4; i++) {
    rotate_and_translate_mino(i, &currentPiece_ptr->minoLockedPos_arr[i]);
  }
}

void CurrentPiece_80067604_fourteenliner_loops4times(void) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;
  register s32 i;

  Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 2);
  CurrentPiece_800675a8_fiveliner_loops4times();
  CurrentPiece_80066cc8_fourliner();
  currentPiece_ptr->qWinLoseIndicator = 1;
  for (i = 0; i < 4; i++) {
    if (currentPiece_ptr->minoLockedPos_arr[i].y < 0) {
      currentPiece_ptr->state = 2;
      currentPiece_ptr->qWinLoseIndicator = 2;
      return;
    }
  }
  currentPiece_ptr->state = 0;
}

// pressing Up (drop the piece to the bottom)
void CurrentPiece_800676ac_fourliner_looper(CurrentPiece *currentPiece_ptr) {
  while (CurrentPiece_80067078_twelveliner_retbool(currentPiece_ptr));
  currentPiece_ptr->piece.physicalPos.y = currentPiece_ptr->logicalPos.y << 8;
}

static void CurrentPiece_80067708_eightliner_interesting_1_2_8_10(CurrentPiece *currentPiece_ptr) {
  if (currentPiece_ptr->possibleMoves & 0x1) {   // LEFT
    CurrentPiece_8006715c_twelveliner_plays_SFX(currentPiece_ptr);
  }
  if (currentPiece_ptr->possibleMoves & 0x2) {   // RIGHT
    CurrentPiece_80067254_twelveliner_plays_SFX(currentPiece_ptr);
  }
  if (currentPiece_ptr->possibleMoves & 0x8) {   // A
    CurrentPiece_8006734c_thirtyliner_looks_interesting(currentPiece_ptr, 1);  // clockwise
  }
  if (currentPiece_ptr->possibleMoves & 0x10) {  // B
    CurrentPiece_8006734c_thirtyliner_looks_interesting(currentPiece_ptr, -1);  // counterclockwise
  }
}

u8 CurrentPiece_800677b8_twohundredliner_doit_last(CurrentPiece *currentPiece_ptr, s32 arg1) {
  register Piece *temp_s0 = &currentPiece_ptr->piece;
  register s16 temp_s1;
  register s16 temp_s2;
  register s16 temp_s3;
  register s16 temp_s4;

  MobilePiece_800655c4_oneliner_if_calls_fun(&currentPiece_ptr->flasher, arg1);
  MobilePiece_80064f54_fourliner_loops_4_times(&currentPiece_ptr->piece, arg1);
  while (arg1 != 0) {
    if (currentPiece_ptr->state != 1) {
      break;
    }
    currentPiece_ptr->qWinLoseIndicator = 0;
    currentPiece_ptr->isLocked = temp_s0->physicalPos.y >= ((currentPiece_ptr->logicalPos.y << 8) - currentPiece_ptr->fallVelocity);
    CurrentPiece_80067708_eightliner_interesting_1_2_8_10(currentPiece_ptr);
    temp_s1 = (currentPiece_ptr->logicalRotOrigin.x << 8) + 0x80;
    temp_s2 = (currentPiece_ptr->logicalRotOrigin.y << 8) + 0x80;
    if (temp_s0->physicalRotOrigin.x < temp_s1) {
      if (temp_s0->physicalRotOrigin.x < temp_s1 - 0x40) {
        temp_s0->physicalRotOrigin.x += 0x40;
      } else {
        temp_s0->physicalRotOrigin.x = temp_s1;
      }
    }
    if (temp_s0->physicalRotOrigin.y < temp_s2) {
      if (temp_s0->physicalRotOrigin.y < temp_s2 - 0x40) {
        temp_s0->physicalRotOrigin.y += 0x40;
      } else {
        temp_s0->physicalRotOrigin.y = temp_s2;
      }
    }
    if (temp_s1 < temp_s0->physicalRotOrigin.x) {
      if (temp_s1 + 0x40 < temp_s0->physicalRotOrigin.x) {
        temp_s0->physicalRotOrigin.x -= 0x40;
      } else {
        temp_s0->physicalRotOrigin.x = temp_s1;
      }
    }
    if (temp_s2 < temp_s0->physicalRotOrigin.y) {
      if (temp_s2 + 0x40 < temp_s0->physicalRotOrigin.y) {
        temp_s0->physicalRotOrigin.y -= 0x40;
      } else {
        temp_s0->physicalRotOrigin.y = temp_s2;
      }
    }
    temp_s3 = currentPiece_ptr->logicalPos.x << 8;
    temp_s4 = currentPiece_ptr->logicalPos.y << 8;
    if (temp_s3 < temp_s0->physicalPos.x) {
      if (temp_s3 + 0x40 < temp_s0->physicalPos.x) {
        temp_s0->physicalPos.x -= 0x40;
      } else {
        temp_s0->physicalPos.x = temp_s3;
      }
    }
    if (temp_s0->physicalPos.x < temp_s3) {
      if (temp_s0->physicalPos.x < temp_s3 - 0x40) {
        temp_s0->physicalPos.x += 0x40;
      } else {
        temp_s0->physicalPos.x = temp_s3;
      }
    }
    if (currentPiece_ptr->num_rotate_angle_steps > 0) {
      temp_s0->physicalCkwRotValue += currentPiece_ptr->rotate_angle_step;
      currentPiece_ptr->num_rotate_angle_steps--;
    }
    if (!currentPiece_ptr->isLocked) {
      CurrentPiece_8006705c_twoliner_setstuff_0x30_0x04(currentPiece_ptr);
    } else if (CurrentPiece_80067078_twelveliner_retbool(currentPiece_ptr)) {
      CurrentPiece_8006705c_twoliner_setstuff_0x30_0x04(currentPiece_ptr);
    } else {
      currentPiece_ptr->piece.physicalPos.y = currentPiece_ptr->logicalPos.y << 8;
    }
    if (CurrentPiece_80067020_twoliner_retbool(currentPiece_ptr)) {
      if (currentPiece_ptr->lockDelay == 0) {
        CurrentPiece_80067604_fourteenliner_loops4times();
      } else {
        currentPiece_ptr->lockDelay--;
      }
    }
    arg1--;
  }
  if (currentPiece_ptr->state == 1) {
    CurrentPiece_80066920_sixteenliner(currentPiece_ptr, 1);
  }
  return currentPiece_ptr->qWinLoseIndicator;
}

s8 CurrentPiece_80067bc0_sixliner_loops4times(CurrentPiece *currentPiece_ptr) {
  register s8 var_a1 = 20;
  register s32 i;

  for (i = 0; i < 4; i++) {
    if (currentPiece_ptr->minoLockedPos_arr[i].y < var_a1) {
      var_a1 = currentPiece_ptr->minoLockedPos_arr[i].y;
    }
  }
  return var_a1;
}

void CurrentPiece_80067c1c_fifteenliner_loops3times(CurrentPiece *currentPiece_ptr, BoundingBox *bbox_ptr) {
  register u32 i;
  register s32 x;
  register s32 y;

  FUN_026900_sets_arg0_struct_to_arg1_arg2(bbox_ptr, currentPiece_ptr->minoLockedPos_arr[0].x, currentPiece_ptr->minoLockedPos_arr[0].y);
  for (i = 1; i < 4; i++) {
    x = currentPiece_ptr->minoLockedPos_arr[i].x;
    y = currentPiece_ptr->minoLockedPos_arr[i].y;
    if (x < bbox_ptr->x_min) {
      bbox_ptr->x_min = x;
    }
    if (bbox_ptr->x_max < x) {
      bbox_ptr->x_max = x;
    }
    if (y < bbox_ptr->y_min) {
      bbox_ptr->y_min = y;
    }
    if (bbox_ptr->y_max < y) {
      bbox_ptr->y_max = y;
    }
  }
}

s32 CurrentPiece_80067d1c_twoliner(CurrentPiece *currentPiece_ptr) {
  BoundingBox bbox;

  CurrentPiece_80067c1c_fifteenliner_loops3times(currentPiece_ptr, &bbox);
  return (bbox.y_max - bbox.y_min) + 1;
}

void CurrentPiece_Render(CurrentPiece *currentPiece_ptr) {
  if (currentPiece_ptr->state == 1) {
    Minos_SetScale(0x100);
    currentPiece_ptr->ghostPiece.piece.alpha = (currentPiece_ptr->alpha * 0x60) >> 8;
    GhostPiece_Render(&currentPiece_ptr->ghostPiece);
    currentPiece_ptr->piece.alpha = currentPiece_ptr->alpha;
    MobilePiece_Render(&currentPiece_ptr->piece);
  }
}

void CurrentPiece_80067dd8_big_fiftyliner(u8 pieceType) {
  register CurrentPiece *currentPiece_ptr = g_currentPiece_ptr;
  Point point;
  Color color;
  Point sp50;
  Point sp4C;
  register u8 temp_t3;
  register u8 temp_t8;
  register u8 temp_t4;
  s32 unused;
  Point sp40;
  Point sp3C;

  currentPiece_ptr->pieceType = pieceType;
  getCurPieceSpawnPoint(&point, pieceType);
  currentPiece_ptr->logicalPos.x = point.x >> 8;
  currentPiece_ptr->logicalPos.y = point.y >> 8;
  getStartingOriginOfRotationPoint(&point, pieceType);
  currentPiece_ptr->logicalRotOrigin.x = point.x >> 8;
  currentPiece_ptr->logicalRotOrigin.y = point.y >> 8;
  currentPiece_ptr->alpha = 0xFF;
  currentPiece_ptr->logicalRotCkwState = getStartingRotationState(pieceType);
  currentPiece_ptr->rotate_angle_step = 0;
  currentPiece_ptr->num_rotate_angle_steps = 0;
  currentPiece_ptr->lockDelay = 20;
  currentPiece_ptr->possibleMoves = 0;
  currentPiece_ptr->isLocked = 0;
  currentPiece_ptr->fallVelocity = currentPiece_ptr->fallVelocityCopy;
  currentPiece_ptr->state = 1;
  currentPiece_ptr->qWinLoseIndicator = 0;
  getCurPieceSpawnPoint(&sp3C, pieceType);
  getStartingOriginOfRotationPoint(&sp40, pieceType);
  MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&currentPiece_ptr->piece, g_pieceDef_ptr_arr[pieceType], sp3C, sp40, getStartingRotationAngle(pieceType), 0xFF);
  MobilePiece_8006553c_nineliner_sets_arg0_struct(&currentPiece_ptr->flasher, &currentPiece_ptr->piece);
  color = *currentPiece_ptr->piece.pieceDef_ptr->color_ptr;
  Color_Blend(&color, &g_color_red, 0xC0);
  MobilePiece_SetAlternateColor(&currentPiece_ptr->flasher, &color);
  GhostPiece_800668ec_sixliner_inits_struct(&currentPiece_ptr->ghostPiece, g_pieceDef_ptr_arr[currentPiece_ptr->pieceType], currentPiece_ptr->unk538);
  sp50.x = currentPiece_ptr->piece.physicalPos.x;
  sp50.y = currentPiece_ptr->logicalPos.y << 8;
  sp4C.x = currentPiece_ptr->piece.physicalRotOrigin.x;
  sp4C.y = (currentPiece_ptr->logicalRotOrigin.y << 8) + 0x80;
  GhostPiece_800667dc_twelveliner_sets_struct(&currentPiece_ptr->ghostPiece, sp50, sp4C, currentPiece_ptr->logicalRotCkwState << 14);
  temp_t3 = currentPiece_ptr->ghostPiece.piece.physicalPos.x >> 8;
  temp_t8 = currentPiece_ptr->ghostPiece.piece.physicalPos.y >> 8;
  temp_t4 = currentPiece_ptr->ghostPiece.piece.physicalCkwRotValue >> 14;
  if (FUN_003E40_8003dda8_twentyfiveliner_nested_loops(temp_t3, temp_t8, temp_t4) || FUN_003E40_8003dbc0_twentyliner_nested_loops(temp_t3, temp_t8, temp_t4)) {
    MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(&currentPiece_ptr->ghostPiece.flasher);
  }
}

void CurrentPiece_80068090_oneliner_sets_0x538_to_1(CurrentPiece *currentPiece_ptr) {
  currentPiece_ptr->unk538 = TRUE;
}
