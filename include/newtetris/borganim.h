#ifndef _BORGANIM_H_
#define _BORGANIM_H_

typedef struct {
  /* 0x0   */ u32            unk0;
  /* 0x4   */ u8             unk4;
  /* 0x5   */ u8             unk5;
  /* 0x6   */ u16            unk6;
  /* 0x8   */ UnkStruct_48  *unk8;
  /* 0xC   */ f32            unkC[4][4];
  /* 0x4C  */ f32            unk4C[4][4];
  /* 0x8C  */ u8             pad8C[0x144];
  /* 0x1D0 */ UnkStruct_50  *unk1D0;  // animation list (root node)
  /* 0x1D4 */ u8             pad1D4[0x14];
} UnkStruct_32; // 0x1E8 bytes

extern void           func_800A678C(UnkStruct_32 *, UnkStruct_50 *);
extern UnkStruct_32  *func_800A6990(s32);
extern void           func_800A6A2C(UnkStruct_32 *);
extern UnkStruct_50  *func_800A6A74(s32);
extern void           func_800A6AA8(UnkStruct_50 *);
extern void           func_800A6DD8(UnkStruct_32 *);
extern Gfx           *func_800A724C(Gfx *, UnkStruct_32 *);

#endif /* !_BORGANIM_H_ */
