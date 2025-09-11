#ifndef _BORGANIM_H_
#define _BORGANIM_H_

typedef struct {
  /* 0x0   */ u32            unk0;
  /* 0x4   */ u8             unk4;    // 0 or 1 (toggle)
  /* 0x5   */ u8             unk5;
  /* 0x6   */ u16            unk6;
  /* 0x8   */ UnkStruct_48  *unk8;
  /* 0xC   */ MtxF           unkC;
  /* 0x4C  */ MtxF           unk4C;
  /* 0x8C  */ MtxF           unk8C;
  /* 0xCC  */ MtxF           unkCC;
  /* 0x10C */ MtxF           unk10C;
  /* 0x14C */ u8             pad14C[0x84];
  /* 0x1D0 */ UnkStruct_50  *unk1D0;  // animation list (root node)
  /* 0x1D4 */ u8             unk1D4;
  /* 0x1D5 */ u8             unk1D5;
  /* 0x1D6 */ u8             unk1D6;
  /* 0x1D7 */ u8             unk1D7;
  /* 0x1D8 */ s32            unk1D8;
  /* 0x1DC */ s32            unk1DC;
  /* 0x1E0 */ u8             pad1E0[0x8];
} UnkStruct_32; // 0x1E8 bytes

typedef struct {
  /* 0x0  */ UnkStruct_32  *unk0;
  /* 0x4  */ UnkStruct_75  *unk4;    // .id = 5
  /* 0x8  */ UnkStruct_49  *unk8;
  /* 0xC  */ UnkStruct_46  *unkC;    // .id = 2
  /* 0x10 */ UnkStruct_44  *unk10;   // .id = 1
  /* 0x14 */ UnkStruct_62  *unk14;
  /* 0x18 */ u8             pad18[0x4];
  /* 0x1C */ UnkStruct_39  *unk1C[0x8];
  /* 0x3C */ u32            gm_set;  // SetGeometryMode flags
  /* 0x40 */ u32            gm_clr;  // ClearGeometryMode flags
  /* 0x44 */ u32            unk44;   // SetTextureFilter
  /* 0x48 */ u8             red;     // SetPrimColor
  /* 0x49 */ u8             green;   //
  /* 0x4A */ u8             blue;    //
  /* 0x4B */ u8             alpha;   //
  /* 0x4C */ u32            unk4C;   // SetCycleType
  /* 0x50 */ u32            mode1;   // SetRenderMode
  /* 0x54 */ u32            mode2;   //
  /* 0x58 */ u8             pad58[0x8];
} UnkStruct_69; // 0x60 bytes

extern Gfx           *func_800A4B98(Gfx *, UnkStruct_44 *);
extern void           func_800A678C(UnkStruct_32 *, UnkStruct_50 *);
extern UnkStruct_32  *func_800A6990(s32);
extern void           func_800A6A2C(UnkStruct_32 *);
extern UnkStruct_50  *func_800A6A74(s32);
extern void           func_800A6AA8(UnkStruct_50 *);
extern void           func_800A6DD8(UnkStruct_32 *);
extern Gfx           *func_800A724C(Gfx *, UnkStruct_32 *);

#endif /* !_BORGANIM_H_ */
