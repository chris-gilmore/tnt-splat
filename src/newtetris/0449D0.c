#include "common.h"

extern f32 D_801201E0;
extern f32 D_801201E4;
/*
static f32 D_801201E0;
static f32 D_801201E4;
*/

u8 func_8007E750(void) {
  if (D_801201E4 <= 1.0) {
    gDPPipeSync(g_gdl++);
    gDPSetCycleType(g_gdl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(g_gdl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetRenderMode(g_gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(g_gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(g_gdl++, 0, 0, 0x00, 0x00, 0x00, D_801201E4 * 255);
    gDPFillRectangle(g_gdl++, 0, 0, 400, 300);
    gDPPipeSync(g_gdl++);

    D_801201E4 += D_801201E0 * func_800A3AF0();
    if (D_801201E4 >= 1.0) {
      return TRUE;
    }

    return FALSE;
  }

  return TRUE;
}

void func_8007E9F8(f32 arg0) {
  D_801201E0 = 1.0 / arg0;
  D_801201E4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007EA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007ECC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007ED00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007EFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007EFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007F288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007F2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007F320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007F344.s")

void func_8007FBB0(void **arg0, u32 arg1) {
  main_8004A34C_threeliner();
  *arg0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg1));
  FUN_03A750_800746c0_twentyliner(&D_273A00, *arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007FC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007FC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007FD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007FD74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/0449D0/func_8007FD84.s")
