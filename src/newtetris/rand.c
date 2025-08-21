#include "common.h"

static u32 D_80129340[5];
static f32 D_80129358[5];

static u32   func_800A35AC(void);
static f32   func_800A368C(void);
static u32   func_800A37F0(u8);
static f32   func_800A38B8(u8);

void func_800A3550(void) {
  D_80129340[0] = osGetTime();
  D_80129358[0] = D_80129340[0] / 100001;
}

static u32 func_800A35AC(void) {
  D_80129340[0] = D_80129340[0] * 10001 + 100001;

  return D_80129340[0];
}

s32 func_800A35EC(s32 arg0, s32 arg1) {
  s32 tmp;

  if (arg0 == arg1) {
    return arg0;
  }

  if (arg1 < arg0) {
    tmp = arg0;
    arg0 = arg1;
    arg1 = tmp;
  }

  return (func_800A35AC() % ((arg1 - arg0) + 1)) + arg0;
}

s32 func_800A3658(s32 arg0) {
  s32 tmp = arg0 / 2;

  return func_800A35EC(-tmp, tmp);
}

static f32 func_800A368C(void) {
  D_80129358[0] = (f32) (func_800A35AC() % 100001) / 100001;

  return D_80129358[0];
}

f32 func_800A36F0(f32 arg0, f32 arg1) {
  f32 tmp;

  if (arg0 == arg1) {
    return arg0;
  }

  if (arg1 < arg0) {
    tmp = arg0;
    arg0 = arg1;
    arg1 = tmp;
  }

  return func_800A368C() * (arg1 - arg0) + arg0;
}

void func_800A3758(void) {
  u8 i;

  D_80129340[0] = osGetTime();
  D_80129358[0] = D_80129340[0] / 100001;
  for (i = 1; i < 5; i++) {
    D_80129340[i] = D_80129340[0];
    D_80129358[i] = D_80129358[0];
  }
}

static u32 func_800A37F0(u8 i) {
  D_80129340[i] = D_80129340[i] * 10001 + 100001;

  return D_80129340[i];
}

s32 func_800A3840(u8 i, s32 arg1, s32 arg2) {
  s32 tmp;

  if (arg1 == arg2) {
    return arg1;
  }

  tmp = arg1;
  if (arg2 < arg1) {
    arg1 = arg2;
    arg2 = tmp;
  }

  return (func_800A37F0(i) % ((arg2 - arg1) + 1)) + arg1;
}

static f32 func_800A38B8(u8 i) {
  D_80129358[i] = (f32) (func_800A37F0(i) % 100001) / 100001;

  return D_80129358[i];
}

f32 func_800A3928(u8 i, f32 arg1, f32 arg2) {
  f32 tmp;

  if (arg1 == arg2) {
    return arg1;
  }

  if (arg2 < arg1) {
    tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
  }

  return func_800A38B8(i) * (arg2 - arg1) + arg1;
}
