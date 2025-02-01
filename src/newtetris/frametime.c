#include "common.h"

FrameTime g_frameTime;

void func_800A39B0(void) {
  g_frameTime.unk0 = 0;
  g_frameTime.unk4 = 0;
  g_frameTime.unk8 = 0;
  g_frameTime.unkC = 0;
  g_frameTime.unk10 = 0;
  g_frameTime.unk14 = 0;
}

void func_800A39D4(s32 arg0) {
  func_800A39B0();
  g_frameTime.unk0 = arg0;
}

void func_800A39FC(s32 arg0) {
  g_frameTime.unk4 = arg0;
  g_frameTime.unk0 += arg0;
  g_frameTime.unk8 += arg0;
  while (g_frameTime.unk8 >= 60) {
    g_frameTime.unk8 -= 60;
    g_frameTime.unkC++;
    if (g_frameTime.unkC == 60) {
      g_frameTime.unkC = 0;
      g_frameTime.unk10++;
      if (g_frameTime.unk10 == 60) {
        g_frameTime.unk10 = 0;
        g_frameTime.unk14++;
        if (g_frameTime.unk14 == 24) {
          g_frameTime.unk14 = 0;
        }
      }
    }
  }
}

void func_800A3A8C(s32 arg0) {
  func_800A39FC(arg0 - g_frameTime.unk0);
}

s32 func_800A3AB4(void) {
  return g_frameTime.unk0;
}

s32 func_800A3AC0(void) {
  return g_frameTime.unk8;
}

s32 func_800A3ACC(void) {
  return g_frameTime.unkC;
}

s32 func_800A3AD8(void) {
  return g_frameTime.unk10;
}

s32 func_800A3AE4(void) {
  return g_frameTime.unk14;
}

s32 func_800A3AF0(void) {
  return g_frameTime.unk4;
}
