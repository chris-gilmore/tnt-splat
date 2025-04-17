#include "common.h"

#include "sintable.h"

s16 sins(u16 angle) {
  s16 ret;

  angle >>= 4;

  if (angle & 0x400) {
    ret = sintable[0x3FF - (angle & 0x3FF)];
  } else {
    ret = sintable[angle & 0x3FF];
  }

  if (angle & 0x800) {
    return -ret;
  } else {
    return ret;
  }
}
