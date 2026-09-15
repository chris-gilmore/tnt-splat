#include "common.h"

static s32 D_80110580;
static s32 D_80110584;
static s32 D_80110588;
static Font D_80110590;
static Font D_80110608;
static Font D_80110680;
static Font D_801106F8;
static OSPfsState D_80110770[16];
static s32 D_80110970[16];
static u8 D_801109B0[16];
static u8 *D_801109C0;
static s32 D_801109C4;
static s32 D_801109C8;  // unused
static s32 D_801109CC;
static s32 D_801109D0;
static s32 D_801109D4;
static s32 D_801109D8;
static s32 D_801109DC;
static s32 D_801109E0;

static u8 D_800CFE50 = 0;
static s32 D_800CFE54 = 4;
static u8 D_800CFE58 = FALSE;
u8 D_800CFE5C = 0xF;
static char D_800CFE60[0x42] = {
  ' ', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', ' ',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  '!', '"', '#', '\'', '*', '+', ',', '-', '.', '/', ':', '=', '?', '@'
};
static s32 D_800CFEA4 = 0xFF;
static s32 D_800CFEA8 = 0;
static s32 D_800CFEAC = 0;
static u8 D_800CFEB0 = FALSE;
static s32 D_800CFEB4 = TRUE;
static f32 D_800CFEB8 = 0.0;
static f32 D_800CFEBC = 0.04;
static f32 D_800CFEC0 = 0.0;
static f32 D_800CFEC4 = 0.03;
static f32 D_800CFEC8 = 0.0;
static f32 D_800CFECC = 0.01;
s16 D_800CFED0 = 2;  // unused
s16 D_800CFED4 = 1;
s32 D_800CFED8 = 0;
s16 D_800CFEDC = 1;  // unused
u8 D_800CFEE0 = 0;  // enable fps measurement display
u8 D_800CFEE4 = 0;
u8 D_800CFEE8 = 15;
u32 D_800CFEEC = 0;
u32 D_800CFEF0 = 0;

static void FUN_010870_8004abe8_fifteenliner_1(void);
static void FUN_010870_8004acb0_fifteenliner_2(void);

void FUN_010870_interesting_stuff_large_liner(void) {
  if (osTvType == OS_TV_PAL) {
    D_800CFEE8 = 15;
    D_800CFED4 = 0;
    D_800CFE54 = 0;
    return;
  }

  while (func_800A3534(&g_PV_ptr->contQ) != 0) {
    func_800A33E4(&g_PV_ptr->contQ);
  }

  g_PV_ptr->unk1C = g_PV_ptr->contQ.unk14;
  g_PV_ptr->unk24 = (g_PV_ptr->unk20 ^ -1) & g_PV_ptr->unk1C->unk0;
  g_PV_ptr->unk20 = g_PV_ptr->unk1C->unk0;

  if (D_800CFE54 == 0) {
    return;
  }

  if (!(superThread.bitpattern & 0x1)) {
    func_80061124();
    func_80060D58(1);
    Audio_80084e20_twentyliner(SONG_HALUCI, &g_songPlayer, 1);
    Audio2_GFXDone_SendPlayMessage(&g_songPlayer);
    D_800CFEE8 = 0;
    D_800CFE54 = 0;
    func_80061134(400, 300);
    func_80060D58(0);
    return;
  }

  if (D_800CFE5C & (1 << g_PV_ptr->cont_no)) {
    D_80110584 = g_PV_ptr->cont_no;
    D_80110588 = FUN_001050_getControllerStatus(&superThread, D_80110584);
    D_800CFE5C &= ~(1 << D_80110584);
    if (!D_800CFE5C) {
      D_800CFE54 = 5;
    }

    if (D_80110588 & 0x2) {
      FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
      FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
      FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
      D_80110588 = FUN_001050_getControllerStatus(&superThread, D_80110584);
      if (D_80110588 & 0x2) {
        return;
      }
    }

    if ((D_80110588 & 0x1) && !(D_80110588 & 0x2)) {
      D_800CFE50 = 0;
      D_800CFE50 = FUN_001050_cpakInit(&superThread, D_80110584);
      if ((((D_800CFE50 >> 4) & 0xF) == 10) || (((D_800CFE50 >> 4) & 0xF) == 3) || (((D_800CFE50 >> 4) & 0xF) == 4)) {
        if ((superThread.unk25AE & (1 << D_80110584)) != 0) {
          D_800CFE50 = 0;
        } else {
          s32 sp1C = FUN_001050_gbpakInit(&superThread, D_80110584);

          if (sp1C == 0) {
            D_800CFE50 = 0;
          } else {
            D_800CFE50 = FUN_001050_cpakInit(&superThread, D_80110584);
            D_800CFEE8 = 14;
            D_800CFE54 = 0;
            D_800CFED4 = 4;
            return;
          }
        }
      } else if (((FUN_001050_cpakNumFiles(&superThread, D_80110584) & 0xFF) >= 16) || (FUN_001050_cpakFreeBlocks(&superThread, NULL, D_80110584) < 256)) {
        if (g_PV_arr[D_80110584].unk24 & 0x1000) {  // START_BUTTON / CONT_START
          D_800CFE58 = TRUE;
        } else {
          D_800CFE58 = FALSE;
        }

        D_800CFEE8 = 14;
        D_800CFE54 = 0;
        D_800CFED4 = 4;
        return;
      } else {
        D_800CFE50 = 0;
      }
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x1000) || (D_800CFE50 != 0)) {  // START_BUTTON / CONT_START
      if (!(g_PV_arr[D_80110584].unk24 & 0x4000)) {  // B_BUTTON / CONT_B
        D_800CFE58 = TRUE;
        D_80110584 = g_PV_ptr->cont_no;
        if (osTvType == OS_TV_PAL) {
          D_800CFEE8 = 15;
          D_800CFED4 = 0;
          return;
        }

        if (D_80110588 & 0x1) {
          D_80110588 = FUN_001050_cpakInit(&superThread, D_80110584) >> 4;
          if (D_80110588 & 0xF) {
            if (FUN_001050_gbpakInit(&superThread, D_80110584) == 0) {
              D_800CFE54--;
            } else if (superThread.unk25AE & (1 << D_80110584)) {
              D_800CFE54--;
            }
            return;
          } else {
            D_800CFEE8 = 14;
            D_800CFE54 = 0;
          }
        }

        D_800CFED4 = 4;
      }
      return;
    }
  }

  D_800CFE58 = FALSE;
  if (D_800CFE54 == 5) {
    D_800CFE54 = 0;
    D_800CFEE8 = 2;
  }
}

static void FUN_010870_8004abe8_fifteenliner_1(void) {
  s32 sp4;  // (bug?) Missing " = 0"

  D_800CFEA4--;
  if (D_800CFEA4 < 0) {
    D_800CFEA4 = 15;
  }

  while (D_801109B0[D_800CFEA4] == 0xFF) {
    sp4++;  // (bug?) Use of uninitialized variable
    if (sp4 >= 32) {
      D_800CFEA4 = 0xFF;
      D_800CFEA8 = 4;
      break;
    }

    D_800CFEA4--;
    if (D_800CFEA4 < 0) {
      D_800CFEA4 = 15;
    }
  }
}

static void FUN_010870_8004acb0_fifteenliner_2(void) {
  s32 sp4 = 0;

  D_800CFEA4++;
  if (D_800CFEA4 > 15) {
    D_800CFEA4 = 0;
  }

  while (D_801109B0[D_800CFEA4] == 0xFF) {
    sp4++;
    if (sp4 >= 32) {
      D_800CFEA4 = 0xFF;
      D_800CFEA8 = 4;
      break;
    }

    D_800CFEA4++;
    if (D_800CFEA4 > 15) {
      D_800CFEA4 = 0;
    }
  }
}

void FUN_010870_OptionsDataMenu(void) {
  char sp68[24];
  char sp60[8];
  char sp5C[4];
  char sp54[8];
  char sp4C[8];
  s32 unused[4];

  D_800CFEB8 += D_800CFEBC;
  D_800CFEC0 += D_800CFEC4;
  D_800CFEC8 += D_800CFECC;
  if (D_800CFEB8 >= 1.0) { D_800CFEB8 = 1.0; D_800CFEBC *= -1; }
  if (D_800CFEB8 <= 0.4) { D_800CFEB8 = 0.4; D_800CFEBC *= -1; }
  if (D_800CFEC0 >= 1.0) { D_800CFEC0 = 1.0; D_800CFEC4 *= -1; }
  if (D_800CFEC0 <= 0.4) { D_800CFEC0 = 0.4; D_800CFEC4 *= -1; }
  if (D_800CFEC8 >= 1.0) { D_800CFEC8 = 1.0; D_800CFECC *= -1; }
  if (D_800CFEC8 <= 0.4) { D_800CFEC8 = 0.4; D_800CFECC *= -1; }

  if (D_800CFEB4) {
    D_800CFEA4 = 0xFF;
    D_800CFEB4 = FALSE;
    FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
    D_800CFEB8 = 0.5;
    D_800CFEBC = 0.04;
    D_800CFEC0 = 0.6;
    D_800CFEC4 = 0.03;
    D_800CFEC8 = 0.7;
    D_800CFECC = 0.01;
    D_801109C4 = FUN_001050_getControllerStatus(&superThread, D_80110584);
    if (D_801109C4 & 0x1) {
      if (D_800CFE50 != 0) {
        Font_Init46Char(&D_80110590, IMG_FONT_C);
        Font_Init46Char(&D_80110608, IMG_FONT_A);
        Font_Init46Char(&D_80110680, IMG_FONT_B);
        Font_Init51Char(&D_801106F8, IMG_FONT_D);

        D_801109C0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_RECTANGLE));
        FUN_03A750_800746c0_twentyliner(&D_273A00, D_801109C0, IMG_RECTANGLE);

        D_800CFEA8 = 5;
      } else {
        Font_Init46Char(&D_80110590, IMG_FONT_C);
        Font_Init46Char(&D_80110608, IMG_FONT_A);
        Font_Init46Char(&D_80110680, IMG_FONT_B);
        Font_Init51Char(&D_801106F8, IMG_FONT_D);

        D_801109C0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_RECTANGLE));
        FUN_03A750_800746c0_twentyliner(&D_273A00, D_801109C0, IMG_RECTANGLE);

        D_80110580 = FUN_001050_cpakNumFiles(&superThread, D_80110584) & 0xFF;
        if (((FUN_001050_cpakNumFiles(&superThread, D_80110584) & 0xFF) >= 16) || (FUN_001050_cpakFreeBlocks(&superThread, NULL, D_80110584) < 256)) {
          if ((D_80110580 == 16) || (FUN_001050_cpakFreeBlocks(&superThread, NULL, D_80110584) < 256)) {
            D_800CFEB0 = TRUE;
            if (D_800CFE58) {
              for (D_801109CC = 0, D_801109D0 = 0; D_801109CC < 16; D_801109CC++) {
                D_80110970[D_801109CC] = FUN_001050_cpakFileState(&superThread, &D_80110770[D_801109CC], D_801109CC, D_80110584);
                if (D_80110970[D_801109CC] < 17) {
                  if (D_800CFEA4 == 0xFF) {
                    D_800CFEA4 = D_801109CC;
                  }
                  D_801109B0[D_801109D0] = D_801109CC;
                  D_801109D0++;
                } else {
                  D_801109B0[D_801109D0] = 0xFF;
                  D_801109D0++;
                }
              }

              D_800CFEA8 = 0;
            } else {
              D_800CFEA8 = 12;
            }

            D_800CFE58 = FALSE;
            return;
          }

          D_800CFEA8 = 12;
          return;
        }

        D_800CFEA8 = 0;

        for (D_801109CC = 0, D_801109D0 = 0; D_801109CC < 16; D_801109CC++) {
          D_80110970[D_801109CC] = FUN_001050_cpakFileState(&superThread, &D_80110770[D_801109CC], D_801109CC, D_80110584);
          if (D_80110970[D_801109CC] < 17) {
            if (D_800CFEA4 == 0xFF) {
              D_800CFEA4 = D_801109CC;
            }
            D_801109B0[D_801109D0] = D_801109CC;
            D_801109D0++;
          } else {
            D_801109B0[D_801109D0] = 0xFF;
            D_801109D0++;
          }
        }

        if (D_800CFEA4 == 0xFF) {
          D_800CFEA8 = 4;
        }
      }
    } else {
      D_800CFEE8 = 2;
      return;
    }
  }

  func_8005BBFC(&g_gdl);

  if ((D_800CFEA8 < 5) && (D_800CFEA8 != 3)) {
    displayText_XY_RGBA_2(&g_gdl, &D_80110608, 30, 16, "GAME!NOTES!!!!!!!!!!!!PAGES", 0xFF, 0xFF, 0, 0xFF);
    sprintf(sp4C, "%3d", FUN_001050_cpakFreeBlocks(&superThread, NULL, D_80110584) >> 8);
    D_801109D8 = 30;
    D_801109DC = 254;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "FREE PAGES: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "FREE PAGES: ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 = 200;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);

    for (D_801109CC = 0, D_801109D8 = 60, D_801109DC = 42, D_801109D4 = 1; D_801109CC < 16; D_801109CC++) {
      if (D_80110970[D_801109CC] < 17) {
        bzero(sp68, 21);
        for (D_801109D0 = 0; D_801109D0 < 16; D_801109D0++) {
          if (D_80110770[D_801109CC].game_name[D_801109D0] < 0xF) {
            sp68[D_801109D0] = ' ';
          } else if (D_80110770[D_801109CC].game_name[D_801109D0] >= 0x42) {
            sp68[D_801109D0] = '*';
          } else {
            sp68[D_801109D0] = D_800CFE60[D_80110770[D_801109CC].game_name[D_801109D0]];
          }
        }

        bzero(sp60, 6);
        D_801109D0 = 0;
        sp60[D_801109D0++] = '.';

        if (D_80110770[D_801109CC].ext_name[0] != 0) {
          if (D_80110770[D_801109CC].ext_name[0] < 0xF) {
            sp60[D_801109D0++] = ' ';
          } else if (D_80110770[D_801109CC].ext_name[0] >= 0x42) {
            sp60[D_801109D0++] = '*';
          } else {
            sp60[D_801109D0++] = D_800CFE60[D_80110770[D_801109CC].ext_name[0]];
          }
        } else {
          sp60[D_801109D0++] = ' ';
        }

        if (D_80110770[D_801109CC].ext_name[1] != 0) {
          if (D_80110770[D_801109CC].ext_name[1] < 0xF) {
            sp60[D_801109D0++] = ' ';
          } else if (D_80110770[D_801109CC].ext_name[1] >= 0x42) {
            sp60[D_801109D0++] = '*';
          } else {
            sp60[D_801109D0++] = D_800CFE60[D_80110770[D_801109CC].ext_name[1]];
          }
        } else {
          sp60[D_801109D0++] = ' ';
        }

        if (D_80110770[D_801109CC].ext_name[2] != 0) {
          if (D_80110770[D_801109CC].ext_name[2] < 0xF) {
            sp60[D_801109D0++] = ' ';
          } else if (D_80110770[D_801109CC].ext_name[2] >= 0x42) {
            sp60[D_801109D0++] = '*';
          } else {
            sp60[D_801109D0++] = D_800CFE60[D_80110770[D_801109CC].ext_name[2]];
          }
        } else {
          sp60[D_801109D0++] = ' ';
        }

        if (D_80110770[D_801109CC].ext_name[3] != 0) {
          if (D_80110770[D_801109CC].ext_name[3] < 0xF) {
            sp60[D_801109D0++] = ' ';
          } else if (D_80110770[D_801109CC].ext_name[3] >= 0x42) {
            sp60[D_801109D0++] = '*';
          } else {
            sp60[D_801109D0++] = D_800CFE60[D_80110770[D_801109CC].ext_name[3]];
          }
        } else {
          sp60[D_801109D0++] = ' ';
        }

        sp60[5] = '\0';

        sprintf(sp5C, "%2d", D_801109D4++);
        sprintf(sp54, "%3d", D_80110770[D_801109CC].file_size >> 8);

        if (D_801109CC == D_800CFEA4) {
          displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8 - 25, D_801109DC, sp5C, 255 * D_800CFEC0, 255 * D_800CFEC8, 255 * D_800CFEB8, 255 * D_800CFEB8);
          displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8 + 240, D_801109DC, sp54, 255 * D_800CFEC0, 255 * D_800CFEC8, 255 * D_800CFEB8, 255 * D_800CFEB8);
          displayText_XY_RGBA_1(&g_gdl, &D_801106F8, D_801109D8, D_801109DC, sp68, 255 * D_800CFEC0, 255 * D_800CFEC8, 255 * D_800CFEB8, 255 * D_800CFEB8);
          displayText_XY_RGBA_1(&g_gdl, &D_801106F8, D_801109D8 + 180, D_801109DC, sp60, 255 * D_800CFEC0, 255 * D_800CFEC8, 255 * D_800CFEB8, 255.0f * D_800CFEB8);
        } else {
          displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8 - 30, D_801109DC, sp5C, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8 + 240, D_801109DC, sp54, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_1(&g_gdl, &D_801106F8, D_801109D8, D_801109DC, sp68, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_1(&g_gdl, &D_801106F8, D_801109D8 + 180, D_801109DC, sp60, 0xFF, 0xFF, 0xFF, 0xFF);
        }

        D_801109DC += 13;
      }
    }
  }

  switch (D_800CFEA8) {
  case 0:
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO DELETE    ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO DELETE    ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO EXIT ", 0xFF, 0xFF, 0, 0xFF);
    if (g_PV_arr[D_80110584].unk24 & 0x400) {  // D_JPAD / CONT_DOWN
      FUN_010870_8004acb0_fifteenliner_2();
    }
    if (g_PV_arr[D_80110584].unk24 & 0x800) {  // U_JPAD / CONT_UP
      FUN_010870_8004abe8_fifteenliner_1();
    }
    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 1;
    }
    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
    }
    break;
  case 1:
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO CONFIRM   ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO CONFIRM   ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO CANCEL ", 0xFF, 0xFF, 0, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - ((((D_801109C0[0] << 8) | D_801109C0[1]) & 0xFFFF) >> 1);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_801109C0, NULL, D_801109E0, 70, 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "WARNING") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 80, "WARNING", 0xFF, 0, 0, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "YOU ARE ABOUT TO DELETE") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 110, "YOU ARE ABOUT TO DELETE", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "THIS FILE PERMANENTLY") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 125, "THIS FILE PERMANENTLY", 0xFF, 0xFF, 0xFF, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 0;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_801109C4 = FUN_001050_cpakDeleteFile(&superThread, &D_80110770[D_801109B0[D_800CFEA4]], D_80110584);
      if ((D_801109C4 & 0xF) == 0xF) {
        D_800CFEAC = 0;
        D_800CFEA8 = 2;
      } else {
        D_80110580--;
        D_80110970[D_801109B0[D_800CFEA4]] = 0x5F;  // 95
        D_801109B0[D_800CFEA4] = 0xFF;
        D_800CFEA8 = 0;
        FUN_010870_8004acb0_fifteenliner_2();
      }
    }
    break;
  case 2:
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO CONTINUE ");
    D_801109E0 = (screen_1_width >> 1) - ((((D_801109C0[0] << 8) | D_801109C0[1]) & 0xFFFF) >> 1);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_801109C0, NULL, D_801109E0, 70, 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "ERROR") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 80, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "PLEASE REINSERT THE") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 110, "PLEASE REINSERT THE", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "ORIGINAL CONTROLLER PAK") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 125, "ORIGINAL CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109E0 = (screen_1_width >> 1) - (get_text_width(&D_80110680, "AND TRY AGAIN") >> 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109E0, 140, "AND TRY AGAIN", 0xFF, 0xFF, 0xFF, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = D_800CFEAC;
    }
    break;
  case 3:
    if (((FUN_001050_cpakNumFiles(&superThread, D_80110584) & 0xFF) >= 16) || (FUN_001050_cpakFreeBlocks(&superThread, NULL, D_80110584) < 256)) {
      D_800CFEB0 = TRUE;
      if (D_80110580 == 16) {
        D_800CFEA8 = 12;
      } else {
        D_800CFEA8 = 12;
      }
      func_8005BE40(&g_gdl);
      return;
    }

    if (D_800CFE5C != 0) {
      D_800CFE54 = 1;
      D_800CFEE8 = 15;
    } else {
      D_800CFED4 = 1;
      D_800CFEE8 = 2;
      D_800CFE54 = 5;
    }

    func_8005BE40(&g_gdl);
    main_8004A34C_threeliner();
    Font_Deinit(&D_801106F8);
    Font_Deinit(&D_80110680);
    Font_Deinit(&D_80110608);
    Font_Deinit(&D_80110590);
    n64HeapUnalloc(D_801109C0);
    D_800CFE50 = 0;
    D_800CFEB4 = TRUE;
    return;
  case 4:
    func_8005BBFC(&g_gdl);
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 268, "TO EXIT ", 0xFF, 0xFF, 0, 0xFF);

    if (g_PV_arr[D_80110584].unk24 & 0x4000) {
      D_800CFEA8 = 3;
    }

    func_8005BE40(&g_gdl);
    osWritebackDCacheAll();
    break;
  case 5:
    D_801109DC = 80;
    D_801109D8 = 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "CORRUPTED CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "IN CONTROLLER:", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER:  ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "WOULD YOU LIKE TO REINITIALIZE", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "THE CONTROLLER PAK?", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, 30, D_801109DC, "SAVED DATA MAY BE LOST", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 30;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO REPAIR ", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_801109C4 = FUN_001050_cpakRepairId(&superThread, NULL, D_80110584);
      if (!(D_801109C4 & 0xF)) {
        D_800CFEA8 = 6;
      } else {
        D_800CFEAC = 5;
        switch ((D_801109C4 >> 4) & 0xF) {
        case 1:
          D_800CFEA8 = 7;
          break;
        case 2:
          D_800CFEA8 = 8;
          break;
        case 4:
          D_800CFEA8 = 9;
          break;
        case 10:
          D_800CFEA8 = 10;
          break;
        case 11:
          D_800CFEA8 = 11;
          break;
        default:
          D_800CFEA8 = 6;
          break;
        }
      }
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }
    break;
  case 6:
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 80, "CONTROLLER PAK SUCCESSFULLY", 0xFF, 0xFF, 0xFF, 0xFF);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 110, "REPAIRED ", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "REPAIRED ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, 110, "PRESS START", 0xFF, 0, 0, 0xFF);

    if (g_PV_arr[D_80110584].unk24 & 0x1000) {
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFE24 = 1;
      D_800CFEB4 = TRUE;
      D_800CFE54 = 4;
      return;
    }
    break;
  case 7:
    D_801109D8 = 25;
    D_801109DC = 80;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "NO CONTROLLER PAK DETECTED", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 25;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO TRY AGAIN ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO TRY AGAIN ");
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 5;
    }
    break;
  case 8:
    D_801109D8 = 25;
    D_801109DC = 80;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "NEW CONTROLLER PAK INSERTED", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 25;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO TRY AGAIN ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO TRY AGAIN ");
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 5;
    }
    break;
  case 9:
    D_801109D8 = 25;
    D_801109DC = 80;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "CONTROLLER PAK NOT RESPONDING", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PLEASE CHECK ALL CONNECTIONS", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 25;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO TRY AGAIN ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO TRY AGAIN ");
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 5;
    }
    break;
  case 10:
    D_801109D8 = 25;
    D_801109DC = 80;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "CONTROLLER PAK DAMAGED", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 25;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO TRY AGAIN ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO TRY AGAIN ");
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 5;
    }
    break;
  case 11:
    D_801109D8 = 25;
    D_801109DC = 80;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "ERROR", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "THIS IS NOT A CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 25;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO TRY AGAIN ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "TO TRY AGAIN ");
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 25;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 3;
      if (D_800CFE5C != 0) {
        D_800CFE54 = 1;
        D_800CFEE8 = 15;
      } else {
        D_800CFED4 = 1;
        D_800CFEE8 = 2;
        D_800CFE54 = 5;
      }

      func_8005BE40(&g_gdl);
      main_8004A34C_threeliner();
      Font_Deinit(&D_801106F8);
      Font_Deinit(&D_80110680);
      Font_Deinit(&D_80110608);
      Font_Deinit(&D_80110590);
      n64HeapUnalloc(D_801109C0);
      D_800CFE50 = 0;
      D_800CFEB4 = TRUE;
      return;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA8 = 5;
    }
    break;
  case 12:
    /*
    D_801109D8 = 30;
    D_801109DC = 80;
    */
    D_801109DC = 80;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "WARNING", 0xFF, 0, 0, 0xFF);
    D_801109DC += 20;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "THERE ARE NOT ENOUGH NOTES OR", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "PAGES REMAINING TO SAVE A NEW", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "NAME TO THE CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, "IN CONTROLLER: ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110680, "IN CONTROLLER: ");
    sprintf(sp4C, "%1d", D_80110584 + 1);
    displayText_XY_RGBA_2(&g_gdl, &D_80110680, D_801109D8, D_801109DC, sp4C, 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 20;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "A ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "TO EDIT CONTROLLER PAK DATA", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "PRESS ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "B ", 0x70, 0xC3, 0x74, 0xFF);
    D_801109D8 += get_text_width(&D_80110590, "B ");
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);
    D_801109DC += 15;
    D_801109D8 = 30;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "THE GAME REQUIRES 1 NOTE AND 1 PAGE", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;
    displayText_XY_RGBA_2(&g_gdl, &D_80110590, D_801109D8, D_801109DC, "TO SAVE A NEW NAME TO THE CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
    D_801109DC += 15;

    if ((g_PV_arr[D_80110584].unk24 & 0x8000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      D_800CFEA4 = 0xFF;

      for (D_801109CC = 0, D_801109D0 = 0; D_801109CC < 16; D_801109CC++) {
        D_80110970[D_801109CC] = FUN_001050_cpakFileState(&superThread, &D_80110770[D_801109CC], D_801109CC, D_80110584);
        if (D_80110970[D_801109CC] < 17) {
          if (D_800CFEA4 == 0xFF) {
            D_800CFEA4 = D_801109CC;
          }
          D_801109B0[D_801109D0] = D_801109CC;
          D_801109D0++;
        } else {
          D_801109B0[D_801109D0]= 0xFF;
          D_801109D0++;
        }
      }

      D_800CFEA8 = 0;
      D_800CFEB0 = FALSE;
    }

    if ((g_PV_arr[D_80110584].unk24 & 0x4000) && !(g_PV_arr[D_80110584].unk24 & 0x1000)) {
      if (D_800CFEB0) {
        if (D_800CFE5C != 0) {
          D_800CFEE8 = 15;
          D_800CFE54 = 1;
        } else {
          D_800CFE54 = 5;
        }

        func_8005BE40(&g_gdl);
        main_8004A34C_threeliner();
        Font_Deinit(&D_801106F8);
        Font_Deinit(&D_80110680);
        Font_Deinit(&D_80110608);
        Font_Deinit(&D_80110590);
        n64HeapUnalloc(D_801109C0);
        D_800CFE50 = 0;
        D_800CFEB4 = TRUE;
        D_800CFEB0 = FALSE;
        return;
      }

      D_800CFEA8 = 3;
    }
    break;
  default:
    D_800CFEA8 = 3;
    D_800CFE50 = 0;
    break;
  }

  func_8005BE40(&g_gdl);
}
