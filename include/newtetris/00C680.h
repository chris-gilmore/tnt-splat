#ifndef _00C680_H_
#define _00C680_H_

typedef struct {
  /* 0x0  */ u8             unk0;
  /* 0x1  */ u8             playernum;
  /* 0x2  */ u8             unk2;  // boolean
  /* 0x3  */ s8             cur_screen;
  /* 0x4  */ s8             next_screen;
  /* 0x8  */ UnkStruct_11  *unk8;
  /* 0xC  */ ImgPalParams   imgPalParams[11];
  /* 0xE8 */ Font           font[2];
} WonderViewer; // 0x1D8 bytes

extern void   wonders3_switch_0to7_6and7are_same(void);
extern void   wonders3_switch_0to3_2and3are_same(void);
extern void   wonders3_wonder_viewer(s8, u8, u8);

#endif /* !_00C680_H_ */
