#ifndef _IDS_H_
#define _IDS_H_

typedef struct {
  /* 0x0 */ u8   cnt;
} Id; // 0x1 byte

typedef struct {
  /* 0x0 */ Id   *list;     // allocated list of ids
  /* 0x4 */ u32   max_ids;  // set to 201 (num_cells + 1) for pieceIds
  /* 0x8 */ u32   next_id;
} Ids; // 0xC bytes

extern void   Ids_Init(Ids *, u32);
extern void   Ids_Deinit(Ids *);
extern u32    can_run_out_of_ids(Ids *);
extern void   FUN_80050800_oneliner(Ids *, u32);
extern void   FUN_80050820_oneliner(Ids *, u32, u32);
extern void   FUN_80050840_fiveliner(Ids *, u32);
extern void   FUN_800508a8_fiveliner(Ids *, u32, u32);
extern void   FUN_800508ec_fifteen_liner_allocs_heap(Ids *, Ids *);

#endif /* !_IDS_H_ */
