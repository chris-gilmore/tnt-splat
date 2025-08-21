#ifndef _AUDIO_H_
#define _AUDIO_H_

extern UnkStruct_79 D_80120A70;
extern UnkStruct_79 D_80122010;
extern u8 D_801235B0;  // TODO: change u8 to some new struct

extern void   Audio_InitAudio(void);
extern void   Audio_80084e20_twentyliner(s32, UnkStruct_79 *, u8);
extern void   Audio_UnloadSFX(void);
extern void   Audio_LoadSFX(void *);

#endif /* !_AUDIO_H_ */
