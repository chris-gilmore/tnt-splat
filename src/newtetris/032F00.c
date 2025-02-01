#include "common.h"

extern s8 D_800CF838;
extern u8 D_800CFD48;

////////////////////////////////////////

s32 D_800D0550 = 0;
static s32 D_800D0554 = 30;

static void   FUN_032F00_8006cc80_twentyliner_checks_pnum_1_2_4(void);
static void   FUN_032F00_8006cd98_tenliner_checks_12(void);
static void   FUN_032F00_8006ce30_tenliner_magic_4000(void);
static void   FUN_032F00_8006cedc_sets_glb_to_fun_call_glb(void);

static void FUN_032F00_8006cc80_twentyliner_checks_pnum_1_2_4(void) {
  register s32 temp_s0;

  temp_s0 = func_800721D8();
  D_801109F4 = func_800A3AF0();
  Game_line_782_game_c(&g_game);
  Game_render_stuff_line_850(&g_game);
  func_80072248();
  switch (temp_s0) {
  case 1:
    func_800721A4();
    Game_80051618_twentyliner(&g_game);
    D_800CFEE8 = 9;
    D_800CFD48 = TRUE;
    break;
  case 2:
    temp_s0 = D_800D05C0->unk89;
    func_800721A4();
    D_801109F0 = 9;
    D_800CFEE8 = 8;
    D_800CFD48 = TRUE;
    wonders3_wonder_viewer(D_800CF838, 0, temp_s0);
    break;
  case 4:
    func_800721A4();
    gets_lineCounts_loops_numPlayers_checks_gametype();
    break;
  }
}

static void FUN_032F00_8006cd98_tenliner_checks_12(void) {
  D_801109F4 = func_800A3AF0();
  Game_line_782_game_c(&g_game);
  Game_render_stuff_line_850(&g_game);

  switch (g_game.unk1) {
  case 2:
    gets_lineCounts_loops_numPlayers_checks_gametype();
    break;
  case 1:
    if (func_80072140(g_game.unk4)) {
      D_800CFEE8 = 11;
      D_800CFD48 = FALSE;
    }
    break;
  }
}

static void FUN_032F00_8006ce30_tenliner_magic_4000(void) {
  D_800D0550++;
  D_801109F4 = func_800A3AF0();
  Game_line_782_game_c(&g_game);
  Game_render_stuff_line_850(&g_game);
  if (g_game.unk1 == 2) {
    D_800D0550 = 4000;
  }
  if (D_800D0550 >= 4000) {
    main_8004A34C_threeliner();
    Game_Deinit();
    D_800CFEE8 = 17;
    D_800D0550 = 0;
  }
}

static void FUN_032F00_8006cedc_sets_glb_to_fun_call_glb(void) {
  g_gdl = func_8007DA00(g_gdl);
}

void debug_print2(const char *arg0, const char *arg1) {
}

void FUN_032F00_MVC_control_menu_choice_process(void) {
  register s32 unused;

  switch (D_800CFEE8) {
  case 0:
    FUN_0279C0_80061740_switch_0to8_1to6_same();
    break;
  case 14:
    FUN_010870_OptionsDataMenu();
    break;
  case 1:
    func_80080B50();
    break;
  case 2:
    func_80083160();
    break;
  case 3:
    func_8007F344();
    break;
  case 4:
    func_80090E08();
    break;
  case 7:
    wonders1_case6_calls_music_magic();
    wonders1_something_hall_or_exit_case();
    break;
  case 8:
    wonders3_switch_0to7_6and7are_same();
    wonders3_switch_0to3_2and3are_same();
    break;
  case 11:
    FUN_032F00_8006cc80_twentyliner_checks_pnum_1_2_4();
    break;
  case 9:
    FUN_032F00_8006cd98_tenliner_checks_12();
    break;
  case 12:
    FUN_032F00_8006ce30_tenliner_magic_4000();
    break;
  case 16:
    Credits_StateMachine_q();
    break;
  case 13:
    FUN_032F00_8006cedc_sets_glb_to_fun_call_glb();
    break;
  case 10:
    game_over_display_stuff_huge_function_q();
    break;
  case 17:
    D_800D0554--;
    if (D_800D0554 == 0) {
      D_800D0554 = 30;
      D_800CFEE8 = 4;
      func_800905E8(0);
      D_800CFD48 = TRUE;
    }
    break;
  }
}
