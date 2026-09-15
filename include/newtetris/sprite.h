#ifndef _SPRITE_H_
#define _SPRITE_H_

extern u16 D_800D9190;
extern s32 D_800D9194;

extern void   SetSpriteMode(u16);
extern Gfx   *GetSpriteMode(u16);
extern void   func_800B1BFC(Gfx **, void *, u16 *, u16, u16, f32, f32, u16, u16, u8, u8, u8, u8);
extern void   func_800B2810(Gfx **, void *, UnkStruct_44 *, u16, u16, f32, f32, u16, u16, u8, u8, u8, u8);

#endif /* !_SPRITE_H_ */
