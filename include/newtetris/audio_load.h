#ifndef _AUDIO_LOAD_H_
#define _AUDIO_LOAD_H_

extern Acmd  *h2oRaw16Pull(void *, s16 *, s32, s32, Acmd *);
extern Acmd  *h2oRaw8Pull(void *, s16 *, s32, s32, Acmd *);
extern s32    h2oLoadParam(void *, s32, void *);

#endif /* !_AUDIO_LOAD_H_ */
