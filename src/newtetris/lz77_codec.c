#include "common.h"

/*
  Preset dictionary.
*/
void func_8008EFA0(u8 *arg0, LZ77_Decompressor *arg1) {
  s16 i;
  s16 j;

  arg1->unk0 = arg0;
  arg1->unk1008 = arg1->unk1004 = 0;
  for (i = 0; i < 0x100; i++) {
    arg1->unk4[i] = i;
  }
  for (i = 0x100; i < 0x200; i++) {
    arg1->unk4[i] = 0x1FF - i;
  }
  for (i = 0; i < 0x100; i++) {
    for (j = 0; j < 4; j++) {
      arg1->unk4[0x200 + (4 * i) + j] = i;
    }
  }
  for (i = 0x600; i < 0x1000; i++) {
    arg1->unk4[i] = i & 0xFF;
  }
  arg1->unk100C = 0;
  arg1->unk100E = 0;
}

/*
  Decompression function for dcm pattern data.
  Is this a variant of LZ77 ?
*/
u8 func_8008F0D0(LZ77_Decompressor *arg0) {
  u8 ret;

  if (arg0->unk100C == 0) {
    arg0->unk100D = arg0->unk0[arg0->unk1004++];
    if (!(arg0->unk100D & 0xF0)) {
      arg0->unk100C = 1;
      arg0->unk100D++;
    } else {
      arg0->unk100C = 2;
      arg0->unk100E = arg0->unk0[arg0->unk1004++] + ((arg0->unk100D & 0xF) << 8);
      arg0->unk100D = (arg0->unk100D >> 4) + 2;
    }
  }

  if (arg0->unk100C == 1) {
    ret = arg0->unk0[arg0->unk1004++];
    arg0->unk4[arg0->unk1008++] = ret;
    arg0->unk1008 &= 0xFFF;
  }

  if (arg0->unk100C == 2) {
    ret = arg0->unk4[arg0->unk100E++];
    arg0->unk100E &= 0xFFF;
    arg0->unk4[arg0->unk1008++] = ret;
    arg0->unk1008 &= 0xFFF;
  }

  arg0->unk100D--;
  if (arg0->unk100D == 0) {
    arg0->unk100C = 0;
  }

  return ret;
}
