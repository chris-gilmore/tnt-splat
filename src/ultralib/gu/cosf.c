#include "common.h"

static const du	P[] = {
  {0x3ff00000, 0x00000000},
  {0xbfc55554, 0xbc83656d},
  {0x3f8110ed, 0x3804c2a0},
  {0xbf29f6ff, 0xeea56814},
  {0x3ec5dbdf, 0x0e314bfe},
};
static const du	rpi = {0x3fd45f30, 0x6dc9c883};
static const du	pihi = {0x400921fb, 0x50000000};
static const du	pilo = {0x3e6110b4, 0x611a6263};
static const fu	zero = {0x00000000};

#pragma GLOBAL_ASM("asm/nonmatchings/ultralib/gu/cosf/cosf.s")
