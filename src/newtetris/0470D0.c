#include "common.h"
#include "minilzo.h"

void func_80080E50(void) {
  __lzo_init2(LZO_VERSION, 2, 4, 4, 4, 4, 4, 4, 4, 4);
}

void func_80080EAC(void) {
}

void func_80080EB4(u8 *arg0, u32 *arg1, u8 *arg2, u32 arg3) {
}

/*
  arg0: pointer to decompressed data
  arg1: address of length of decompressed data
  arg2: pointer to compressed data
  arg3: length of compressed data
*/
void func_80080EC8(u8 *arg0, u32 *arg1, u8 *arg2, u32 arg3) {
  lzo1x_decompress(arg2, arg3, arg0, arg1, NULL);
}

void func_80080F08(s32 arg0) {
  n64HeapAlloc(arg0);
}

void func_80080F30(u8 *arg0) {
  n64HeapUnalloc(arg0);
}
