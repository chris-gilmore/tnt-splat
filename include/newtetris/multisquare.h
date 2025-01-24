#ifndef _MULTISQUARE_H_
#define _MULTISQUARE_H_

#define SQUARETYPE_NONE    0
#define SQUARETYPE_MULTI   1
#define SQUARETYPE_MONO    2

typedef struct {
  /* 0x0  */ u8           type;  // 1 (silver) or 2 (gold)
  /* 0x1  */ u8           unk1;  // count ?
  /* 0x2  */ u8           id;
  /* 0x3  */ u8           unk3;  // bool
  /* 0x4  */ SquareGlow   glow;
} Square; // 0x12 bytes

typedef struct {
  /* 0x0 */ u8       unk0;
  /* 0x1 */ u8       unk1;
  /* 0x2 */ u8       delay;    // square formation delay
  /* 0x3 */ u8       cnt;
  /* 0x4 */ Square   arr[44];
} Squares; // 0x31C bytes

extern Squares *g_squares_ptr;

extern void     Multisquare_8006a410_fourliner(Square *, u8 *);
extern Color   *Multisquare_pGetColor(Square *);
extern u8       MultisquareGlow_isArg0_lessthan_44(u8);
extern s32      MultisquareGlow_8006ac2c_loops_10_times(s32, s32);
extern u8       MultisquareGlow_8006ad0c_checks_1_2_3_4(void);
extern void     MultisquareGlow_8006ada4_Init2(void);
extern void     MultisquareGlow_Deinit_doesnothing(void);
extern void     Multisquares_UpdateGlows(Squares *, u32);
extern void     Multisquares_RenderGlows(Squares *);
extern void     MultisquareGlow_8006aebc_loops_44_times_4(Squares *, u8);

#endif /* !_MULTISQUARE_H_ */
