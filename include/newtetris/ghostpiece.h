#ifndef _GHOSTPIECE_H_
#define _GHOSTPIECE_H_

typedef struct {
  /* 0x0   */ u8                  unk0;
  /* 0x1   */ u8                  unk1[0x7];
  /* 0x8   */ Piece               piece;
  /* 0x500 */ PieceColorFlasher   flasher;
  /* 0x520 */ PieceDefinition    *pieceDef_ptr;
  /* 0x524 */ s16                 unk524;  // currentPiece_ptr->piece.physicalRotOrigin.x
  /* 0x526 */ s16                 unk526;  // currentPiece_ptr->piece.physicalPos.x
  /* 0x528 */ u16                 unk528;  // currentPiece_ptr->logicalRotCkwState << 14
  /* 0x52A */ u8                  unk52A;
} GhostPiece; // 0x52C bytes

extern void   GhostPiece_800666d0_sixliner_loops_arg1_times(GhostPiece *, s32);
extern void   GhostPiece_Render(GhostPiece *);
extern void   GhostPiece_800667dc_twelveliner_sets_struct(GhostPiece *, Point, Point, u16);
extern void   GhostPiece_800668ec_sixliner_inits_struct(GhostPiece *, PieceDefinition *, u8);

#endif /* !_GHOSTPIECE_H_ */
