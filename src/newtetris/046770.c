#include "common.h"

extern u8 D_F00001;  // what is this?

extern u16 draw_buffer;

////////////////////////////////////////

void FUN_046770_800804f0_many_heapallocs_for_arg0_elems(UnkStruct_12 *arg0) {
  u8 *sp4C;  // greyscale image used as height field
  register s32 i;
  register s32 j;
  register Gradient2D *var_s2;
  register u8 *var_s3;
  PaletteInfo palInfo_1;
  PaletteInfo palInfo_2;

  // (200 x 150)  I - IMG_UNKNOWN_0X49B274
  sp4C = (u8 *) n64HeapAlloc(200 * 150 * sizeof(u8));

  // gradients for above height field
  arg0->unk8 = (Gradient2D *) n64HeapAlloc(200 * 150 * sizeof(Gradient2D));

  // (200 x 150) CI - IMG_UNKNOWN_0X4946FE
  arg0->unk0 = (u8 *) n64HeapAlloc(200 * 150 * sizeof(u8));

  // (RGB palette)  - IMG_UNKNOWN_0X49AFAC
  arg0->unk4 = (RGB *) n64HeapAlloc(256 * sizeof(RGB));

  // (128 x 128) CI - IMG_UNKNOWN_0X4A1C4C
  arg0->unkC = (u8 *) n64HeapAlloc(128 * 128 * sizeof(u8));

  // (RGB palette)  - IMG_UNKNOWN_0X4A3BBC
  arg0->unk10 = (RGB *) n64HeapAlloc(256 * sizeof(RGB));

  arg0->unk14 = n64HeapAlloc(60008);
  arg0->unk18 = n64HeapAlloc(60008);

  main_8004A34C_threeliner();
  FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk0, IMG_UNKNOWN_0X4946FE);
  FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk4, IMG_UNKNOWN_0X49AFAC);
  FUN_03A750_800746c0_twentyliner(&D_273A00, sp4C, IMG_UNKNOWN_0X49B274);
  FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unkC, IMG_UNKNOWN_0X4A1C4C);
  FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk10, IMG_UNKNOWN_0X4A3BBC);

  var_s3 = sp4C;
  var_s2 = arg0->unk8;
  for (j = 0; j < 149; j++) {
    for (i = 0; i < 199; i++) {
      // calculate gradient
      var_s2->y = var_s3[0] - var_s3[200];
      var_s2->x = var_s3[0] - var_s3[1];
      var_s2++;
      var_s3++;
    }
    var_s2->y = 0;
    var_s2->x = 0;
    var_s2++;
    var_s3++;
  }
  n64HeapUnalloc(sp4C);

  palInfo_1.unk4 = 0;
  palInfo_1.num_entries = 256;
  palInfo_1.pal = arg0->unk4;
  palInfo_2.unk4 = 0;
  palInfo_2.num_entries = 256;
  palInfo_2.pal = arg0->unk10;

  arg0->unk1C.unk8.unk8 = 0;
  arg0->unk1C.unk8.unk9 = 2;
  func_80075480(&arg0->unk1C.unk8, &palInfo_1, &palInfo_2);
  func_80075830(&arg0->unk1C);
  func_80075760(&arg0->unk1C, 1);
  func_800757BC(&arg0->unk1C, arg0->unkC, 128, 128);

  arg0->unk7C = 0;
  arg0->unk7E = 0;
  arg0->unk80 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/046770/FUN_046770_8008074c_nineliner_calls_9funcs_warg0_elems.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/046770/FUN_046770_8008080c_threeliner_sets_arg0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/046770/FUN_046770_magic_150_is_it_ultra_related.s")
