#ifndef _026C80_H_
#define _026C80_H_

typedef struct {
  /* 0x0 */ u8   unk0;
  /* 0x1 */ u8   unk1;
  /* 0x2 */ u8   unk2;
  /* 0x3 */ u8   unk3;
} UnkStruct_25; // 0x4 bytes

typedef struct {
  /* 0x0  */ UnkStruct_25   unk0[32];
  /* 0x80 */ u32            unk80;       // button mask
  /* 0x84 */ u32            unk84;       // button
  /* 0x88 */ u32            unk88;       // button
  /* 0x8C */ u32            unk8C;       // button
} UnkStruct_1; // 0x90 bytes

extern void   FUN_026900_80060a00_fourliner_sets_arg0_e0123(UnkStruct_25 *, u8, u8);
extern void   FUN_026900_80060a1c_twoliner_sets_arg0_e01(UnkStruct_25 *);
extern s32    FUN_026900_80060a28_twelveliner_retbool(UnkStruct_25 *, s32);
extern void   FUN_026900_80060ad4_oneliner_calls_fun(UnkStruct_1 *);
extern void   FUN_026900_80060b04_twelveliner_loops_32t(UnkStruct_1 *, u32, u8, u8);
extern void   FUN_026900_GU_or_ControllerRepeat_Update(UnkStruct_1 *, u32, u32);
extern void   FUN_026900_nineliner_loops_32t(UnkStruct_1 *);

#endif /* !_026C80_H_ */
