#include "common.h"

// handicap values
u8 D_800CFF00[] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  0,
  0,  5, 10, 15, 20, 25, 30, 35, 40, 45,  0,  0,
  0, 10, 20, 30, 40, 50, 60, 70, 80, 90,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0, 28,  0,  0,  0, 32,  0,  0,  0, 36,  0,
  0,  0, 40,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
};
u8 D_800CFF50 = 1;
Game g_game;

static void   setPlayerTopOutOrder(Game *, u8);
static u8     hasPlayerToppedOut(Game *, u8);
static void   Game_SetAlpha(Game *, u8);
static u8     getPlayerTopOutOrder(Game *, u8);
static u32    getMaxPlayerLines(Game *);
static u32    getMinPlayerTime(Game *);
static s32    Game_800510a4_eightliner(Game *);
static s32    Game_80051104_sevenliner_num_players(Game *);
static void   Game_game_over_related(Game *, u32, s32);
static u8     isGoalCompleted(Game *);
static void   Game_80051320_fiveliner(Game *, u8);
static void   Game_800513bc_tenliner_num_players(Game *);
static void   Game_QueryGameOver(Game *);
static void   Game_800515f8_twoliner(Game *);
static void   Game_80051790_twelveliner(Game *, u8);
static void   Game_80051880_sixliner(Game *);
static void   Game_ControllerRepeat_Update(Game *);
static void   Game_800519b4_thirtyliner(Game *);
static void   Game_Update(Game *);
static void   Game_80052090_calls_3_functions(void);
static void   Game_800520d0_calls_cubetiles_init(void);

static void setPlayerTopOutOrder(Game *game_ptr, u8 playerNum) {
  if (game_ptr->topOutCount < 0 || game_ptr->topOutCount >= g_playercount) {
    debug_print_reason_routine_linenum("topOutOrderIndex invalid", "game.c", 63);
  }
  game_ptr->topOutOrder[game_ptr->topOutCount++] = playerNum;
}

static u8 hasPlayerToppedOut(Game *game_ptr, u8 playerNum) {
  register s32 i;

  for (i = 0; i < game_ptr->topOutCount; i++) {
    if (game_ptr->topOutOrder[i] == playerNum) {
      return TRUE;
    }
  }
  return FALSE;
}

s32 Game_calls_SETGP_magic_7(Game *game_ptr) {
  register s32 var_s0;
  register u32 var_s1;

  var_s0 = 0;
  for (var_s1 = 0; (var_s1 < g_playercount) && (var_s0 == 0); var_s1++) {
    Game_SetGlobalPointers(var_s1);
    PlayerVars_SetGlobalPointers(var_s1);
    if (BoardP_8006ddd0_check_for_nonempty_cell_upwards(7) != 0) {
      var_s0 = 1;
    }
  }
  return var_s0;
}

// pause/unpause (make invisible/visible)
static void Game_SetAlpha(Game *game_ptr, u8 alpha) {
  register s32 i;

  for (i = 0; i < g_playercount; i++) {
    game_ptr->tetris_ptr_arr[i]->board.currentPiece.alpha = alpha;
    game_ptr->tetris_ptr_arr[i]->board.mobileCubes.alpha = alpha;
    game_ptr->tetris_ptr_arr[i]->board.nextPieces.alpha = alpha;
    FallingCubes_SetAlpha(&game_ptr->tetris_ptr_arr[i]->board.fallingCubes, alpha);
    game_ptr->tetris_ptr_arr[i]->pieceHold.buf[0].piece.alpha = alpha;
    game_ptr->tetris_ptr_arr[i]->pieceHold.buf[0].shadow.alpha = alpha;
    game_ptr->tetris_ptr_arr[i]->pieceHold.buf[1].piece.alpha = alpha;
    game_ptr->tetris_ptr_arr[i]->pieceHold.buf[1].shadow.alpha = alpha;
    MultisquareGlow_8006aebc_loops_44_times_4(&game_ptr->tetris_ptr_arr[i]->squares, alpha);
  }
}

static u8 getPlayerTopOutOrder(Game *game_ptr, u8 playerNum) {
  register s32 i;

  for (i = 0; i < game_ptr->topOutCount; i++) {
    if (game_ptr->topOutOrder[i] == playerNum) {
      return i;
    }
  }
  return 0xFF;
}

static u32 getMaxPlayerLines(Game *game_ptr) {
  register u32 max_lines;
  register s32 i;
  register u32 lines;

  max_lines = 0;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (getPlayerTopOutOrder(game_ptr, i) == 0xFF) {
      lines = getLineCount(&g_game.tetris_ptr_arr[i]->gameStats.linesInfo);
      if (lines > max_lines) {
        max_lines = lines;
      }
    }
  }
  return max_lines;
}

static u32 getMinPlayerTime(Game *game_ptr) {
  register u32 minTime;
  register s32 i;
  register u32 elapsedTime;

  minTime = 0xFFFFFFFF;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (getPlayerTopOutOrder(game_ptr, i) == 0xFF) {
      elapsedTime = g_game.tetris_ptr_arr[i]->gameStats.elapsedTime;
      if (minTime > elapsedTime) {
        minTime = elapsedTime;
      }
    }
  }
  return minTime;
}

u8 Game_isGameWinner(Game *game_ptr, u8 playerNum) {
  register u8 temp_s0;
  register u32 maxLinesSprint;
  register u32 minTimeUltra;
  register u32 maxLinesUltra;
  register u32 playerLines;

  temp_s0 = getPlayerTopOutOrder(game_ptr, playerNum);
  if ((temp_s0 + 1) == game_ptr->numPlayers) {
    return TRUE;
  }
  if (temp_s0 != 0xFF) {
    return FALSE;
  }
  switch (game_ptr->gameType) {
  case GAMETYPE_MARATHON:
    return TRUE;
  case GAMETYPE_SPRINT:
    maxLinesSprint = getMaxPlayerLines(game_ptr);
    return getLineCount(&g_game.tetris_ptr_arr[playerNum]->gameStats.linesInfo) == maxLinesSprint;
  case GAMETYPE_ULTRA:
    minTimeUltra = getMinPlayerTime(game_ptr);
    maxLinesUltra = getMaxPlayerLines(game_ptr);
    playerLines = getLineCount(&g_game.tetris_ptr_arr[playerNum]->gameStats.linesInfo);
    return (playerLines >= g_game.tetris_ptr_arr[playerNum]->ultraGoal || playerLines >= maxLinesUltra) && g_game.tetris_ptr_arr[playerNum]->gameStats.elapsedTime == minTimeUltra;
  default:
    debug_print_reason_routine_linenum("invalid GameType", "game.c", 292);
    return FALSE;
  }
}

s32 Game_countWinners(Game *game_ptr) {
  register s32 num_winners;
  register s32 i;

  num_winners = 0;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (Game_isGameWinner(game_ptr, i)) {
      num_winners++;
    }
  }
  return num_winners;
}

static s32 Game_800510a4_eightliner(Game *game_ptr) {
  register s32 i;
  register s32 var_a2;

  var_a2 = 0;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (game_ptr->tetris_ptr_arr[i]->unk0) {
      var_a2 += 1;
    }
  }
  return var_a2;
}

static s32 Game_80051104_sevenliner_num_players(Game *game_ptr) {
  register u32 i;
  register s32 var_a2;
  register u8 playercount = g_playercount;

  var_a2 = 0;
  for (i = 0; i < playercount; i++) {
    if (game_ptr->tetris_ptr_arr[i]->unk2) {
      var_a2++;
    }
  }
  return var_a2;
}

static void Game_game_over_related(Game *game_ptr, u32 playerNum, s32 gf_type) {
  FrameAct_calls_gamefinish_something2(&game_ptr->tetris_ptr_arr[playerNum]->frameAct, gf_type);
  game_ptr->tetris_ptr_arr[playerNum]->unk2 = FALSE;
  func_800726A4(&game_ptr->landfill, playerNum);
  game_ptr->unkE50A = playerNum;
}

static u8 isGoalCompleted(Game *game_ptr) {
  register u32 i;
  register u8 playercount;

  switch (game_ptr->gameType) {
  case GAMETYPE_MARATHON:
    return FALSE;
  case GAMETYPE_SPRINT:
    if (game_ptr->unkE4E8 >= game_ptr->unkE4F0) {  // if elapsedTime >= 3 minutes
      game_ptr->unkE4E8 = game_ptr->unkE4F0;       //   elapsedTime = 3 minutes
      return TRUE;
    }
    return FALSE;
  case GAMETYPE_ULTRA:
    playercount = g_playercount;
    for (i = 0; i < playercount; i++) {
      if (getLineCount(&g_game.tetris_ptr_arr[i]->gameStats.linesInfo) >= g_game.tetris_ptr_arr[i]->ultraGoal) {
        return TRUE;
      }
    }
    return FALSE;
  default:
    debug_print_reason_routine_linenum("invalid type", "game.c", 405);
  }
}

static void Game_80051320_fiveliner(Game *game_ptr, u8 playerNum) {
  register Tetris *tetris_ptr = game_ptr->tetris_ptr_arr[playerNum];

  if (tetris_ptr->frameAct.unk3) {
    if (g_playercount == 1) {
      Game_game_over_related(game_ptr, playerNum, GAMEFINISHTYPE_GAMEOVER);
    } else {
      Game_game_over_related(game_ptr, playerNum, GAMEFINISHTYPE_LOSE);
    }
    setPlayerTopOutOrder(game_ptr, playerNum);
  }
}

static void Game_800513bc_tenliner_num_players(Game *game_ptr) {
  register u8 playercount = g_playercount;
  register s32 i;

  if (playercount != 1 && Game_80051104_sevenliner_num_players(game_ptr) == 1) {
    for (i = 0; i < playercount; i++) {
      if (game_ptr->tetris_ptr_arr[i]->unk2) {
        if (FALSE) {}
        Game_game_over_related(game_ptr, i, GAMEFINISHTYPE_WIN);
      }
    }
  }
}

static void Game_QueryGameOver(Game *game_ptr) {
  register u32 i;
  register u32 numPlayers = game_ptr->numPlayers;
  register Tetris *tetris_ptr;
  register s32 j;

  for (i = 0; i < numPlayers; i++) {
    tetris_ptr = game_ptr->tetris_ptr_arr[i];
    if (tetris_ptr->unk2) {
      if (FALSE) {}
      Game_80051320_fiveliner(game_ptr, i);
    }
  }
  if (numPlayers > 1) {
    Game_800513bc_tenliner_num_players(game_ptr);
  }
  if (isGoalCompleted(game_ptr)) {
    for (j = 0; j < game_ptr->numPlayers; j++) {
      if (game_ptr->tetris_ptr_arr[j]->unk2) {
        if (FALSE) {}
        if (Game_isGameWinner(game_ptr, j)) {
          Game_game_over_related(game_ptr, j, GAMEFINISHTYPE_WIN);
        } else {
          Game_game_over_related(game_ptr, j, GAMEFINISHTYPE_LOSE);
        }
      }
    }
  }
  if (Game_800510a4_eightliner(game_ptr) == 0) {
    rmonPrintf("Game_QueryGameOver(): Setting state to GAMEOVER\n");
    game_ptr->unk0 = 1;
    game_ptr->unk1 = 2;
  }
}

static void Game_800515f8_twoliner(Game *game_ptr) {
  if (game_ptr->unk3 != 0) {
    game_ptr->unk1 = 1;
  }
}

void Game_80051618_twentyliner(Game *game_ptr) {
  register s32 i;
  register PlayerVars *temp_s1;
  register UnkStruct_1 *temp_s2;

  for (i = 0; i < game_ptr->numPlayers; i++) {
    Tetris_FUN_80054220_fourliner(game_ptr->tetris_ptr_arr[i], FALSE);
  }
  game_ptr->unk3 = 0;
  game_ptr->unk0 = 0;
  game_ptr->unk6 = 1;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    temp_s1 = &g_PV_arr[i];
    temp_s2 = &temp_s1->unk28;
    temp_s2->unk88 = 0;  // buttons
    temp_s2->unk8C = 0;  // buttons
    FUN_026900_nineliner_loops_32t(temp_s2);
    func_800A3460(&temp_s1->contQ);
  }
  game_ptr->unkE4FC.unk8 = 255.0f;
  game_ptr->unkE4FC.unk4 = (255.0f - game_ptr->unkE4FC.alpha) / 16.0f;
  game_ptr->unkE508 = TRUE;
}

static void Game_80051790_twelveliner(Game *game_ptr, u8 arg1) {
  register s32 i;

  for (i = 0; i < game_ptr->numPlayers; i++) {
    Tetris_FUN_80054220_fourliner(game_ptr->tetris_ptr_arr[i], TRUE);
  }
  game_ptr->unk3 = 1;
  game_ptr->unk4 = arg1;
  game_ptr->unk0 = 2;
  game_ptr->unkE4FC.unk8 = 0.0f;
  game_ptr->unkE4FC.unk4 = (0.0f - game_ptr->unkE4FC.alpha) / 16.0f;
  game_ptr->unkE508 = TRUE;
}

static void Game_80051880_sixliner(Game *game_ptr) {
  register s32 i;

  for (i = 0; i < game_ptr->numPlayers; i++) {
    gamefinish_80052D48_twoliner(&game_ptr->tetris_ptr_arr[i]->frameAct.unk10);
  }
}

static void Game_ControllerRepeat_Update(Game *game_ptr) {
  register s32 i;
  register PlayerVars *temp_s1;
  register UnkStruct_1 *temp_s2;

  for (i = 0; i < game_ptr->numPlayers; i++) {
    temp_s1 = &g_PV_arr[i];
    temp_s2 = &temp_s1->unk28;
    temp_s2->unk88 = temp_s1->unk1C->unk0;
    temp_s2->unk8C = temp_s1->unk24;
    debug_print2("ControllerRepeat_Update", "GU");
    FUN_026900_GU_or_ControllerRepeat_Update(temp_s2, temp_s2->unk88, D_801109F4);
  }
}

static void Game_800519b4_thirtyliner(Game *game_ptr) {
  register s32 var_s0;
  register s32 var_s1;
  register s32 i;
  register UnkStruct_1 *temp_s3;
  register s32 var_s4;
  register s32 j;
  register UnkStruct_1 *temp_s6;

  var_s0 = 0;
  var_s1 = 0;
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (game_ptr->tetris_ptr_arr[i]->unk2) {
      temp_s3 = &g_PV_arr[i].unk28;
      if ((temp_s3->unk8C & CONT_START) && D_800CFF50) {  // START_BUTTON
        var_s0 = 1;
        var_s1 = i;
      }
    }
  }
  if (var_s0) {
    Game_80051790_twelveliner(game_ptr, var_s1);
    return;
  }
  if (Game_80051104_sevenliner_num_players(game_ptr) == 0) {
    if (game_ptr->unk7 > D_801109F4) {
      game_ptr->unk7 -= D_801109F4;
      return;
    }
    var_s4 = 0;
    for (j = 0; j < game_ptr->numPlayers; j++) {
      temp_s6 = &g_PV_arr[j].unk28;
      if (temp_s6->unk8C & (CONT_A | CONT_START)) {  // A_BUTTON or START_BUTTON
        var_s4 = 1;
      }
    }
    if (var_s4) {
      Game_80051880_sixliner(game_ptr);
    }
    game_ptr->unk7 = 0;
  }
}

static void Game_Update(Game *game_ptr) {
  register s32 i;

  for (i = 0; i < game_ptr->numPlayers; i++) {
    debug_print2("Game_SetGlobalPointers", "GU");
    Game_SetGlobalPointers(i);
    debug_print2("PlayerVars_SetGlobalPointers", "GU");
    PlayerVars_SetGlobalPointers(i);
    if ((D_800CFEE8 == 0xC) && (g_PV_arr[0].unk24 != 0)) {
      D_800D0550 = 4000;
    }
    debug_print2("Tetris:Update() enter", "Game:Update()");
    Tetris_Update(game_ptr->tetris_ptr_arr[i]);
    debug_print2("Tetris:Update() finished", "Game:Update()");
  }
}

void Game_line_782_game_c(Game *game_ptr) {
  if (!game_ptr->is_active) {
    debug_print_reason_routine_linenum("oops", "game.c", 782);
  }
  if (game_ptr->unk0 != 1) {
    if (FALSE) {}
    game_ptr->unk1 = 0;
    if (game_ptr->unkE508) {
      FUN_026900_80060770_sevenliner(&game_ptr->unkE4FC, D_801109F4);
      Game_SetAlpha(game_ptr, game_ptr->unkE4FC.alpha);
      if (game_ptr->unkE4FC.unk4 == 0.0f) {
        game_ptr->unkE508 = FALSE;
      }
    }
    if (game_ptr->unk3 == 0) {
      if (Game_80051104_sevenliner_num_players(game_ptr) != 0) {
        game_ptr->unkE4E8 = game_ptr->unkE4E8 + D_801109F4;
      }
      func_800763EC(D_801109F4);
      Game_ControllerRepeat_Update(game_ptr);
      if (game_ptr->unk0 == 0) {
        aiplayer_8004311c_largefunction();
      }
      if (D_800CFEE8 != 0xC) {
        Game_800519b4_thirtyliner(game_ptr);
      }
      Game_800515f8_twoliner(game_ptr);
      if (game_ptr->unk1 != 1) {
        if (FALSE) {}
        if (game_ptr->unk0 == 0) {
          Game_Update(game_ptr);
        }
        Game_QueryGameOver(game_ptr);
      }
    }
  }
}

void Game_render_stuff_line_850(Game *game_ptr) {
  register u32 i;

  if (!game_ptr->is_active) {
    debug_print_reason_routine_linenum("oops", "game.c", 850);
  }
  if (game_ptr->unk0 != 1) {
    FUN_027BF0_800636C0_display_game_stats_screen_q();
    g_landfill_ptr = &game_ptr->landfill;
    func_80072A84();
    debug_print2("BEFORE", "TETBREND");
    for (i = 0; i < game_ptr->numPlayers; i++) {
      debug_print2("BEFORE", "GSETGP");
      Game_SetGlobalPointers(i);
      debug_print2("BEFORE", "PSETGP");
      PlayerVars_SetGlobalPointers(i);
      debug_print2("BEFORE", "TRENDER");
      Tetris_Render(game_ptr->tetris_ptr_arr[i]);
    }
    debug_print2("BEFORE", "TAREND");
    debug_print2("BEFORE", "TAFTEREND");
  }
}

// deinit cubetiles?
static void Game_80052090_calls_3_functions(void) {
  register Game *game_ptr = &g_game;

  func_80075F5C(&game_ptr->unkE080);
  CubeTiles_Deinit(&game_ptr->cubeTiles);
  MultisquareGlow_8006b384_oneliner_calls_fun();
}

static void Game_800520d0_calls_cubetiles_init(void) {
  register Game *game_ptr = &g_game;

  MultisquareGlow_InitStaticMembers(g_playercount);
  FUN_03C130_80075EB0_nineliner_allocs_heap(&game_ptr->unkE080);
  CubeTiles_Init(&game_ptr->cubeTiles);
}

void Game_Init(u8 numPlayers, u8 *handicap_arr) {
  register Game *game_ptr = &g_game;
  register s32 i;
  register s32 j;
  register s32 temp_s3;
  GameVars gameVars;
  register s32 k;
  register UnkStruct_1 *temp_s5;

  game_ptr->is_active = TRUE;
  D_800CFF50 = 1;
  rmonPrintf("Game_Init() : entry, numPlayers %d", numPlayers);
  for (i = 0; i < numPlayers; i++) {
    rmonPrintf(", handicap%d %d", i, handicap_arr[i]);
  }
  rmonPrintf("\n");
  for (j = 0; j < numPlayers; j++) {
    temp_s3 = handicap_arr[j];
    if (temp_s3 < 0) {
      debug_print_reason_routine_linenum("handicapValue to low", "game.c", 988);
    }
    if (temp_s3 >= 10) {
      debug_print_reason_routine_linenum("handicapValue to high", "game.c", 991);
    }
  }
  game_ptr->numPlayers = numPlayers;
  FUN_027BF0_Init(game_ptr->unkE4F8);
  game_ptr->unkE4E8 = 0;  // gameElapsedTime
  game_ptr->topOutCount = 0;
  game_ptr->unk7 = 120;  // 120 jiffies (2 seconds delay after end of game before you can exit)
  switch (game_ptr->gameType) {
  case GAMETYPE_MARATHON:
    break;
  case GAMETYPE_SPRINT:
    game_ptr->unkE4F0 = 10800;  // 3 minutes (in jiffies)
    break;
  case GAMETYPE_ULTRA:
    game_ptr->unkE4F4 = 150;
    break;
  default:
    debug_print_reason_routine_linenum("Unknown GAMETYPE", "game.c", 1049);
    break;
  }
  game_ptr->unk0 = 0;
  game_ptr->unk3 = 0;
  g_playercount = numPlayers;
  CubeTiles_Init(&game_ptr->cubeTiles);
  FUN_03C130_80075EB0_nineliner_allocs_heap(&game_ptr->unkE080);
  Landfill_Init(&game_ptr->landfill);
  func_8007635C();
  MultisquareGlow_InitStaticMembers(numPlayers);
  gamefinish_8005344C_fiveliner(numPlayers);
  FUN_SRAM_80077408_twentyliner_loops_46t(&game_ptr->unk8, 9);  // init font?
  game_ptr->unkE4FC.alpha = 0.0f;
  game_ptr->unkE4FC.unk8 = 255.0f;
  game_ptr->unkE4FC.unk4 = (255.0f - game_ptr->unkE4FC.alpha) / 16.0f;
  game_ptr->unkE508 = TRUE;
  gameVars.seed = __ull_div(__ll_mul(g_sram_ptr->unk18F4, 64), 3);
  g_sram_ptr->unk18F4 = __ull_div(__ll_mul(osGetTime(), 64), 3);
  func_8007C5CC(g_sram_ptr);
  gameVars.unk4 = &game_ptr->unkE080;
  gameVars.unk8 = game_ptr->unkE4F8;
  gameVars.gameType = game_ptr->gameType;
  for (k = 0; k < numPlayers; k++) {
    game_ptr->tetris_ptr_arr[k] = (Tetris *)n64HeapAlloc(sizeof(Tetris));
    Game_SetGlobalPointers(k);
    PlayerVars_SetGlobalPointers(k);
    temp_s5 = &g_PV_ptr->unk28;  // UnkStruct_1
    FUN_026900_80060ad4_oneliner_calls_fun(temp_s5);
    FUN_026900_80060b04_twelveliner_loops_32t(temp_s5, 0xF00, 8, 4);  // JPAD (U, D, R, L) only
    FUN_026900_80060b04_twelveliner_loops_32t(temp_s5, 0xC000, 16, 16);  // Buttons A and B only
    g_PV_ptr->unk20 = g_PV_ptr->unk24 = 0;
    gameVars.handicap = handicap_arr[k];
    Tetris_Init(game_ptr->tetris_ptr_arr[k], &gameVars);
  }
  FUN_80041260_twoliner();
  osWritebackDCacheAll();
  rmonPrintf("Game_Init() : Done\n");
}

void Game_Deinit(void) {
  register Game *game_ptr = &g_game;
  register s32 i;
  register s32 j;
  register s32 k;

  if (!game_ptr->is_active) {
    debug_print_reason_routine_linenum("oops", "game.c", 1165);
  }
  game_ptr->is_active = FALSE;
  rmonPrintf("\n\n\n*** Deinitializing the game ***\n");
  for (i = 0; i < game_ptr->numPlayers; i++) {
    if (Game_isGameWinner(game_ptr, i)) {
      rmonPrintf("Player %d is a winner!\n", i);
    } else {
      rmonPrintf("Player %d is a loser.\n", i);
    }
  }
  rmonPrintf("The jackpot goes to: ");
  for (j = 0; j < game_ptr->numPlayers; j++) {
    if (Game_isGameWinner(game_ptr, j)) {
      rmonPrintf("Player %d ", j);
    }
  }
  rmonPrintf("\n");
  FUN_027BF0_Deinit(0);
  aiplayer_80042b3c_calls_heap_unalloc();
  FUN_8004129c_fourliner();
  for (k = 0; k < game_ptr->numPlayers; k++) {
    Game_SetGlobalPointers(k);
    Tetris_Deinit(game_ptr->tetris_ptr_arr[k]);
    n64HeapUnalloc((void *)game_ptr->tetris_ptr_arr[k]);
    game_ptr->tetris_ptr_arr[k] = NULL;
  }
  gamefinish_800534A4_fiveliner();
  MultisquareGlow_8006b384_oneliner_calls_fun();
  func_800763B4();
  FUN_SRAM_n64HeapUnalloc_and_set_to_NULL(&game_ptr->unk8);  // deinit font?
  Landfill_Deinit(&game_ptr->landfill);
  CubeTiles_Deinit(&game_ptr->cubeTiles);
  func_80075F5C(&game_ptr->unkE080);
  g_playercount = 0;
  game_ptr->unk0 = 3;
  rmonPrintf("Game_Deinit() : Done\n");
}
