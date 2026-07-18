#include "common.h"

//static u8 D_801109B0[16];
extern u8 D_801109B0[16];

//static s8 D_800CFEA4 = 0xFF;
extern s32 D_800CFEA4;

//static s32 D_800CFEA8 = 0;
extern s32 D_800CFEA8;

static void FUN_010870_8004abe8_fifteenliner_1(void);
static void FUN_010870_8004acb0_fifteenliner_2(void);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/010870/FUN_010870_interesting_stuff_large_liner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/010870/FUN_010870_8004abe8_fifteenliner_1.s")
/*
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
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/010870/FUN_010870_8004acb0_fifteenliner_2.s")
/*
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
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/010870/FUN_010870_OptionsDataMenu.s")
