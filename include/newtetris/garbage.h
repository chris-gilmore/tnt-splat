#ifndef _GARBAGE_H_
#define _GARBAGE_H_

typedef struct {
  /* 0x0 */ u8    unk0;
  /* 0x1 */ u8    hole;
  /* 0x2 */ u8    unk2;
  /* 0x4 */ u32   seed;
} UnkStruct_110; // 0x8 bytes

typedef struct {
  /* 0x0  */ u8              unk0;
  /* 0x1  */ u8              unk1;
  /* 0x2  */ u8              unk2;
  /* 0x3  */ u8              unk3;
  /* 0x4  */ u8              unk4;
  /* 0x5  */ u8              unk5;
  /* 0x6  */ u8              unk6;
  /* 0x8  */ s32             unk8;
  /* 0xC  */ s32             unkC;
  /* 0x10 */ u8              unk10;
  /* 0x14 */ UnkStruct_110   unk14;
  /* 0x1C */ u8              unk1C;
  /* 0x1D */ u8              unk1D;
  /* 0x1E */ u8              unk1E[4];
} Garbage; // 0x24 bytes

extern Garbage *g_garbage_ptr;

extern void   func_80072CC8(Garbage *, u8, u8);
extern u8     func_80072D24(Garbage *, u8);
extern void   Garbage_Init(Garbage *, u32 *);
extern void   Garbage_Deinit(Garbage *);
extern void   Garbage_80072e2c_set_arg0p_to_arg1(Garbage *, s32);
extern void   func_80072E34(Garbage *, s32);
extern u8     func_80072F1C(s32);
extern void   func_80072FB0(void);  // unused
extern void   func_80072FC4(void);
extern void   func_80073030(u32);

#endif /* !_GARBAGE_H_ */
