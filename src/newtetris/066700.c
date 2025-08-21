#include "common.h"

UnkStruct_78 D_801290D0;
UnkStruct_78 D_80129208;

static void   func_800A0480(void *);
static void   func_800A0494(void *);
static void   func_800A04A8(GUI_Textbox *);
extern /* static */ void   func_800A04F4(GUI_Textbox *);
extern /* static */ void   func_800A06D0(GUI_Textbox *);
static void   func_800A08A0(GUI_Textbox *);
static void   func_800A08EC(GUI_Slider *);
static void   func_800A097C(GUI_Slider *);
static void   func_800A0A08(void);
extern /* static */ void   func_800A0A44(GUI_Textbox *, f32);
extern /* static */ void   func_800A1060(GUI_Textbox *, f32);
extern /* static */ void   func_800A167C(GUI_Textbox *, f32);
extern /* static */ void   func_800A1C98(GUI_Textbox *, f32);
extern /* static */ void   func_800A2148(GUI_Textbox *);
static void   func_800A27BC(GUI_Toggle *, f32);
static void   func_800A286C(GUI_Toggle *);
static void   func_800A287C(GUI_Toggle *);
extern /* static */ void   func_800A2884(GUI_Textbox *);
static void   func_800A2A94(GUI_Toggle *);
extern /* static */ void   func_800A2AA4(void);

static void func_800A0480(void *arg0) {
  D_800D3CF0 = 2;
}

static void func_800A0494(void *arg0) {
  D_800D3CF0 = 5;
}

static void func_800A04A8(GUI_Textbox *arg0) {
  D_800D3D10[0] = D_800D3D00[0];
  arg0->unk60 = 0xFA;
  arg0->unk5D = 0xFD;
  D_800D42B4[8].unk24 = GUI_TEXTBOX | GUI_TITLE;
  D_800D3D00[0] = 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A04F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A06D0.s")

static void func_800A08A0(GUI_Textbox *arg0) {
  D_800D3D10[0] = D_800D3D00[0];
  arg0->unk60 = 0xFF;
  arg0->unk5D = 0xFE;
  D_800D42B4[8].unk24 = GUI_TEXTBOX | GUI_TITLE;
  D_800D3D00[0] = 8;
}

static void func_800A08EC(GUI_Slider *arg0) {
  func_800875EC(arg0->cur * 2340, &D_80120A70);
  g_sram_ptr->music_level = arg0->cur * 2340;
  func_8007C5CC(g_sram_ptr);
}

static void func_800A097C(GUI_Slider *arg0) {
  Audio2_80087618_fourteenliner_loops_256t(arg0->cur * 2340);
  g_sram_ptr->sfx_level = arg0->cur * 2340;
  func_8007C5CC(g_sram_ptr);
}

static void func_800A0A08(void) {
  g_sram_ptr->music_mode = D_800D4DC4.cur;
  func_8007C5CC(g_sram_ptr);
}

u32 D_800D3FB0[18] = { 3, 4, 0x48, 0, 0x56, 0x57, 0, 0, 0, 0, 0, 0, 0, 0, 0x23, 0, 0, 0 };
UnkStruct_77 D_800D3FF8[9] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x1E, 0x31, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "ONE!PLAYER" }, NULL, 0x87, 0x61, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x51,
    NULL,
    D_800D5850,
    D_800D5808,
    0x7F000000,
  },
  {
    { { "MULTI!PLAYER" }, NULL, 0x87, 0x77, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x51,
    NULL,
    D_800D5D48,
    D_800D5CE8,
    0x7F000000,
  },
  {
    { { "WONDERS" }, NULL, 0x82, 0x8D, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x45,
    (void (*)(void *, ...)) func_800A0480,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "OPTIONS" }, NULL, 0x82, 0xA3, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x51,
    NULL,
    D_800D53C8,
    D_800D5378,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x100, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 3, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
GUI_Textbox D_800D41F0 = {
  0x40,
  8,
  0,
  &D_800D2DE0,
  0xBE,
  0xCC,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  0xFF,
  0xF6,
  0,
  0,
  0xF8,
  0,
  0,
};
u32 D_800D4254[24] = {
  3,
  4,
  0x66,
  0,
  0x64,
  0x65,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x40,
  0,
  0,
  0,
  0x19,
  0,
  0,
  0,
};
UnkStruct_77 D_800D42B4[12] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D53C8,
    D_800D5378,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 1, 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x14, 0x18, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x37, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 1 },
    8,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "TRANSFER FROM GAME BOY" }, NULL, 0x5F, 0x54, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    8,
    (void (*)(void *, ...)) func_800A04A8,
    NULL,
    &D_800D41F0,
    0x7F000000,
  },
  {
    { { "TRANSFER NAME" }, NULL, 0x61, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    5,
    (void (*)(void *, ...)) func_800A04F4,
    NULL,
    &D_800D41F0,
    0x7F000000,
  },
  {
    { { "DUMP LINES TO GAME PAK" }, NULL, 0x61, 0x72, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    5,
    (void (*)(void *, ...)) func_800A06D0,
    NULL,
    &D_800D41F0,
    0x7F000000,
  },
  {
    { { "DELETE NAME" }, NULL, 0x61, 0xA2, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    5,
    (void (*)(void *, ...)) func_800A08A0,
    NULL,
    &D_800D41F0,
    0x7F000000,
  },
  {
    { { "NAME:" }, NULL, 0x50, 0xCD, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x201,
    NULL,
    NULL,
    &D_800D41F0,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x48,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x109, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 5, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
static u32 D_800D4554[4] = { 0x6D, 0, 0x6E, 0 };
GUI_Slider D_800D4564 = {
  0xE,
  { { NULL }, NULL, 0xB8, 0x58, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
  {
    { { NULL }, NULL, 0xC1, 0x5D, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xCB, 0x5E, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xD5, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xDF, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xE9, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xF3, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xFD, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x107, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x111, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x11B, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x125, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x12F, 0x5B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x139, 0x5C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x143, 0x5D, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  },
  D_800D4554,
  0xC,
};
static u32 D_800D4918[4] = { 0x6D, 0, 0x6E, 0 };
GUI_Slider D_800D4928 = {
  0xE,
  { { NULL }, NULL, 0xB8, 0x76, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
  {
    { { NULL }, NULL, 0xC1, 0x7B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xCB, 0x7C, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xD5, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xDF, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xE9, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xF3, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0xFD, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x107, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x111, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x11B, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x125, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x12F, 0x79, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x139, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0x143, 0x7B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  },
  D_800D4918,
  0xC,
};
GUI_Textbox D_800D4CDC = {
  0x40,
  8,
  0,
  &D_800D2DC8,
  0xB9,
  0xC8,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  0xFF,
  0xF7,
  0,
  0,
  0xF9,
  0,
  0,
};
static u32 D_800D4D40[6] = { 0, 0, 0, 0, 0, 0 };
static UnkStruct_80 D_800D4D58[3] = {
  { { "AUTO" }, NULL, 0xBF, 0xAF, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
  { { "CHOOSE" }, NULL, 0xBF, 0xAF, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
  { { "RANDOM" }, NULL, 0xBF, 0xAF, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
};
GUI_Toggle D_800D4DC4 = { 3, D_800D4D58, D_800D4D40, 0 };
u32 D_800D4DD4[18] = { 3, 4, 0x63, 0, 0x61, 0x62, 0, 0, 0, 0, 0, 0, 0x40, 0, 0x19, 0, 0, 0 };
UnkStruct_77 D_800D4E1C[9] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D53C8,
    D_800D5378,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0, 0x17, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0xF, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "MUSIC LEVEL" }, NULL, 0x3C, 0x5C, 0xFF, 0xFF, 0xFF, 0xFF, 1 },
    0x1005,
    (void (*)(void *, ...)) func_800A08EC,
    NULL,
    &D_800D4564,
    0x7F000000,
  },
  {
    { { "SFX LEVEL" }, NULL, 0x3C, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 1 },
    0x1005,
    (void (*)(void *, ...)) func_800A097C,
    NULL,
    &D_800D4928,
    0x7F000000,
  },
  {
    { { "MUSIC MODE:" }, NULL, 0x3C, 0xAF, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x405,
    (void (*)(void *, ...)) func_800A0A08,
    NULL,
    &D_800D4DC4,
    0x7F000000,
  },
  {
    { { "SONG:" }, NULL, 0x3C, 0xCF, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x201,
    NULL,
    NULL,
    &D_800D4CDC,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x10B, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 3, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A0A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A1060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A167C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A1C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A2148.s")

static void func_800A27BC(GUI_Toggle *arg0, f32 arg1) {
  switch (arg0->cur) {
  case 0:
    func_800A1C98(&D_800D5014, arg1);
    break;
  case 1:
    func_800A0A44(&D_800D5014, arg1);
    break;
  case 2:
    func_800A1060(&D_800D5014, arg1);
    break;
  case 3:
    func_800A167C(&D_800D5014, arg1);
    break;
  }
}

static void func_800A286C(GUI_Toggle *arg0) {
  g_game.gameType = arg0->cur;
}

static void func_800A287C(GUI_Toggle *arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A2884.s")

static void func_800A2A94(GUI_Toggle *arg0) {
  g_game.landfill.type = arg0->cur;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/066700/func_800A2AA4.s")

void func_800A2E2C(void) {
  D_800D5AC4.unk5D = 0xFE;
  D_800D5AC4.unk5C = 0xFF;
  D_800D5B28.unk5C = 1;
  D_800D5B8C.unk5C = 2;
  D_800D5BF0.unk5C = 3;
  D_800D5AC4.unk61 = FALSE;
  D_800D5B28.unk61 = FALSE;
  D_800D5B8C.unk61 = FALSE;
  D_800D5BF0.unk61 = FALSE;
  D_800D5AC4.unk62 = 0;
  D_800D5B28.unk62 = 0;
  D_800D5B8C.unk62 = 0;
  D_800D5BF0.unk62 = 0;
  D_800D5AC4.node = &D_800D2D80;
  D_800D5B28.node = &D_800D2D80;
  D_800D5B8C.node = &D_800D2D80;
  D_800D5BF0.node = &D_800D2D80;
  D_800D2D98.pack = 0xF;
  D_800D2D80.pack = 0xE;
  D_800D3DD8 = 0;
}

GUI_Textbox D_800D5014 = {
  0x40,
  8,
  0,
  &D_800D2DB0,
  0x7B,
  0x60,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  0xFF,
  0xFE,
  0,
  0,
  0xFC,
  0,
  0,
};
static u32 D_800D5078[18] = {
  3,
  4,
  0x69,
  0,
  0x67,
  0x68,
  0x1C,
  0x1D,
  0x1E,
  0x1F,
  0,
  0,
  0x40,
  0,
  0x19,
  0,
  0,
  0,
};
static u32 D_800D50C0[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
static UnkStruct_80 D_800D50E0[4] = {
  { { "GENERAL" }, NULL, 0x90, 0x42, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "MARATHON" }, NULL, 0x84, 0x42, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "SPRINT" }, NULL, 0x9D, 0x42, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "ULTRA" }, NULL, 0x9F, 0x42, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
};
GUI_Toggle D_800D5170 = { 4, D_800D50E0, D_800D50C0, 0 };
UnkStruct_77 D_800D5180[9] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D53C8,
    D_800D5378,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x12C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x37, 0x42, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0xC04,
    (void (*)(void *, ...)) func_800A27BC,
    NULL,
    &D_800D5170,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xD3, 0xAF, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0xA00,
    (void (*)(void *, ...)) func_800A2148,
    NULL,
    &D_800D5014,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x10D, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 5, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
u32 D_800D5378[20] = { 3, 4, 0x60, 0, 0x5E, 0x5F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x19, 0, 0, 0 };
UnkStruct_77 D_800D53C8[10] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D3FF8,
    D_800D3FB0,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x28, 0x32, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "SCORES" }, NULL, 0x82, 0x67, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x51,
    NULL,
    D_800D5180,
    D_800D5078,
    0x7F000000,
  },
  {
    { { "DATA" }, NULL, 0x82, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x51,
    NULL,
    D_800D42B4,
    D_800D4254,
    0x7F000000,
  },
  {
    { { "AUDIO" }, NULL, 0x82, 0x95, 0xFF, 0xFF, 0xFF, 0x64, 0 },
    0x51,
    NULL,
    D_800D4E1C,
    D_800D4DD4,
    0x7F000000,
  },
  {
    { { "CREDITS" }, NULL, 0x82, 0xAC, 0xFF, 0xFF, 0xFF, 0x64, 0 },
    0x45,
    (void (*)(void *, ...)) func_800A0494,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0xCB, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x48,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 3, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
static u32 D_800D55F8[6] = { 0, 0, 0, 0, 0, 0 };
static UnkStruct_80 D_800D5610[3] = {
  { { "MARATHON" }, NULL, 0xE8, 0xA6, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "SPRINT" }, NULL, 0x110, 0xA6, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "ULTRA" }, NULL, 0x114, 0xA6, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
};
GUI_Toggle D_800D567C = { 3, D_800D5610, D_800D55F8, 0 };
static UnkStruct_80 D_800D568C[6] = {
  { { "OFF" }, NULL, 0x12D, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "EASY" }, NULL, 0x122, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "MEDIUM" }, NULL, 0x107, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "HARD" }, NULL, 0x11C, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "VERY HARD" }, NULL, 0xE9, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "MASTER" }, NULL, 0x10A, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
};
static u32 D_800D5764[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
GUI_Toggle D_800D5794 = { 6, D_800D568C, D_800D5764, 0 };
GUI_Textbox D_800D57A4 = {
  0x40,
  8,
  0,
  &D_800D2D80,
  0xB0,
  0x50,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  0xFF,
  0xFE,
  0,
  0,
  0xFD,
  0,
  0,
};
u32 D_800D5808[18] = { 3, 4, 0x49, 0, 0x58, 0x59, 0, 0, 0, 0, 0, 0, 0, 0, 0x19, 0, 0, 0 };
UnkStruct_77 D_800D5850[9] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D3FF8,
    D_800D3FB0,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0, 0x25, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { "NAME:" }, NULL, 0x3C, 0x51, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x201,
    NULL,
    NULL,
    &D_800D57A4,
    0x7F000000,
  },
  {
    { { "OPPONENT:" }, NULL, 0x3A, 0x88, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x405,
    (void (*)(void *, ...)) func_800A287C,
    NULL,
    &D_800D5794,
    0x7F000000,
  },
  {
    { { "GAME:" }, NULL, 0x3A, 0xA6, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x405,
    (void (*)(void *, ...)) func_800A286C,
    NULL,
    &D_800D567C,
    0x7F000000,
  },
  {
    { { "START" }, NULL, 0x78, 0xCA, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x45,
    (void (*)(void *, ...)) func_800A2884,
    NULL,
    &D_800D57A4,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x104, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 3, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
static UnkStruct_80 D_800D5A48[3] = {
  { { "MARATHON" }, NULL, 0xE4, 0xA0, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "SPRINT" }, NULL, 0x10C, 0xA0, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "ULTRA" }, NULL, 0x112, 0xA0, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
};
GUI_Toggle D_800D5AB4 = { 3, D_800D5A48, D_800D55F8, 0 };
GUI_Textbox D_800D5AC4 = {
  0x40,
  8,
  0,
  &D_800D2D80,
  0x28,
  0x4D,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  0xFF,
  0xFE,
  0,
  0,
  0xFD,
  0,
  0,
};
GUI_Textbox D_800D5B28 = {
  0x40,
  8,
  0,
  &D_800D2D80,
  0x28,
  0x70,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  1,
  0,
  0,
  0,
  0xFD,
  0,
  0,
};
GUI_Textbox D_800D5B8C = {
  0x40,
  8,
  0,
  &D_800D2D80,
  0xCC,
  0x4D,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  2,
  0,
  0,
  0,
  0xFD,
  0,
  0,
};
GUI_Textbox D_800D5BF0 = {
  0x40,
  8,
  0,
  &D_800D2D80,
  0xCC,
  0x70,
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  { { NULL }, NULL, 0, 0, 0, 0, 0, 0, 0 },
  3,
  0,
  0,
  0,
  0xFD,
  0,
  0,
};
static u32 D_800D5C54[6] = { 0, 0, 0, 0, 0, 0 };
static UnkStruct_80 D_800D5C6C[3] = {
  { { "NONE" }, NULL, 0x118, 0xB7, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "HOT POTATO" }, NULL, 0xD0, 0xB7, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
  { { "DIRECTED" }, NULL, 0xF7, 0xB7, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
};
GUI_Toggle D_800D5CD8 = { 3, D_800D5C6C, D_800D5C54, 0 };
u32 D_800D5CE8[24] = {
  3,
  4,
  0x6B,
  0,
  0x5A,
  0x5B,
  0x40,
  0,
  0x40,
  0,
  0x40,
  0,
  0x40,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};
UnkStruct_77 D_800D5D48[12] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    D_800D3FF8,
    D_800D3FB0,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x3C, 0x2E, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x3C, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x26, 0x7A, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x200,
    NULL,
    NULL,
    &D_800D5AC4,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xD1, 0x2F, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x200,
    NULL,
    NULL,
    &D_800D5B28,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xD1, 0x64, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x200,
    NULL,
    NULL,
    &D_800D5B8C,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xD1, 0x9B, 0xFF, 0xFF, 0xFF, 0xA0, 0 },
    0x200,
    NULL,
    NULL,
    &D_800D5BF0,
    0x7F000000,
  },
  {
    { { "GAME:" }, NULL, 0x3C, 0xA0, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x405,
    (void (*)(void *, ...)) func_800A286C,
    NULL,
    &D_800D5AB4,
    0x7F000000,
  },
  {
    { { "GARBAGE:" }, NULL, 0x3C, 0xB7, 0xFF, 0xFF, 0xFF, 0xA0, 1 },
    0x405,
    (void (*)(void *, ...)) func_800A2A94,
    NULL,
    &D_800D5CD8,
    0x7F000000,
  },
  {
    { { "START" }, NULL, 0x64, 0xDB, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x45,
    (void (*)(void *, ...)) func_800A2AA4,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x48,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 3, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
u32 D_800D5FE8[10] = { 3, 4, 0x6C, 0, 0x5C, 0x5D, 0x23, 0, 0, 0 };
UnkStruct_77 D_800D6010[5] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0x32, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { NULL }, NULL, 0xC8, 0x106, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0x4A,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
u32 D_800D6128[4] = { 3, 4, 0, 0 };
UnkStruct_77 D_800D6138[2] = {
  {
    { { NULL }, NULL, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0 },
    0xA,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
  {
    { { ":" }, NULL, 0, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
u32 D_800D61A8[2] = { 0, 0 };
UnkStruct_77 D_800D61B0[1] = {
  {
    { { ":" }, NULL, 1, 0, 0, 0, 0, 0, 0 },
    0x8008,
    NULL,
    NULL,
    NULL,
    0x7F000000,
  },
};
