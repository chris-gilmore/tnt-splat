#include "common.h"

FallingCubes *g_fallingCubes_ptr;

static void   FallingCubes_Drop(Cube **);

static void FallingCubes_Drop(Cube **cube_ptr_ptr) {
  register Cube *cube_ptr;

  cube_ptr = *cube_ptr_ptr;
  cube_ptr->unk2.unk6.p.y += 0x80;
  cube_ptr->unk14.unk6 = cube_ptr->unk2.unk6;
  if (cube_ptr->unk2.unk6.p.y > 0x1600) {
    MobileCubes_Unalloc(*cube_ptr_ptr);
    *cube_ptr_ptr = NULL;
    *cube_ptr_ptr = NULL;
    g_fallingCubes_ptr->num_active--;
  }
}

void FallingCubes_Update(void) {
  register FallingCubes *fallingCubes_ptr = g_fallingCubes_ptr;
  register Cube **cube_ptr_ptr;
  register s32 i;

  for (i = fallingCubes_ptr->num_active, cube_ptr_ptr = fallingCubes_ptr->cube_ptr_list; i != 0; cube_ptr_ptr++) {
    if (*cube_ptr_ptr != NULL) {
      Minos_800709d8_threeliner_sets_arg0_1c_1e_1d(&(*cube_ptr_ptr)->mino, fallingCubes_ptr->alpha);
      FallingCubes_Drop(cube_ptr_ptr);
      i--;
    }
  }
}

void FallingCubes_SetAlpha(FallingCubes *fallingCubes_ptr, u8 alpha) {
  register s32 i;
  register Cube **cube_ptr_ptr;

  fallingCubes_ptr->alpha = alpha;
  for (i = fallingCubes_ptr->num_active, cube_ptr_ptr = fallingCubes_ptr->cube_ptr_list; i > 0; cube_ptr_ptr++) {
    if (*cube_ptr_ptr != NULL) {
      Minos_800709d8_threeliner_sets_arg0_1c_1e_1d(&(*cube_ptr_ptr)->mino, alpha);
      i--;
    }
  }
}

Cube **FallingCubes_Alloc(void) {
  register FallingCubes *fallingCubes_ptr = g_fallingCubes_ptr;
  register Cube **cube_ptr_ptr;
  register s32 i;

  for (i = 0, cube_ptr_ptr = fallingCubes_ptr->cube_ptr_list; (*cube_ptr_ptr != NULL) && (i < fallingCubes_ptr->max_allowed); cube_ptr_ptr++, i++);

  if (fallingCubes_ptr->max_allowed == i) {
    debug_print_reason_routine("FallingCubes_Alloc()", "Failed!");
  }

  fallingCubes_ptr->num_active++;

  return cube_ptr_ptr;
}

void FallingCubes_Init(s32 num_cubes) {
  register FallingCubes *fallingCubes_ptr = g_fallingCubes_ptr;
  register s32 i;
  register Cube **cube_ptr_ptr;

  fallingCubes_ptr->alpha = 0xFF;
  fallingCubes_ptr->max_allowed = num_cubes;
  fallingCubes_ptr->num_active = 0;
  fallingCubes_ptr->cube_ptr_list = (Cube **)n64HeapAlloc(num_cubes * sizeof(Cube *));
  for (i = fallingCubes_ptr->max_allowed, cube_ptr_ptr = fallingCubes_ptr->cube_ptr_list; i > 0; cube_ptr_ptr++, i--) {
    *cube_ptr_ptr = NULL;
  }
}

void FallingCubes_Deinit(void) {
  register FallingCubes *fallingCubes_ptr = g_fallingCubes_ptr;

  n64HeapUnalloc(fallingCubes_ptr->cube_ptr_list);
  fallingCubes_ptr->cube_ptr_list = NULL;
  fallingCubes_ptr->max_allowed = 0;
  fallingCubes_ptr->num_active = 0;
}
