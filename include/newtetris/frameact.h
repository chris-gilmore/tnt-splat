#ifndef _FRAMEACT_H_
#define _FRAMEACT_H_

typedef struct {
  /* 0x0  */ u8             unk0;
  /* 0x1  */ u8             unk1;
  /* 0x2  */ u8             unk2;  // boolean
  /* 0x3  */ u8             unk3;  // boolean
  /* 0x4  */ PieceHold     *pieceHold_ptr;
  /* 0x8  */ s32           *unk8;
  /* 0xC  */ u8             unkC;  // boolean
  /* 0x10 */ UnkStruct_20   unk10;
} UnkStruct_6; // 0x4C bytes

extern UnkStruct_6 *D_8011F220;

extern void   FrameAct_set_DAT_8011f220(u8);
extern void   FrameAct_calls_gamefinish_something2(UnkStruct_6 *, s32);
extern void   FrameAct_ScheduleEvents(UnkStruct_6 *, u32);
extern void   FrameAct_Render(UnkStruct_6 *);
extern void   FrameAct_Init(UnkStruct_6 *, PieceHold *, s32 *, BoardInfo *);
extern void   FrameAct_Deinit(UnkStruct_6 *);
extern u8     FrameAct_80053EC4_tenliner(s32 *, s32);
extern void   FrameAct_80053F40_oneliner(s32 *, s32);
extern void   FrameAct_Deinit_doesnothing(s32 *);

#endif /* !_FRAMEACT_H_ */
