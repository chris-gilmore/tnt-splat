#ifndef _GAME_H_
#define _GAME_H_

typedef struct {
  /* 0x0    */ u8             unk0;
  /* 0x1    */ u8             unk1;
  /* 0x2    */ u8             is_active;
  /* 0x3    */ u8             unk3;
  /* 0x4    */ u8             unk4;
  /* 0x5    */ u8             numPlayers;
  /* 0x6    */ u8             unk6;
  /* 0x7    */ u8             unk7;     // 120 jiffies (2 seconds delay after end of game before you can exit)
  /* 0x8    */ Font           font;
  /* 0x80   */ CubeTiles      cubeTiles;
  /* 0xE080 */ UnkStruct_21   unkE080;  // light source (128x128)
  /* 0xE0E8 */ Landfill       landfill;
  /* 0xE12C */ Tetris        *tetris_ptr_arr[4];
  /* 0xE13C */ u8             padE13C[0x3AC];
  /* 0xE4E8 */ u32            unkE4E8;  // gameElapsedTime (in jiffies)
  /* 0xE4EC */ u8             gameType;
  /* 0xE4F0 */ u32            unkE4F0;  // 10800 jiffies (3 minutes sprint goal)
  /* 0xE4F4 */ u32            unkE4F4;  // 150 (ultra goal)
  /* 0xE4F8 */ u8             unkE4F8;  // screen (0 to 7)
  /* 0xE4FC */ UnkStruct_2    unkE4FC;  // (Game_80051618_twentyliner)
  /* 0xE508 */ u8             unkE508;  // (Game_80051618_twentyliner)
  /* 0xE509 */ u8             unkE509;
  /* 0xE50A */ u8             unkE50A;  // a playerNum (set in Game_game_over_related)
  /* 0xE50B */ u8             topOutOrder[4];
  /* 0xE50F */ u8             topOutCount;
} Game; // 0xE510 bytes

extern u8 D_800CFF00[];
extern u8 D_800CFF50;
extern Game g_game;

extern u8     Game_calls_SETGP_magic_7(Game *);
extern u8     Game_isGameWinner(Game *, u8);
extern s32    Game_countWinners(Game *);
extern void   Game_80051618_twentyliner(Game *);
extern void   Game_line_782_game_c(Game *);
extern void   Game_render_stuff_line_850(Game *);
extern void   Game_Init(u8, u8 *);
extern void   Game_Deinit(void);

#endif /* !_GAME_H_ */
