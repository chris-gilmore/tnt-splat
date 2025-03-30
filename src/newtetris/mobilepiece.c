#include "common.h"

static void   MobilePiece_Minos_setUpdateFlag(Piece *, u8, Point *);
static void   MobilePiece_80064e10_similar_to_Minos_setUpdFlag(Piece *, u8, Point *);
static void   MobilePiece_800652e4_sets_arg0_struct_to_arg1_struct(Piece *, Piece *);
static void   MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(Piece *, Color *, s32);
static void   MobilePiece_800654b0_sixliner_if_zero_if_one(PieceColorFlasher *);

static void MobilePiece_Minos_setUpdateFlag(Piece *piece_ptr, u8 mino_idx, Point *pnt_ptr) {
  register s32 delta_x;
  register s32 delta_y;
  register Position *local_mino_pos;
  register s32 sin_val;
  register s32 cos_val;

  sin_val = FUN_026900_800608f4_oneliner_shift6_1(piece_ptr->physicalCkwRotValue);
  cos_val = FUN_026900_80060914_oneliner_shift6_2(piece_ptr->physicalCkwRotValue);

  local_mino_pos = &piece_ptr->pieceDef_ptr->local_mino_pos_arr[mino_idx];

  delta_x = ((local_mino_pos->x << 8) - piece_ptr->physicalRotOrigin.x) + 0x80;
  delta_y = ((local_mino_pos->y << 8) - piece_ptr->physicalRotOrigin.y) + 0x80;

  delta_x = (delta_x * g_minos_ptr->scale) >> 8;
  delta_y = (delta_y * g_minos_ptr->scale) >> 8;

  pnt_ptr->x = ((delta_x * cos_val) - (delta_y * sin_val)) >> 14;
  pnt_ptr->y = ((delta_x * sin_val) + (delta_y * cos_val)) >> 14;
}

static void MobilePiece_80064e10_similar_to_Minos_setUpdFlag(Piece *piece_ptr, u8 mino_idx, Point *pnt_ptr) {
  register s32 delta_x;
  register s32 delta_y;
  register Position *local_mino_pos;
  register s32 sin_val;
  register s32 cos_val;

  sin_val = FUN_026900_800608f4_oneliner_shift6_1(piece_ptr->physicalCkwRotValue);
  cos_val = FUN_026900_80060914_oneliner_shift6_2(piece_ptr->physicalCkwRotValue);

  local_mino_pos = &piece_ptr->pieceDef_ptr->local_mino_pos_arr[mino_idx];

  delta_x = ((local_mino_pos->x << 8) - piece_ptr->physicalRotOrigin.x) + 0x80;
  delta_y = ((local_mino_pos->y << 8) - piece_ptr->physicalRotOrigin.y) + 0x80;

  delta_x = (delta_x * g_minos_ptr->scale) >> 8;
  delta_y = (delta_y * g_minos_ptr->scale) >> 8;

  pnt_ptr->x = (((delta_x * cos_val) - (delta_y * sin_val)) >> 14) + piece_ptr->physicalPos.x;
  pnt_ptr->y = (((delta_x * sin_val) + (delta_y * cos_val)) >> 14) + piece_ptr->physicalPos.y;
}

void MobilePiece_80064f54_fourliner_loops_4_times(Piece *piece_ptr, s32 arg1) {
  register s32 i;

  i = 0;
  do {
    Minos_80070528_Morph(&piece_ptr->mino_arr[i]);
  } while (++i < 4);
}

void MobilePiece_Render(Piece *piece_ptr) {
  UnkStruct_8 sp3C;
  Point sp38;
  register u16 savedPhysicalCkwRotValue;
  register s32 i;
  register Mino *mino_ptr;

  Minos_SetAlpha(piece_ptr->alpha);
  debug_print2("AFTER", "Minos_SetAlpha");
  Minos_BeginRender(g_minos_ptr);
  debug_print2("AFTER", "Minos_BeginRender");
  Minos_SetVtxTransform(1);
  debug_print2("AFTER", "Minos_SetVtxTransform");
  setPointAngle(sp3C.unk6, piece_ptr->physicalPos.x, piece_ptr->physicalPos.y, 0);
  setPointAngle(sp3C.unkC, 0, 0, piece_ptr->physicalCkwRotValue & 0x3FFF);
  savedPhysicalCkwRotValue = piece_ptr->physicalCkwRotValue;
  piece_ptr->physicalCkwRotValue &= ~0x3FFF;
  for (i = 0; i < 4; i++) {
    MobilePiece_Minos_setUpdateFlag(piece_ptr, i, &sp38);
    setPointAngle(sp3C.unk0, sp38.x, sp38.y, 0);
    mino_ptr = &piece_ptr->mino_arr[i];
    mino_ptr->unk1 |= 1;
    debug_print2("AFTER", "Mino_SetUpdateFlag");
    Minos_Mino_Render(mino_ptr, &sp3C);
    debug_print2("AFTER", "Mino_Render");
  }
  piece_ptr->physicalCkwRotValue = savedPhysicalCkwRotValue;
  Minos_EndRender(g_minos_ptr);
  debug_print2("AFTER", "Minos_EndRender");
}

u8 MobilePiece_80065154_sevenliner_loops_4_times_v1_retbool(Piece *piece_ptr, s32 y) {
  register s32 i;
  Point pnt;

  for (i = 0; i < 4; i++) {
    MobilePiece_80064e10_similar_to_Minos_setUpdFlag(piece_ptr, i, &pnt);
    if (pnt.y < y) {
      return TRUE;
    }
  }
  return FALSE;
}

u8 MobilePiece_800651c8_sevenliner_loops_4_times_v2_retbool(Piece *piece_ptr) {
  register s32 i;
  Point pnt;

  for (i = 0; i < 4; i++) {
    MobilePiece_80064e10_similar_to_Minos_setUpdFlag(piece_ptr, i, &pnt);
    if (!BoardP_IsPointEmpty(pnt.x, pnt.y)) {
      return FALSE;
    }
  }
  return TRUE;
}

void MobilePiece_80065238_sevenliner_loops_4_times(Piece *arg0, Piece *arg1) {
  register s32 i;

  MobilePiece_800652e4_sets_arg0_struct_to_arg1_struct(arg0, arg1);
  arg0->pieceDef_ptr = arg1->pieceDef_ptr;
  arg0->alpha = arg1->alpha;
  i = 0;
  do {
    Minos_80070398_fourteenliner(&arg0->mino_arr[i], &arg1->mino_arr[i]);
  } while (++i < 4);
}

static void MobilePiece_800652e4_sets_arg0_struct_to_arg1_struct(Piece *arg0, Piece *arg1) {
  arg0->physicalCkwRotValue = arg1->physicalCkwRotValue;
  arg0->physicalRotOrigin = arg1->physicalRotOrigin;
  arg0->physicalPos = arg1->physicalPos;
}

void MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(Piece *piece_ptr, Color *color_ptr) {
  register s32 i;

  i = 0;
  do {
    Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(&piece_ptr->mino_arr[i], color_ptr);
  } while (++i < 4);
}

static void MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(Piece *piece_ptr, Color *color_ptr, s32 arg2) {
  register s32 i;

  i = 0;
  do {
    Minos_80070860_fortyliner(&piece_ptr->mino_arr[i], color_ptr, arg2);
  } while (++i < 4);
}

void MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(Piece *piece_ptr, PieceDefinition *pieceDef_ptr, Point physicalPos, Point physicalRotOrigin, u16 physicalCkwRotValue, u8 alpha) {
  register s32 i;

  piece_ptr->pieceDef_ptr = pieceDef_ptr;
  piece_ptr->physicalPos = physicalPos;
  piece_ptr->physicalRotOrigin = physicalRotOrigin;
  piece_ptr->physicalCkwRotValue = physicalCkwRotValue;
  piece_ptr->alpha = alpha;
  i = 0;
  do {
    Minos_800702e4_nineliner(&piece_ptr->mino_arr[i]);
  } while (++i < 4);
  MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(piece_ptr, pieceDef_ptr->color_ptr);
}

static void MobilePiece_800654b0_sixliner_if_zero_if_one(PieceColorFlasher *flasher_ptr) {
  switch (flasher_ptr->state) {
  case 0:
    flasher_ptr->state = 1;
    MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(flasher_ptr->piece_ptr, &flasher_ptr->alt_color, 0xC);
    break;
  case 1:
    flasher_ptr->state = 0;
    MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(flasher_ptr->piece_ptr, &flasher_ptr->main_color, 0xC);
    break;
  }
}

void MobilePiece_8006553c_nineliner_sets_arg0_struct(PieceColorFlasher *flasher_ptr, Piece *piece_ptr) {
  flasher_ptr->enabled = FALSE;
  flasher_ptr->piece_ptr = piece_ptr;
  flasher_ptr->main_color = *piece_ptr->pieceDef_ptr->color_ptr;
  flasher_ptr->alt_color = g_color_white;
}

void MobilePiece_800655c4_oneliner_if_calls_fun(PieceColorFlasher *flasher_ptr, s32 arg1) {
  if (!flasher_ptr->enabled) {
    return;
  }

  if (flasher_ptr->piece_ptr->mino_arr[0].unk2 == 0) {
    MobilePiece_800654b0_sixliner_if_zero_if_one(flasher_ptr);
  }
}

// ensable flasher
void MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(PieceColorFlasher *flasher_ptr) {
  if (flasher_ptr->enabled) {
    return;
  }

  flasher_ptr->enabled = TRUE;
  flasher_ptr->state = 1;
  MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(flasher_ptr->piece_ptr, &flasher_ptr->alt_color, 0xC);
}

// disable flasher
void MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c(PieceColorFlasher *flasher_ptr) {
  if (!flasher_ptr->enabled) {
    return;
  }

  flasher_ptr->enabled = FALSE;
  MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2(flasher_ptr->piece_ptr, &flasher_ptr->main_color, 0x4);
}

void MobilePiece_SetAlternateColor(PieceColorFlasher *flasher_ptr, Color *alt_color_ptr) {
  flasher_ptr->alt_color = *alt_color_ptr;
}
