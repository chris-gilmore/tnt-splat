#ifndef _AUDIO_H_
#define _AUDIO_H_

typedef struct {
  /* 0x0 */ u32   freq;
  /* 0x4 */ u32   unk4;
  /* 0x8 */ u32   max_clist_size;  // max Acmd list size
} UnkStruct_93; // 0xC bytes

extern SongPlayer g_songPlayer;

extern void   Audio_InitAudio(void);
extern void   Audio_ChangeSong(s32, SongPlayer *);  // unused
extern void   func_80084C90(s32, SongPlayer *);  // unused
extern void   Audio_FreeAudio(SongPlayer *);  // unused
extern void   Audio_80084e20_twentyliner(s32, SongPlayer *, u8);
extern void   Audio_UnloadSFX(void);
extern void   Audio_LoadSFX(SfxBank *);

#endif /* !_AUDIO_H_ */
