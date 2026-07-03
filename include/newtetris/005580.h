#ifndef _005580_H_
#define _005580_H_

typedef struct {
  /* 0x0 */ UnkStruct_27   unk0;
  /* 0x3 */ u8             unk3;
} UnkStruct_98; // 0x4 bytes

typedef struct {
  /* 0x0 */ s8             unk0;
  /* 0x1 */ UnkStruct_98   unk1[10];
} UnkStruct_105; // 0x29 bytes

extern void   FUN_005580_8003f760_twoliner_calls_fun(UnkStruct_105 *, u8, s8, u8, u8);
extern s32    FUN_005580_800400fc_largefun_more_currpiece_stuff(UnkStruct_105 *, u8);

#endif /* !_005580_H_ */
