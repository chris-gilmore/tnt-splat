#ifndef _LINEEFFECT_H_
#define _LINEEFFECT_H_

typedef struct {
  /* 0x0 */ u8     state;
  /* 0x1 */ u8     type;
  /* 0x2 */ u8     unk2;  // bool
  /* 0x3 */ u8     unk3;  // bool
  /* 0x4 */ u8     unk4;
  /* 0x5 */ u8     col_step;
  /* 0x8 */ Cell  *cells[10];
} LineEffect; // 0x30 bytes

extern u8     LineEffect_Update(LineEffect *, u8);
extern void   LineEffect_80069668_fourliner_sets_arg0_struct_v1(LineEffect *);
extern void   LineEffect_Init(LineEffect *, s32, u8);

#endif /* !_LINEEFFECT_H_ */
