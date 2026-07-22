#include "common.h"

Garbage *g_garbage_ptr;

static void func_80072B30(UnkStruct_110 *, u32);
static void func_80072B58(UnkStruct_110 *);
static void func_80072BAC(UnkStruct_110 *);
static void func_80072E3C(void);
static void func_80073014(Garbage *, u32);

static void func_80072B30(UnkStruct_110 *arg0, u32 seed) {
  arg0->unk0 = 12;
  arg0->unk2 = 0;
  arg0->seed = seed;
  arg0->hole = seed % 10;
}

static void func_80072B58(UnkStruct_110 *arg0) {
  arg0->seed = FUN_026900_PRNG_2(arg0->seed);
  arg0->hole = arg0->seed % 10;
}

static void func_80072BAC(UnkStruct_110 *arg0) {
  register s32 var_s0;
  register s32 var_s1;

  for (var_s1 = 0; var_s1 < 19; var_s1++) {
    for (var_s0 = 0; var_s0 < 10; var_s0++) {
      BoardPieces_SwapCubes(var_s0, var_s1, var_s0, var_s1 + 1);
    }
  }

  for (var_s0 = 0; var_s0 < 10; var_s0++) {
    if (var_s0 != arg0->hole) {
      BoardP_8006de40_nineliner(var_s0, 19, FUN_026900_PRNG_1() % 7);
    }
  }

  arg0->unk2++;
  if (arg0->unk2 == arg0->unk0) {
    func_80072B58(arg0);
  }
}

void func_80072CC8(Garbage *arg0, u8 arg1, u8 arg2) {
  if (arg1 > 3) {
    debug_print_reason_routine_linenum("out of bounds", "garbage.c", 96);
  }

  arg0->unk1E[arg1] = arg2;
}

u8 func_80072D24(Garbage *arg0, u8 arg1) {
  return arg0->unk1E[arg1];
}

void Garbage_Init(Garbage *arg0, u32 *seed) {
  register s32 i;

  arg0->unk1 = 0;
  Garbage_80072e2c_set_arg0p_to_arg1(arg0, FALSE);
  arg0->unk1C = 0;
  arg0->unk8 = 0;
  arg0->unkC = 0;
  arg0->unk10 = 5;
  arg0->unk1D = g_currentplayer;
  arg0->unk3 = FALSE;
  arg0->unk4 = FALSE;
  func_80072B30(&arg0->unk14, *seed);

  *seed = FUN_026900_PRNG_2(*seed);
  for (i = 0; i < 4; i++) {
    func_80072CC8(arg0, i, TRUE);
  }
}

void Garbage_Deinit(Garbage *arg0) {
  arg0->unk1 = 0;
}

void Garbage_80072e2c_set_arg0p_to_arg1(Garbage *arg0, s32 arg1) {
  arg0->unk0 = arg1;
}

void func_80072E34(Garbage *arg0, s32 arg1) {
  arg0->unk1D = arg1;
}

static void func_80072E3C(void) {
  register Garbage *garbage_ptr = g_garbage_ptr;

  if (garbage_ptr->unk3) {
    if (BoardP_8006ddd0_check_for_nonempty_cell_upwards(3)) {
      garbage_ptr->unk2 = 2;
      return;
    }
  } else if (BoardP_8006dd64_check_for_nonempty_cell_downwards(0)) {
    garbage_ptr->unk4 = TRUE;
    return;
  }

  if (garbage_ptr->unk6 == 0) {
    func_80072BAC(&garbage_ptr->unk14);
    garbage_ptr->unk1C--;
    garbage_ptr->unk5++;
    garbage_ptr->unk6 = 4;
    if ((garbage_ptr->unk1C == 0) || (garbage_ptr->unk5 >= garbage_ptr->unk10)) {
      garbage_ptr->unk2 = 2;
    }
  } else {
    garbage_ptr->unk6--;
  }
}

u8 func_80072F1C(s32 arg0) {
  register Garbage *garbage_ptr = g_garbage_ptr;

  garbage_ptr->unk2 = 0;

  if ((garbage_ptr->unk1 == 0) || !garbage_ptr->unk0) {
    garbage_ptr->unk2 = 1;
    return garbage_ptr->unk2;
  }

  if (garbage_ptr->unk1 == 1) {
    func_80072E3C();
  }

  if (garbage_ptr->unk4) {
    garbage_ptr->unk2 = 3;
  }

  return garbage_ptr->unk2;
}

// unused
void func_80072FB0(void) {
  register Garbage *garbage_ptr = g_garbage_ptr;
}

void func_80072FC4(void) {
  register Garbage *garbage_ptr = g_garbage_ptr;

  if (!garbage_ptr->unk0) {
    garbage_ptr->unk1C = 0;
  }

  if (garbage_ptr->unk1C == 0) {
    garbage_ptr->unk1 = 0;
    return;
  }

  garbage_ptr->unk1 = 1;
  garbage_ptr->unk6 = 0;
  garbage_ptr->unk5 = 0;
}

static void func_80073014(Garbage *arg0, u32 arg1) {
  arg0->unk1C += arg1;
  arg0->unk8 += arg1;
}

void func_80073030(u32 arg0) {
  register Garbage *garbage_ptr = g_garbage_ptr;
  register Garbage *var_s1;

  if (!garbage_ptr->unk0 || (garbage_ptr->unk1D == 0xFF) || (arg0 == 0) || (garbage_ptr->unk1D == g_currentplayer)) {
    return;
  }

  if (garbage_ptr->unk1C > arg0) {
    garbage_ptr->unk1C -= arg0;
    arg0 = 0;
  } else {
    arg0 -= garbage_ptr->unk1C;
    garbage_ptr->unk1C = 0;
  }

  if (arg0 != 0) {
    var_s1 = g_landfill_ptr->list + garbage_ptr->unk1D;
    func_80073014(var_s1, arg0);
  }
}
