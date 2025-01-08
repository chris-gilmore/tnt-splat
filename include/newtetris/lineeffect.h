#ifndef _LINEEFFECT_H_
#define _LINEEFFECT_H_

typedef struct {
  /* 0x0  */ u8   pad0[0x2E]; // pad0[0x30];
  /* 0x2E */ u16  unk2E;
} LineEffect; // 0x30 bytes

extern u8   LineEffect_Update(LineEffect *, u8);

#endif /* !_LINEEFFECT_H_ */
