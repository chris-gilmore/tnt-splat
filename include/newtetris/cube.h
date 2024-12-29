#ifndef _CUBE_H_
#define _CUBE_H_

typedef struct {
  /* 0x0  */ u8            is_active;
  /* 0x2  */ UnkStruct_8   unk2;
  /* 0x14 */ UnkStruct_8   unk14;
  /* 0x26 */ u8            unk26;
  /* 0x28 */ Mino          unk28;
} Cube; // 0x160 bytes

typedef struct {
  /* 0x0   */ u8         cell_id;   // unique id for cell
  /* 0x1   */ Position   pos;       // position of cell
  /* 0x4   */ Cube      *cube_ptr;  // pointer to a cube
} CubeInfo; // 0x8 bytes

extern u8 *g_next_cell_id_ptr;

extern void   Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros(CubeInfo *, s32, s32);
extern void   Cube_Alloc(CubeInfo *, s32, s32, Color *);
extern void   Cube_NewCellInfo(CubeInfo *);

#endif /* !_CUBE_H_ */
