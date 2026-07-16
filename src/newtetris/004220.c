#include "common.h"

UnkStruct_109 *D_800E1F20;

void FUN_004220_8003dfa0_sixliner_allocs_heap_x962(void) {
  register u8 i;

  D_800E1F20 = n64HeapAlloc(sizeof(UnkStruct_109));
  for (i = 0; i < 2; i++) {
    D_800E1F20->unk0[i] = 0;
  }
}

void FUN_004220_8003e004_threeliner_unallocs_heap(void) {
  if (D_800E1F20 != NULL) {
    n64HeapUnalloc(D_800E1F20);
    D_800E1F20 = NULL;
  }
}

void FUN_004220_8003e038_twentytwoliner_nested_loops(u8 arg0, u8 arg1) {
  register u8 var_s0;
  register u8 var_s1;
  register UnkStruct_108 *temp_s2;
  u8 sp2F;

  D_800E1F20->unk0[arg0] = 0;
  for (var_s0 = 0; var_s0 < 10; var_s0++) {
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
      for (sp2F = 19; FUN_8004199c_twentyliner_loop(var_s0, &sp2F, var_s1, arg1); sp2F--) {
        if (D_800E1F20->unk0[arg0] >= 400) {  // (bug?) this is always false, since u8 is always less than 400
          return;
        }

        temp_s2 = &D_800E1F20->unk2[arg0][D_800E1F20->unk0[arg0]];
        temp_s2->unk0 = var_s0;
        temp_s2->unk1 = sp2F;
        temp_s2->unk2 = var_s1;
        D_800E1F20->unk0[arg0]++;

        if ((sp2F == 0) || FUN_8004191c_sixliner_loop_shift_right(var_s0, sp2F)) {
          break;
        }
      }
    }
  }
}
