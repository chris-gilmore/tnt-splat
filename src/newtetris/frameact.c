#include "common.h"

extern u32 D_801109F4;

////////////////////////////////////////

FrameAct *g_frameAct_ptr;

static void   FrameAct_80053684_threeliner(FrameAct *);
static void   FrameAct_calls_increment_game_time_seconds2(FrameAct *);
static void   FrameAct_80053760_mediumliner(FrameAct *);
static void   FrameAct_80053868_twentyliner(FrameAct *);
static void   FrameAct_80053934_tenliner(FrameAct *);
static void   FrameAct_line_253(FrameAct *);
static void   FrameAct_NextPieces_Update(FrameAct *);
static void   FrameAct_calls_gamefinish_something(FrameAct *);
static u8     FrameAct_80053EA0_threeliner(s32 *);

void FrameAct_set_state(u8 state) {
  g_frameAct_ptr->state = state;
}

static void FrameAct_80053684_threeliner(FrameAct *frameAct_ptr) {
  NextPieces_800688e0_sets_global_var_element();
  frameAct_ptr->state = 7;
  frameAct_ptr->unk2 = TRUE;
}

static void FrameAct_calls_increment_game_time_seconds2(FrameAct *frameAct_ptr) {
  register s32 c = CurrentPiece_800677b8_twohundredliner_doit_last(g_currentPiece_ptr, D_801109F4);

  switch (c) {
  case 1:
    frameAct_ptr->state = 3;
    frameAct_ptr->unk2 = FALSE;
    GameStats_saveCurrentPieceFallVelocity(g_gameStats_ptr);
    g_squares_ptr->unk0 = 1;
    break;
  case 2:
    frameAct_ptr->unk3 = TRUE;
    break;
  }
}

static void FrameAct_80053760_mediumliner(FrameAct *frameAct_ptr) {
  register s32 c = MultisquareGlow_8006ad0c_checks_1_2_3_4();

  switch (c) {
  case 0:
    frameAct_ptr->unk2 = TRUE;
    break;
  case 1:
    frameAct_ptr->state = 4;
    frameAct_ptr->unk2 = FALSE;
    D_8011FBC0->currentPiece_ptr = g_currentPiece_ptr;
    D_8011FBC0->unk0 = 2;
    break;
  case 2:
    frameAct_ptr->state = 5;
    frameAct_ptr->unk2 = FALSE;
    LineScan_80069ec0_sevenliner_loops_4_times();
    g_lineScan_ptr->unk0 = 1;
    break;
  case 3:
    if (frameAct_ptr->unkC) {
      frameAct_ptr->state = 8;
    } else {
      frameAct_ptr->state = 6;
      func_80072FC4();  // garbage func
    }
    break;
  }
}

static void FrameAct_80053868_twentyliner(FrameAct *frameAct_ptr) {
  register s32 c = KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35(D_8011FBC0, D_801109F4);

  switch (c) {
  case 1:
    frameAct_ptr->state = 5;
    frameAct_ptr->unk2 = FALSE;
    LineScan_80069ec0_sevenliner_loops_4_times();
    g_lineScan_ptr->unk0 = 1;
    D_800CFF50 = 1;
    break;
  case 2:
    frameAct_ptr->state = 5;
    frameAct_ptr->unk2 = FALSE;
    LineScan_80069e84_sevenliner_loops_20_times();
    g_lineScan_ptr->unk0 = 1;
    D_800CFF50 = 1;
    break;
  }
}

static void FrameAct_80053934_tenliner(FrameAct *frameAct_ptr) {
  LineScan_80069fb8_elevenliner_case_and_loop_interesting();
  switch (g_lineScan_ptr->unk1) {
  case 1:
    if (frameAct_ptr->unkC) {
      frameAct_ptr->state = 8;
    } else {
      frameAct_ptr->state = 6;
      frameAct_ptr->unk2 = FALSE;
      func_80072FC4();  // garbage func
    }
    break;
  case 2:
    frameAct_ptr->state = 3;
    g_squares_ptr->unk0 = 3;
    break;
  }
}

static void FrameAct_line_253(FrameAct *frameAct_ptr) {
  register s32 c = func_80072F1C(D_801109F4);  // garbage func

  switch (c) {
  case 0:
    break;
  case 1:
    frameAct_ptr->state = 7;
    frameAct_ptr->unk2 = FALSE;
    NextPieces_800688e0_sets_global_var_element();
    break;
  case 2:
    aiplayer_8004376c_fiveliner();
    frameAct_ptr->state = 7;
    NextPieces_800688e0_sets_global_var_element();
    break;
  case 3:
    frameAct_ptr->unk3 = TRUE;
    break;
  default:
    debug_print_reason_routine_linenum("invalid retval", "frameact.c", 253);
  }
}

static void FrameAct_NextPieces_Update(FrameAct *frameAct_ptr) {
  register s32 i;
  register s32 tmp;

  for (i = D_801109F4; i > 0; i--) {
    NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun();
  }

  tmp = g_nextPieces_ptr->unk1;
  if (tmp != 0) {
    switch (tmp) {
    case 1:
      frameAct_ptr->state = 2;
      frameAct_ptr->unk1 = 0;
      frameAct_ptr->unk2 = FALSE;
      tmp = NextPieces_80068b18_threeliner();
      CurrentPiece_80067dd8_big_fiftyliner(tmp);
      PieceHold_Enable(frameAct_ptr->pieceHold_ptr);
      aiplayer_8004370c_threeliner();
      break;
    default:
      debug_print_reason_routine("Invalid return value", "NextPieces:Update, frameact.c");
    }
  }
}

void FrameAct_calls_gamefinish_something2(FrameAct *frameAct_ptr, s32 gf_type) {
  if (frameAct_ptr->unkC) {
    return;
  }

  frameAct_ptr->unkC = TRUE;
  frameAct_ptr->state = 8;
  if (D_800CFEE8 == 0xC) {
    gamefinish_something2(&frameAct_ptr->unk10, gf_type, FALSE);
  } else {
    gamefinish_something2(&frameAct_ptr->unk10, gf_type, TRUE);
  }
}

static void FrameAct_calls_gamefinish_something(FrameAct *frameAct_ptr) {
  register s32 c = gamefinish_c_line_383(&frameAct_ptr->unk10, D_801109F4);

  switch (c) {
  case 1:
    frameAct_ptr->state = 0;
    frameAct_ptr->unk1 = 1;
    break;
  }
}

void FrameAct_ScheduleEvents(FrameAct *frameAct_ptr, u32 arg1) {
  do {
    if ((D_800CFEE8 != 0xC) || (frameAct_ptr->unk1 != 1)) {
      frameAct_ptr->unk1 = 0;
    }
    frameAct_ptr->unk2 = TRUE;
    //rmonPrintf("case %d\n", frameAct_ptr->state);
    switch (frameAct_ptr->state) {
    case 1:
      // init related
      FrameAct_80053684_threeliner(frameAct_ptr);
      // goes to 7
      break;
    case 2:
      // when piece is falling
      FrameAct_calls_increment_game_time_seconds2(frameAct_ptr);
      break;
    case 3:
      // when piece is dropped
      FrameAct_80053760_mediumliner(frameAct_ptr);
      break;
    case 4:
      // keyspin related
      FrameAct_80053868_twentyliner(frameAct_ptr);
      break;
    case 5:
      // linescan related
      FrameAct_80053934_tenliner(frameAct_ptr);
      break;
    case 6:
      // garbage related
      FrameAct_line_253(frameAct_ptr);
      // goes to 7
      break;
    case 7:
      FrameAct_NextPieces_Update(frameAct_ptr);
      break;
    case 8:
      FrameAct_calls_gamefinish_something(frameAct_ptr);
      break;
    }
  } while (!frameAct_ptr->unk2);
}

void FrameAct_Render(FrameAct *frameAct_ptr) {
  if (frameAct_ptr->unkC) {
    gamefinish_80053280_twoliner(&frameAct_ptr->unk10);
  }
}

void FrameAct_Init(FrameAct *frameAct_ptr, PieceHold *pieceHold_ptr, s32 *arg2, BoardInfo *boardInfo_ptr) {
  frameAct_ptr->state = 0;
  frameAct_ptr->unk3 = FALSE;
  frameAct_ptr->unkC = FALSE;
  frameAct_ptr->pieceHold_ptr = pieceHold_ptr;
  frameAct_ptr->unk8 = arg2;
  gamefinish_80053390_fiveliner(&frameAct_ptr->unk10, boardInfo_ptr);
}

void FrameAct_Deinit(FrameAct *frameAct_ptr) {
  frameAct_ptr->state = 0;
  gamefinish_80053400_fiveliner(&frameAct_ptr->unk10);
}

static u8 FrameAct_80053EA0_threeliner(s32 *arg0) {
  if (*arg0 == 0) {
    return TRUE;
  }
  return FALSE;
}

u8 FrameAct_80053EC4_tenliner(s32 *arg0, s32 arg1) {
  if (*arg0 < arg1) {
    *arg0 = 0;
  } else {
    *arg0 -= arg1;
  }
  if (FrameAct_80053EA0_threeliner(arg0)) {
    return TRUE;
  }
  return FALSE;
}

void FrameAct_80053F40_oneliner(s32 *arg0, s32 arg1) {
  *arg0 = arg1;
}

void FrameAct_Deinit_doesnothing(s32 *arg0) {
}
