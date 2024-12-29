#include "common.h"

extern u32 D_801109F4;

////////////////////////////////////////

UnkStruct_6 *D_8011F220;

static void   FrameAct_80053684_threeliner(UnkStruct_6 *);
static void   FrameAct_calls_increment_game_time_seconds2(UnkStruct_6 *);
static void   FrameAct_80053760_mediumliner(UnkStruct_6 *);
static void   FrameAct_80053868_twentyliner(UnkStruct_6 *);
static void   FrameAct_80053934_tenliner(UnkStruct_6 *);
static void   FrameAct_line_253(UnkStruct_6 *);
static void   FrameAct_NextPieces_Update(UnkStruct_6 *);
static void   FrameAct_calls_gamefinish_something(UnkStruct_6 *);
static u8     FrameAct_80053EA0_threeliner(s32 *);

void FrameAct_set_DAT_8011f220(u8 arg0) {
  D_8011F220->unk0 = arg0;
}

static void FrameAct_80053684_threeliner(UnkStruct_6 *arg0) {
  NextPieces_800688e0_sets_global_var_element();
  arg0->unk0 = 7;
  arg0->unk2 = TRUE;
}

static void FrameAct_calls_increment_game_time_seconds2(UnkStruct_6 *arg0) {
  register s32 c = CurrentPiece_800677b8_twohundredliner_doit_last(g_currentPiece_ptr, D_801109F4);

  switch (c) {
  case 1:
    arg0->unk0 = 3;
    arg0->unk2 = FALSE;
    GameStats_saveCurrentPieceFallVelocity(g_gameStats_ptr);
    D_8011FBA0->unk0 = 1;
    break;
  case 2:
    arg0->unk3 = TRUE;
    break;
  }
}

static void FrameAct_80053760_mediumliner(UnkStruct_6 *arg0) {
  register s32 c = MultisquareGlow_8006ad0c_checks_1_2_3_4();

  switch (c) {
  case 0:
    arg0->unk2 = TRUE;
    break;
  case 1:
    arg0->unk0 = 4;
    arg0->unk2 = FALSE;
    D_8011FBC0->currentPiece_ptr = g_currentPiece_ptr;
    D_8011FBC0->unk0 = 2;
    break;
  case 2:
    arg0->unk0 = 5;
    arg0->unk2 = FALSE;
    LineScan_80069ec0_sevenliner_loops_4_times();
    g_lineScan_ptr->unk0 = 1;
    break;
  case 3:
    if (arg0->unkC) {
      arg0->unk0 = 8;
    } else {
      arg0->unk0 = 6;
      func_80072FC4();  // garbage func
    }
    break;
  }
}

static void FrameAct_80053868_twentyliner(UnkStruct_6 *arg0) {
  register s32 c = KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35(D_8011FBC0, D_801109F4);

  switch (c) {
  case 1:
    arg0->unk0 = 5;
    arg0->unk2 = FALSE;
    LineScan_80069ec0_sevenliner_loops_4_times();
    g_lineScan_ptr->unk0 = 1;
    D_800CFF50 = 1;
    break;
  case 2:
    arg0->unk0 = 5;
    arg0->unk2 = FALSE;
    LineScan_80069e84_sevenliner_loops_20_times();
    g_lineScan_ptr->unk0 = 1;
    D_800CFF50 = 1;
    break;
  }
}

static void FrameAct_80053934_tenliner(UnkStruct_6 *arg0) {
  LineScan_80069fb8_elevenliner_case_and_loop_interesting();
  switch (g_lineScan_ptr->unk1) {
  case 1:
    if (arg0->unkC) {
      arg0->unk0 = 8;
    } else {
      arg0->unk0 = 6;
      arg0->unk2 = FALSE;
      func_80072FC4();  // garbage func
    }
    break;
  case 2:
    arg0->unk0 = 3;
    D_8011FBA0->unk0 = 3;
    break;
  }
}

static void FrameAct_line_253(UnkStruct_6 *arg0) {
  register s32 c = func_80072F1C(D_801109F4);  // garbage func

  switch (c) {
  case 0:
    break;
  case 1:
    arg0->unk0 = 7;
    arg0->unk2 = FALSE;
    NextPieces_800688e0_sets_global_var_element();
    break;
  case 2:
    aiplayer_8004376c_fiveliner();
    arg0->unk0 = 7;
    NextPieces_800688e0_sets_global_var_element();
    break;
  case 3:
    arg0->unk3 = TRUE;
    break;
  default:
    debug_print_reason_routine_linenum("invalid retval", "frameact.c", 253);
  }
}

static void FrameAct_NextPieces_Update(UnkStruct_6 *arg0) {
  register s32 i;
  register s32 tmp;

  for (i = D_801109F4; i > 0; i--) {
    NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun();
  }

  tmp = g_nextPieces_ptr->unk1;
  if (tmp != 0) {
    switch (tmp) {
    case 1:
      arg0->unk0 = 2;
      arg0->unk1 = 0;
      arg0->unk2 = FALSE;
      tmp = NextPieces_80068b18_threeliner();
      CurrentPiece_80067dd8_big_fiftyliner(tmp);
      PieceHold_Enable(arg0->pieceHold_ptr);
      aiplayer_8004370c_threeliner();
      break;
    default:
      debug_print_reason_routine("Invalid return value", "NextPieces:Update, frameact.c");
    }
  }
}

void FrameAct_calls_gamefinish_something2(UnkStruct_6 *arg0, s32 gf_type) {
  if (arg0->unkC) {
    return;
  }

  arg0->unkC = TRUE;
  arg0->unk0 = 8;
  if (D_800CFEE8 == 0xC) {
    gamefinish_something2(&arg0->unk10, gf_type, FALSE);
  } else {
    gamefinish_something2(&arg0->unk10, gf_type, TRUE);
  }
}

static void FrameAct_calls_gamefinish_something(UnkStruct_6 *arg0) {
  register s32 c = gamefinish_c_line_383(&arg0->unk10, D_801109F4);

  switch (c) {
  case 1:
    arg0->unk0 = 0;
    arg0->unk1 = 1;
    break;
  }
}

void FrameAct_ScheduleEvents(UnkStruct_6 *arg0, u32 arg1) {
  do {
    if ((D_800CFEE8 != 0xC) || (arg0->unk1 != 1)) {
      arg0->unk1 = 0;
    }
    arg0->unk2 = TRUE;
    switch (arg0->unk0) {
    case 1:
      FrameAct_80053684_threeliner(arg0);
      break;
    case 2:
      FrameAct_calls_increment_game_time_seconds2(arg0);
      break;
    case 3:
      FrameAct_80053760_mediumliner(arg0);
      break;
    case 4:
      FrameAct_80053868_twentyliner(arg0);
      break;
    case 5:
      FrameAct_80053934_tenliner(arg0);
      break;
    case 6:
      FrameAct_line_253(arg0);
      break;
    case 7:
      FrameAct_NextPieces_Update(arg0);
      break;
    case 8:
      FrameAct_calls_gamefinish_something(arg0);
      break;
    }
  } while (!arg0->unk2);
}

void FrameAct_Render(UnkStruct_6 *arg0) {
  if (arg0->unkC) {
    gamefinish_80053280_twoliner(&arg0->unk10);
  }
}

void FrameAct_Init(UnkStruct_6 *arg0, PieceHold *pieceHold_ptr, s32 *arg2, BoardInfo *boardInfo_ptr) {
  arg0->unk0 = 0;
  arg0->unk3 = FALSE;
  arg0->unkC = FALSE;
  arg0->pieceHold_ptr = pieceHold_ptr;
  arg0->unk8 = arg2;
  gamefinish_80053390_fiveliner(&arg0->unk10, boardInfo_ptr);
}

void FrameAct_Deinit(UnkStruct_6 *arg0) {
  arg0->unk0 = 0;
  gamefinish_80053400_fiveliner(&arg0->unk10);
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
