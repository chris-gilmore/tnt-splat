#ifndef _HOTPOTATO_H_
#define _HOTPOTATO_H_

typedef struct {
  /* 0x0  */ u8    unk0;
  /* 0x1  */ u8    unk1;
  /* 0x2  */ s16   unk2;
  /* 0x4  */ s16   unk4;
  /* 0x6  */ s16   unk6;
  /* 0x8  */ s16   unk8;
  /* 0xA  */ s16   unkA;
  /* 0xC  */ s16   unkC;
  /* 0xE  */ s16   unkE;
  /* 0x10 */ s16   unk10;
  /* 0x12 */ u16   unk12;
} UnkStruct_29; // 0x14 bytes

extern void   HotPotato_Render(UnkStruct_29 *);
extern void   HotPotato_Init(UnkStruct_29 *);
extern void   HotPotato_Deinit(UnkStruct_29 *);

#endif /* !_HOTPOTATO_H_ */
