#ifndef _GARBAGE_H_
#define _GARBAGE_H_

typedef struct {
  /* 0x0 */ u8   pad0[0x24];
} Garbage; // 0x24 bytes

extern Garbage *g_garbage_ptr;

extern void   Garbage_Init(Garbage *, u32 *);
extern void   Garbage_Deinit(Garbage *);
extern void   Garbage_80072e2c_set_arg0p_to_arg1(Garbage *, s8);
extern u8     func_80072F1C(s32);
extern void   func_80072FC4(void);
extern void   func_80073030(u32);

#endif /* !_GARBAGE_H_ */
