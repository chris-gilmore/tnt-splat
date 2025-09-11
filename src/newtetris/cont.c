#include "common.h"

#ifndef H2O_DEBUG
#define H2O_DEBUG_PRINT1(f_) (f_)
#define H2O_DEBUG_PRINT2(f_, a_) (f_)
#define H2O_DEBUG_PRINT3(f_, a_, b_) (f_)
#else
#define H2O_DEBUG_PRINT1(f_) rmonPrintf((f_))
#define H2O_DEBUG_PRINT2(f_, a_) rmonPrintf((f_), (a_))
#define H2O_DEBUG_PRINT3(f_, a_, b_) rmonPrintf((f_), (a_), (b_))
#endif

void func_800B1770(Controller *arg0, OSContPad *arg1) {
  u32 temp_v0 = arg1->button;
  s32 var_v0 = 0;

  arg0->unk4 = arg0->unk0;
  arg0->unk0 = temp_v0;
  arg0->unk8 = (arg0->unk4 ^ -1) & arg0->unk0;

  arg0->unkC  = (temp_v0 & 0x800)  ? arg0->unkC  + 1 : 0;  // U_JPAD / CONT_UP
  arg0->unk10 = (temp_v0 & 0x400)  ? arg0->unk10 + 1 : 0;  // D_JPAD / CONT_DOWN
  arg0->unk14 = (temp_v0 & 0x100)  ? arg0->unk14 + 1 : 0;  // R_JPAD / CONT_RIGHT
  arg0->unk18 = (temp_v0 & 0x200)  ? arg0->unk18 + 1 : 0;  // L_JPAD / CONT_LEFT
  arg0->unk1C = (temp_v0 & 0x8)    ? arg0->unk1C + 1 : 0;  // U_CBUTTONS / CONT_E
  arg0->unk20 = (temp_v0 & 0x4)    ? arg0->unk20 + 1 : 0;  // D_CBUTTONS / CONT_D
  arg0->unk24 = (temp_v0 & 0x1)    ? arg0->unk24 + 1 : 0;  // R_CBUTTONS / CONT_F
  arg0->unk28 = (temp_v0 & 0x2)    ? arg0->unk28 + 1 : 0;  // L_CBUTTONS / CONT_C
  arg0->unk2C = (temp_v0 & 0x20)   ? arg0->unk2C + 1 : 0;  // L_TRIG / CONT_L
  arg0->unk30 = (temp_v0 & 0x10)   ? arg0->unk30 + 1 : 0;  // R_TRIG / CONT_R
  arg0->unk34 = (temp_v0 & 0x2000) ? arg0->unk34 + 1 : 0;  // Z_TRIG / CONT_G
  if (temp_v0 & 0x1000) {  // START_BUTTON / CONT_START
    arg0->unk38++;
    arg0->unk3C++;
  } else {
    arg0->unk3C = 0;
    arg0->unk38 = 0;
  }
  arg0->unk40 = (temp_v0 & 0x8000) ? arg0->unk40 + 1 : 0;  // A_BUTTON / CONT_A
  arg0->unk44 = (temp_v0 & 0x4000) ? arg0->unk44 + 1 : 0;  // B_BUTTON / CONT_B


  arg0->unk4C = arg1->stick_x;  // OSContPad->stick_x
  arg0->unk4E = arg1->stick_y;  // OSContPad->stick_y

  var_v0 = (arg0->unk4C >= 0) ? arg0->unk4C : -arg0->unk4C;
  if (var_v0 < arg0->unk48) {   // stick_x dead-zone
    arg0->unk4C = 0;
  }

  var_v0 = (arg0->unk4E >= 0) ? arg0->unk4E : -arg0->unk4E;
  if (var_v0 < arg0->unk4A) {   // stick_y dead-zone
    arg0->unk4E = 0;
  }

  if (arg0->unk4C >= 0x51) {    // stick_x max 80
    arg0->unk4C = 0x50;
  }
  if (arg0->unk4E >= 0x51) {    // stick_y max 80
    arg0->unk4E = 0x50;
  }
  if (arg0->unk4C < -0x50) {    // stick_x min -80
    arg0->unk4C = -0x50;
  }
  if (arg0->unk4E < -0x50) {    // stick_y min -80
    arg0->unk4E = -0x50;
  }

  arg0->unk50 = (arg0->unk4C * 0xFF) / 80;  // scale stick_x to range [-255, 255]
  arg0->unk52 = (arg0->unk4E * 0xFF) / 80;  // scale stick_y to range [-255, 255]
}

void func_800B1A7C(Controller *arg0) {
  bzero(arg0, sizeof(Controller));
  H2O_DEBUG_PRINT2("_Controller Size: %d\n", sizeof(Controller));

  arg0->unk48 = 8;  // stick_x dead-zone 10% (8/80)
  arg0->unk4A = 8;  // stick_y dead-zone 10% (8/80)
  H2O_DEBUG_PRINT3("Cont->DeadX,Cont->DeadY Set to: (%d,%d)\n", arg0->unk48, arg0->unk4A);
}
