#include "common.h"

static void   func_800756E0(void);

s32 func_80075480(UnkStruct_15 *arg0, PaletteInfo *arg1, PaletteInfo *arg2) {
  register s32 alloc_size;
  register s32 j;
  register s32 i;
  register u16 *var_s3;
  register RGB *var_s4;
  register RGB *var_s5;
  register u32 r;
  register u32 g;
  register u32 b;
  register u16 rgba5551;

  arg0->unk4 = arg1->num_entries;
  arg0->unk6 = arg2->num_entries;
  alloc_size = arg0->unk4 * arg0->unk6 * arg0->unk9;
  arg0->unk0 = (u16 *) n64HeapAlloc(alloc_size);
  var_s3 = arg0->unk0;
  var_s5 = arg2->pal;
  for (i = 0; i < arg2->num_entries; i++) {
    var_s4 = arg1->pal;
    for (j = 0; j < arg1->num_entries; j++) {
      r = var_s5->r * (0xFF - var_s4->r) / 0xFF;
      g = var_s5->g * (0xFF - var_s4->g) / 0xFF;
      b = var_s5->b * (0xFF - var_s4->b) / 0xFF;
      r += var_s4->r;
      g += var_s4->g;
      b += var_s4->b;
      // RGB888 to RGBA5551
      rgba5551 = ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1) | 1;
      *var_s3++ = rgba5551;
      var_s4++;
    }
    var_s5++;
  }

  return 0;
}

void func_800756A8(UnkStruct_15 *arg0) {
  n64HeapUnalloc(arg0->unk0);
  arg0->unk0 = NULL;
}

static void func_800756E0(void) {
  UnkStruct_0 sp8;
  UnkStruct_15 *sp4;
  UnkStruct_24 *sp0;

  sp4 = &sp8.unk8;
  sp0 = &sp8.unk14;
}

void func_80075700(UnkStruct_24 *arg0, u32 arg1, u32 arg2, u32 arg3) {
  arg0->unkC = arg1;
  arg0->unk10 = arg2;
  arg0->unk14 = arg3;
  arg0->unk1C = (0x10000 / arg1) << 16;
  arg0->unk20 = (0x10000 / arg2) << 16;
  arg0->unk18 = arg1 * arg2;
}

void func_80075760(UnkStruct_0 *arg0, u8 arg1) {
  arg0->unk5C = arg1;

  switch (arg1) {
  case 0:
    arg0->unk58 = NULL;
    break;
  case 2:
    arg0->unk58 = func_800A2FB0;
    break;
  case 1:
    arg0->unk58 = (void (*)(UnkStruct_0 *))func_800A30F0;
    break;
  }
}

u8 func_800757BC(UnkStruct_0 *arg0, void *arg1, u32 arg2, u32 arg3) {
  arg0->unk0 = arg1;
  arg0->width = arg2;
  arg0->height = arg3;

  switch (arg0->unk5C) {
  case 0:
    break;
  case 2:
    if ((arg2 != 128) || (arg3 != 128)) {
      return FALSE;
    }
    break;
  case 1:
    if ((arg2 != 128) || (arg3 != 128)) {
      return FALSE;
    }
    break;
  default:
    return FALSE;
  }

  return TRUE;
}

void func_80075830(UnkStruct_0 *arg0) {
  func_800756E0();
  func_80075760(arg0, 0);
  func_800757BC(arg0, NULL, 0, 0);
}

void func_80075870(UnkStruct_0 *arg0) {
  func_80075760(arg0, 0);
  func_800757BC(arg0, NULL, 0, 0);
}
