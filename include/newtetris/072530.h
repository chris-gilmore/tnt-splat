#ifndef _072530_H_
#define _072530_H_

typedef struct {
  /* 0x0 */ s16    unk0;  // char width
  /* 0x2 */ s16    unk2;
  /* 0x4 */ s16    unk4;  // s
  /* 0x6 */ s16    unk6;  // t
  /* 0x8 */ void  *unk8;  // font map image
  /* 0xC */ s16    unkC;  // char height
} UnkStruct_113; // 0x10 bytes

typedef struct UnkStruct_114 UnkStruct_114;
struct UnkStruct_114 {
  /* 0x0   */ UnkStruct_113   unk0[80];
  /* 0x500 */ char           *unk500;  // font chars array
  /* 0x504 */ UnkStruct_114  *unk504;  // self ptr
  /* 0x508 */ void           *unk508;  // font map image
}; // 0x50C bytes

extern void   func_800AC308(s32, s32);
extern void   func_800AC334(s32, s32, s32);
extern Gfx   *func_800AC350(Gfx *);
extern Gfx   *func_800AC4E0(Gfx *, char *);
extern Gfx   *func_800AC708(Gfx *, u8 *, s32, s32);
extern Gfx   *func_800AC950(Gfx *, s32);

#endif /* !_072530_H_ */
