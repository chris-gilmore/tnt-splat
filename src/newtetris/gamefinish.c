#include "common.h"

static Color color_gray = { 0x800, 0x800, 0x800, 0xFF0, 0xFF0, 0xFF0 };
static u8 playercount = 0;
static u8 *D_800CFF80 = NULL;  // WIN
static u8 *D_800CFF84 = NULL;  // LOSE
static u8 *D_800CFF88 = NULL;  // GAME OVER

static void   gamefinish_80052AA0_tenliner(UnkStruct_7 *, u32);
static void   gamefinish_80052B30_tenliner(UnkStruct_7 *, Gfx **);
static void   gamefinish_c_line_127(UnkStruct_7 *, s32);
static void   gamefinish_80052D24_oneliner(UnkStruct_7 *, Point);
static void   gamefinish_80052D40_doesnothing(UnkStruct_7 *);
static void   gamefinish_magic_number_180_sprint_twoliner(UnkStruct_20 *);
static void   gamefinish_80052D70_twoliner(UnkStruct_20 *);
static void   gamefinish_80052D8C_nevercalled(UnkStruct_20 *);
static void   gamefinish_80052DA0_oneliner(UnkStruct_20 *, u32);
static void   gamefinish_80052DAC_read_playfield_logic_cell(UnkStruct_20 *);
static void   gamefinish_80052F3C_eightliner(UnkStruct_20 *, u32);
static void   gamefinish_80052FC8_eightliner(UnkStruct_20 *, u32);

static void gamefinish_80052AA0_tenliner(UnkStruct_7 *arg0, u32 arg1) {
  arg0->unk10 += arg0->unk12 * arg1;
  if (arg0->unk10 < 0x500) {
    arg0->unk10 = 0x500;
    arg0->unk12 = 0;
  }
  arg0->unkC += arg0->unkE * arg1;
  arg0->unk14 += arg0->unk16 * arg1;
  if (arg0->unk14 >= 0xFF0) {
    arg0->unk14 = 0xFF0;
    arg0->unk16 = 0;
  }
}

static void gamefinish_80052B30_tenliner(UnkStruct_7 *arg0, Gfx **arg1) {
  Point pnt;

  pnt.x = arg0->image_loc.x;
  pnt.y = arg0->image_loc.y - ((FUN_026900_80060914_oneliner_shift6_2(arg0->unkC) * arg0->unk10) >> 0x16);
  func_8005BBFC(arg1);
  weird_lots_of_magic_number_setting_66xrefs(arg1, arg0->image, 0, pnt.x, pnt.y, 0xFF, 0xFF, 0xFF, arg0->unk14 >> 4);
  func_8005BE40(arg1);
}

static void gamefinish_c_line_127(UnkStruct_7 *arg0, s32 gf_type) {
  switch (gf_type) {
  case 0:
    arg0->image = D_800CFF80;  // WIN
    break;
  case 1:
    arg0->image = D_800CFF84;  // LOSE
    break;
  case 2:
    arg0->image = D_800CFF88;  // GAME OVER
    break;
  default:
    debug_print_reason_routine_linenum("invalid type", "gamefinish.c", 127);
  }
  arg0->image_loc.x = arg0->center_of_board.x - (((u16 *) arg0->image)[0] >> 1);
  arg0->image_loc.y = arg0->center_of_board.y - (((u16 *) arg0->image)[1] >> 1);
  arg0->unk10 = 0x3C00;  // is this (s16)(60 * 256) ?
  arg0->unk12 = -arg0->unk10 / 150;
  arg0->unkC = 0;
  arg0->unkE = 0x333;    // is this (s16)(3.2 * 256) ?
  arg0->unk14 = 0;
  arg0->unk16 = 0xCC;    // is this (s16)(0.8 * 256) ?
}

static void gamefinish_80052D24_oneliner(UnkStruct_7 *arg0, Point pnt) {
  arg0->center_of_board = pnt;
}

static void gamefinish_80052D40_doesnothing(UnkStruct_7 *arg0) {
}

void gamefinish_80052D48_twoliner(UnkStruct_20 *arg0) {
  arg0->state = 4;
  arg0->unk1 = TRUE;
}

static void gamefinish_magic_number_180_sprint_twoliner(UnkStruct_20 *arg0) {
  arg0->state = 3;
  arg0->unk8 = 180;
}

static void gamefinish_80052D70_twoliner(UnkStruct_20 *arg0) {
  arg0->state = 2;
  arg0->unk4 = 19;
  arg0->unk8 = 3;
}

// unused
static void gamefinish_80052D8C_nevercalled(UnkStruct_20 *arg0) {
  arg0->state = 1;
  arg0->unk8 = 60;
}

static void gamefinish_80052DA0_oneliner(UnkStruct_20 *arg0, u32 arg1) {
  arg0->unk1 = FALSE;
}

void gamefinish_80052DAC_read_playfield_logic_cell(UnkStruct_20 *arg0) {
  s32 sp3C;
  register Cell **var_s0;
  register s32 var_s1;
  register Cell **var_s2;
  register s32 var_s3;

  sp3C = arg0->unk4;
  if (sp3C >= 0) {
    var_s0 = &g_boardPieces_ptr->cell_ptr_arr[sp3C * 10];
    for (var_s1 = 10; var_s1 > 0; var_s1--) {
      if ((*var_s0)->piece_type != EMPTY_CELL) {
        Minos_80070860_fortyliner(&(*var_s0)->cubeInfo.cube_ptr->mino, &color_gray, 16);
      }
      var_s0++;
    }
  }

  sp3C = arg0->unk4 + 5;
  if ((sp3C >= 0) && (sp3C < 20)) {
    var_s2 = &g_boardPieces_ptr->cell_ptr_arr[sp3C * 10];
    for (var_s3 = 10; var_s3 > 0; var_s3--) {
      if ((*var_s2)->piece_type != EMPTY_CELL) {
        Minos_800709EC(&(*var_s2)->cubeInfo.cube_ptr->mino, 0, 16);
        BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(*var_s2);
      }
      var_s2++;
    }
  }

  if (arg0->unk4 < -4) {
    gamefinish_magic_number_180_sprint_twoliner(arg0);
  } else {
    arg0->unk4--;
  }
}

static void gamefinish_80052F3C_eightliner(UnkStruct_20 *arg0, u32 arg1) {
  arg0->unk8 -= arg1;
  while (arg0->unk8 <= 0) {
    arg0->unk8 += 3;
    gamefinish_80052DAC_read_playfield_logic_cell(arg0);
  }
}

static void gamefinish_80052FC8_eightliner(UnkStruct_20 *arg0, u32 arg1) {
  if (arg0->unk38) {
    return;
  }

  if (arg0->unk8 < arg1) {  // (potential bug), -Wsign-compare issue,
                            // since arg0->unk8 is signed and arg1 is unsigned.
                            // Equivalent to:
                            //   if ((u32)arg0->unk8 < arg1) {
                            // but should probably have been:
                            //   if (arg0->unk8 < (s32)arg1) {
                            // The danger comes if/when arg0->unk8 is negative.
                            // For example, a small negative value will
                            // become a large positive value after casting.
    gamefinish_80052D48_twoliner(arg0);
  } else {
    arg0->unk8 -= arg1;
  }
}

u8 gamefinish_c_line_383(UnkStruct_20 *arg0, u32 arg1) {
  register u8 alpha;

  if (!arg0->unk18) {
    return 2;
  }

  arg0->unk1 = FALSE;
  FUN_026900_80060770_sevenliner(&arg0->unkC, arg1);
  alpha = arg0->unkC.alpha;
  g_currentPiece_ptr->alpha = alpha;
  g_nextPieces_ptr->alpha = alpha;
  g_tetris_ptr->pieceHold.buf[0].piece.alpha = alpha;
  g_tetris_ptr->pieceHold.buf[0].shadow.alpha = alpha;
  g_tetris_ptr->pieceHold.buf[1].piece.alpha = alpha;
  g_tetris_ptr->pieceHold.buf[1].shadow.alpha = alpha;
  FallingCubes_SetAlpha(g_fallingCubes_ptr, alpha);
  switch (arg0->state) {
  case 1:
    gamefinish_80052DA0_oneliner(arg0, arg1);
    break;
  case 2:
    gamefinish_80052F3C_eightliner(arg0, arg1);
    break;
  case 3:
    gamefinish_80052FC8_eightliner(arg0, arg1);
    break;
  case 4:
    arg0->unk1 = TRUE;
    break;
  default:
    debug_print_reason_routine_linenum("invalid state", "gamefinish.c", 383);
    break;
  }
  gamefinish_80052AA0_tenliner(&arg0->unk20, arg1);
  return arg0->unk1;
}

// called from FrameAct_Render
void gamefinish_80053280_twoliner(UnkStruct_20 *arg0) {
  if (!arg0->unk18) {
    return;
  }

  if(arg0->state == 4) {
    return;
  }

  gamefinish_80052B30_tenliner(&arg0->unk20, &g_gdl);
}

void gamefinish_800532DC_nevercalled(UnkStruct_20 *arg0) {
  arg0->unk38 = FALSE;
}

void gamefinish_something2(UnkStruct_20 *arg0, s32 gf_type, u8 arg2) {
  gamefinish_c_line_127(&arg0->unk20, gf_type);
  arg0->unkC.alpha = 255.0f;
  arg0->unkC.unk8 = 0.0f;
  arg0->unkC.unk4 = (0.0f - arg0->unkC.alpha) / 32.0f;
  arg0->gf_type = gf_type;
  arg0->unk18 = TRUE;
  arg0->unk38 = arg2;
  gamefinish_80052D70_twoliner(arg0);
}

// called from FrameAct_Init
// GameFinish_Init
void gamefinish_80053390_fiveliner(UnkStruct_20 *arg0, BoardInfo *boardInfo_ptr) {
  Point pnt;

  get_board_center(&pnt, boardInfo_ptr);
  gamefinish_80052D24_oneliner(&arg0->unk20, pnt);
  arg0->unk18 = FALSE;
  arg0->state = 5;
  arg0->gf_type = GAMEFINISHTYPE_NULL;
}

// called from FrameAct_Deinit
// GameFinish_Deinit
void gamefinish_80053400_fiveliner(UnkStruct_20 *arg0) {
  gamefinish_80052D40_doesnothing(&arg0->unk20);
  arg0->unk18 = FALSE;
  arg0->state = 5;
  arg0->gf_type = GAMEFINISHTYPE_NULL;
}

// called from Game_Init
// GameFinish_Images_Init
void gamefinish_8005344C_fiveliner(u8 numPlayers) {
  playercount = numPlayers;
  func_8007FBB0(&D_800CFF88, IMG_GAME_OVER);
  func_8007FBB0(&D_800CFF80, IMG_WIN);
  func_8007FBB0(&D_800CFF84, IMG_LOSE);
}

// called from Game_Deinit
// GameFinish_Images_Deinit
void gamefinish_800534A4_fiveliner(void) {
  n64HeapUnalloc(D_800CFF88);
  D_800CFF88 = NULL;
  n64HeapUnalloc(D_800CFF80);
  D_800CFF80 = NULL;
  n64HeapUnalloc(D_800CFF84);
  D_800CFF84 = NULL;
}
