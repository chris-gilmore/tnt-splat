#ifndef _ANIMPARAMS_H_
#define _ANIMPARAMS_H_

typedef struct {
  /* 0x0  */ u16     img_ids[30];
  /* 0x3C */ u16     pal_ids[30];
  /* 0x78 */ u8      num_images;
  /* 0x79 */ u8      unk79;
  /* 0x7A */ Point   p;
  /* 0x80 */ u8    **images;
  /* 0x84 */ u8    **palettes;
  /* 0x88 */ u8      unk88;
  /* 0x89 */ u8      unk89;
  /* 0x8A */ u8      unk8A;
  /* 0x8B */ u8      unk8B;
  /* 0x8C */ u8      unk8C;
  /* 0x90 */ f32     unk90;
  /* 0x94 */ f32     unk94;
  /* 0x98 */ u8      red;
  /* 0x99 */ u8      green;
  /* 0x9A */ u8      blue;
  /* 0x9B */ u8      alpha;
} AnimParams; // 0x9C bytes

// mayan temple fire (x8)
extern AnimParams D_800D1030;
extern AnimParams D_800D10CC;
extern AnimParams D_800D1168;
extern AnimParams D_800D1204;
extern AnimParams D_800D12A0;
extern AnimParams D_800D133C;
extern AnimParams D_800D13D8;
extern AnimParams D_800D1474;

// japanese sparkle (x5)
extern AnimParams D_800D1510;
extern AnimParams D_800D15AC;
extern AnimParams D_800D1648;
extern AnimParams D_800D16E4;
extern AnimParams D_800D1780;

// japanese water
extern AnimParams D_800D181C;

// finale boiler (x3)
extern AnimParams D_800D18B8;
extern AnimParams D_800D1954;
extern AnimParams D_800D19F0;

// finale light bulb (x8)
extern AnimParams D_800D1A8C;
extern AnimParams D_800D1B28;
extern AnimParams D_800D1BC4;
extern AnimParams D_800D1C60;
extern AnimParams D_800D1CFC;
extern AnimParams D_800D1D98;
extern AnimParams D_800D1E34;
extern AnimParams D_800D1ED0;

// finale gauge needle
extern AnimParams D_800D1F6C;

// celtic lamp
extern AnimParams D_800D2008;

// russian candle (x13)
extern AnimParams D_800D20A4;
extern AnimParams D_800D2140;
extern AnimParams D_800D21DC;
extern AnimParams D_800D2278;
extern AnimParams D_800D2314;
extern AnimParams D_800D23B0;
extern AnimParams D_800D244C;
extern AnimParams D_800D24E8;
extern AnimParams D_800D2584;
extern AnimParams D_800D2620;
extern AnimParams D_800D26BC;
extern AnimParams D_800D2758;
extern AnimParams D_800D27F4;

// greek fire pot
extern AnimParams D_800D2890;

// egyptian coal pot
extern AnimParams D_800D292C;

// egyptian candle A
extern AnimParams D_800D29C8;

// egyptian candle B
extern AnimParams D_800D2A64;

// egyptian dust A
extern AnimParams D_800D2B00;

// egyptian dust B
extern AnimParams D_800D2B9C;

// african volcano smoke
extern AnimParams D_800D2C38;

extern void   func_8007635C(void);
extern void   func_800763B4(void);
extern void   func_800763EC(u32);
extern void   func_8007641C(UnkStruct_14 *, UnkStruct_23 *);
extern void   func_80076458(UnkStruct_14 *, UnkStruct_23 *);
extern void   func_800764A0(AnimParams *, AnimParams *);
extern void   func_800764B8(AnimParams *);
extern void   func_800766C8(AnimParams *);
extern void   func_800767C0(AnimParams *);

#endif /* !_ANIMPARAMS_H_ */
