#include "common.h"

/*
  The functions in this file are handwritten assembly.
  The best we can do is to provide functionally equivalent versions in c,
  being highly unlikely to match the handwritten assembly.
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/06F220/func_800A8FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/06F220/func_800A8FC8.s")
/*
s16 *func_800A8FC8(s16 *arg0, s32 arg1, s32 arg2) {
  for (*arg0 = arg2; arg1 != 0; arg1--) {
    *arg0++ = arg2;
  }
  return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/06F220/func_800A8FE8.s")
