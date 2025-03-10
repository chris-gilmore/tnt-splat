#ifndef _N64HEAP_H_
#define _N64HEAP_H_

typedef struct N64Heap_s {
  u8                 *pBlock;  // should this be a void *, instead?
  u32                size;
  struct N64Heap_s   *next;
  struct N64Heap_s   *prev;
} N64Heap;

extern void   n64HeapInit(u8 *, s32);  // should this be a void * ?
extern u8    *n64HeapAlloc(s32);  // should this be a void * ?
extern void   n64HeapUnalloc(u8 *);  // should this be a void * ?
extern s32    n64HeapGetTotalMemFree(void);
extern s32    n64HeapGetMaxFreeBlockSize(void);
extern void   n64HeapStats(void);

#endif /* !_N64HEAP_H_ */
