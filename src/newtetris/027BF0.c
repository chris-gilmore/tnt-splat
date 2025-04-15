#include "common.h"

static u8 D_800D02B0 = 10;
static u8 D_800D02B4 = 0;

/*
   201 - mayan skybox
   488 - celtic skybox
   568 - african skybox
   770 - japanese skybox
   902 - russian skybox
  1319 - greek rain
  1336 - celtic flying leaves
  1361 - japanese flying butterflies
  1371 - russian snow
  1399 - greek skybox
*/

// mayan skybox
static UnkStruct_11 D_800D02B8 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x10, 0, 201, 0
};

// japanese skybox
static UnkStruct_11 D_800D02E8 = {
  NULL, NULL, 0.2, -0.2, -0.7, 0.0, 0.0, 0.0, 0x1B, 0, 770, 0
};

// celtic skybox
static UnkStruct_11 D_800D0318 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 488
};

// russian skybox
static UnkStruct_11 D_800D0348 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 902
};

// african skybox
static UnkStruct_11 D_800D0378 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 568
};

// greek skybox
static UnkStruct_11 D_800D03A8 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 1399, 0
};

// japanese flying butterflies
static UnkStruct_11 D_800D03D8 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 1361
};

// celtic flying leaves
static UnkStruct_11 D_800D0408 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 1336
};

// russian snow
static UnkStruct_11 D_800D0438 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 1371
};

// greek rain
static UnkStruct_11 D_800D0468 = {
  NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0x00, 0, 0, 1319
};

static s16 D_800D0498[2] = { 0x400, 0x400 };
static s16 D_800D049C[2] = { 0x400, 0x400 };
static s16 D_800D04A0[2] = { 0, 0 };
static s16 D_800D04A4[2] = { 0, 0 };
static s32 D_800D04A8 = 10;
static s32 D_800D04AC = 0;
static f32 D_800D04B0 = 0.01;
static f32 D_800D04B4 = 0.05;  // skybox velocity
static s32 D_800D04B8 = 1;

static Img_u D_8011FAE0;
static s32   D_8011FAE4;
static s32   D_8011FAE8;
static s32   D_8011FAEC;
static s32   D_8011FAF0;
static s32   D_8011FAF4;
static s32   D_8011FAF8;
static Pal_u D_8011FAFC;

static Img_u D_8011FB00;
static s32   D_8011FB04;
static s32   D_8011FB08;
static s32   D_8011FB0C;
static s32   D_8011FB10;
static s32   D_8011FB14;
static s32   D_8011FB18;
static Pal_u D_8011FB1C;

static Img_u D_8011FB20;
static s32   D_8011FB24;
static s32   D_8011FB28;
static s32   D_8011FB2C;
static s32   D_8011FB30;
static s32   D_8011FB34;
static s32   D_8011FB38;
static Pal_u D_8011FB3C;

static UnkStruct_30 D_8011FB40;
static s8 saved_screen;
static s16 D_8011FB60[2];
static s16 D_8011FB64[2];

static void   FUN_027BF0_80061a3c_tenliner_allocs_heap(ImageParams *, ImageParams *);
static void   FUN_027BF0_8006307c_sixliner(ImageParams *);

// right-justify a number?
void FUN_027BF0_convert_decimal_q(u32 arg0, s32 arg1) {
  if (arg0 < 10) {
    func_800AC308(262, arg1);
  } else if (arg0 < 100) {
    func_800AC308(254, arg1);
  } else if (arg0 < 1000) {
    func_800AC308(246, arg1);
  } else if (arg0 < 10000) {
    func_800AC308(238, arg1);
  } else {
    func_800AC308(230, arg1);
  }
}

void FUN_027BF0_80061A34_does_nothing(void) {
}

// load image and palette
static void FUN_027BF0_80061a3c_tenliner_allocs_heap(ImageParams *dest, ImageParams *src) {
  if (src->img.id != 0) {
    // load image
    dest->img.data = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, src->img.id));
    FUN_03A750_800746c0_twentyliner(&D_273A00, dest->img.data, src->img.id);
    if (((u8 *) dest->img.data)[5] == 3) {  // COLOR_INDEX image type
      // load palette
      dest->pal.data = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, src->pal.id));
      FUN_03A750_800746c0_twentyliner(&D_273A00, dest->pal.data, src->pal.id);
    }
  }
}

void FUN_027BF0_check_music_settings_and_play(s32 screen) {
  s32 sp1C;
  s32 sp18;

  if (D_800CFEE8 == 12) {
    sp1C = 0xFF;
  } else {
    sp1C = 0;
    if (g_sram_ptr->music_mode == 1) {  // music_mode == choose
      sp1C = 0xFF;
    } else if (g_sram_ptr->music_mode == 0) {  // music_mode == auto
      sp18 = func_800A35EC(0, 50);
      if (sp18 < 30) {
        sp1C = 0xFE;
      } else {
        sp1C = func_800A35EC(1, screen + 9);
      }
    } else {  // music_mode == random (2)
      sp1C = func_800A35EC(1, screen + 9);
    }
  }

  if (D_800CFED4 == 1) {
    switch (screen) {
    case 0:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(9, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 1:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(10, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 2:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(11, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 3:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(12, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 4:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(13, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 5:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(14, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 6:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 7:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    }
  }

  if (D_800CFED4 == 2) {
    switch (screen) {
    case 0:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(9, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 1:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(10, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 2:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(11, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 3:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(12, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 4:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(13, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 5:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(14, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 6:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 7:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    }
  }

  if (D_800CFED4 >= 3) {
    switch (screen) {
    case 0:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(9, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 1:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(10, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 2:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(11, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 3:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(12, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 4:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(13, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 5:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(14, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 6:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    case 7:
      if (sp1C == 0xFE) {
        Audio_80084e20_twentyliner(15, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      } else if (sp1C < 16) {
        Audio_80084e20_twentyliner(sp1C, &D_80120A70, 1);
        Audio2_GFXDone_SendPlayMessage(&D_80120A70);
      }
      break;
    }
  }
}

void FUN_027BF0_Init(s32 screen) {
  UnkStruct_31 sp20;
  s32 unused;

  main_8004A34C_threeliner();
  if (D_800CFED4 == 1) {
    ((ImageParams *) &D_8011FAE0)[0] = D_800D0930[3 * screen + 0];
    ((ImageParams *) &D_8011FAE0)[1] = D_800D0930[3 * screen + 1];
    ((ImageParams *) &D_8011FAE0)[2] = D_800D0930[3 * screen + 2];

    main_8004A34C_threeliner();
    switch (screen) {
    case 0:
      func_800764B8(&D_800D1030);
      func_800764A0(&D_800D10CC, &D_800D1030);
      func_800764A0(&D_800D1168, &D_800D1030);
      func_800764A0(&D_800D1204, &D_800D1030);
      func_800764A0(&D_800D12A0, &D_800D1030);
      func_800764A0(&D_800D133C, &D_800D1030);
      func_800764A0(&D_800D13D8, &D_800D1030);
      func_800764A0(&D_800D1474, &D_800D1030);
      func_80076EC0(&D_800D02B8, 1);
      bzero(&sp20, sizeof(UnkStruct_31));
      sp20.unk0.unk0 = 0x11, sp20.unk0.unk1 = 0x40;
      sp20.unk2 = 0x4A, sp20.unk4 = 0xD0;
      sp20.unk6 = 0x80;
      func_8007523C(&D_8011FB40, &sp20);
      break;
    case 1:
      func_800764B8(&D_800D2890);
      func_80076EC0(&D_800D03A8, 1);
      func_80076EC0(&D_800D0468, 1);
      break;
    case 2:
      func_800764B8(&D_800D292C);
      func_800764B8(&D_800D29C8);
      func_800764B8(&D_800D2A64);
      break;
    case 3:
      func_800764B8(&D_800D2008);
      func_80076EC0(&D_800D0318, 1);
      func_80076EC0(&D_800D0408, 1);
      break;
    case 4:
      func_800764B8(&D_800D2C38);
      func_80076EC0(&D_800D0378, 1);
      break;
    case 5:
      func_800764B8(&D_800D1510);
      func_800764A0(&D_800D15AC, &D_800D1510);
      func_800764A0(&D_800D1648, &D_800D1510);
      func_800764A0(&D_800D16E4, &D_800D1510);
      func_800764A0(&D_800D1780, &D_800D1510);
      func_800764B8(&D_800D181C);
      func_80076EC0(&D_800D02E8, 1);
      func_80076EC0(&D_800D03D8, 1);
      break;
    case 6:
      func_800764B8(&D_800D20A4);
      func_800764A0(&D_800D2140, &D_800D20A4);
      func_800764A0(&D_800D21DC, &D_800D20A4);
      func_800764A0(&D_800D2278, &D_800D20A4);
      func_800764A0(&D_800D2314, &D_800D20A4);
      func_800764A0(&D_800D23B0, &D_800D20A4);
      func_800764A0(&D_800D244C, &D_800D20A4);
      func_800764A0(&D_800D24E8, &D_800D20A4);
      func_800764A0(&D_800D2584, &D_800D20A4);
      func_800764A0(&D_800D2620, &D_800D20A4);
      func_800764A0(&D_800D26BC, &D_800D20A4);
      func_800764A0(&D_800D2758, &D_800D20A4);
      func_800764A0(&D_800D27F4, &D_800D20A4);
      func_80076EC0(&D_800D0348, 1);
      func_80076EC0(&D_800D0438, 1);
      break;
    case 7:
      func_800764B8(&D_800D18B8);
      func_800764A0(&D_800D1954, &D_800D18B8);
      func_800764A0(&D_800D19F0, &D_800D18B8);
      func_800764B8(&D_800D1A8C);
      func_800764A0(&D_800D1B28, &D_800D1A8C);
      func_800764A0(&D_800D1BC4, &D_800D1A8C);
      func_800764A0(&D_800D1C60, &D_800D1A8C);
      func_800764A0(&D_800D1CFC, &D_800D1A8C);
      func_800764A0(&D_800D1D98, &D_800D1A8C);
      func_800764A0(&D_800D1E34, &D_800D1A8C);
      func_800764A0(&D_800D1ED0, &D_800D1A8C);
      func_800764B8(&D_800D1F6C);
      break;
    }
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[0], &D_800D0930[3 * screen + 0]);
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[1], &D_800D0930[3 * screen + 1]);
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[2], &D_800D0930[3 * screen + 2]);
  }

  if (D_800CFED4 == 2) {
    switch (screen) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      break;
    }
    ((ImageParams *) &D_8011FAE0)[0] = D_800D0C30[2 * screen + 0];
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[0], &D_800D0C30[2 * screen + 0]);
    ((ImageParams *) &D_8011FAE0)[1] = D_800D0C30[2 * screen + 1];
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[1], &D_800D0C30[2 * screen + 1]);
  }

  if (D_800CFED4 >= 3) {
    switch (screen) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      break;
    }
    ((ImageParams *) &D_8011FAE0)[0] = D_800D0E30[2 * screen + 0];
    FUN_027BF0_80061a3c_tenliner_allocs_heap(&((ImageParams *) &D_8011FAE0)[0], &D_800D0E30[2 * screen + 0]);
  }

  saved_screen = screen;
}

static void FUN_027BF0_8006307c_sixliner(ImageParams *imageParams) {
  if (imageParams->img.data != NULL) {
    n64HeapUnalloc(imageParams->img.data);
    imageParams->img.data = NULL;
  }
  if (imageParams->pal.data != NULL) {
    n64HeapUnalloc(imageParams->pal.data);
    imageParams->pal.data = NULL;
  }
}

void FUN_027BF0_Deinit(s32 arg0) {
  main_8004A34C_threeliner();
  if (D_800CFED4 == 1) {
    switch (saved_screen) {
    case 0:
      func_80077028(&D_800D02B8);
      func_800766C8(&D_800D1030);
      func_80075400(&D_8011FB40);
      break;
    case 1:
      func_80077028(&D_800D0468);
      func_80077028(&D_800D03A8);
      func_800766C8(&D_800D2890);
      break;
    case 2:
      func_800766C8(&D_800D2A64);
      func_800766C8(&D_800D29C8);
      func_800766C8(&D_800D292C);
      break;
    case 3:
      func_80077028(&D_800D0408);
      func_80077028(&D_800D0318);
      func_800766C8(&D_800D2008);
      break;
    case 4:
      func_80077028(&D_800D0378);
      func_800766C8(&D_800D2C38);
      break;
    case 5:
      func_80077028(&D_800D03D8);
      func_80077028(&D_800D02E8);
      func_800766C8(&D_800D181C);
      func_800766C8(&D_800D1510);
      break;
    case 6:
      func_80077028(&D_800D0438);
      func_80077028(&D_800D0348);
      func_800766C8(&D_800D20A4);
      break;
    case 7:
      func_800766C8(&D_800D1F6C);
      func_800766C8(&D_800D1A8C);
      func_800766C8(&D_800D18B8);
      break;
    }
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[0]);
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[1]);
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[2]);
  }

  if (D_800CFED4 == 2) {
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[0]);
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[1]);
  }

  if (D_800CFED4 >= 3) {
    FUN_027BF0_8006307c_sixliner(&((ImageParams *) &D_8011FAE0)[0]);
  }
}

void FUN_027BF0_8006332c_thirtyfiveliner(void) {
  s32 i;
  s32 j;

  for (i = 0; i < func_800A3AF0(); i++) {
    if (D_800D04A0[0] != 0) {
      D_800D04A0[0]--;
    }
    if (D_800D04A4[0] != 0) {
      D_800D04A4[0]--;
    }
  }

  D_8011FB60[0] = ((sins(D_800CFED8 << 11) * D_800D04A0[0]) >> 13) + 0x400;
  D_8011FB64[0] = ((coss(D_800CFED8 << 11) * D_800D04A4[0]) >> 13) + 0x400;

  for (j = 0; j < func_800A3AF0(); j++) {
    if (D_800D0498[0] > D_8011FB60[0]) {
      D_800D0498[0] -= 0x40;
      if (D_800D0498[0] < D_8011FB60[0]) {
        D_800D0498[0] = D_8011FB60[0];
      }
    }
    if (D_800D0498[0] < D_8011FB60[0]) {
      D_800D0498[0] += 0x40;
      if (D_800D0498[0] > D_8011FB60[0]) {
        D_800D0498[0] = D_8011FB60[0];
      }
    }
    if (D_800D049C[0] > D_8011FB64[0]) {
      D_800D049C[0] -= 0x40;
      if (D_800D049C[0] < D_8011FB64[0]) {
        D_800D049C[0] = D_8011FB64[0];
      }
    }
    if (D_800D049C[0] < D_8011FB64[0]) {
      D_800D049C[0] += 0x40;
      if (D_800D049C[0] > D_8011FB64[0]) {
        D_800D049C[0] = D_8011FB64[0];
      }
    }
  }
}

void func_80063618(s16 arg0) {
  D_800D04A0[arg0] = 100;
  D_800D04A4[arg0] = 100;
}

void func_8006364C(void) {
  D_800D04A0[0] = 0;
  D_800D04A0[1] = 0;
  D_800D04A4[0] = 0;
  D_800D04A4[1] = 0;
  D_800D0498[0] = 0x400;
  D_800D0498[1] = 0x400;
  D_800D049C[0] = 0x400;
  D_800D049C[1] = 0x400;
}

void FUN_027BF0_800636C0_display_game_stats_screen_q(void) {
  Game *game_ptr = &g_game;
  u8 tmp;

  if (D_800CFEE8 == 9) {
    D_800D02B0--;
    if (D_800D02B0 == 0) {
      tmp = Game_calls_SETGP_magic_7(game_ptr);
      if (D_800D02B4 != tmp) {
        if (FALSE);
        D_800D02B4 = tmp;
      }
      D_800D02B0 = 10;
    }
  }

  if (D_800CFED4 == 1) {
    switch (game_ptr->unkE4F8) {
    case 0:
      D_800D02B8.unk14 += D_800D04B4;

      func_8005BBFC(&g_gdl);

      // mayan moon
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FAE0.data, D_8011FAFC.data, D_8011FAE4, D_8011FAE8, D_8011FAEC, D_8011FAF0, D_8011FAF4, D_8011FAF8);

      func_8005BE40(&g_gdl);

      // mayan skybox
      func_80077098(&D_800D02B8);


      func_8005BBFC(&g_gdl);

      // mayan playfield
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB00.data, D_8011FB1C.data, D_8011FB04, D_8011FB08, D_8011FB0C, D_8011FB10, D_8011FB14, D_8011FB18);

      // mayan background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      gDPPipeSync(g_gdl++);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 290, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // mayan temple fire (x8)
      func_800767C0(&D_800D1030);
      func_800767C0(&D_800D10CC);
      func_800767C0(&D_800D1168);
      func_800767C0(&D_800D1204);
      func_800767C0(&D_800D12A0);
      func_800767C0(&D_800D133C);
      func_800767C0(&D_800D13D8);
      func_800767C0(&D_800D1474);

      func_8005BE40(&g_gdl);


      // special fx - mayan large fire (x2)
      func_80074EC4(&D_8011FB40);
      func_80075180();
      func_80075218(&D_8011FB40, 74, 208);
      func_80074F3C(&D_8011FB40);
      func_80075218(&D_8011FB40, 205, 208);
      func_80074F3C(&D_8011FB40);
      func_800751C0();
      break;
    case 1:
      D_800D03A8.unk14 += D_800D04B4;

      // greek skybox
      func_80077098(&D_800D03A8);


      func_8005BBFC(&g_gdl);

      // greek background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 201, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // greek fire pot
      func_800767C0(&D_800D2890);

      func_8005BE40(&g_gdl);


      // greek rain
      func_80077098(&D_800D0468);
      break;
    case 2:
      func_8005BBFC(&g_gdl);

      // egyptian background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // egyptian coal pot
      func_800767C0(&D_800D292C);

      // egyptian candle A
      func_800767C0(&D_800D29C8);

      // egyptian candle B
      func_800767C0(&D_800D2A64);

      func_8005BE40(&g_gdl);
      break;
    case 3:
      // celtic skybox
      func_80077098(&D_800D0318);


      func_8005BBFC(&g_gdl);

      // celtic background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // celtic lamp
      func_800767C0(&D_800D2008);

      func_8005BE40(&g_gdl);


      // celtic flying leaves
      func_80077098(&D_800D0408);
      break;
    case 4:
      // african skybox
      func_80077098(&D_800D0378);


      func_8005BBFC(&g_gdl);

      // african background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // african volcano smoke
      func_800767C0(&D_800D2C38);

      func_8005BE40(&g_gdl);
      break;
    case 5:
      D_800D02E8.unk14 -= D_800D04B4;

      // japanese skybox
      func_80077098(&D_800D02E8);


      func_8005BBFC(&g_gdl);

      // japanese background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // japanese water
      func_800767C0(&D_800D181C);

      // japanese sparkle (x5)
      func_800767C0(&D_800D1510);
      func_800767C0(&D_800D15AC);
      func_800767C0(&D_800D1648);
      func_800767C0(&D_800D16E4);
      func_800767C0(&D_800D1780);

      func_8005BE40(&g_gdl);


      // japanese flying butterflies
      func_80077098(&D_800D03D8);
      break;
    case 6:
      // russian skybox
      func_80077098(&D_800D0348);


      func_8005BBFC(&g_gdl);

      // russian background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // russian candle (x13)
      func_800767C0(&D_800D20A4);
      func_800767C0(&D_800D2140);
      func_800767C0(&D_800D21DC);
      func_800767C0(&D_800D2278);
      func_800767C0(&D_800D2314);
      func_800767C0(&D_800D23B0);
      func_800767C0(&D_800D244C);
      func_800767C0(&D_800D24E8);
      func_800767C0(&D_800D2584);
      func_800767C0(&D_800D2620);
      func_800767C0(&D_800D26BC);
      func_800767C0(&D_800D2758);
      func_800767C0(&D_800D27F4);

      func_8005BE40(&g_gdl);


      // russian snow
      func_80077098(&D_800D0438);
      break;
    case 7:
      func_8005BBFC(&g_gdl);

      // finale background
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB20.data, D_8011FB3C.data, D_8011FB24, D_8011FB28, D_8011FB2C, D_8011FB30, D_8011FB34, D_8011FB38);

      // p0 name
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 293, 202, game_ptr->players[0].name, 0xFF, 0xFF, 0xFF, 0xFF);

      // finale boiler (x3)
      func_800767C0(&D_800D18B8);
      func_800767C0(&D_800D1954);
      func_800767C0(&D_800D19F0);

      // finale light bulb (x8)
      func_800767C0(&D_800D1A8C);
      func_800767C0(&D_800D1B28);
      func_800767C0(&D_800D1BC4);
      func_800767C0(&D_800D1C60);
      func_800767C0(&D_800D1CFC);
      func_800767C0(&D_800D1D98);
      func_800767C0(&D_800D1E34);
      func_800767C0(&D_800D1ED0);

      // finale gauge needle
      func_800767C0(&D_800D1F6C);

      func_8005BE40(&g_gdl);
      break;
    }

    if (game_ptr->gameType == GAMETYPE_SPRINT) {
      register u32 time_remaining;

      // if (3 minutes > elapsed time)
      if (game_ptr->unkE4F0 > game_ptr->unkE4E8) {
        time_remaining = game_ptr->unkE4F0 - game_ptr->unkE4E8;
      } else {
        time_remaining = 0;
      }
      func_8005BBFC(&g_gdl);
      displayTimeFormatted_XY_RGBA(time_remaining, &game_ptr->font, 343, 230, 0xFF, 0xFF, 0xFF, 0xFF);
      func_8005BE40(&g_gdl);
    }

    if (game_ptr->gameType == GAMETYPE_ULTRA) {
      char ultra_goal_str[20];

      func_8005BBFC(&g_gdl);
      displayTimeFormatted_XY_RGBA(game_ptr->unkE4E8, &game_ptr->font, 343, 230, 0xFF, 0xFF, 0xFF, 0xFF);
      sprintf(ultra_goal_str, "%d", game_ptr->unkE4F4);
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 280, 260, ultra_goal_str, 0xFF, 0xFF, 0xFF, 0xFF);
      func_8005BE40(&g_gdl);
    }
  }

  if (D_800CFED4 == 2) {
    func_8005BBFC(&g_gdl);

    // background
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FAE0.data, D_8011FAFC.data, D_8011FAE4, D_8011FAE8, D_8011FAEC, D_8011FAF0, D_8011FAF4, D_8011FAF8);

    // p0 name (red)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 169, 200, game_ptr->players[0].name, 0xFF, 0, 0, 0xFF);

    // p1 name (green)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 169, 231, game_ptr->players[1].name, 0, 0xFF, 0, 0xFF);

    if (game_ptr->gameType == GAMETYPE_SPRINT) {
      // time
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB00.data, D_8011FB1C.data, D_8011FB04, D_8011FB08, D_8011FB0C, D_8011FB10, D_8011FB14, D_8011FB18);

      displayTimeFormatted_XY_RGBA(game_ptr->unkE4F0 - game_ptr->unkE4E8, &game_ptr->font, D_8011FB04 + 50, D_8011FB08 + 15, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (game_ptr->gameType == GAMETYPE_ULTRA) {
      char ultra_goal_str[20];

      sprintf(ultra_goal_str, "%d", game_ptr->unkE4F4);
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 190, 279, ultra_goal_str, 0xFF, 0xFF, 0xFF, 0xFF);

      // time
      weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FB00.data, D_8011FB1C.data, D_8011FB04, D_8011FB08, D_8011FB0C, D_8011FB10, D_8011FB14, D_8011FB18);

      displayTimeFormatted_XY_RGBA(game_ptr->unkE4E8, &game_ptr->font, D_8011FB04 + 50, D_8011FB08 + 15, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8005BE40(&g_gdl);

    gDPPipeSync(g_gdl++);
  }

  if (D_800CFED4 == 3) {
    func_8005BBFC(&g_gdl);

    // background
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FAE0.data, D_8011FAFC.data, D_8011FAE4, D_8011FAE8, D_8011FAEC, D_8011FAF0, D_8011FAF4, D_8011FAF8);

    // p0 name (red)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 39, 234, game_ptr->players[0].name, 0xFF, 0, 0, 0xFF);

    // p1 name (green)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 123, 234, game_ptr->players[1].name, 0, 0xFF, 0, 0xFF);

    // p2 name (blue)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 207, 234, game_ptr->players[2].name, 0, 0, 0xFF, 0xFF);

    if (game_ptr->gameType == GAMETYPE_SPRINT) {
      displayTimeFormatted_XY_RGBA(game_ptr->unkE4F0 - game_ptr->unkE4E8, &game_ptr->font, 216, 266, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (game_ptr->gameType == GAMETYPE_ULTRA) {
      char ultra_goal_str[20];

      sprintf(ultra_goal_str, "%d", game_ptr->unkE4F4);
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 188, 265, ultra_goal_str, 0xFF, 0xFF, 0xFF, 0xFF);

      displayTimeFormatted_XY_RGBA(game_ptr->unkE4E8, &game_ptr->font, 217, 278, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8005BE40(&g_gdl);

    gDPPipeSync(g_gdl++);
  }

  if (D_800CFED4 == 4) {
    func_8005BBFC(&g_gdl);

    // background
    weird_lots_of_magic_number_setting_66xrefs(&g_gdl, D_8011FAE0.data, D_8011FAFC.data, D_8011FAE4, D_8011FAE8, D_8011FAEC, D_8011FAF0, D_8011FAF4, D_8011FAF8);

    // p0 name (red)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 39, 234, game_ptr->players[0].name, 0xFF, 0, 0, 0xFF);

    // p1 name (green)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 123, 234, game_ptr->players[1].name, 0, 0xFF, 0, 0xFF);

    // p2 name (blue)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 207, 234, game_ptr->players[2].name, 0, 0, 0xFF, 0xFF);

    // p3 name (yellow)
    displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 292, 234, game_ptr->players[3].name, 0xFF, 0xFF, 0, 0xFF);

    if (game_ptr->gameType == GAMETYPE_SPRINT) {
      displayTimeFormatted_XY_RGBA(game_ptr->unkE4F0 - game_ptr->unkE4E8, &game_ptr->font, 216, 266, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (game_ptr->gameType == GAMETYPE_ULTRA) {
      char ultra_goal_str[20];

      sprintf(ultra_goal_str, "%d", game_ptr->unkE4F4);
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 188, 265, ultra_goal_str, 0xFF, 0xFF, 0xFF, 0xFF);

      displayTimeFormatted_XY_RGBA(game_ptr->unkE4E8, &game_ptr->font, 217, 278, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8005BE40(&g_gdl);

    gDPPipeSync(g_gdl++);
  }

  if (D_800CFEE8 == 12) {
    if (D_800D04B8 < 20) {
      func_8005BBFC(&g_gdl);
      displayText_XY_RGBA_2(&g_gdl, &game_ptr->font, 265, 110, "PRESS START", 0xFF, 0xFF, 0xFF, 0xFF);
      func_8005BE40(&g_gdl);
    }
    D_800D04B8 = (func_800A3AF0() + D_800D04B8) % 30;
  }
}
