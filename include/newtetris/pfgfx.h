#ifndef _PFGFX_H_
#define _PFGFX_H_

typedef struct {
  /* 0x0  */ u8      pad0[0xB0];
  /* 0xB0 */ Point   unkB0;  // player-specific playfield location
  /* 0xB4 */ u8      padB4[0x4];
} PfGfx; // 0xB8 bytes

typedef struct {
  /* 0x0 */ Point   unk0;  // top lookahead
  /* 0x4 */ Point   unk4;  // bottom lookahead
} UnkStruct_26; // 0x8 bytes

typedef struct {
  /* 0x0 */ Point   unk0;  // top lookahead
  /* 0x4 */ Point   unk4;  // middle lookahead
  /* 0x8 */ Point   unk8;  // bottom lookahead
} UnkStruct_10; // 0xC bytes

extern PfGfx *g_pfGfx_ptr;

extern void    GameCamera_Render(void);
extern Point  *PFGFX_Init(Point *, PfGfx *);
extern void    PFGFX_Playfield_Init(u8);

#endif /* !_PFGFX_H_ */
