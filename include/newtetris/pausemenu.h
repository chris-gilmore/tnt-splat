#ifndef _PAUSEMENU_H_
#define _PAUSEMENU_H_

#define PAUSEMENU_CONTINUE 1
#define PAUSEMENU_PROGRESS 2
#define PAUSEMENU_EXIT     4

typedef struct UnkStruct_35 UnkStruct_35;
typedef struct UnkStruct_10 UnkStruct_10;

struct UnkStruct_35 {
  /* 0x0  */ s32            x;
  /* 0x4  */ s32            y;
  /* 0x8  */ u8             red;
  /* 0x9  */ u8             green;
  /* 0xA  */ u8             blue;
  /* 0xB  */ u8             alpha;
  /* 0xC  */ f32            unkC;
  /* 0x10 */ f32            unk10;
  /* 0x14 */ u8             unk14;  // boolean
  /* 0x18 */ char          *str;
  /* 0x1C */ Font          *p_font;
  /* 0x20 */ void         (*unk20)(struct UnkStruct_10 *);
  /* 0x24 */ UnkStruct_35  *unk24;  // up
  /* 0x28 */ UnkStruct_35  *unk28;  // down
  /* 0x2C */ UnkStruct_35  *unk2C;  // left
  /* 0x30 */ UnkStruct_35  *unk30;  // right
}; // 0x34 bytes

struct UnkStruct_10 {
  /* 0x0  */ u8             unk0;
  /* 0x1  */ u8             unk1;   // { CONTINUE, PROGRESS, EXIT }
  /* 0x4  */ Font           font;
  /* 0x7C */ u8             unk7C;  // set to 3
  /* 0x80 */ UnkStruct_35  *unk80;  // list of 3
  /* 0x84 */ UnkStruct_35  *unk84;
  /* 0x88 */ u8             unk88;  // boolean
  /* 0x89 */ u8             unk89;  // playernum
}; // 0x8C bytes

extern UnkStruct_10 *D_800D05C0;

extern u8     func_80072140(u8);
extern void   func_800721A4(void);
extern s32    func_800721D8(void);
extern void   func_80072248(void);

#endif /* !_PAUSEMENU_H_ */
