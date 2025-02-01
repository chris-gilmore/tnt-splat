#ifndef _FRAMETIME_H_
#define _FRAMETIME_H_

typedef struct {
  /* 0x0  */ s32   unk0;
  /* 0x4  */ s32   unk4;
  /* 0x8  */ s32   unk8;
  /* 0xC  */ s32   unkC;
  /* 0x10 */ s32   unk10;
  /* 0x14 */ s32   unk14;
} FrameTime; // 0x18 bytes

extern FrameTime g_frameTime;

extern void   func_800A39B0(void);
extern void   func_800A39D4(s32);
extern void   func_800A39FC(s32);
extern void   func_800A3A8C(s32);
extern s32    func_800A3AB4(void);
extern s32    func_800A3AC0(void);
extern s32    func_800A3ACC(void);
extern s32    func_800A3AD8(void);
extern s32    func_800A3AE4(void);
extern s32    func_800A3AF0(void);

#endif /* !_FRAMETIME_H_ */
