#ifndef _04BFD0_H_
#define _04BFD0_H_

extern s32 D_800D3A90;  // TODO: change s32 to some new struct

extern void   Audio2_GFXDone_SendPlayMessage(void *);
extern void   Audio2_8008780c_sixliner_v1(void *);
extern void   Audio2_GFXDone_SendStopMessage(void *);
extern void  *Audio2_Play_SFX(void *, s32 *, u8);

#endif /* !_04BFD0_H_ */
