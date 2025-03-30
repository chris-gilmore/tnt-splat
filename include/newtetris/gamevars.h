#ifndef _GAMEVARS_H_
#define _GAMEVARS_H_

#define GAMETYPE_MARATHON   0
#define GAMETYPE_SPRINT     1
#define GAMETYPE_ULTRA      2

typedef struct {
  /* 0x0 */ u32           seed;
  /* 0x4 */ UnkStruct_0  *unk4;
  /* 0x8 */ u8            screen;
  /* 0x9 */ u8            handicap;
  /* 0xA */ u8            gameType;
} GameVars; // 0xB bytes

extern u8 g_playercount;
extern u8 g_currentplayer;

#endif /* !_GAMEVARS_H_ */
