#include "common.h"

// Sram *g_sram_ptr;

/*
PlayerNode D_800D2D80 = {
  { 'G', 'U', 'E', 'S', 'T', 0, 0, 0, 0 },
  { 0x20, 0x20 },
  0xE,
  NULL,
  &D_800D2D98,
  &D_800D2D98
};
PlayerNode D_800D2D98 = {
  { 'N', 'E', 'W', ' ', 'N', 'A', 'M', 'E', 0 },
  { 0x20, 0x20 },
  0xF,
  NULL,
  &D_800D2D80,
  &D_800D2D80
};
PlayerNode D_800D2DB0 = {
  { 'G', 'L', 'O', 'B', 'A', 'L', 0, 0, 0 },
  { 0x20, 0x20 },
  0x9,
  NULL,
  &D_800D2DB0,
  &D_800D2DB0
};
PlayerNode D_800D2DC8 = {
  { 0x20, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0 },
  0x5,
  NULL,
  &D_800D2DC8,
  &D_800D2DC8
};
PlayerNode D_800D2DE0 = {
  { 'C', 'H', 'O', 'O', 'S', 'E', 0, 0, 0 },
  { 0xFF, 0xFF },
  0x4,
  NULL,
  &D_800D2DE0,
  &D_800D2DE0
};
*/

// /* 099078 800D2DF8 800D2D98 */ .word D_800D2D98

/* static */ extern u8 D_800D2DFC[30];
/*
static u8 D_800D2DFC[30] = {
  3, 7, 10, 13, 17, 20, 23, 27, 30, 33,
  37, 40, 43, 47, 50, 53, 57, 60, 63, 67,
  70, 73, 77, 80, 83, 87, 90, 93, 97, 100
};
*/

static void   set_total_wonder_lines(Sram *, u32);

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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_80078534_tenliner_loops.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_800785e0_sixliner_loop_arg0_t.s")

PlayerNode *FUN_SRAM_8007868c_tenliner_loop_arg0_t(PlayerNode *arg0) {
  PlayerNode *sp1C;
  s32 sp18;

  sp18 = 0;
  sp1C = arg0;
  do {
    if (((sp1C->pack & 0xF) == 0xF) || ((sp1C->pack & 0xF) == 0xE) || ((sp1C->pack & 0xF) == 0xA) || ((sp1C->pack & 0xF) == 9) || ((sp1C->pack & 0xF) == 8) || ((sp1C->pack & 0xF) == 6) || ((sp1C->pack & 0xF) == 5) || ((sp1C->pack & 0xF) == 4) || ((sp1C->pack & 0xF) == 0xB)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_8007875c_check_gameover_conditions.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/FUN_SRAM_800795d8_fourteenliner_loops_8t.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_800796C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_800798F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_80079F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/D_800DDDFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A5D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007A738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AA50.s")

PlayerNode *func_8007AA5C(PlayerNode *arg0, PlayerNode *arg1) {
  PlayerNode *sp4;

  sp4 = arg0;
  do {
    if ((sp4->salt[0] == arg1->salt[0]) && (sp4->salt[1] == arg1->salt[1]) && (sp4->name[0] == arg1->name[0])) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AB10.s")

PlayerNode *func_8007AEB0(PlayerNode *arg0) {
  PlayerNode *sp1C;

  if (((arg0->pack & 0xF) != 0xE) && ((arg0->pack & 0xF) != 0xF) && ((arg0->pack & 0xF) != 0xA) && ((arg0->pack & 0xF) != 5)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007AF88.s")

void func_8007B38C(PlayerNode *arg0) {
  rmonPrintf("Name: %s\n", arg0->name);
  rmonPrintf("Salt: %x %x\n", arg0->salt[0], arg0->salt[1]);
  rmonPrintf("Pack: %x\n", arg0->pack);
  rmonPrintf("Ptr: %x\n", arg0->ptr);
  rmonPrintf("Next: %x\n", arg0->next);
  rmonPrintf("Last: %x\n", arg0->last);
}

void func_8007B420(Player *arg0) {
  s32 unused;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007B964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BB54.s")

static void set_total_wonder_lines(Sram *sram_ptr, u32 total_wonder_lines) {
  sram_ptr->total_wonder_lines_odd_bits = total_wonder_lines & 0xAAAAAAAA;
  sram_ptr->total_wonder_lines_even_bits = total_wonder_lines & 0x55555555;
}

u32 get_total_wonder_lines(Sram *sram_ptr) {
  return sram_ptr->total_wonder_lines_odd_bits | sram_ptr->total_wonder_lines_even_bits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BCC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007BDD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/load_from_sram.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/sram/func_8007C5CC.s")
