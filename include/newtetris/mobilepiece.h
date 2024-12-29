#ifndef _MOBILEBPIECE_H_
#define _MOBILEBPIECE_H_

typedef struct {
  /* 0x0  */ u8                alpha;                // color alpha
  /* 0x4  */ PieceDefinition  *pieceDef_ptr;         // piece definition address
  /* 0x8  */ u16               physicalCkwRotValue;  // rendering clockwise rotation value
  /* 0xA  */ Point             physicalRotOrigin;    // rendering origin of rotation
  /* 0xE  */ Point             physicalPos;          // rendering position
  /* 0x12 */ u8                pad12[0x6];
  /* 0x18 */ Mino              mino_arr[4];
} Piece; // 0x4F8 bytes

typedef struct {
  /* 0x0  */ u8      enabled;
  /* 0x1  */ u8      state;
  /* 0x2  */ Color   alt_color;
  /* 0xE  */ Color   main_color;
  /* 0x1C */ Piece  *piece_ptr;
} PieceColorFlasher; // 0x20 bytes

extern void   MobilePiece_80064f54_fourliner_loops_4_times(Piece *, s32);
extern void   MobilePiece_Render(Piece *);
extern u8     MobilePiece_80065154_sevenliner_loops_4_times_v1_retbool(Piece *, s32);
extern u8     MobilePiece_800651c8_sevenliner_loops_4_times_v2_retbool(Piece *);
extern void   MobilePiece_80065238_sevenliner_loops_4_times(Piece *, Piece *);
extern void   MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(Piece *, Color *);
extern void   MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(Piece *, PieceDefinition *, Point, Point, u16, u8);
extern void   MobilePiece_8006553c_nineliner_sets_arg0_struct(PieceColorFlasher *, Piece *);
extern void   MobilePiece_800655c4_oneliner_if_calls_fun(PieceColorFlasher *, s32);
extern void   MobilePiece_80065620_threeliner_if_zero_calls_fun_537c(PieceColorFlasher *);
extern void   MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c(PieceColorFlasher *);
extern void   MobilePiece_SetAlternateColor(PieceColorFlasher *, Color *);

#endif /* !_MOBILEBPIECE_H_ */
