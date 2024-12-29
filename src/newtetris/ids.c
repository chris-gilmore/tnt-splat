#include "common.h"

static void   FUN_800507e4_twoliner(Ids *, s32);

void Ids_Init(Ids *ids, s32 arg1) {
  register u8 *var_s0;
  register s32 i;

  ids->modulus = arg1;
  ids->next_id = 0;
  ids->list = n64HeapAlloc(arg1);
  var_s0 = ids->list;
  for (i = arg1; i > 0; i--, var_s0++) {
    *var_s0 = 0;
  }
}

void Ids_Deinit(Ids *ids) {
  ids->modulus = 0;
  ids->next_id = 0;
  n64HeapUnalloc(ids->list);
}

u32 can_run_out_of_ids(Ids *ids) {
  register u8 *var_s0;
  register s32 var_s1;  // unused
  register u32 var_s2;

  var_s2 = ids->next_id;
  var_s0 = ids->list + var_s2;
  while (*var_s0 != 0) {
    var_s2++;
    var_s0++;
    if (ids->modulus == var_s2) {
      var_s0 = ids->list;
      var_s2 = 0;
    }
    if (ids->next_id == var_s2) {
      debug_print_reason_routine("Ids:", "out of IDs");
    }
  }
  ids->next_id = (var_s2 + 1) % ids->modulus;
  return var_s2;
}

static void FUN_800507e4_twoliner(Ids *ids, s32 arg1) {
  register u8 *var_a2 = ids->list + arg1;

  *var_a2 = 0;
  ids->next_id = arg1;
}

void FUN_80050800_oneliner(Ids *ids, s32 arg1) {
  register u8 *temp_a2 = ids->list + arg1;

  (*temp_a2)++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/ids/FUN_80050820_oneliner.s")

void FUN_80050840_fiveliner(Ids *ids, s32 arg1) {
  register u8 *temp_s0 = ids->list + arg1;

  (*temp_s0)--;
  if (*temp_s0 == 0) {
    FUN_800507e4_twoliner(ids, arg1);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/ids/FUN_800508a8_fiveliner.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/ids/FUN_800508ec_fifteen_liner_allocs_heap.s")
