#include "common.h"

static void func_80073BD0(UnkStruct_29 *);
static void func_80073C60(UnkStruct_29 *);
static void func_80073D70(UnkStruct_29 *);
static void func_80074024(UnkStruct_29 *);

static void func_80073BD0(UnkStruct_29 *arg0) {
  register u8 var_a1 = arg0->unk0;
  register u8 playercount = g_playercount;

  do {
    arg0->unk0 = (arg0->unk0 + 1) % playercount;
    if (g_landfill_ptr->list[arg0->unk0].unk0) {
      break;
    }
  } while (arg0->unk0 != var_a1);
}

static void func_80073C60(UnkStruct_29 *arg0) {
  register u32 var_s0;
  register u32 var_s1;
  register s32 var_s2;
  register s32 var_s3;
  register s32 var_s4;

  var_s0 = func_8007232C();
  if (var_s0 > 1) {
    if (var_s0 == 2) {
      func_80073BD0(arg0);
    } else {
      var_s1 = func_8007232C() - 1;
      var_s2 = FUN_026900_PRNG_1() % var_s1;
      for (var_s3 = 0; var_s3 <= var_s2; var_s3++) {
        func_80073BD0(arg0);
      }
    }

    for (var_s4 = 0; var_s4 < g_playercount; var_s4++) {
      Landfill_8007240c_fiveliner(var_s4, arg0->unk0);
    }

    arg0->unk1 = FALSE;
  }
}

static void func_80073D70(UnkStruct_29 *arg0) {
  register PfGfx *pfGfx_ptr = &g_game.tetris_ptr_arr[arg0->unk0]->pfGfx;
  Point sp48;
  register Gfx *gdl = g_gdl;

  sp48.x = pfGfx_ptr->unkB0.x >> 2;
  sp48.y = 243;

  arg0->unk8 = (sins(arg0->unk12) >> 9) + 160;
  arg0->unk12 += 0x800;

  gDPPipeSync(gdl++);
  gDPSetCycleType(gdl++, G_CYC_1CYCLE);
  gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
  gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
  gDPSetPrimColor(gdl++, 0, 0, arg0->unk2, arg0->unk4, arg0->unk6, arg0->unk8);
  gDPFillRectangle(gdl++, sp48.x, sp48.y, sp48.x + 100, sp48.y + 2);
  gDPFillRectangle(gdl++, sp48.x - 3, sp48.y - 200, sp48.x, sp48.y + 3);
  gDPFillRectangle(gdl++, sp48.x + 100, sp48.y - 200, sp48.x + 103, sp48.y + 3);
  gDPPipeSync(gdl++);

  g_gdl = gdl;
}

static void func_80074024(UnkStruct_29 *arg0) {
  register PfGfx *pfGfx_ptr = &g_game.tetris_ptr_arr[arg0->unk0]->pfGfx;
  Point sp50;
  register Gfx *gdl = g_gdl;

  sp50.x = pfGfx_ptr->unkB0.x >> 2;
  sp50.y = 228;

  arg0->unk8 = (sins(arg0->unk12) >> 9) + 160;
  arg0->unk12 += 0x800;

  gDPPipeSync(gdl++);
  gDPSetCycleType(gdl++, G_CYC_1CYCLE);
  gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
  gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
  gDPSetPrimColor(gdl++, 0, 0, arg0->unk2, arg0->unk4, arg0->unk6, arg0->unk8);
  gDPFillRectangle(gdl++, sp50.x - 3, sp50.y - 160, sp50.x, sp50.y + 3);
  gDPFillRectangle(gdl++, sp50.x + 80, sp50.y - 160, sp50.x + 83, sp50.y + 3);
  gDPPipeSync(gdl++);
  gDPSetPrimColor(gdl++, 0, 0, arg0->unkA, arg0->unkC, arg0->unkE, arg0->unk10);
  gDPFillRectangle(gdl++, sp50.x, sp50.y - 160, sp50.x + 80, sp50.y);
  gDPPipeSync(gdl++);

  g_gdl = gdl;
}

void HotPotato_Render(UnkStruct_29 *arg0) {
  if (arg0->unk1) {
    func_80073C60(arg0);
  }

  switch (g_playercount) {
  case 1:
    break;
  case 2:
    func_80073D70(arg0);
    break;
  case 3:
  case 4:
    func_80074024(arg0);
    break;
  default:
    debug_print_reason_routine("Invalid player count for HotPotato", "HotPotato_Render(), hotpotato.c");
    break;
  }
}

void HotPotato_Init(UnkStruct_29 *arg0) {
  arg0->unk0 = FUN_026900_PRNG_1() % g_playercount;
  arg0->unk1 = FALSE;

  arg0->unk2 = 0xFF;
  arg0->unk4 = 0;
  arg0->unk6 = 0;
  arg0->unk8 = 0xFF;

  arg0->unkA = 0xFF;
  arg0->unkC = 0xFF;
  arg0->unkE = 0xFF;
  arg0->unk10 = 0x20;

  arg0->unk12 = 0;
}

void HotPotato_Deinit(UnkStruct_29 *arg0) {
}
