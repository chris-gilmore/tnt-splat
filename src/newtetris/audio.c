#include "common.h"

//#include "synthInternals.h"

extern /* static */ void *D_80128A9C;
extern /* static */ void *D_80128AA0;

//u32 D_800D3910 = 0;
extern u32 D_800D3910;

static void   Audio_Wrap(void);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_InitAudio.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_ChangeSong.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/func_80084C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_FreeAudio.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_80084e20_twentyliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_UnloadSFX.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_LoadSFX.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_80085408_oneliner_calls_allocdcm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_ALManager.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_PreNmiAudio.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_80085924_fortyliner_sets_arg0_struct.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_80085b9c_threeliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/Audio_80085bec_tenliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio/func_80085CF4.s")

static void Audio_Wrap(void) {
  D_800D3910++;
  if (D_800D3910 == 0) {
    rmonPrintf("audio wrap\n");
  }
  D_80128A9C = D_80128AA0;
}
