#ifndef _06F290_H_
#define _06F290_H_

typedef struct {
  /* 0x0  */ u16      unk0;
  /* 0x4  */ s32      unk4;
  /* 0x8  */ OSTime   unk8;
  /* 0x10 */ OSTime   unk10;
} UnkStruct_116; // 0x18 bytes

typedef struct UnkStruct_117 UnkStruct_117;
struct UnkStruct_117 {
  /* 0x0  */ s32             unk0;
  /* 0x4  */ u8              unk4;
  /* 0x5  */ u8              unk5;
  /* 0x8  */ UnkStruct_116   unk8[2];
  /* 0x38 */ u8              unk38;
  /* 0x39 */ u8              unk39;
  /* 0x3C */ s32             unk3C;  // unused
  /* 0x40 */ UnkStruct_116   unk40[2];
  /* 0x70 */ u8              unk70;  // red
  /* 0x71 */ u8              unk71;  // green
  /* 0x72 */ u8              unk72;  // blue
  /* 0x74 */ UnkStruct_117  *next;
}; // 0x78 bytes

extern u32 D_801295E0;
extern u32 D_801295E4;
extern u32 D_801295E8;
extern u32 D_801295EC;
extern OSTime D_801295F0;

extern void            func_800A9010(Gfx **);
extern UnkStruct_117  *func_800A939C(s32, u8, u8, u8);  // unused
extern void            func_800A94A8(UnkStruct_117 *);  // unused
extern void            func_800A9518(UnkStruct_117 *);  // unused
extern void            func_800A958C(UnkStruct_117 *);  // unused
extern void            func_800A95F8(UnkStruct_117 *);  // unused
extern void            func_800A9668(UnkStruct_117 *, OSTime, OSTime);  // unused
extern void            func_800A96F4(UnkStruct_117 *, u32);  // unused
extern void            func_800A9758(void);  // unused
extern Gfx            *func_800A98E4(Gfx *);  // unused

#endif /* !_06F290_H_ */
