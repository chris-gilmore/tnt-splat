#ifndef _03D140_H_
#define _03D140_H_

typedef struct {
  /* 0x0  */ u8   *unk0;
  /* 0x4  */ u8   *unk4;
  /* 0x8  */ f32   unk8;
  /* 0xC  */ f32   unkC;
  /* 0x10 */ f32   unk10;
  /* 0x14 */ f32   unk14;
  /* 0x18 */ f32   unk18;
  /* 0x1C */ f32   unk1C;
  /* 0x20 */ u8    unk20;  // bit pattern (see 03D140.c)
  /* 0x24 */ s32   unk24;
  /* 0x28 */ s32   unk28;
  /* 0x2C */ s32   unk2C;
} UnkStruct_11; // 0x30 bytes

extern void   func_80076EC0(UnkStruct_11 *, u8);  // init
extern void   func_80077028(UnkStruct_11 *);      // deinit
extern void   func_80077098(UnkStruct_11 *);      // render

#endif /* !_03D140_H_ */
