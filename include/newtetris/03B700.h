#ifndef _03B700_H_
#define _03B700_H_

typedef struct {
  /* 0x0 */ u8   r;
  /* 0x1 */ u8   g;
  /* 0x2 */ u8   b;
} RGB; // 0x3 bytes

typedef struct {
  /* 0x0 */ RGB  *pal;
  /* 0x4 */ u8    unk4;
  /* 0x6 */ u16   num_entries;
} PaletteInfo; // 0x8 bytes

typedef struct {
  /* 0x0 */ s32   unk0;
  /* 0x4 */ s32   unk4;
} UnkStruct_23; // 0x8 bytes

typedef struct {
  /* 0x0  */ Gradient2D    *unk0;      // &(Mino *)->unk24
  /* 0x4  */ void          *unk4;      // &(Mino *)->unk{B0,F0}
  /* 0x8  */ u8            *unk8;
  /* 0xC  */ u32            unkC;      // 8, 200
  /* 0x10 */ u32            unk10;     // 8, 150
  /* 0x14 */ u32            unk14;     // 1, 2
  /* 0x18 */ u32            unk18;     // 8 * 8, 200 * 150
  /* 0x1C */ u32            unk1C;
  /* 0x20 */ u32            unk20;
  /* 0x24 */ UnkStruct_23   unk24[4];
} UnkStruct_24; // 0x44 bytes

typedef struct {
  /* 0x0 */ u16  *unk0;
  /* 0x4 */ s16   unk4;  // PaletteInfo.num_entries
  /* 0x6 */ s16   unk6;  // PaletteInfo.num_entries
  /* 0x8 */ u8    unk8;
  /* 0x9 */ u8    unk9;
} UnkStruct_15; // 0xC bytes

typedef struct UnkStruct_0 UnkStruct_0;

struct UnkStruct_0 {
  /* 0x0  */ u8            *unk0;  // light source data
  /* 0x4  */ u16            width;
  /* 0x6  */ u16            height;
  /* 0x8  */ UnkStruct_15   unk8;
  /* 0x14 */ UnkStruct_24   unk14;
  /* 0x58 */ void         (*unk58)(UnkStruct_0 *);
  /* 0x5C */ u8             unk5C;  // 0, 1, or 2 (see 03B700.c, func_80075760)
}; // 0x60 bytes

extern s32    func_80075480(UnkStruct_15 *, PaletteInfo *, PaletteInfo *);
extern void   func_800756A8(UnkStruct_15 *);
extern void   func_80075700(UnkStruct_24 *, u32, u32, u32);
extern void   func_80075760(UnkStruct_0 *, u8);
extern u8     func_800757BC(UnkStruct_0 *, void *, u32, u32);
extern void   func_80075830(UnkStruct_0 *);
extern void   func_80075870(UnkStruct_0 *);

#endif /* !_03B700_H_ */
