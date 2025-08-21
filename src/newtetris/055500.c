#include "common.h"

extern u16 draw_buffer;
extern s8 D_800CF830;
extern s8 D_800CF834;
extern s8 D_800CF838;
extern s8 D_800CF83C;
extern u8 D_800CFD48;
extern u8 D_800CFD4C;

////////////////////////////////////////

Font D_80128EB0;
Font D_80128F28;
Font D_80128FA0;
static char *D_80129018;  // (str) lines dumped to game pak
static void *D_8012901C;
static void *D_80129020;
static void *D_80129024;
static void *D_80129028;
static UnkStruct_78 *D_8012902C[1];

u8 D_800D3CF0 = 0;
s32 D_800D3CF4 = 0;
UnkStruct_77 *D_800D3CF8 = NULL;
void *D_800D3CFC = NULL;
s32 D_800D3D00[4] = { 1, 1, 1, 1 };
s32 D_800D3D10[4] = { 1, 1, 1, 1 };
static s32 D_800D3D20 = 0;
static s8 D_800D3D24 = 0;
static f32 D_800D3D28 = 1;
static s32 D_800D3D2C = 0;
static u8 D_800D3D30 = FALSE;
u8 D_800D3D34 = 0;
static s32 D_800D3D38 = 1;
static Font *D_800D3D3C[3] = { &D_80128EB0, &D_80128F28, &D_80128FA0 };
static char *D_800D3D48[16] = {
  "MOROCCO.",
  "DVIE.",
  "POLYASIA.",
  "FLOPPY.",
  "PYRAMID.",
  "GIALI.",
  "THREAD6.",
  "HALUCI.",
  "MAYAN.",
  "GREEK.",
  "EGYPT.",
  "CELTIC.",
  "AFRICA.",
  "JAPAN.",
  "KALINKA.",
  "TITLE.",
};
static u8 D_800D3D88 = FALSE;
static s32 D_800D3D8C = 0;  // unused
static s32 D_800D3D90 = 0;
static u8 D_800D3D94 = 0;
static u8 handicap[4] = { 0, 0, 0, 0 };
static u8 D_800D3D9C = 10;
static char D_800D3DA0[45] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', ':', '%', '?', '"', '(', ')', ' ', '[', '\\'
};

static s32 D_800D3DD0 = 0;  // lines dumped to game pak
static u8 D_800D3DD4 = 0;
u8 D_800D3DD8 = 0;
static s32 D_800D3DDC = 0;  // unused
static s32 D_800D3DE0 = 0;  // unused
static s32 D_800D3DE4 = 8;
static s32 D_800D3DE8 = 0;    // cpak note extension name incrementer
static u8 D_800D3DEC = 0x1A;  // cpak note extension name base 'A' (N64 font code)
static s32 D_800D3DF0 = 0;
static s32 D_800D3DF4 = 0;
static s32 D_800D3DF8 = 0;
static s32 D_800D3DFC = 0;
static s32 D_800D3E00 = 0;
static s32 D_800D3E04 = 0;
static s32 D_800D3E08 = 0;
static s32 D_800D3E0C = 0;
static s32 D_800D3E10 = 0;
static s32 D_800D3E14 = 0;
static s32 D_800D3E18 = 0;
static s32 D_800D3E1C = 0;
static s32 D_800D3E20 = 0;

static f32 D_800D3E24 = 0;
static f32 D_800D3E28 = 0.05;
static f32 D_800D3E2C = 0;
static f32 D_800D3E30 = 1.0/9;
static s32 D_800D3E34 = 0;
static s32 D_800D3E38 = 0;  // unused
static s32 D_800D3E3C = 0;  // unused
static s32 D_800D3E40 = 8;

static void   func_8008FF78(UnkStruct_78 *);
static void   func_8009098C(UnkStruct_78 *);
static void   func_80090AC0(UnkStruct_78 *);
static s32    func_80091440(UnkStruct_78 *, s32, s32 *);
static s32    func_80091744(UnkStruct_78 *, s32, s32 *);
static void   func_80091A8C(UnkStruct_78 *);
static void   func_80091D60(GUI_Textbox *, UnkStruct_78 *, s32, f32);
static void   func_80099674(UnkStruct_78 *);

void func_8008F280(UnkStruct_78 *arg0, s32 img_id, s32 width, s32 height, void *arg4) {
  if (img_id == -1) {
    arg0->img = arg4;
  } else {
    arg0->img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, img_id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->img, img_id);
  }
  arg0->width = width;
  arg0->height = height;
  arg0->unk114 = 0;
  arg0->unk134 = 0;
  arg0->unk128 = 0;
  arg0->unk120 = 0;
  func_8009F2DC(arg0);
}

void func_8008F360(UnkStruct_78 *arg0, UnkStruct_77 *arg1, u32 *arg2) {
  u8 i, j;
  GUI_Slider  *gui_slider;
  GUI_Toggle  *gui_toggle;
  GUI_Textbox *gui_textbox;
  s32 tmp;

  arg0->unk124 = arg1;
  i = 0;
  main_8004A34C_threeliner();
  for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
    if ((arg0->unk124[i].unk24 & GUI_NULL) != GUI_NULL) {
      arg0->unk124[i].unk0.a = 0xA0;
    }
    if (arg0->unk124[i].unk24 & GUI_SLIDER) {
      gui_slider = arg0->unk124[i].unk30;

      if (gui_slider->ids[0] != 0) {
        gui_slider->track.data.img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, gui_slider->ids[0]));
        FUN_03A750_800746c0_twentyliner(&D_273A00, gui_slider->track.data.img, gui_slider->ids[0]);

        gui_slider->marks[0].data.img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, gui_slider->ids[2]));
        FUN_03A750_800746c0_twentyliner(&D_273A00, gui_slider->marks[0].data.img, gui_slider->ids[2]);
      }

      for (j = 0; j < gui_slider->num_ticks; j++) {
        gui_slider->marks[j].data.img = gui_slider->marks[0].data.img;
      }
    }

    if (arg0->unk124[i].unk24 & GUI_TOGGLE) {
      gui_toggle = arg0->unk124[i].unk30;

      for (j = 0; j < gui_toggle->num; j++) {
        if (gui_toggle->ids[j * 2] != 0) {
          gui_toggle->unk4[j].data.img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, gui_toggle->ids[j * 2]));
          FUN_03A750_800746c0_twentyliner(&D_273A00, gui_toggle->unk4[j].data.img, gui_toggle->ids[j * 2]);

          if (gui_toggle->ids[j * 2 + 1] != 0) {
            gui_toggle->unk4[j].pal = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, gui_toggle->ids[j * 2 + 1]));
            FUN_03A750_800746c0_twentyliner(&D_273A00, gui_toggle->unk4[j].pal, gui_toggle->ids[j * 2 + 1]);
          }
        }
      }
    }

    if (arg0->unk124[i].unk24 & GUI_TEXTBOX) {
      gui_textbox = arg0->unk124[i].unk30;
      gui_textbox->unk14.data.img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, gui_textbox->id));
      FUN_03A750_800746c0_twentyliner(&D_273A00, gui_textbox->unk14.data.img, gui_textbox->id);
    }

    if (arg0->unk124[i].unk24 & GUI_PIC) {
      if (arg2[i * 2] != 0) {
        arg0->unk124[i].unk0.data.img = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg2[i * 2]));
        FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk124[i].unk0.data.img, arg2[i * 2]);

        if (arg2[i * 2 + 1] != 0) {
          arg0->unk124[i].unk0.pal = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, arg2[i * 2 + 1]));
          FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk124[i].unk0.pal, arg2[i * 2 + 1]);
        }
      }
    }
  }

  if (D_800D5D48 == arg1) {
    D_800D3D00[0] = 3;
    D_800D3D00[1] = 4;
    D_800D3D00[2] = 5;
    D_800D3D00[3] = 6;
    D_800D3D10[0] = 3;
    D_800D3D10[1] = 4;
    D_800D3D10[2] = 5;
    D_800D3D10[3] = 6;
  }

  if (D_800D5850 == arg1) {
    D_800D3D00[0] = 3;
    D_800D3D00[1] = 0;
    D_800D3D00[2] = 0;
    D_800D3D00[3] = 0;
    D_800D3D10[0] = 3;
    D_800D3D10[1] = 0;
    D_800D3D10[2] = 0;
    D_800D3D10[3] = 0;
  }

  if (D_800D5180 == arg1) {
    D_800D3D00[0] = 5;
    D_800D3D10[0] = 5;
    D_800D5170.cur = 0;
    D_800D5180[8].unk0.x = 5;
  }

  if (D_800D42B4 == arg1) {
    FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
    tmp = FUN_001050_getControllerStatus(&superThread, 0);
    if (tmp & CONT_CARD_ON) {
      tmp = FUN_001050_cpakInit(&superThread, 0);
    } else {
      for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
        if (arg0->unk124[i + 1].unk24 & GUI_QUIT) {
          arg0->unk124[i + 1].unk0.x = 5;
          D_800D3D10[0] = D_800D3D00[0];
          break;
        }
      }
      D_800D42B4[3].unk24 = GUI_NULL;
      D_800D42B4[4].unk24 = GUI_NULL;
    }
    for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
      if (arg0->unk124[i + 1].unk24 & GUI_QUIT) {
        if (arg0->unk124[i + 1].unk0.x == 8) {
          arg0->unk124[i + 1].unk0.x = 5;
        }
        D_800D3D10[0] = D_800D3D00[0];
        break;
      }
    }
    D_800D42B4[8].unk24 = GUI_NULL;
  }

  if (!D_800D3D88 && (D_800D4E1C == arg1)) {
    for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
      if (arg0->unk124[i + 1].unk24 & GUI_QUIT) {
        arg0->unk124[i + 1].unk0.x = 3;
        D_800D3D10[0] = D_800D3D00[0];
        break;
      }
    }
    if (g_sram_ptr->song == 0) {
      j = 15;
    } else {
      j = g_sram_ptr->song - 1;
    }
    for (i = 0; D_800D3D48[j][i] != '.'; i++) {
      D_800D2DC8.name[i] = D_800D3D48[j][i];
    }
    D_800D2DC8.name[i] = 0;
  }

  if ((arg0->unk124 == D_800D5850) || (arg0->unk124 == D_800D5D48) || (arg0->unk124 == D_800D42B4) || (arg0->unk124 == D_800D5180)) {
    if (D_80129024 == NULL) {
      D_80129024 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_GAMECART));
      FUN_03A750_800746c0_twentyliner(&D_273A00, D_80129024, IMG_GAMECART);
    }
    if (D_80129020 == NULL) {
      D_80129020 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_GAMEPAK));
      FUN_03A750_800746c0_twentyliner(&D_273A00, D_80129020, IMG_GAMEPAK);
    }
    if (D_80129028 == NULL) {
      D_80129028 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_RECTANGLE));
      FUN_03A750_800746c0_twentyliner(&D_273A00, D_80129028, IMG_RECTANGLE);
    }
  }

  D_800D3D38 = 1;
}

static void func_8008FF78(UnkStruct_78 *arg0) {
  u8 i, j;
  GUI_Slider  *gui_slider;
  GUI_Toggle  *gui_toggle;
  GUI_Textbox *gui_textbox;

  main_8004A34C_threeliner();
  if ((arg0->unk124 == D_800D5850) || (arg0->unk124 == D_800D5D48) || (arg0->unk124 == D_800D42B4) || (arg0->unk124 == D_800D5180)) {
    if (D_80129028 != NULL) {
      n64HeapUnalloc(D_80129028);
      D_80129028 = NULL;
    }
    if (D_80129020 != NULL) {
      n64HeapUnalloc(D_80129020);
      D_80129020 = NULL;
    }
    if (D_80129024 != NULL) {
      n64HeapUnalloc(D_80129024);
      D_80129024 = NULL;
    }
  }

  for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
    if (arg0->unk124[i].unk24 & GUI_SLIDER) {
      gui_slider = arg0->unk124[i].unk30;
      if (gui_slider->ids[0] != 0) {
        n64HeapUnalloc(gui_slider->track.data.img);
        n64HeapUnalloc(gui_slider->marks[0].data.img);
      }
    }

    if (arg0->unk124[i].unk24 & GUI_TOGGLE) {
      gui_toggle = arg0->unk124[i].unk30;
      for (j = 0; j < gui_toggle->num; j++) {
        if (gui_toggle->ids[j * 2] != 0) {
          if (gui_toggle->unk4[j].data.img != NULL) {
            n64HeapUnalloc(gui_toggle->unk4[j].data.img);
            gui_toggle->unk4[j].data.img = NULL;
          }
          if (gui_toggle->unk4[j].pal != NULL) {
            n64HeapUnalloc(gui_toggle->unk4[j].pal);
            gui_toggle->unk4[j].pal = NULL;
          }
        }
      }
    }

    if (arg0->unk124[i].unk24 & GUI_TEXTBOX) {
      gui_textbox = arg0->unk124[i].unk30;
      n64HeapUnalloc(gui_textbox->unk14.data.img);
    }

    if (arg0->unk124[i].unk24 & GUI_PIC) {
      if (arg0->unk124[i].unk0.data.img != NULL) {
        n64HeapUnalloc(arg0->unk124[i].unk0.data.img);
        arg0->unk124[i].unk0.data.img = NULL;
      }
      if (arg0->unk124[i].unk0.pal != NULL) {
        n64HeapUnalloc(arg0->unk124[i].unk0.pal);
        arg0->unk124[i].unk0.pal = NULL;
      }
    }
  }
}

void func_8009035C(UnkStruct_77 *arg0, u32 *arg1) {
  s32 i;
  UnkStruct_1 *sp30;

  for (i = 0; i < 4; i++) {
    sp30 = &g_PV_arr[i].unk28;
    FUN_026900_80060ad4_oneliner_calls_fun(sp30);
    FUN_026900_80060b04_twelveliner_loops_32t(sp30, 0xF00, 32, 10);   // JPAD (U, D, R, L) only
    FUN_026900_80060b04_twelveliner_loops_32t(sp30, 0xC000, 16, 16);  // Buttons A and B only
    g_PV_arr[0].unk20 = g_PV_arr[i].unk24 = 0;  // (bug?) why [0]?
  }
  D_800CFED4 = 4;
  D_800D3CF0 = 0;
  func_8008F360(&D_801290D0, arg0, arg1);
  D_801290D0.img = n64HeapAlloc(240008);
  func_800A8FC8(D_801290D0.img, 120004, 0);
  func_8008F280(&D_801290D0, -1, 400, 300, D_801290D0.img);
  D_8012901C = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_CURSOR));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_8012901C, IMG_CURSOR);
  Font_Init46Char(&D_80128EB0, IMG_FONT_A);
  Font_Init46Char(&D_80128F28, IMG_FONT_B);
  Font_Init46Char(&D_80128FA0, IMG_FONT_C);
  func_8009FA2C(&D_801290D0);
  D_800D3CF8 = NULL;
  Audio_LoadSFX(&D_800D3988);
  for (i = 0; i < 4; i++) {
    D_800D3FF8[3 + i].unk0.a = 0xA0;
    D_800D3FF8[3 + i].unk0.r = 0xFF;
    D_800D3FF8[3 + i].unk0.g = 0xFF;
    D_800D3FF8[3 + i].unk0.b = 0xFF;
  }
}

void func_800905E8(u8 arg0) {
  s32 i;
  UnkStruct_1 *sp30;

  for (i = 0; i < 4; i++) {
    sp30 = &g_PV_arr[i].unk28;
    FUN_026900_80060ad4_oneliner_calls_fun(sp30);
    FUN_026900_80060b04_twelveliner_loops_32t(sp30, 0xF00, 32, 10);   // JPAD (U, D, R, L) only
    FUN_026900_80060b04_twelveliner_loops_32t(sp30, 0xC000, 16, 16);  // Buttons A and B only
    g_PV_arr[0].unk20 = g_PV_arr[i].unk24 = 0;  // (bug?) why [0]?
  }

  func_800A3550();
  D_800CFED4 = 4;
  D_800D3CF0 = 0;
  D_80129030 = 400;
  D_80129034 = 300;
  D_80129038 = 50;
  D_8012903C = 37;
  func_800A36F0(-50, 50);
  func_8008F360(&D_801290D0, D_800D3FF8, D_800D3FB0);
  D_801290D0.img = n64HeapAlloc(240008);
  func_800A8FC8(D_801290D0.img, 120004, 0);
  func_8008F280(&D_801290D0, -1, 400, 300, D_801290D0.img);
  Audio_LoadSFX(&D_800D3988);
  func_800A36F0(-50, 50);
  func_800A36F0(-50, 50);
  D_8012902C[0] = &D_801290D0;
  if (arg0 == 0) {
    D_800D3D00[0] = 3;
    D_800D3D00[1] = 0;
    D_800D3D00[2] = 0;
    D_800D3D00[3] = 0;
    D_800D3D10[0] = 3;
    D_800D3D10[1] = 0;
    D_800D3D10[2] = 0;
    D_800D3D10[3] = 0;
  }
  D_800D3CF4 = 0;
  D_8012901C = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_CURSOR));
  FUN_03A750_800746c0_twentyliner(&D_273A00, D_8012901C, IMG_CURSOR);
  for (i = 0; i < 4; i++) {
    D_800D3FF8[3 + i].unk0.a = 0xA0;
    D_800D3FF8[3 + i].unk0.r = 0xFF;
    D_800D3FF8[3 + i].unk0.g = 0xFF;
    D_800D3FF8[3 + i].unk0.b = 0xFF;
  }
  Font_Init46Char(&D_80128EB0, IMG_FONT_A);
  Font_Init46Char(&D_80128F28, IMG_FONT_B);
  Font_Init46Char(&D_80128FA0, IMG_FONT_C);
  func_8009FA2C(&D_801290D0);
  D_800D3CF8 = NULL;
}

static void func_8009098C(UnkStruct_78 *arg0) {
  main_8004A34C_threeliner();
  if (D_80128EB0.image != NULL) {
    Font_Deinit(&D_80128EB0);
  }
  if (D_80128F28.image != NULL) {
    Font_Deinit(&D_80128F28);
  }
  if (D_80128FA0.image != NULL) {
    Font_Deinit(&D_80128FA0);
  }
  if (arg0->img != NULL) {
    n64HeapUnalloc(arg0->img);
    arg0->img = NULL;
  }
  func_8009F338(arg0);
}

void func_80090A44(void) {
  s32 i;

  main_8004A34C_threeliner();
  for (i = 0; i < 3; i++) {
    // empty
  }
  if (D_8012901C != NULL) {
    n64HeapUnalloc(D_8012901C);
    D_8012901C = NULL;
  }
  func_8008FF78(&D_801290D0);
  func_8009098C(&D_801290D0);
  D_800D3CF8 = NULL;
}

static void func_80090AC0(UnkStruct_78 *arg0) {
  s32 i;

  if ((arg0->unk114 != 0) && (D_800D3CF8 != NULL)) {
    for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
      if (arg0->unk124[i + 1].unk24 & GUI_QUIT) {
        arg0->unk124[i + 1].unk0.x = D_800D3D00[0];
        D_800D3D10[0] = D_800D3D00[0];
        break;
      }
    }

    main_8004A34C_threeliner();
    func_8008FF78(&D_801290D0);
    func_8009098C(&D_801290D0);
    func_8008F360(&D_801290D0, D_800D3CF8, D_800D3CFC);
    D_801290D0.img = n64HeapAlloc(240008);
    func_800A8FC8(D_801290D0.img, 120004, 0);
    func_8008F280(&D_801290D0, -1, 400, 300, D_801290D0.img);
    Font_Init46Char(&D_80128EB0, IMG_FONT_A);
    Font_Init46Char(&D_80128F28, IMG_FONT_B);
    Font_Init46Char(&D_80128FA0, IMG_FONT_C);
    D_800D3CF4 = 0;
    D_800D3CF8 = NULL;

    if (D_800D3D90 == 0) {
      if ((D_800CFEE8 != 11) && (D_800CFEE8 != 10)) {
        func_8009FA2C(&D_801290D0);
      }
    } else {
      D_800D3D90 = 0;
    }

    if (arg0->unk124 == D_800D5850) {
      D_800D3D00[0] = 3;
      D_800D3D10[0] = D_800D3D00[0];
      return;
    }

    if (arg0->unk124 == D_800D5D48) {
      D_800D3D00[0] = 3;
      D_800D3D10[0] = D_800D3D00[0];
      return;
    }

    for (i = 0; (arg0->unk124[i].unk24 & GUI_QUIT) != GUI_QUIT; i++) {
      if (arg0->unk124[i + 1].unk24 & GUI_QUIT) {
        D_800D3D00[0] = arg0->unk124[i + 1].unk0.x;
        D_800D3D10[0] = D_800D3D00[0];
        break;
      }
    }
  }
}

void func_80090E08(void) {
  s32 i;
  s32 sp48;  // unused
  GUI_Textbox *gui_textbox_1;
  GUI_Textbox *gui_textbox_2;
  GUI_Textbox *gui_textbox_3;
  GUI_Textbox *gui_textbox_4;
  GUI_Textbox *gui_textbox_5;
  register Game *game_ptr = &g_game;
  s32 sp2C;  // unused
  s32 sp28;  // unused
  UnkStruct_1 *sp24;

  if (D_800D3CF0 == 1) {  // game mode
    main_8004A34C_threeliner();
    func_80090A44();
    D_800CFEE8 = 9;
    if (D_800CF838 >= 7) {
      game_ptr->unkE4F8 = func_800A35EC(0, 7);
    } else {
      game_ptr->unkE4F8 = func_800A35EC(0, D_800CF838);
    }
    FUN_027BF0_check_music_settings_and_play(game_ptr->unkE4F8);
    Audio_LoadSFX(&D_800D3A90);
    Game_Init(D_800CFED4, handicap);
    if (D_800D3D20 != 0) {
      D_800D3D20 = 0;
    }
    D_800D3CF0 = 0;
    main_8004A34C_threeliner();

  } else if (D_800D3CF0 == 3) {  // attract mode
    main_8004A34C_threeliner();
    func_80090A44();
    if (func_800A35EC(0, 10) < 8) {
      D_800CFEE8 = 12;
      g_game.landfill.type = LANDFILLTYPE_NONE;
      g_game.gameType = GAMETYPE_MARATHON;
      if (D_800CF838 >= 7) {
        game_ptr->unkE4F8 = func_800A35EC(0, 7);
      } else {
        game_ptr->unkE4F8 = func_800A35EC(0, D_800CF838);
      }
      FUN_027BF0_check_music_settings_and_play(game_ptr->unkE4F8);
      Audio_LoadSFX(&D_800D3A90);
      func_8007A078(&D_800D2D80, 0);
      aiplayer_gameinit_related(1, 0, 6);
      D_800CFED4 = 1;
      Game_Init(1, handicap);
      D_800D3CF0 = 0;
    } else {
      D_800CFEE8 = 3;
      D_800CFD48 = TRUE;
      D_800CFD4C = TRUE;
    }

  } else if (D_800D3CF0 == 2) {  // wonders progress
    if (D_800D3D9C == 5) {
      main_8004A34C_threeliner();
      func_80090A44();
    }
    if (D_800D3D9C-- == 0) {
      D_800D3D9C = 10;
      wonders1_anim_related(D_800CF830);
      D_801109F0 = 4;
      D_800CFEE8 = 7;
      D_800D3CF0 = 0;
    }

  } else if (D_800D3CF0 == 4) {  // haluci mode
    main_8004A34C_threeliner();
    func_80090A44();
    D_800CFEE8 = 13;
    func_8007CF40(1);  // haluci_init(1);
    D_800D3CF0 = 0;

  } else if (D_800D3CF0 == 5) {  // scroll credits
    main_8004A34C_threeliner();
    func_80090A44();
    D_800CFEE8 = 16;
    D_800D3CF0 = 0;

  } else {
    if (D_800D5D48 == D_801290D0.unk124) {
      gui_textbox_1 = D_801290D0.unk124[3].unk30;
      gui_textbox_2 = D_801290D0.unk124[4].unk30;
      gui_textbox_3 = D_801290D0.unk124[5].unk30;
      gui_textbox_4 = D_801290D0.unk124[6].unk30;
      if (((gui_textbox_1->unk5C == 0xFF) && (gui_textbox_1->node->pack & 0x10) &&
           (gui_textbox_2->unk5C == 0xFF) &&
           (gui_textbox_3->unk5C != 0xFF) &&
           (gui_textbox_4->unk5C != 0xFF)) ||
          ((gui_textbox_1->unk5C == 0xFF) && (gui_textbox_1->node->pack & 0x10) &&
           (gui_textbox_2->unk5C == 0xFF) &&
           (gui_textbox_3->unk5C == 0xFF) &&
           (gui_textbox_4->unk5C != 0xFF)) ||
          ((gui_textbox_1->unk5C == 0xFF) && (gui_textbox_1->node->pack & 0x10) &&
           (gui_textbox_2->unk5C == 0xFF) &&
           (gui_textbox_3->unk5C == 0xFF) &&
           (gui_textbox_4->unk5C == 0xFF))) {
        if (D_800D3D94 == 0) {
          D_800D3D34 = 1;
        } else {
          D_800D3D34 = 0;
        }
      } else {
        D_800D3D34 = 0;
      }
    }

    if (D_800D5850 == D_801290D0.unk124) {
      gui_textbox_5 = D_801290D0.unk124[3].unk30;
      if (gui_textbox_5->unk5C == 0xFF) {
        if (gui_textbox_5->node->pack & 0x10) {
          D_800D3D34 = 1;
        } else {
          D_800D3D34 = 0;
        }
      } else {
        D_800D3D34 = 0;
      }
    }

    for (i = 0; i < 4; i++) {
      sp24 = &g_PV_arr[i].unk28;
      sp24->unk88 = g_PV_arr[i].unk1C->unk0;
      sp24->unk8C = g_PV_arr[i].unk24;
      debug_print2("ControllerRepeat_Update", "MainMenu");
      FUN_026900_GU_or_ControllerRepeat_Update(sp24, sp24->unk88, func_800A3AF0());
    }

    func_8009D5E4();
  }
}

static s32 func_80091440(UnkStruct_78 *arg0, s32 arg1, s32 *arg2) {
  register UnkStruct_77 *temp_s0 = arg0->unk124;
  s32 sp28;
  s32 sp24;

  func_800A35EC(0, 0xFF);
  if (D_800D3D94 != 0) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
    return arg1;
  }

  if (arg0->unk114 == 0) {
    func_8009DDF4(arg0);
    if (D_800D3D20 != 0) {
      D_800D3D20 = 0;
    }
  }

  for (sp28 = 0; (temp_s0[sp28].unk24 & GUI_QUIT) != GUI_QUIT; sp28++) {
    if (temp_s0[sp28].unk24 & GUI_NULL) {
      continue;
    }

    temp_s0[sp28].unk0.a = 0xA0;
    temp_s0[sp28].unk0.r = 0xFF;
    temp_s0[sp28].unk0.g = 0xFF;
    temp_s0[sp28].unk0.b = 0xFF;
  }
  sp24 = sp28 - 1;

  temp_s0[arg1].unk0.a = 0xA0;
  temp_s0[arg1].unk0.r = 0xFF;
  temp_s0[arg1].unk0.g = 0xFF;
  temp_s0[arg1].unk0.b = 0xFF;

  *arg2 = arg1;

  sp28 = arg1 - 1;
  while (sp28 >= 0) {
    if (sp28 == 0) {
      sp28 = sp24;
    }
    if (temp_s0[sp28].unk24 & GUI_NULL) {
      if (temp_s0[sp28].unk24 & GUI_TEXTBOX) {
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
        return sp28;
      }
    } else {
      Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
      return sp28;
    }
    sp28--;
  }

  return arg1;
}

static s32 func_80091744(UnkStruct_78 *arg0, s32 arg1, s32 *arg2) {
  register UnkStruct_77 *temp_s0 = arg0->unk124;
  s32 sp28;
  s32 sp24;  // unused

  func_800A35EC(0, 0xFF);
  if (D_800D3D94 != 0) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
    return arg1;
  }

  if (arg0->unk114 == 0) {
    func_8009DDF4(arg0);
    if (D_800D3D20 != 0) {
      D_800D3D20 = 0;
    }
  }

  for (sp28 = 0; (temp_s0[sp28].unk24 & GUI_QUIT) != GUI_QUIT; sp28++) {
    if (temp_s0[sp28].unk24 & GUI_NULL) {
      continue;
    }

    temp_s0[sp28].unk0.a = 0xA0;
    temp_s0[sp28].unk0.r = 0xFF;
    temp_s0[sp28].unk0.g = 0xFF;
    temp_s0[sp28].unk0.b = 0xFF;
  }

  *arg2 = arg1;

  sp28 = arg1 + 1;

  temp_s0[arg1].unk0.a = 0xA0;
  temp_s0[arg1].unk0.r = 0xFF;
  temp_s0[arg1].unk0.g = 0xFF;
  temp_s0[arg1].unk0.b = 0xFF;

  while ((temp_s0[sp28].unk24 & GUI_QUIT) != GUI_QUIT) {
    if (temp_s0[sp28 + 1].unk24 & GUI_QUIT) {
      sp28 = 0;
    }
    if (temp_s0[sp28].unk24 & GUI_NULL) {
      if (temp_s0[sp28].unk24 & GUI_TEXTBOX) {
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
        return sp28;
      }
    } else {
      Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
      return sp28;
    }
    sp28++;
  }

  return arg1;
}

static void func_80091A8C(UnkStruct_78 *arg0) {
  register UnkStruct_77 *temp_s0 = arg0->unk124;

  if ((temp_s0->unk2C != NULL) && (D_800D3CF8 == NULL)) {
    temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
    temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
    temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
    temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
    temp_s0[D_800D3D10[0]].unk0.a = 0xA0;
    temp_s0[D_800D3D10[0]].unk0.r = 0xFF;
    temp_s0[D_800D3D10[0]].unk0.g = 0xFF;
    temp_s0[D_800D3D10[0]].unk0.b = 0xFF;
    D_800D3CF8 = temp_s0->unk2C;
    D_800D3CFC = temp_s0->unk30;
  }

  if (D_800D5850 == temp_s0) {
    FUN_SRAM_8007868c_tenliner_loop_arg0_t(D_800D57A4.node);
    D_800D57A4.node = &D_800D2D80;
    D_800D57A4.unk5D = 0xFE;
    D_800D57A4.unk60 = 0xFD;
    D_800D57A4.unk62 = 0;
  }

  if (D_800D5D48 == temp_s0) {
    FUN_SRAM_8007868c_tenliner_loop_arg0_t(D_800D5AC4.node);
    D_800D5AC4.node = &D_800D2D80;
    D_800D5AC4.unk5D = 0xFE;
    D_800D5AC4.unk60 = 0xFD;
    D_800D5B28.node = &D_800D2D80;
    D_800D5B8C.node = &D_800D2D80;
    D_800D5BF0.node = &D_800D2D80;
    func_800A2E2C();
  }

  if (D_800D5180 == temp_s0) {
    D_800D5014.node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(D_800D5014.node);
    D_800D5014.node = &D_800D2DB0;
    D_800D5014.unk5D = 0xFE;
    D_800D5014.unk60 = 0xFC;
  }

  if (D_800D4E1C == temp_s0) {
    D_800D4CDC.node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(D_800D4CDC.node);
    D_800D4CDC.node = &D_800D2DC8;
    D_800D4CDC.unk5D = 0xF7;
    D_800D4CDC.unk60 = 0xF9;
  }
}

static void func_80091D60(GUI_Textbox *arg0, UnkStruct_78 *arg1, s32 arg2, f32 arg3) {
  register UnkStruct_77 *temp_s0 = arg1->unk124;
  UnkStruct_1 *sp218;
  Player *sp214;
  PlayerNode *sp210;
  s32 sp20C;
  s32 pfs_err_1;
  OSPfsState cpaknote_1;
  PlayerNode *sp1E4;
  Player *sp1E0;
  u8 *sp1DC;
  s32 file_no_1;
  s32 sp1D4;  // x
  s32 sp1D0;  // y
  s32 sp1CC;
  s32 sp1C8;
  s32 sp1C4;
  PlayerNode *sp1C0;
  s32 sp1BC;  // y
  s32 sp1B8;  // x
  s32 sp1B4;  // y
  s32 sp1B0;  // x
  s32 sp1AC;  // y
  s32 sp1A8;  // x
  s32 sp1A4;
  PlayerNode *sp1A0;
  OSPfsState cpaknote_2;
  u8 sp17F;
  s32 pfs_err_2;
  s32 sp174;
  s32 file_no_2;
  u8 *sp16C;
  s32 sp168;  // y
  s32 sp164;  // x
  s32 sp160;  // y
  s32 sp15C;  // x
  s32 sp158;  // y
  s32 sp154;  // x
  s32 sp150;  // y
  s32 sp14C;  // x
  s32 sp148;  // y
  s32 sp144;  // x
  s32 sp140;  // y
  s32 sp13C;  // x
  s32 sp138;  // y
  s32 sp134;  // x
  s32 sp130;  // y
  s32 sp12C;  // x
  s32 sp128;  // y
  s32 sp124;  // x
  s32 sp120;
  s32 sp11C;  // y
  s32 sp118;  // x
  s32 sp114;  // y
  s32 sp110;  // x
  PlayerNode *sp10C;
  PlayerNode *sp108;
  PlayerNode *sp104;
  s32 sp100;
  s32 spFC;  // unused
  s32 spF8;  // unused
  OSPfsState cpaknote_3;
  u8 spD7;
  s32 pfs_err_3;
  s32 spCC;
  s32 file_no_3;
  u8 *spC4;
  OSPfsState cpaknote_4;
  u8 spA3;
  s32 sp9C;
  s32 sp98;
  s32 sp94;
  OSPfsState cpaknote_5;
  u8 sp73;
  s32 pfs_err_5;
  s32 sp68;
  s32 sp64;
  s32 file_no_5;
  u8 *sp5C;
  s32 sp58;
  s32 sp54;  // x
  s32 sp50;  // y
  s32 sp4C;  // unused
  PlayerNode *sp48;
  u8 sp47;

  sp218 = &g_PV_arr[arg0->unk5C].unk28;
  if (arg0->unk62 == 2) {
    if (arg0->unk5D == 0xFE) {
      if (arg2 == 0) {
        arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
        if (arg0->unk60 != 0xFB) {
          for (sp20C = 0; sp20C < 32; sp20C++) {
            if (g_sram_ptr->unk0 & (1 << sp20C)) {
              sp210 = n64HeapAlloc(sizeof(PlayerNode));
              sp214 = n64HeapAlloc(sizeof(Player));
              func_8007B430(sp214, g_sram_ptr->unk4, sp20C * sizeof(UnkStruct_34));
              func_8007A6C4(sp214, sp210, 0xD);
              if (func_80079F90(arg0->node, sp210)) {
                n64HeapUnalloc(sp210);
                n64HeapUnalloc(sp214);
              } else {
                func_8007B420(sp214);
              }
            }
          }
        }
      }

      FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
      arg0->unk5E = FUN_001050_getControllerStatus(&superThread, arg0->unk5C);
      D_800D2D98.pack = 0xF;
      D_800D2D80.pack = 0xE;
      arg0->unk5C = 0;
      arg0->unk5D = 0;
      switch (arg0->unk60) {
      case 0xFB:
      case 0xFD:
      case 0xFE:
      case 0xFF:
        if (D_800D5D48 == temp_s0) {
          if (FUN_001050_cpakInit(&superThread, 0) == 0) {
            arg0->unk5F = 1;
          }
          if (FUN_001050_cpakInit(&superThread, 1) == 0) {
            D_800D5B28.unk5F = 1;
          }
          if (FUN_001050_cpakInit(&superThread, 2) == 0) {
            D_800D5B8C.unk5F = 1;
          }
          if (FUN_001050_cpakInit(&superThread, 3) == 0) {
            D_800D5BF0.unk5F = 1;
          }
        } else if (FUN_001050_cpakInit(&superThread, 0) == 0) {
          arg0->unk5F = 1;
        }
        break;
      case 0xFC:
        if (FUN_001050_cpakInit(&superThread, 0) == 0) {
          arg0->unk5F = 1;
        }
        arg0->unk5C = 0;
        break;
      default:
        arg0->unk5F = 0;
        D_800D5B28.unk5F = 0;
        D_800D5B8C.unk5F = 0;
        D_800D5BF0.unk5F = 0;
        break;
      }
      D_800D3DD8 = 1;
    }

    if ((arg0->unk5F == 1) && (D_800D3DD8 == 1)) {
      if (FUN_001050_getControllerStatus(&superThread, arg0->unk5C) & CONT_CARD_ON) {
        D_800D3DE4 = 8;
        bzero(cpaknote_1.ext_name, 4);
        bzero(cpaknote_1.game_name, 16);
        cpaknote_1.file_size = 128;
        cpaknote_1.game_code = 0x4E524945;  // 'NRIE'
        cpaknote_1.company_code = 0x3031;   // '01'
        sprintf(cpaknote_1.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);  // 'NEWTETRIS' (using N64 font codes)
        cpaknote_1.ext_name[0] = D_800D3DEC + D_800D3DE8;
        FUN_001050_cpakInit(&superThread, arg0->unk5C);
        for (D_800D3DE8 = 0; D_800D3DE8 < 16; D_800D3DE8++) {
          D_800D3DF0 = 0;
          cpaknote_1.ext_name[0] = D_800D3DEC + D_800D3DE8;
          pfs_err_1 = FUN_001050_cpakFindFile(&superThread, &cpaknote_1, arg0->unk5C);
          file_no_1 = pfs_err_1;
          if (!((pfs_err_1 >> 4) & 0xF)) {
            sp1DC = n64HeapAlloc(128);
            bzero(sp1DC, 128);
            pfs_err_1 = FUN_001050_cpakRead(&superThread, file_no_1, 128, 0, sp1DC, arg0->unk5C);
            if (((pfs_err_1 >> 4) & 0xF) || ((sp1DC[6] == 0) && (sp1DC[7] == 0))) {
              pfs_err_1 = FUN_001050_cpakDeleteFile(&superThread, &cpaknote_1, arg0->unk5C);
              n64HeapUnalloc(sp1E4);
              n64HeapUnalloc(sp1E0);
              n64HeapUnalloc(sp1DC);
              D_800D3DF0 = 1;
            }
            if (D_800D3DF0 == 0) {
              sp1E4 = n64HeapAlloc(sizeof(PlayerNode));
              sp1E0 = n64HeapAlloc(sizeof(Player));
              func_8007B430(sp1E0, (UnkStruct_34 *) sp1DC, 0);
              func_8007A6C4(sp1E0, sp1E4, (arg0->unk5C << 4) | 0xC);
              sp1E0->unkD4 = (arg0->unk5C << 4) | 0xC;
              if (func_80079F90(arg0->node, sp1E4)) {
                n64HeapUnalloc(sp1E4);
                n64HeapUnalloc(sp1E0);
              }
              n64HeapUnalloc(sp1DC);
            }
          }
        }
      }

      FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
      arg0->unk5F = 0;
      arg0->unk5E = FUN_001050_getControllerStatus(&superThread, arg0->unk5C);
      if (arg0->unk60 == 0xFC) {
        arg0->unk5C = 0xFF;
      }

    } else if (arg0->unk5D >= 0x81) {
      sp1D4 = 60;
      sp1D0 = 50;

      if (arg0->unk5D == 0xF7) {
        for (sp1CC = 0; sp1CC < 5; sp1CC++) {
          arg0->node->name[sp1CC] = D_800D3D48[15][sp1CC];  // "TITLE"
        }
        arg0->node->name[sp1CC] = 0;
        if (D_800CF830 == 0x30) {
          sp1C4 = 15;
        } else {
          sp1C4 = (D_800CF838 % 7) + 9;
        }
        for (sp1CC = 0; sp1CC < sp1C4; sp1CC++) {
          sp1C0 = n64HeapAlloc(sizeof(PlayerNode));
          for (sp1C8 = 0; D_800D3D48[sp1CC][sp1C8] != '.'; sp1C8++) {
            sp1C0->name[sp1C8] = D_800D3D48[sp1CC][sp1C8];
          }
          sp1C0->name[sp1C8] = 0;
          sp1C0->pack = 3;
          sp1C0->salt[0] = sp1CC + 1;
          sp1C0->ptr = NULL;
          if (func_80079F90(arg0->node, sp1C0)) {
            n64HeapUnalloc(sp1C0);
          }
        }
        arg0->unk5D = 0;
        arg0->node = &D_800D2DC8;
        for (sp1CC = 0; sp1CC < g_sram_ptr->song; sp1CC++) {
          arg0->node = arg0->node->last;
        }

      } else if (arg0->unk5D == 0xF6) {
        arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
        arg0->unk5D = 0;

      } else if (arg0->unk5D == 0xEF) {
        sp1BC = sp1D0;
        sp1B8 = sp1D4;
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1BC, "WARNING THERE ARE NOT", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1BC += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1BC, "ENOUGH NOTES OR PAGES", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1BC += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1BC, "REMAINING TO SAVE A NEW", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1BC += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1BC, "NAME TO THE CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1BC += 20;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1BC, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        sp1B8 += get_text_width(&D_80128F28, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1B8, sp1BC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
        sp1B8 += get_text_width(&D_80128F28, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1B8, sp1BC, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
        if (g_PV_arr[arg2].unk24 & 0x8000) {
          arg0->unk4 = 0;
          arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
          arg0->unk5D = 0xF6;
          D_800D42B4[8].unk24 = GUI_NULL;
          D_800D3D10[0] = D_800D3D00[0];
          D_800D3D00[0] = 5;
          arg0->unk60 = 0xF8;
        }

      } else if (arg0->unk5D == 0xF3) {
        sp1B4 = sp1D0;
        sp1B0 = sp1D4;
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 9, 0xFF, 0xFF, 0xFF, 0xFF);
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1B4, "THERE IS NOT ENOUGH", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1B4 += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1B4, "SPACE REMAINING ON THE", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1B4 += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1B4, "GAME PAK TO SAVE A NEW", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1B4 += 15;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1B4, "NAME: PLEASE DELETE ONE", 0xFF, 0xFF, 0xFF, 0xFF);
        sp1B4 += 20;
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1B4, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
        sp1B0 += get_text_width(&D_80128F28, "PRESS ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1B0, sp1B4, "A ", 0x5A, 0x50, 0xB9, 0xFF);
        sp1B0 += get_text_width(&D_80128F28, "A ");
        displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1B0, sp1B4, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
        if (g_PV_arr[arg2].unk24 & 0x8000) {
          arg0->unk61 = FALSE;
          arg0->unk5D = 0;
          D_800D3DD4 = 0;
        }

      } else if (D_800D3DD4 == 0) {

        if (arg0->unk5D == 0xFB) {
          sp1AC = sp1D0;
          sp1A8 = sp1D4;
          sp1A0 = arg0->node;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1AC, "ARE YOU SURE YOU WANT TO", 0xFF, 0xFF, 0xFF, 0xFF);
          sp1AC += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp1AC, "DELETE THIS PLAYER?", 0xFF, 0xFF, 0xFF, 0xFF);
          sp1AC += 25;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1A8, sp1AC, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp1A8 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1A8, sp1AC, "ACCEPT ", 0xFF, 0xFF, 0, 0xFF);
          sp1A8 += get_text_width(&D_80128F28, "ACCEPT ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1A8, sp1AC, "B ", 0x70, 0xC3, 0x74, 0xFF);
          sp1A8 += get_text_width(&D_80128F28, "B ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1A8, sp1AC, "CANCEL ", 0xFF, 0xFF, 0, 0xFF);

          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3DF4 = 0;

            switch (sp1A0->pack & 0xF) {
            case 0xD:
              for (sp1A4 = 0; sp1A4 < 32; sp1A4++) {
                if (func_8007AADC((u8 *) &g_sram_ptr->unk4[sp1A4], arg0->node->salt[0], arg0->node->salt[1])) {
                  func_8007A62C(g_sram_ptr, sp1A4);
                  bzero(&g_sram_ptr->unk4[sp1A4], sizeof(UnkStruct_34));
                  arg0->node = func_8007AEB0(arg0->node);
                  break;
                }
              }
              func_8007C5CC(g_sram_ptr);
              arg0->unk5D = 0xF1;
              return;
            case 0xC:
              sp17F = 0x1A;  // cpak note extension name base 'A' (N64 font code)
              sp174 = 0;
              bzero(cpaknote_2.ext_name, 4);
              bzero(cpaknote_2.game_name, 16);
              cpaknote_2.file_size = 128;
              cpaknote_2.game_code = 0x4E524945;  // 'NRIE'
              cpaknote_2.company_code = 0x3031;   // '01'
              sprintf(cpaknote_2.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);  // 'NEWTETRIS' (using N64 font codes)
              cpaknote_2.ext_name[0] = sp17F;
              sp16C = n64HeapAlloc(128);
              pfs_err_2 = FUN_001050_cpakInit(&superThread, arg0->unk5C);
              if ((pfs_err_2 >> 4) & 0xF) {
                arg0->unk5D = 0xFA;
                n64HeapUnalloc(sp16C);
                return;
              }

              for (sp174 = 0; sp174 < 16; sp174++) {
                cpaknote_2.ext_name[0] = sp17F + sp174;
                pfs_err_2 = FUN_001050_cpakFindFile(&superThread, &cpaknote_2, arg0->unk5C);
                if (!((pfs_err_2 >> 4) & 0xF)) {
                  file_no_2 = pfs_err_2;
                  pfs_err_2 = FUN_001050_cpakRead(&superThread, file_no_2, 32, 0, sp16C, arg0->unk5C);
                  if (func_8007AADC(sp16C, arg0->node->ptr->node.salt[0], arg0->node->ptr->node.salt[1])) {
                    pfs_err_2 = FUN_001050_cpakDeleteFile(&superThread, &cpaknote_2, arg0->unk5C);
                    if ((pfs_err_2 >> 4) & 0xF) {
                      arg0->unk5D = 0xFA;
                      n64HeapUnalloc(sp16C);
                      return;
                    }
                    arg0->node = func_8007AEB0(arg0->node);
                    break;
                  }
                }
              }
              n64HeapUnalloc(sp16C);
              arg0->unk5D = 0xF1;
              return;
            }
          }

          if (g_PV_arr[arg2].unk24 & 0x4000) {
            D_800D3D00[arg0->unk5C] = 5;
            D_800D3D10[arg0->unk5C] = 7;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5C = 0xFF;
            arg0->unk5D = 0xF6;
            arg0->unk4 = 0;
            D_800D3DF4 = 0;
            D_800D3D10[0] = D_800D3D00[0];
            D_800D3D00[0] = 7;
            D_800D42B4[8].unk24 = GUI_NULL;
            arg0->unk60 = 0xF8;
            D_800D3DF4 = 0;
          }
        }

        if (arg0->unk5D == 0xF1) {
          sp168 = sp1D0 + 10;
          sp164 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp168, "DELETE SUCCESSFUL", 0xFF, 0xFF, 0xFF, 0xFF);
          sp168 += 20;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp168, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp164 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp164, sp168, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp164 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp164, sp168, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3DF8 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk60 = 0xF8;
            arg0->unk5C = 0xFF;
            arg0->unk4 = 0;
            D_800D3D10[0] = D_800D3D00[0];
            D_800D3D00[0] = 7;
            D_800D42B4[8].unk24 = GUI_NULL;
            return;
          }
        }

        if (arg0->unk5D == 0xF4) {
          sp160 = sp1D0 + 10;
          sp15C = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp160, "TRANSFER TO CONTROLLER", 0xFF, 0xFF, 0xFF, 0xFF);
          sp160 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp160, "PAK SUCCESSFUL", 0xFF, 0xFF, 0xFF, 0xFF);
          sp160 += 20;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp160, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp15C += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp15C, sp160, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp15C += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp15C, sp160, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3DFC = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
            arg0->unk5D = 0xF6;
            arg0->unk60 = 0xF8;
            arg0->unk5C = 0xFF;
            arg0->unk4 = 0;
            D_800D3D10[0] = D_800D3D00[0];
            D_800D3D00[0] = 5;
            D_800D42B4[8].unk24 = GUI_NULL;
            return;
          }
        }

        if (arg0->unk5D == 0xEE) {
          sp158 = sp1D0 + 10;
          sp154 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp158, "TRANSFER TO GAME", 0xFF, 0xFF, 0xFF, 0xFF);
          sp158 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp158, "PAK SUCCESSFUL", 0xFF, 0xFF, 0xFF, 0xFF);
          sp158 += 20;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp158, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp154 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp154, sp158, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp154 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp154, sp158, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E00 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
            arg0->unk5D = 0xF6;
            arg0->unk60 = 0xF8;
            arg0->unk5C = 0xFF;
            arg0->unk4 = 0;
            D_800D3D10[0] = D_800D3D00[0];
            D_800D3D00[0] = 5;
            D_800D42B4[8].unk24 = GUI_NULL;
            return;
          }
        }

        if (arg0->unk5D == 0xF2) {
          sp150 = sp1D0 + 10;
          sp14C = sp1D4;
          if (D_800D3E04 == 0) {
            D_800D3E04 = 1;
            g_PV_arr[arg2].unk24 = 0;
            D_80129018 = n64HeapAlloc(20);
            sprintf(D_80129018, "%d", D_800D3DD0);
          }
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp14C, sp150, "DUMPED ", 0xFF, 0xFF, 0xFF, 0xFF);
          sp14C += get_text_width(&D_80128F28, "DUMPED ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp14C, sp150, D_80129018, 0xFF, 0xFF, 0xFF, 0xFF);
          sp150 += 15;
          sp14C = sp1D4;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp150, "LINES TO GAME PAK", 0xFF, 0xFF, 0xFF, 0xFF);
          sp150 += 20;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp150, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp14C += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp14C, sp150, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp14C += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp14C, sp150, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            n64HeapUnalloc(D_80129018);
            D_800D3E04 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5C = 0xFF;
            arg0->unk5D = 0xF6;
            arg0->unk4 = 0;
            D_800D3E04 = 0;
            D_800D3D10[0] = D_800D3D00[0];
            D_800D3D00[0] = 6;
            D_800D42B4[8].unk24 = GUI_NULL;
            return;
          }
        }

        if (arg0->unk5D == 0xFA) {
          sp148 = sp1D0;
          sp144 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp148, "ERROR ACCESSING", 0xFF, 0xFF, 0xFF, 0xFF);
          sp148 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp148, "CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
          sp148 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp148, "PLEASE REINSERT CONTROLLER", 0xFF, 0xFF, 0xFF, 0xFF);
          sp148 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp148, "PAK AND TRY AGAIN", 0xFF, 0xFF, 0xFF, 0xFF);
          sp148 += 25;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp148, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp144 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp144, sp148, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp144 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp144, sp148, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E08 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xEB) {
          sp140 = sp1D0;
          sp13C = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp140, "ERROR", 0xFF, 0xFF, 0xFF, 0xFF);
          sp140 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp140, "CONTROLLER PAK DAMAGED", 0xFF, 0xFF, 0xFF, 0xFF);
          sp140 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp140, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp13C += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp13C, sp140, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp13C += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp13C, sp140, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E0C = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xEA) {
          sp138 = sp1D0;
          sp134 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp138, "ERROR", 0xFF, 0xFF, 0xFF, 0xFF);
          sp138 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp138, "NEW CONTROLLER PAK INSERTED", 0xFF, 0xFF, 0xFF, 0xFF);
          sp138 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp138, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp134 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp134, sp138, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp134 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp134, sp138, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E10 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xE9) {
          sp130 = sp1D0;
          sp12C = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp130, "ERROR", 0xFF, 0xFF, 0xFF, 0xFF);
          sp130 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp130, "DEVICE FAILED", 0xFF, 0xFF, 0xFF, 0xFF);
          sp130 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp130, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp12C += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp12C, sp130, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp12C += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp12C, sp130, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E14 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xED) {
          sp128 = sp1D0 - 3;
          sp124 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "CORRUPTED CONTROLLER PAK. WOULD YOU", 0xFF, 0xFF, 0xFF, 0xFF);
          sp128 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "LIKE TO REPAIR THE CONTROLLER PAK?", 0xFF, 0xFF, 0xFF, 0xFF);
          sp128 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "SAVED DATA MAY BE LOST", 0xFF, 0xFF, 0xFF, 0xFF);
          sp128 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp124 += get_text_width(&D_80128FA0, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp124, sp128, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp124 += get_text_width(&D_80128FA0, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp124, sp128, "TO REPAIR ", 0xFF, 0xFF, 0, 0xFF);
          sp128 += 15;
          sp124 = sp1D4;
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp124 += get_text_width(&D_80128FA0, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp124, sp128, "B ", 0x70, 0xC3, 0x74, 0xFF);
          sp124 += get_text_width(&D_80128FA0, "B ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp124, sp128, "TO CONTINUE WITHOUT", 0xFF, 0xFF, 0, 0xFF);
          sp128 += 15;
          sp124 = sp1D4;
          displayText_XY_RGBA_2(&g_gdl, &D_80128FA0, sp1D4, sp128, "SAVING TO THE CONTROLLER PAK", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            sp120 = 0;
            FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
            sp120 = FUN_001050_cpakInit(&superThread, arg2);
            sp120 = FUN_001050_cpakRepairId(&superThread, NULL, 0);
            if (!(sp120 & 0xF) || ((sp120 >> 4) & 0xF) == 8 || ((sp120 >> 4) & 0xF) == 7) {
              arg0->unk5D = 0xEC;
            } else {
              sp120 = (sp120 >> 4) & 0xF;
              switch (sp120) {
              case 1:
                arg0->unk5D = 0xF0;
                break;
              case 2:
                arg0->unk5D = 0xEA;
                break;
              case 4:
                arg0->unk5D = 0xE9;
                break;
              case 10:
                arg0->unk5D = 0xEB;
                break;
              case 11:
                arg0->unk5D = 0xE9;
                break;
              default:
                arg0->unk5D = 0xEB;
                break;
              }
            }
            return;
          } else if (g_PV_arr[arg2].unk24 & 0x4000) {
            D_800D3E18 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xEC) {
          sp11C = sp1D0;
          sp118 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp11C, "CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
          sp11C += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp11C, "SUCCESSFULLY REPAIRED", 0xFF, 0xFF, 0xFF, 0xFF);
          sp11C += 25;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp11C, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp118 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp118, sp11C, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp118 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp118, sp11C, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          sp11C += 15;
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E1C = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }

        if (arg0->unk5D == 0xF0) {
          sp114 = sp1D0;
          sp110 = sp1D4;
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129028, NULL, sp1D4 - 10, sp1D0 - 10, 0xFF, 0xFF, 0xFF, 0xFF);
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp114, "NO CONTROLLER PAK", 0xFF, 0xFF, 0xFF, 0xFF);
          sp114 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp114, "PLEASE INSERT CONTROLLER", 0xFF, 0xFF, 0xFF, 0xFF);
          sp114 += 15;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp114, "PAK AND TRY AGAIN", 0xFF, 0xFF, 0xFF, 0xFF);
          sp114 += 25;
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp1D4, sp114, "PRESS ", 0xFF, 0xFF, 0, 0xFF);
          sp110 += get_text_width(&D_80128F28, "PRESS ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp110, sp114, "A ", 0x5A, 0x50, 0xB9, 0xFF);
          sp110 += get_text_width(&D_80128F28, "A ");
          displayText_XY_RGBA_2(&g_gdl, &D_80128F28, sp110, sp114, "TO CONTINUE ", 0xFF, 0xFF, 0, 0xFF);
          if (g_PV_arr[arg2].unk24 & 0x8000) {
            D_800D3E20 = 0;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            arg0->unk4 = 0;
            arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
            arg0->unk5D = 0xF6;
            arg0->unk5C = 0xFF;
            D_800D42B4[8].unk24 = GUI_NULL;
            D_800D3D10[0] = D_800D3D00[0];
            if (arg0->unk60 == 0xFF) {
              D_800D3D00[0] = 7;
            }
            if (arg0->unk60 == 0xFE) {
              D_800D3D00[0] = 5;
            }
            if (arg0->unk60 == 0xFB) {
              D_800D3D00[0] = 6;
            }
            if (arg0->unk60 == 0xFA) {
              D_800D3D00[0] = 4;
            }
            arg0->unk60 = 0xF8;
          }
        }
      }

    } else if (D_800D3DD4 == 0) {

      if ((arg0->unk5C == 0xFF) || ((arg2 == 0) && (arg0->unk5C != 0))) {
        if (g_PV_arr[arg2].unk24 & 0x8000) {
          if ((D_800D5D48 == temp_s0) || (D_800D5850 == temp_s0)) {
            arg0->unk61 = FALSE;
          }
          arg0->unk5C = arg2;
          Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
          if ((arg0->node->pack & 0xF) == 0xE) {
            arg0->node->pack &= ~((1 << arg0->unk5C) << 4);
          } else {
            arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
          }
        }

        if ((g_PV_arr[arg2].unk24 & 0x4000) && (arg2 == 0)) {
          if (D_800D3D94 != 0) {
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            return;
          }

          if (((D_800D5D48 == temp_s0) || (D_800D5850 == temp_s0)) && arg0->unk61) {
            arg0->unk61 = FALSE;
            arg0->unk5C = arg2;
            arg0->unk5D = 0;
            if ((arg0->node->pack & 0xF) == 0xE) {
              arg0->node->pack &= ~((1 << arg0->unk5C) << 4);
            } else {
              arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
            }
            return;
          }

          func_80091A8C(arg1);
          Audio2_Play_SFX(&D_801235B0, &D_800D3988, 5);
          if (arg0->unk60 == 0xF9) {
            return;
          }

          arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);

          if ((arg0->unk60 == 0xFF) || (arg0->unk60 == 0xFE) || (arg0->unk60 == 0xFB) || (arg0->unk60 == 0xFA)) {
            arg0->unk5D = 0xF6;
            arg0->unk60 = 0xF8;
          }

          if (arg0->unk60 == 0xFC) {
            arg0->unk5D = 0xFE;
            arg0->unk60 = 0xFC;
          }

          if (D_800D5D48 == temp_s0) {
            D_800D5B28.node = arg0->node;
            D_800D5B8C.node = arg0->node;
            D_800D5BF0.node = arg0->node;
            func_800A2E2C();
          }
        }

        if ((arg2 == 0) && (arg0->unk5C != 0)) {

          if (g_PV_arr[arg2].unk24 & 0x800) {
            if (D_800D3D94 != 0) {
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
              return;
            }

            D_800D3D00[arg2] = func_80091440(arg1, D_800D3D00[arg2], &D_800D3D10[arg2]);
          }

          if (g_PV_arr[arg2].unk24 & 0x400) {
            if (D_800D3D94 != 0) {
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            } else if (D_800D5850 == temp_s0) {
              D_800D3D00[arg2] = func_80091744(arg1, D_800D3D00[arg2], &D_800D3D10[arg2]);
            } else if (D_800D3D00[arg2] == 3) {
              D_800D3D00[arg2] = 7;
            } else {
              D_800D3D00[arg2] = func_80091744(arg1, D_800D3D00[arg2], &D_800D3D10[arg2]);
            }
          }
        }

      } else if ((arg0->unk5C == arg2) || (arg2 == 0)) {

        if (arg0->unk5D == 0) {
          sp10C = arg0->node;

          if (sp218->unk84 & 0x4000) {
            if (arg0->unk5C == 0) {
              arg0->node->pack = (((arg0->node->pack >> 4) & 0xF & ~((1 << arg0->unk5C) & 0xF)) << 4) | (arg0->node->pack & 0xF);
              if ((arg0->unk60 == 0xFF) || (arg0->unk60 == 0xFE) || (arg0->unk60 == 0xFB) || (arg0->unk60 == 0xFA)) {
                arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
                arg0->unk5D = 0xF6;
                arg0->unk5C = 0xFF;
                D_800D42B4[8].unk24 = GUI_NULL;
                D_800D3D10[0] = D_800D3D00[0];
                if (arg0->unk60 == 0xFF) {
                  D_800D3D00[0] = 7;
                }
                if (arg0->unk60 == 0xFE) {
                  D_800D3D00[0] = 5;
                }
                if (arg0->unk60 == 0xFB) {
                  D_800D3D00[0] = 6;
                }
                if (arg0->unk60 == 0xFA) {
                  D_800D3D00[0] = 4;
                }
                arg0->unk60 = 0xF8;
              } else if (arg0->unk60 == 0xFC) {
                arg0->unk5D = 0;
                arg0->unk60 = 0xFC;
                arg0->unk5C = 0xFF;
              } else if (arg0->unk60 == 0xF9) {
                arg0->unk61 = FALSE;
                arg0->unk5C = 0xFF;
                arg0->unk5D = 0;
              } else if (!arg0->unk61) {
                if (D_800D3D94 != 0) {
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
                } else {
                  func_80091A8C(arg1);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 5);
                  if (D_800D5D48 == temp_s0) {
                    D_800D5B28.node = arg0->node;
                    D_800D5B8C.node = arg0->node;
                    D_800D5BF0.node = arg0->node;
                    func_800A2E2C();
                  }
                  arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
                  arg0->unk61 = FALSE;
                }
              } else {
                arg0->unk61 = FALSE;
                arg0->unk5C = 0xFF;
                arg0->unk5D = 0;
              }

              return;
            }
          }

          if ((sp218->unk84 & 0x400) || (sp218->unk84 & 0x100)) {
            sp108 = arg0->node;
            if ((sp108->pack & 0xF) != 0xE) {
              sp108->pack = (((sp108->pack >> 4) & 0xF & ~(1 << arg0->unk5C)) << 4) | (sp108->pack & 0xF);
            }

            do {
              if (((sp108->next->pack & 0xF) == 0xE) || ((sp108->next->pack & 0xF) == 0xF) || ((sp108->next->pack & 0xF) == 4) || ((sp108->next->pack & 0xF) == 9)) {
                arg0->node = sp108->next;
                break;
              }

              if (sp108->next->ptr != NULL) {
                if ((sp108->next->ptr->unkD4 & 0xF) == 0xC) {
                  if (((sp108->next->ptr->unkD4 >> 4) & 0xF) == arg0->unk5C) {
                    arg0->node = sp108->next;
                    break;
                  }
                } else if (((sp108->next->pack >> 4) & 0xF) == 0) {
                  arg0->node = sp108->next;
                  if ((arg0->node->pack & 0xF) != 0xE) {
                    arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
                  }
                  break;
                }
              } else {
                if (((sp108->next->pack >> 4) & 0xF) == 0) {
                  arg0->node = sp108->next;
                  if ((sp108->pack & 0xF) != 0xE) {
                    arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
                  }
                  break;
                }
              }

              sp108 = sp108->next;
            } while (arg0->node != sp108);

            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
            return;
          }

          if ((sp218->unk84 & 0x200) || (sp218->unk84 & 0x800)) {
            sp104 = arg0->node;
            if ((sp104->pack & 0xF) != 0xE) {
              sp104->pack = (((sp104->pack >> 4) & 0xF & ~(1 << arg0->unk5C)) << 4) | (sp104->pack & 0xF);
            }

            do {
              if (((sp104->last->pack & 0xF) == 0xE) || ((sp104->last->pack & 0xF) == 0xF) || ((sp104->last->pack & 0xF) == 4) || ((sp104->last->pack & 0xF) == 9)) {
                arg0->node = sp104->last;
                break;
              }

              if (sp104->last->ptr != NULL) {
                if ((sp104->last->ptr->unkD4 & 0xF) == 0xC) {
                  if (((sp104->last->ptr->unkD4 >> 4) & 0xF) == arg0->unk5C) {
                    arg0->node = sp104->last;
                    break;
                  }
                } else if (((sp104->last->pack >> 4) & 0xF) == 0) {
                  arg0->node = sp104->last;
                  if ((arg0->node->pack & 0xF) != 0xE) {
                    arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
                  }
                  break;
                }
              } else {
                if (((sp104->last->pack >> 4) & 0xF) == 0) {
                  arg0->node = sp104->last;
                  if ((sp104->pack & 0xF) != 0xE) {
                    arg0->node->pack = ((1 << arg0->unk5C) << 4) | (arg0->node->pack & 0xF);
                  }
                  break;
                }
              }

              sp104 = sp104->last;
            } while (arg0->node != sp104);

            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1U);
            return;
          }

          if (sp218->unk84 & 0x8000) {

            if (arg0->node->pack == 0x4) {
              return;
            }

            if ((D_800D5D48 == temp_s0) || (D_800D5850 == temp_s0)) {
              arg0->unk61 = TRUE;
            }

            switch (arg0->unk60) {
            case 0xF9:
              if (sp10C->salt[0] != 0xFF) {
                if (g_sram_ptr->music_mode == 1) {  // CHOOSE
                  g_sram_ptr->song = sp10C->salt[0];  // TODO: is this wrong?
                  func_8007C5CC(g_sram_ptr);
                } else {  // TODO: this does the same thing as above -- why?
                  g_sram_ptr->song = sp10C->salt[0];
                  func_8007C5CC(g_sram_ptr);
                }
                D_800D3D88 = TRUE;
                return;
              }
              break;

            case 0xFF:
              if (arg0->node->ptr != NULL) {
                arg0->unk5D = 0xFB;
              }
              return;

            case 0xFB:
              if ((sp10C->pack & 0xF) == 0xC) {
                spD7 = 0x1A;  // cpak note extension name base 'A' (N64 font code)
                spCC = 0;
                bzero(cpaknote_3.ext_name, 4);
                bzero(cpaknote_3.game_name, 16);
                cpaknote_3.file_size = 128;
                cpaknote_3.game_code = 0x4E524945;  // 'NRIE'
                cpaknote_3.company_code = 0x3031;   // '01'
                sprintf(cpaknote_3.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);  // 'NEWTETRIS' (using N64 font codes)
                cpaknote_3.ext_name[0] = spD7;
                spC4 = n64HeapAlloc(128);
                pfs_err_3 = FUN_001050_cpakInit(&superThread, arg0->unk5C);
                if ((pfs_err_3 >> 4) & 0xF) {
                  arg0->unk5D = 0xFA;
                  n64HeapUnalloc(spC4);
                  return;
                }
                D_800D3DD0 = arg0->node->ptr->unkC4;
                func_800798F0(arg0->node->ptr, g_sram_ptr, arg0->node->ptr->unkC4);
                arg0->node->ptr->unkC4 = 0;

                for (spCC = 0; spCC < 16; spCC++) {
                  cpaknote_3.ext_name[0] = spD7 + spCC;
                  pfs_err_3 = FUN_001050_cpakFindFile(&superThread, &cpaknote_3, arg0->unk5C);
                  if (!((pfs_err_3 >> 4) & 0xF)) {
                    file_no_3 = pfs_err_3;
                    pfs_err_3 = FUN_001050_cpakRead(&superThread, file_no_3, 32, 0, spC4, arg0->unk5C);
                    if ((pfs_err_3 >> 4) & 0xF) {
                      arg0->unk5D = 0xFA;
                      n64HeapUnalloc(spC4);
                      return;
                    }
                    if (func_8007AADC(spC4, arg0->node->ptr->node.salt[0], arg0->node->ptr->node.salt[1])) {
                      pfs_err_3 = FUN_001050_cpakDeleteFile(&superThread, &cpaknote_3, arg0->unk5C);
                      if ((pfs_err_3 >> 4) & 0xF) {
                        arg0->unk5D = 0xFA;
                        n64HeapUnalloc(spC4);
                        return;
                      }
                      pfs_err_3 = FUN_001050_cpakAllocFile(&superThread, &cpaknote_3, arg0->unk5C);
                      if ((pfs_err_3 >> 4) & 0xF) {
                        arg0->unk5D = 0xFA;
                        n64HeapUnalloc(spC4);
                        return;
                      }
                      file_no_3 = pfs_err_3;
                      bzero(spC4, 128);
                      func_8007B420(arg0->node->ptr);
                      func_8007AF88(arg0->node->ptr, spC4, 0);
                      pfs_err_3 = FUN_001050_cpakWrite(&superThread, file_no_3, 128, 0, spC4, arg0->unk5C);
                      if ((pfs_err_3 >> 4) & 0xF) {
                        arg0->unk5D = 0xFA;
                        n64HeapUnalloc(spC4);
                        return;
                      }
                      wonders2_80045fdc_sets_num_won_compl_q();
                      func_8007C5CC(g_sram_ptr);
                      break;
                    }
                  }
                }

                arg0->unk5D = 0xF2;
                n64HeapUnalloc(spC4);
                return;
              }
              break;

            case 0xFE:
              switch (sp10C->pack & 0xF) {
              case 0xD:
                spA3 = 0x1A;  // cpak note extension name base 'A' (N64 font code)
                sp98 = 0;
                sp94 = 0;
                bzero(cpaknote_4.ext_name, 4);
                bzero(cpaknote_4.game_name, 16);
                cpaknote_4.file_size = 128;
                cpaknote_4.game_code = 0x4E524945;  // 'NRIE'
                cpaknote_4.company_code = 0x3031;   // '01'
                sprintf(cpaknote_4.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);  // 'NEWTETRIS' (using N64 font codes)
                cpaknote_4.ext_name[0] = spA3;
                if ((FUN_001050_cpakInit(&superThread, arg0->unk5C) & 0xF) == 0xF) {
                  arg0->unk5D = 0xFA;
                  return;
                }

                if (((FUN_001050_cpakNumFiles(&superThread, arg0->unk5C) & 0xFF) >= 16) || (FUN_001050_cpakFreeBlocks(&superThread, NULL, arg0->unk5C) < 256)) {
                  arg0->unk5D = 0xEF;
                  return;
                }

                for (sp98 = 0, sp94 = 0; sp98 < 16; sp98++) {
                  cpaknote_4.ext_name[0] = spA3 + sp98;
                  sp9C = FUN_001050_cpakFindFile(&superThread, &cpaknote_4, arg0->unk5C);
                  if (((sp9C >> 4) & 0xF) == 0) {
                    // do nothing
                  } else if (((sp9C >> 4) & 0xF) == 5) {
                    sp9C = FUN_001050_cpakAllocFile(&superThread, &cpaknote_4, arg0->unk5C);
                    if (((sp9C >> 4) & 0xF) != 0) {
                      if (((sp9C >> 4) & 0xF) == 7) {
                        arg0->unk5D = 0xEF;
                      } else if (((sp9C >> 4) & 0xF) == 8) {
                        arg0->unk5D = 0xEF;
                      } else {
                        arg0->unk5D = 0xFA;
                      }
                      return;
                    }

                    if (((sp9C >> 4) & 0xF) == 0) {
                      for (sp100 = 0; sp100 < 32; sp100++) {
                        if (func_8007AADC((u8 *) &g_sram_ptr->unk4[sp100], arg0->node->salt[0], arg0->node->salt[1])) {
                          sp9C = FUN_001050_cpakWrite(&superThread, sp9C, 128, 0, (u8 *) &g_sram_ptr->unk4[sp100], arg0->unk5C);
                          if (((sp9C >> 4) & 0xF) != 0) {
                            FUN_001050_cpakDeleteFile(&superThread, &cpaknote_4, arg0->unk5C);
                            arg0->unk5D = 0xFA;
                            return;
                          }

                          sp9C = FUN_001050_cpakFindFile(&superThread, &cpaknote_4, arg0->unk5C);
                          if (((sp9C >> 4) & 0xF) == 0) {
                            sp94 = 1;
                            func_8007A62C(g_sram_ptr, sp100);
                            bzero(&g_sram_ptr->unk4[sp100], sizeof(UnkStruct_34));
                            func_8007C5CC(g_sram_ptr);
                            arg0->node->ptr->unkD4 = 0xC;
                            arg0->node->pack = (arg0->unk5C << 4) | 0xC;
                            break;
                          }

                          FUN_001050_cpakDeleteFile(&superThread, &cpaknote_4, arg0->unk5C);
                          arg0->unk5D = 0xFA;
                          return;
                        }
                      }
                    }
                  }
                  if (sp94 == 1) {
                    arg0->unk5D = 0xF4;
                    break;
                  }
                }
                if (sp94 == 0) {
                  arg0->unk5C = 0xFF;
                  arg0->unk5D = 0xFA;
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
                }
                break;

              case 0xC:
                sp73 = 0x1A;  // cpak note extension name base 'A' (N64 font code)
                sp68 = 0;
                sp64 = 0;
                bzero(cpaknote_5.ext_name, 4);
                bzero(cpaknote_5.game_name, 16);
                cpaknote_5.file_size = 128;
                cpaknote_5.game_code = 0x4E524945;  // 'NRIE'
                cpaknote_5.company_code = 0x3031;   // '01'
                sprintf(cpaknote_5.game_name, "%c%c%c%c%c%c%c%c%c", 0x27, 0x1E, 0x30, 0x2D, 0x1E, 0x2D, 0x2B, 0x22, 0x2C);  // 'NEWTETRIS' (using N64 font codes)
                cpaknote_5.ext_name[0] = sp73;

                if ((FUN_001050_cpakInit(&superThread, arg0->unk5C) & 0xF) == 0xF) {
                  arg0->unk5D = 0xFA;
                  return;
                }

                if (func_8007A660(g_sram_ptr) >= 16) {
                  arg0->unk5D = 0xF3;
                  return;
                }

                sp5C = n64HeapAlloc(128);
                for (sp68 = 0, sp64 = 0; sp68 < 16; sp68++) {
                  cpaknote_5.ext_name[0] = sp73 + sp68;
                  pfs_err_5 = FUN_001050_cpakFindFile(&superThread, &cpaknote_5, arg0->unk5C);
                  if (((pfs_err_5 >> 4) & 0xF) == 0) {
                    file_no_5 = pfs_err_5;
                    pfs_err_5 = FUN_001050_cpakRead(&superThread, file_no_5, 32, 0, sp5C, arg0->unk5C);
                    if (((pfs_err_5 >> 4) & 0xF) != 0) {
                      arg0->unk5D = 0xFA;
                      n64HeapUnalloc(sp5C);
                      return;
                    }

                    if (func_8007AADC(sp5C, arg0->node->ptr->node.salt[0], arg0->node->ptr->node.salt[1])) {
                      pfs_err_5 = FUN_001050_cpakDeleteFile(&superThread, &cpaknote_5, arg0->unk5C);
                      if (((pfs_err_5 >> 4) & 0xF) != 0) {
                        arg0->unk5D = 0xFA;
                        n64HeapUnalloc(sp5C);
                        return;
                      }

                      arg0->node->pack = (arg0->node->pack & 0xF0) | 0xD;
                      func_8007AF88(arg0->node->ptr, (u8 *) &g_sram_ptr->unk4[0], func_8007A5D4(g_sram_ptr) * sizeof(UnkStruct_34));
                      func_8007A648(g_sram_ptr, func_8007A5D4(g_sram_ptr));
                      func_8007C5CC(g_sram_ptr);
                      sp64 = 1;
                    } else if (((pfs_err_5 >> 4) & 0xF) == 5) {
                      arg0->unk5D = 0xFA;
                      n64HeapUnalloc(sp5C);
                      return;
                    }

                    if (sp64 == 1) {
                      arg0->unk5D = 0xEE;
                      n64HeapUnalloc(sp5C);
                      break;
                    }
                  }
                }

                if (sp64 == 0) {
                  arg0->unk5C = 0xFF;
                  arg0->unk5D = 0xFA;
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
                  n64HeapUnalloc(sp5C);
                }
                break;
              }
              break;

            case 0xFD:
              switch (sp10C->pack & 0xF) {
              case 0xF:
                if (D_800D3DD4 == 0) {
                  arg0->unk5 = 0;
                  arg0->unk4 = 0;
                  if ((D_800D5850 == temp_s0) && (func_8007A660(g_sram_ptr) >= 16)) {
                    arg0->unk5D = 0xF3;
                    return;
                  }

                  if ((D_800D5D48 == temp_s0) && (func_8007A660(g_sram_ptr) >= 14)) {
                    arg0->unk5D = 0xF3;
                    D_800D3DD4 = 1;
                    return;
                  }

                  arg0->node = func_8007A738(arg0->node, arg0->unk5C);
                  arg0->unk5D = 1;
                  arg0->unk4 = 0;

                  if (D_800D5850 == temp_s0) {
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    temp_s0[4].unk24 = GUI_NULL;
                    temp_s0[5].unk24 = GUI_NULL;
                    temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
                    temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
                    temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 3;
                  }

                  if (D_800D5D48 == temp_s0) {
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    temp_s0[7].unk24 = GUI_NULL;
                    temp_s0[8].unk24 = GUI_NULL;
                    temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
                    temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
                    temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 3;
                  }

                  D_800D3D94 |= 1 << arg0->unk5C;
                }
                return;

              case 0xE:
                arg0->unk5D = 0;
                sp10C->pack = (1 << arg2) << 4 | sp10C->pack;  // (bug?) missing "& 0xF"

                if ((D_800D3D94 == 0) && (arg0->unk5C == 0)) {
                  if (D_800D5850 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 4;
                  }

                  if (D_800D5D48 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 7;
                  }
                }

                arg0->unk5C = 0xFF;
                break;

              case 0xD:
                arg0->unk5D = 0;
                arg0->unk4 = 0;

                temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;

                sp10C->pack = ((1 << arg2) << 4) | (sp10C->pack & 0xF);

                if ((D_800D3D94 == 0) && (arg0->unk5C == 0)) {
                  if (D_800D5850 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 4;
                  }

                  if (D_800D5D48 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 7;
                  }
                }

                arg0->unk5C = 0xFF;
                break;

              default:
                arg0->unk5D = 0;
                sp10C->pack = ((1 << arg2) << 4) | (sp10C->pack & 0xF);

                if ((D_800D3D94 == 0) && (arg0->unk5C == 0)) {
                  if (D_800D5850 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 4;
                  }

                  if (D_800D5D48 == temp_s0) {
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3D10[0] = D_800D3D00[0];
                    D_800D3D00[0] = 7;
                  }
                }

                arg0->unk5C = 0xFF;
                break;
              }
              break;

            case 0xFC:
              arg0->unk5D = 0;
              arg0->unk5C = 0xFF;
              break;
            }
          }
        }

        if (arg0->unk5D == 1) {
          sp48 = arg0->node;

          if (sp218->unk84 & 0x100) {  // R_JPAD / CONT_RIGHT
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
            if (arg0->unk4 == 8) {
              arg0->unk4 = 7;
            }
            if (arg0->unk5 == 14) {
              arg0->unk5 = 0;
            } else if (arg0->unk5 == 29) {
              arg0->unk5 = 15;
            } else if (arg0->unk5 == 44) {
              arg0->unk5 = 30;
            } else {
              arg0->unk5++;
            }
            sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
          }

          if (sp218->unk84 & 0x200) {  // L_JPAD / CONT_LEFT
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
            if (arg0->unk4 == 8) {
              arg0->unk4 = 7;
            }
            if (arg0->unk5 == 0) {
              arg0->unk5 = 14;
            } else if (arg0->unk5 == 15) {
              arg0->unk5 = 29;
            } else if (arg0->unk5 == 30) {
              arg0->unk5 = 44;
            } else {
              arg0->unk5--;
            }
            sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
          }

          if (sp218->unk84 & 0x800) {  // U_JPAD / CONT_UP
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
            if (arg0->unk4 == 8) {
              arg0->unk4 = 7;
            }
            if ((arg0->unk5 - 15) < 0) {
              arg0->unk5 += 30;
            } else {
              arg0->unk5 -= 15;
            }
            sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
          }

          if (sp218->unk84 & 0x400) {  // D_JPAD / CONT_DOWN
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
            if (arg0->unk4 == 8) {
              arg0->unk4 = 7;
            }
            if ((arg0->unk5 + 15) >= 45) {
              arg0->unk5 -= 30;
            } else {
              arg0->unk5 += 15;
            }
            sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
          }

          if (g_PV_arr[arg0->unk5C].unk24 & 0x1000) {  // START_BUTTON / CONT_START
            arg0->unk5 = 44;
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
            if (arg0->unk4 < 8) {
              sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
            }
          }

          if (g_PV_arr[arg0->unk5C].unk24 & 0x8000) {  // A_BUTTON / CONT_A

            if (arg0->unk5 == 43) {  // BACKSPACE
              if (arg0->unk4 > 0) {
                Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
                sp48->name[arg0->unk4] = 0;
                arg0->unk4--;
              }

            } else if (arg0->unk5 == 44) {  // OK
              sp47 = FALSE;

              if (arg0->unk4 == 0) {
                Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
                return;
              }

              arg0->unk61 = TRUE;
              sp48->name[arg0->unk4] = 0;
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);

              for (sp58 = 0; sp58 < 8; sp58++) {
                sp48->ptr->node.name[sp58] = sp48->name[sp58];
              }

              arg0->unk5D = 0;

              if (D_800D5850 == temp_s0) {

                if ((sp48->name[0] == 'H') &&
                    (sp48->name[1] == 'A') &&
                    (sp48->name[2] == 'L') &&
                    (sp48->name[3] == 'U') &&
                    (sp48->name[4] == 'C') &&
                    (sp48->name[5] == 'I')) {
                  if (func_800A35EC(1, 3) == 2) {
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                    D_800D3CF0 = 4;
                  }
                  sp47 = TRUE;
                }

                if ((sp48->name[0] == '2') &&
                    (sp48->name[1] == 'F') &&
                    ((sp48->name[2] ^ 0x10) != 0) &&
                    (sp48->name[3] == 'S') &&
                    (sp48->name[4] == 'T') &&
                    (sp48->name[5] == '4') &&
                    (sp48->name[6] == 'U')) {
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                  g_pieceFallAcceleration = 0.0001;
                  sp47 = TRUE;
                }

                if (((sp48->name[0] ^ 0x3) != 0) &&
                    (sp48->name[1] == '1') &&
                    (sp48->name[2] == 'D') &&
                    ((sp48->name[3] ^ 0x1E) != 0) &&
                    (sp48->name[4] == 'R') &&
                    (sp48->name[5] == 'S')) {
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                  D_800CF830 = 0;
                  D_800CF834 = 0;
                  D_800CF838 = 0;
                  D_800CF83C = 0;
                  g_sram_ptr->total_wonder_lines_odd_bits = 0;
                  g_sram_ptr->total_wonder_lines_even_bits = 0;
                  func_8007C5CC(g_sram_ptr);
                  wonders2_80045e50_sets_num_won_compl_q();
                  g_game.unkE4F8 = D_800CF838;
                  sp47 = TRUE;
                }

                if ((sp48->name[0] == '1') &&
                    (sp48->name[1] == 'N') &&
                    (sp48->name[2] == '1') &&
                    ((sp48->name[3] ^ 0x4) != 0) &&
                    (sp48->name[4] == '5') &&
                    ((sp48->name[5] ^ 0xF) != 0) &&
                    (sp48->name[6] == '4') &&
                    (sp48->name[7] == 'M')) {
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                  D_800CF830 = 0;
                  D_800CF834 = 0;
                  D_800CF838 = 0;
                  D_800CF83C = 0;
                  load_from_sram(1);
                  wonders2_80045e50_sets_num_won_compl_q();
                  g_game.unkE4F8 = D_800CF838;
                  arg0->node = FUN_SRAM_8007868c_tenliner_loop_arg0_t(arg0->node);
                  sp47 = TRUE;
                }

                D_800E1F50 = FALSE;
                if ((sp48->name[0] == 'A') &&
                    (sp48->name[1] == 'I') &&
                    (sp48->name[2] == '2') &&
                    ((sp48->name[3] ^ 0xC) != 0) &&
                    (sp48->name[4] == 'Z') &&
                    ((sp48->name[5] ^ 0x14) != 0) &&
                    (sp48->name[6] == 'U') &&
                    (sp48->name[7] == '?')) {
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                  Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                  D_800E1F50 = TRUE;
                  sp47 = TRUE;
                }
              }

              D_800D3D94 &= ~(1 << arg0->unk5C);
              if (D_800D3D94 == 0) {
                Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                if (D_800D3D94 == 0) {
                  if (D_800D5850 == temp_s0) {
                    temp_s0[4].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                    temp_s0[5].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    if (!sp47 && (arg0->unk5C == 0)) {
                      D_800D3D10[0] = D_800D3D00[0];
                      D_800D3D00[0] = 4;
                    }
                  }
                  if (D_800D5D48 == temp_s0) {
                    temp_s0[7].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                    temp_s0[8].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                    temp_s0[D_800D3D00[arg2]].unk0.a = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.r = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.g = 0xA0;
                    temp_s0[D_800D3D00[arg2]].unk0.b = 0xA0;
                    if (!sp47 && (arg0->unk5C == 0)) {
                      D_800D3D10[0] = D_800D3D00[0];
                      D_800D3D00[0] = 7;
                    }
                  }
                }
              }
              if (sp47) {
                arg0->node = func_8007AEB0(arg0->node);
                arg0->node = &D_800D2D80;
              } else {
                func_8007A078(sp48, arg0->unk5C);
                arg0->unk5C = 0xFF;
              }
              return;

            } else if (sp48->name[0] != ' ') {
              if (arg0->unk4 < 8) {
                Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
                arg0->unk4++;
              }
              if (arg0->unk4 == 8) {
                arg0->unk4 = 8;
                arg0->unk5 = 44;
                return;
              }

            } else {
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            }

            sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
          }

          if (g_PV_arr[arg0->unk5C].unk24 & 0x4000) {  // B_BUTTON / CONT_B
            if (arg0->unk4 > 0) {
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
              sp48->name[arg0->unk4] = 0;
              arg0->unk4--;
              sp48->name[arg0->unk4] = D_800D3DA0[arg0->unk5];
            } else {
              arg0->unk61 = FALSE;
              D_800D3D94 &= ~(1 << arg0->unk5C);
              Audio2_Play_SFX(&D_801235B0, &D_800D3988, 5);
              if (D_800D3D94 == 0) {
                Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
                if (D_800D5850 == temp_s0) {
                  temp_s0[4].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                  temp_s0[5].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                }
                if (D_800D5D48 == temp_s0) {
                  temp_s0[7].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                  temp_s0[8].unk24 = GUI_TOGGLE | GUI_FUNC | GUI_TITLE;
                }
              }
              arg0->node = func_8007AEB0(arg0->node);
              arg0->node = &D_800D2D80;
              arg0->unk5D = 0;
            }
          }

          sp58 = 0;
          sp54 = arg0->unkC + 5;
          sp50 = arg0->unk10 + 8;
          do {
            if ((sp48->name[sp58] == 0) || (sp58 == 8)) {
              continue;
            }

            if (arg0->unk4 == sp58) {
              sp54 = displayText_XY_RGBA_3(&g_gdl, &D_80128F28, sp54, sp50, sp48->name[sp58], 255 * arg3, 255 * arg3, 255 * arg3, 255 * arg3);
            } else {
              sp54 = displayText_XY_RGBA_3(&g_gdl, &D_80128F28, sp54, sp50, sp48->name[sp58], 0xFF, 0xFF, 0xFF, 0xFF);
            }
          } while (++sp58 < 9);
        }
      }
    }
  } else {
    arg0->unk62++;
  }
}

static void func_80099674(UnkStruct_78 *arg0) {
  register UnkStruct_77 *temp_s0 = arg0->unk124;
  register s32 var_s1 = 0;
  register s32 var_s2;
  s32 spB8;  // cont_no; 3 to 0
  s32 spB4;  // y
  s32 spB0;  // x
  s32 spAC;  // y
  s32 spA8;  // a
  GUI_Toggle *gui_toggle_1;
  s32 spA0;  // x
  s32 sp9C;  // y
  s32 sp98;  // a
  s32 sp94;  // x
  s32 sp90;  // y
  s32 sp8C;  // r
  s32 sp88;  // g
  s32 sp84;  // b
  s32 sp80;  // a
  s32 i;
  GUI_Slider *gui_slider_1;
  GUI_Textbox *gui_textbox_1;
  GUI_Textbox *gui_textbox_2;
  GUI_Textbox *gui_textbox_3;
  s32 sp68;  // x
  s32 sp64;  // unused
  GUI_Textbox *gui_textbox_4;
  s32 sp5C;  // x
  UnkStruct_1 *sp58;
  GUI_Slider *gui_slider_2;
  GUI_Toggle *gui_toggle_2;

  D_800D3E24 += D_800D3E28;
  if (D_800D3E24 >= 1.0) {
    D_800D3E24 = 1.0;
    D_800D3E28 *= -1;
  }
  if (D_800D3E24 <= 0.6) {
    D_800D3E24 = 0.6;
    D_800D3E28 *= -1;
  }

  if (D_800D3FF8 == temp_s0) {
    D_800D3D30 = TRUE;
    D_800D3D2C++;
    if (D_800D3D2C == 1000) {
      D_800D3CF0 = 3;
      D_800D3D2C = 0;
    }
  } else {
    D_800D3D30 = FALSE;
    D_800D3D2C = 0;
  }

  if (D_800D3E40-- == 0) {
    FUN_001050_8003b5d0_controller_sendrecvmsg(&superThread);
    D_800D3E40 = 8;
    if (FUN_001050_getControllerErrNo(&superThread, 0) != 0) {
      main_8004A34C_threeliner();
      func_80090A44();
      D_800CFEE8 = 0;
      D_800CFD48 = TRUE;
      return;
    }
    if (D_800D3D30) {
      if (FUN_001050_getControllerErrNo(&superThread, 1) != 0) {
        if (D_800D3D00[0] == 4) {
          D_800D3D10[0] = D_800D3D00[0];
          D_800D3D00[0] = 3;
        }
        D_800D3FF8[4].unk24 = GUI_CENTX | GUI_MENU | GUI_NULL | GUI_TITLE;
        D_800D3FF8[4].unk0.a = 0x64;
      } else {
        D_800D3FF8[4].unk24 = GUI_CENTX | GUI_MENU | GUI_TITLE;
        D_800D3FF8[4].unk0.a = 0xA0;
      }
    }
  }

  if (temp_s0 == NULL) {
    return;
  }

  func_8005BBFC(&g_gdl);
  if (arg0->unk114 != 0) {
    if (D_800D3E34 != 0) {
      if (D_800D3E2C > 0.0) {
        D_800D3E2C -= D_800D3E30 * func_800A3AF0();
      }
      if (D_800D3E2C < 0.0) {
        D_800D3E2C = 0;
      }
      func_8007E750();
      if (D_800D3E2C == 0.0) {
        D_800D3D24 = 2;
        if (D_800D3E34 == 1) {
          temp_s0->unk0.a = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
          temp_s0[D_800D3D10[0]].unk0.a = 0xA0;
          func_80091A8C(arg0);
          D_800D3E2C = 0;
          D_800D3E34 = 0;
          func_8005BE40(&g_gdl);
          return;
        }
        if (D_800D3E34 == 2) {
          D_800D3E2C = 0;
          temp_s0->unk0.a = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
          temp_s0[D_800D3D10[0]].unk0.a = 0xA0;
          D_800D3CF8 = temp_s0[D_800D3D00[0]].unk2C;
          D_800D3CFC = temp_s0[D_800D3D00[0]].unk30;
          D_800D3E34 = 0;
          func_8005BE40(&g_gdl);
          return;
        }
      }
    } else {
      if (D_800D3E2C < 1.0) {
        D_800D3E2C += D_800D3E30 * func_800A3AF0();
      }
      if (D_800D3E2C > 1.0) {
        D_800D3E2C = 1;
      }
    }

    for (; (temp_s0[var_s1].unk24 & GUI_QUIT) != GUI_QUIT; var_s1++) {
      if ((temp_s0[var_s1].unk24 & GUI_TOGGLE) && (var_s1 != 0) && !(temp_s0[var_s1].unk24 & GUI_NULL)) {
        gui_toggle_1 = temp_s0[var_s1].unk30;
        spB0 = gui_toggle_1->unk4[gui_toggle_1->cur].x;
        spAC = gui_toggle_1->unk4[gui_toggle_1->cur].y;
        spA8 = temp_s0[var_s1].unk0.a * D_800D3E2C;
        if (gui_toggle_1->ids[gui_toggle_1->cur] != 0) {
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_toggle_1->unk4[gui_toggle_1->cur].data.img, gui_toggle_1->unk4[gui_toggle_1->cur].pal, spB0, spAC, gui_toggle_1->unk4[gui_toggle_1->cur].r, gui_toggle_1->unk4[gui_toggle_1->cur].g, gui_toggle_1->unk4[gui_toggle_1->cur].b, spA8);
        } else {
          displayText_XY_RGBA_2(&g_gdl, D_800D3D3C[temp_s0[var_s1].unk0.font], spB0, spAC, gui_toggle_1->unk4[gui_toggle_1->cur].data.str, gui_toggle_1->unk4[gui_toggle_1->cur].r, gui_toggle_1->unk4[gui_toggle_1->cur].g, gui_toggle_1->unk4[gui_toggle_1->cur].b, spA8);
        }
      }

      if ((temp_s0[var_s1].unk24 & GUI_PIC) && (var_s1 != 0)) {
        sp98 = temp_s0[var_s1].unk0.a * D_800D3E2C;
        spA0 = temp_s0[var_s1].unk0.x;
        sp9C = temp_s0[var_s1].unk0.y;
        if (temp_s0[var_s1].unk24 & GUI_CENTX) {
          spA0 = (screen_1_width >> 1) - (((u16) ((((u8 *) temp_s0[var_s1].unk0.data.img)[0] << 8) | ((u8 *) temp_s0[var_s1].unk0.data.img)[1])) >> 1);
        }
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, temp_s0[var_s1].unk0.data.img, temp_s0[var_s1].unk0.pal, spA0, sp9C, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, sp98);
      }

      if ((temp_s0[var_s1].unk24 & GUI_SLIDER) && (var_s1 != 0) && !(temp_s0[var_s1].unk24 & GUI_NULL)) {
        gui_slider_1 = temp_s0[var_s1].unk30;
        if (temp_s0[var_s1].unk24 & GUI_CENTX) {
          sp94 = (screen_1_width >> 1) - (((u16) ((((u8 *) gui_slider_1->track.data.img)[0] << 8) | ((u8 *) gui_slider_1->track.data.img)[1])) >> 1);
        } else {
          sp94 = gui_slider_1->track.x;
        }
        sp90 = gui_slider_1->track.y;
        sp8C = gui_slider_1->track.r;
        sp88 = gui_slider_1->track.g;
        sp84 = gui_slider_1->track.b;
        sp80 = gui_slider_1->track.a * D_800D3E2C;
        weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_slider_1->track.data.img, gui_slider_1->track.pal, sp94, sp90, sp8C, sp88, sp84, sp80);

        for (i = 0; i < gui_slider_1->num_ticks; i++) {
          sp94 = gui_slider_1->marks[i].x;
          sp90 = gui_slider_1->marks[i].y;
          if (gui_slider_1->cur == i) {
            sp8C = gui_slider_1->marks[i].r * D_800D3E24;
          } else {
            sp8C = gui_slider_1->marks[i].r;
          }
          sp88 = gui_slider_1->marks[i].g;
          sp84 = gui_slider_1->marks[i].b;
          if (i > gui_slider_1->cur) {
            sp80 = 0;
          } else {
            sp80 = 0xFF;
          }
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_slider_1->marks[i].data.img, gui_slider_1->marks[i].pal, sp94, sp90, sp8C, sp88, sp84, sp80);
        }
      }

      for (spB8 = 3; spB8 >= 0; spB8--) {
        if ((FUN_001050_getControllerErrNo(&superThread, spB8) == 0) && ((spB8 != 3) || (FUN_001050_getControllerErrNo(&superThread, 2) == 0)) && (D_800D3D00[spB8] == var_s1) && (arg0->unk114 != 0)) {
          if (temp_s0[var_s1].unk24 & GUI_TEXTBOX) {
            gui_textbox_1 = temp_s0[var_s1].unk30;
            switch (gui_textbox_1->unk5C) {
            case 0:
              temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.r = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.g = 0;
              temp_s0[var_s1].unk0.b = 0;
              break;
            case 1:
              temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.r = 0;
              temp_s0[var_s1].unk0.g = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.b = 0;
              break;
            case 2:
              temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.r = 0;
              temp_s0[var_s1].unk0.g = 0;
              temp_s0[var_s1].unk0.b = D_800D3E24 * 255;
              break;
            case 3:
              temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.r = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.g = D_800D3E24 * 255;
              temp_s0[var_s1].unk0.b = 0;
              break;
            default:
              temp_s0[D_800D3D10[spB8]].unk0.a = 0xA0;
              temp_s0[D_800D3D10[spB8]].unk0.g = 0xFF;
              temp_s0[D_800D3D10[spB8]].unk0.b = 0xFF;
              temp_s0[D_800D3D10[spB8]].unk0.r = 0xFF;
              temp_s0[var_s1].unk0.a = 0xFF;
              temp_s0[var_s1].unk0.r = 0xFF;
              temp_s0[var_s1].unk0.g = 0xFF;
              temp_s0[var_s1].unk0.b = 0xFF;
              break;
            }
            if (D_800D5D48 == temp_s0) {
              spB4 = 152;
            } else {
              spB4 = 132;
            }
            if (gui_textbox_1->unk5C != 0xFF) {
              gui_textbox_2 = temp_s0[var_s1].unk30;
              if (D_800D3D94 & (1 << gui_textbox_1->unk5C)) {
                weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8012901C, NULL, ((gui_textbox_1->unk5 % 15) * 18) + 59, (((gui_textbox_1->unk5 / 15) * 23) + spB4) - 6, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
              }
            }
            if (spB8 == 0) {
              temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
            }
          } else if ((spB8 == 0) && !(temp_s0[var_s1].unk24 & GUI_NULL)) {
            temp_s0[D_800D3D10[spB8]].unk0.a = 0xA0;
            temp_s0[D_800D3D10[spB8]].unk0.r = 0xFF;
            temp_s0[D_800D3D10[spB8]].unk0.g = 0xFF;
            temp_s0[D_800D3D10[spB8]].unk0.b = 0xFF;
            temp_s0[var_s1].unk0.a = D_800D3E24 * 255;
            temp_s0[var_s1].unk0.g = D_800D3E24 * 255;
            temp_s0[var_s1].unk0.b = D_800D3E24 * 255;
          }
        }
      }

      if ((temp_s0[var_s1].unk24 & GUI_TEXTBOX) && (arg0->unk114 != 0)) {
        gui_textbox_3 = temp_s0[var_s1].unk30;
        if (D_800D3D94 != 0) {
          for (sp68 = 63, spB8 = 0; spB8 < 15; spB8++, sp68 += 18) {
            displayText_XY_RGBA_3(&g_gdl, &D_80128F28, (sp68 - (get_char_width(&D_80128F28, D_800D3DA0[spB8]) / 2)) + 9, spB4, D_800D3DA0[spB8], 0xFF, 0xFF, 0xFF, 0xFF);
            displayText_XY_RGBA_3(&g_gdl, &D_80128F28, (sp68 - (get_char_width(&D_80128F28, D_800D3DA0[spB8 + 15]) / 2)) + 9, spB4 + 23, D_800D3DA0[spB8 + 15], 0xFF, 0xFF, 0xFF, 0xFF);
            displayText_XY_RGBA_3(&g_gdl, &D_80128F28, (sp68 - (get_char_width(&D_80128F28, D_800D3DA0[spB8 + 30]) / 2)) + 9, spB4 + 46, D_800D3DA0[spB8 + 30], 0xFF, 0xFF, 0xFF, 0xFF);
          }
        }

        if (D_800D5D48 == temp_s0) {
          for (spB8 = 3; spB8 >= 0; spB8--) {
            if ((FUN_001050_getControllerErrNo(&superThread, spB8) == 0) && ((spB8 != 3) || (FUN_001050_getControllerErrNo(&superThread, 2) == 0)) && (spB8 + 3 == var_s1)) {
              if (gui_textbox_3->unk5C == 0xFF) {
                if (D_800D3D00[0] == var_s1) {
                  displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, 0xFF, 255 * D_800D3E24, 255 * D_800D3E24, temp_s0[var_s1].unk0.a * D_800D3E2C);
                } else {
                  displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, 0xFF, 0xFF, 0xFF, temp_s0[var_s1].unk0.a * D_800D3E2C);
                }
              } else {
                weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_textbox_3->unk14.data.img, NULL, gui_textbox_3->unkC, gui_textbox_3->unk10, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
                displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, 0xFF, 255 * D_800D3E24, 255 * D_800D3E24, temp_s0[var_s1].unk0.a * D_800D3E2C * D_800D3E24);
              }
            }
          }
        } else if (gui_textbox_3->unk5C == 0xFF) {
          if (D_800D3D00[0] == var_s1) {
            displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g * D_800D3E24, temp_s0[var_s1].unk0.b * D_800D3E24, temp_s0[var_s1].unk0.a * D_800D3E2C);
          } else {
            displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
          }
          if ((gui_textbox_3->unk60 == 0xFF) || (gui_textbox_3->unk60 == 0xFE) || (gui_textbox_3->unk60 == 0xFB) || (gui_textbox_3->unk60 == 0xFA) || (gui_textbox_3->unk60 == 0xF9) || (gui_textbox_3->unk60 == 0xF8) || (gui_textbox_3->unk60 == 0xFC)) {
            weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_textbox_3->unk14.data.img, NULL, gui_textbox_3->unkC, gui_textbox_3->unk10, 0xFF, 0xFF, 0xFF, temp_s0[var_s1].unk0.a * D_800D3E2C);
          }
        } else {
          weird_lots_of_magic_number_setting_66xrefs(&g_gdl, gui_textbox_3->unk14.data.img, NULL, gui_textbox_3->unkC, gui_textbox_3->unk10, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
          if (gui_textbox_3->unk5D != 1) {
            displayText_XY_RGBA_2(&g_gdl, &D_80128F28, gui_textbox_3->unkC + 5, gui_textbox_3->unk10 + 8, gui_textbox_3->node->name, 0xFF, 255 * D_800D3E24, 255 * D_800D3E24, temp_s0[var_s1].unk0.a * D_800D3E2C * D_800D3E24);
          }
        }
      }

      if (D_800D5D48 == D_801290D0.unk124) {
        if (D_800D3D34 == 1) {
          if (D_800D3D00[0] == 9) {
            temp_s0[9].unk0.r = D_800D3E24 * 150;
            temp_s0[9].unk0.g = (1.0 - D_800D3E24) * 255;
            temp_s0[9].unk0.b = (1.0 - D_800D3E24) * 255;
            temp_s0[9].unk0.a = D_800D3E24 * 255;
          } else {
            temp_s0[9].unk0.r = 0xFF;
            temp_s0[9].unk0.g = 0xFF;
            temp_s0[9].unk0.b = 0xFF;
            temp_s0[9].unk0.a = 0xA0;
          }
          temp_s0[9].unk24 &= ~GUI_NULL;
        } else {
          temp_s0[9].unk0.r = 0;
          temp_s0[9].unk0.g = 0;
          temp_s0[9].unk0.b = 0;
          temp_s0[9].unk0.a = 0;
          temp_s0[9].unk24 |= GUI_NULL;
        }
      }

      if (D_800D5850 == D_801290D0.unk124) {
        if (D_800D3D34 == 1) {
          if (D_800D3D00[0] == 6) {
            temp_s0[6].unk0.r = D_800D3E24 * 150;
            temp_s0[6].unk0.g = (1.0 - D_800D3E24) * 255;
            temp_s0[6].unk0.b = (1.0 - D_800D3E24) * 255;
            temp_s0[6].unk0.a = D_800D3E24 * 255;
          } else {
            temp_s0[6].unk0.r = 0xFF;
            temp_s0[6].unk0.g = 0xFF;
            temp_s0[6].unk0.b = 0xFF;
            temp_s0[6].unk0.a = 0xA0;
          }
          temp_s0[6].unk24 &= ~GUI_NULL;
        } else {
          temp_s0[6].unk0.r = 0;
          temp_s0[6].unk0.g = 0;
          temp_s0[6].unk0.b = 0;
          temp_s0[6].unk0.a = 0;
          temp_s0[6].unk24 |= GUI_NULL;
        }
      }

      if ((temp_s0[var_s1].unk24 & GUI_TEXTBOX) && (arg0->unk114 != 0)) {
        gui_textbox_4 = temp_s0[var_s1].unk30;
        if ((gui_textbox_4->unk5D != 1) && (gui_textbox_4->node->ptr != NULL) && (gui_textbox_4->unk60 != 0xFA)) {
          if (D_800D5D48 == D_801290D0.unk124) {
            if ((gui_textbox_4->node->pack & 0xF) == 0xC) {
              weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129020, NULL, gui_textbox_4->unkC + 128, gui_textbox_4->unk10 + 3, 0xFF, 0xFF, 0xFF, 255 * D_800D3E2C);
            } else {
              weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129024, NULL, gui_textbox_4->unkC + 128, gui_textbox_4->unk10 + 3, 0xFF, 0xFF, 0xFF, 255 * D_800D3E2C);
            }
            if ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) >= 10) {
              sp5C = displayText_XY_RGBA_3(&g_gdl, &D_80128F28, gui_textbox_4->unkC + 133, gui_textbox_4->unk10 + 8, ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) / 10) + 0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
              displayText_XY_RGBA_3(&g_gdl, &D_80128F28, sp5C, gui_textbox_4->unk10 + 8, ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) % 10) + 0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
            } else {
              displayText_XY_RGBA_3(&g_gdl, &D_80128F28, gui_textbox_4->unkC + 137, gui_textbox_4->unk10 + 8, (FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) + 0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
            }
          } else {
            if ((gui_textbox_4->node->pack & 0xF) == 0xC) {
              weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129020, NULL, gui_textbox_4->unkC + 128, gui_textbox_4->unk10 + 3, 0xFF, 0xFF, 0xFF, 255 * D_800D3E2C);
            } else {
              weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_80129024, NULL, gui_textbox_4->unkC + 128, gui_textbox_4->unk10 + 3, 0xFF, 0xFF, 0xFF, 255 * D_800D3E2C);
            }
            func_8005BBFC(&g_gdl);
            if ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) >= 10) {
              sp5C = displayText_XY_RGBA_3(&g_gdl, &D_80128F28, gui_textbox_4->unkC + 133, gui_textbox_4->unk10 + 8, ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) / 10) + 0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
              displayText_XY_RGBA_3(&g_gdl, &D_80128F28, sp5C, gui_textbox_4->unk10 + 8, ((FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) % 10) + 0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
            } else {
              displayText_XY_RGBA_3(&g_gdl, &D_80128F28, gui_textbox_4->unkC + 137, gui_textbox_4->unk10 + 8, (FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(gui_textbox_4->node->ptr) + 1) +  0x30, 0xFF, 0xFF, 0, 255 * D_800D3E2C);
            }
          }
        }
      }

      if (temp_s0[var_s1].unk24 & GUI_TITLE) {
        if (temp_s0[var_s1].unk24 & GUI_CENTX) {
          displayText_XY_RGBA_2(&g_gdl, D_800D3D3C[temp_s0[var_s1].unk0.font], (screen_1_width >> 1) - (get_text_width(&D_80128EB0, temp_s0[var_s1].unk0.data.str) >> 1), temp_s0[var_s1].unk0.y, temp_s0[var_s1].unk0.data.str, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
        } else {
          displayText_XY_RGBA_2(&g_gdl, D_800D3D3C[temp_s0[var_s1].unk0.font], temp_s0[var_s1].unk0.x, temp_s0[var_s1].unk0.y, temp_s0[var_s1].unk0.data.str, temp_s0[var_s1].unk0.r, temp_s0[var_s1].unk0.g, temp_s0[var_s1].unk0.b, temp_s0[var_s1].unk0.a * D_800D3E2C);
        }
      }
    }
  }

  if ((D_800CFEE4 == 0) && (D_800CFEE8 != 10) && (D_800CFEE8 != 16)) {
    sp58 = &g_PV_arr[0].unk28;

    if (temp_s0[D_800D3D00[0]].unk24 & GUI_WINDOW) {
      ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, D_800D3E2C);
    }

    if (g_PV_arr[0].unk24 & 0x1000) {  // START_BUTTON / CONT_START
      if ((D_800D5850 == D_801290D0.unk124) && (D_800D3D34 == 1)) {
        temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
        temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
        temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
        temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
        ((void (*)(void *, f32)) temp_s0[6].unk28)(temp_s0[6].unk30, 0);
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
        func_8005BE40(&g_gdl);
        D_800D57A4.unk61 = FALSE;
        return;
      }

      if ((D_800D5D48 == D_801290D0.unk124) && (D_800D3D34 == 1)) {
        temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
        temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
        temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
        temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
        ((void (*)(void *, f32)) temp_s0[9].unk28)(temp_s0[9].unk30, 0);
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
        func_8005BE40(&g_gdl);
        D_800D5AC4.unk61 = FALSE;
        D_800D5B28.unk61 = FALSE;
        D_800D5B8C.unk61 = FALSE;
        D_800D5BF0.unk61 = FALSE;
        return;
      }
    }

    if ((D_800D3E34 == 0) && !((temp_s0[D_800D3D00[0]].unk24 & GUI_TEXTBOX) || (arg0->unk114 == 0))) {
      if ((temp_s0[D_800D3D00[0]].unk24 & GUI_SLIDER) && (arg0->unk114 != 0)) {
        gui_slider_2 = temp_s0[D_800D3D00[0]].unk30;
        if (sp58->unk84 & 0x200) {  // L_JPAD / CONT_LEFT
          if (gui_slider_2->cur != 0) {
            gui_slider_2->cur--;
            if (temp_s0[D_800D3D00[0]].unk28 == NULL) {
              debug_print_reason_routine("gui func call in menu", "bad mojo");
            }
            ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, 0);
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
          } else {
            return;
          }
        }
        if (sp58->unk84 & 0x100) {  // R_JPAD / CONT_RIGHT
          if (gui_slider_2->cur < gui_slider_2->num_ticks - 1) {
            gui_slider_2->cur++;
            if (temp_s0[D_800D3D00[0]].unk28 == NULL) {
              debug_print_reason_routine("gui func call in menu", "bad mojo");
            }
            ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, 0);
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
          } else {
            return;
          }
        }
      }

      if ((temp_s0[D_800D3D00[0]].unk24 & GUI_TOGGLE) && (arg0->unk114 != 0) && ((g_PV_arr[0].unk24 & 0x200) || (g_PV_arr[0].unk24 & 0x100))) {
        gui_toggle_2 = temp_s0[D_800D3D00[0]].unk30;
        if (g_PV_arr[0].unk24 & 0x200) {  // L_JPAD / CONT_LEFT
          if (gui_toggle_2->cur == 0) {
            gui_toggle_2->cur = gui_toggle_2->num;
          }
          gui_toggle_2->cur--;
        }
        if (g_PV_arr[0].unk24 & 0x100) {  // R_JPAD / CONT_RIGHT
          gui_toggle_2->cur++;
          if (gui_toggle_2->cur >= gui_toggle_2->num) {
            gui_toggle_2->cur = 0;
          }
        }
        if (temp_s0[D_800D3D00[0]].unk28 != NULL) {
          ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, D_800D3E2C);
        }
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
      }

      if ((temp_s0[D_800D3D00[0]].unk24 & GUI_FUNC) && (arg0->unk114 != 0) && ((g_PV_arr[0].unk24 & 0x8000) || (g_PV_arr[0].unk24 & 0x1000))) {
        if (D_800D3FF8 == D_801290D0.unk124) {
          if (g_PV_arr[0].unk24 & 0x1000) {  // START_BUTTON / CONT_START
            func_8005BE40(&g_gdl);
            return;
          }

          if (temp_s0[D_800D3D00[0]].unk28 == NULL) {
            debug_print_reason_routine("gui func call in menu", "bad mojo");
          }
          ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, 0);
          Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
          func_8005BE40(&g_gdl);
          return;
        }

        if (temp_s0[D_800D3D00[0]].unk28 == NULL) {
          debug_print_reason_routine("gui func call in menu", "bad mojo");
        }
        ((void (*)(void *, f32)) temp_s0[D_800D3D00[0]].unk28)(temp_s0[D_800D3D00[0]].unk30, 0);
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 2);
        func_8005BE40(&g_gdl);
        return;
      }

      if ((temp_s0[D_800D3D00[0]].unk24 & GUI_MENU) && (arg0->unk114 != 0) && (g_PV_arr[0].unk24 & 0x8000) && (D_800D3CF8 == NULL)) {
        D_800D3E34 = 2;
        func_8007E9F8(9);
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
      }

      if ((D_800D3E34 == 0) && (g_PV_arr[0].unk24 & 0x8000)) {
        D_800D3E2C = 0;
        func_8009DDF4(arg0);
        if (D_800D3D20 != 0) {
          D_800D3D20 = 0;
        }
        D_800D3D90 = 1;
      }

      if ((g_PV_arr[0].unk24 & 0x4000) && (D_800D3CF8 == NULL) && (temp_s0->unk2C != NULL)) {
        if ((D_800D5D48 == temp_s0) && D_800D5AC4.unk61) {
          D_800D5AC4.unk61 = FALSE;
          D_800D5AC4.unk5C = 0;
          D_800D5AC4.unk5D = 0;
          temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
          temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
          D_800D3D10[0] = D_800D3D00[0];
          D_800D3D00[0] = 3;
          return;
        }

        if ((D_800D5850 == temp_s0) && D_800D57A4.unk61) {
          D_800D57A4.unk61 = FALSE;
          D_800D57A4.unk5C = 0;
          D_800D57A4.unk5D = 0;
          temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
          temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
          temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
          D_800D3D10[0] = D_800D3D00[0];
          D_800D3D00[0] = 3;
          return;
        }

        func_8007E9F8(9);
        D_800D3E34 = 1;
        Audio2_Play_SFX(&D_801235B0, &D_800D3988, 5);
        return;
      }

      if (sp58->unk84 & 0x800) {  // U_JPAD / CONT_UP
        if (D_800D5D48 == temp_s0) {
          if (D_800D3D94 != 0) {
            Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
            return;
          }

          if (D_800D3D00[0] == 7) {
            temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
            temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
            temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
            temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
            D_800D3D00[0] = 3;
            return;
          }

          D_800D3D00[0] = func_80091440(arg0, D_800D3D00[0], &D_800D3D10[0]);
          D_800D3D2C = 0;
          return;
        }

        D_800D3D00[0] = func_80091440(arg0, D_800D3D00[0], &D_800D3D10[0]);
        D_800D3D2C = 0;
        return;
      }

      if (sp58->unk84 & 0x400) {  // D_JPAD / CONT_DOWN
        if (D_800D3D94 != 0) {
          Audio2_Play_SFX(&D_801235B0, &D_800D3988, 3);
          return;
        }

        if (D_800D5D48 == temp_s0) {
          if (D_800D3D00[0] == 3) {
            temp_s0[D_800D3D00[0]].unk0.a = 0xA0;
            temp_s0[D_800D3D00[0]].unk0.r = 0xFF;
            temp_s0[D_800D3D00[0]].unk0.g = 0xFF;
            temp_s0[D_800D3D00[0]].unk0.b = 0xFF;
            D_800D3D00[0] = 7;
            return;
          }

          D_800D3D00[0] = func_80091744(arg0, D_800D3D00[0], D_800D3D10);
          D_800D3D2C = 0;
          return;
        }

        D_800D3D00[0] = func_80091744(arg0, D_800D3D00[0], D_800D3D10);
        D_800D3D2C = 0;
        return;
      }
    }

    for (var_s2 = 0; var_s2 < 4; var_s2++) {
      if (((var_s2 != 3) || (FUN_001050_getControllerErrNo(&superThread, 2) == 0)) && (temp_s0[D_800D3D00[var_s2]].unk24 & GUI_TEXTBOX) && (arg0->unk114 != 0)) {
        if (((GUI_Textbox *) temp_s0[D_800D3D00[var_s2]].unk30)->unk60 != 0xFD) {
          if (var_s2 == 0) {
            func_80091D60(temp_s0[D_800D3D00[var_s2]].unk30, arg0, var_s2, D_800D3E24);
          }
        } else {
          func_80091D60(temp_s0[D_800D3D00[var_s2]].unk30, arg0, var_s2, D_800D3E24);
        }
      }
    }
  }

  func_8005BE40(&g_gdl);
}

void func_8009D400(u16 arg0) {
  if (arg0 & GUI_TITLE) {
    rmonPrintf("GUI_TITLE ");
  }
  if (arg0 & GUI_PIC) {
    rmonPrintf("GUI_PIC ");
  }
  if (arg0 & GUI_FUNC) {
    rmonPrintf("GUI_FUNC ");
  }
  if (arg0 & GUI_NULL) {
    rmonPrintf("GUI_NULL ");
  }
  if (arg0 & GUI_MENU) {
    rmonPrintf("GUI_MENU ");
  }
  if (arg0 & GUI_DIS) {
    rmonPrintf("GUI_DIS ");
  }
  if (arg0 & GUI_CENTX) {
    rmonPrintf("GUI_CENTX ");
  }
  if (arg0 & GUI_CENTY) {
    rmonPrintf("GUI_CENTY ");
  }
  if (arg0 & GUI_NUM) {
    rmonPrintf("GUI_NUM ");
  }
  if (arg0 & GUI_TEXTBOX) {
    rmonPrintf("GUI_TEXTBOX ");
  }
  if (arg0 & GUI_TOGGLE) {
    rmonPrintf("GUI_TOGGLE ");
  }
  if (arg0 & GUI_WINDOW) {
    rmonPrintf("GUI_WINDOW ");
  }
  if (arg0 & GUI_SLIDER) {
    rmonPrintf("GUI_SLIDER ");
  }
  if (arg0 & GUI_QUIT) {
    rmonPrintf("GUI_QUIT ");
  }
  rmonPrintf("\n");
}

void func_8009D5E4(void) {
  UnkStruct_77 *sp3C;

  sp3C = D_801290D0.unk124;
  if (D_800D3D88) {
    main_8004A34C_threeliner();
    func_8008FF78(&D_801290D0);
    func_8009098C(&D_801290D0);
    rmonPrintf("Loading: %d\n", g_sram_ptr->song);
    Audio_80084e20_twentyliner(g_sram_ptr->song, &D_80120A70, 1);
    main_8004A34C_threeliner();
    func_8008F360(&D_801290D0, D_800D4E1C, D_800D4DD4);
    Font_Init46Char(&D_80128EB0, IMG_FONT_A);
    Font_Init46Char(&D_80128F28, IMG_FONT_B);
    Font_Init46Char(&D_80128FA0, IMG_FONT_C);
    main_8004A34C_threeliner();
    Audio2_GFXDone_SendPlayMessage(&D_80120A70);
    D_800D3D88 = FALSE;
  }

  if (D_801290D0.unk114 == 0) {
    func_800A0228(&D_801290D0);
  }

  if (D_801290D0.unk114 == 1) {
    n64HeapUnalloc(D_801290D0.img);
    func_8009F338(&D_801290D0);
    D_801290D0.unk114 = 2;
  }

  func_80090AC0(D_8012902C[D_800D3CF4]);

  func_8005BBFC(&g_gdl);

  if (D_801290D0.unk114 == 0) {
    gDPPipeSync(g_gdl++);

    gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_PHYSICAL_TO_K0(D_8012902C[D_800D3CF4]->img));

    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, sp3C->unk0.data.img, sp3C->unk0.pal, sp3C->unk0.x, sp3C->unk0.y, sp3C->unk0.r, sp3C->unk0.g, sp3C->unk0.b, sp3C->unk0.a);

    gDPSetColorImage(g_gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, screen_1_width, OS_PHYSICAL_TO_K0(cfb[draw_buffer]));
  } else {
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, sp3C->unk0.data.img, sp3C->unk0.pal, sp3C->unk0.x, sp3C->unk0.y, sp3C->unk0.r, sp3C->unk0.g, sp3C->unk0.b, sp3C->unk0.a);
  }
  func_8005BE40(&g_gdl);
  func_80099674(&D_801290D0);
}
