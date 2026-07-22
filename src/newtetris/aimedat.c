#include "common.h"

static void *D_8011FC90;

static Point D_800D05E0[4] = {
  { 0, 0 },
  { 7, 0 },
  { 14, 0 },
  { 21, 0 },
};
static RGB D_800D05F0[4] = {
  { 0xFF, 0, 0 },
  { 0, 0xFF, 0 },
  { 0, 0, 0xFF },
  { 0xFF, 0xFF, 0 },
};
static u8 D_800D05FC[3] = { 0x80, 0x80, 0x80 };

static void func_80073130(UnkStruct_111 *, u8);
static void func_80073170(UnkStruct_111 *);
static void func_80073178(UnkStruct_111 *, u8, u8);
static void func_8007318C(UnkStruct_111 *, u8);
static void func_800731EC(UnkStruct_111 *);
static void func_800733F0(UnkStruct_112 *);
static void func_800737FC(UnkStruct_112 *);

static void func_80073130(UnkStruct_111 *arg0, u8 arg1) {
  register s32 i;

  arg0->unk0 = TRUE;
  for (i = 0; i < 4; i++) {
    arg0->unk1[i] = TRUE;
  }
  arg0->unkA = arg1;
}

static void func_80073170(UnkStruct_111 *arg0) {
}

static void func_80073178(UnkStruct_111 *arg0, u8 arg1, u8 arg2) {
  arg0->unk1[arg1] = arg2;
}

void func_8007318C(UnkStruct_111 *arg0, u8 arg1) {
  register s32 i;

  for (i = 0; i < 4; i++) {
    func_80073178(arg0, i, arg1);
  }

  arg0->unk0 = arg1;
}

static void func_800731EC(UnkStruct_111 *arg0) {
  register s32 x;
  register s32 y;
  register s32 i;

  x = arg0->unk6.x;
  y = arg0->unk6.y;

  for (i = 0; i < 4; i++) {
    if (!arg0->unk1[i]) {
      gDPPipeSync(g_gdl++);

      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FC90, NULL, x + D_800D05E0[i].x, y + D_800D05E0[i].y, D_800D05FC[0], D_800D05FC[1], D_800D05FC[2], 0xFF);
    }
  }

  if (arg0->unk0) {
    register s32 temp_s3 = arg0->unkA;

    gDPPipeSync(g_gdl++);

    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FC90, NULL, x + D_800D05E0[temp_s3].x, y + D_800D05E0[temp_s3].y, D_800D05F0[temp_s3].r, D_800D05F0[temp_s3].g, D_800D05F0[temp_s3].b, 0xFF);
  }
}

static void func_800733F0(UnkStruct_112 *arg0) {
  register Gfx *gdl = g_gdl;
  register s32 i;

  gDPPipeSync(gdl++);
  gDPSetCycleType(gdl++, G_CYC_1CYCLE);
  gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
  gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

  for (i = 0; i < g_playercount; i++) {
    register PfGfx *pfGfx_ptr = &g_game.tetris_ptr_arr[i]->pfGfx;
    Point sp10;

    sp10.x = pfGfx_ptr->unkB0.x >> 2;
    sp10.y = 228;

    gDPSetPrimColor(gdl++, 0, 0, arg0->color[i].red, arg0->color[i].green, arg0->color[i].blue, arg0->color[i].alpha);
    gDPFillRectangle(gdl++, sp10.x, sp10.y, sp10.x + 80, sp10.y + 2);
  }

  gDPPipeSync(gdl++);

  g_gdl = gdl;
}

void AimedAt_Render(UnkStruct_112 *arg0) {
  register s32 i;

  if (arg0->numIndicators < 4) {
    return;
  }

  func_800733F0(arg0);

  func_8005BBFC(&g_gdl);
  for (i = 0; i < arg0->numIndicators; i++) {
    func_800731EC(arg0->list + i);
  }
  func_8005BE40(&g_gdl);
}

// unused
void func_80073688(UnkStruct_112 *arg0) {
}

void func_80073690(UnkStruct_112 *arg0, u8 arg1, u8 arg2, u8 arg3) {
  func_80073178(arg0->list + arg1, arg2, arg3);
}

void func_800736E0(UnkStruct_112 *arg0, u8 arg1, u8 arg2) {
  register s32 i;

  for (i = 0; i < arg0->numIndicators; i++) {
    func_80073178(arg0->list + i, arg1, arg2);
  }

  func_8007318C(arg0->list + arg1, arg2);
}

void func_80073784(UnkStruct_112 *arg0, u8 arg1) {
  register s32 i;

  for (i = 0; i < arg0->numIndicators; i++) {
    func_8007318C(arg0->list + i, arg1);
  }
}

static void func_800737FC(UnkStruct_112 *arg0) {
  arg0->list[0].unk6.x = 61;
  arg0->list[0].unk6.y = 267;

  arg0->list[1].unk6.x = 145;
  arg0->list[1].unk6.y = 267;

  arg0->list[2].unk6.x = 230;
  arg0->list[2].unk6.y = 267;

  arg0->list[3].unk6.x = 314;
  arg0->list[3].unk6.y = 267;

  arg0->color[0].red   = D_800D05F0[0].r;
  arg0->color[0].green = D_800D05F0[0].g;
  arg0->color[0].blue  = D_800D05F0[0].b;
  arg0->color[0].alpha = 0x80;

  arg0->color[1].red   = D_800D05F0[1].r;
  arg0->color[1].green = D_800D05F0[1].g;
  arg0->color[1].blue  = D_800D05F0[1].b;
  arg0->color[1].alpha = 0x80;

  arg0->color[2].red   = D_800D05F0[2].r;
  arg0->color[2].green = D_800D05F0[2].g;
  arg0->color[2].blue  = D_800D05F0[2].b;
  arg0->color[2].alpha = 0x80;

  arg0->color[3].red   = D_800D05F0[3].r;
  arg0->color[3].green = D_800D05F0[3].g;
  arg0->color[3].blue  = D_800D05F0[3].b;
  arg0->color[3].alpha = 0x80;
}

void func_80073940(UnkStruct_112 *arg0) {
  register u8 playercount = g_playercount;
  register s32 i;

  if (playercount < 3) {
    arg0->numIndicators = g_playercount;
  } else {
    arg0->numIndicators = 4;
  }

  arg0->list = n64HeapAlloc(arg0->numIndicators * sizeof(UnkStruct_111));

  for (i = 0; i < arg0->numIndicators; i++) {
    func_80073130(arg0->list + i, i);
  }

  switch (arg0->numIndicators) {
  case 1:
  case 2:
    break;
  case 3:
    debug_print_reason_routine_linenum("Invalid numIndicators", "aimedat.c", 399);
    break;
  case 4:
    func_800737FC(arg0);
    break;
  default:
    debug_print_reason_routine_linenum("Invalid numIndicators", "aimedat.c", 407);
    break;
  }

  if (playercount == 3) {
    func_800736E0(arg0, 3, FALSE);
  }
}

void func_80073AC4(UnkStruct_112 *arg0) {
  register s32 i;

  for (i = 0; i < arg0->numIndicators; i++) {
    func_80073170(arg0->list + i);
  }

  n64HeapUnalloc(arg0->list);
}

void AimedAt_Init(void) {
  main_8004A34C_threeliner();
  D_8011FC90 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_INDICATOR));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_8011FC90, IMG_INDICATOR);
}

void AimedAt_Deinit(void) {
  n64HeapUnalloc(D_8011FC90);
}
