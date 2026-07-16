#include "common.h"

u8 FUN_006780_80040500_twentyfiveliner_loops(u8 arg0, u8 arg1) {
  register u8 i;
  register UnkStruct_107 *temp_s1;
  register UnkStruct_106 *temp_s2;
  u8 sp33;
  u8 sp32;
  u8 sp31;

  FUN_008050_80041e88_loops_200_times();

  temp_s1 = &D_800C5E04->unk2E;
  for (i = 0; i < temp_s1->unk0; i++) {
    temp_s2 = &temp_s1->unk7[temp_s1->unk1[i]];
    if (!check_square_completion(temp_s2->unk0, temp_s2->unk1, &sp33, &sp32, &sp31)) {
      aisquarelist_8003e2c8_sevenliner(temp_s1, i);
    }
  }

  sp31 = 0;
  for (i = 0; i < temp_s1->unk0; i++) {
    if (aisquarelist_8003ed40_largeliner_many_loops(temp_s1, i, &sp31, arg0, arg1)) {
      aisquarelist_8003e2c8_sevenliner(temp_s1, i);
      break;
    }
  }

  if (sp31 == 0) {
    if (aisquarelist_8003e458_thirteenliner_loops_7t(temp_s1, &sp33, &sp32)) {
      aisquarelist_8003e22c_tenliner_loops_6t(temp_s1, sp33, sp32);
      aisquarelist_8003ed40_largeliner_many_loops(temp_s1, i, &sp31, arg0, arg1);
      if (sp31 == 0) {
        return FALSE;
      }
    } else {
      return FALSE;
    }
  }

  FUN_008050_800423f0_uses_dat_800e1f40_ptr(sp31);

  return TRUE;
}
