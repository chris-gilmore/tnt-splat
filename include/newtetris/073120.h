#ifndef _073120_H_
#define _073120_H_

typedef struct {
  /* 0x0  */ f32    unk0;
  /* 0x4  */ Vec3   unk4;
  /* 0x10 */ u8     pad10[0xC];
  /* 0x1C */ s32    unk1C;
  /* 0x20 */ u8     pad20[0x8];
} UnkStruct_87; // 0x28 bytes

typedef struct {
  /* 0x0   */ u8             pad0[0xC0];
  /* 0xC0  */ s32            unkC0;
  /* 0xC4  */ UnkStruct_87  *unkC4;
  /* 0xC8  */ u8             padC8[0xC];
  /* 0xD4  */ s32            unkD4;
  /* 0xD8  */ f32            unkD8;
  /* 0xDC  */ f32            unkDC;
  /* 0xE0  */ f32            unkE0;
  /* 0xE4  */ u8             padE4[0x4];
  /* 0xE8  */ f32            unkE8;
  /* 0xEC  */ f32            unkEC;
  /* 0xF0  */ f32            unkF0;
  /* 0xF4  */ u8             padF4[0x10];
  /* 0x104 */ f32            unk104;
  /* 0x108 */ f32            unk108;
  /* 0x10C */ f32            unk10C;
  /* 0x110 */ f32            unk110;
  /* 0x114 */ f32            unk114;
  /* 0x118 */ s32            unk118;
  /* 0x11C */ s32            unk11C;
} UnkStruct_86; // 0x120 bytes

extern UnkStruct_86  *func_800ACEA0(s32, UnkStruct_44 *);
extern void           func_800AD120(UnkStruct_86 *);
extern Gfx           *func_800AD970(Gfx *, UnkStruct_86 *, UnkStruct_32 *);

#endif /* !_073120_H_ */
