#include "common.h"

int guRandom(void) {
  static u32 xseed = 174823885;
  u32 x;

  x = xseed << 2;
  x = (x + 2) * (x + 3);
  x >>= 2;
  xseed = x;

  return x;
}
