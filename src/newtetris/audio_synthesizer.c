#include "common.h"
#include "synthInternals.h"

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/alSynNew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/alAudioFrame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/__allocParam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/__freeParam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/_collectPVoices.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/_freePVoice.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/_timeToSamples.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/_samplesToTime.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_synthesizer/__nextSampleTime.s")
