#include "common.h"

extern u32 D_801109F4;

////////////////////////////////////////

Tetris *g_tetris_ptr;

static void Tetris_CheckButtons(void);
static void Tetris_SetMarathonHandicap(Tetris *, GameVars *);
static void Tetris_SetSprintHandicap(Tetris *, GameVars *);
static void Tetris_SetUltraHandicap(Tetris *, GameVars *);
static void Tetris_SetGameHandicap(Tetris *, GameVars *);

static void Tetris_CheckButtons(void) {
  register Tetris *tetris_ptr = g_tetris_ptr;
  register UnkStruct_1 *temp_s1;
  register u8 currentplayer;
  register CurrentPiece *currentPiece_ptr;

  if (tetris_ptr->unk4 > 0) {
    tetris_ptr->unk4--;
  } else {
    temp_s1 = &g_PV_ptr->unk28;
    currentplayer = g_currentplayer;
    currentPiece_ptr = &tetris_ptr->board.currentPiece;
    if (currentPiece_ptr->state == 1) {
      if (temp_s1->unk8C & 0x20) {           // L_TRIG / CONT_L
        PieceHold_Swap(&tetris_ptr->pieceHold, currentPiece_ptr);
        Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 1);
      }
      if (temp_s1->unk84 & 0x200) {          // L_JPAD / CONT_LEFT
        currentPiece_ptr->possibleMoves |= 0x1;
      }
      if (temp_s1->unk84 & 0x100) {          // R_JPAD / CONT_RIGHT
        currentPiece_ptr->possibleMoves |= 0x2;
      }
      if (temp_s1->unk84 & 0x8000) {         // A_BUTTON / CONT_A
        currentPiece_ptr->possibleMoves |= 0x8;
      }
      if (temp_s1->unk84 & 0x4000) {         // B_BUTTON / CONT_B
        currentPiece_ptr->possibleMoves |= 0x10;
      }
      if (!(temp_s1->unk88 & 0x200)) {       // L_JPAD / CONT_LEFT
        currentPiece_ptr->possibleMoves &= ~0x1;
      }
      if (!(temp_s1->unk88 & 0x100)) {       // R_JPAD / CONT_RIGHT
        currentPiece_ptr->possibleMoves &= ~0x2;
      }
      if (!(temp_s1->unk88 & 0x8000)) {      // A_BUTTON / CONT_A
        currentPiece_ptr->possibleMoves &= ~0x8;
      }
      if (!(temp_s1->unk88 & 0x4000)) {      // B_BUTTON / CONT_B
        currentPiece_ptr->possibleMoves &= ~0x10;
      }
      if (temp_s1->unk8C & 0x400) {          // D_JPAD / CONT_DOWN
        currentPiece_ptr->fallVelocity = 0x100;
        Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xE);
      }
      if (!(temp_s1->unk88 & 0x400)) {       // D_JPAD / CONT_DOWN
        currentPiece_ptr->fallVelocity = currentPiece_ptr->fallVelocityCopy;
      }
      if (temp_s1->unk8C & 0x800) {          // U_JPAD / CONT_UP
        CurrentPiece_800676ac_fourliner_looper(currentPiece_ptr);
        Audio2_Play_SFX(&D_801235B0, &D_800D3A90, 0xE);
      }
    }
    if ((g_playercount >= 3) && (g_landfill_ptr->type == LANDFILLTYPE_DIRECTED)) {
      if (temp_s1->unk8C & 0x2) {            // L_CBUTTONS / CONT_C
        func_80072508(currentplayer);
      }
      if (temp_s1->unk8C & 0x1) {            // R_CBUTTONS / CONT_F
        func_8007257C(currentplayer);
      }
    }
  }
}

void Tetris_FUN_80054220_fourliner(Tetris *tetris_ptr, u8 arg1) {
  tetris_ptr->unk3 = arg1;
  if (!arg1) {
    tetris_ptr->unk4 = 1;
  }
}

u8 Tetris_Update(Tetris *tetris_ptr) {
  register s32 i;

  tetris_ptr->unk1 = 0;
  if (tetris_ptr->unk0 == 0) {
    tetris_ptr->unk1 = 1;
    return 1;
  }
  if (tetris_ptr->unk2 && (D_800CFEE8 != 0xC)) {
    Tetris_CheckButtons();
  }
  FrameAct_ScheduleEvents(&tetris_ptr->frameAct, D_801109F4);
  debug_print2("Tetris_Update", "FrameAct_ScheduleEvents");
  if (g_frameAct_ptr->unk1 == 1) {
    tetris_ptr->unk0 = 0;
  }
  if (tetris_ptr->unk2 && !tetris_ptr->unk3) {
    PieceHold_Update(&tetris_ptr->pieceHold, D_801109F4);
    debug_print2("Tetris_Update", "PieceHold_Update");
    Board_Update(&tetris_ptr->board, D_801109F4);
    debug_print2("Tetris_Update", "Board_Update");
    GameStats_Update(&tetris_ptr->gameStats, D_801109F4);
    debug_print2("Tetris_Update", "GameStats_Update");
    for (i = D_801109F4; i > 0; i--) {
      FallingCubes_Update();
      debug_print2("Tetris_Update", "FallingCubes_Update");
      MobileCubes_Update();
      debug_print2("Tetris_Update", "MobileCubes_Update");
    }
    Multisquares_UpdateGlows(&tetris_ptr->squares, D_801109F4);
    debug_print2("Tetris_Update", "Multisquares_UpdateGlows");
  }
  if (tetris_ptr->unk3) {
    tetris_ptr->unk1 = 2;
  }
  if (tetris_ptr->frameAct.unk3) {
    tetris_ptr->unk1 = 1;
  }
  return tetris_ptr->unk1;
}

void Tetris_Render(Tetris *tetris_ptr) {
  GameCamera_Render();
  debug_print2("AFTER", "GameCamera_Render");
  MobileCubes_Render();
  debug_print2("AFTER", "MobileCubes_Render");
  CurrentPiece_Render(&tetris_ptr->board.currentPiece);
  debug_print2("AFTER", "CurrentPiece_Render");
  PieceHold_Render(&tetris_ptr->pieceHold);
  debug_print2("AFTER", "PieceHold_Render");
  NextPieces_Render();
  debug_print2("AFTER", "NextPieces_Render");
  GameStats_Render(&tetris_ptr->gameStats);
  debug_print2("AFTER", "GameStats_Render");
  Multisquares_RenderGlows(&tetris_ptr->squares);
  debug_print2("AFTER", "Multisquares_RenderGlows");
  FrameAct_Render(&tetris_ptr->frameAct);
  debug_print2("AFTER", "FrameAct_Render");
}

static void Tetris_SetMarathonHandicap(Tetris *tetris_ptr, GameVars *gameVars_ptr) {
  register s32 lowestScanableLine;
  register s32 y;
  register s32 x;

  lowestScanableLine = 19 - D_800CFF00[gameVars_ptr->handicap];
  if (lowestScanableLine != 19) {
    LineScan_80069f10_threeliner_lowestscanableline(lowestScanableLine);
    for (y = lowestScanableLine + 1; y < 20; y++) {
      for (x = 0; x < 10; x++) {
        BoardP_8006de40_nineliner(x, y, 6);
      }
    }
    FrameAct_80053F40_oneliner(&tetris_ptr->unk6840, 0);
  }
}

static void Tetris_SetSprintHandicap(Tetris *tetris_ptr, GameVars *gameVars_ptr) {
  register s32 lowestScanableLine;
  register s32 y;
  register s32 x;

  lowestScanableLine = 19 - D_800CFF00[gameVars_ptr->handicap];
  if (lowestScanableLine != 19) {
    LineScan_80069f10_threeliner_lowestscanableline(lowestScanableLine);
    for (y = lowestScanableLine + 1; y < 20; y++) {
      for (x = 0; x < 10; x++) {
        BoardP_8006de40_nineliner(x, y, 6);
      }
    }
    FrameAct_80053F40_oneliner(&tetris_ptr->unk6840, 0);
  }
}

static void Tetris_SetUltraHandicap(Tetris *tetris_ptr, GameVars *gameVars_ptr) {
  tetris_ptr->ultraGoal = gameVars_ptr->handicap * 10 + 150;
  FrameAct_80053F40_oneliner(&tetris_ptr->unk6840, 0);
}

static void Tetris_SetGameHandicap(Tetris *tetris_ptr, GameVars *gameVars_ptr) {
  switch (gameVars_ptr->gameType) {
  case GAMETYPE_MARATHON:
    Tetris_SetMarathonHandicap(tetris_ptr, gameVars_ptr);
    break;
  case GAMETYPE_SPRINT:
    Tetris_SetSprintHandicap(tetris_ptr, gameVars_ptr);
    break;
  case GAMETYPE_ULTRA:
    Tetris_SetUltraHandicap(tetris_ptr, gameVars_ptr);
    break;
  }
}

void Tetris_Init(Tetris *tetris_ptr, GameVars *gameVars_ptr) {
  u32 seed = gameVars_ptr->seed;
  register u8 currentplayer;
  register u8 temp_s1;
  Point boardlocation;

  tetris_ptr->unk0 = 1;
  tetris_ptr->unk2 = TRUE;
  tetris_ptr->unk3 = FALSE;
  tetris_ptr->unk4 = 1;
  Bag63_Init(&tetris_ptr->bag63, &seed);
  Minos_Init(&tetris_ptr->unk7D0, gameVars_ptr->unk4);
  PFGFX_Playfield_Init(gameVars_ptr->unk8);
  Board_Init(&tetris_ptr->board, &tetris_ptr->bag63, &tetris_ptr->unk7D0);
  PieceHold_Init(&tetris_ptr->pieceHold, &seed, 10, 20, gameVars_ptr->unk8);
  MultisquareGlow_8006ada4_Init2();
  LineScan_Init();
  Tetris_SetGameHandicap(tetris_ptr, gameVars_ptr);
  GameStats_Init(&tetris_ptr->gameStats);
  PFGFX_Init(&boardlocation, &tetris_ptr->pfGfx);
  BoardInfo_Init(&tetris_ptr->boardInfo, boardlocation, D_8011FC10->unk2 >> 8);
  FrameAct_Init(&tetris_ptr->frameAct, &tetris_ptr->pieceHold, &tetris_ptr->unk6840, &tetris_ptr->boardInfo);
  tetris_ptr->garbage_ptr = Landfill_Garbage();
  g_garbage_ptr = tetris_ptr->garbage_ptr;
  Garbage_Init(tetris_ptr->garbage_ptr, &seed);
  switch (g_landfill_ptr->type) {
  case LANDFILLTYPE_NONE:
    Garbage_80072e2c_set_arg0p_to_arg1(g_garbage_ptr, 0);
    break;
  case LANDFILLTYPE_DIRECTED:
    Garbage_80072e2c_set_arg0p_to_arg1(g_garbage_ptr, 1);
    currentplayer = g_currentplayer;
    Landfill_800723a0_calls_garbage_fun(currentplayer, currentplayer, 0);
    Landfill_8007240c_fiveliner(currentplayer, (currentplayer + 1) % g_playercount);
    if (g_playercount == 2) {
      if (g_currentplayer == 0) {
        Landfill_8007240c_fiveliner(0, 1);
      } else {
        Landfill_8007240c_fiveliner(1, 0);
      }
    }
    break;
  case LANDFILLTYPE_HOTPOTATO:
    Garbage_80072e2c_set_arg0p_to_arg1(g_garbage_ptr, 1);
    temp_s1 = g_landfill_ptr->unk30;
    Landfill_8007240c_fiveliner(g_currentplayer, temp_s1);
    break;
  default:
    debug_print_reason_routine_linenum("bad type", "tetris.c", 504);
    break;
  }
  tetris_ptr->gameStats.elapsedTime = 0;
  // sets initial state (to 1) for FrameAct_ScheduleEvents
  FrameAct_set_state(1);
}

void Tetris_Deinit(Tetris *tetris_ptr) {
  FrameAct_Deinit_doesnothing(&tetris_ptr->unk6840);
  FrameAct_Deinit(&tetris_ptr->frameAct);
  PieceHold_Deinit(&tetris_ptr->pieceHold);
  Board_Deinit(&tetris_ptr->board);
  Minos_Deinit_doesnothing(&tetris_ptr->unk7D0);
  Garbage_Deinit(tetris_ptr->garbage_ptr);
  MultisquareGlow_Deinit_doesnothing();
  Bag63_Deinit(&tetris_ptr->bag63);
  GameStats_Deinit(&tetris_ptr->gameStats);
}
