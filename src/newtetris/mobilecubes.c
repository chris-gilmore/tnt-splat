#include "common.h"

MobileCubes *g_mobileCubes_ptr;

static void   MobileCubes_Move(Cube *);

static void MobileCubes_Move(Cube *cube_ptr) {
  register s16 temp_a1;

  cube_ptr->unk26 = FALSE;

  temp_a1 = cube_ptr->unk2.unk0.p.x - cube_ptr->unk14.unk0.p.x;
  if ((temp_a1 >= -0x40) && (temp_a1 < 0x41)) {
    cube_ptr->unk2.unk0.p.x = cube_ptr->unk14.unk0.p.x;
  } else {
    cube_ptr->unk26 = TRUE;
  }
  if (temp_a1 >= 0x41) {
    cube_ptr->unk2.unk0.p.x -= 0x40;
  }
  if (temp_a1 < -0x40) {
    cube_ptr->unk2.unk0.p.x += 0x40;
  }

  temp_a1 = cube_ptr->unk2.unk6.p.x - cube_ptr->unk14.unk6.p.x;
  if ((temp_a1 >= -0x40) && (temp_a1 < 0x41)) {
    cube_ptr->unk2.unk6.p.x = cube_ptr->unk14.unk6.p.x;
  } else {
    cube_ptr->unk26 = TRUE;
  }
  if (temp_a1 >= 0x41) {
    cube_ptr->unk2.unk6.p.x -= 0x40;
  }
  if (temp_a1 < -0x40) {
    cube_ptr->unk2.unk6.p.x += 0x40;
  }

  temp_a1 = cube_ptr->unk2.unk0.p.y - cube_ptr->unk14.unk0.p.y;
  if ((temp_a1 >= -0x40) && (temp_a1 < 0x41)) {
    cube_ptr->unk2.unk0.p.y = cube_ptr->unk14.unk0.p.y;
  } else {
    cube_ptr->unk26 = TRUE;
  }
  if (temp_a1 >= 0x41) {
    cube_ptr->unk2.unk0.p.y -= 0x40;
  }
  if (temp_a1 < -0x40) {
    cube_ptr->unk2.unk0.p.y += 0x40;
  }

  temp_a1 = cube_ptr->unk2.unk6.p.y - cube_ptr->unk14.unk6.p.y;
  if ((temp_a1 >= -0x40) && (temp_a1 < 0x41)) {
    cube_ptr->unk2.unk6.p.y = cube_ptr->unk14.unk6.p.y;
  } else {
    cube_ptr->unk26 = TRUE;
  }
  if (temp_a1 >= 0x41) {
    cube_ptr->unk2.unk6.p.y -= 0x40;
  }
  if (temp_a1 < -0x40) {
    cube_ptr->unk2.unk6.p.y += 0x40;
  }
}

void MobileCubes_Update(void) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;
  register Cube *cube_ptr;
  register s32 i;

  for (i = mobileCubes_ptr->num_active, cube_ptr = mobileCubes_ptr->cube_list; i != 0;) {
    if (!cube_ptr->is_active) {
      cube_ptr++;
    } else {
      MobileCubes_Move(cube_ptr);
      cube_ptr++;
      i--;
    }
  }
}

void MobileCubes_Render(void) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;
  register Cube *cube_ptr;
  register s32 i;

  Minos_SetScale(0x100);
  Minos_SetAlpha(mobileCubes_ptr->alpha);
  Minos_BeginRender(mobileCubes_ptr->minos_ptr);
  Minos_SetVtxTransform(0);
  for (i = mobileCubes_ptr->num_active, cube_ptr = mobileCubes_ptr->cube_list; i != 0;) {
    if (!cube_ptr->is_active) {
      cube_ptr++;
    } else {
      if (cube_ptr->unk26) {
        cube_ptr->mino.unk1 |= 1;
      }
      Minos_80070528_Morph(&cube_ptr->mino);
      Minos_Mino_Render(&cube_ptr->mino, &cube_ptr->unk2);
      cube_ptr++;
      i--;
    }
  }
  Minos_EndRender(mobileCubes_ptr->minos_ptr);
}

Cube *MobileCubes_Alloc(void) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;
  register s32 i;
  register Cube *cube_ptr;

  for (i = 0, cube_ptr = mobileCubes_ptr->cube_list; cube_ptr->is_active && (i < mobileCubes_ptr->max_allowed); cube_ptr++, i++);

  mobileCubes_ptr->num_active++;
  cube_ptr->is_active = TRUE;

  return cube_ptr;
}

void MobileCubes_Unalloc(Cube *cube_ptr) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;

  cube_ptr->is_active = FALSE;
  mobileCubes_ptr->num_active--;
}

void MobileCubes_Init(s32 num_cubes, Minos *minos_ptr) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;
  register s32 i;
  register Cube *cube_ptr;

  mobileCubes_ptr->minos_ptr = minos_ptr;
  mobileCubes_ptr->alpha = 0xFF;
  mobileCubes_ptr->num_active = 0;
  mobileCubes_ptr->max_allowed = num_cubes;
  mobileCubes_ptr->cube_list = (Cube *)n64HeapAlloc(num_cubes * sizeof(Cube));
  for (i = num_cubes, cube_ptr = mobileCubes_ptr->cube_list; i > 0; cube_ptr++, i--) {
    cube_ptr->is_active = FALSE;
  }
}

void MobileCubes_Deinit(void) {
  register MobileCubes *mobileCubes_ptr = g_mobileCubes_ptr;
  register s32 i;
  register Cube *cube_ptr;

  // does nothing
  for (i = mobileCubes_ptr->max_allowed, cube_ptr = mobileCubes_ptr->cube_list; i > 0; cube_ptr++, i--);

  n64HeapUnalloc(mobileCubes_ptr->cube_list);
  mobileCubes_ptr->cube_list = NULL;
  mobileCubes_ptr->max_allowed = 0;
  mobileCubes_ptr->num_active = 0;
}
