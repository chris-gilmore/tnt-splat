#include "common.h"

static Gfx D_800D0610[] = {
  gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
  gsDPPipeSync(),
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsDPSetTextureLUT(G_TT_NONE),
  gsDPSetAlphaCompare(G_AC_NONE),
  gsDPSetTexturePersp(G_TP_NONE),
  gsDPSetTextureFilter(G_TF_AVERAGE),
  gsDPSetTextureConvert(G_TC_FILT),
  gsDPSetTextureDetail(G_TD_CLAMP),
  gsDPSetTextureLOD(G_TL_TILE),
  gsDPSetCombineMode(_G_CC_BLENDPEDECALA, _G_CC_BLENDPEDECALA),
  gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
  gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
  gsDPSetEnvColor(0xFF, 0xFF, 0x00, 0xFF),
  gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
  gsSPEndDisplayList(),
};

/* static */ void func_800749A0(UnkStruct_33 *, u8, u8);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_800749A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80074F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80075180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_800751C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80075218.s")

u8 func_8007523C(UnkStruct_30 *arg0, UnkStruct_31 *arg1) {
  register s32 i;
  register UnkStruct_33 *var_s1;

  arg1->unk0.unk1 += 3;
  arg0->unk14 = arg1->unk0;
  arg0->unk16 = arg0->unk14.unk0 * arg0->unk14.unk1;
  arg0->unk18 = arg0->unk16;
  if (arg0->unk18 >= 0x1000) {
    return FALSE;
  }

  arg0->unkC = (u8 *)n64HeapAlloc(arg0->unk18);
  arg0->unk10 = (u8 *)n64HeapAlloc(arg0->unk18);
  bzero(arg0->unkC, arg0->unk18);
  bzero(arg0->unk10, arg0->unk18);
  arg0->unk4 = arg1->unk6;
  arg0->unk8 = (UnkStruct_33 *)n64HeapAlloc(arg0->unk4 * sizeof(UnkStruct_33));
  var_s1 = arg0->unk8;
  for (i = arg0->unk4; i > 0; i--) {
    func_800749A0(var_s1, arg0->unk14.unk0, arg0->unk14.unk1);
    var_s1++;
  }
  func_80075218(arg0, arg1->unk2, arg1->unk4);
  return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/03AC20/func_80075400.s")
