#ifndef _IDS_H_
#define _IDS_H_

typedef struct {
  /* 0x0 */ u8   *list;     // allocated list of ids
  /* 0x4 */ u32   modulus;  // set to 201 (num_cells + 1) for pieceIds
  /* 0x8 */ u32   next_id;
} Ids; // 0xC bytes

extern void   Ids_Init(Ids *, s32);
extern void   Ids_Deinit(Ids *);
extern u32    can_run_out_of_ids(Ids *);
extern void   FUN_80050800_oneliner(Ids *, s32);
extern void   FUN_80050820_oneliner(Ids *, s32, s32);
extern void   FUN_80050840_fiveliner(Ids *, s32);

#endif /* !_IDS_H_ */
