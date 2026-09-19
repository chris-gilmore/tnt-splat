#include "common.h"
#include "synthInternals.h"

// log_e 2
#define M_LN2 0.69314718055994530942

static s16 eqpower[] = {
  0x7FFF,
  0x7FFC,
  0x7FF5,
  0x7FE8,
  0x7FD7,
  0x7FC0,
  0x7FA5,
  0x7F84,
  0x7F5F,
  0x7F34,
  0x7F05,
  0x7ED0,
  0x7E97,
  0x7E58,
  0x7E15,
  0x7DCD,
  0x7D7F,
  0x7D2D,
  0x7CD6,
  0x7C7A,
  0x7C1A,
  0x7BB4,
  0x7B49,
  0x7ADA,
  0x7A66,
  0x79ED,
  0x796F,
  0x78ED,
  0x7866,
  0x77DA,
  0x7749,
  0x76B4,
  0x761A,
  0x757B,
  0x74D8,
  0x7430,
  0x7384,
  0x72D3,
  0x721E,
  0x7164,
  0x70A6,
  0x6FE3,
  0x6F1C,
  0x6E51,
  0x6D81,
  0x6CAD,
  0x6BD5,
  0x6AF9,
  0x6A18,
  0x6933,
  0x684A,
  0x675D,
  0x666C,
  0x6577,
  0x647E,
  0x6381,
  0x6280,
  0x617C,
  0x6073,
  0x5F67,
  0x5E57,
  0x5D43,
  0x5C2C,
  0x5B11,
  0x59F2,
  0x58D0,
  0x57AA,
  0x5681,
  0x5555,
  0x5425,
  0x52F2,
  0x51BC,
  0x5082,
  0x4F46,
  0x4E06,
  0x4CC3,
  0x4B7D,
  0x4A35,
  0x48E9,
  0x479B,
  0x4649,
  0x44F5,
  0x439E,
  0x4245,
  0x40E9,
  0x3F8A,
  0x3E29,
  0x3CC6,
  0x3B60,
  0x39F8,
  0x388D,
  0x3721,
  0x35B2,
  0x3441,
  0x32CE,
  0x3159,
  0x2FE2,
  0x2E69,
  0x2CEF,
  0x2B72,
  0x29F4,
  0x2875,
  0x26F3,
  0x2570,
  0x23EC,
  0x2266,
  0x20DF,
  0x1F57,
  0x1DCE,
  0x1C43,
  0x1AB7,
  0x192A,
  0x179C,
  0x160E,
  0x147E,
  0x12ED,
  0x115C,
  0xFCA,
  0xE38,
  0xCA5,
  0xB11,
  0x97D,
  0x7E9,
  0x654,
  0x4C0,
  0x32A,
  0x195,
  0x0
};

static Acmd *_pullSubFrame(void *, s16 *, s16 *, s32, s32, Acmd *);
static s16 _getRate(f64, f64, s32, u16 *);
static f32 _getVol(f32, s32, s16, u16);

Acmd *alEnvmixerPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
  Acmd *ptr = p;
  ALEnvMixer *e = filter;
  s16 inp;
  s32 lastOffset;
  s32 thisOffset = sampleOffset;
  s32 samples;
  s16 loutp = 0;
  s32 fVol;
  ALParam *thisParam;

  inp = AL_RESAMPLER_OUT;

  if (((uintptr_t)outp < 0x80000000) || ((uintptr_t)outp >= 0x80400001) || !filter) {
    return ptr;
  }

  while (e->ctrlList != NULL) {
    lastOffset = thisOffset;
    thisOffset = e->ctrlList->delta;

    if ((thisOffset - lastOffset) < 0) {
      thisOffset = lastOffset;
    }

    samples = thisOffset - lastOffset;
    if (samples > outCount) {
      break;
    }
    if (samples < 0) {
      return ptr;
    }

    switch (e->ctrlList->type) {
    case AL_FILTER_START_VOICE_ALT:
      {
        ALStartParamAlt *param = (ALStartParamAlt *) e->ctrlList;
        ALFilter *f = (ALFilter *) e;
        s32 tmp;

        if (param->unity != 0) {
          e->filter.setParam(&e->filter, AL_FILTER_SET_UNITY_PITCH, NULL);
        }

        e->filter.setParam(&e->filter, AL_FILTER_SET_WAVETABLE, param->wave);
        e->filter.setParam(&e->filter, AL_FILTER_START, NULL);

        e->first = 1;

        e->delta = 0;
        e->segEnd = param->samples;

        tmp = (param->volume * param->volume) >> 15;
        e->volume = tmp;
        e->pan = param->pan;
        e->dryamt = eqpower[param->fxMix];
        e->wetamt = eqpower[127 - param->fxMix];

        if (param->samples != 0) {
          e->cvolL = 1;
          e->cvolR = 1;
        } else {
          e->cvolL = (e->volume * eqpower[e->pan]) >> 15;
          e->cvolR = (e->volume * eqpower[127 - e->pan]) >> 15;
        }

        if (f->source != NULL) {
          union {
            f32 f;
            s32 i;
          } data;

          data.f = param->pitch;
          f->source->setParam(f->source, AL_FILTER_SET_PITCH, (void *)  data.i);
        }
      }
      break;
    case AL_FILTER_SET_FXAMT:
    case AL_FILTER_SET_PAN:
    case AL_FILTER_SET_VOLUME:
      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
      e->delta += samples;

      if (e->delta >= e->segEnd) {
        e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
        e->rtgt = (e->volume * eqpower[127 - e->pan]) >> 15;
    e->delta = e->segEnd;
        e->cvolL = e->ltgt;
        e->cvolR = e->rtgt;
      } else {
        e->cvolL = _getVol(e->cvolL, e->delta, e->lratm, e->lratl);
        e->cvolR = _getVol(e->cvolR, e->delta, e->rratm, e->rratl);
      }

      if (e->cvolL == 0) { e->cvolL = 1; }
      if (e->cvolR == 0) { e->cvolR = 1; }

      if (e->ctrlList->type == AL_FILTER_SET_PAN) {
        e->pan = e->ctrlList->data.i;
      }

      if (e->ctrlList->type == AL_FILTER_SET_VOLUME) {
        e->delta = 0;

        fVol = e->ctrlList->data.i;
        fVol = (fVol * fVol) >> 15;
        e->volume = fVol;

        e->segEnd = e->ctrlList->moredata.i;
      }

      if (e->ctrlList->type == AL_FILTER_SET_FXAMT) {
        e->dryamt = eqpower[e->ctrlList->data.i];
        e->wetamt = eqpower[127 - e->ctrlList->data.i];
      }

      e->first = 1;
      break;
    case AL_FILTER_START_VOICE:
      {
        ALStartParam *p = (ALStartParam *) e->ctrlList;

        if (p->unity != 0) {
          e->filter.setParam(&e->filter, AL_FILTER_SET_UNITY_PITCH, 0);
        }

        e->filter.setParam(&e->filter, AL_FILTER_SET_WAVETABLE, p->wave);
        e->filter.setParam(&e->filter, AL_FILTER_START, 0);
      }
      break;
    case AL_FILTER_STOP_VOICE:
      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
      e->filter.setParam(&e->filter, AL_FILTER_RESET, 0);
      break;
    case AL_FILTER_FREE_VOICE:
      {
        ALSynth *drvr = &alGlobals->drvr;
        ALFreeParam *param = (ALFreeParam *) e->ctrlList;

        param->pvoice->offset = 0;
        _freePVoice(drvr, param->pvoice);
      }
      break;
    default:
      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
      e->delta += samples;

      e->filter.setParam(&e->filter, e->ctrlList->type, (void *) e->ctrlList->data.i);
      break;
    }

    loutp += samples << 1;
    outCount -= samples;

    thisParam = e->ctrlList;
    e->ctrlList = e->ctrlList->next;
    if (e->ctrlList == NULL) {
      e->ctrlTail = NULL;
    }

    __freeParam(thisParam);
  }

  if (e->motion == AL_PLAYING) {
    ptr = _pullSubFrame(e, &inp, &loutp, outCount, sampleOffset, ptr);
    e->delta += outCount;
  }

  if (e->delta > e->segEnd) {
    e->delta = e->segEnd;
  }

  return ptr;
}

s32 alEnvmixerParam(void *filter, s32 paramID, void *param) {
  ALFilter *f = filter;
  ALEnvMixer *e = filter;

  if (!f || !e) {
    return 0;
  }

  switch (paramID) {
  case AL_FILTER_ADD_UPDATE:
    if (e->ctrlTail != NULL) {
      e->ctrlTail->next = param;
    } else {
      e->ctrlList = param;
    }
    e->ctrlTail = param;
    break;
  case AL_FILTER_RESET:
    e->first = 1;
    e->motion = AL_STOPPED;
    e->volume = 1;
    if (f->source != NULL) {
      f->source->setParam(f->source, AL_FILTER_RESET, param);
    }
    break;
  case AL_FILTER_START:
    e->motion = AL_PLAYING;
    if (f->source != NULL) {
      f->source->setParam(f->source, AL_FILTER_START, param);
    }
    break;
  case AL_FILTER_SET_SOURCE:
    f->source = param;
    break;
  default:
    if (f->source != NULL) {
      f->source->setParam(f->source, paramID, param);
    }
    break;
  }

  return 0;
}

static Acmd *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
  Acmd *ptr = p;
  ALEnvMixer *e = filter;
  ALFilter *source = e->filter.source;

  if (outCount == 0) {
    return ptr;
  }

  ptr = source->handler(source, inp, outCount, sampleOffset, p);

  aSetBuffer(ptr++, A_MAIN, *inp, AL_MAIN_L_OUT + *outp, outCount << 1);
  aSetBuffer(ptr++, A_AUX, AL_MAIN_R_OUT + *outp, AL_AUX_L_OUT + *outp, AL_AUX_R_OUT + *outp);

  if (e->first != 0) {
    e->first = 0;

    e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
    e->lratm = _getRate(e->cvolL, e->ltgt, e->segEnd, &e->lratl);
    e->rtgt = (e->volume * eqpower[127 - e->pan]) >> 15;
    e->rratm = _getRate(e->cvolR, e->rtgt, e->segEnd, &e->rratl);

    aSetVolume(ptr++, A_LEFT | A_VOL, e->cvolL, 0, 0);
    aSetVolume(ptr++, A_RIGHT | A_VOL, e->cvolR, 0, 0);
    aSetVolume(ptr++, A_LEFT | A_RATE, e->ltgt, e->lratm, e->lratl);
    aSetVolume(ptr++, A_RIGHT | A_RATE, e->rtgt, e->rratm, e->rratl);
    aSetVolume(ptr++, A_AUX, e->dryamt, 0, e->wetamt);
    aEnvMixer(ptr++, A_INIT | A_AUX, osVirtualToPhysical(e->state));
  } else {
    aEnvMixer(ptr++, A_CONTINUE | A_AUX, osVirtualToPhysical(e->state));
  }

  *inp += outCount << 1;

  return ptr;
}

f64 _frexpf(f64 value, s32 *eptr) {
  f64 absvalue;

  *eptr = 0;

  if (value == 0.0) {
    return value;
  }

  absvalue = (value > 0.0) ? value : -value;
  for (; absvalue >= 1.0; absvalue *= 0.5) {
    (*eptr)++;
  }
  for (; absvalue < 0.5; absvalue += absvalue) {
    (*eptr)--;
  }

  return (value > 0.0) ? absvalue : -absvalue;
}

f64 _ldexpf(f64 in, s32 ex) {
  s32 exp;

  if (ex != 0) {
    exp = 1 << ex;
    in *= exp;
  }

  return in;
}

static s16 _getRate(f64 vol, f64 tgt, s32 count, u16 *ratel) {
  s16 s;
  f64 invn = 1.0 / count;
  f64 eps;
  f64 a;
  f64 fs;
  f64 mant;
  s32 i_invn;
  s32 ex;
  s32 indx;

  if (count == 0) {
    if (tgt >= vol) {
      *ratel = 0xFFFF;
      return 0x7FFF;
    } else {
      *ratel = 0;
      return 0;
    }
  }

  if (tgt < 1.0) { tgt = 1.0; }
  if (vol <= 0.0) { vol = 1.0; }

  {
    f64 logtab[] = { -0.912537, -0.752072, -0.607683, -0.476438, -0.356144, -0.245112, -0.142019, -0.045804 };

    i_invn = _ldexpf(invn, 30);
    mant = _frexpf(tgt / vol, &ex);
    indx = _ldexpf(mant, 4);
    eps = (logtab[indx - 8] + ex) * M_LN2;
    eps /= _ldexpf(1.0, 30);
    fs = 1.0 + eps;
    a = 1.0;

    while (i_invn != 0) {
      if (i_invn & 0x1) {
        a *= fs;
      }
      fs *= fs;
      i_invn >>= 1;
    }
  }

  a *= (a *= (a *= a));
  s = a;
  *ratel = (s16) (0xFFFF * (a - (f32) s));

  return a;
}

static f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel) {
  f32 r;
  f32 a;
  s32 i;

  samples >>= 3;
  if (samples == 0) {
    return ivol;
  }

  r = ((f32) (ratem << 16) + ratel) / 65536;
  a = 1.0;
  for (i = 0; i < 32; i++) {
    if (samples & 0x1) {
      a *= r;
    }
    samples >>= 1;
    if (samples == 0) {
      break;
    }
    r *= r;
  }

  ivol *= a;

  return ivol;
}
