#include "common.h"

void FUN_01D300_80057080_nevercalled(ImgParams *imgParams) {
  imgParams->img = NULL;
  imgParams->x = 0;
  imgParams->y = 0;
  imgParams->red = 0xFF, imgParams->green = 0xFF, imgParams->blue = 0xFF, imgParams->alpha = 0xFF;
}

void FUN_01D300_800570b0_fiveliner(ImgParams *imgParams, u32 arg1) {
  main_8004A34C_threeliner();
  imgParams->img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg1));
  FUN_03A750_800746c0_twentyliner(&D_273A00, imgParams->img, arg1);
}

void FUN_01D300_n64HeapUnalloc(ImgParams *imgParams) {
  n64HeapUnalloc(imgParams->img);
}

void FUN_01D300_80057140_sixliner(ImgParams *imgParams) {
  gDPPipeSync(g_gdl++);

  weird_lots_of_magic_number_setting_66xrefs(&g_gdl, imgParams->img, NULL, imgParams->x, imgParams->y, imgParams->red, imgParams->green, imgParams->blue, imgParams->alpha);
}

void FUN_01D300_800571d4_twentyliner(ImgPalParams *imgPalParams, u32 arg1, u32 arg2) {
  register u32 temp_s0;
  register u32 temp_s1;

  main_8004A34C_threeliner();
  temp_s0 = FUN_03A750_80074888_twelveliner(&D_273A00, arg1);
  temp_s1 = FUN_03A750_80074888_twelveliner(&D_273A00, arg2);
  imgPalParams->img = n64HeapAlloc(temp_s0);
  FUN_03A750_800746c0_twentyliner(&D_273A00, imgPalParams->img, arg1);
  imgPalParams->pal = n64HeapAlloc(temp_s1);
  FUN_03A750_800746c0_twentyliner(&D_273A00, imgPalParams->pal, arg2);
  imgPalParams->x = 0;
  imgPalParams->y = 0;
  imgPalParams->unkC = 0x400;
  imgPalParams->unkE = 0x400;
  imgPalParams->red = imgPalParams->green = imgPalParams->blue = imgPalParams->alpha = 0xFF;
}

void FUN_01D300_800572f8_twoliner(ImgPalParams *imgPalParams) {
  n64HeapUnalloc(imgPalParams->img);
  n64HeapUnalloc(imgPalParams->pal);
}

void FUN_01D300_80057338_fifteenliner(ImgPalParams *imgPalParams) {
  gDPPipeSync(g_gdl++);

  if ((imgPalParams->unkC == 0x400) && (imgPalParams->unkE == 0x400)) {
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, imgPalParams->img, imgPalParams->pal, imgPalParams->x, imgPalParams->y, imgPalParams->red, imgPalParams->green, imgPalParams->blue, imgPalParams->alpha);
    return;
  }

  func_8005DB90(&g_gdl, imgPalParams->img, imgPalParams->pal, imgPalParams->x, imgPalParams->y, imgPalParams->red, imgPalParams->green, imgPalParams->blue, imgPalParams->alpha, imgPalParams->unkC, imgPalParams->unkE);
}
