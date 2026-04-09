#include "common.h"

static u8 *D_8011FAD0;
static u8 *D_8011FAD4;
static s32 D_8011FAD8;
static s32 D_8011FADC;

static u32 D_800D02A0 = 0;

void FUN_0279C0_80061740_switch_0to8_1to6_same(void) {
  switch (D_800D02A0) {
  case 0:
    main_8004A34C_threeliner();
    FUN_026900_80060d58_elevenliner(1);
    D_8011FAD0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_WARNING_NO_CONTROLLER));
    FUN_03A750_800746c0_twentyliner(&D_273A00, D_8011FAD0, IMG_WARNING_NO_CONTROLLER);
    D_8011FAD4 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_WARNING_NO_CONTROLLER_PAL));
    FUN_03A750_800746c0_twentyliner(&D_273A00, D_8011FAD4, IMG_WARNING_NO_CONTROLLER_PAL);
    func_8007CF40(0);
    func_800875EC(0x6000, &D_80120A70);
    func_80061134(400, 300);
    D_800D02A0++;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    D_800D02A0++;
    break;
  case 7:
    FUN_026900_80060d58_elevenliner(0);
    D_800D02A0++;
    break;
  case 8:
    g_gdl = func_8007DA00(g_gdl);
    D_8011FAD8 = (screen_1_width >> 1) - ((u16) ((D_8011FAD0[0] << 8) | D_8011FAD0[1]) >> 1);
    D_8011FADC = (screen_1_height >> 1) - ((u16) ((D_8011FAD0[2] << 8) | D_8011FAD0[3]) >> 1);
    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FAD0, D_8011FAD4, D_8011FAD8, D_8011FADC, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
    break;
  }
}
