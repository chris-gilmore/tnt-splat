#ifndef _SPRITE_H_
#define _SPRITE_H_

typedef struct {
  /* 0x0  */ u32   unk0;
  /* 0x4  */ u32   unk4;
  /* 0x8  */ u32   unk8;
  /* 0xC  */ s32   unkC;
  /* 0x10 */ s32   unk10;
  /* 0x14 */ s32   unk14;
  /* 0x18 */ s32   unk18;
  /* 0x1C */ s32   unk1C;
  /* 0x20 */ s32   unk20;
  /* 0x24 */ s32   unk24;
  /* 0x28 */ s32   unk28;
  /* 0x2C */ s32   unk2C;
  /* 0x30 */ s32   unk30;
  /* 0x34 */ s32   unk34;
  /* 0x38 */ s32   unk38;
  /* 0x3C */ s32   unk3C;
  /* 0x40 */ s32   unk40;
  /* 0x44 */ s32   unk44;
  /* 0x48 */ s16   unk48;
  /* 0x4A */ s16   unk4A;
  /* 0x4C */ s16   unk4C;
  /* 0x4E */ s16   unk4E;
  /* 0x50 */ s16   unk50;
  /* 0x52 */ s16   unk52;
} UnkStruct_3; // 0x54 bytes

extern void   func_800B1770(UnkStruct_3 *, OSContPad *);
extern void   func_800B1A7C(UnkStruct_3 *);

#endif /* !_SPRITE_H_ */
