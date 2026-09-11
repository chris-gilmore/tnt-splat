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

static f64 _frexpf(f64, s32 *);
static f64 _ldexpf(f64, s32);
static s16 _getRate(f64, f64, s32, u16 *);
static f32 _getVol(f32, s32, s16, u16);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_env/alEnvmixerPull.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_env/alEnvmixerParam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/audio_env/_pullSubFrame.s")

static f64 _frexpf(f64 value, s32 *eptr) {
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

static f64 _ldexpf(f64 in, s32 ex) {
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
