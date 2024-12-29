#ifndef _BAG63_H_
#define _BAG63_H_

typedef struct {
  /* 0x0  */ u32    next_idx;
  /* 0x4  */ u32    refill_idx;
  /* 0x8  */ u32    queue[25];
  /* 0x6C */ u8     pad6C[0x8];
  /* 0x74 */ u16    bag_len;
  /* 0x76 */ u8     bag[63];
  /* 0xB8 */ u32    seed;
} Bag63; // 0xBC bytes

extern u32    Bag63_GetNextPiece(Bag63 *);
extern void   Bag63_Init(Bag63 *, u32 *);
extern void   Bag63_Deinit(Bag63 *);

#endif /* !_BAG63_H_ */
