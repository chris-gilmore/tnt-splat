#include "common.h"

/*
  The functions in this file are handwritten assembly.
  The best we can do is to provide functionally equivalent versions in c,
  being highly unlikely to match the handwritten assembly.
*/

/*
  cvt.w.s    $ft0, $fa0
  mfc1       $v0, $ft0
  jr         $ra
   nop
*/

/*
  cvt.w.s converts float to integer
  rounding mode on the N64 uses FPCSR_RM_RN (round to nearest)
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069170/func_800A2EF0.s")
/*
s32 func_800A2EF0(f32 arg0) {
  return lroundf(arg0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/069170/func_800A2F00.s")
