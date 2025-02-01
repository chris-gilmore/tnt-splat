#ifndef _0379B0_H_
#define _0379B0_H_

typedef struct {
  /* 0x0  */ u8     unk0;
  /* 0x1  */ u8     unk1;
  /* 0x2  */ u8     pad2[0x7A];
  /* 0x7C */ s32    unk7C;
  /* 0x80 */ void  *unk80;
  /* 0x84 */ u8     pad84[0x4];
  /* 0x88 */ u8     unk88;
  /* 0x89 */ u8     unk89;
} UnkStruct_10; // 0x8C bytes

//UnkStruct_10 *D_800D05C0 = NULL;
extern UnkStruct_10 *D_800D05C0;

extern u8     func_80072140(u8);
extern void   func_800721A4(void);
extern u8     func_800721D8(void);
extern void   func_80072248(void);

#endif /* !_0379B0_H_ */
