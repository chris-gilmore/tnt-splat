#include "common.h"

static s32 D_800D0160 = 0x800;
static s16 D_800D0164 = 0;  // saved_type
static u8 D_800D0168 = 0;   // saved_red
static u8 D_800D016C = 0;   // saved_green
static u8 D_800D0170 = 0;   // saved_blue
static u8 D_800D0174 = 0;   // saved_alpha

void weird_lots_of_magic_number_setting_66xrefs(Gfx **gdl_ptr, void *img, void *pal, s32 x, s32 y, s32 red, s32 green, s32 blue, s32 alpha) {
  s32 sp164;
  s32 sp160;
  s32 width;
  s32 height;
  s32 type;

  if ((img == NULL) || (alpha == 0)) {
    return;
  }

  width  = ((u16 *) img)[0];
  height = ((u16 *) img)[1];
  type   = ((u16 *) img)[2];

  if ((width > 0) && (height > 0)) {
    if (D_800D0164 != type) {
      switch (type) {
      case 0:  // G_IM_FMT_RGBA, G_IM_SIZ_16b
        D_800D0160 = 0x800;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 2:  // G_IM_FMT_IA, G_IM_SIZ_8b
        D_800D0160 = 0x800;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 1:  // G_IM_FMT_I, G_IM_SIZ_4b
        D_800D0160 = 0x1000;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 3:  // G_IM_FMT_CI, G_IM_SIZ_8b
        D_800D0160 = 0x800;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_RGBA16);
        gDPLoadTLUT_pal256((*gdl_ptr)++, pal);
        break;
      default:
        return;
      }
    } else if (type == 3) {
      gDPLoadTLUT_pal256((*gdl_ptr)++, pal);
    }

    sp164 = D_800D0160 / ((width + 3) & 0xFFFC);

    if (sp164 > 0) {
      if ((D_800D0168 != red) || (D_800D016C != green) || (D_800D0170 != blue) || (D_800D0174 != alpha) || (D_800D0164 != type)) {
        if ((alpha == 0xFF) && (red == 0xFF) && (green == 0xFF) && (blue == 0xFF)) {
          gDPSetCombineMode((*gdl_ptr)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        } else {
          if (((D_800D0168 == 0xFF) && (D_800D016C == 0xFF) && (D_800D0170 == 0xFF) && (D_800D0174 == 0xFF)) || (D_800D0164 != type)) {
            gDPSetCombineMode((*gdl_ptr)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
          }

          gDPSetPrimColor((*gdl_ptr)++, 0, 0, red, green, blue, alpha);
        }

        D_800D0168 = red;
        D_800D016C = green;
        D_800D0170 = blue;
        D_800D0174 = alpha;
      }

      D_800D0164 = type;

      for (sp160 = height; sp160 != 0; ) {
        if (sp160 > sp164) {
          switch (type) {
          case 0:  // G_IM_FMT_RGBA, G_IM_SIZ_16b
            // uls = 0
            // ult = height - sp160
            // lrs = width - 1
            // lrt = (height - sp160) + sp164 - 1
            // cms = G_TX_NOMIRROR | G_TX_CLAMP
            // cmt = G_TX_NOMIRROR | G_TX_CLAMP
            // masks = G_TX_NOMASK
            // maskt = G_TX_NOMASK
            // shifts = G_TX_NOLOD
            // shiftt = G_TX_NOLOD
            // gDPLoadTextureTile(pkt, timg, fmt, siz, width, height, uls, ult, lrs, lrt, pal, cms, cmt, masks, maskt, shifts, shiftt);

            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, height - sp160, width - 1, (height - sp160) + sp164 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 1:  // G_IM_FMT_I, G_IM_SIZ_4b
            // gDPLoadTextureTile_4b(pkt, timg, fmt, width, height, uls, ult, lrs, lrt, pal, cms, cmt, masks, maskt, shifts, shiftt);

            gDPLoadTextureTile_4b((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_I, width, height, 0, height - sp160, width - 1, (height - sp160) + sp164 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 2:  // G_IM_FMT_IA, G_IM_SIZ_8b
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0, height - sp160, width - 1, (height - sp160) + sp164 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 3:  // G_IM_FMT_CI, G_IM_SIZ_8b
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, 0, height - sp160, width - 1, (height - sp160) + sp164 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          }

          gDPSetTileSize((*gdl_ptr)++, G_TX_RENDERTILE, 0, 0, (width << 2) - 1, (sp164 << 2) - 1);
          gSPTextureRectangle((*gdl_ptr)++, x << 2, (y + height - sp160) << 2, ((x + width) << 2) - 1, (((y + height - sp160) + sp164) << 2) - 1, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);

          sp160 -= sp164;
        } else {
          switch (type) {
          case 0:  // G_IM_FMT_RGBA, G_IM_SIZ_16b
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, height - sp160, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 1:  // G_IM_FMT_I, G_IM_SIZ_4b
            gDPLoadTextureTile_4b((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_I, width, height, 0, height - sp160, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 2:  // G_IM_FMT_IA, G_IM_SIZ_8b
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0, height - sp160, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 3:  // G_IM_FMT_CI, G_IM_SIZ_8b
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, 0, height - sp160, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          }

          gDPSetTileSize((*gdl_ptr)++, G_TX_RENDERTILE, 0, 0, (width << 2) - 1, (sp160 << 2) - 1);
          gSPTextureRectangle((*gdl_ptr)++, x << 2, (y + height - sp160) << 2, ((x + width) << 2) - 1, ((y + height) << 2) - 1, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);

          sp160 = 0;
        }
      }

      gDPPipeSync((*gdl_ptr)++);
    }
  }
}

void display_one_text_character_rgb(Gfx **gdl_ptr, void *img, s32 sl, s32 tl, s32 sh, s32 th, s32 x, s32 y, s32 red, s32 green, s32 blue, s32 alpha) {
  s32 sp134;
  s32 sp130;
  s32 width;
  s32 height;
  s32 type;

  if ((img == NULL) || (alpha == 0)) {
    return;
  }

  width  = ((u16 *) img)[0];
  height = ((u16 *) img)[1];
  type   = ((u16 *) img)[2];

  if ((width > 0) && (height > 0) && (sh >= sl) && (th >= tl)) {
    if (D_800D0164 != type) {
      switch (type) {
      case 0:
        D_800D0160 = 0x800;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 2:
        D_800D0160 = 0x800;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 1:
        D_800D0160 = 0x1000;
        gDPSetTextureLUT((*gdl_ptr)++, G_TT_NONE);
        break;
      case 3:
        D_800D0160 = 0x800;
        break;
      default:
        return;
      }
    }

    sp134 = D_800D0160 / ((((sh - sl) + 1) + 3) & 0xFFFC);

    if (sp134 > 0) {
      if ((D_800D0168 != red) || (D_800D016C != green) || (D_800D0170 != blue) || (D_800D0174 != alpha) || (D_800D0164 != type)) {
        if ((alpha == 0xFF) && (red == 0xFF) && (green == 0xFF) && (blue == 0xFF)) {
          gDPSetCombineMode((*gdl_ptr)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        } else {
          if (((D_800D0168 == 0xFF) && (D_800D016C == 0xFF) && (D_800D0170 == 0xFF) && (D_800D0174 == 0xFF)) || (D_800D0164 != type)) {
            gDPSetCombineMode((*gdl_ptr)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
          }

          gDPSetPrimColor((*gdl_ptr)++, 0, 0, red, green, blue, alpha);
        }

        D_800D0168 = red;
        D_800D016C = green;
        D_800D0170 = blue;
        D_800D0174 = alpha;
      }

      D_800D0164 = type;

      for (sp130 = (th - tl) + 1; sp130 != 0; ) {
        if (sp130 > sp134) {
          switch (type) {
          case 0:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, sl, th - sp130 + 1, sh, th - sp130 + sp134, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 1:
            gDPLoadTextureTile_4b((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_I, width, height, sl, th - sp130 + 1, sh, th - sp130 + sp134, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 2:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, sl, th - sp130 + 1, sh, th - sp130 + sp134, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 3:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, sl, th - sp130 + 1, sh, th - sp130 + sp134, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          }
          gDPSetTileSize((*gdl_ptr)++, G_TX_RENDERTILE, 0, 0, ((sh - sl + 1) << 2) - 1, (sp134 << 2) - 1);
          gSPTextureRectangle((*gdl_ptr)++, x << 2, (y << 2) + 3, ((x + sh - sl) << 2) + 3, ((y + sp134) << 2) - 1, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);

          sp130 -= sp134;
          y += sp134;
          tl += sp134;  // this is unnecessary since tl is not used inside the loop
        } else {
          switch (type) {
          case 0:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, sl, th - sp130 + 1, sh, th, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 1:
            gDPLoadTextureTile_4b((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_I, width, height, sl, th - sp130 + 1, sh, th, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 2:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, sl, th - sp130 + 1, sh, th, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          case 3:
            gDPLoadTextureTile((*gdl_ptr)++, (u32)img + 8, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, sl, th - sp130 + 1, sh, th, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
          }
          gDPSetTileSize((*gdl_ptr)++, G_TX_RENDERTILE, 0, 0, ((sh - sl) << 2) + 3, (sp130 << 2) - 1);
          gSPTextureRectangle((*gdl_ptr)++, x << 2, y << 2, ((x + sh - sl) << 2) + 3, ((y + sp130) << 2) - 1, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);

          sp130 = 0;
        }
      }

      gDPPipeSync((*gdl_ptr)++);
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/01D6E0/FUN_8005aa9c_prob_display_text_rgb_as_well.s")

void func_8005BBFC(Gfx **gdl_ptr) {
  gDPPipeSync((*gdl_ptr)++);
  gDPSetCycleType((*gdl_ptr)++, G_CYC_1CYCLE);
  gSPTexture((*gdl_ptr)++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
  gDPSetAlphaCompare((*gdl_ptr)++, G_AC_THRESHOLD);
  gDPSetTexturePersp((*gdl_ptr)++, G_TP_NONE);
  gDPSetTextureFilter((*gdl_ptr)++, G_TF_AVERAGE);
  gDPSetTextureConvert((*gdl_ptr)++, G_TC_FILT);
  gDPSetTextureDetail((*gdl_ptr)++, G_TD_CLAMP);
  gDPSetTextureLOD((*gdl_ptr)++, G_TL_TILE);
  gSPClearGeometryMode((*gdl_ptr)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
  gDPSetRenderMode((*gdl_ptr)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

  D_800D0164 = -1;
}

void func_8005BE40(Gfx **gdl_ptr) {
  gDPPipeSync((*gdl_ptr)++);
  gDPSetCombineMode((*gdl_ptr)++, G_CC_SHADE, G_CC_SHADE);
  gDPSetTexturePersp((*gdl_ptr)++, G_TP_PERSP);
}

// unused
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/01D6E0/func_8005BEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/01D6E0/func_8005DB90.s")
