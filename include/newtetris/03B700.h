#ifndef _03B700_H_
#define _03B700_H_

typedef struct {
  /* 0x0 */ u8   *pal;
  /* 0x4 */ u8    unk4;
  /* 0x6 */ u16   num_entries;
} PaletteInfo; // 0x8 bytes

typedef struct {
  /* 0x0 */ s32   unk0;
  /* 0x4 */ s32   unk4;
} UnkStruct_23; // 0x8 bytes

typedef struct {
  /* 0x0  */ s8            *unk0;        // &(Mino *)->unk24
  /* 0x4  */ s8            *unk4;        // &(Mino *)->unk{B0,F0}
  /* 0x8  */ s32            unk8;
  /* 0xC  */ u32            unkC;
  /* 0x10 */ u32            unk10;
  /* 0x14 */ s32            unk14;
  /* 0x18 */ s32            unk18;
  /* 0x1C */ s32            unk1C;
  /* 0x20 */ s32            unk20;
  /* 0x24 */ UnkStruct_23   unk24[4];
} UnkStruct_24; // 0x44 bytes

typedef struct {
  /* 0x0 */ u8   *unk0;
  /* 0x4 */ u16   unk4;
  /* 0x6 */ u16   unk6;
  /* 0x8 */ u8    unk8;
  /* 0x9 */ u8    unk9;
} UnkStruct_15; // 0xA bytes

typedef struct UnkStruct_0_s {
  /* 0x0  */ u8            *unk0;
  /* 0x4  */ u16            width;
  /* 0x6  */ u16            height;
  /* 0x8  */ UnkStruct_15   unk8;
  /* 0x14 */ UnkStruct_24   unk14;
  /* 0x58 */ void         (*unk58)(struct UnkStruct_0_s *);
  /* 0x5C */ u8             unk5C;  // 0, 1, or 2 (see 03B700.c, func_80075760)
} UnkStruct_0; // 0x60 bytes

extern s32    func_80075480(UnkStruct_15 *, PaletteInfo *, PaletteInfo *);
extern void   func_800756A8(UnkStruct_15 *);
extern void   func_80075700(UnkStruct_24 *, u32, u32, s32);
extern void   func_80075760(UnkStruct_0 *, s32);
extern s32    func_800757BC(UnkStruct_0 *, u8 *, s16, s16);
extern void   func_80075830(UnkStruct_0 *);
extern void   func_80075870(UnkStruct_0 *);

#endif /* !_03B700_H_ */
