#include "common.h"

extern /* static */ void   func_800A58A4(UnkStruct_32 *);
static void   func_800A652C(UnkStruct_32 *, UnkStruct_50 *);
extern /* static */ void   func_800A70A8(UnkStruct_32 *);
extern /* static */ Gfx   *func_800A7EFC(Gfx *, UnkStruct_32 *);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A4EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A52E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A53E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A56E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A57A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A57FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A58A4.s")
// static

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A59C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A5F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A60FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6360.s")

static void func_800A652C(UnkStruct_32 *arg0, UnkStruct_50 *arg1) {
  s32 temp_s4;
  UnkStruct_51 *var_s0;
  int i;
  void *temp_v0;
  UnkStruct_49 *temp_v0_3;
  UnkStruct_46 *tmp;

  if (arg1 == NULL) {
    return;
  }

  if (arg1->unk14 & 1) {
    return;
  }

  arg1->unk20 = arg0->unk8;
  arg1->unk10 = arg0;
  temp_s4 = arg1->unk24;
  var_s0 = arg1->unk28;
  for (i = 0; i < temp_s4; i++, var_s0++) {
    temp_v0 = func_800AA134((intptr_t)var_s0->unk0);
    switch (var_s0->unkC) {
    case 0:
      switch (func_800AA038((intptr_t)var_s0->unk0)) {
      case 0:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 1:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 2:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 3:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 4:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x8);
        break;
      case 5:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x10);
        break;
      case 6:
        OFFSET_TO_PTR(var_s0->unk10, temp_v0, 0x20);
        break;
      }
      var_s0->unk0 = temp_v0;
      break;
    case 1:
      temp_v0_3 = &arg1->unk20->unk28[(intptr_t)var_s0->unk10];
      var_s0->unk10 = temp_v0_3;
      var_s0->unk0 = temp_v0_3;
      break;
    case 2:
      tmp = temp_v0;
      var_s0->unk10 = &tmp->unk2C[(intptr_t)var_s0->unk10].unk4;
      var_s0->unk0 = temp_v0;
      break;
    case 3:
      var_s0->unk10 = &arg1->unk20->unk44[(intptr_t)var_s0->unk10];
      // or is it this?
      // var_s0->unk10 = &arg1->unk20->unk44[(intptr_t)var_s0->unk10].unk0;
      var_s0->unk0 = temp_v0;
      break;
    }
  }

  arg1->unk14 |= 1;
}

void func_800A6734(UnkStruct_32 *arg0) {
  UnkStruct_50 *var_s0;

  var_s0 = arg0->unk1D0;
  rmonPrintf("Animation list\n");
  while (var_s0 != NULL) {
    rmonPrintf("anim : 0x%08X\n", var_s0);
    var_s0 = var_s0->unkC;
  }
}

// push
void func_800A678C(UnkStruct_32 *arg0, UnkStruct_50 *arg1) {
  register UnkStruct_50 *temp_v0;

  if (!(arg1->unk14 & 1)) {
    func_800A652C(arg0, arg1);
  }
  temp_v0 = arg0->unk1D0;
  if (temp_v0 == NULL) {
    arg0->unk1D0 = arg1;
  } else {
    arg1->unkC = temp_v0;
    arg0->unk1D0->unk8 = arg1;
    arg0->unk1D0 = arg1;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A67EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A689C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6974.s")

// arg0 is fx_id
UnkStruct_32 *func_800A6990(s32 arg0) {
  register UnkStruct_32 *temp_v0;

  temp_v0 = n64HeapAlloc(0x1E8);
  if (temp_v0 == NULL) {
    return NULL;
  }

  func_800A9D50();
  temp_v0->unk8 = func_800AA14C(arg0);
  func_800A9D60();
  if (temp_v0->unk8 == NULL) {
    n64HeapUnalloc(temp_v0);
    return NULL;
  }

  temp_v0->unk0 = 0;
  temp_v0->unk4 = 0;
  temp_v0->unk6 = 1;
  temp_v0->unk5 = 0;
  temp_v0->unk1D0 = NULL;
  guMtxIdentF(temp_v0->unkC);
  guMtxIdentF(temp_v0->unk4C);
  return temp_v0;
}

void func_800A6A2C(UnkStruct_32 *arg0) {
  if (arg0 == NULL) {
    rmonPrintf("BorgAnimFreeScene : NULL handle\n");
    return;
  }

  func_800AB5E0(arg0->unk8);
  n64HeapUnalloc(arg0);
}

// arg0 is fx_id
UnkStruct_50 *func_800A6A74(s32 arg0) {
  register UnkStruct_50 *temp_v0;

  func_800A9D50();
  temp_v0 = func_800AA14C(arg0);
  func_800A9D60();
  return temp_v0;
}

void func_800A6AA8(UnkStruct_50 *obj) {
  func_800AB934(obj);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A6E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A70A8.s")
// static

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A71DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A724C.s")
/*
Gfx *func_800A724C(Gfx *arg0, UnkStruct_32 *arg1) {
  func_800A70A8(arg1);
  func_800A58A4(arg1);
  return func_800A7EFC(arg0, arg1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A7288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A72B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A7374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A74DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A7EFC.s")
// static

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A8FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A8FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/borganim/func_800A8FE8.s")
