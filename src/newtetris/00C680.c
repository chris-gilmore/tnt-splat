#include "common.h"

extern u16 draw_buffer;
extern s8 D_800CF830;
extern s8 D_800CF838;
extern u8 D_800CFD48;

////////////////////////////////////////

static void *D_800E1F80;
static void *D_800E1F84;

static UnkStruct_11 D_800CF950 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 1072 };
static UnkStruct_11 D_800CF980 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 1048 };
static UnkStruct_11 D_800CF9B0 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 189 };
static UnkStruct_11 D_800CF9E0 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 317 };
static UnkStruct_11 D_800CFA10 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 376 };
static UnkStruct_11 D_800CFA40 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 472 };
static UnkStruct_11 D_800CFA70 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 560 };
static UnkStruct_11 D_800CFAA0 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 757 };
static UnkStruct_11 D_800CFAD0 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 891 };
static UnkStruct_11 D_800CFB00 = { NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0x42200000, 0, 1426 };
static UnkStruct_11 *D_800CFB30[11] = {
  &D_800CF9B0,
  &D_800CF9E0,
  &D_800CFA10,
  &D_800CFA40,
  &D_800CFA70,
  &D_800CFAA0,
  &D_800CFAD0,
  &D_800CF950,
  &D_800CF980,
  &D_800CFB00,
  NULL
};
static WonderViewer *wonderViewer = NULL;

static void wonders3_80046400_twentyliner(WonderViewer *);
static void wonders3_80046610_fifteenliner(WonderViewer *);
static void wonders3_80046798_threeliner(WonderViewer *);
static void wonders3_800467f8_threeliner(WonderViewer *);
static void wonders3_init_tuples(WonderViewer *);
static void wonders3_display_wonders_hall_text(void);
static void wonders3_related(void);
static void wonders3_no_idea_menu_img_button(void);
static void wonders3_8004745c_medium_liner_has_audio(void);

static void wonders3_80046400_twentyliner(WonderViewer *wndrVwr) {
  register u32 temp_s0 = g_PV_arr[wndrVwr->playernum].unk24;

  if ((wndrVwr->unk2 && (temp_s0 & 0x8000)) && (!(wndrVwr->cur_screen < 7) || (wndrVwr->cur_screen < D_800CF838) || ((wndrVwr->cur_screen == D_800CF838) && (D_800CF830 != -1) && (wonders2_divide_by_seven(D_800CF830) == wndrVwr->cur_screen)))) {  // A_BUTTON / CONT_A
    wndrVwr->unk0 = 6;
  } else if (temp_s0 & 0x4000) {  // B_BUTTON / CONT_B
    wndrVwr->unk0 = 7;
  } else if (wndrVwr->unk2 && (temp_s0 & 0x200)) {  // L_JPAD / CONT_LEFT
    if (wndrVwr->cur_screen != 0) {
      wndrVwr->next_screen = wndrVwr->cur_screen - 1;
    } else if (D_800CF840) {
      wndrVwr->next_screen = 7;
    } else {
      wndrVwr->next_screen = 6;
    }
    wndrVwr->unk0 = 5;
  } else if (wndrVwr->unk2 && (temp_s0 & 0x100)) {  // R_JPAD / CONT_RIGHT
    if ((D_800CF840 && (wndrVwr->cur_screen < 7)) || (wndrVwr->cur_screen < 6)) {
      wndrVwr->next_screen = wndrVwr->cur_screen + 1;
    } else {
      wndrVwr->next_screen = 0;
    }
    wndrVwr->unk0 = 5;
  }
}

static void wonders3_80046610_fifteenliner(WonderViewer *wndrVwr) {
  if (wndrVwr == NULL) {
    return;
  }

  if (wndrVwr->cur_screen >= 7) {
    wndrVwr->unk8 = D_800CFB30[9];
  } else {
    if (wndrVwr->cur_screen < D_800CF838) {
      wndrVwr->unk8 = D_800CFB30[wndrVwr->cur_screen];
    } else if (wndrVwr->cur_screen > D_800CF838) {
      wndrVwr->unk8 = D_800CFB30[7];
    } else if (D_800CF830 == 48) {
      wndrVwr->unk8 = D_800CFB30[wndrVwr->cur_screen];
    } else {
      wndrVwr->unk8 = D_800CFB30[8];
    }
  }
  func_80076EC0(wndrVwr->unk8, 1);
  func_800A4654(wndrVwr->unk8->unk0);
  wndrVwr->unk8->unk0->unk8->unk10.unk20 = NULL;
  func_800773A4(wndrVwr->unk8);
  wndrVwr->unk0 = 0;
}

static void wonders3_80046798_threeliner(WonderViewer *wndrVwr) {
  if (wndrVwr == NULL) {
    return;
  }

  if (wndrVwr->unk8 == NULL) {
    return;
  }

  func_80077028(wndrVwr->unk8);
  wndrVwr->unk8 = NULL;
}

static void wonders3_800467f8_threeliner(WonderViewer *wndrVwr) {
  wonders3_80046798_threeliner(wndrVwr);
  wndrVwr->cur_screen = wndrVwr->next_screen;
  wonders3_80046610_fifteenliner(wndrVwr);
}

static void wonders3_init_tuples(WonderViewer *wndrVwr) {
  register u8 screen;

  Font_Init46Char(&wndrVwr->font[0], IMG_FONT_B);
  Font_Init46Char(&wndrVwr->font[1], IMG_FONT_C);

  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[10], IMG_WONDER, IMG_WONDER_PAL);
  if (wndrVwr->unk2) {
    FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[0], IMG_ARROW_LEFT, IMG_ARROW_LEFT_PAL);
    FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[1], IMG_ARROW_RIGHT, IMG_ARROW_RIGHT_PAL);
  }
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[2], IMG_PROGRESS_PIE_A, IMG_PROGRESS_PIE_A_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[3], IMG_PROGRESS_PIE_B, IMG_PROGRESS_PIE_B_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[4], IMG_PROGRESS_PIE_C, IMG_PROGRESS_PIE_C_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[5], IMG_PROGRESS_PIE_D, IMG_PROGRESS_PIE_D_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[6], IMG_PROGRESS_PIE_E, IMG_PROGRESS_PIE_E_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[7], IMG_PROGRESS_PIE_F, IMG_PROGRESS_PIE_F_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[8], IMG_PROGRESS_PIE_G, IMG_PROGRESS_PIE_G_PAL);
  FUN_01D300_800571d4_twentyliner(&wndrVwr->imgPalParams[9], IMG_PROGRESS_PIE_H, IMG_PROGRESS_PIE_H_PAL);

  wndrVwr->imgPalParams[10].x = 3, wndrVwr->imgPalParams[10].y = 28;

  if (wndrVwr->unk2) {
    wndrVwr->imgPalParams[0].x = 55, wndrVwr->imgPalParams[0].y = 65;
    wndrVwr->imgPalParams[1].x = 300, wndrVwr->imgPalParams[1].y = 65;
  }

  for (screen = 0; screen < 8; screen++) {
    wndrVwr->imgPalParams[2 + screen].x = 35, wndrVwr->imgPalParams[2 + screen].y = 150;
  }

  wndrVwr->unk0 = 4;
}

void wonders3_switch_0to7_6and7are_same(void) {
  register WonderViewer *wndrVwr = wonderViewer;

  if (wndrVwr == NULL) {
    return;
  }

  switch (wndrVwr->unk0) {
  case 0:
    wonders3_80046400_twentyliner(wndrVwr);
    break;
  case 1:
    if (D_801290D0.unk114 != 0) {
      n64HeapUnalloc(D_801290D0.img);
      func_8009F338(&D_801290D0);
      wndrVwr->unk0 = 2;
      main_8004A34C_threeliner();
    }
    break;
  case 2:
    wndrVwr->unk0 = 3;
    break;
  case 3:
    wonders3_init_tuples(wndrVwr);
    break;
  case 4:
    wonders3_80046610_fifteenliner(wndrVwr);
    break;
  case 5:
    wonders3_800467f8_threeliner(wndrVwr);
    break;
  case 6:
  case 7:
    wonders3_8004745c_medium_liner_has_audio();
    break;
  }
}

static void wonders3_display_wonders_hall_text(void) {
  register WonderViewer *wndrVwr = wonderViewer;
  register s8 var_s1;
  register s8 var_s2;
  register s32 var_s3;
  register u16 var_s4;
  register u16 var_s5;
  register u16 temp_s6;
  char sp58[12];

  if (wndrVwr == NULL) {
    return;
  }

  func_8005BBFC(&g_gdl);
  weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_800E1F80, D_800E1F84, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
  FUN_01D300_80057338_fifteenliner(&wndrVwr->imgPalParams[10]);

  if ((wndrVwr->cur_screen != D_800CF838) || (wonders2_divide_by_seven(D_800CF830) != wndrVwr->cur_screen)) {
    var_s1 = wonders2_8004624c_mult_7_add_6_etc(wndrVwr->cur_screen);
  } else {
    var_s1 = D_800CF830;
  }

  if ((D_800CF830 != 48) && (var_s1 < 49)) {
    var_s3 = wonders2_80046388_fiveliner(wonders2_divide_by_seven(var_s1));
    if (D_800CF830 >= var_s1) {
      var_s2 = (var_s1 - (wonders2_divide_by_seven(var_s1) * 7)) + 1;
    } else {
      var_s2 = 0;
    }
  } else {
    var_s3 = 0;
    var_s2 = 7;
  }

  FUN_01D300_80057338_fifteenliner(&wndrVwr->imgPalParams[2 + var_s2]);
  sprintf(sp58, "%d", var_s3);
  var_s4 = 70 - (get_text_width(&wndrVwr->font[0], sp58) / 2);
  var_s5 = 180;
  displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[0], var_s4, var_s5, sp58, 0xFF, 0xFF, 0xFF, 0xFF);

  if (wndrVwr->unk2) {
    FUN_01D300_80057338_fifteenliner(&wndrVwr->imgPalParams[0]);
    FUN_01D300_80057338_fifteenliner(&wndrVwr->imgPalParams[1]);
  }

  sprintf(sp58, "%s", D_800CF844[wndrVwr->cur_screen]);
  var_s4 = 200 - (get_text_width(&wndrVwr->font[0], sp58) / 2);
  displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[0], var_s4, 80, sp58, 0xFF, 0xFF, 0xFF, 0xFF);

  temp_s6 = wndrVwr->font[0].width;
  var_s4 = 130;
  var_s5 = 270;
  if (wndrVwr->unk2) {
    sprintf(sp58, "A");
    displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[0], var_s4, var_s5, sp58, 0x7F, 0x7F, 0xFF, 0xFF);
    var_s4 += temp_s6;
    var_s5 += 1;
    sprintf(sp58, "ACCEPT");
    displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[1], var_s4, var_s5, sp58, 0xFF, 0xFF, 0xFF, 0xFF);
    var_s4 += temp_s6 + get_text_width(&wndrVwr->font[1], sp58);
    var_s5 -= 1;
  } else {
    sprintf(sp58, "ACCEPT");
    var_s4 += (temp_s6 * 2) + get_text_width(&wndrVwr->font[1], sp58);
  }
  sprintf(sp58, "B");
  displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[0], var_s4, var_s5, sp58, 0x7F, 0xFF, 0x7F, 0xFF);
  var_s4 += temp_s6;
  var_s5 += 1;
  sprintf(sp58, "BACK");
  displayText_XY_RGBA_2(&g_gdl, &wndrVwr->font[1], var_s4, var_s5, sp58, 0xFF, 0xFF, 0xFF, 0xFF);
  func_8005BE40(&g_gdl);
}

static void wonders3_related(void) {
  register WonderViewer *wndrVwr = wonderViewer;

  if (wndrVwr == NULL) {
    return;
  }

  if (wndrVwr->unk8 == NULL) {
    return;
  }

  wonders3_display_wonders_hall_text();
  func_80077098(wndrVwr->unk8);
}

static void wonders3_no_idea_menu_img_button(void) {
  register WonderViewer *wndrVwr = wonderViewer;

  if (wndrVwr == NULL) {
    return;
  }

  func_800A0228(&D_801290D0);

  func_8005BBFC(&g_gdl);

  gDPPipeSync(g_gdl++);

  gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_PHYSICAL_TO_K0(D_801290D0.img));

  weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_800E1F80, D_800E1F84, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

  gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_PHYSICAL_TO_K0(cfb[draw_buffer]));

  func_8005BE40(&g_gdl);
}

void wonders3_switch_0to3_2and3are_same(void) {
  register WonderViewer *wndrVwr = wonderViewer;

  if (wndrVwr == NULL) {
    return;
  }

  if (wndrVwr->unk0 == 0) {
    wonders3_related();
  } else if (wndrVwr->unk0 == 1) {
    wonders3_no_idea_menu_img_button();
  } else if ((wndrVwr->unk0 == 2) || (wndrVwr->unk0 == 3)) {
    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_800E1F80, D_800E1F84, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
  } else {
    wonders3_display_wonders_hall_text();
  }
}

void wonders3_wonder_viewer(s8 screen, u8 arg1, u8 playernum) {
  register WonderViewer *wndrVwr;

  main_8004A34C_threeliner();
  wonderViewer = n64HeapAlloc(sizeof(WonderViewer));
  wndrVwr = wonderViewer;
  if (wndrVwr == NULL) {
    debug_print_reason_routine("Not enough memory", "for WonderViewer");
  }

  wndrVwr->playernum = playernum;
  wndrVwr->cur_screen = screen;
  wndrVwr->unk8 = 0;
  D_801290D0.img = n64HeapAlloc(240008);
  func_800A8FC8(((s16 *) D_801290D0.img) + 2, 120000, 0);  // minor bug, falls short by 2 shorts
  func_8008F280(&D_801290D0, -1, 400, 300, D_801290D0.img);
  D_800E1F80 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_MAIN_BACKGROUND));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_800E1F80, IMG_MAIN_BACKGROUND);
  D_800E1F84 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_MAIN_BACKGROUND_PAL));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_800E1F84, IMG_MAIN_BACKGROUND_PAL);
  func_8009FA2C(&D_801290D0);
  wndrVwr->unk0 = 1;
  wndrVwr->unk2 = arg1;
}

static void wonders3_8004745c_medium_liner_has_audio(void) {
  register WonderViewer *wndrVwr = wonderViewer;
  register u8 screen;
  register u8 temp_s2;

  wonders3_80046798_threeliner(wndrVwr);

  Font_Deinit(&wndrVwr->font[0]);
  Font_Deinit(&wndrVwr->font[1]);

  FUN_01D300_800572f8_twoliner(&wndrVwr->imgPalParams[10]);

  if (wndrVwr->unk2) {
    FUN_01D300_800572f8_twoliner(&wndrVwr->imgPalParams[0]);
    FUN_01D300_800572f8_twoliner(&wndrVwr->imgPalParams[1]);
  }

  for (screen = 0; screen < 8; screen++) {
    FUN_01D300_800572f8_twoliner(&wndrVwr->imgPalParams[2 + screen]);
  }

  n64HeapUnalloc(D_800E1F80);
  n64HeapUnalloc(D_800E1F84);

  screen = wndrVwr->cur_screen;
  temp_s2 = wndrVwr->unk0;

  n64HeapUnalloc(wonderViewer);
  wonderViewer = NULL;

  main_8004A34C_threeliner();
  D_800D3CF0 = 0;
  if (temp_s2 == 6) {
    if (screen < D_800CF838) {
      wonders1_anim_related(wonders2_8004624c_mult_7_add_6_etc(screen));
    } else if (screen == D_800CF838) {
      if (screen == 7) {
        wonders1_anim_related(49);
      } else {
        wonders1_anim_related(D_800CF830);
      }
    }
    D_800CFEE8 = 7;
  } else if (D_801109F0 == 5) {
    func_8009035C(D_800D5850, D_800D5808);
    D_800CFEE8 = 4;
    D_800CFD48 = 1;
  } else if (D_801109F0 == 6) {
    func_8009035C(D_800D5D48, D_800D5CE8);
    D_800CFEE8 = 4;
    D_800CFD48 = 1;
  } else if (D_801109F0 == 4) {
    func_800905E8(1);
    D_800CFEE8 = 4;
    D_800CFD48 = 1;
  } else {
    Audio_UnloadSFX();
    Game_80051618_twentyliner(&g_game);
    D_800CFEE8 = 9;
    D_800CFD48 = 1;
    Audio_LoadSFX(&D_800D3A90);
  }
}
