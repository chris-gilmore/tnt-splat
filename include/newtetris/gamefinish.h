#ifndef _GAMEFINISH_H_
#define _GAMEFINISH_H_

#define GAMEFINISHTYPE_WIN        0
#define GAMEFINISHTYPE_LOSE       1
#define GAMEFINISHTYPE_GAMEOVER   2
#define GAMEFINISHTYPE_NULL       3

/*
  In 0449D0.c

  void func_8007FBB0(u8 **arg0, s32 arg1) {
    main_8004A34C_threeliner();
    *arg0 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg1));
    FUN_03A750_800746c0_twentyliner(&D_273A00, *arg0, arg1);
  }
*/

typedef struct {
  /* 0x0 */ u16   width;
  /* 0x2 */ u16   height;
  //  /* 0x4 */ u8   *data;
} UnkStruct_21; // 0x4 bytes
// ImageAsset maybe?

typedef struct {
  /* 0x0  */ UnkStruct_21  *image;
  /* 0x4  */ Point          image_loc;  // win/lose/game_over image location (top-left point)
  /* 0x8  */ Point          center_of_board;
  /* 0xC  */ u16            unkC;
  /* 0xE  */ s16            unkE;
  /* 0x10 */ s16            unk10;
  /* 0x12 */ s16            unk12;
  /* 0x14 */ s16            unk14;  // alpha
  /* 0x16 */ s16            unk16;
} UnkStruct_7; // 0x18 bytes

typedef struct {
  /* 0x0  */ u8            state;
  /* 0x1  */ u8            unk1;     // boolean
  /* 0x4  */ s32           unk4;
  /* 0x8  */ s32           unk8;
  /* 0xC  */ UnkStruct_2   unkC;
  /* 0x18 */ u8            unk18;    // boolean
  /* 0x1C */ s32           gf_type;
  /* 0x20 */ UnkStruct_7   unk20;
  /* 0x38 */ u8            unk38;    // boolean
} UnkStruct_20; // 0x3C bytes

extern void   gamefinish_80052D48_twoliner(UnkStruct_20 *);
extern u8     gamefinish_c_line_383(UnkStruct_20 *, u32);
extern void   gamefinish_80053280_twoliner(UnkStruct_20 *);
extern void   gamefinish_800532DC_nevercalled(UnkStruct_20 *);
extern void   gamefinish_something2(UnkStruct_20 *, s32, u8);
extern void   gamefinish_80053390_fiveliner(UnkStruct_20 *, BoardInfo *);
extern void   gamefinish_80053400_fiveliner(UnkStruct_20 *);
extern void   gamefinish_8005344C_fiveliner(u8);
extern void   gamefinish_800534A4_fiveliner(void);

#endif /* !_GAMEFINISH_H_ */
