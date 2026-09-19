#include "common.h"
#include "synthInternals.h"

Acmd *h2oRaw16Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
  Acmd *ptr = p;
  s32 nbytes;
  s32 dramLoc;
  s32 dramAlign;
  s32 dmemAlign;
  s32 overFlow;
  s32 startZero;
  s32 nSam;
  s32 op;

  ALLoadFilter *f = filter;
  ALFilter *a = filter;

  if ((filter == NULL) || (outp == NULL) || (outCount == 0) || (p == NULL)) {
    return ptr;
  }

  if (outCount == 0) {
    return ptr;
  }

  if ((outCount + f->sample > f->loop.end) && (f->loop.count != 0)) {
    nSam = f->loop.end - f->sample;
    nbytes = nSam << 1;
    if (nSam > 0) {
      dramLoc = (s32) OS_PHYSICAL_TO_K0(f->memin);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;
      aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else {
      dramAlign = 0;
    }

    *outp += dramAlign;

    f->memin = (s32) f->table->base + (f->loop.start << 1);
    f->sample = f->loop.start;
    op = *outp;

    while (outCount > nSam) {
      op += nSam << 1;
      outCount -= nSam;

      if ((f->loop.count != -1) && (f->loop.count != 0)) {
        f->loop.count--;
      }

      nSam = (outCount < f->loop.end - f->loop.start) ? outCount : f->loop.end - f->loop.start;
      nbytes = nSam << 1;

      dramLoc = (s32) OS_PHYSICAL_TO_K0(f->memin);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;

      if (op & 0x7) {
        dmemAlign = 8 - (op & 0x7);
      } else {
        dmemAlign = 0;
      }

      aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);

      if ((dramAlign != 0) || (dmemAlign != 0)) {
        aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
      }
    }

    f->sample += outCount;
    f->memin += outCount << 1;

    return ptr;
  }

  nbytes = outCount << 1;
  overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
  if (overFlow < 0) {
    overFlow = 0;
  }
  if (overFlow > nbytes) {
    overFlow = nbytes;
  }

  if (overFlow < nbytes) {
    if (outCount > 0) {
      nbytes -= overFlow;
      dramLoc = (s32) OS_PHYSICAL_TO_K0(f->memin);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;
      aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else {
      dramAlign = 0;
    }
    *outp += dramAlign;

    f->sample += outCount;
    f->memin += outCount << 1;
  } else {
    f->memin += outCount << 1;
  }

  if (overFlow != 0) {
    startZero = (outCount << 1) - overFlow;
    if (startZero < 0) {
      startZero = 0;
    }
    aClearBuffer(ptr++, startZero + *outp, overFlow);
  }

  return ptr;
}

Acmd *h2oRaw8Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
  Acmd *ptr = p;
  s32 nbytes;
  s32 dramLoc;
  s32 dramAlign;
  s32 dmemAlign;
  s32 overFlow;
  s32 startZero;
  s32 nSam;
  s32 op;

  s32 unused[2];

  ALLoadFilter *f = filter;
  ALFilter *a = filter;

  if (outCount == 0) {
    return ptr;
  }

  if ((filter == NULL) || (outp == NULL) || (outCount == 0) || (p == NULL)) {
    return ptr;
  }

  if ((outCount + f->sample > f->loop.end) && (f->loop.count != 0)) {
    nSam = f->loop.end - f->sample;
    nbytes = nSam << 1;
    if (nSam > 0) {
      dramLoc = f->dma(f->memin, nbytes >> 1, f->dmaState);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;
      aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else {
      dramAlign = 0;
    }

    *outp += dramAlign;

    f->memin = (s32) f->table->base + f->loop.start;
    f->sample = f->loop.start;
    op = *outp;

    while (outCount > nSam) {
      op += nSam << 1;
      outCount -= nSam;

      if ((f->loop.count != -1) && (f->loop.count != 0)) {
        f->loop.count--;
      }

      nSam = (outCount < f->loop.end - f->loop.start) ? outCount : f->loop.end - f->loop.start;
      nbytes = nSam << 1;

      dramLoc = f->dma(f->memin, nbytes >> 1, f->dmaState);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;

      if (op & 0x7) {
        dmemAlign = 8 - (op & 0x7);
      } else {
        dmemAlign = 0;
      }

      aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);

      if ((dramAlign != 0) || (dmemAlign != 0)) {
        aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
      }
    }

    f->sample += outCount;
    f->memin += outCount;

    return ptr;
  }

  nbytes = outCount << 1;
  overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
  if (overFlow < 0) {
    overFlow = 0;
  }
  if (overFlow > nbytes) {
    overFlow = nbytes;
  }

  if (overFlow < nbytes) {
    if (outCount > 0) {
      nbytes -= overFlow;
      dramLoc = f->dma(f->memin, nbytes >> 1, f->dmaState);

      dramAlign = dramLoc & 0x7;
      nbytes += dramAlign;
      aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
      aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else {
      dramAlign = 0;
    }
    *outp += dramAlign;

    f->sample += outCount;
    f->memin += outCount;
  } else {
    f->memin += outCount;
  }

  if (overFlow != 0) {
    startZero = (outCount << 1) - overFlow;
    if (startZero < 0) {
      startZero = 0;
    }
    aClearBuffer(ptr++, startZero + *outp, overFlow);
  }

  return ptr;
}

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
