#ifndef _BOARD_H_
#define _BOARD_H_

typedef struct {
  /* 0x0    */ CurrentPiece   currentPiece;
  /* 0xA6C  */ u8             padA6C[0x4];
  /* 0xA70  */ NextPieces     nextPieces;
  /* 0x3390 */ MobileCubes    mobileCubes;
  /* 0x339C */ FallingCubes   fallingCubes;
  /* 0x33A4 */ u8             next_cell_id;
  /* 0x33A8 */ BoardPieces    boardPieces;
} Board; // 0x6018 bytes

extern void   Board_Update(Board *, s32);
extern void   Board_Init(Board *, Bag63 *, UnkStruct_0 *);
extern void   Board_Deinit(Board *);

#endif /* !_BOARD_H_ */
