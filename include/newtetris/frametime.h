#ifndef _FRAMETIME_H_
#define _FRAMETIME_H_

typedef struct {
  /* 0x0  */ u32   count;
  /* 0x4  */ s32   delta;
  /* 0x8  */ s32   jiffies;
  /* 0xC  */ s32   seconds;
  /* 0x10 */ s32   minutes;
  /* 0x14 */ s32   hours;
} FrameTime; // 0x18 bytes

extern FrameTime g_frameTime;

extern void   frametime_clear(void);
extern void   frametime_reset(u32);
extern void   frametime_add(s32);
extern void   frametime_update(u32);
extern u32    frametime_count(void);
extern s32    frametime_jiffies(void);
extern s32    frametime_seconds(void);
extern s32    frametime_minutes(void);
extern s32    frametime_hours(void);
extern s32    frametime_delta(void);

#endif /* !_FRAMETIME_H_ */
