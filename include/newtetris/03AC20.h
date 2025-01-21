#ifndef _03AC20_H_
#define _03AC20_H_

typedef struct {
  /* 0x0 */ u8   pad0[0x14];
} UnkStruct_33; // 0x14 bytes

typedef struct {
  /* 0x0 */ u8   unk0;
  /* 0x1 */ u8   unk1;
} UnkStruct_32; // 0x2 bytes

typedef struct {
  /* 0x0 */ UnkStruct_32   unk0;
  /* 0x2 */ s16            unk2;
  /* 0x4 */ s16            unk4;
  /* 0x6 */ u16            unk6;
} UnkStruct_31; // 0x8 bytes

typedef struct {
  /* 0x0  */ u8             pad0[0x4];
  /* 0x4  */ u16            unk4;
  /* 0x8  */ UnkStruct_33  *unk8;
  /* 0xC  */ u8            *unkC;
  /* 0x10 */ u8            *unk10;
  /* 0x14 */ UnkStruct_32   unk14;
  /* 0x16 */ u16            unk16;
  /* 0x18 */ u16            unk18;
} UnkStruct_30; // 0x1A bytes

extern void   func_80075218(UnkStruct_30 *, u16, u16);
extern u8     func_8007523C(UnkStruct_30 *, UnkStruct_31 *);

#endif /* !_03AC20_H_ */
