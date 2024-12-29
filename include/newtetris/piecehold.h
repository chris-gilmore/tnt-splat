#ifndef _PIECEHOLD_H_
#define _PIECEHOLD_H_

typedef struct {
  /* 0x0  */ u8      unk0;
  /* 0x1  */ u8      alpha;
  /* 0x2  */ s16     unk2;
  /* 0x4  */ s16     unk4;
  /* 0x6  */ s16     unk6;
  /* 0x8  */ u16     mino_scale;
  /* 0xA  */ u8      unkA[0x6];
  /* 0x10 */ Piece   piece;
} PieceHoldPieceShadow; // 0x508 bytes

typedef struct {
  /* 0x0   */ u8                     state;
  /* 0x1   */ u8                     piece_type;
  /* 0x2   */ u16                    physicalCkwRotValue;
  /* 0x4   */ s16                    unk4;
  /* 0x6   */ s16                    mino_scale;
  /* 0x8   */ s16                    unk8;
  /* 0xA   */ Point                  physicalRotOrigin;
  /* 0xE   */ Point                  unkE;
  /* 0x12  */ Point                  physicalPos;
  /* 0x16  */ Point                  unk16;
  /* 0x1A  */ u8                     unk1A;
  /* 0x1B  */ u8                     pad1B[5];
  /* 0x20  */ Piece                  piece;
  /* 0x518 */ PieceColorFlasher      flasher;
  /* 0x538 */ PieceHoldPieceShadow   shadow;
  /* 0xA40 */ u8                     unkA40[0x8];
} PieceHoldPiece; // 0xA48 bytes

typedef struct {
  /* 0x0    */ PieceHoldPiece   buf[2];
  /* 0x1490 */ Point            unk1490;
  /* 0x1494 */ u8               buf_idx;          // 0 or 1
  /* 0x1495 */ u8               can_swap;
  /* 0x1496 */ u8               num_anim_frames;  // set to 16 jiffies
  /* 0x1498 */ UnkStruct_16     unk1498;
} PieceHold; // 0x14A0 bytes

extern void   PieceHold_Update(PieceHold *, s32);
extern void   PieceHold_Render(PieceHold *);
extern void   PieceHold_Swap(PieceHold *, CurrentPiece *);
extern void   PieceHold_Enable(PieceHold *);
extern void   PieceHold_Disable(PieceHold *);
extern void   PieceHold_Init(PieceHold *, u32 *, u8, u8, u8);
extern void   PieceHold_Deinit(PieceHold *);

#endif /* !_PIECEHOLD_H_ */
