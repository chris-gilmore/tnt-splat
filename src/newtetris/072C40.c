#include "common.h"

UnkStruct_32 *func_800AC9C0(void) {
  s32 alloc_sz;
  s32 i;
  u8 *ptr;
  void *sp48;
  UnkStruct_32 *sp44;
  UnkStruct_48 *sp40;
  UnkStruct_49 *sp3C;
  UnkStruct_45 *sp38;
  UnkStruct_39 *sp34;
  UnkStruct_39 **sp30;
  Vp *sp2C;
  UnkStruct_64 *sp28;
  UnkStruct_65 *sp24;
  UnkStruct_63 *sp20;
  s32 j;

  alloc_sz  =     sizeof(UnkStruct_64);
  alloc_sz += 8 * sizeof(UnkStruct_65);
  alloc_sz += 2 * sizeof(Vp);
  alloc_sz +=     sizeof(UnkStruct_32);
  alloc_sz +=     sizeof(UnkStruct_48);
  alloc_sz += 9 * sizeof(UnkStruct_49);
  alloc_sz +=     sizeof(UnkStruct_45);
  alloc_sz += 8 * sizeof(UnkStruct_39);
  alloc_sz += 8 * sizeof(UnkStruct_39 *);
  alloc_sz += 9 * sizeof(UnkStruct_63);
  ptr = n64HeapAlloc(alloc_sz);
  if (ptr == NULL) {
    return NULL;
  }

  sp48 = ptr;
  sp28 = (UnkStruct_64 *) ptr;
  ptr += sizeof(UnkStruct_64);
  sp24 = (UnkStruct_65 *) ptr;
  ptr += sizeof(UnkStruct_65) * 8;
  sp2C = (Vp *) ptr;
  ptr += sizeof(Vp) * 2;
  sp44 = (UnkStruct_32 *) ptr;
  ptr += sizeof(UnkStruct_32);
  sp40 = (UnkStruct_48 *) ptr;
  ptr += sizeof(UnkStruct_48);
  sp3C = (UnkStruct_49 *) ptr;
  ptr += sizeof(UnkStruct_49) * 9;
  sp38 = (UnkStruct_45 *) ptr;
  ptr += sizeof(UnkStruct_45);
  sp34 = (UnkStruct_39 *) ptr;
  ptr += sizeof(UnkStruct_39) * 8;
  sp30 = (UnkStruct_39 **) ptr;
  ptr += sizeof(UnkStruct_39 *) * 8;
  sp20 = (UnkStruct_63 *) ptr;
  ptr += sizeof(UnkStruct_63) * 9;

  sp44->unk0 = 2072;
  sp44->unk4 = 0;
  sp44->unk5 = 0;
  sp44->unk6 = 1;
  sp44->unk8 = sp40;

  guMtxIdentF((f32 (*)[4]) &sp44->unkC);
  guMtxIdentF((f32 (*)[4]) &sp44->unk4C);

  sp44->unk1D4 = 0;
  sp44->unk1D5 = 0;
  sp44->unk1D6 = 0;
  sp44->unk1D7 = 1;
  sp44->unk1D8 = 800;
  sp44->unk1DC = 1000;
  sp44->unk1D0 = NULL;

  sp40->basehdr.id = -1;
  sp40->basehdr.unk4 = 0;
  sp40->unk8 = sp48;
  sp40->unk10.unk0 = 2;
  sp40->unk10.unk4 = 1;
  sp40->unk10.unkC = 0;
  sp40->unk10.unk8 = 0;
  sp40->unk10.unk14 = 0;
  sp40->unk10.unk1C = NULL;
  sp40->unk10.unk38 = NULL;
  sp40->unk10.unk18 = sp3C;
  sp40->unk10.unk24 = sp38;
  sp40->unk10.unk28 = sp30;

  sp3C->unk0 = 256;
  sp3C->unk2 = 1;
  sp3C->unk3 = 0;
  sp3C->unk8 = 0;
  sp3C->unk4 = NULL;
  sp3C->unkC = sp20;
  i = 0;
  while (i < 6) {
    sp3C->unk10[i++] = 0;
  }
  while (i < 9) {
    sp3C->unk10[i++] = 1;
  }
  sp3C++;
  sp20++;

  sp38->basehdr.id = -1;
  sp38->basehdr.unk4 = 0;
  sp38->unk10.unk0 = 0;
  sp38->unk10.unk8 = 1;      // near
  sp38->unk10.unk10 = 1;
  sp38->unk10.unk4 = 45;     // fovy
  sp38->unk10.unkC = 4096;   // far
  sp38->unk10.unk14 = 1.18;  // aspect
  sp38->unk10.unk18 = sp2C;  // veiewport
  sp38->unk10.unk1C = sp28;

  for (i = 0; i < 2; i++) {
    sp38->unk10.unk18[i].vp.vscale[0] = 800;
    sp38->unk10.unk18[i].vp.vscale[1] = 600;
    sp38->unk10.unk18[i].vp.vscale[2] = 1023;
    sp38->unk10.unk18[i].vp.vscale[3] = 0;

    sp38->unk10.unk18[i].vp.vtrans[0] = 800;
    sp38->unk10.unk18[i].vp.vtrans[1] = 600;
    sp38->unk10.unk18[i].vp.vtrans[2] = 0;
    sp38->unk10.unk18[i].vp.vtrans[3] = 0;
  }

  for (i = 8; i != 0; i--, sp3C++, sp34++, sp30++, sp20++, sp24++) {
    *sp30 = sp34;

    sp34->basehdr.id = -1;
    sp34->basehdr.unk4 = 0;
    sp34->unk8.unk0 = 0.75;
    sp34->unk8.red = 0.75;
    sp34->unk8.green = 0.75;
    sp34->unk8.blue = 0.75;
    sp34->unk8.unk10 = sp24;

    sp3C->unk0 = 256;
    sp3C->unk2 = 3;
    sp3C->unk3 = 0;
    sp3C->unkC = sp20;
    sp3C->unk8 = 0;
    sp3C->unk4 = NULL;

    for (j = 0; j < 9; sp3C->unk10[j++] = 0);
  }

  return sp44;
}

// unused
void func_800ACCDC(UnkStruct_32 *arg0) {
  if (arg0->unk0 & 0x800) {
    n64HeapUnalloc(arg0->unk8->unk8);
  }
}

// unused
void func_800ACD10(UnkStruct_32 *arg0, s32 cnt) {
  if (arg0->unk0 & 0x800) {
    if (cnt > 8) {
      cnt = 8;
    }
    arg0->unk8->unk10.unk0 = cnt + 1;
    arg0->unk8->unk10.unk4 = cnt;
  }
}

// unused
void func_800ACD4C(UnkStruct_32 *arg0, s32 num, f32 arg2, f32 arg3, f32 arg4) {
  UnkStruct_49 *temp_v0;

  if (arg0->unk0 & 0x800) {
    num = (num & 7) + 1;
    temp_v0 = &arg0->unk8->unk10.unk18[num];
    temp_v0->unk10[0] = arg2;
    temp_v0->unk10[1] = arg3;
    temp_v0->unk10[2] = arg4;
  }
}

// unused
void func_800ACD94(UnkStruct_32 *arg0, s32 num, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
  UnkStruct_39 *temp_v0;

  if (arg0->unk0 & 0x800) {
    num = num & 7;
    temp_v0 = arg0->unk8->unk10.unk28[num];
    temp_v0->unk8.red = arg2;
    temp_v0->unk8.green = arg3;
    temp_v0->unk8.blue = arg4;
    temp_v0->unk8.unk0 = arg5;
  }
}

// unused
void func_800ACDE4(UnkStruct_32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
  Vp *vp;

  if (arg0->unk0 & 0x800) {
    vp = arg0->unk8->unk10.unk24->unk10.unk18;
    vp->vp.vscale[0] = 2.0 * (arg3 - arg1);
    vp->vp.vscale[1] = 2.0 * (arg4 - arg2);
    vp->vp.vtrans[0] = 2.0 * (arg3 + arg1);
    vp->vp.vtrans[1] = 2.0 * (arg4 + arg2);
  }
}
