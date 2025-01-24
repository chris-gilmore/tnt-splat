#ifndef _TETRIS_H_
#define _TETRIS_H_

typedef struct {
  /* 0x0    */ u8             unk0;
  /* 0x1    */ u8             unk1;
  /* 0x2    */ u8             unk2;
  /* 0x3    */ u8             unk3;
  /* 0x4    */ u8             unk4;
  /* 0x8    */ FrameAct       frameAct;
  /* 0x54   */ LineScan       lineScan;
  /* 0x44C  */ Squares        squares;
  /* 0x768  */ UnkStruct_9    unk768;        // keyspin related
  /* 0x7D0  */ UnkStruct_0    unk7D0;        // minos related
  /* 0x830  */ Board          board;
  /* 0x51F0 */ PieceHold      pieceHold;
  /* 0x6690 */ Bag63          bag63;
  /* 0x674C */ Garbage       *garbage_ptr;
  /* 0x6750 */ PfGfx          pfGfx;
  /* 0x6808 */ GameStats      gameStats;
  /* 0x6834 */ u32            ultraGoal;
  /* 0x6838 */ BoardInfo      boardInfo;
  /* 0x6840 */ s32            unk6840;
  /* 0x6844 */ u8             pad6844[0x4];
} Tetris; // 0x6848 bytes

extern Tetris *g_tetris_ptr;

extern void   Tetris_FUN_80054220_fourliner(Tetris *, u8);
extern u8     Tetris_Update(Tetris *);
extern void   Tetris_Render(Tetris *);
extern void   Tetris_Init(Tetris *, GameVars *);
extern void   Tetris_Deinit(Tetris *);

#endif /* !_TETRIS_H_ */
