#include "common.h"

Sram *g_sram_ptr;
static s32 D_8011FCF4;
static s32 D_8011FCF8;
static s32 D_8011FCFC;
static u8 D_8011FD00;

TextList D_800D2D80 = {
  { 'G', 'U', 'E', 'S', 'T', 0, 0, 0, 0 },
  { 32, 32 },
  14,
  NULL,
  &D_800D2D98,
  &D_800D2D98
};
TextList D_800D2D98 = {
  { 'N', 'E', 'W', ' ', 'N', 'A', 'M', 'E', 0 },
  { 32, 32 },
  15,
  NULL,
  &D_800D2D80,
  &D_800D2D80
};
TextList D_800D2DB0 = {
  { 'G', 'L', 'O', 'B', 'A', 'L', 0, 0, 0 },
  { 32, 32 },
  9,
  NULL,
  &D_800D2DB0,
  &D_800D2DB0
};
TextList D_800D2DC8 = {
  { ' ', 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0 },
  5,
  NULL,
  &D_800D2DC8,
  &D_800D2DC8
};
TextList D_800D2DE0 = {
  { 'C', 'H', 'O', 'O', 'S', 'E', 0, 0, 0 },
  { 0xFF, 0xFF },
  4,
  NULL,
  &D_800D2DE0,
  &D_800D2DE0
};
TextList *D_800D2DF8 = &D_800D2D98;  // unused
static u8 D_800D2DFC[30] = {
  3, 7, 10, 13, 17, 20, 23, 27, 30, 33,
  37, 40, 43, 47, 50, 53, 57, 60, 63, 67,
  70, 73, 77, 80, 83, 87, 90, 93, 97, 100
};
u16 D_800D2E1C = 0;
static char *D_800D2E20[8][9] = {
  {
    "CHIXULUB",
    "AHPOP",
    "PASCAL",
    "BALAM",
    "NACHANCAN",
    "MALINALI",
    "IXCHUP",
    "CHIXULUB",
    "CHIXULUB",
  },
  {
    "BARDAS",
    "AETHON",
    "HEKTOR",
    "PELONUS",
    "CYZICUS",
    "ERIS",
    "IOLA",
    "THESSALA",
    "HERCULES",
  },
  {
    "ANKHEF",
    "GENUBATH",
    "INARUS",
    "SENEMUT",
    "INHAPI",
    "MAYATI",
    "NEFERET",
    "TAIS",
    "KHEFRON",
  },
  {
    "ANGUS",
    "MCBAIN",
    "LIAM",
    "MALACHY",
    "BRIANA",
    "CATHAL",
    "GRAINNE",
    "MAIRE",
    "ANGUS",
  },
  {
    "AHJMED",
    "HACHIM",
    "KHALED",
    "TAHAR",
    "BOUCHRA",
    "NAJET",
    "SAGIRAH",
    "ZAHRA",
    "MBELE",
  },
  {
    "YOSUKE",
    "TOSHIO",
    "RINTARO",
    "MASARU",
    "FUMIKO",
    "KAZUMI",
    "HOSHIKO",
    "SAKUKO",
    "LUPIN",
  },
  {
    "IVAN",
    "YURI",
    "ALEXI",
    "LENIN",
    "BORIS",
    "IVAN",
    "IVAN",
    "IVAN",
    "IVAN",
  },
  {
    "MARTIST",
    "FYSX",
    "TRUBADOR",
    "RAPTOR",
    "LUPIN",
    "FREERAD",
    "GRANOLA",
    "ZUUL",
    "ORION",
  },
};
static u32 D_800D2F40[] = {
  0x0,
  0x1,
  0x3,
  0x7,
  0xF,
  0x1F,
  0x3F,
  0x7F,
  0xFF,
  0x1FF,
  0x3FF,
  0x7FF,
  0xFFF,
  0x1FFF,
  0x3FFF,
  0x7FFF,
  0xFFFF,
  0x1FFFF,
  0x3FFFF,
  0x7FFFF,
  0xFFFFF,
  0x1FFFFF,
  0x3FFFFF,
  0x7FFFFF,
  0xFFFFFF,
  0x1FFFFFF,
  0x3FFFFFF,
  0x7FFFFFF,
  0xFFFFFFF,
  0x1FFFFFFF,
  0x3FFFFFFF,
  0x7FFFFFFF,
  0xFFFFFFFF,
};
static s32 D_800D2FC4[] = { 500, 400, 300, 200, 100 };  // global marathon lines
static s32 D_800D2FD8[] = { 150, 150, 150, 150, 150 };  // global ultra lines
static s32 D_800D2FEC[] = { 70, 60, 40, 30, 20 };       // global sprint lines
static s32 D_800D3000[] = { 500, 400, 300, 200, 100 };  // global marathon time
static s32 D_800D3014[] = { 120, 180, 240, 300, 360 };  // global ultra time
static s32 D_800D3028[] = { 180, 180, 180, 180, 180 };  // global sprint time

static void FUN_SRAM_800795d8_fourteenliner_loops_8t(Player *, UnkStruct_3 *, u32, s32);
static s8 func_80079650(Player *, Sram *);
static void func_800796C8(Player *, Sram *, u32, s32);
static void func_8007AB10(u8, TextList *);
static void func_8007B8A8(UnkStruct_115 *, s32, s32);
static s32 func_8007B964(UnkStruct_115 *, s32);
static void func_8007BA38(UnkStruct_115 *);
static void func_8007BB54(u8 *, SuperThread *);
static void set_total_wonder_lines(Sram *, u32);
static u32 sram_chksum(u8 *, u32);
static u16 func_8007BD48(u8 *, u32);
static void func_8007BDD8(Sram *);

// calculating rank
u8 FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(Player *arg0) {
  s32 i;
  s32 lines_per_minute;

  if ((arg0->time_in_seconds != 0) && ((arg0->time_in_seconds / 60) != 0)) {
    lines_per_minute = arg0->lines / (f32) ((f32) arg0->time_in_seconds / 60.0);

    i = 0;
    do {
      if (lines_per_minute < D_800D2DFC[i]) {
        return i;
      }
    } while (++i < 30);

    return 29;
  }

  return 0;
}

// calculating rank, too
u8 FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(u16 time_in_seconds, u16 lines) {
  s32 i;
  s32 lines_per_minute;

  if ((time_in_seconds != 0) && ((time_in_seconds / 60) != 0)) {
    lines_per_minute = lines / (f32) ((f32) time_in_seconds / 60.0);

    i = 0;
    do {
      if (lines_per_minute < D_800D2DFC[i]) {
        return i;
      }
    } while (++i < 30);

    return 29;
  }

  return 0;
}

// unused
TextList *FUN_SRAM_80078534_tenliner_loops(TextList *arg0, u8 arg1) {
  TextList *sp1C;

  sp1C = arg0;
  do {
    if ((sp1C->ptr != NULL) && (((Player *) sp1C->ptr)->unkD4 == arg1)) {
      func_8007AEB0(sp1C);
      if (sp1C == arg0) {
        arg0 = sp1C->next;
      }
      sp1C = arg0;
    }

    sp1C = sp1C->next;
  } while (sp1C != arg0);

  return sp1C;
}

void FUN_SRAM_800785e0_sixliner_loop_arg0_t(TextList *arg0) {
  TextList *sp1C;

  sp1C = arg0;
  do {
    if (((sp1C->pack & 0xF) == 15) || ((sp1C->pack & 0xF) == 14) || ((sp1C->pack & 0xF) == 10) || ((sp1C->pack & 0xF) == 9) || ((sp1C->pack & 0xF) == 8)) {
      // do nothing
    } else if (!((Player *) sp1C->ptr)->unkD0) {
      func_8007AEB0(sp1C);
    }

    sp1C = sp1C->next;
  } while (sp1C != arg0);
}

TextList *FUN_SRAM_8007868c_tenliner_loop_arg0_t(TextList *arg0) {
  TextList *sp1C;
  s32 sp18;

  sp18 = 0;
  sp1C = arg0;
  do {
    if (((sp1C->pack & 0xF) == 15) || ((sp1C->pack & 0xF) == 14) || ((sp1C->pack & 0xF) == 10) || ((sp1C->pack & 0xF) == 9) || ((sp1C->pack & 0xF) == 8) || ((sp1C->pack & 0xF) == 6) || ((sp1C->pack & 0xF) == 5) || ((sp1C->pack & 0xF) == 4) || ((sp1C->pack & 0xF) == 11)) {
      sp18++;
      if (sp18 == 100) {
        break;
      }
    } else {
      func_8007AEB0(sp1C);
    }

    sp1C = sp1C->next;
  } while (sp1C != arg0);

  return sp1C;
}

void FUN_SRAM_8007875c_check_gameover_conditions(Player *player, GameResults *gameResults, u8 arg2) {
  u8 sp3F;  // num winners
  u8 sp3E;  // rank
  s32 sp38;
  s32 sp34;
  s32 sp30;
  GlobalScore *sp2C;
  GlobalScore *sp28;

  sp3F = gameResults->unk0;  // num winners
  sp3E = FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(player);  // rank
  player->time_in_seconds += gameResults->unk8[arg2];
  player->lines += gameResults->unk18[arg2];
  if (player->time_in_seconds >= 900) {  // 15 minutes
    player->lines /= 3;
    player->time_in_seconds /= 3;
  }

  if (player->unkC8 + gameResults->unk28[arg2] < 0x40000000) {
    player->unkC8 += gameResults->unk28[arg2];
  } else {
    player->unkC8 = 0x40000000;
  }

  if (player->unkCC + (gameResults->unk18[arg2] - gameResults->unk28[arg2]) < 0x40000000U) {
    player->unkCC += gameResults->unk18[arg2] - gameResults->unk28[arg2];
  } else {
    player->unkCC = 0x40000000;
  }

  switch (g_game.gameType) {
  case GAMETYPE_MARATHON:
    for (sp38 = 0; sp38 < 5; sp38++) {
      if ((player->marathon_scores.unk0[sp38] + player->marathon_scores.unk14[sp38]) < gameResults->unk18[arg2]) {
        sp34 = 3;
        if (sp38 < 4) {
          do {
            player->marathon_scores.unk0[sp34 + 1] = player->marathon_scores.unk0[sp34];
            player->marathon_scores.unk14[sp34 + 1] = player->marathon_scores.unk14[sp34];
            player->marathon_scores.unk28[sp34 + 1] = player->marathon_scores.unk28[sp34];
          } while (--sp34 >= sp38);
        }
        player->marathon_scores.unk0[sp38] = gameResults->unk28[arg2];
        player->marathon_scores.unk14[sp38] = gameResults->unk18[arg2] - gameResults->unk28[arg2];
        player->marathon_scores.unk28[sp38] = gameResults->unk8[arg2];
        break;
      }
    }

    for (sp38 = 0; sp38 < 5; sp38++) {
      if (g_sram_ptr->global_marathon[sp38].unkC < gameResults->unk18[arg2]) {
        sp34 = 3;
        if (sp38 < 4) {
          do {
            sp2C = &g_sram_ptr->global_marathon[sp34];
            sp28 = &g_sram_ptr->global_marathon[sp34 + 1];
            for (sp30 = 0; sp30 < 8; sp30++) {
              sp28->name[sp30] = sp2C->name[sp30];
            }
            sp28->name[sp30] = '\0';
            sp28->unkA = sp2C->unkA;
            sp28->unkB = sp2C->unkB;
            sp28->unkC = sp2C->unkC;
            sp28->unk10 = sp2C->unk10;
            sp28->unk14 = sp2C->unk14;
            sp28->unk16 = sp2C->unk16;
          } while (--sp34 >= sp38);
        }

        sp2C = &g_sram_ptr->global_marathon[sp38];
        for (sp34 = 0; sp34 < 8; sp34++) {
          sp2C->name[sp34] = player->name[sp34];
        }
        sp2C->name[sp34] = '\0';
        sp2C->unkA = player->salt[0];
        sp2C->unkB = player->salt[1];
        sp2C->unkC = gameResults->unk18[arg2];
        sp2C->unk10 = gameResults->unk8[arg2];
        sp2C->unk14 = player->time_in_seconds;
        sp2C->unk16 = player->lines;
        break;
      }
    }
    break;
  case GAMETYPE_SPRINT:
    if (gameResults->unk8[arg2] >= 179) {
      gameResults->unk8[arg2] = 180;
    }

    if (gameResults->unk8[arg2] >= 180) {
      for (sp38 = 0; sp38 < 5; sp38++) {
        if ((player->sprint_scores.unk0[sp38] + player->sprint_scores.unk14[sp38]) < gameResults->unk18[arg2]) {
          sp34 = 3;
          if (sp38 < 4) {
            do {
              player->sprint_scores.unk0[sp34 + 1] = player->sprint_scores.unk0[sp34];
              player->sprint_scores.unk14[sp34 + 1] = player->sprint_scores.unk14[sp34];
              player->sprint_scores.unk28[sp34 + 1] = player->sprint_scores.unk28[sp34];
            } while (--sp34 >= sp38);
          }
          player->sprint_scores.unk0[sp38] = gameResults->unk28[arg2];
          player->sprint_scores.unk14[sp38] = gameResults->unk18[arg2] - gameResults->unk28[arg2];
          player->sprint_scores.unk28[sp38] = gameResults->unk8[arg2];
          break;
        }
      }

      for (sp38 = 0; sp38 < 5; sp38++) {
        if (g_sram_ptr->global_sprint[sp38].unkC < gameResults->unk18[arg2]) {
          sp34 = 3;
          if (sp38 < 4) {
            do {
              sp2C = &g_sram_ptr->global_sprint[sp34];
              sp28 = &g_sram_ptr->global_sprint[sp34 + 1];
              for (sp30 = 0; sp30 < 8; sp30++) {
                sp28->name[sp30] = sp2C->name[sp30];
              }
              sp28->name[sp30] = '\0';
              sp28->unkA = sp2C->unkA;
              sp28->unkB = sp2C->unkB;
              sp28->unkC = sp2C->unkC;
              sp28->unk10 = sp2C->unk10;
              sp28->unk14 = sp2C->unk14;
              sp28->unk16 = sp2C->unk16;
            } while (--sp34 >= sp38);
          }

          sp2C = &g_sram_ptr->global_sprint[sp38];
          for (sp34 = 0; sp34 < 8; sp34++) {
            sp2C->name[sp34] = player->name[sp34];
          }
          sp2C->name[sp34] = '\0';
          sp2C->unkA = player->salt[0];
          sp2C->unkB = player->salt[1];
          sp2C->unkC = gameResults->unk18[arg2];
          sp2C->unk10 = gameResults->unk8[arg2];
          sp2C->unk14 = player->time_in_seconds;
          sp2C->unk16 = player->lines;
          break;
        }
      }
    }
    break;
  case GAMETYPE_ULTRA:
    if (gameResults->unk18[arg2] >= 150) {
      for (sp38 = 0; sp38 < 5; sp38++) {
        if ((player->ultra_scores.unk28[sp38] > gameResults->unk8[arg2]) || (player->ultra_scores.unk28[sp38] == 0)) {
          sp34 = 3;
          if (sp38 < 4) {
            do {
              player->ultra_scores.unk0[sp34 + 1] = player->ultra_scores.unk0[sp34];
              player->ultra_scores.unk14[sp34 + 1] = player->ultra_scores.unk14[sp34];
              player->ultra_scores.unk28[sp34 + 1] = player->ultra_scores.unk28[sp34];
            } while (--sp34 >= sp38);
          }
          player->ultra_scores.unk0[sp38] = gameResults->unk28[arg2];
          player->ultra_scores.unk14[sp38] = gameResults->unk18[arg2] - gameResults->unk28[arg2];
          player->ultra_scores.unk28[sp38] = gameResults->unk8[arg2];
          break;
        }
      }

      for (sp38 = 0; sp38 < 5; sp38++) {
        if (g_sram_ptr->global_ultra[sp38].unk10 > gameResults->unk8[arg2]) {
          sp34 = 3;
          if (sp38 < 4) {
            do {
              sp2C = &g_sram_ptr->global_ultra[sp34];
              sp28 = &g_sram_ptr->global_ultra[sp34 + 1];
              for (sp30 = 0; sp30 < 8; sp30++) {
                sp28->name[sp30] = sp2C->name[sp30];
              }
              sp28->name[sp30] = '\0';
              sp28->unkA = sp2C->unkA;
              sp28->unkB = sp2C->unkB;
              sp28->unkC = sp2C->unkC;
              sp28->unk10 = sp2C->unk10;
              sp28->unk14 = sp2C->unk14;
              sp28->unk16 = sp2C->unk16;
            } while (--sp34 >= sp38);
        }
        sp2C = &g_sram_ptr->global_ultra[sp38];
          for (sp34 = 0; sp34 < 8; sp34++) {
            sp2C->name[sp34] = player->name[sp34];
          }
          sp2C->name[sp34] = '\0';
          sp2C->unkA = player->salt[0];
          sp2C->unkB = player->salt[1];
          sp2C->unkC = gameResults->unk18[arg2];
          sp2C->unk10 = gameResults->unk8[arg2];
          sp2C->unk14 = player->time_in_seconds;
          sp2C->unk16 = player->lines;
          break;
        }
      }
    }
    break;
  }

  if (gameResults->unk1[arg2] == 1) {
    switch (player->unkD4 & 0xF) {
    case 13:
      func_800798F0(player, g_sram_ptr, gameResults->unk38);
      save_to_sram(g_sram_ptr);
      break;
    case 12:
      if ((player->unkC4 + gameResults->unk38) < 0x100000U) {
        player->unkC4 += gameResults->unk38;
      } else {
        player->unkC4 = 0x100000;
      }
      save_to_sram(g_sram_ptr);
      break;
    default:
      save_to_sram(g_sram_ptr);
      break;
    }
  }
}

static void FUN_SRAM_800795d8_fourteenliner_loops_8t(Player *arg0, UnkStruct_3 *arg1, u32 arg2, s32 arg3) {
  register u8 i;

  for (i = 0; i < 8; i++) {
    arg1->name[i] = arg0->name[i];
  }
  arg1->unkA = arg0->salt[0];
  arg1->unkB = arg0->salt[1];
  arg1->lines += arg2;
  arg1->unk10 += arg3;
  arg1->unk14 = arg0->time_in_seconds;
  arg1->unk16 = arg0->lines;
}

static s8 func_80079650(Player *player, Sram *sram_ptr) {
  s32 i;

  for (i = 0; i < 20; i++) {
    if ((sram_ptr->unk1704[i].unkA == player->salt[0]) && (sram_ptr->unk1704[i].unkB == player->salt[1])) {
      return i;
    }
  }
  return -1;
}

static void func_800796C8(Player *player, Sram *sram_ptr, u32 arg2, s32 arg3) {
  s32 sp2C;
  s32 sp28;
  s32 sp24;
  UnkStruct_3 *sp20;
  UnkStruct_3 *sp1C;

  for (sp2C = 0; sp2C < 20; sp2C++) {
    if ((sram_ptr->unk1704[sp2C].unkA == 0) && (sram_ptr->unk1704[sp2C].unkB == 0)) {
      FUN_SRAM_800795d8_fourteenliner_loops_8t(player, &sram_ptr->unk1704[sp2C], arg2, arg3);
      break;
    }
  }
  if (sp2C != 20) {
    return;
  }

  for (sp2C = 0; sp2C < 20; sp2C++) {
    if (sram_ptr->unk1704[sp2C].lines < arg2) {
      sp28 = 18;
      if (sp2C < 19) {
        do {
          sp20 = &sram_ptr->unk1704[sp28];
          sp1C = &sram_ptr->unk1704[sp28 + 1];
          for (sp24 = 0; sp24 < 8; sp24++) {
            sp1C->name[sp24] = sp20->name[sp24];
          }
          sp1C->unkA = sp20->unkA;
          sp1C->unkB = sp20->unkB;
          sp1C->lines = sp20->lines;
          sp1C->unk10 = sp20->unk10;
          sp1C->unk14 = sp20->unk14;
          sp1C->unk16 = sp20->unk16;
        } while (--sp28 >= sp2C);
      }

      FUN_SRAM_800795d8_fourteenliner_loops_8t(player, &sram_ptr->unk1704[sp2C], arg2, arg3);
      break;
    }
  }
}

void func_800798F0(Player *player, Sram *sram_ptr, u32 arg2) {
  s32 i;
  s32 sp98;
  u32 sp94;
  u32 sp90;
  s8 sp8F;
  s8 sp78[20];
  u32 sp28[20];

  D_8011FCFC = D_800CF838;
  D_8011FCF8 = 1;
  if (D_8011FCFC < 7) {
    do {
      D_8011FCF4 = wonders2_80046388_fiveliner(D_8011FCFC);
      if (arg2 >= D_8011FCF4) {
        arg2 -= D_8011FCF4;
        set_total_wonder_lines(g_sram_ptr, get_total_wonder_lines(g_sram_ptr) + D_8011FCF4);
        sp8F = func_80079650(player, sram_ptr);
        if (sp8F == -1) {
          func_800796C8(player, sram_ptr, D_8011FCF4, 0);
        } else {
          FUN_SRAM_800795d8_fourteenliner_loops_8t(player, &sram_ptr->unk1704[sp8F], D_8011FCF4, 0);
        }

        for (i = 0; i < 20; i++) {
          sp78[i] = -1;
          sp28[i] = sram_ptr->unk1704[i].lines;
        }

        for (i = 0; i < 20; i++) {
          sp94 = 0;
          for (sp98 = 0; sp98 < 20; sp98++) {
            if (sp94 < sp28[sp98]) {
              sp94 = sp28[sp98];
              sp78[i] = sp98;
            }
          }
          sp28[sp78[i]] = 0;
        }

        for (i = 0; i < 10; i++) {
          for (sp90 = 0; sp90 < 8; sp90++) {
            sram_ptr->contributions[D_8011FCFC].contributors[i].name[sp90] = sram_ptr->unk1704[sp78[i]].name[sp90];
          }
          sram_ptr->contributions[D_8011FCFC].contributors[i].unkA = sram_ptr->unk1704[sp78[i]].unkA;
          sram_ptr->contributions[D_8011FCFC].contributors[i].unkB = sram_ptr->unk1704[sp78[i]].unkB;
          sram_ptr->contributions[D_8011FCFC].contributors[i].lines = sram_ptr->unk1704[sp78[i]].lines;
          sram_ptr->contributions[D_8011FCFC].contributors[i].unk10 = sram_ptr->unk1704[sp78[i]].unk10;
          sram_ptr->contributions[D_8011FCFC].contributors[i].unk14 = sram_ptr->unk1704[sp78[i]].unk14;
          sram_ptr->contributions[D_8011FCFC].contributors[i].unk16 = sram_ptr->unk1704[sp78[i]].unk16;
        }

        for (i = 0; i < 20; i++) {
          for (sp90 = 0; sp90 < 8; sp90++) {
            sram_ptr->unk1704[i].name[sp90] = '\0';
          }
          sram_ptr->unk1704[i].unkA = 0;
          sram_ptr->unk1704[i].unkB = 0;
          sram_ptr->unk1704[i].lines = 0;
          sram_ptr->unk1704[i].unk10 = 0;
          sram_ptr->unk1704[i].unk14 = 0;
          sram_ptr->unk1704[i].unk16 = 0;
        }

        if (++D_8011FCFC >= 7) {
          break;
        }
      } else {
        set_total_wonder_lines(g_sram_ptr, get_total_wonder_lines(g_sram_ptr) + arg2);
        sp8F = func_80079650(player, sram_ptr);
        if (sp8F == -1) {
          func_800796C8(player, sram_ptr, arg2, 0);
        } else {
          FUN_SRAM_800795d8_fourteenliner_loops_8t(player, &sram_ptr->unk1704[sp8F], arg2, 0);
        }
        D_8011FCF8 = 0;
        arg2 = 0;
      }
    } while (D_8011FCF8 == 1);
  }

  set_total_wonder_lines(g_sram_ptr, get_total_wonder_lines(g_sram_ptr) + arg2);
}

Contributions *func_80079F74(Sram *sram_ptr, u8 arg1) {
  return &sram_ptr->contributions[arg1];
}

// inserts a TextList node
u8 func_80079F90(TextList *arg0, TextList *arg1) {
  TextList *sp1C;

  for (sp1C = arg0; sp1C->next != arg0; sp1C = sp1C->next) {
    if ((sp1C->salt[0] == arg1->salt[0]) && (sp1C->salt[1]) == arg1->salt[1]) {
      func_8007B420(sp1C->ptr);
      return TRUE;
    }
  }

  arg1->next = arg0->next;
  arg1->last = arg0;
  arg0->next = arg1;
  arg1->next->last = arg1;
  return FALSE;
}

void func_8007A078(TextList *arg0, u8 arg1) {
  TextList *sp2C;
  u16 sp2A;
  u8 sp29;

  if ((&D_800D2D98 == arg0) || (&D_800D2D80 == arg0)) {  // "NEW NAME" || "GUEST"
    sp2A = 0;
    sp2C = n64HeapAlloc(sizeof(TextList));

    D_8011FD00 = 10;
    sp2A = func_800A35EC(0, 0xFF) % ((g_game.unkE4F8 < 7) ? 7 : 9);
    while ((1 << sp2A) & D_800D2E1C) {
      sp2A = func_800A35EC(0, 0xFF) % ((g_game.unkE4F8 < 7) ? 7 : 9);
      if (D_8011FD00-- == 0) {
        sp2A = 0;
        break;
      }
    }

    D_800D2E1C |= 1 << sp2A;
    sprintf(sp2C->text, "%s", D_800D2E20[g_game.unkE4F8][sp2A]);
    sp2C->salt[0] = 0;
    sp2C->salt[1] = 0;
    sp2C->pack = ((1 << arg1) << 4) | 14;
    sp2C->next = NULL;
    sp2C->last = NULL;
    sp2C->ptr = NULL;
    func_8007AB10(arg1, sp2C);

    n64HeapUnalloc(sp2C);
  } else {
    sp29 = (arg0->pack >> 4) & 0xF;
    switch (arg0->pack & 0xF) {
    case 13:
      func_8007AB10(arg1, arg0);
      ((Player *) arg0->ptr)->unkD0 = TRUE;
      arg0->pack &= 0xF;
      break;
    case 11:
      arg0->pack = (sp29 << 4) | 13;
      ((Player *) arg0->ptr)->unkD4 = (sp29 << 4) | 13;
      ((Player *) arg0->ptr)->salt[0] = arg0->salt[0];
      ((Player *) arg0->ptr)->salt[1] = arg0->salt[1];
      func_8007AB10(arg1, arg0);
      func_8007AF88(&g_game.players[arg1], g_sram_ptr->players, func_8007A5D4(g_sram_ptr) * SRAM_PLAYER_SZ);
      func_8007A648(g_sram_ptr, func_8007A5D4(g_sram_ptr));
      save_to_sram(g_sram_ptr);
      break;
    case 12:
      func_8007AB10(arg1, arg0);
      arg0->pack &= 0xF;
      ((Player *) arg0->ptr)->unkD0 = TRUE;
      break;
    }
  }
}

// unused
s8 func_8007A4A0(u8 *arg0) {
  u8 bitpattern;
  s32 i;

  bitpattern = arg0[g_eepromSize - 1];
  for (i = 0; i < 32; i++) {
    if (!(bitpattern & (1 << i))) {
      return i;
    }
  }
  return -1;
}

// unused
void func_8007A508(u8 *arg0, u8 arg1) {
  arg0[g_eepromSize - 1] = arg0[g_eepromSize - 1] & ~(1 << arg1);
}

// unused
void func_8007A538(u8 *arg0, u8 arg1) {
  arg0[g_eepromSize - 1] = arg0[g_eepromSize - 1] | (1 << arg1);
}

// unused
u32 func_8007A564(u8 *arg0) {
  u8 bitpattern;
  s32 i;
  u8 cnt;

  bitpattern = arg0[g_eepromSize - 1];
  for (i = 0, cnt = 0; i < 32; i++) {
    if (bitpattern & (1 << i)) {
      cnt++;
    }
  }
  return cnt;
}

s32 func_8007A5D4(Sram *sram_ptr) {
  u32 bitpattern = sram_ptr->bitpattern;
  s32 i;

  for (i = 0; i < 32; i++) {
    if (!(bitpattern & (1 << i))) {
      return i;
    }
  }
  return -1;
}

void func_8007A62C(Sram *sram_ptr, s32 arg1) {
  sram_ptr->bitpattern &= ~(1 << arg1);
}

void func_8007A648(Sram *sram_ptr, s32 arg1) {
  sram_ptr->bitpattern |= 1 << arg1;
}

u32 func_8007A660(Sram *sram_ptr) {
  u32 bitpattern = sram_ptr->bitpattern;
  u32 i;
  u32 cnt;

  for (i = 0, cnt = 0; i < 32; i++) {
    if (bitpattern & (1 << i)) {
      cnt++;
    }
  }
  return cnt;
}

void func_8007A6C4(Player *arg0, TextList *arg1, u8 arg2) {
  s32 i;

  for (i = 0; i < 8; i++) {
    arg1->text[i] = arg0->name[i];
  }
  arg1->text[8] = 0;

  arg1->salt[0] = arg0->salt[0];
  arg1->salt[1] = arg0->salt[1];
  arg1->ptr = arg0;
  arg1->pack = arg2;
  ((Player *) arg1->ptr)->unkD4 = arg2;

  arg1->next = NULL;
  arg1->last = NULL;
}

// creates a TextList node
TextList *func_8007A738(TextList *arg0, u8 arg1) {
  s32 i;
  TextList *sp30;
  Player *player;

  sp30 = n64HeapAlloc(sizeof(TextList));
  sp30->ptr = n64HeapAlloc(sizeof(Player));
  player = (Player *) sp30->ptr;

  sp30->salt[0] = (u32) OS_CYCLES_TO_NSEC(osGetTime()) >> 4;
  sp30->salt[1] = func_800A35EC(0, 0xFF);  // random byte
  sp30->pack = ((1 << arg1) << 4) | 11;

  sp30->text[0] = 'A';
  sp30->text[1] = '\0';
  sp30->text[2] = '\0';
  sp30->text[3] = '\0';
  sp30->text[4] = '\0';
  sp30->text[5] = '\0';
  sp30->text[6] = '\0';
  sp30->text[7] = '\0';
  sp30->text[8] = '\0';

  sp30->next = NULL;
  sp30->last = NULL;

  player->salt[0] = sp30->salt[0];
  player->salt[1] = sp30->salt[1];

  player->name[0] = '\0';
  player->name[1] = '\0';
  player->name[2] = '\0';
  player->name[3] = '\0';
  player->name[4] = '\0';
  player->name[5] = '\0';
  player->name[6] = '\0';
  player->name[7] = '\0';
  player->name[8] = '\0';

  player->pack = 0;

  for (i = 0; i < 5; i++) {
    player->marathon_scores.unk0[i] = 0;
    player->marathon_scores.unk14[i] = 0;
    player->marathon_scores.unk28[i] = 0;

    player->ultra_scores.unk0[i] = 0;
    player->ultra_scores.unk14[i] = 0;
    player->ultra_scores.unk28[i] = 0;

    player->sprint_scores.unk0[i] = 0;
    player->sprint_scores.unk14[i] = 0;
    player->sprint_scores.unk28[i] = 0;
  }

  player->time_in_seconds = 0;
  player->lines = 0;
  player->unkC4 = 0;
  player->unkC8 = 0;
  player->unkCC = 0;
  player->unkD0 = FALSE;

  func_80079F90(arg0, sp30);
  return sp30;
}

// unused
void func_8007AA50(s32 arg0, s32 arg1) {
}

TextList *func_8007AA5C(TextList *arg0, Player *arg1) {
  TextList *sp4;

  sp4 = arg0;
  do {
    if ((sp4->salt[0] == arg1->salt[0]) && (sp4->salt[1] == arg1->salt[1]) && (sp4->text[0] == arg1->name[0])) {
      return sp4;
    }
    sp4 = sp4->next;
  } while (sp4 != arg0);

  return NULL;
}

u8 func_8007AADC(u8 *arg0, u8 arg1, u8 arg2) {
  if ((arg0[6] == arg1) && (arg0[7] == arg2)) {
    return TRUE;
  } else {
    return FALSE;
  }
}

static void func_8007AB10(u8 arg0, TextList *arg1) {
  s32 i;
  Player *player;

  player = &g_game.players[arg0];

  for (i = 0; i < 8; i++) {
    player->name[i] = arg1->text[i];
  }
  player->name[8] = 0;

  player->salt[0] = arg1->salt[0];
  player->salt[1] = arg1->salt[1];
  player->unkD4 = arg1->pack;

  if (arg1->ptr != NULL) {
    player->pack = ((Player *) arg1->ptr)->pack;

    for (i = 0; i < 5; i++) {
      player->marathon_scores.unk0[i] = ((Player *) arg1->ptr)->marathon_scores.unk0[i];
      player->marathon_scores.unk14[i] = ((Player *) arg1->ptr)->marathon_scores.unk14[i];
      player->marathon_scores.unk28[i] = ((Player *) arg1->ptr)->marathon_scores.unk28[i];
      player->ultra_scores.unk0[i] = ((Player *) arg1->ptr)->ultra_scores.unk0[i];
      player->ultra_scores.unk14[i] = ((Player *) arg1->ptr)->ultra_scores.unk14[i];
      player->ultra_scores.unk28[i] = ((Player *) arg1->ptr)->ultra_scores.unk28[i];
      player->sprint_scores.unk0[i] = ((Player *) arg1->ptr)->sprint_scores.unk0[i];
      player->sprint_scores.unk14[i] = ((Player *) arg1->ptr)->sprint_scores.unk14[i];
      player->sprint_scores.unk28[i] = ((Player *) arg1->ptr)->sprint_scores.unk28[i];
    }

    player->time_in_seconds = ((Player *) arg1->ptr)->time_in_seconds;
    player->lines = ((Player *) arg1->ptr)->lines;
    player->unkC4 = ((Player *) arg1->ptr)->unkC4;
    player->unkC8 = ((Player *) arg1->ptr)->unkC8;
    player->unkCC = ((Player *) arg1->ptr)->unkCC;
    player->unkD0 = FALSE;

    return;
  }

  player->pack = 0;

  for (i = 0; i < 5; i++) {
    player->marathon_scores.unk0[i] = 0;
    player->marathon_scores.unk14[i] = 0;
    player->marathon_scores.unk28[i] = 0;
    player->ultra_scores.unk0[i] = 0;
    player->ultra_scores.unk14[i] = 0;
    player->ultra_scores.unk28[i] = 0;
    player->sprint_scores.unk0[i] = 0;
    player->sprint_scores.unk14[i] = 0;
    player->sprint_scores.unk28[i] = 0;
  }

  player->time_in_seconds = 0;
  player->lines = 0;
  player->unkC4 = 0;
  player->unkC8 = 0;
  player->unkCC = 0;
  player->unkD0 = FALSE;
}

// deletes a TextList node and returns its parent
TextList *func_8007AEB0(TextList *arg0) {
  TextList *sp1C;

  if (((arg0->pack & 0xF) != 14) && ((arg0->pack & 0xF) != 15) && ((arg0->pack & 0xF) != 10) && ((arg0->pack & 0xF) != 5)) {
    arg0->last->next = arg0->next;

    if (arg0->next != NULL) {
      arg0->next->last = arg0->last;
    }

    sp1C = arg0->last;

    if (arg0->ptr != NULL) {
      n64HeapUnalloc(arg0->ptr);
      arg0->ptr = NULL;
    }

    n64HeapUnalloc(arg0);
    return sp1C;
  }

  return arg0;
}

void func_8007AF88(Player *arg0, u8 *arg1, s32 arg2) {
  s32 i;
  UnkStruct_115 *sp28;
  register s32 var_s0;

  sp28 = n64HeapAlloc(sizeof(UnkStruct_115));

  sp28->unk0 = 0;
  sp28->unk4 = 8;
  sp28->unk8 = arg2;
  sp28->unkC = arg1;

  arg0->unkD2 = func_8007BD48((u8 *) arg0, 11) & 0xFFFF;

  rmonPrintf("Files: %x\n", g_sram_ptr->bitpattern);

  for (i = 0; i < 8; i++) {
    if (arg0->name[i] != '\0') {
      var_s0 = arg0->name[i] - 32;
    } else {
      var_s0 = arg0->name[i];
    }
    func_8007B8A8(sp28, (u8) var_s0, 6);
  }

  func_8007B8A8(sp28, arg0->salt[0], 8);
  func_8007B8A8(sp28, arg0->salt[1], 8);
  func_8007B8A8(sp28, arg0->pack, 5);

  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->marathon_scores.unk0[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->marathon_scores.unk14[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->marathon_scores.unk28[i], 17);
  }

  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->ultra_scores.unk0[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->ultra_scores.unk14[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->ultra_scores.unk28[i], 17);
  }

  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->sprint_scores.unk0[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->sprint_scores.unk14[i], 17);
  }
  for (i = 0; i < 5; i++) {
    func_8007B8A8(sp28, arg0->sprint_scores.unk28[i], 17);
  }

  func_8007B8A8(sp28, arg0->time_in_seconds, 10);
  func_8007B8A8(sp28, arg0->lines, 14);
  func_8007B8A8(sp28, arg0->unkC4, 20);
  func_8007B8A8(sp28, arg0->unkC8, 30);
  func_8007B8A8(sp28, arg0->unkCC, 30);
  func_8007B8A8(sp28, arg0->unkD0, 1);
  func_8007B8A8(sp28, arg0->unkD2, 16);
  func_8007BA38(sp28);

  n64HeapUnalloc(sp28);
}

void func_8007B38C(TextList *arg0) {
  rmonPrintf("Name: %s\n", arg0->text);
  rmonPrintf("Salt: %x %x\n", arg0->salt[0], arg0->salt[1]);
  rmonPrintf("Pack: %x\n", arg0->pack);
  rmonPrintf("Ptr: %x\n", arg0->ptr);
  rmonPrintf("Next: %x\n", arg0->next);
  rmonPrintf("Last: %x\n", arg0->last);
}

void func_8007B420(Player *arg0) {
  s32 unused;
}

void func_8007B430(Player *arg0, u8 *arg1, s32 arg2) {
  s32 i;
  UnkStruct_115 *sp18;

  sp18 = n64HeapAlloc(sizeof(UnkStruct_115));

  sp18->unk14 = 0;
  sp18->unk8 = arg2;
  sp18->unkC = arg1;
  sp18->unk10 = 0;

  for (i = 0; i < 8; i++) {
    arg0->name[i] = func_8007B964(sp18, 6) & 0x3F;
    arg0->name[i] += 32;
  }
  arg0->name[8] = '\0';

  arg0->salt[0] = func_8007B964(sp18, 8) & 0xFF;
  arg0->salt[1] = func_8007B964(sp18, 8) & 0xFF;
  arg0->pack = func_8007B964(sp18, 5) & 0x1F;

  for (i = 0; i < 5; i++) {
    arg0->marathon_scores.unk0[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->marathon_scores.unk14[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->marathon_scores.unk28[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }

  for (i = 0; i < 5; i++) {
    arg0->ultra_scores.unk0[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->ultra_scores.unk14[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->ultra_scores.unk28[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }

  for (i = 0; i < 5; i++) {
    arg0->sprint_scores.unk0[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->sprint_scores.unk14[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }
  for (i = 0; i < 5; i++) {
    arg0->sprint_scores.unk28[i] = func_8007B964(sp18, 17) & 0x1FFFF;
  }

  arg0->time_in_seconds = func_8007B964(sp18, 10) & 0x3FF;
  arg0->lines = func_8007B964(sp18, 14) & 0xFFF;  // (bug?) should this have been 0x3FFF ?
  arg0->unkC4 = func_8007B964(sp18, 20) & 0xFFFFF;
  arg0->unkC8 = func_8007B964(sp18, 30) & 0x3FFFFFFF;
  arg0->unkCC = func_8007B964(sp18, 30) & 0x3FFFFFFF;
  arg0->unkD0 = func_8007B964(sp18, 1) & 0x1;
  arg0->unkD2 = func_8007B964(sp18, 16) & 0xFFFF;
  // 955 bits consumed by func_8007B964, which rounds up to 120 bytes (SRAM_PLAYER_SZ)
  arg0->unkD0 = FALSE;

  n64HeapUnalloc(sp18);
}

static void func_8007B8A8(UnkStruct_115 *arg0, s32 arg1, s32 arg2) {
  while (arg2 >= arg0->unk4) {
    arg0->unk0 = (arg0->unk0 << arg0->unk4) | (arg1 >> (arg2 - arg0->unk4));
    arg0->unkC[arg0->unk8++] = (u8) arg0->unk0;
    arg1 &= D_800D2F40[arg2 - arg0->unk4];
    arg2 -= arg0->unk4;
    arg0->unk4 = 8;
    arg0->unk0 = 0;
  }
  if (arg2 > 0) {
    arg0->unk0 = (arg0->unk0 << arg2) | arg1;
    arg0->unk4 -= arg2;
  }
}

static s32 func_8007B964(UnkStruct_115 *arg0, s32 arg1) {
  s32 ret = 0;

  while (arg1 > arg0->unk10) {
    ret |= arg0->unk14 << (arg1 - arg0->unk10);
    arg1 -= arg0->unk10;
    arg0->unk14 = arg0->unkC[arg0->unk8++];
    arg0->unk10 = 8;
  }
  if (arg1 > 0) {
    ret |= arg0->unk14 >> (arg0->unk10 - arg1);
    arg0->unk14 &= D_800D2F40[arg0->unk10 - arg1];
    arg0->unk10 -= arg1;
  }

  return ret;
}

static void func_8007BA38(UnkStruct_115 *arg0) {
  if (arg0->unk4 != 8) {
    arg0->unkC[arg0->unk8] = arg0->unk0 << arg0->unk4;
    arg0->unk8++;
    arg0->unk0 = 0;
    arg0->unk4 = 8;
  }
}

// unused
void func_8007BA84(u8 *arg0, SuperThread *arg1) {
  FUN_001050_eepromRead(arg1, arg0);
  while (arg1->eepRead) {}
  if (arg0[g_eepromSize - 2] != 0x69) {
    func_8007BB54(arg0, arg1);
  }
  FUN_001050_eepromWrite(arg1, arg0);
  while (arg1->eepWrite) {}
}

static void func_8007BB54(u8 *arg0, SuperThread *arg1) {
  s32 i;

  bzero(arg0, g_eepromSize);
  for (i = 0; i < g_eepromSize; i++) {
    arg1->eepCache[i] = 1;
  }
  arg0[g_eepromSize - 2] = 0x69;
  arg0[g_eepromSize - 1] = 0;
  arg0[g_eepromSize - 3] = 0;
  arg0[g_eepromSize - 4] = 0;
  arg0[g_eepromSize - 5] = 0;
  arg0[g_eepromSize - 6] = 0;
  FUN_001050_eepromWrite(arg1, arg0);
  while (arg1->eepWrite) {}
}

static void set_total_wonder_lines(Sram *sram_ptr, u32 total_wonder_lines) {
  sram_ptr->total_wonder_lines_odd_bits = total_wonder_lines & 0xAAAAAAAA;
  sram_ptr->total_wonder_lines_even_bits = total_wonder_lines & 0x55555555;
}

u32 get_total_wonder_lines(Sram *sram_ptr) {
  return sram_ptr->total_wonder_lines_odd_bits | sram_ptr->total_wonder_lines_even_bits;
}

// calculates checksum of Sram
static u32 sram_chksum(u8 *data, u32 nbytes) {
  u32 chksum = 0;
  u32 i;

  for (i = 0; i < nbytes; i += 4) {
    chksum += data[i + 0] ^ 0x10;
    chksum -= data[i + 2];
    chksum += data[i + 1] ^ 0x20;
    chksum -= data[i + 3] << 1;
  }

  return chksum;
}

// calculates checksum of Player
static u16 func_8007BD48(u8 *data, u32 nbytes) {
  u16 chksum = 0;
  u32 i;

  for (i = 0; i < nbytes; i += 4) {
    chksum += data[i + 0] ^ 0x10;
    chksum -= data[i + 2];
    chksum += data[i + 1] ^ 0x20;
    chksum += data[i + 3] << 1;
  }

  return chksum;
}

static void func_8007BDD8(Sram *sram_ptr) {
  s32 i;

  sprintf(sram_ptr->global_marathon[0].name, "MARTIST");
  sprintf(sram_ptr->global_marathon[1].name, "FYSX");
  sprintf(sram_ptr->global_marathon[2].name, "ORION");
  sprintf(sram_ptr->global_marathon[3].name, "GRANOLA");
  sprintf(sram_ptr->global_marathon[4].name, "GOKU");

  sprintf(sram_ptr->global_ultra[0].name, "RAPTOR");
  sprintf(sram_ptr->global_ultra[1].name, "LUPIN");
  sprintf(sram_ptr->global_ultra[2].name, "TRUBADOR");
  sprintf(sram_ptr->global_ultra[3].name, "SASQUACH");
  sprintf(sram_ptr->global_ultra[4].name, "KUNGPOW");

  sprintf(sram_ptr->global_sprint[0].name, "5ARAH");
  sprintf(sram_ptr->global_sprint[1].name, "FEVER");
  sprintf(sram_ptr->global_sprint[2].name, ")(CEMAN");
  sprintf(sram_ptr->global_sprint[3].name, "JUNGLY");
  sprintf(sram_ptr->global_sprint[4].name, "CHOPPER");

  for (i = 0; i < 5; i++) {
    sram_ptr->global_marathon[i].unkA = 0;
    sram_ptr->global_marathon[i].unkB = 0;
    sram_ptr->global_ultra[i].unkA = 0;
    sram_ptr->global_ultra[i].unkB = 0;
    sram_ptr->global_sprint[i].unkA = 0;
    sram_ptr->global_sprint[i].unkB = 0;

    // lines
    sram_ptr->global_marathon[i].unkC = D_800D2FC4[i];
    sram_ptr->global_ultra[i].unkC = D_800D2FD8[i];
    sram_ptr->global_sprint[i].unkC = D_800D2FEC[i];

    // time
    sram_ptr->global_marathon[i].unk10 = D_800D3000[i];
    sram_ptr->global_ultra[i].unk10 = D_800D3014[i];
    sram_ptr->global_sprint[i].unk10 = D_800D3028[i];
  }
}

void load_from_sram(u8 arg0) {
  Sram *sram_ptr;

  if (arg0 == 0) {
    g_sram_ptr = n64HeapAlloc(sizeof(Sram));
    sram_ptr = g_sram_ptr;
    func_800AC1A8(sram_ptr, (void *) SRAM_START_ADDR, sizeof(Sram));
  }

  sram_ptr = g_sram_ptr;
  if ((bcmp(sram_ptr->version, "0.0b", 4) != 0) || (arg0 == 1)) {
    bzero(sram_ptr, sizeof(Sram));
    sram_ptr->bitpattern = 0;
    sram_ptr->version[0] = '0';
    sram_ptr->version[1] = '.';
    sram_ptr->version[2] = '0';
    sram_ptr->version[3] = 'b';
    sram_ptr->music_level = 2340 * 10;
    sram_ptr->sfx_level = 0x7000;
    sram_ptr->song = SONG_TITLE;
    sram_ptr->game_id = OS_CYCLES_TO_NSEC(osGetTime());
    func_8007BDD8(g_sram_ptr);
    sram_ptr->chksum = sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4);
    func_800AC22C(sram_ptr, (void *) SRAM_START_ADDR, sizeof(Sram));
    func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + sizeof(Sram)), sizeof(Sram));
    func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + (sizeof(Sram) + sizeof(Sram))), sizeof(Sram));
    Audio2_80087618_fourteenliner_loops_256t(sram_ptr->sfx_level);
    func_800875EC(sram_ptr->music_level, &g_songPlayer);
    D_800D4564.cur = sram_ptr->music_level / 2340;
    D_800D4928.cur = sram_ptr->sfx_level / 2340;
  } else {
    if (sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4) != sram_ptr->chksum) {
      func_800AC1A8(sram_ptr, (void *) (SRAM_START_ADDR + sizeof(Sram)), sizeof(Sram));
      if (sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4) != sram_ptr->chksum) {
        func_800AC1A8(sram_ptr, (void *) (SRAM_START_ADDR + (sizeof(Sram) + sizeof(Sram))), sizeof(Sram));
        if (sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4) != sram_ptr->chksum) {
          sram_ptr->bitpattern = 0;
          bzero(sram_ptr, sizeof(Sram));
          sram_ptr->version[0] = '0';
          sram_ptr->version[1] = '.';
          sram_ptr->version[2] = '0';
          sram_ptr->version[3] = 'b';
          sram_ptr->music_level = 2340 * 10;
          sram_ptr->sfx_level = 0x7000;
          sram_ptr->song = SONG_TITLE;
          sram_ptr->game_id = OS_CYCLES_TO_NSEC(osGetTime() + osTvType + osResetType + sram_ptr->chksum);
          func_8007BDD8(g_sram_ptr);
          sram_ptr->chksum = sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4);
          func_800AC22C(sram_ptr, (void *) SRAM_START_ADDR, sizeof(Sram));
          func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + sizeof(Sram)), sizeof(Sram));
          func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + (sizeof(Sram) + sizeof(Sram))), sizeof(Sram));
          Audio2_80087618_fourteenliner_loops_256t(sram_ptr->sfx_level);
          func_800875EC(sram_ptr->music_level, &g_songPlayer);
          D_800D4564.cur = sram_ptr->music_level / 2340;
          D_800D4928.cur = sram_ptr->sfx_level / 2340;
        }
      }
    }

    func_800875EC(sram_ptr->music_level, &g_songPlayer);
    Audio2_80087618_fourteenliner_loops_256t(sram_ptr->sfx_level);
    D_800D4DC4.cur = sram_ptr->music_mode;
    wonders2_80045e50_sets_num_won_compl_q();
    D_800D4564.cur = sram_ptr->music_level / 2340;
    D_800D4928.cur = sram_ptr->sfx_level / 2340;
  }

  g_game.unkE4F8 = D_800CF838;
}

void save_to_sram(Sram *sram_ptr) {
  sram_ptr->game_id = osGetTime();
  sram_ptr->chksum = sram_chksum((u8 *) sram_ptr, sizeof(Sram) - 4);
  func_800AC22C(sram_ptr, (void *) SRAM_START_ADDR, sizeof(Sram));
  func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + sizeof(Sram)), sizeof(Sram));
  func_800AC22C(sram_ptr, (void *) (SRAM_START_ADDR + (sizeof(Sram) + sizeof(Sram))), sizeof(Sram));
}
