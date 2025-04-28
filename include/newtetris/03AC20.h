#ifndef _03AC20_H_
#define _03AC20_H_

typedef struct {
  /* 0x0  */ u16   unk0;
  /* 0x2  */ s16   unk2;
  /* 0x4  */ s16   unk4;
  /* 0x6  */ s16   unk6;
  /* 0x8  */ u16   unk8;
  /* 0xA  */ s16   unkA;
  /* 0xC  */ s16   unkC;
  /* 0xE  */ s16   unkE;
  /* 0x10 */ s16   unk10;
  /* 0x12 */ u16   unk12;
} UnkStruct_33; // 0x14 bytes

typedef struct {
  /* 0x0 */ u8   width;
  /* 0x1 */ u8   height;
} Dim; // 0x2 bytes

typedef struct {
  /* 0x0 */ Dim     unk0;
  /* 0x2 */ Point   unk2;
  /* 0x6 */ u16     unk6;
} UnkStruct_31; // 0x8 bytes

typedef struct {
  /* 0x0  */ Point          unk0;
  /* 0x4  */ u16            unk4;     // 128
  /* 0x8  */ UnkStruct_33  *unk8;     // list (unk4 is count)
  /* 0xC  */ u8            *unkC[2];
  /* 0x14 */ Dim            unk14;
  /* 0x16 */ u16            unk16;
  /* 0x18 */ u16            unk18;
  /* 0x1A */ u16            unk1A;
} UnkStruct_30; // 0x1C bytes

extern void   func_80074EC4(UnkStruct_30 *);
extern void   func_80074F3C(UnkStruct_30 *);
extern void   func_80075180(void);
extern void   func_800751C0(void);
extern void   func_80075218(UnkStruct_30 *, s32, s32);
extern u8     func_8007523C(UnkStruct_30 *, UnkStruct_31 *);  // init
extern void   func_80075400(UnkStruct_30 *);                  // deinit

#endif /* !_03AC20_H_ */
