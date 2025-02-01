#include "common.h"

PlayerVars g_PV_arr[4];
PlayerVars *g_PV_ptr;

static void   func_8005360C(void);

void FUN_80053500_fiveliner(void) {
  D_800CFED4 = 1;
  FUN_026900_8006093c_rounds_floors_loops_1024t();  // sinf table
  func_80075DF4();  // cubetiles
  initPieceColorsScale16();
}

void FUN_80053538_fiveliner(void) {
  s16 i;

  for (i = 0; i < 4; i++) {
    bzero(&g_PV_arr[i], sizeof(PlayerVars));
  }
}

void PV_set_controller_no(s16 cont_no) {
  g_PV_ptr->cont_no = cont_no;
}

void FUN_800535B8_fiveliner(PlayerVars *PV_ptr) {
  FUN_026900_nineliner_loops_32t(&PV_ptr->unk28);
  PV_ptr->unk24 = 0;
  PV_ptr->unk1C->unk0 = 0;
  func_800A3460(&PV_ptr->contQ);
}

static void func_8005360C(void) {
  if ((&g_PV_arr[0] != g_PV_ptr) && (&g_PV_arr[1] != g_PV_ptr) && (&g_PV_arr[2] != g_PV_ptr) && (&g_PV_arr[3] != g_PV_ptr)) {
    debug_print_reason_routine("PV does not point to a valid PlayerVars object", "");
  }
}
