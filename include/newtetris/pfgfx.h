#ifndef _PFGFX_H_
#define _PFGFX_H_

typedef struct {
  /* 0x0  */ s16     pad0[0x58];
  /* 0xB0 */ Point   unkB0;  // player-specific playfield location
  /* 0xB4 */ u8      padB4[0x4];
} PfGfx; // 0xB8 bytes

typedef struct {
  /* 0x0 */ Point   unk0;  // top nextpiece
  /* 0x4 */ Point   unk4;  // bottom nextpiece
} UnkStruct_26; // 0x8 bytes

extern PfGfx *g_pfGfx_ptr;

extern void    PFGFX_Sets_x58_x59_Checks_NumPlayers_CurrPlayer(void);
extern void    GameCamera_Render(void);
extern Point  *PFGFX_Init(Point *, PfGfx *);
extern void    PFGFX_Playfield_Init(u8);
extern void    PFGFX_80060654_doesnothing(void);

#endif /* !_PFGFX_H_ */
