#ifndef _006B30_H_
#define _006B30_H_

typedef struct {
  /* 0x0 */ s8   unk0[4];  // relative x position for each mino
  /* 0x4 */ s8   unk4[4];  // relative y position for each mino
} UnkStruct_28; // 0x8 bytes

// 7 pieces, 4 rotations per piece
extern UnkStruct_28 D_800C5CF0[7][4];

extern u8   FUN_006B30_800408b0_fiveliner_loops_4t(u8, u8, u8);

#endif /* !_006B30_H_ */
