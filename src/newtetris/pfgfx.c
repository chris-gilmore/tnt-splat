#include "common.h"

PfGfx *g_pfGfx_ptr;

static UnkStruct_26 D_800D01A0[8] = {
  { {0x00D7, 0x0031 },  { 0x00D7, 0x0077} },
  { {0x00E1, 0x0031 },  { 0x00E1, 0x0077} },
  { {0x00D7, 0x0031 },  { 0x00D7, 0x0077} },
  { {0x00D7, 0x0031 },  { 0x00D7, 0x0084} },
  { {0x00DC, 0x004B },  { 0x00DC, 0x0084} },
  { {0x00D6, 0x0031 },  { 0x00D6, 0x0077} },
  { {0x00DC, 0x0044 },  { 0x00DC, 0x0078} },
  { {0x00DC, 0x0031 },  { 0x00DC, 0x0078} }
};

static UnkStruct_26 D_800D01E0[8][2] = {
  {
    { {0x00B8, 0x0031},  {0x00B8, 0x0081} },
    { {0x00DE, 0x0031},  {0x00DE, 0x0081} }  //{ {0x0179, 0x0031},  {0x0179, 0x0081} }
  },
  {
    { {0x00B5, 0x0048},  {0x00B5, 0x00A0} },
    { {0x00E0, 0x0048},  {0x00E0, 0x00A0} }
  },
  {
    { {0x00B8, 0x003C},  {0x00B8, 0x0081} },
    { {0x00DE, 0x003C},  {0x00DE, 0x0081} }
  },
  {
    { {0x00B5, 0x0037},  {0x00B5, 0x007D} },
    { {0x00E0, 0x0037},  {0x00E0, 0x007D} }
  },
  {
    { {0x00B5, 0x0041},  {0x00B5, 0x0081} },
    { {0x00E0, 0x0041},  {0x00E0, 0x0081} }
  },
  {
    { {0x00B5, 0x0037},  {0x00B5, 0x007A} },
    { {0x00E0, 0x0037},  {0x00E0, 0x007A} }
  },
  {
    { {0x00B8, 0x0031},  {0x00B8, 0x0081} },
    { {0x00DE, 0x0031},  {0x00DE, 0x0081} }
  },
  {
    { {0x00B8, 0x0031},  {0x00B8, 0x0081} },
    { {0x00DE, 0x0031},  {0x00DE, 0x0081} }
  }
};

static void   PFGFX_8005fc70_doesnothing(void);
static void   PFGFX_SetTextDisplayPos_1p(u8);
static void   PFGFX_SetTextDisplayPos_2p(u8);
static void   PFGFX_SetTextDisplayPos_3p(u8);
static void   PFGFX_SetTextDisplayPos_4p(u8);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/pfgfx/PFGFX_8005fa80_twoliner_calls_fun.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/pfgfx/PFGFX_8005fab8_oneliner_calls_fun.s")

void PFGFX_Sets_x58_x59_Checks_NumPlayers_CurrPlayer(void) {
  register PfGfx *pfGfx_ptr = g_pfGfx_ptr;

  switch (g_playercount) {
  case 1:
    pfGfx_ptr->unkB0.x = 0x14C, pfGfx_ptr->unkB0.y = 0x90;
    break;
  case 2:
    switch (g_currentplayer) {
    case 0:
      pfGfx_ptr->unkB0.x = 0xE4, pfGfx_ptr->unkB0.y = 0xAC;
      break;
    case 1:
      pfGfx_ptr->unkB0.x = 0x3DC, pfGfx_ptr->unkB0.y = 0xAC;
      break;
    }
    break;
  case 3:
    switch (g_currentplayer) {
    case 0:
      pfGfx_ptr->unkB0.x = 0x88, pfGfx_ptr->unkB0.y = 0x110;
      break;
    case 1:
      pfGfx_ptr->unkB0.x = 0x1D8, pfGfx_ptr->unkB0.y = 0x110;
      break;
    case 2:
      pfGfx_ptr->unkB0.x = 0x328, pfGfx_ptr->unkB0.y = 0x110;
      break;
    }
    break;
  case 4:
    switch (g_currentplayer) {
    case 0:
      pfGfx_ptr->unkB0.x = 0x88, pfGfx_ptr->unkB0.y = 0x110;
      break;
    case 1:
      pfGfx_ptr->unkB0.x = 0x1D8, pfGfx_ptr->unkB0.y = 0x110;
      break;
    case 2:
      pfGfx_ptr->unkB0.x = 0x328, pfGfx_ptr->unkB0.y = 0x110;
      break;
    case 3:
      pfGfx_ptr->unkB0.x = 0x478, pfGfx_ptr->unkB0.y = 0x110;
      break;
    }
    break;
  }
}

static void PFGFX_8005fc70_doesnothing(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/pfgfx/GameCamera_Render.s")

Point *PFGFX_Init(Point *arg0, PfGfx *arg1) {
  Point p;

  p.x = arg1->unkB0.x >> 2;
  p.y = arg1->unkB0.y >> 2;
  *arg0 = p;
  return arg0;
}

static void PFGFX_SetTextDisplayPos_1p(u8 screen) {
  UnkStruct_17 sp28;
  Point sp1C[3];

  Minos_80070c40_twoliner_set_OR_1(0xB00);
  Minos_80070c70_threeliner_set_OR_8(0x500, 0xA00);
  Minos_80070cb8_threeliner_set_OR_4(g_pfGfx_ptr->unkB0.x, g_pfGfx_ptr->unkB0.y);
  Minos_80070a34_twentyliner();
  sp1C[0] = D_800D01A0[screen].unk0;
  sp1C[2] = D_800D01A0[screen].unk4;
  sp1C[1].x = (sp1C[0].x + sp1C[2].x) >> 1;
  sp1C[1].y = (sp1C[0].y + sp1C[2].y) >> 1;
  Minos_8007104c_fiveliner_nuts(&sp28.unk0[0], sp1C[0].x << 2, sp1C[0].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp28.unk0[1], sp1C[1].x << 2, sp1C[1].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp28.unk0[2], sp1C[2].x << 2, sp1C[2].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp28.unk0[3], sp1C[2].x << 2, sp1C[2].y << 2);
  sp28.unk10 = 0xFF;
  sp28.unk11 = 0xFF;
  sp28.unk12 = 0xC0;
  sp28.unk14 = 0xC0;
  NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(&sp28);
  g_gameStats_ptr->linesInfo.x = 295;
  g_gameStats_ptr->linesInfo.y = 183;
}

static void PFGFX_SetTextDisplayPos_2p(u8 screen) {
  UnkStruct_17 sp38;
  Point sp2C[3];
  u8 currentplayer;

  Minos_80070c40_twoliner_set_OR_1(0xA00);
  Minos_80070c70_threeliner_set_OR_8(0x500, 0xA00);
  Minos_80070cb8_threeliner_set_OR_4(g_pfGfx_ptr->unkB0.x, g_pfGfx_ptr->unkB0.y);
  Minos_80070a34_twentyliner();
  currentplayer = g_currentplayer;
  sp2C[0] = D_800D01E0[screen][currentplayer].unk0;
  sp2C[2] = D_800D01E0[screen][currentplayer].unk4;
  sp2C[1].x = (sp2C[0].x + sp2C[2].x) >> 1;
  sp2C[1].y = (sp2C[0].y + sp2C[2].y) >> 1;
  Minos_8007104c_fiveliner_nuts(&sp38.unk0[0], sp2C[0].x << 2, sp2C[0].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp38.unk0[1], sp2C[1].x << 2, sp2C[1].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp38.unk0[2], sp2C[2].x << 2, sp2C[2].y << 2);
  Minos_8007104c_fiveliner_nuts(&sp38.unk0[3], sp2C[2].x << 2, sp2C[2].y << 2);
  sp38.unk10 = 0xFF;
  sp38.unk11 = 0xFF;
  sp38.unk12 = 0xC0;
  sp38.unk14 = 0xC0;
  NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(&sp38);
  switch (g_currentplayer) {
  case 0:
    g_gameStats_ptr->linesInfo.x = 169;
    g_gameStats_ptr->linesInfo.y = 186;
    break;
  case 1:
    g_gameStats_ptr->linesInfo.x = 169;
    g_gameStats_ptr->linesInfo.y = 217;
    break;
  }
}

static void PFGFX_SetTextDisplayPos_3p(u8 screen) {
  UnkStruct_17 sp28;

  Minos_80070c40_twoliner_set_OR_1(0x800);
  Minos_80070c70_threeliner_set_OR_8(0x500, 0xA00);
  Minos_80070cb8_threeliner_set_OR_4(g_pfGfx_ptr->unkB0.x, g_pfGfx_ptr->unkB0.y);
  Minos_80070a34_twentyliner();
  sp28.unk0[0].x = 0x100;
  sp28.unk0[0].y = -0x500;
  sp28.unk0[1].x = 0x480;
  sp28.unk0[1].y = -0x500;
  sp28.unk0[2].x = 0x800;
  sp28.unk0[2].y = -0x500;
  sp28.unk0[3].x = 0x800;
  sp28.unk0[3].y = -0x500;
  sp28.unk10 = 0x80;
  sp28.unk11 = 0xFF;
  sp28.unk12 = 0x80;
  sp28.unk14 = 0xD8;
  NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(&sp28);
  switch (g_currentplayer) {
  case 0:
    g_gameStats_ptr->linesInfo.x = 39;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  case 1:
    g_gameStats_ptr->linesInfo.x = 123;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  case 2:
    g_gameStats_ptr->linesInfo.x = 207;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  }
}

static void PFGFX_SetTextDisplayPos_4p(u8 screen) {
  UnkStruct_17 sp28;

  Minos_80070c40_twoliner_set_OR_1(0x800);
  Minos_80070c70_threeliner_set_OR_8(0x500, 0xA00);
  Minos_80070cb8_threeliner_set_OR_4(g_pfGfx_ptr->unkB0.x, g_pfGfx_ptr->unkB0.y);
  Minos_80070a34_twentyliner();
  sp28.unk0[0].x = 0x100;
  sp28.unk0[0].y = -0x500;
  sp28.unk0[1].x = 0x480;
  sp28.unk0[1].y = -0x500;
  sp28.unk0[2].x = 0x800;
  sp28.unk0[2].y = -0x500;
  sp28.unk0[3].x = 0x800;
  sp28.unk0[3].y = -0x500;
  sp28.unk10 = 0xC0;
  sp28.unk11 = 0xFF;
  sp28.unk12 = 0x80;
  sp28.unk14 = 0xD8;
  NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(&sp28);
  switch (g_currentplayer) {
  case 0:
    g_gameStats_ptr->linesInfo.x = 39;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  case 1:
    g_gameStats_ptr->linesInfo.x = 123;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  case 2:
    g_gameStats_ptr->linesInfo.x = 207;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  case 3:
    g_gameStats_ptr->linesInfo.x = 292;
    g_gameStats_ptr->linesInfo.y = 248;
    break;
  }
}

void PFGFX_Playfield_Init(u8 screen) {
  PFGFX_Sets_x58_x59_Checks_NumPlayers_CurrPlayer();
  switch (g_playercount) {
  case 1:
    PFGFX_SetTextDisplayPos_1p(screen);
    break;
  case 2:
    PFGFX_SetTextDisplayPos_2p(screen);
    break;
  case 3:
    PFGFX_SetTextDisplayPos_3p(screen);
    break;
  case 4:
    PFGFX_SetTextDisplayPos_4p(screen);
    break;
  default:
    debug_print_reason_routine("Playfield:Init invalid playercount", "pfgfx.c");
    break;
  }
}

void PFGFX_80060654_doesnothing(void) {
  PFGFX_8005fc70_doesnothing();
}
