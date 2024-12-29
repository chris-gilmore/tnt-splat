#ifndef _GAMESTATS_H_
#define _GAMESTATS_H_

typedef struct {
  /* 0x0  */ s16   x;
  /* 0x2  */ s16   y;
  /* 0x4  */ u32   odd_bits;
  /* 0x8  */ u32   even_bits;
  /* 0xC  */ s32   linesToBeAdded;
  /* 0x10 */ s32   linesMultiplier;
  /* 0x14 */ s32   unk14;
} LinesInfo; // 0x18 bytes

typedef struct {
  /* 0x0  */ f32         pieceFallVelocityInitial;  // initial piece fall velocity rate (0.01)
  /* 0x4  */ f32         pieceFallVelocityMax;      // max piece fall velocity rate (1.0)
  /* 0x8  */ f32         pieceFallAcceleration;     // piece fall acceleration rate (0.000003) (2fast4u, 0.0001)
  /* 0xC  */ s32         unkC;
  /* 0x10 */ u32         elapsedTime;
  /* 0x14 */ LinesInfo   linesInfo;
} GameStats; // 0x2C bytes

extern f32 g_pieceFallAcceleration;
extern GameStats *g_gameStats_ptr;

extern u32    getLineCount(LinesInfo *);
extern void   GameStats_saveCurrentPieceFallVelocity(GameStats *);
extern void   updateLinesToBeAdded(LinesInfo *, s32);
extern void   GameStats_Update(GameStats *, u32);
extern void   GameStats_Render(GameStats *);
extern void   GameStats_Init(GameStats *);
extern void   GameStats_Deinit(GameStats *);

#endif /* !_GAMESTATS_H_ */
