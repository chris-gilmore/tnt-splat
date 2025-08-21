#ifndef _04BFD0_H_
#define _04BFD0_H_

typedef struct {
  /* 0x0    */ u8   pad0[0x1599];
  /* 0x1599 */ u8   unk1599;
  /* 0x159A */ u8   pad159A[0x6];
} UnkStruct_79; // 0x15A0 bytes

extern s32 D_800D3988;  // TODO: change s32 to some new struct
extern s32 D_800D3A90;  // TODO: change s32 to some new struct

extern void   func_800875E4(s32);
extern void   func_800875EC(u16, UnkStruct_79 *);
extern void   Audio2_80087618_fourteenliner_loops_256t(u16);
extern void   Audio2_80087770_oneliner_turn_on(UnkStruct_79 *);
extern void   Audio2_8008777c_oneliner_turn_off(UnkStruct_79 *);
extern void   Audio2_GFXDone_SendPlayMessage(void *);
extern void   Audio2_8008780c_sixliner_v1(void *);
extern void   Audio2_GFXDone_SendStopMessage(void *);
extern void  *Audio2_Play_SFX(void *, s32 *, u8);

#endif /* !_04BFD0_H_ */
