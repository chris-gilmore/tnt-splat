#ifndef _FRAMEACT_H_
#define _FRAMEACT_H_

typedef struct {
  /* 0x0  */ u8             state;
  /* 0x1  */ u8             unk1;
  /* 0x2  */ u8             unk2;  // boolean
  /* 0x3  */ u8             unk3;  // boolean
  /* 0x4  */ PieceHold     *pieceHold_ptr;
  /* 0x8  */ s32           *unk8;
  /* 0xC  */ u8             unkC;  // boolean
  /* 0x10 */ UnkStruct_20   unk10;
} FrameAct; // 0x4C bytes

extern FrameAct *g_frameAct_ptr;

extern void   FrameAct_set_state(u8);
extern void   FrameAct_calls_gamefinish_something2(FrameAct *, s32);
extern void   FrameAct_ScheduleEvents(FrameAct *, u32);
extern void   FrameAct_Render(FrameAct *);
extern void   FrameAct_Init(FrameAct *, PieceHold *, s32 *, BoardInfo *);
extern void   FrameAct_Deinit(FrameAct *);
extern u8     FrameAct_80053EC4_tenliner(s32 *, s32);
extern void   FrameAct_80053F40_oneliner(s32 *, s32);
extern void   FrameAct_Deinit_doesnothing(s32 *);

#endif /* !_FRAMEACT_H_ */
