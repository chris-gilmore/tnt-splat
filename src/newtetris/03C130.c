#include "common.h"

extern u8 D_273A00;  // image_lut

////////////////////////////////////////

void FUN_03C130_80075EB0_nineliner_allocs_heap(UnkStruct_21 *arg0) {
  func_80075700(&arg0->unk0.unk14, 8, 8, 1);
  main_8004A34C_threeliner();

  // light source (128x128)
  arg0->unk64 = (u8 *) n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_273A00, IMG_UNKNOWN_0X2A774C));
  FUN_03A750_800746c0_twentyliner(&D_273A00, arg0->unk64, IMG_UNKNOWN_0X2A774C);
  func_80075830(&arg0->unk0);
  func_80075760(&arg0->unk0, 2);
  func_800757BC(&arg0->unk0, arg0->unk64, 128, 128);
}

void func_80075F5C(UnkStruct_21 *arg0) {
  func_80075870(&arg0->unk0);
  n64HeapUnalloc(arg0->unk64);
}
