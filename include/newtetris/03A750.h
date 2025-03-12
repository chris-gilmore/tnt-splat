#ifndef _03A750_H_
#define _03A750_H_

#define LZOBUF 0x80000400

typedef union {
  u32   data;
  u64   force_union_align;
} Dram_u;

extern void   func_800744D0(u8 *, u8 *, u32);
extern u32    func_800745DC(u8 *, u32);
extern void   FUN_03A750_800746c0_twentyliner(u8 *, u8 *, u32);
extern u32    FUN_03A750_80074888_twelveliner(u8 *, u32);

#endif /* !_03A750_H_ */
