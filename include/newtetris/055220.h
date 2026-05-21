#ifndef _055220_H_
#define _055220_H_

typedef struct {
  /* 0x0    */ u8   *unk0;
  /* 0x4    */ u8    unk4[0x1000];
  /* 0x1004 */ u32   unk1004;
  /* 0x1008 */ u32   unk1008;
  /* 0x100C */ u8    unk100C;
  /* 0x100D */ u8    unk100D;
  /* 0x100E */ u16   unk100E;
} UnkStruct_85; // 0x1010 bytes

extern void   func_8008EFA0(u8 *, UnkStruct_85 *);
extern u8     func_8008F0D0(UnkStruct_85 *);

#endif /* !_055220_H_ */
