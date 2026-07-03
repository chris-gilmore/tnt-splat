#include "common.h"

static void *D_80120210;
static void *D_80120214;
static s32 D_80120218;

static u32 D_800D32C0[] = { IMG_BPS_AND_H2O_LOGO };
static u32 D_800D32C4[] = { IMG_BPS_AND_H2O_LOGO_PAL };
static u32 D_800D32C8 = 0;
static s32 D_800D32CC = 0;

void func_80080B50(void) {
  if ((D_800D32C8 == 1) || (D_800D32C8 == 2) || (D_800D32C8 == 3)) {
    func_8005BBFC(&g_gdl);
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80120210, D_80120214, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
  }

  switch (D_800D32C8) {
  case 0:
    main_8004A34C_threeliner();
    D_80120210 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, D_800D32C0[D_800D32CC]));
    FUN_03A750_800746c0_twentyliner(&D_273A00, D_80120210, D_800D32C0[D_800D32CC]);

    if (D_800D32C4[D_800D32CC] != 0) {
      D_80120214 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, D_800D32C4[D_800D32CC]));
      FUN_03A750_800746c0_twentyliner(&D_273A00, D_80120214, D_800D32C4[D_800D32CC]);
    }
    func_8007ECC8(10);
    D_800D32C8 = 1;
    break;
  case 1:
    if (func_8007EA2C() == 1) {
      D_800D32C8 = 2;
      D_80120218 = 300;
    }
    break;
  case 2:
    D_80120218--;
    if ((D_80120218 == 0) || ((g_PV_arr[0].unk24 & 0x8000) && (D_80120218 < 240))) {  // A_BUTTON / CONT_A
      func_8007E9F8(10);
      D_800D32C8 = 3;
    }
    break;
  case 3:
    if (func_8007E750() == 1) {
      main_8004A34C_threeliner();
      n64HeapUnalloc(D_80120214);
      n64HeapUnalloc(D_80120210);

      D_800D32CC++;
      if (D_800D32CC == 1) {
        D_800D32C8 = 4;
        func_8007E750();
      } else {
        D_800D32C8 = 0;
      }
    }
    break;
  case 4:
    D_800CFD48 = 1;
    D_800CFEE8 = 3;
    break;
  }

  func_800722E0();
}
