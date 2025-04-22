#ifndef _KEYSPIN_H_
#define _KEYSPIN_H_

typedef struct {
  /* 0x0  */ u8    unk0;  // boolean
  /* 0x1  */ u8    unk1;  // boolean
  /* 0x2  */ s8    unk2;
  /* 0x3  */ s8    unk3;
  /* 0x4  */ s8    unk4;
  /* 0x6  */ s16   unk6;
  /* 0x8  */ s16   unk8;
  /* 0xA  */ s16   unkA;
  /* 0xC  */ s16   unkC;
  /* 0xE  */ s8    unkE;
  /* 0xF  */ s8    unkF;
  /* 0x10 */ u8    unk10;  // boolean
  /* 0x11 */ u8    unk11;  // boolean
  /* 0x12 */ u8    unk12;  // boolean
  /* 0x13 */ u8    unk13;  // boolean
} UnkStruct_19; // 0x14 bytes

typedef struct {
  /* 0x0 */ u8   unk0;  // boolean
  /* 0x1 */ s8   unk1;
  /* 0x2 */ s8   unk2;
  /* 0x3 */ u8   unk3;  // boolean
  /* 0x4 */ u8   unk4;  // boolean
  /* 0x5 */ u8   unk5;
  /* 0x6 */ u8   unk6;
  /* 0x7 */ u8   unk7;
  /* 0x8 */ u8   unk8;
} UnkStruct_36; // 0x9 bytes

typedef struct {
  /* 0x0 */ u8   unk0;  // boolean
  /* 0x1 */ s8   unk1;
  /* 0x2 */ s8   unk2;
  /* 0x3 */ u8   unk3;
  /* 0x4 */ s8   unk4;
  /* 0x5 */ s8   unk5;
} UnkStruct_37; // 0x6 bytes

typedef struct {
  /* 0x0  */ u8             unk0;
  /* 0x1  */ u8             unk1;
  /* 0x2  */ u8             unk2;
  /* 0x4  */ CurrentPiece  *currentPiece_ptr;
  /* 0x8  */ UnkStruct_19   unk8[4];
  /* 0x58 */ u8             unk58;
  /* 0x59 */ UnkStruct_36   unk59;
  /* 0x62 */ UnkStruct_37   unk62;
} UnkStruct_9; // 0x68 bytes

extern UnkStruct_9 *D_8011FBC0;

extern u8   KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35(UnkStruct_9 *, s32);

#endif /* !_KEYSPIN_H_ */
