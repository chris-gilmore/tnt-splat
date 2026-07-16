#include "common.h"

static u8 D_800C55A0[4] = { 0, 20, 40, 160 };

static u8 aisquarelist_8003e34c_thirteenliner_loops_arg0_t(UnkStruct_107 *, u8, u8);
static u8 aisquarelist_8003e68c_hugeliner_many_loops(UnkStruct_106 *, u8, u8, u8, s16 *, u8);

void aisquarelist_8003e1e0_sevenliner_loops_6t(UnkStruct_107 *arg0) {
  register u8 i;

  arg0->unk0 = 0;
  for (i = 0; i < 6; i++) {
    arg0->unk1[i] = -1;
    arg0->unk7[i].unk2 = FALSE;
  }
}

void aisquarelist_8003e22c_tenliner_loops_6t(UnkStruct_107 *arg0, u8 arg1, u8 arg2) {
  register u8 i;

  for (i = 0; i < 6; i++) {
    if (!arg0->unk7[i].unk2) {
      break;
    }
  }
  if (i < 6) {
    register UnkStruct_106 *var_t0 = &arg0->unk7[i];

    var_t0->unk2 = TRUE;
    var_t0->unk0 = arg1;
    var_t0->unk1 = arg2;

    arg0->unk1[arg0->unk0++] = i;
  }
}

void aisquarelist_8003e2c8_sevenliner(UnkStruct_107 *arg0, u8 arg1) {
  register u8 i;

  arg0->unk7[arg0->unk1[arg1]].unk2 = FALSE;

  for (i = arg1; i < 5; i++) {
    if (arg0->unk1[i + 1] == -1) {
      break;
    }
    arg0->unk1[i] = arg0->unk1[i + 1];
  }
  arg0->unk1[i] = -1;

  arg0->unk0--;
}

static u8 aisquarelist_8003e34c_thirteenliner_loops_arg0_t(UnkStruct_107 *arg0, u8 arg1, u8 arg2) {
  register u8 i;
  register UnkStruct_106 *var_t0;

  for (i = 0; i < arg0->unk0; i++) {
    var_t0 = &arg0->unk7[arg0->unk1[i]];
    if (((var_t0->unk0 <= arg1) && (arg1 <= (var_t0->unk0 + 3)) &&
         (var_t0->unk1 <= arg2) && (arg2 <= (var_t0->unk1 + 3))) ||
        ((arg1 <= var_t0->unk0) && (var_t0->unk0 <= (arg1 + 3)) &&
         (arg2 <= var_t0->unk1) && (var_t0->unk1 <= (arg2 + 3)))) {
      return TRUE;
    }
  }

  return FALSE;
}

u8 aisquarelist_8003e458_thirteenliner_loops_7t(UnkStruct_107 *arg0, u8 *arg1, u8 *arg2) {
  register u8 var_s0;
  register s8 var_s1;
  u8 sp2D;
  u8 sp2C;
  u8 sp2B;

  for (var_s1 = 16; var_s1 >= 7; var_s1--) {
    for (var_s0 = 0; var_s0 < 7; var_s0++) {
      if (check_square_completion(var_s0, var_s1, &sp2D, &sp2C, &sp2B) && (sp2C < 4) && FUN_80041ab4_tenliner_loop(var_s0, var_s1 + 4) && !aisquarelist_8003e34c_thirteenliner_loops_arg0_t(arg0, var_s0, var_s1)) {
        *arg1 = var_s0;
        *arg2 = var_s1;
        return TRUE;
      }
    }
  }

  return FALSE;
}

u8 aisquarelist_8003e55c_eightliner_loops_arg0_t_1(UnkStruct_107 *arg0) {
  register u8 i;
  register UnkStruct_106 *var_t0;
  u8 sp2F;
  u8 sp2E;
  u8 sp2D;

  for (i = 0; i < arg0->unk0; i++) {
    var_t0 = &arg0->unk7[arg0->unk1[i]];
    if (!check_square_completion(var_t0->unk0, var_t0->unk1, &sp2F, &sp2E, &sp2D)) {
      return FALSE;
    }
  }

  return TRUE;
}

void aisquarelist_8003e608_eightliner_loops_arg0_t_2(UnkStruct_107 *arg0, u8 arg1) {
  register u8 i;
  register u8 var_a3;
  register UnkStruct_106 *tmp;

  for (i = 0; i < arg0->unk0; i++) {
    tmp = &arg0->unk7[arg0->unk1[i]];
    var_a3 = tmp->unk1;
    var_a3 += 3;
    if (var_a3 < arg1) {
      tmp->unk1++;
    }
  }
}

static u8 aisquarelist_8003e68c_hugeliner_many_loops(UnkStruct_106 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 *arg4, u8 arg5) {
  register u8 var_s0;
  register u8 var_s1;
  register u8 var_s2;
  register u8 var_s3;
  register u8 var_s4;
  register u8 var_s5;
  register UnkStruct_27 *var_s6;
  u8 sp58[4];
  u8 sp57;
  u8 sp56;
  u8 sp55;
  u8 sp54;
  s8 sp44[4][4];

  if (arg2 != 3) {
    return TRUE;
  }

  for (var_s0 = 0; var_s0 < 4; var_s0++) {
    sp58[var_s0] = 1 << g_nextPieces_ptr->buf[var_s0].piece_type;
  }

  var_s1 = g_currentPiece_ptr->pieceType;
  for (var_s2 = 0; var_s2 < 7; var_s2++) {
    for (var_s0 = 0; var_s0 < 5; var_s0++) {
      if (D_800C55B0[var_s0] == (arg3 | var_s2)) {
        break;
      }
    }

    if (var_s0 == 5) {
      for (var_s0 = 0; var_s0 < 19; var_s0++) {
        if (D_800C55B0[var_s0] & (arg3 | var_s2)) {
          break;
        }
      }
    }

    if (var_s0 != 19) {
      CurrentPiece_80067dd8_big_fiftyliner(var_s2);
      for (var_s3 = arg0->unk0; var_s3 < (arg0->unk0 + 4); var_s3++) {
        for (var_s4 = 0; var_s4 < 4; var_s4++) {
          for (sp57 = arg0->unk1 + 3; FUN_8004199c_twentyliner_loop(var_s3, &sp57, var_s4, arg5) && (sp57 >= arg0->unk1); sp57--) {
            FUN_800413c0_twentyfive_liner(var_s3, sp57, var_s4, 8);
            if (check_square_completion(arg0->unk0, arg0->unk1, &sp56, &sp55, &sp54) && (sp56 == arg1) && (arg2 != sp55) && (arg3 != sp54)) {
              for (var_s5 = 0; var_s5 < 4; var_s5++) {
                for (var_s0 = 0; var_s0 < 4; var_s0++) {
                  sp44[var_s0][var_s5] = 0;
                }
              }

              if (!(FUN_005580_8003f300_fourteenliner_recursive(sp44, arg0->unk0, arg0->unk1, arg0->unk0, arg0->unk1) % 4)) {
                for (var_s5 = 0; var_s5 < 4; var_s5++) {
                  for (var_s0 = 0; var_s0 < 4; var_s0++) {
                    var_s6 = &D_800E1F30->unk0[var_s0 + arg0->unk0 + ((var_s5 + arg0->unk1) * 10)];
                    if (var_s6->unk0 == EMPTY_CELL) {
                      sp44[var_s0][var_s5] = -1;
                    } else {
                      sp44[var_s0][var_s5] = var_s6->unk1;
                    }
                  }
                }

                if (sp56 == 0) {
                  for (var_s0 = 0; var_s0 < 5; var_s0++) {
                    if (FUN_005580_8003f4f4_thirtyliner_nested_loops(sp44, 0, sp54, var_s0) && aisquarelist_8003e68c_hugeliner_many_loops(arg0, sp56, sp55, sp54, arg4, arg5)) {
                      for (var_s5 = 0; var_s5 < 4; var_s5++) {
                        if (sp58[var_s5] == var_s2) {
                          *arg4 += 20;
                          break;
                        }
                      }
                      FUN_800413c0_twentyfive_liner(var_s3, sp57, var_s4, 7);
                      CurrentPiece_80067dd8_big_fiftyliner(var_s1);
                      return TRUE;
                    }
                  }
                }

                for (var_s0 = 0; var_s0 < 19; var_s0++) {
                  if (FUN_005580_8003f4f4_thirtyliner_nested_loops(sp44, 1, sp54, var_s0) && aisquarelist_8003e68c_hugeliner_many_loops(arg0, sp56, sp55, sp54, arg4, arg5)) {
                    for (var_s5 = 0; var_s5 < 4; var_s5++) {
                      if (sp58[var_s5] == var_s2) {
                        *arg4 += 20;
                        break;
                      }
                    }

                    FUN_800413c0_twentyfive_liner(var_s3, sp57, var_s4, 7);
                    CurrentPiece_80067dd8_big_fiftyliner(var_s1);
                    return TRUE;
                  }
                }
              }
            }

            FUN_800413c0_twentyfive_liner(var_s3, sp57, var_s4, 7);
            if ((sp57 == 0) || FUN_8004191c_sixliner_loop_shift_right(var_s3, sp57)) {
              break;
            }
          }
        }
      }
    }
  }

  *arg4 = 0;
  CurrentPiece_80067dd8_big_fiftyliner(var_s1);
  return FALSE;
}

u8 aisquarelist_8003ed40_largeliner_many_loops(UnkStruct_107 *arg0, u8 arg1, u8 *arg2, u8 arg3, u8 arg4) {
  register u8 var_s0;
  register u8 var_s1;
  register u8 var_s2;
  register u8 var_s3;
  register UnkStruct_106 *temp_s4;
  register UnkStruct_99 *temp_s5;
  register UnkStruct_27 *temp_s6;
  register UnkStruct_108 *temp_s7;
  u8 sp5B;
  u8 sp5A;
  u8 sp59;
  u8 sp58;
  u8 sp57;
  u8 sp56;
  u8 sp55;
  s16 sp52;
  s8 sp40[4][4];

  var_s0 = *arg2;
  temp_s4 = &arg0->unk7[arg0->unk1[arg1]];
  for (var_s1 = 0; var_s1 < D_800E1F20->unk0[arg3]; var_s1++) {
    if (var_s0 >= 200) {
      debug_print_reason_routine("NOT ENOUGH AI SCORES", "AISQUARELIST.C");
      var_s0 = 200;
      *arg2 = var_s0;
      return FALSE;
    }

    temp_s7 = &D_800E1F20->unk2[arg3][var_s1];
    sp5B = temp_s7->unk0;
    sp5A = temp_s7->unk1;
    sp59 = temp_s7->unk2;
    if ((temp_s4->unk0 <= sp5B) && (sp5B <= (temp_s4->unk0 + 3)) && (temp_s4->unk1 <= sp5A) && (sp5A <= (temp_s4->unk1 + 3))) {
      FUN_800413c0_twentyfive_liner(sp5B, sp5A, sp59, 8);
      sp52 = 0;
      if (check_square_completion(temp_s4->unk0, temp_s4->unk1, &sp56, &sp58, &sp57)) {
        if (sp58 == 4) {
          temp_s5 = &(*D_800E1F40)[var_s0];
          temp_s5->unk2.unk0 = sp5B;
          temp_s5->unk2.unk1 = sp5A;
          temp_s5->unk2.unk2 = sp59;
          temp_s5->unk0 = 0x7FFF;
          FUN_006930_80040784_nested_loop_20t_inside_loop_10t(&temp_s5->unk5, NULL, NULL, &temp_s5->unk6);
          FUN_800413c0_twentyfive_liner(sp5B, sp5A, sp59, 7);
          var_s0++;
          *arg2 = var_s0;
          return TRUE;
        }

        for (var_s3 = 0; var_s3 < 4; var_s3++) {
          for (var_s2 = 0; var_s2 < 4; var_s2++) {
            sp40[var_s2][var_s3] = 0;
          }
        }

        if (!(FUN_005580_8003f300_fourteenliner_recursive(sp40, temp_s4->unk0, temp_s4->unk1, temp_s4->unk0, temp_s4->unk1) % 4)) {
          for (var_s3 = 0; var_s3 < 4; var_s3++) {
            for (var_s2 = 0; var_s2 < 4; var_s2++) {
              temp_s6 = &D_800E1F30->unk0[var_s2 + temp_s4->unk0 + ((var_s3 + temp_s4->unk1) * 10)];
              if (temp_s6->unk0 == EMPTY_CELL) {
                sp40[var_s2][var_s3] = -1;
              } else {
                sp40[var_s2][var_s3] = temp_s6->unk1;
              }
            }
          }

          if (sp56 == 0) {
            for (var_s2 = 0; var_s2 < 5; var_s2++) {
              if ((FUN_005580_8003f4f4_thirtyliner_nested_loops(sp40, 0, sp57, var_s2) != 0) && (aisquarelist_8003e68c_hugeliner_many_loops(temp_s4, 0, sp58, sp57, &sp52, arg4))) {
                sp52 += 20;
              }
            }
          }

          for (var_s2 = 0; var_s2 < 19; var_s2++) {
            sp55 = FUN_005580_8003f4f4_thirtyliner_nested_loops(sp40, 1, sp57, var_s2);
            if ((sp55 != 0) && (aisquarelist_8003e68c_hugeliner_many_loops(temp_s4, 1, sp58, sp57, &sp52, arg4))) {
              sp52 += sp55 * 10;
            }
          }
          if (sp52 != 0) {
            sp52 += D_800C55A0[sp58];
          }
        }
      }

      if (sp52 != 0) {
        temp_s5 = &(*D_800E1F40)[var_s0];
        temp_s5->unk2.unk0 = sp5B;
        temp_s5->unk2.unk1 = sp5A;
        temp_s5->unk2.unk2 = sp59;
        temp_s5->unk0 = sp52;
        FUN_006930_80040784_nested_loop_20t_inside_loop_10t(&temp_s5->unk5, NULL, NULL, &temp_s5->unk6);
        var_s0++;
      }
      FUN_800413c0_twentyfive_liner(sp5B, sp5A, sp59, 7);
    }
  }
  *arg2 = var_s0;
  return FALSE;
}
