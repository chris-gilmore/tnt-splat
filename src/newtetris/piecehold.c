#include "common.h"

Point D_800D04C0[8] = {
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
  { 0x003D, 0x0034 },
};

Point D_800D04E0[8][2] = {
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
  { { 0x0025, 0x003A }, { 0x0179, 0x003A } },
};

static void   PieceHold_80065710_twoliner_sets_to_0_and_0xff(PieceHoldPieceShadow *);
static void   PieceHold_80065720_fiveliner_two_traps(PieceHoldPieceShadow *, s32);
static void   PieceHoldPiece_MakeShadowActive(PieceHoldPieceShadow *, u8, Point, Point, u16, s16, s32);
static void   PieceHoldPiece_RenderShadow(PieceHoldPieceShadow *);
static void   PieceHold_8006593c_nineliner_sets_struct_stuff(PieceHoldPieceShadow *, s32);
static void   PieceHoldPiece_FinishSwap(PieceHoldPiece *, s32);
static void   PieceHold_80065a0c_tenliner_adds_sets_struct(PieceHoldPiece *, u32);
static void   PieceHoldPiece_Update(PieceHoldPiece *, s32);
static void   PieceHoldPiece_Render(PieceHoldPiece *);
static void   PieceHoldPiece_MakeActive(PieceHoldPiece *, u8, Point, Point, u16, s16);
static void   PieceHold_80065e20_lots_of_ifs_and_traps(PieceHoldPiece *, Point, Point, u16, s16, u16);
static void   PieceHold_80065fbc_oneliner_calls_fun1(PieceHoldPiece *, PieceHoldPiece *);  // unused
static void   PieceHoldPiece_Init(PieceHoldPiece *);
static void   PieceHold_80065ff8_oneliner_calls_fun2_wunk518(PieceHoldPiece *);
static void   PieceHold_80066020_oneliner_calls_fun3_wunk518(PieceHoldPiece *);
static void   PieceHold_80066048_tenliner_checks_numplayers(Point *, s32, s32, u8);

static void PieceHold_80065710_twoliner_sets_to_0_and_0xff(PieceHoldPieceShadow *shadow_ptr) {
  shadow_ptr->unk0 = 0;
  shadow_ptr->alpha = 0xFF;
}

static void PieceHold_80065720_fiveliner_two_traps(PieceHoldPieceShadow *shadow_ptr, s32 arg1) {
  shadow_ptr->unk6 = 0;
  shadow_ptr->unk4 = (shadow_ptr->unk6 - shadow_ptr->unk2) / arg1;
}

// PieceHoldPiece_MakeShadowActive(&pieceHold_ptr->buf[0].shadow, ihp, pieceHold_ptr->unk1490, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0xC0, pieceHold_ptr->num_anim_frames);
void PieceHoldPiece_MakeShadowActive(PieceHoldPieceShadow *shadow_ptr, u8 ihp, Point arg2, Point arg3, u16 arg4, s16 arg5, s32 arg6) {
  arg2.x += 0x80;
  arg2.y += 0x80;
  MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&shadow_ptr->piece, g_pieceDef_ptr_arr[ihp], arg2, arg3, arg4, 0xFF);
  MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(&shadow_ptr->piece, &g_color_black);
  shadow_ptr->unk2 = 0;
  shadow_ptr->unk6 = 0xAA0;  // 2720
  shadow_ptr->unk4 = (shadow_ptr->unk6 - shadow_ptr->unk2) / arg6;
  shadow_ptr->mino_scale = arg5;
  shadow_ptr->unk0 = 1;
}

static void PieceHoldPiece_RenderShadow(PieceHoldPieceShadow *shadow_ptr) {
  Piece *shadow_piece_ptr;

  if (shadow_ptr->unk0 == 0) {
    return;
  }

  shadow_piece_ptr = &shadow_ptr->piece;
  if (shadow_ptr->alpha == 0xFF) {
    shadow_piece_ptr->alpha = shadow_ptr->unk2 >> 4;
  } else {
    shadow_piece_ptr->alpha = (shadow_ptr->unk2 * shadow_ptr->alpha) >> 12;
  }
  Minos_SetScale(shadow_ptr->mino_scale);
  MobilePiece_Render(shadow_piece_ptr);
}

static void PieceHold_8006593c_nineliner_sets_struct_stuff(PieceHoldPieceShadow *shadow_ptr, s32 arg1) {
  if (shadow_ptr->unk0 != 0) {
    shadow_ptr->unk2 += shadow_ptr->unk4 * arg1;
    if (shadow_ptr->unk4 > 0) {
      if (shadow_ptr->unk2 >= shadow_ptr->unk6) {
        shadow_ptr->unk4 = 0;
        shadow_ptr->unk2 = shadow_ptr->unk6;
      }
    } else if (shadow_ptr->unk2 <= shadow_ptr->unk6) {
      shadow_ptr->unk4 = 0;
      shadow_ptr->unk2 = shadow_ptr->unk6;
    }
  }
}

static void PieceHoldPiece_FinishSwap(PieceHoldPiece *pieceHoldPiece_ptr, s32 arg1) {
  if (pieceHoldPiece_ptr->unk1A == 0) {
    CurrentPiece_80067dd8_big_fiftyliner(pieceHoldPiece_ptr->piece_type);
    pieceHoldPiece_ptr->state = 0;
  }
}

void PieceHold_80065a0c_tenliner_adds_sets_struct(PieceHoldPiece *pieceHoldPiece_ptr, u32 arg1) {
  if (pieceHoldPiece_ptr->unk1A != 0) {
    if (pieceHoldPiece_ptr->unk1A < arg1) {
      arg1 = pieceHoldPiece_ptr->unk1A;
    }
    pieceHoldPiece_ptr->physicalPos.x       += pieceHoldPiece_ptr->unk16.x * arg1;
    pieceHoldPiece_ptr->physicalPos.y       += pieceHoldPiece_ptr->unk16.y * arg1;
    pieceHoldPiece_ptr->physicalRotOrigin.x += pieceHoldPiece_ptr->unkE.x  * arg1;
    pieceHoldPiece_ptr->physicalRotOrigin.y += pieceHoldPiece_ptr->unkE.y  * arg1;
    pieceHoldPiece_ptr->mino_scale          += pieceHoldPiece_ptr->unk8    * arg1;
    pieceHoldPiece_ptr->physicalCkwRotValue += pieceHoldPiece_ptr->unk4    * arg1;
    pieceHoldPiece_ptr->unk1A               -= arg1;
  }
}

static void PieceHoldPiece_Update(PieceHoldPiece *pieceHoldPiece_ptr, s32 arg1) {
  PieceHold_8006593c_nineliner_sets_struct_stuff(&pieceHoldPiece_ptr->shadow, arg1);
  switch (pieceHoldPiece_ptr->state) {
  case 0:
    break;
  case 1:
    MobilePiece_800655c4_oneliner_if_calls_fun(&pieceHoldPiece_ptr->flasher, arg1);
    MobilePiece_80064f54_fourliner_loops_4_times(&pieceHoldPiece_ptr->piece, arg1);
    PieceHold_80065a0c_tenliner_adds_sets_struct(pieceHoldPiece_ptr, arg1);
    break;
  case 2:
    MobilePiece_800655c4_oneliner_if_calls_fun(&pieceHoldPiece_ptr->flasher, arg1);
    MobilePiece_80064f54_fourliner_loops_4_times(&pieceHoldPiece_ptr->piece, arg1);
    PieceHold_80065a0c_tenliner_adds_sets_struct(pieceHoldPiece_ptr, arg1);
    PieceHoldPiece_FinishSwap(pieceHoldPiece_ptr, arg1);
    break;
  default:
    debug_print_reason_routine("PieceHoldPiece_Update", "piecehold.c");
  }
}

static void PieceHoldPiece_Render(PieceHoldPiece *pieceHoldPiece_ptr) {
  register Piece *piece;

  if (pieceHoldPiece_ptr->state == 0) {
    return;
  }

  PieceHoldPiece_RenderShadow(&pieceHoldPiece_ptr->shadow);
  Minos_SetScale(pieceHoldPiece_ptr->mino_scale);
  piece = &pieceHoldPiece_ptr->piece;
  piece->physicalRotOrigin   = pieceHoldPiece_ptr->physicalRotOrigin;
  piece->physicalPos         = pieceHoldPiece_ptr->physicalPos;
  piece->physicalCkwRotValue = pieceHoldPiece_ptr->physicalCkwRotValue;
  MobilePiece_Render(piece);
}

void PieceHoldPiece_MakeActive(PieceHoldPiece *pieceHoldPiece_ptr, u8 piece_type, Point arg2, Point arg3, u16 arg4, s16 mino_scale) {
  Color color;

  pieceHoldPiece_ptr->physicalPos = arg2;
  pieceHoldPiece_ptr->unk16.x = 0;
  pieceHoldPiece_ptr->unk16.y = 0;
  pieceHoldPiece_ptr->physicalRotOrigin = arg3;
  pieceHoldPiece_ptr->unkE.x = 0;
  pieceHoldPiece_ptr->unkE.y = 0;
  pieceHoldPiece_ptr->mino_scale = mino_scale;
  pieceHoldPiece_ptr->unk8 = 0;
  pieceHoldPiece_ptr->physicalCkwRotValue = arg4;
  pieceHoldPiece_ptr->unk4 = 0;
  pieceHoldPiece_ptr->piece_type = piece_type;
  pieceHoldPiece_ptr->unk1A = 0;
  pieceHoldPiece_ptr->state = 1;
  MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&pieceHoldPiece_ptr->piece, g_pieceDef_ptr_arr[piece_type], arg2, arg3, arg4, 0xFF);
  MobilePiece_8006553c_nineliner_sets_arg0_struct(&pieceHoldPiece_ptr->flasher, &pieceHoldPiece_ptr->piece);
  color = *pieceHoldPiece_ptr->piece.pieceDef_ptr->color_ptr;
  Color_Blend(&color, &g_color_red, 0x80);
  MobilePiece_SetAlternateColor(&pieceHoldPiece_ptr->flasher, &color);
  PieceHold_80065710_twoliner_sets_to_0_and_0xff(&pieceHoldPiece_ptr->shadow);
}

static void PieceHold_80065e20_lots_of_ifs_and_traps(PieceHoldPiece *pieceHoldPiece_ptr, Point arg1, Point arg2, u16 arg3, s16 arg4, u16 arg5) {
  pieceHoldPiece_ptr->unk1A = arg5;
  pieceHoldPiece_ptr->unk16.x = (arg1.x - pieceHoldPiece_ptr->physicalPos.x) / arg5;
  pieceHoldPiece_ptr->unk16.y = (arg1.y - pieceHoldPiece_ptr->physicalPos.y) / arg5;
  pieceHoldPiece_ptr->unkE.x  = (arg2.x - pieceHoldPiece_ptr->physicalRotOrigin.x) / arg5;
  pieceHoldPiece_ptr->unkE.y  = (arg2.y - pieceHoldPiece_ptr->physicalRotOrigin.y) / arg5;
  pieceHoldPiece_ptr->unk8    = (arg4   - pieceHoldPiece_ptr->mino_scale) / arg5;
  pieceHoldPiece_ptr->unk4    = (arg3   - pieceHoldPiece_ptr->physicalCkwRotValue) / arg5;
}

// unused
static void PieceHold_80065fbc_oneliner_calls_fun1(PieceHoldPiece *pieceHoldPiece_ptr_A, PieceHoldPiece *pieceHoldPiece_ptr_B) {
  MobilePiece_80065238_sevenliner_loops_4_times(&pieceHoldPiece_ptr_A->piece, &pieceHoldPiece_ptr_B->piece);
}

static void PieceHoldPiece_Init(PieceHoldPiece *pieceHoldPiece_ptr) {
  pieceHoldPiece_ptr->state = 0;
}

static void PieceHold_80065ff8_oneliner_calls_fun2_wunk518(PieceHoldPiece *pieceHoldPiece_ptr) {
  MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(&pieceHoldPiece_ptr->flasher);
}

static void PieceHold_80066020_oneliner_calls_fun3_wunk518(PieceHoldPiece *pieceHoldPiece_ptr) {
  MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c(&pieceHoldPiece_ptr->flasher);
}

static void PieceHold_80066048_tenliner_checks_numplayers(Point *point_ptr, s32 playercount, s32 playerNum, u8 screenNum) {
  Point point;

  switch (playercount) {
  case 1:
    point = D_800D04C0[screenNum];
    Minos_8007104c_fiveliner_nuts(point_ptr, point.x * 4, point.y * 4);
    break;
  case 2:
    point = D_800D04E0[screenNum][playerNum];
    Minos_8007104c_fiveliner_nuts(point_ptr, point.x * 4, point.y * 4);
    break;
  case 3:
  case 4:
    point_ptr->x = 0x800;
    point_ptr->y = -0x240;
    break;
  }
}

void PieceHold_Update(PieceHold *pieceHold_ptr, s32 arg1) {
  PieceHoldPiece_Update(&pieceHold_ptr->buf[0], arg1);
  PieceHoldPiece_Update(&pieceHold_ptr->buf[1], arg1);
}

void PieceHold_Render(PieceHold *pieceHold_ptr) {
  PieceHoldPiece_Render(&pieceHold_ptr->buf[0]);
  PieceHoldPiece_Render(&pieceHold_ptr->buf[1]);
}

void PieceHold_Swap(PieceHold *pieceHold_ptr, CurrentPiece *currentPiece_ptr) {
  register PieceHoldPiece *pieceHoldPiece_ptr;
  register PieceDefinition *pieceDef_ptr;
  register Piece *piece_ptr;
  s32 unused;
  Point sp3C;  // physical origin of rotation
  Point sp38;  // spawn point

  if (!pieceHold_ptr->can_swap) {
    return;
  }

  pieceHoldPiece_ptr = &pieceHold_ptr->buf[pieceHold_ptr->buf_idx];
  pieceDef_ptr = g_pieceDef_ptr_arr[pieceHoldPiece_ptr->piece_type];
  FUN_033310_setPieceDef(&pieceHold_ptr->unk1498, pieceHoldPiece_ptr->piece_type);
  FUN_033310_getPhysicalCurPieceSpawnPos(&sp38, &pieceHold_ptr->unk1498);
  FUN_033310_getPhysicalStartingRotOrigin(&sp3C, &pieceHold_ptr->unk1498);
  PieceHold_80065e20_lots_of_ifs_and_traps(pieceHoldPiece_ptr, sp38, sp3C, pieceHold_ptr->unk1498.pieceDef_ptr->starting_rot_state << 14, 0x100, pieceHold_ptr->num_anim_frames);
  pieceHoldPiece_ptr->state = 2;
  PieceHold_80065720_fiveliner_two_traps(&pieceHoldPiece_ptr->shadow, pieceHold_ptr->num_anim_frames);

  pieceHoldPiece_ptr = &pieceHold_ptr->buf[1 - pieceHold_ptr->buf_idx];
  piece_ptr = &currentPiece_ptr->piece;
  pieceDef_ptr = g_pieceDef_ptr_arr[currentPiece_ptr->pieceType];
  PieceHoldPiece_MakeActive(pieceHoldPiece_ptr, currentPiece_ptr->pieceType, piece_ptr->physicalPos, piece_ptr->physicalRotOrigin, piece_ptr->physicalCkwRotValue, 0x100);
  PieceHold_80065e20_lots_of_ifs_and_traps(pieceHoldPiece_ptr, pieceHold_ptr->unk1490, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0xC0, pieceHold_ptr->num_anim_frames);
  pieceHoldPiece_ptr->state = 1;
  currentPiece_ptr->state = 0;
  PieceHoldPiece_MakeShadowActive(&pieceHoldPiece_ptr->shadow, currentPiece_ptr->pieceType, pieceHold_ptr->unk1490, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0xC0, pieceHold_ptr->num_anim_frames);
  pieceHold_ptr->buf_idx = 1 - pieceHold_ptr->buf_idx;
  PieceHold_Disable(pieceHold_ptr);
}

void PieceHold_Enable(PieceHold *pieceHold_ptr) {
  pieceHold_ptr->can_swap = TRUE;
  PieceHold_80066020_oneliner_calls_fun3_wunk518(&pieceHold_ptr->buf[pieceHold_ptr->buf_idx]);
}

void PieceHold_Disable(PieceHold *pieceHold_ptr) {
  pieceHold_ptr->can_swap = FALSE;
  PieceHold_80065ff8_oneliner_calls_fun2_wunk518(&pieceHold_ptr->buf[pieceHold_ptr->buf_idx]);
}

// PieceHold_Init(&tetris_ptr->pieceHold, &sp3C, 10, 20, arg1->unk8);
// arg4 is game.unkE4F8, which screen? (0..7)
void PieceHold_Init(PieceHold *pieceHold_ptr, u32 *seed_ptr, u8 board_width, u8 board_height, u8 screenNum) {
  register u8 ihp;  // initial hold piece
  register PieceDefinition *pieceDef_ptr;

  FUN_033310_Init(&pieceHold_ptr->unk1498, board_width, board_height);
  pieceHold_ptr->num_anim_frames = 16;
  PieceHold_80066048_tenliner_checks_numplayers(&pieceHold_ptr->unk1490, g_playercount, g_currentplayer, screenNum);
  pieceHold_ptr->buf_idx = 0;
  PieceHoldPiece_Init(&pieceHold_ptr->buf[0]);
  PieceHoldPiece_Init(&pieceHold_ptr->buf[1]);
  *seed_ptr = FUN_026900_PRNG_2(*seed_ptr);
  ihp = *seed_ptr % 7;
  pieceDef_ptr = g_pieceDef_ptr_arr[ihp];
  PieceHoldPiece_MakeActive(&pieceHold_ptr->buf[0], ihp, pieceHold_ptr->unk1490, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0xC0);
  PieceHoldPiece_MakeShadowActive(&pieceHold_ptr->buf[0].shadow, ihp, pieceHold_ptr->unk1490, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0xC0, pieceHold_ptr->num_anim_frames);
  PieceHold_Enable(pieceHold_ptr);
}

void PieceHold_Deinit(PieceHold *pieceHold_ptr) {
  FUN_033310_Deinit(&pieceHold_ptr->unk1498);
}
