#ifndef _KEYSPIN_H_
#define _KEYSPIN_H_

typedef struct {
  /* 0x0 */ u8   pad0[0x14];
} UnkStruct_19; // 0x14 bytes

typedef struct {
  /* 0x0  */ u8             unk0;
  /* 0x1  */ u8             unk1;
  /* 0x2  */ u8             unk2;
  /* 0x4  */ CurrentPiece  *currentPiece_ptr;
  /* 0x8  */ UnkStruct_19   unk8[4];
  /* 0x58 */ u8             pad58[0x10];
} UnkStruct_9; // 0x68 bytes

extern UnkStruct_9 *D_8011FBC0;

extern u8   KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35(UnkStruct_9 *, s32);

#endif /* !_KEYSPIN_H_ */
