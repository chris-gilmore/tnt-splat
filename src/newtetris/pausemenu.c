#include "common.h"

UnkStruct_10 *D_800D05C0 = NULL;

static void   func_80071730(UnkStruct_35 *, Font *, char *, s32, s32);
static void   func_8007183C(UnkStruct_35 *);
static void   func_80071A40(UnkStruct_35 *);
static void   func_80071B08(UnkStruct_35 *);
static void   func_80071B2C(UnkStruct_35 *);
static void   func_80071B44(UnkStruct_10 *);
static void   func_80071B88(UnkStruct_10 *);
static void   func_80071BBC(UnkStruct_10 *);
static void   displayPausePopupMenu(UnkStruct_10 *);
static void   func_80071DEC(UnkStruct_10 *);
static void   func_80071E58(UnkStruct_10 *);
static void   func_800720C0(UnkStruct_10 *);

static void func_80071730(UnkStruct_35 *arg0, Font *p_font, char *str, s32 cx, s32 cy) {
  arg0->str = str;
  arg0->x = cx - (get_text_width(p_font, str) >> 1);
  arg0->y = cy - p_font->height;
  arg0->red = arg0->green = arg0->blue = arg0->alpha = 0xFF;
  arg0->p_font = p_font;
  arg0->unk20 = NULL;
  arg0->unk24 = NULL;
  arg0->unk28 = NULL;
  arg0->unk2C = NULL;
  arg0->unk30 = NULL;
  arg0->unk14 = FALSE;
}

static void func_8007183C(UnkStruct_35 *arg0) {
  if (arg0->unk14) {
    arg0->unkC += arg0->unk10 * D_801109F4;
    if (arg0->unkC >= 1.0f) {
      arg0->unkC = 1.0f;
      arg0->unk10 *= -1;
    }
    if (arg0->unkC <= 0.5f) {
      arg0->unkC = 0.5f;
      arg0->unk10 *= -1;
    }
    arg0->red = arg0->unkC * 0xFF;
    arg0->alpha = arg0->unkC * 0xFF;
  }
}

static void func_80071A40(UnkStruct_35 *arg0) {
  gDPPipeSync(g_gdl++);

  displayText_XY_RGBA_2(&g_gdl, arg0->p_font, arg0->x, arg0->y, arg0->str, arg0->red, arg0->green, arg0->blue, arg0->alpha);

  gDPPipeSync(g_gdl++);
}

static void func_80071B08(UnkStruct_35 *arg0) {
  arg0->unkC = 1.0;
  arg0->unk10 = -0.03;
  arg0->unk14 = TRUE;
}

static void func_80071B2C(UnkStruct_35 *arg0) {
  arg0->red = 0xFF;
  arg0->alpha = 0xFF;
  arg0->unk14 = FALSE;
}

static void func_80071B44(UnkStruct_10 *arg0) {
  Audio_UnloadSFX();
  func_80071DEC(arg0);
  Audio_LoadSFX(&D_800D3A90);
  arg0->unk1 = PAUSEMENU_CONTINUE;
}

static void func_80071B88(UnkStruct_10 *arg0) {
  func_80071DEC(arg0);
  arg0->unk1 = PAUSEMENU_PROGRESS;
}

static void func_80071BBC(UnkStruct_10 *arg0) {
  func_80071DEC(arg0);
  arg0->unk1 = PAUSEMENU_EXIT;
}

static void displayPausePopupMenu(UnkStruct_10 *arg0) {
  Audio_LoadSFX(&D_800D3988);
  Font_Init46Char(&arg0->font, IMG_FONT_A);
  arg0->unk7C = 3;
  arg0->unk80 = (UnkStruct_35 *) n64HeapAlloc(arg0->unk7C * sizeof(UnkStruct_35));
  func_80071730(&arg0->unk80[0], &arg0->font, "CONTINUE", 200, 130);
  func_80071730(&arg0->unk80[1], &arg0->font, "PROGRESS", 200, 150);
  func_80071730(&arg0->unk80[2], &arg0->font, "EXIT", 200, 170);
  arg0->unk80[0].unk28 = &arg0->unk80[1];
  arg0->unk80[1].unk28 = &arg0->unk80[2];
  arg0->unk80[2].unk28 = &arg0->unk80[0];
  arg0->unk80[0].unk24 = &arg0->unk80[2];
  arg0->unk80[1].unk24 = &arg0->unk80[0];
  arg0->unk80[2].unk24 = &arg0->unk80[1];
  arg0->unk80[0].unk20 = func_80071B44;
  arg0->unk80[1].unk20 = func_80071B88;
  arg0->unk80[2].unk20 = func_80071BBC;
  arg0->unk84 = &arg0->unk80[0];
  func_80071B08(arg0->unk84);
  FUN_800535B8_fiveliner(g_PV_arr);
  arg0->unk88 = 0;
  arg0->unk0 = 0;
}

static void func_80071DEC(UnkStruct_10 *arg0) {
  main_8004A34C_threeliner();
  n64HeapUnalloc(arg0->unk80);
  Font_Deinit(&arg0->font);
  FUN_800535B8_fiveliner(g_PV_arr);
  arg0->unk88 = 0;
  arg0->unk0 = 0;
  main_8004A34C_threeliner();
  main_8004A34C_threeliner();
}

static void func_80071E58(UnkStruct_10 *arg0) {
  register u32 temp_s0;

  temp_s0 = g_PV_arr[arg0->unk89].unk24;
  if (temp_s0 & 0x800) {  // CONT_UP
    if (arg0->unk84->unk24 != NULL) {
      func_80071B2C(arg0->unk84);
      arg0->unk84 = arg0->unk84->unk24;
      func_80071B08(arg0->unk84);
      Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
    }
  }
  if (temp_s0 & 0x400) {  // CONT_DOWN
    if (arg0->unk84->unk28 != NULL) {
      func_80071B2C(arg0->unk84);
      arg0->unk84 = arg0->unk84->unk28;
      func_80071B08(arg0->unk84);
      Audio2_Play_SFX(&D_801235B0, &D_800D3988, 1);
    }
  }
  if (temp_s0 & 0x100) {  // CONT_RIGHT
    if (arg0->unk84->unk30 != NULL) {
      func_80071B2C(arg0->unk84);
      arg0->unk84 = arg0->unk84->unk30;
      func_80071B08(arg0->unk84);
    }
  }
  if (temp_s0 & 0x200) {  // CONT_LEFT
    if (arg0->unk84->unk2C != NULL) {
      func_80071B2C(arg0->unk84);
      arg0->unk84 = arg0->unk84->unk2C;
      func_80071B08(arg0->unk84);
    }
  }
  // CONT_A
  if ((temp_s0 & 0x8000) && (arg0->unk84->unk20 != NULL)) {
    Audio2_Play_SFX(&D_801235B0, &D_800D3988, 4);
    arg0->unk84->unk20(arg0);
  }
}

static void func_800720C0(UnkStruct_10 *arg0) {
  register UnkStruct_35 *var_s0;
  register s32 i;

  arg0->unk88 = TRUE;
  var_s0 = arg0->unk80;
  for (i = 0; i < arg0->unk7C; i++) {
    func_8007183C(var_s0);
    var_s0++;
  }
  func_80071E58(arg0);
}

u8 func_80072140(u8 playernum) {
  register UnkStruct_10 *temp_s0;

  temp_s0 = D_800D05C0 = (UnkStruct_10 *) n64HeapAlloc(sizeof(UnkStruct_10));
  if (temp_s0 == NULL) {
    return FALSE;
  }

  temp_s0->unk88 = FALSE;
  temp_s0->unk89 = playernum;
  temp_s0->unk0 = 1;
  return TRUE;
}

void func_800721A4(void) {
  main_8004A34C_threeliner();
  n64HeapUnalloc(D_800D05C0);
  D_800D05C0 = NULL;
}

s32 func_800721D8(void) {
  register UnkStruct_10 *temp_s0 = D_800D05C0;
  register u8 temp_s1;

  if (temp_s0 == NULL) {
    return -1;
  }

  temp_s1 = temp_s0->unk0;
  temp_s0->unk1 = 0;
  if (temp_s1 != 0) {
    if (temp_s1 == 1) {
      displayPausePopupMenu(temp_s0);
    }
  } else {
    func_800720C0(temp_s0);
  }

  return temp_s0->unk1;
}

void func_80072248(void) {
  register UnkStruct_10 *temp_s0 = D_800D05C0;
  register UnkStruct_35 *var_s1;
  register s32 i;

  if ((temp_s0 != NULL) && temp_s0->unk88) {
    var_s1 = temp_s0->unk80;
    func_8005BBFC(&g_gdl);
    for (i = 0; i < temp_s0->unk7C; i++) {
      func_80071A40(var_s1);
      var_s1++;
    }
    func_8005BE40(&g_gdl);
  }
}
