#ifndef _073D50_H_
#define _073D50_H_

typedef struct {
  /* 0x0 */ Vtx   vlist[4];
} UnkStruct_89; // 0x40 bytes

typedef struct {
  /* 0x0   */ s32            unk0;  // r (guOrtho)
  /* 0x4   */ s32            unk4;  // b (guOrtho)
  /* 0x8   */ s32            unk8;
  /* 0xC   */ s32            unkC;
  /* 0x10  */ s32            unk10;  // 0 or 1 (idx of unk18 and unk98)
  /* 0x14  */ UnkStruct_89  *unk14;
  /* 0x18  */ Mtx            unk18[2];  // modelview matrix
  /* 0x98  */ Mtx            unk98[2];  // m (guOrtho), projection matrix
  /* 0x118 */ Vp             unk118;
  /* 0x128 */ Vec3           unk128;
  /* 0x134 */ Vec3           unk134;
  /* 0x140 */ f32            unk140;
} UnkStruct_88; // 0x148 bytes

extern UnkStruct_88  *func_800ADE5C(s32, s32);
extern Gfx           *func_800AE220(UnkStruct_88 *, Gfx *, u16 *, u8, u8, u8, u8);
extern void           func_800AE6C8(UnkStruct_88 *, Vec3 *);
extern void           func_800AE6E4(UnkStruct_88 *, Vec3 *);
extern void           func_800AE700(UnkStruct_88 *, f32);

#endif /* !_073D50_H_ */
