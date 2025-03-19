#ifndef _MULTISQUAREGLOW_H_
#define _MULTISQUAREGLOW_H_

typedef struct {
  /* 0x0 */ u8      is_active;
  /* 0x1 */ u8      size;       // 0:large, 1:medium, 2:small
  /* 0x2 */ u16     val;        // current glow value
  /* 0x4 */ u16     rate;       // glowing rate
  /* 0x6 */ u8      num_steps;  // set to 0x40 (64 jiffies), about a second of glowing
  /* 0x8 */ Point   location;   // upper left corner of glow image
  /* 0xC */ u8      alpha;
} SquareGlow; // 0xE bytes

extern void   MultisquareGlow_8006af00_eightliner(SquareGlow *, s32);
extern void   MultisquareGlow_8006af70_nineliner(SquareGlow *);
extern void   MultisquareGlow_Init(SquareGlow *, Point, u8);
extern void   MultisquareGlow_InitStaticMembers(u8);
extern void   MultisquareGlow_8006b384_oneliner_calls_fun(void);

#endif /* !_MULTISQUAREGLOW_H_ */
