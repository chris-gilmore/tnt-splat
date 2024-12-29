#ifndef _GAMEVARS_H_
#define _GAMEVARS_H_

#define GAMETYPE_MARATHON   0
#define GAMETYPE_SPRINT     1
#define GAMETYPE_ULTRA      2

/*
   From Game_Init(u8 numPlayers, u8 playerHandicaps[])

    u8 sp5E;      0xA   game.unkE4EC  // gameType
    u8 sp5D;      0x9   handicap
    u8 sp5C;      0x8   game.unkE4F8
    void *sp58;   0x4   &game + 0xE080
    u32 sp54;     0x0   seed
*/
typedef struct {
  /* 0x0 */ u32    seed;
  /* 0x4 */ void  *unk4;      // &game + 0xE080
  /* 0x8 */ u8     unk8;      // game.unkE4F8
  /* 0x9 */ u8     handicap;
  /* 0xA */ u8     gameType;  // game.unkE4EC
} GameVars; // 0xB bytes

extern u8 g_playercount;
extern u8 g_currentplayer;

#endif /* !_GAMEVARS_H_ */
