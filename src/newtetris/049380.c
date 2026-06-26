#include "common.h"

// spinning N64 3d logo
static UnkStruct_11 D_800D32E0 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0.0, 0, 995
};
static s32 D_800D3310 = 480;
static s32 D_800D3314 = 0;  // unused
static s32 D_800D3318 = 0;
static s32 D_800D331C = TRUE;
static s32 D_800D3320 = 0;
static s32 D_800D3324 = TRUE;

static void func_80083100(void);
static void func_8008313C(void);

// init
static void func_80083100(void) {
  func_80076EC0(&D_800D32E0, TRUE);  // init
  func_800A4654(D_800D32E0.unk0);
  D_800D3318 = 0;
}

// deinit
static void func_8008313C(void) {
  func_80077028(&D_800D32E0);  // deinit
}

void func_80083160(void) {
  if (D_800D3318 == 0) {
    if (D_800D331C) {
      func_80083100();  // init
      D_800D331C = FALSE;
      func_8007ECC8(100);
      D_800D3324 = TRUE;
      func_8007EA2C();  // fade from black
      D_800D3320 = 0;
      return;
    }

    if (((g_PV_arr->unk24 & 0x8000) || ((s32) D_800D32E0.unk0->unk6 >= D_800D3310)) && (D_800D3320 > 60)) {  // A_BUTTON / CONT_A
      func_8007E9F8(20);
      D_800D331C = TRUE;
      D_800D3318 = 1;
      D_800D3324 = FALSE;
    }

    func_80077098(&D_800D32E0);  // render
    D_800D3320++;
    if (D_800D3324 && (func_8007EA2C() == 1)) {  // fade from black
      D_800D3324 = FALSE;
    }
  }

  if (D_800D3318 == 1) {
    if (D_800D331C) {
      D_800D331C = FALSE;
    } else {
      func_80077098(&D_800D32E0);  // render
    }

    if (func_8007E750() == 1) {  // fade to black
      main_8004A34C_threeliner();
      func_8008313C();  // deinit
      D_800D331C = TRUE;
      D_800CFEE8 = 1;
    }
  }
}
