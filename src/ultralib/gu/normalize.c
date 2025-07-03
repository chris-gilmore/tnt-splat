#include "common.h"

void guNormalize(f32 *x, f32 *y, f32 *z) {
  f32 m;

  m = 1 / sqrtf((*x * *x) + (*y * *y) + (*z * *z));
  *x *= m;
  *y *= m;
  *z *= m;
}
