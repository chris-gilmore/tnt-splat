#ifndef _046700_H_
#define _046700_H_

typedef struct {
  /* 0x0  */ u8           *unk0;
  /* 0x4  */ u8           *unk4;
  /* 0x8  */ u8           *unk8;
  /* 0xC  */ u8           *unkC;
  /* 0x10 */ u8           *unk10;
  /* 0x14 */ u8           *unk14;
  /* 0x18 */ u8           *unk18;
  /* 0x1C */ UnkStruct_0   unk1C;
  /* 0x7C */ u16           unk7C;
  /* 0x7E */ u16           unk7E;
  /* 0x80 */ u16           unk80;
} UnkStruct_12; // 0x84 bytes

extern void   FUN_046770_800804f0_many_heapallocs_for_arg0_elems(UnkStruct_12 *);

#endif /* !_046700_H_ */
