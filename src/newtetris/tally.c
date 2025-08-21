#include "common.h"

extern s8 D_800CF830;
extern s8 D_800CF838;
extern u8 D_800CFD48;

////////////////////////////////////////

static s32 D_800D0140 = TRUE;
static s32 D_800D0144 = FALSE;
static u8 D_800D0148 = 0;
static s32 D_800D014C = 0;
static s32 D_800D0150 = 0;
static u8 D_800D0154 = 0;
static u8 D_800D0158 = 2;

static void *D_8011F240;
static s32 D_8011F244;  // unused
static s32 D_8011F248;  // unused
static s32 D_8011F24C;  // unused
static void *D_8011F250;
static u8 D_8011F254;
static void *D_8011F258;

static void   calls_game_deinit(void);
static void   FUN_80055704_threeliner(void);

void gets_lineCounts_loops_numPlayers_checks_gametype(void) {
  s32 i, j;
  PlayerNode *sp2C;
  GameResults *sp28;
  register s32 pack;

  sp28 = &g_game.results;
  D_800D014C = 0;
  D_8011F254 = 0;
  D_800D0148 = 0;
  if (D_800CFEE8 != 11) {    // if normal end of game (ie, did not exit from pause menu)
    for (i = 0; i < 4; i++) {
      sp28->unk8[i] = 0;     // elapsed time
      sp28->unk18[i] = 0;    // line count
      sp28->unk1[i] = 0xFF;  // is a winner
      sp28->unk3C[i] = 0;
    }
    sp28->unk38 = 0;
    sp28->unk5 = g_playercount;
    sp28->unk0 = Game_countWinners(&g_game);
    for (i = 0; i < sp28->unk5; i++) {
      sp28->unk8[i] = g_game.tetris_ptr_arr[i]->gameStats.elapsedTime / 60;
      sp28->unk18[i] = getLineCount(&g_game.tetris_ptr_arr[i]->gameStats.linesInfo);
      sp28->unk38 += sp28->unk18[i];
      sp28->unk28[i] = g_game.tetris_ptr_arr[i]->lineScan.unk3EC;
      if (g_game.gameType == GAMETYPE_SPRINT) {
        if (sp28->unk8[i] >= 179) {
          sp28->unk8[i] = 180;
        }
      }
    }
    if (sp28->unk0 == 0) {
      sp28->unk0 = 1;
    }
    sp28->unk38 /= sp28->unk0;
    if (D_800CFED4 > 1) {
      for (i = 0; i < sp28->unk5; i++) {
        sp28->unk1[i] = Game_isGameWinner(&g_game, i);
      }
    } else {
      sp28->unk1[0] = 1;
    }

    for (i = 0; i < sp28->unk5; i++) {
      sp2C = func_8007AA5C(&D_800D2D80, &g_game.players[i].node);
      if (sp2C != NULL) {
        if (sp2C->ptr != NULL) {
          sp28->unk3C[i] = sp2C->ptr;
          FUN_SRAM_8007875c_check_gameover_conditions(sp2C->ptr, sp28, i);
          func_8007B420(sp2C->ptr);
          pack = sp2C->pack & 0xF;
          if (pack != 0xC) {
            if (pack == 0xD) {
              for (j = 0; j < 32; j++) {
                if ((1 << j) & g_sram_ptr->unk0) {
                  if (func_8007AADC((u8 *) (g_sram_ptr->unk4 + j), sp2C->ptr->node.salt[0], sp2C->ptr->node.salt[1])) {
                    func_8007AF88(sp2C->ptr, (u8 *) g_sram_ptr->unk4, j * sizeof(UnkStruct_34));
                  }
                }
              }
              func_8007C5CC(g_sram_ptr);
            }
          } else {
            D_8011F254 |= 1 << i;
          }
        } else {
          sp28->unk3C[i] = NULL;
        }
      }
    }
    D_800D0144 = FALSE;
  } else {  // exit from pause menu
    sp28->unk5 = g_playercount;
    D_800D0144 = TRUE;
  }

  D_800CFEE8 = 10;
  D_800CFD48 = TRUE;
  D_800D0140 = TRUE;
}

static void calls_game_deinit(void) {
  main_8004A34C_threeliner();
  Audio_UnloadSFX();
  Game_Deinit();
  Audio_LoadSFX(&D_800D3988);
  D_8011F250 = n64HeapAlloc(240008);
  ((u8 *) D_8011F250)[0] = 1;
  ((u8 *) D_8011F250)[1] = 0x90;
  ((u8 *) D_8011F250)[2] = 1;
  ((u8 *) D_8011F250)[3] = 0x2C;
  ((u8 *) D_8011F250)[4] = 0;
  ((u8 *) D_8011F250)[5] = 0;
  ((u8 *) D_8011F250)[6] = 0;
  ((u8 *) D_8011F250)[7] = 0;
  func_800A8FC8((s16 *) D_8011F250, 120004, 0);
  func_8008F280(&D_801290D0, -1, 400, 300, D_8011F250);
  func_8008F360(&D_801290D0, D_800D6010, D_800D5FE8);
  D_800D3CF4 = 0;
  D_800D3CF8 = NULL;
  D_800D3CFC = NULL;
  D_801290D0.unk114 = 0;
  D_8011F240 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_INVISIBLE_TROPHY));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_8011F240, IMG_INVISIBLE_TROPHY);
  D_8011F258 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_RECTANGLE));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_8011F258, IMG_RECTANGLE);
  Font_Init46Char(&D_80128EB0, IMG_FONT_A);
  Font_Init46Char(&D_80128F28, IMG_FONT_B);
  Font_Init46Char(&D_80128FA0, IMG_FONT_C);
}

static void FUN_80055704_threeliner(void) {
  s32 unused;

  n64HeapUnalloc(D_8011F258);
  n64HeapUnalloc(D_8011F240);
  func_80090A44();
}

void game_over_display_stuff_huge_function_q(void) {
  GameResults *spFC;
  Player *spF8;
  PlayerNode *spF4;
  u8 spB8[60];
  s32 spB4;
  s32 unused;
  s32 spAC;
  s32 spA8;
  s32 spA4;
  s32 spA0;
  u32 sp9C;
  OSPfsState sp7C;
  u8 sp7B;
  s32 sp74;
  s32 sp70;
  s32 sp6C;
  u8 sp6B;
  u8 *sp64;

  spFC = &g_game.results;
  spF8 = g_game.players;

  // if exited from pause menu
  if (D_800D0144 && D_800D0140) {
    main_8004A34C_threeliner();
    Game_Deinit();
    D_800D014C = 0;
    if ((spFC->unk5 > 1) && (spF8[1].unkD0 == 0)) {
      func_8009035C(D_800D5D48, D_800D5CE8);
    } else {
      func_8009035C(D_800D5850, D_800D5808);
    }
    D_800CFEE8 = 4;
    D_800CFD48 = TRUE;
    D_800D0140 = FALSE;
    D_800D0154 = 0;
    return;
  }

  // if normal end of game
  if (D_800D0140 && !D_800D0144) {
    main_8004A34C_threeliner();
    calls_game_deinit();
    D_800D0140 = FALSE;
    D_800D0150 = 0;
    D_800D0154 = 0;
    return;
  }

  if ((D_800D0150 < 120) && (g_PV_arr[0].unk24 & 0x8000)) {
    if (D_800D0150 < 30) {
      D_800D0150 = 30;
    } else if (D_800D0150 < 60) {
      D_800D0150 = 60;
    } else if (D_800D0150 < 90) {
      D_800D0150 = 90;
    } else if (D_800D0150 < 120) {
      D_800D0150 = 120;
    }
  }

  if (D_8011F254 == 0) {
    D_800D014C++;
  }

  // 50 seconds
  if ((D_800D014C >= 3000) || ((g_PV_arr[0].unk24 & 0x8000) && (D_800D0150 > 120))) {
    D_800D014C = 3000;
    if (D_800D0158-- == 0) {
      D_800D0158 = 2;
      FUN_80055704_threeliner();
      if ((spFC->unk0 != 0) && wonders2_80045fdc_sets_num_won_compl_q()) {
        g_game.unkE4F8 = D_800CF838;
        if ((spFC->unk5 > 1) && (spF8[1].unkD0 == 0)) {
          D_801109F0 = 6;
        } else {
          D_801109F0 = 5;
        }
        main_8004A34C_threeliner();
        D_800D3CF0 = 0;
        D_800CFEE8 = 7;
        wonders1_anim_related(D_800CF830);
        return;
      }
      if ((spFC->unk5 > 1) && (spF8[1].unkD0 == 0)) {
        func_8009035C(D_800D5D48, D_800D5CE8);
      } else {
        func_8009035C(D_800D5850, D_800D5808);
      }
      D_800CFEE8 = 4;
      D_800CFD48 = TRUE;
      return;
    }
    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_801290D0.unk124->unk0.data.img, D_801290D0.unk124->unk0.pal, D_801290D0.unk124->unk0.x, D_801290D0.unk124->unk0.y, D_801290D0.unk124->unk0.r, D_801290D0.unk124->unk0.g, D_801290D0.unk124->unk0.b, D_801290D0.unk124->unk0.a);
    func_8005BE40(&g_gdl);
    return;
  }

  func_8009D5E4();

  if (D_8011F254 != 0) {
    spA8 = 60;
    spA4 = 50;
    spA0 = 50;
    func_8005BBFC(&g_gdl);
    if (D_8011F254 & (1 << D_800D0154)) {
      sp7B = 0x1A;  // cpak note extension name base 'A' (N64 font code)
      sp70 = sp74 = 0;
      switch (D_800D0148) {
      case 0:
        sp9C = FUN_001050_cpakInit(&superThread, D_800D0154);
        if ((sp9C >> 4) & 0xF) {
          D_800D0148 = 1;
          return;
        }
        bzero(&sp7C.ext_name, 4);
        bzero(&sp7C.game_name, 16);
        sp7C.file_size = 128;
        sp7C.game_code = 0x4E524945;  // NRIE
        sp7C.company_code = 0x3031;   // 01
        // "NEWTETRIS" (using N64 font codes, see cpak docs or ncode.h from the n64sdk)
        sprintf(sp7C.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);
        sp7C.ext_name[0] = sp7B;
        sp64 = n64HeapAlloc(0x80);
        sp6B = FALSE;
        for (sp70 = sp74 = 0; sp74 < 16; sp74++) {
          sp7C.ext_name[0] = sp7B + sp74;
          sp9C = FUN_001050_cpakFindFile(&superThread, &sp7C, D_800D0154);
          if (((sp9C >> 4) & 0xF) == 0) {
            sp6C = sp9C;
            sp9C = FUN_001050_cpakRead(&superThread, sp9C, 0x20, 0, sp64, D_800D0154);
            if (func_8007AADC(sp64, spFC->unk3C[D_800D0154]->node.salt[0], spFC->unk3C[D_800D0154]->node.salt[1])) {
              bzero(sp64, 0x80);
              func_8007B420(spFC->unk3C[D_800D0154]);
              func_8007AF88(spFC->unk3C[D_800D0154], sp64, 0);
              sp9C = FUN_001050_cpakWrite(&superThread, sp6C, 0x80, 0, sp64, D_800D0154);
              if (((sp9C >> 4) & 0xF) != 0) {
                D_800D0148 = 2;
                n64HeapUnalloc(sp64);
                return;
              }
              sp6B = FALSE;
              break;
            }
          } else if (((sp9C >> 4) & 0xF) == 5) {
            sp6B = TRUE;
          }
        }

        if (sp6B) {
          D_800D0148 = 3;
          n64HeapUnalloc(sp64);
          return;
        }

        n64HeapUnalloc(sp64);
        D_8011F254 = ~(1 << D_800D0154) & D_8011F254;
        break;
      case 1:
        spA8 = 60;
        spA4 = 50;
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011F258, NULL, 50, 40, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(spB8, "%s", spF8[D_800D0154].node.name);
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "PLEASE INSERT YOUR CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 15;
        sprintf(spB8, "INTO CONTROLLER %d OR DATA MAY BE LOST", D_800D0154 + 1);
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 20;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        spA8 += get_text_width(&D_80128F28, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "A ", 0x5A, 0x50, 0xB9, 0xFF);
        spA8 += get_text_width(&D_80128F28, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "TO SAVE", 0xFF, 0xFF, 0, 0xFF);
        spA4 += 17;
        spA8 = 60;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        spA8 += get_text_width(&D_80128F28, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "B ", 0x70, 0xC3, 0x74, 0xFF);
        spA8 += get_text_width(&D_80128F28, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, spA8, spA4, "TO CANCEL", 0xFF, 0xFF, 0, 0xFF);
        if (g_PV_arr[D_800D0154].unk24 & 0x8000) {
          D_800D0148 = 0;
          return;
        }
        if (g_PV_arr[D_800D0154].unk24 & 0x4000) {
          D_8011F254 = ~(1 << D_800D0154) & D_8011F254;
          D_800D0148 = 0;
          return;
        }
        break;
      case 3:
        spA8 = 60;
        spA4 = 50;
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011F258, NULL, 52, 41, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(spB8, "%s", spF8[D_800D0154].node.name);
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "YOU WERE NOT FOUND ON THIS CONTROLLER", 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 14;
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "PAK. PLEASE INSERT YOUR CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 14;
        sprintf(spB8, "INTO CONTROLLER %d OR DATA MAY BE LOST", D_800D0154 + 1);
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        spA4 += 17;
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        spA8 += get_text_width(&D_80128FA0, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "A ", 0x5A, 0x50, 0xB9, 0xFF);
        spA8 += get_text_width(&D_80128FA0, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "TO TRY AGAIN", 0xFF, 0xFF, 0, 0xFF);
        spA4 += 13;
        spA8 = 58;
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        spA8 += get_text_width(&D_80128FA0, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "B ", 0x70, 0xC3, 0x74, 0xFF);
        spA8 += get_text_width(&D_80128FA0, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, spA8, spA4, "TO CANCEL", 0xFF, 0xFF, 0, 0xFF);
        if (g_PV_arr[D_800D0154].unk24 & 0x8000) {
          D_800D0148 = 0;
          return;
        }
        if (g_PV_arr[D_800D0154].unk24 & 0x4000) {
          D_8011F254 = ~(1 << D_800D0154) & D_8011F254;
          D_800D0148 = 0;
          return;
        }
        break;
      }
    } else {
      D_800D0154++;
    }

    func_8005BE40(&g_gdl);
    return;
  }

  func_8005BBFC(&g_gdl);
  gDPPipeSync(g_gdl++);

  if (!D_800D0144) {
    Player *sp5C;
    s32 rank;

    D_800D0150++;

    // display name and rank
    for (spB4 = 90, spAC = 0; spAC < spFC->unk5; spAC++, spB4 += 25) {
      sp5C = &spF8[spAC];
      gDPPipeSync(g_gdl++);
      displayText_XY_RGBA_2(&g_gdl, &D_80128F28, 46, spB4 + 4, sp5C->node.name, 0xFF, 0xFF, 0xFF, 0xFF);
      gDPPipeSync(g_gdl++);
      if (D_800D0150 > 90) {
        spF4 = func_8007AA5C(&D_800D2D98, &sp5C->node);
        if (spF4 != NULL) {
          rank = FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(spF4->ptr) + 1;
        } else {
          rank = FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(sp5C) + 1;
        }
      } else {
        rank = FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(sp5C) + 1;
      }
      gDPPipeSync(g_gdl++);
      sprintf(spB8, "%d", rank);
      displayText_XY_RGBA_2(&g_gdl, &D_80128F28, 166 - (get_text_width(&D_80128F28, spB8) / 2), spB4 + 4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    // display score and time
    if (D_800D0150 > 30) {
      for (spB4 = 93, spAC = 0; spAC < spFC->unk5; spAC++, spB4 += 25) {
        sprintf(spB8, "%d", spFC->unk18[spAC]);
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, 240 - (get_text_width(&D_80128F28, spB8) / 2), spB4, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        displayTimeFormatted_XY_RGBA(spFC->unk8[spAC] * 60, &D_80128F28, 333, spB4, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPPipeSync(g_gdl++);
      }
    }

    // display trophy
    if ((D_800D0150 > 60) && (spFC->unk5 > 1)) {
      for (spB4 = 90, spAC = 0; spAC < spFC->unk5; spAC++, spB4 += 25) {
        if (spFC->unk1[spAC] == 1) {
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011F240, NULL, 12, spB4, 0xFF, 0xFF, 0xFF, 0xFF);
        }
      }
    }

    if (D_800D0150 > 90) {
      for (spB4 = 90, spAC = 0; spAC < spFC->unk5; spAC++, spB4 += 25) {
        sp5C = &spF8[spAC];
        spF4 = func_8007AA5C(&D_800D2D98, &sp5C->node);
        if (spF4 != NULL) {
          if (FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(spF4->ptr) != FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(sp5C)) {
            // empty -- maybe debug print excised?
          }
        }
      }
    }

    if (D_800D0150 > 120) {
      if (spFC->unk0 > 1) {
        if (spFC->unk38 != 0) {
          if (spFC->unk38 == 1) {
            sprintf(spB8, "WINNERS GET %d LINE", spFC->unk38);
          } else {
            sprintf(spB8, "WINNERS GET %d LINES", spFC->unk38);
          }
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, 62, 198, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
        }
      } else {
        for (spAC = 0; spAC < spFC->unk5; spAC++) {
          sp5C = &spF8[spAC];
          if (spFC->unk1[spAC] == 1) {
            if (spFC->unk38 != 0) {
              if (spFC->unk38 == 1) {
                sprintf(spB8, "%s WINS %d LINE", sp5C->node.name, spFC->unk38);
              } else {
                sprintf(spB8, "%s WINS %d LINES", sp5C->node.name, spFC->unk38);
              }
              displayText_XY_RGBA_2(&g_gdl, &D_80128F28, 62, 195, spB8, 0xFF, 0xFF, 0xFF, 0xFF);
            }
          }
        }
      }
    }

    func_8005BE40(&g_gdl);
  }
}
