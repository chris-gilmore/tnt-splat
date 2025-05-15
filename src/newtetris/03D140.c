#include "common.h"

static void   func_80076F20(UnkStruct_11 *);

// init
void func_80076EC0(UnkStruct_11 *arg0, u8 arg1) {
  func_80076F20(arg0);
  if (arg1) {
    func_800A4590(arg0->unk0);
    func_800A45D8(arg0->unk0);
  }
}

static void func_80076F20(UnkStruct_11 *arg0) {
  if (arg0->unk28 != 0) {
    arg0->unk0 = func_800A6990(arg0->unk28);
  }
  if (arg0->unk2C != 0) {
    arg0->unk4 = func_800A6A74(arg0->unk2C);
    if (arg0->unk28 == 0) {
      arg0->unk0 = func_800A6990((s32)arg0->unk4->unk20);
    }
    func_800A678C(arg0->unk0, arg0->unk4);
  }
  if (arg0->unk20 == 0) {
    arg0->unk20 |= 0x1B;
  }
  guMtxIdentF(arg0->unk0->unkC);
  guMtxIdentF(arg0->unk0->unk4C);
}

// deinit
void func_80077028(UnkStruct_11 *arg0) {
  if (arg0->unk4 != NULL) {
    func_800A6AA8(arg0->unk4);
    arg0->unk4 = NULL;
  }
  if (arg0->unk0 != NULL) {
    func_800A6A2C(arg0->unk0);
    arg0->unk0 = NULL;
  }
}

// render
void func_80077098(UnkStruct_11 *arg0) {
  register u8 var_s0;

  if (arg0->unk0 == NULL) {
    return;
  }

  if (arg0->unk2C != 0) {
    if (arg0->unk20 & 2) {
      func_800A4698(arg0->unk0);
      func_800A46C0(arg0->unk0, 0);
      arg0->unk20 &= ~2;
    }
    if (arg0->unk20 & 4) {
      arg0->unk20 = arg0->unk20 | 1;
    }
    if (arg0->unk20 & 1) {
      var_s0 = func_800A3AF0();
    } else {
      var_s0 = 0;
    }
    if (arg0->unk20 & 4) {
      var_s0 = 2;
    }
    func_800A46C0(arg0->unk0, var_s0);
  }
  if (arg0->unk20 & 0x10) {
    func_800A3BF8(arg0->unk0, arg0->unk14, arg0->unk18, arg0->unk1C);
  }
  if (arg0->unk20 & 8) {
    func_800A3B00(arg0->unk0, arg0->unk8, arg0->unkC, arg0->unk10);
  }

  gDPPipeSync(g_gdl++);
  gDPSetScissor(g_gdl++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
  gSPClipRatio(g_gdl++, FRUSTRATIO_1);

  g_gdl = func_800A724C(g_gdl, arg0->unk0);

  if (arg0->unk2C != 0) {
    if (arg0->unk20 & 4) {
      arg0->unk20 &= ~1;
      arg0->unk20 &= ~4;
    }
  }
}

void func_800773A4(UnkStruct_11 *arg0) {
  arg0->unk20 |= 1;
}

void func_800773B8(UnkStruct_11 *arg0) {
  arg0->unk20 &= ~1;
}
