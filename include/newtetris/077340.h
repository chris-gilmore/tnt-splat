#ifndef _077340_H_
#define _077340_H_

typedef struct {
  /* 0x0  */ f32   unk0;
  /* 0x4  */ f32   unk4;
  /* 0x8  */ f32   unk8;
  /* 0xC  */ f32   unkC;
  /* 0x10 */ u8    pad10[0x110];
} UnkStruct_84; // 0x120 bytes

typedef struct {
  /* 0x0  */ f32   unk0;
  /* 0x4  */ f32   unk4;
  /* 0x8  */ f32   unk8;
  /* 0xC  */ f32   unkC;
  /* 0x10 */ u16   unk10;
  /* 0x12 */ u16   unk12;
  /* 0x14 */ u16   unk14;
  /* 0x16 */ u16   unk16;
  /* 0x18 */ u16   unk18;
  /* 0x1A */ u16   unk1A;
  /* 0x1C */ u16   unk1C;
  /* 0x1E */ u16   unk1E;
} UnkStruct_85; // 0x20 bytes

extern void   func_800B11C4(UnkStruct_85 *, UnkStruct_84 *);

#endif /* !_077340_H_ */
