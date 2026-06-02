#include "common.h"
#include "synthInternals.h"

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_load/h2oRaw16Pull.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_load/h2oRaw8Pull.s")

s32 h2oLoadParam(void *filter, s32 paramID, void *param) {
  ALLoadFilter *a = filter;
  ALFilter *f = filter;

  switch (paramID) {
  case (AL_FILTER_SET_WAVETABLE):
    a->table = param;
    a->memin = (s32) a->table->base;
    a->sample = 0;
    switch (a->table->type) {
    case (AL_ADPCM_WAVE):
      break;
    case (AL_RAW16_WAVE):
      f->handler = h2oRaw16Pull;
      if (a->table->waveInfo.rawWave.loop) {
        a->loop.start = a->table->waveInfo.rawWave.loop->start;
        a->loop.end = a->table->waveInfo.rawWave.loop->end;
        a->loop.count = a->table->waveInfo.rawWave.loop->count;
      } else {
        a->loop.start = a->loop.end = a->loop.count = 0;
      }
      break;
    case (H2O_RAW8_WAVE):
      f->handler = h2oRaw8Pull;
      if (a->table->waveInfo.rawWave.loop) {
        a->loop.start = a->table->waveInfo.rawWave.loop->start;
        a->loop.end = a->table->waveInfo.rawWave.loop->end;
        a->loop.count = a->table->waveInfo.rawWave.loop->count;
      } else {
        a->loop.start = a->loop.end = a->loop.count = 0;
      }
      break;
    default:
      break;
    }
    break;
  case (AL_FILTER_RESET):
    a->memin = (s32) a->table->base;
    a->lastsam = 0;
    a->first = 1;
    a->sample = 0;
    break;
  default:
    break;
  }
}
