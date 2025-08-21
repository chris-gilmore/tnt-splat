#ifndef _SRAM_H_
#define _SRAM_H_

typedef struct Player Player;
typedef struct PlayerNode PlayerNode;

struct PlayerNode {
  /* 0x0  */ char         name[9];
  /* 0x9  */ u8           salt[2];
  /* 0xB  */ u8           pack;
  /* 0xC  */ Player      *ptr;
  /* 0x10 */ PlayerNode  *next;
  /* 0x14 */ PlayerNode  *last;
}; // 0x18 bytes

struct Player {
  /* 0x0  */ PlayerNode   node;
  /* 0x18 */ u8           pad18[0xA8];
  /* 0xC0 */ u16          time_in_seconds;
  /* 0xC2 */ u16          lines;
  /* 0xC4 */ s32          unkC4;  // lines to dump to game pak
  /* 0xC8 */ s32          unkC8;
  /* 0xCC */ s32          unkCC;
  /* 0xD0 */ u8           unkD0;
  /* 0xD2 */ s16          unkD2;
  /* 0xD4 */ u8           unkD4;
}; // 0xD8 bytes

typedef struct {
  /* 0x0  */ u8       unk0;      // num winners
  /* 0x1  */ u8       unk1[4];   // is a winner
  /* 0x5  */ u8       unk5;      // num players
  /* 0x8  */ u32      unk8[4];   // elapsed time in seconds
  /* 0x18 */ u32      unk18[4];  // line count (score)
  /* 0x28 */ u32      unk28[4];  // lineScan.unk3EC
  /* 0x38 */ u32      unk38;     // total line count / num winners (jackpot)
  /* 0x3C */ Player  *unk3C[4];
} GameResults; // 0x4C bytes

typedef struct {
  /* 0x0 */ u8   unk0[0x6];
  /* 0x6 */ u8   salt[2];
  /* 0x8 */ u8   pad8[0x70];
} UnkStruct_34; // 0x78 bytes

typedef struct {
  /* 0x0    */ u32            unk0;
  /* 0x4    */ UnkStruct_34   unk4[32];
  /* 0xF04  */ u32            total_wonder_lines_odd_bits;
  /* 0xF08  */ u32            total_wonder_lines_even_bits;
  /* 0xF0C  */ u8             padF0C[0x9D8];
  /* 0x18E4 */ u32            music_level;
  /* 0x18E8 */ u32            sfx_level;
  /* 0x18EC */ u32            song;
  /* 0x18F0 */ u32            music_mode;
  /* 0x18F4 */ u32            unk18F4;
  /* 0x18F8 */ u8             pad18F8[0x8];
} Sram; // 0x1900 bytes

extern PlayerNode D_800D2D80;
extern PlayerNode D_800D2D98;
extern PlayerNode D_800D2DB0;
extern PlayerNode D_800D2DC8;  // maybe a better name is TextList?  this variable seems to be related to GUI_Textbox
extern PlayerNode D_800D2DE0;

extern Sram *g_sram_ptr;

extern u8           FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(Player *);  // calculating rank
extern u8           FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(u16, u16);  // calculating rank, too
extern PlayerNode  *FUN_SRAM_8007868c_tenliner_loop_arg0_t(PlayerNode *);
extern void         FUN_SRAM_8007875c_check_gameover_conditions(Player *, GameResults *, u8);
extern void         func_800798F0(Player *, Sram *, u32);
extern u8           func_80079F90(PlayerNode *, PlayerNode *);
extern void         func_8007A078(PlayerNode *, u8);
extern s32          func_8007A5D4(Sram *);
extern void         func_8007A62C(Sram *, s32);
extern void         func_8007A648(Sram *, s32);
extern u32          func_8007A660(Sram *);
extern void         func_8007A6C4(Player *, PlayerNode *, s32);
extern PlayerNode  *func_8007A738(PlayerNode *, u8);
extern PlayerNode  *func_8007AA5C(PlayerNode *, PlayerNode *);
extern u8           func_8007AADC(u8 *, u8, u8);
extern PlayerNode  *func_8007AEB0(PlayerNode *);
extern void         func_8007AF88(Player *, u8 *, s32);
extern void         func_8007B38C(PlayerNode *);
extern void         func_8007B420(Player *);
extern void         func_8007B430(Player *, UnkStruct_34 *, s32);
extern u32          get_total_wonder_lines(Sram *);
extern void         load_from_sram(u8);
extern void         func_8007C5CC(Sram *);  // save_to_sram?

#endif /* !_SRAM_H_ */
