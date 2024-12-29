#ifndef _PFGFX_H_
#define _PFGFX_H_

typedef struct {
  /* 0x0 */ u8   pad0[0xB8];
} PfGfx; // 0xB8 bytes

extern PfGfx *g_pfGfx_ptr;

extern void    GameCamera_Render(void);
extern Point  *PFGFX_Init(Point *, PfGfx *);
extern void    PFGFX_Playfield_Init(u8);

#endif /* !_PFGFX_H_ */
