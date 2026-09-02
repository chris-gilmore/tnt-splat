#include "common.h"

u16 D_800D9190 = 1;
s32 D_800D9194 = G_IM_FMT_IA;

void SetSpriteMode(u16 mode) {
  if ((mode <= 0) || (mode >= 5)) {
    rmonPrintf("h2olib/sprite/sprite.c : SetSpriteMode: ERROR!  Unknown Mode Number: %d\n", mode);
    rmonPrintf("Mode Not Changed\n");
    return;
  }

  D_800D9190 = mode;

  switch (D_800D9190) {
  case 1:
    D_800D9194 = G_IM_FMT_IA;
    break;
  case 2:
  case 3:
  case 4:
    D_800D9194 = G_IM_FMT_RGBA;
    break;
  default:
    rmonPrintf("Hmm, Error in sprite code.  (SetSpriteMode) Someone didn't add in a new mode properly.\n", mode);
    break;
  }
}

Gfx *GetSpriteMode(u16 mode) {
  Gfx *gdl;

  switch (D_800D9190) {
  case 1:
    gdl = D_800D9310;
    break;
  case 2:
    gdl = D_800D9390;
    break;
  case 3:
    gdl = D_800D9410;
    break;
  case 4:
    gdl = D_800D9490;
    break;
  default:
    rmonPrintf("Hmm, Error in sprite code.  (GetSpriteMode) Someone didn't add in a new mode properly.\n");
    break;
  }

  return gdl;
}

void func_800B1BFC(Gfx **gdl_ptr, s32 arg1, u16 *arg2, u16 arg3, u16 arg4, f32 arg5, f32 arg6, u16 arg7, u16 arg8, u8 red, u8 green, u8 blue, u8 alpha) {
  Gfx *gdl = *gdl_ptr;
  u16 var_t2;
  u16 var_s5;
  u16 xh;
  u16 yh;
  u16 dyh;
  u16 dsdx;
  u16 dtdy;
  u16 spEC;
  u16 spEA;
  u16 spE8;
  u16 sp44;

  spEC = 4096U / (arg3 << 1);
  var_t2 = arg4 / spEC;
  spEA = 0;
  if (var_t2 == 0) {
    var_t2 = 1;
    spEC = arg4;
  } else if ((var_t2 * spEC) != arg4) {
    spEA = arg4 - (var_t2 * spEC);
  }

  xh = arg3 * arg5;
  yh = spEC * arg6;
  dsdx = 1024 / arg5;
  dtdy = 1024 / arg6;

  sp44 = arg3 * spEC;

  gDPPipeSync(gdl++);
  gDPSetPrimColor(gdl++, 0, 0, red, green, blue, alpha);

  for (var_s5 = 0; var_s5 < var_t2; var_s5++) {
    spE8 = var_s5 * yh;

    gDPLoadTextureTile(gdl++, arg2 + (var_s5 * sp44), D_800D9194, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3 - 1, spEC - 1, NULL, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPDisplayList(gdl++, GetSpriteMode(D_800D9190));

    gSPTextureRectangle(gdl++, arg7 << 2, (arg8 + spE8) << 2, ((arg7 + xh) << 2) - 1, ((arg8 + yh + spE8) << 2) - 1, G_TX_RENDERTILE, 0, 0, dsdx, dtdy);
  }

  if (spEA) {
    spE8 += yh;
    dyh = spEA * arg6;

    gDPLoadTextureTile(gdl++, arg2 + (var_s5 * sp44), D_800D9194, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3 - 1, spEA - 1, NULL, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPDisplayList(gdl++, GetSpriteMode(D_800D9190));

    gSPTextureRectangle(gdl++, arg7 << 2, (arg8 + spE8) << 2, ((arg7 + xh) << 2) - 1, ((arg8 + dyh + spE8) << 2) - 1, G_TX_RENDERTILE, 0, 0, dsdx, dtdy);
  }

  *gdl_ptr = gdl;
}

void func_800B2810(Gfx **gdl_ptr, s32 arg1, UnkStruct_44 *arg2, u16 arg3, u16 arg4, f32 arg5, f32 arg6, u16 arg7, u16 arg8, u8 red, u8 green, u8 blue, u8 alpha) {
  Gfx *gdl = *gdl_ptr;
  u16 width = arg3 * arg4 * 2;
  UnkStruct_71 *tmp;
  u16 line = (arg3 << 4) / 64;
  u16 xh = arg3 * arg5;
  u16 yh = arg4 * arg6;
  u16 dsdx = 1024 / arg5;
  u16 dtdy = 1024 / arg6;

  gDPPipeSync(gdl++);
  gDPSetPrimColor(gdl++, 0, 0, red, green, blue, alpha);
  gSPDisplayList(gdl++, GetSpriteMode(D_800D9190));

  tmp = &arg2->unk8;

  gDPSetTextureImage(gdl++, D_800D9194, G_IM_SIZ_16b, width, tmp->unkC);
  gDPSetTile(gdl++, D_800D9194, G_IM_SIZ_16b, line, 0, G_TX_RENDERTILE, NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
  gDPLoadSync(gdl++);
  gDPLoadBlock(gdl++, G_TX_RENDERTILE, 0, 0, width, 0);
  gDPPipeSync(gdl++);
  gDPSetTile(gdl++, D_800D9194, G_IM_SIZ_16b, line, 0, G_TX_RENDERTILE, NULL, G_TX_NOMIRROR | G_TX_WRAP, tmp->unk7, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, tmp->unk7, G_TX_NOLOD);
  gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, arg3 - 1, arg4 - 1);

  gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);

  gSPTextureRectangle(gdl++, arg7 << 2, arg8 << 2, (arg7 + xh) << 2, (arg8 + yh) << 2, G_TX_RENDERTILE, 0, 0, dsdx, dtdy);

  *gdl_ptr = gdl;
}
