#ifndef _SRAM_H_
#define _SRAM_H_

#define SRAM_PLAYER_SZ 120

typedef struct {
  /* 0x0  */ s32   unk0;
  /* 0x4  */ s32   unk4;
  /* 0x8  */ s32   unk8;
  /* 0xC  */ u8   *unkC;
  /* 0x10 */ s32   unk10;
  /* 0x14 */ s32   unk14;
} UnkStruct_115; // 0x18 bytes

typedef struct {
  /* 0x0  */ char   name[9];
  /* 0x9  */ u8     unk9;   // unused?
  /* 0xA  */ u8     unkA;   // salt[0]
  /* 0xB  */ u8     unkB;   // salt[1]
  /* 0xC  */ u32    unkC;   // lines
  /* 0x10 */ u32    unk10;  // time_in_seconds
  /* 0x14 */ u16    unk14;  // rank time_in_seconds
  /* 0x16 */ u16    unk16;  // rank lines
} GlobalScore; // 0x18 bytes
// TODO: is this UnkStruct_3 ?

typedef struct {
  /* 0x0  */ u32   unk0[5];   // lines
  /* 0x14 */ u32   unk14[5];  // lines
  /* 0x28 */ u32   unk28[5];  // time_in_seconds
} PlayerScores; // 0x3C bytes

typedef struct {
  /* 0x0  */ char           name[9];
  /* 0x9  */ u8             salt[2];
  /* 0xB  */ u8             pack;
  /* 0xC  */ PlayerScores   marathon_scores;
  /* 0x48 */ PlayerScores   ultra_scores;
  /* 0x84 */ PlayerScores   sprint_scores;
  /* 0xC0 */ u16            time_in_seconds;
  /* 0xC2 */ u16            lines;
  /* 0xC4 */ s32            unkC4;  // lines to dump to game pak
  /* 0xC8 */ s32            unkC8;
  /* 0xCC */ s32            unkCC;
  /* 0xD0 */ u8             unkD0;  // boolean
  /* 0xD2 */ u16            unkD2;  // checksum
  /* 0xD4 */ u8             unkD4;  // pack
} Player; // 0xD8 bytes

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
  /* 0x0  */ char   name[9];
  /* 0x9  */ u8     unk9;  // unused?
  /* 0xA  */ u8     unkA;  // salt[0]
  /* 0xB  */ u8     unkB;  // salt[1]
  /* 0xC  */ u32    lines;
  /* 0x10 */ u32    unk10;
  /* 0x14 */ u16    unk14;
  /* 0x16 */ u16    unk16;
} UnkStruct_3; // 0x18 bytes

typedef struct {
  /* 0x0 */ UnkStruct_3   contributors[10];
} Contributions; // 0xF0 bytes

typedef struct {
  /* 0x0    */ u32             bitpattern;
  /* 0x4    */ u8              players[32 * 120];  // 32 * SRAM_PLAYER_SZ
  /* 0xF04  */ u32             total_wonder_lines_odd_bits;
  /* 0xF08  */ u32             total_wonder_lines_even_bits;
  /* 0xF0C  */ GlobalScore     global_marathon[5];
  /* 0xF84  */ GlobalScore     global_ultra[5];
  /* 0xFFC  */ GlobalScore     global_sprint[5];
  /* 0x1074 */ Contributions   contributions[7];
  /* 0x1704 */ UnkStruct_3     unk1704[20];
  /* 0x18E4 */ u32             music_level;
  /* 0x18E8 */ u32             sfx_level;
  /* 0x18EC */ u32             song;
  /* 0x18F0 */ u32             music_mode;
  /* 0x18F4 */ u32             game_id;
  /* 0x18F8 */ char            version[4];
  /* 0x18FC */ u32             chksum;
} Sram; // 0x1900 bytes

extern Sram *g_sram_ptr;

extern TextList D_800D2D80;   // "GUEST"
extern TextList D_800D2D98;   // "NEW NAME"
extern TextList D_800D2DB0;   // "GLOBAL"
extern TextList D_800D2DC8;   // " "
extern TextList D_800D2DE0;   // "CHOOSE"
extern TextList *D_800D2DF8;  // unused
extern u16 D_800D2E1C;

extern u8              FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(Player *);  // calculating rank
extern u8              FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(u16, u16);  // calculating rank, too
extern TextList       *FUN_SRAM_80078534_tenliner_loops(TextList *, u8);
extern void            FUN_SRAM_800785e0_sixliner_loop_arg0_t(TextList *);
extern TextList       *FUN_SRAM_8007868c_tenliner_loop_arg0_t(TextList *);
extern void            FUN_SRAM_8007875c_check_gameover_conditions(Player *, GameResults *, u8);
extern void            func_800798F0(Player *, Sram *, u32);
extern Contributions  *func_80079F74(Sram *, u8);
extern u8              func_80079F90(TextList *, TextList *);
extern void            func_8007A078(TextList *, u8);
extern s8              func_8007A4A0(u8 *);  // unused
extern void            func_8007A508(u8 *, u8);  // unused
extern void            func_8007A538(u8 *, u8);  // unused
extern u32             func_8007A564(u8 *);  // unused
extern s32             func_8007A5D4(Sram *);
extern void            func_8007A62C(Sram *, s32);
extern void            func_8007A648(Sram *, s32);
extern u32             func_8007A660(Sram *);
extern void            func_8007A6C4(Player *, TextList *, u8);
extern TextList       *func_8007A738(TextList *, u8);
extern void            func_8007AA50(s32, s32);  // unused
extern TextList       *func_8007AA5C(TextList *, Player *);
extern u8              func_8007AADC(u8 *, u8, u8);
extern TextList       *func_8007AEB0(TextList *);
extern void            func_8007AF88(Player *, u8 *, s32);
extern void            func_8007B38C(TextList *);
extern void            func_8007B420(Player *);
extern void            func_8007B430(Player *, u8 *, s32);
extern void            func_8007BA84(u8 *, SuperThread *);  // unused
extern u32             get_total_wonder_lines(Sram *);
extern void            load_from_sram(u8);
extern void            save_to_sram(Sram *);

#endif /* !_SRAM_H_ */
