#include "common.h"

static void   Bag63_FillBag(Bag63 *);
extern void   Bag63_RefillQueue(Bag63 *);

static void Bag63_FillBag(Bag63 *bag63_ptr) {
  register s32 i;
  register s32 piece_type;
  register u8 *bag = bag63_ptr->bag;

  for(i = 0; i < 9; i++) {
    for (piece_type = 0; piece_type < 7; piece_type++) {
      *bag++ = piece_type;
    }
  }
  bag63_ptr->bag_len = 63;
}

void Bag63_RefillQueue(Bag63 *bag63_ptr) {
  register s32 unused;
  register u8 *bag;
  register u32 i;
  register u32 bag_idx;
  register u8 piece_type;

  while (bag63_ptr->next_idx != bag63_ptr->refill_idx) {
    bag63_ptr->seed = FUN_026900_PRNG_2(bag63_ptr->seed);
    bag_idx = bag63_ptr->seed % bag63_ptr->bag_len;
    // Randomly pluck a piece from the bag.
    piece_type = bag63_ptr->bag[bag_idx];
    bag = &bag63_ptr->bag[bag_idx];
    // Fill the hole left by the plucked piece by shifting left every piece after it.
    for (i = bag_idx; i < 62; i++) {
      *bag++ = bag[1];
    }
    if (--bag63_ptr->bag_len == 0) {
      Bag63_FillBag(bag63_ptr);
    }
    // Place the plucked piece into the queue.
    bag63_ptr->queue[bag63_ptr->refill_idx] = piece_type;
    bag63_ptr->refill_idx = (bag63_ptr->refill_idx + 1) % 25;
  }
}

u32 Bag63_GetNextPiece(Bag63 *bag63_ptr) {
  register u32 piece_type;

  Bag63_RefillQueue(bag63_ptr);
  piece_type = bag63_ptr->queue[bag63_ptr->next_idx];
  bag63_ptr->next_idx = (bag63_ptr->next_idx + 1) % 25;
  return piece_type;
}

void Bag63_Init(Bag63 *bag63_ptr, u32 *seed_ptr) {
  Bag63_FillBag(bag63_ptr);
  bag63_ptr->seed = *seed_ptr;
  bag63_ptr->next_idx = 0;
  bag63_ptr->refill_idx = 1;
  Bag63_RefillQueue(bag63_ptr);
  bag63_ptr->next_idx = 1;
  *seed_ptr = bag63_ptr->seed;
}

void Bag63_Deinit(Bag63 *bag63_ptr) {
}
