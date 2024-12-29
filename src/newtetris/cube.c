#include "common.h"

u8 *g_next_cell_id_ptr;

static void   Cube_8006e8b0_sets_struct_0x02_to_0x12_to_mostly_zeros(CubeInfo *, s32, s32);
static u8     Cube_NextCellId(void);

static void Cube_8006e8b0_sets_struct_0x02_to_0x12_to_mostly_zeros(CubeInfo *cubeInfo_ptr, s32 x, s32 y) {
  register Cube *cube_ptr;

  cube_ptr = cubeInfo_ptr->cube_ptr;
  cubeInfo_ptr->pos.x = x;
  cubeInfo_ptr->pos.y = y;
  if (cube_ptr != NULL) {
    setPointAngle(cube_ptr->unk2.unk0, 0, 0, 0);
    setPointAngle(cube_ptr->unk2.unk6, x << 8, y << 8, 0);
    setPointAngle(cube_ptr->unk2.unkC, 0, 0, 0);
  }
}

void Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros(CubeInfo *cubeInfo_ptr, s32 x, s32 y) {
  register Cube *cube_ptr;

  cube_ptr = cubeInfo_ptr->cube_ptr;
  cubeInfo_ptr->pos.x = x;
  cubeInfo_ptr->pos.y = y;
  if (cube_ptr != NULL) {
    setPointAngle(cube_ptr->unk14.unk0, 0, 0, 0);
    setPointAngle(cube_ptr->unk14.unk6, x << 8, y << 8, 0);
    setPointAngle(cube_ptr->unk14.unkC, 0, 0, 0);
  }
}

void Cube_Alloc(CubeInfo *cubeInfo_ptr, s32 x, s32 y, Color *color_ptr) {
  cubeInfo_ptr->cube_ptr = MobileCubes_Alloc();
  Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(&cubeInfo_ptr->cube_ptr->unk28, color_ptr);
  Cube_8006e8b0_sets_struct_0x02_to_0x12_to_mostly_zeros(cubeInfo_ptr, x, y);
  Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros(cubeInfo_ptr, x, y);
  Minos_800702e4_nineliner(&cubeInfo_ptr->cube_ptr->unk28);
}

void Cube_NewCellInfo(CubeInfo *cubeInfo_ptr) {
  cubeInfo_ptr->cell_id = Cube_NextCellId();
  cubeInfo_ptr->cube_ptr = NULL;
  cubeInfo_ptr->pos.x = -1;
  cubeInfo_ptr->pos.y = -1;
}

static u8 Cube_NextCellId(void) {
  register u8 *next_cell_id_ptr = g_next_cell_id_ptr;

  return (*next_cell_id_ptr)++;
}
