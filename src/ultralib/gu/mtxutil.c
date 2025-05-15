#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ultralib/gu/mtxutil/guMtxF2L.s")

void guMtxIdentF(f32 mf[4][4]) {
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (i == j) {
        mf[i][j] = 1.0;
      } else {
        mf[i][j] = 0.0;
      }
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/ultralib/gu/mtxutil/guMtxIdent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ultralib/gu/mtxutil/guMtxL2F.s")
