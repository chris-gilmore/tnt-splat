#ifndef _004220_H_
#define _004220_H_

typedef struct {
  /* 0x0 */ u8   unk0;  // x
  /* 0x1 */ s8   unk1;  // y
  /* 0x2 */ u8   unk2;  // rot
} UnkStruct_108; // 0x3 bytes

typedef struct {
  /* 0x0 */ u8              unk0[2];
  /* 0x2 */ UnkStruct_108   unk2[2][400];
} UnkStruct_109; // 0x962 bytes

extern UnkStruct_109 *D_800E1F20;

extern void   FUN_004220_8003dfa0_sixliner_allocs_heap_x962(void);
extern void   FUN_004220_8003e004_threeliner_unallocs_heap(void);
extern void   FUN_004220_8003e038_twentytwoliner_nested_loops(u8, u8);

#endif /* !_004220_H_ */
