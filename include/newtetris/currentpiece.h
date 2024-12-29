#ifndef _CURRENTPIECE_H_
#define _CURRENTPIECE_H_

typedef struct {
  /* 0x0   */ u8                  state;                 // piece state
  /* 0x1   */ u8                  qWinLoseIndicator;     // win (1), lose (2)
  /* 0x2   */ u8                  possibleMoves;         // movement flags: left (0x1), right (0x2), clockwise (0x8), counterclockwise (0x10)
  /* 0x3   */ u8                  isLocked;              // piece locking bool
  /* 0x4   */ u8                  lockDelay;             // initialized to 20 and decrements
  /* 0x6   */ s16                 fallVelocity;          // piece fall rate.  it starts off slow with a value of 3, meaning the piece falls 3/256th of a unit cell's height (or a line) per frame.  over time, the fall rate increases (it is based on time passed, not piece count), up to a maximum of 1 full line per frame (0x100).
  /* 0x8   */ s16                 fallVelocityCopy;      // memory of current piece fall rate.  since previous field will briefly change to max rate when pressing down, it will need to copy this field to revert back to current fall rate.
  /* 0xA   */ u8                  logicalRotCkwState;    // logical clockwise rotation state: 0 deg (0), 90 deg (1), 180 deg (2), 270 deg (3)
  /* 0xC   */ s16                 rotate_angle_step;
  /* 0xE   */ u8                  num_rotate_angle_steps;
  /* 0xF   */ Position            logicalRotOrigin;      // logical origin of rotation
  /* 0x11  */ Position            logicalPos;            // logical position
  /* 0x13  */ u8                  pieceType;             // piece type
  /* 0x14  */ u8                  alpha;                 // color alpha
  /* 0x15  */ Position            minoLockedPos_arr[4];  // minos locked position
  /* 0x20  */ Piece               piece;
  /* 0x518 */ PieceColorFlasher   flasher;
  /* 0x538 */ u8                  unk538;
  /* 0x539 */ u8                  pad539[0x7];
  /* 0x540 */ GhostPiece          ghostPiece;
} CurrentPiece; // 0xA6C bytes

extern CurrentPiece *g_currentPiece_ptr;

extern Point  *getCurPieceSpawnPoint(Point *, u8);
extern Point  *getStartingOriginOfRotationPoint(Point *, u8);
extern void    rotate_and_translate_mino(u8, Position *);
extern void    CurrentPiece_80066cc8_fourliner(void);
extern u8      CurrentPiece_80066d8c_maybeRotCkw_retbool(CurrentPiece *, s32, s32, s32);
extern void    CurrentPiece_8006715c_twelveliner_plays_SFX(CurrentPiece *);
extern void    CurrentPiece_80067254_twelveliner_plays_SFX(CurrentPiece *);
extern void    CurrentPiece_8006734c_thirtyliner_looks_interesting(CurrentPiece *, s8);
extern void    CurrentPiece_80067604_fourteenliner_loops4times(void);
extern void    CurrentPiece_800676ac_fourliner_looper(CurrentPiece *);
extern u8      CurrentPiece_800677b8_twohundredliner_doit_last(CurrentPiece *, s32);
extern s8      CurrentPiece_80067bc0_sixliner_loops4times(CurrentPiece *);
extern void    CurrentPiece_80067c1c_fifteenliner_loops3times(CurrentPiece *, BoundingBox *);
extern s32     CurrentPiece_80067d1c_twoliner(CurrentPiece *);
extern void    CurrentPiece_Render(CurrentPiece *);
extern void    CurrentPiece_80067dd8_big_fiftyliner(u8);
extern void    CurrentPiece_80068090_oneliner_sets_0x538_to_1(CurrentPiece *);

#endif /* !_CURRENTPIECE_H_ */
