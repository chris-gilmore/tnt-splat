#include "common.h"

UnkStruct_99 **D_800E1F40;

static void FUN_008050_80041ef0_twentyliner(UnkStruct_99 *, UnkStruct_99 *);
static s16 FUN_008050_80041fcc_twentyliner_case4(UnkStruct_99 *, u8);
static s16 FUN_008050_800420d8_fifteenliner(s16, s16, u8);
static u8 FUN_008050_80042184_fifteenliner_loop(UnkStruct_99 **, u8, u8, u8);
static u8 FUN_008050_800422f4_threeliner(UnkStruct_99 **, u8, u8, u8);
static void FUN_008050_80042368_threeliner(UnkStruct_99 **, u8, u8, u8);

void FUN_008050_80041dd0_alloc_heap_4_and_x640(void) {
  D_800E1F40 = n64HeapAlloc(sizeof(UnkStruct_99 *));
  if (D_800E1F40 != NULL) {
    *D_800E1F40 = n64HeapAlloc(sizeof(UnkStruct_99) * 200);
  }
}

void FUN_008050_80041e24_maybe_calls_unalloc_heap(void) {
  if (D_800E1F40 != NULL) {
    if (*D_800E1F40 != NULL) {
      n64HeapUnalloc(*D_800E1F40);
      *D_800E1F40 = NULL;
    }
    n64HeapUnalloc(D_800E1F40);
    D_800E1F40 = NULL;
  }
}

void FUN_008050_80041e88_loops_200_times(void) {
  register u8 i;
  register UnkStruct_99 *temp_a1;

  if (D_800E1F40 == NULL) {
    return;
  }

  for (i = 0; i < 200; i++) {
    temp_a1 = *D_800E1F40 + i;
    temp_a1->unk0 = -0x8000;
    temp_a1->unk2.unk0 = 0;
    temp_a1->unk2.unk1 = 0;
    temp_a1->unk2.unk2 = 0;
  }
}

// swap
static void FUN_008050_80041ef0_twentyliner(UnkStruct_99 *arg0, UnkStruct_99 *arg1) {
  register UnkStruct_99 tmp;

  tmp.unk0 = arg0->unk0;
  tmp.unk2.unk0 = arg0->unk2.unk0;
  tmp.unk2.unk1 = arg0->unk2.unk1;
  tmp.unk2.unk2 = arg0->unk2.unk2;
  tmp.unk5 = arg0->unk5;
  tmp.unk6 = arg0->unk6;

  arg0->unk0 = arg1->unk0;
  arg0->unk2.unk0 = arg1->unk2.unk0;
  arg0->unk2.unk1 = arg1->unk2.unk1;
  arg0->unk2.unk2 = arg1->unk2.unk2;
  arg0->unk5 = arg1->unk5;
  arg0->unk6 = arg1->unk6;

  arg1->unk0 = tmp.unk0;
  arg1->unk2.unk0 = tmp.unk2.unk0;
  arg1->unk2.unk1 = tmp.unk2.unk1;
  arg1->unk2.unk2 = tmp.unk2.unk2;
  arg1->unk5 = tmp.unk5;
  arg1->unk6 = tmp.unk6;
}

static s16 FUN_008050_80041fcc_twentyliner_case4(UnkStruct_99 *arg0, u8 arg1) {
  register s16 var_s0;
  u8 sp25;
  u8 sp24;

  switch (arg1) {
  case 0:
    var_s0 = arg0->unk0;
    break;
  case 1:
    var_s0 = arg0->unk6;
    break;
  case 2:
    if (arg0->unk5 < 5) {
      var_s0 = arg0->unk5;
    } else {
      var_s0 = 10 - arg0->unk5;
    }
    break;
  case 3:
    FUN_006930_800406b0_fifteenliner_two_loops(arg0->unk2.unk2, &sp25, &sp24);
    if (sp25 < sp24) {
      var_s0 = sp25;
    } else {
      var_s0 = sp24;
    }
    break;
  }

  return var_s0;
}

static s16 FUN_008050_800420d8_fifteenliner(s16 arg0, s16 arg1, u8 arg2) {
  register s16 var_a3;
  register s16 unused;

  switch (arg2) {
  case 0:
  case 1:
  case 2:
    if (arg0 < arg1) {
      var_a3 = -1;
    } else if (arg1 < arg0) {
      var_a3 = 1;
    } else {
      var_a3 = 0;
    }
    break;
  case 3:
    if (arg1 < arg0) {
      var_a3 = -1;
    } else if (arg0 < arg1) {
      var_a3 = 1;
    } else {
      var_a3 = 0;
    }
    break;
  }

  return var_a3;
}

static u8 FUN_008050_80042184_fifteenliner_loop(UnkStruct_99 **arg0, u8 arg1, u8 arg2, u8 arg3) {
  register s16 var_s0;
  register s16 var_s1;
  register s16 var_s2;

  var_s0 = FUN_008050_80041fcc_twentyliner_case4(*arg0 + arg1, arg3);
  var_s1 = arg1 - 1;
  var_s2 = arg2 + 1;
  while (TRUE) {
    do {
      var_s2--;
    } while (FUN_008050_800420d8_fifteenliner(FUN_008050_80041fcc_twentyliner_case4(*arg0 + var_s2, arg3), var_s0, arg3) < 0);

    do {
      var_s1++;
    } while (FUN_008050_800420d8_fifteenliner(FUN_008050_80041fcc_twentyliner_case4(*arg0 + var_s1, arg3), var_s0, arg3) > 0);

    if (var_s1 < var_s2) {
      FUN_008050_80041ef0_twentyliner(*arg0 + var_s1, *arg0 + var_s2);
    } else {
      break;
    }
  }

  return var_s2;
}

static u8 FUN_008050_800422f4_threeliner(UnkStruct_99 **arg0, u8 arg1, u8 arg2, u8 arg3) {
  register u8 var_s0;

  var_s0 = func_800A35EC(arg1, arg2);
  FUN_008050_80041ef0_twentyliner(*arg0 + arg1, *arg0 + var_s0);
  return FUN_008050_80042184_fifteenliner_loop(arg0, arg1, arg2, arg3);
}

static void FUN_008050_80042368_threeliner(UnkStruct_99 **arg0, u8 arg1, u8 arg2, u8 arg3) {
  register u8 var_s0;

  if (arg1 < arg2) {
    var_s0 = FUN_008050_800422f4_threeliner(arg0, arg1, arg2, arg3);
    FUN_008050_80042368_threeliner(arg0, arg1, var_s0, arg3);
    var_s0++;
    FUN_008050_80042368_threeliner(arg0, var_s0, arg2, arg3);
  }
}

void FUN_008050_800423f0_uses_dat_800e1f40_ptr(u8 arg0) {
  register u8 var_s0;
  register u8 var_s1;
  register UnkStruct_99 *var_s2;
  register UnkStruct_99 *var_s3;

  if ((arg0 == 0) || (arg0 > 200)) {
    return;
  }

  if (D_800E1F40 != NULL) {
    FUN_008050_80042368_threeliner(D_800E1F40, 0, arg0 - 1, 0);

    var_s0 = 0;
    do {
      var_s1 = var_s0;
      var_s2 = *D_800E1F40 + var_s0;
      var_s3 = *D_800E1F40 + var_s1;
      while ((var_s1 < arg0) && (var_s2->unk0 == var_s3->unk0)) {
        var_s1++;
        var_s3 = *D_800E1F40 + var_s1;
      }

      if (var_s0 != var_s1) {
        FUN_008050_80042368_threeliner(D_800E1F40, var_s0, var_s1 - 1, 1);
        var_s0 = var_s1;
      } else {
        var_s0++;
      }
    } while (var_s0 < 3);

    var_s0 = 0;
    do {
      var_s1 = var_s0;
      var_s2 = *D_800E1F40 + var_s0;
      var_s3 = *D_800E1F40 + var_s1;
      while ((var_s1 < arg0) && (var_s2->unk0 == var_s3->unk0) && (var_s2->unk6 == var_s3->unk6)) {
        var_s1++;
        var_s3 = *D_800E1F40 + var_s1;
      }

      if (var_s0 != var_s1) {
        FUN_008050_80042368_threeliner(D_800E1F40, var_s0, var_s1 - 1, 2);
        var_s0 = var_s1;
      } else {
        var_s0++;
      }
    } while (var_s0 < 3);

    var_s0 = 0;
    do {
      var_s1 = var_s0;
      var_s2 = *D_800E1F40 + var_s0;
      var_s3 = *D_800E1F40 + var_s1;
      while ((var_s1 < arg0) && (var_s2->unk0 == var_s3->unk0) && (var_s2->unk6 == var_s3->unk6) && (var_s2->unk5 == var_s3->unk5)) {
        var_s1++;
        var_s3 = *D_800E1F40 + var_s1;
      }

      if (var_s0 != var_s1) {
        FUN_008050_80042368_threeliner(D_800E1F40, var_s0, var_s1 - 1, 3);
        var_s0 = var_s1;
      } else {
        var_s0++;
      }
    } while (var_s0 < 3);
  }
}

// unused
void FUN_008050_80042738_passes_dat_800e1f40_ptr(UnkStruct_108 *arg0) {
  register u8 var_s0;

  if (D_800E1F40 != NULL) {
    for (var_s0 = 0; var_s0 < 3; var_s0++) {
      FUN_80041da0_threeliner(&arg0[var_s0], &(*D_800E1F40)[var_s0].unk2);
    }
  }
}

void FUN_008050_800427b8_passes_dat_800e1f40_ptr(u8 arg0, UnkStruct_108 *arg1) {
  s32 unused;

  if (D_800E1F40 != NULL) {
    FUN_80041da0_threeliner(arg1, &(*D_800E1F40)[arg0].unk2);
  }
}
