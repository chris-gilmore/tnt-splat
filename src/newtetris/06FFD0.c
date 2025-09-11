#include "common.h"

#include "newtetris/coders.h"

static void   func_800A9D78(void *);
static s32    func_800A9F9C(void *, s32, void *, s32, s32);
static s32    func_800AA3DC(s32);
static s32    func_800AA3F4(s32);
static void   func_800AA5A8(void *);  // 0
static s32    func_800AA5BC(void *);  // 0
static void   func_800AA608(void *);  // 1
static s32    func_800AA62C(void *);  // 1
static void   func_800AA678(void *);  // 2
static s32    func_800AA864(void *);  // 2
static void   func_800AA8C8(void *);  // 4
static s32    func_800AA8D0(void *);  // 4
static void   func_800AA91C(void *);  // 3
static s32    func_800AA934(void *);  // 3
static void   func_800AA980(void *);  // 5
static s32    func_800AAB0C(void *);  // 5
static void   func_800AB700(void *);  // 6
static s32    func_800AB794(void *);  // 6
static void   func_800AB9B4(UnkStruct_56 *, void *);
static void   func_800ABAB8(UnkStruct_54 *, void *);
static void   func_800ABD64(UnkStruct_54 *);

static u8 *D_80129600;  // rom address of fx lut
static u8 *D_80129604;  // rom address of fx assets
static s32 D_80129608;  // total number of fx assets
static OSThread D_80129610;
static u64 D_801297C0[0x88/sizeof(u64)];
static OSMesgQueue D_80129848;
static OSMesg D_80129860[1024];

static UnkStruct_40 *D_800D7B00 = NULL;
static s32 D_800D7B04 = 0;
static void (*D_800D7B08[])(void *) = {
  func_800AA5A8,
  func_800AA608,
  func_800AA678,
  func_800AA91C,
  func_800AA8C8,
  func_800AA980,
  func_800AB700,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};
static s32 (*D_800D7B3C[])(void *) = {
  func_800AA5BC,
  func_800AA62C,
  func_800AA864,
  func_800AA934,
  func_800AA8D0,
  func_800AAB0C,
  func_800AB794,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};
static s32 D_800D7B70[] = { 0x8, 0x8, 0x10, 0x10, 0x8, 0x10, 0x20 };

void func_800A9D50(void) {
  D_800D7B04 = 1;
}

void func_800A9D60(void) {
  D_800D7B04 = 0;
}

// unused
s32 func_800A9D6C(void) {
  return D_80129608;
}

// unused (because func_800A9DD8 is unused)
static void func_800A9D78(void *arg0) {
  OSMesg sp24;

  while (osRecvMesg(&D_80129848, &sp24, OS_MESG_BLOCK));
}

// unused
void func_800A9DD8(void) {
  // (bug) stack parameter should have been:
  // D_801297C0 + 0x88/sizeof(u64)
  osCreateThread(&D_80129610, 17, func_800A9D78, NULL, D_801297C0, 11);
  osCreateMesgQueue(&D_80129848, D_80129860, 1024);
  osStartThread(&D_80129610);
}

void func_800A9E44(void *arg0, void *arg1) {
  UnkStruct_42 sp20;
  s32 i;

  D_80129600 = arg0;  // rom address of fx lut
  D_80129604 = arg1;  // rom address of fx assets
  func_800ABFF0(D_80129600, &sp20, sizeof(UnkStruct_42));
  D_80129608 = sp20.num_assets;  // total number of fx assets
  D_800D7B00 = n64HeapAlloc(sp20.num_assets * sizeof(UnkStruct_40));
  for (i = 0; i < D_80129608; i++) {
    D_800D7B00[i].unk0 = 0;
    D_800D7B00[i].unk4 = NULL;
  }
}

// identical to the function above
// unused
void func_800A9EF0(void *arg0, void *arg1) {
  UnkStruct_42 sp20;
  s32 i;

  D_80129600 = arg0;
  D_80129604 = arg1;
  func_800ABFF0(D_80129600, &sp20, sizeof(UnkStruct_42));
  D_80129608 = sp20.num_assets;
  D_800D7B00 = n64HeapAlloc(sp20.num_assets * sizeof(UnkStruct_40));
  for (i = 0; i < D_80129608; i++) {
    D_800D7B00[i].unk0 = 0;
    D_800D7B00[i].unk4 = NULL;
  }
}

static s32 func_800A9F9C(void *rom_addr, s32 compressed_len, void *ram_addr, s32 decompressed_len, s32 is_compressed) {
  s32 unused[2];
  void *compressed_data;
  u32 returned_decompresed_len;

  switch (is_compressed) {
  case FALSE:
    func_800ABFF0(rom_addr, ram_addr, compressed_len);
    break;
  case TRUE:
    compressed_data = n64HeapAlloc(compressed_len);
    func_800ABFF0(rom_addr, compressed_data, compressed_len);
    returned_decompresed_len = decompressed_len;
    func_80080EC8(ram_addr, &returned_decompresed_len, compressed_data, compressed_len);
    n64HeapUnalloc(compressed_data);
    break;
  }
}

s16 func_800AA038(s32 id) {
  UnkStruct_41 sp20;
  UnkStruct_42 sp18;

  func_800ABFF0(D_80129600, &sp18, sizeof(UnkStruct_42));
  if ((id < 0) || (id >= sp18.num_assets)) {
    return -1;
  }
  func_800ABFF0((id * sizeof(UnkStruct_41)) + D_80129600 + sizeof(UnkStruct_42), &sp20, sizeof(UnkStruct_41));
  return sp20.type;
}

// unused
s16 func_800AA0AC(UnkStruct_41 *arg0, s32 id) {
  UnkStruct_42 sp18;

  func_800ABFF0(D_80129600, &sp18, sizeof(UnkStruct_42));
  if ((id < 0) || (id >= sp18.num_assets)) {
    return -1;
  }
  func_800ABFF0((id * sizeof(UnkStruct_41)) + D_80129600 + sizeof(UnkStruct_42), arg0, sizeof(UnkStruct_41));

  /*
    The assembly of the following statement suggests that arg0
    is a pointer to a packed struct (ie, #pragma pack).
  */
  return arg0->type;
}

void *func_800AA134(s32 id) {
  return D_800D7B00[id].unk4;
}

void *func_800AA14C(s32 id) {
  u8 *tmp1;
  u8 *tmp2;
  UnkStruct_41 sp48;
  UnkStruct_40 sp40;
  BaseHeader *temp_v0;

  if ((id < 0) || (id >= D_80129608)) {
    return NULL;
  }

  func_800ABFF0((id * sizeof(UnkStruct_41)) + D_80129600 + sizeof(UnkStruct_42), &sp48, sizeof(UnkStruct_41));

  if (D_800D7B04 != 0) {
    temp_v0 = n64HeapAlloc(D_800D7B70[sp48.type] + sp48.decompressed_len);
    tmp1 = D_80129604 + sp48.offset;
    func_800A9F9C(tmp1, sp48.compressed_len, D_800D7B70[sp48.type] + (u8 *)temp_v0, sp48.decompressed_len, sp48.is_compressed);

    if (D_800D7B08[sp48.type] != NULL) {
      D_800D7B08[sp48.type](temp_v0);
    }

    if (D_800D7B3C[sp48.type] != NULL) {
      D_800D7B3C[sp48.type](temp_v0);
    }

    temp_v0->id = -1;
    temp_v0->unk4 = 0;

    D_800D7B00[id].unk4 = temp_v0;

    return temp_v0;
  }

  if (D_800D7B00[id].unk0 != 0) {
    D_800D7B00[id].unk0++;

    if (D_800D7B3C[sp48.type] != NULL) {
      D_800D7B3C[sp48.type](sp40.unk4);
    }

    return D_800D7B00[id].unk4;
  }

  temp_v0 = n64HeapAlloc(D_800D7B70[sp48.type] + sp48.decompressed_len);
  tmp2 = D_80129604 + sp48.offset;
  func_800A9F9C(tmp2, sp48.compressed_len, D_800D7B70[sp48.type] + (u8 *)temp_v0, sp48.decompressed_len, sp48.is_compressed);

  if (D_800D7B08[sp48.type] != NULL) {
    D_800D7B08[sp48.type](temp_v0);
  }

  if (D_800D7B3C[sp48.type] != NULL) {
    D_800D7B3C[sp48.type](temp_v0);
  }

  temp_v0->id = id;
  temp_v0->unk4 = 0;

  D_800D7B00[id].unk0 = 1;
  D_800D7B00[id].unk4 = temp_v0;

  return temp_v0;
}

// static
s32 func_800AA3DC(s32 id) {
  return D_800D7B00[id].unk0;
}

static s32 func_800AA3F4(s32 id) {
  D_800D7B00[id].unk0--;
  if (D_800D7B00[id].unk0 != 0) {
    return 0;
  } else {
    n64HeapUnalloc(D_800D7B00[id].unk4);
    D_800D7B00[id].unk4 = NULL;
    return 1;
  }
}

// unused
void func_800AA470(s32 id) {
  s32 unused[4];
  void *sp1C;

  if (D_800D7B00[id].unk0 == 0) {
    return;
  }

  sp1C = D_800D7B00[id].unk4;
  switch (func_800AA038(id)) {
  case 0:
  case 1:
  case 3:
  case 4:
    func_800AA3F4(id);
    break;
  case 2:
    func_800AA874(sp1C);
    break;
  case 5:
    func_800AB5E0(sp1C);
    break;
  case 6:
    func_800AB934(sp1C);
    break;
  }
}

// unused
void func_800AA514(void) {
  s32 i;

  for (i = 0; i < D_80129608; i++) {
    if (D_800D7B00[i].unk0 != 0) {
      n64HeapUnalloc(D_800D7B00[i].unk4);
      D_800D7B00[i].unk0 = 0;
      D_800D7B00[i].unk4 = NULL;
    }
  }
}

static void func_800AA5A8(void *addr) {
  UnkStruct_43 *obj = addr;

  OFFSET_TO_PTR(obj->unk8.unk4, addr, 0x8);
}

static s32 func_800AA5BC(void *addr) {
  UnkStruct_43 *obj = addr;

  return 0;
}

void func_800AA5C8(UnkStruct_43 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj);
    return;
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AA608(void *addr) {
  UnkStruct_44 *obj = addr;

  OFFSET_TO_PTR(obj->unk8.unk8, addr, 0x8);
  OFFSET_TO_PTR(obj->unk8.unkC, addr, 0x8);
}

static s32 func_800AA62C(void *addr) {
  UnkStruct_44 *obj = addr;

  return 0;
}

void func_800AA638(UnkStruct_44 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj);
    return;
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AA678(void *addr) {
  UnkStruct_46 *obj = addr;
  Gfx **p_gdl;
  s32 i;
  UnkStruct_47 *lst;

  OFFSET_TO_PTR(obj->unk10.unkC, addr, 0x10);
  OFFSET_TO_PTR(obj->unk10.unk10, addr, 0x10);
  OFFSET_TO_PTR(obj->unk10.unk1C, addr, 0x10);

  p_gdl = obj->unk10.unkC;
  for (i = obj->unk10.unk4; i != 0; i--, p_gdl++) {
    OFFSET_TO_PTR(*p_gdl, addr, 0x10);
  }

  if ((intptr_t)obj->unk10.unk18 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk18, addr, 0x10);
    OFFSET_TO_PTR(obj->unk10.unk18->unk4, addr, 0x10);
    OFFSET_TO_PTR(obj->unk10.unk18->unk8, addr, 0x10);

    lst = obj->unk10.unk18->unk8;
    for (i = obj->unk10.unk18->unk0; i != 0; i--, lst++) {
      if (lst->unk0 > 1) {
        OFFSET_TO_PTR(lst->unk4, addr, 0x10);
      }
    }
  }
}

static s32 func_800AA864(void *addr) {
  UnkStruct_46 *obj = addr;

  obj->unk8 = NULL;
  obj->unkC = NULL;
  return 0;
}

void func_800AA874(UnkStruct_46 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj);
    return;
  }

  if ((func_800AA3DC(obj->basehdr.id) != 0) && FALSE) {}

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AA8C8(void *addr) {
  UnkStruct_39 *obj = addr;
}

static s32 func_800AA8D0(void *addr) {
  UnkStruct_39 *obj = addr;

  return 0;
}

void func_800AA8DC(UnkStruct_39 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj);
    return;
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AA91C(void *addr) {
  UnkStruct_45 *obj = addr;

  obj->unk10.unk1C = NULL;
  OFFSET_TO_PTR(obj->unk10.unk18, addr, 0x10);
}

static s32 func_800AA934(void *addr) {
  UnkStruct_45 *obj = addr;

  return 0;
}

void func_800AA940(UnkStruct_45 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj);
    return;
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AA980(void *addr) {
  UnkStruct_48 *obj = addr;
  UnkStruct_49 *lst;
  s32 i;

  if ((intptr_t)obj->unk10.unk18 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk18, addr, 0x10);

    lst = obj->unk10.unk18;
    for (i = obj->unk10.unk0; i != 0; i--, lst++) {
      OFFSET_TO_PTR(lst->unk4, addr, 0x10);
    }
  }
  if ((intptr_t)obj->unk10.unk20 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk20, addr, 0x10);
  }
  if ((intptr_t)obj->unk10.unk1C != 0) {
    OFFSET_TO_PTR(obj->unk10.unk1C, addr, 0x10);
    func_800ABAB8(obj->unk10.unk1C, (u8 *)addr + 0x10);
  }
  if ((intptr_t)obj->unk10.unk28 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk28, addr, 0x10);
  }
  if ((intptr_t)obj->unk10.unk2C != 0) {
    OFFSET_TO_PTR(obj->unk10.unk2C, addr, 0x10);
  }
  if ((intptr_t)obj->unk10.unk30 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk30, addr, 0x10);
  }
  if ((intptr_t)obj->unk10.unk34 != 0) {
    OFFSET_TO_PTR(obj->unk10.unk34, addr, 0x10);
  }
  OFFSET_TO_PTR(obj->unk10.unk38, addr, 0x10);

  obj->basehdr.unk4 = 0;
}

static s32 func_800AAB0C(void *addr) {
  s32 i, j;
  s32 temp_t0;
  s32 var_a1;
  intptr_t var_a3;
  UnkStruct_48 *obj = addr;
  UnkStruct_49 *var_v1;
  UnkStruct_49 **var_v0;
  UnkStruct_45 *temp_a0;
  UnkStruct_39 **var_v1_2;
  UnkStruct_46 **var_t0;
  UnkStruct_62 *var_v0_2;
  UnkStruct_44 **var_v1_3;
  UnkStruct_39 **var_v0_3;
  UnkStruct_46 **var_t2;
  UnkStruct_59 *var_v1_6;
  Vtx *var_v0_4;
  Vtx *var_v1_5;

  temp_t0 = obj->unk10.unk0;
  var_v1 = obj->unk10.unk18;
  var_a3 = 0;
  for (i = 0; i < temp_t0; i++, var_v1++) {
    var_v0 = var_v1->unk4;
    var_a3 += sizeof(UnkStruct_63);
    for (j = var_v1->unk3; j != 0; j--, var_v0++) {
      *var_v0 = obj->unk10.unk18 + (intptr_t)*var_v0;
    }
  }

  temp_a0 = obj->unk10.unk24;
  if ((intptr_t)obj->unk10.unk24 != -1) {
    obj->unk10.unk24 = func_800AA14C((intptr_t)temp_a0);
    var_a3 += sizeof(UnkStruct_64);
  } else {
    obj->unk10.unk24 = NULL;
  }

  if (obj->unk10.unk28 != NULL) {
    var_v1_2 = obj->unk10.unk28;
    for (i = obj->unk10.unk4; i != 0; i--, var_v1_2++) {
      *var_v1_2 = func_800AA14C((intptr_t)*var_v1_2);
      var_a3 += sizeof(UnkStruct_65);
    }
  }

  if (obj->unk10.unk2C != NULL) {
    var_t0 = obj->unk10.unk2C;
    for (i = obj->unk10.unk8; i != 0; i--, var_t0++) {
      *var_t0 = func_800AA14C((intptr_t)*var_t0);
      if ((*var_t0)->unk10.unk18 != NULL) {
        var_a3 = (var_a3 + 7) & ~7;
        var_a3 += (intptr_t)(*var_t0)->unk10.unk14 * sizeof(Vtx);
      }

      var_a1 = 0;
      var_v0_2 = (*var_t0)->unk10.unk1C;
      for (j = (*var_t0)->unk10.unk4; j != 0; j--, var_v0_2++) {
        /*
          The assembly of the following statement suggests that var_v0_2
          is a pointer to a packed struct (ie, #pragma pack).
        */
        if (var_v0_2->unk0 & 3) {
          var_a1 |= 1;
        }
      }

      if (var_a1 != 0) {
        (*var_t0)->unk8 = (void *)-1;
        (*var_t0)->unkC = (void *)-1;
        var_a3 += sizeof(UnkStruct_66) + sizeof(UnkStruct_67);
      } else {
        (*var_t0)->unk8 = NULL;
        (*var_t0)->unkC = NULL;
      }
    }
  }

  if (obj->unk10.unk30 != NULL) {
    var_v1_3 = obj->unk10.unk30;
    for (i = obj->unk10.unkC; i != 0; i--, var_v1_3++) {
      *var_v1_3 = func_800AA14C((intptr_t)*var_v1_3);
    }
  }

  obj->unk8 = n64HeapAlloc(var_a3);

  var_v1 = obj->unk10.unk18;
  var_a3 = (intptr_t)obj->unk8;
  for (i = obj->unk10.unk0; i != 0; i--, var_v1++) {
    var_v1->unkC = (UnkStruct_63 *)var_a3;
    var_a3 += sizeof(UnkStruct_63);

    var_v1->unkC->unk140[0] = 0;
    var_v1->unkC->unk140[1] = 0;
    var_v1->unkC->unk140[2] = 0;
    var_v1->unkC->unk14C[0] = 0;
    var_v1->unkC->unk14C[1] = 0;
    var_v1->unkC->unk14C[2] = 0;
    var_v1->unkC->unk158[0] = 0;
    var_v1->unkC->unk158[1] = 0;
    var_v1->unkC->unk158[2] = 0;
    var_v1->unkC->unk164[0] = 0;
    var_v1->unkC->unk164[1] = 0;
    var_v1->unkC->unk164[2] = 0;
  }

  if (obj->unk10.unk24 != NULL) {
    obj->unk10.unk24->unk10.unk1C = (UnkStruct_64 *)var_a3;
    var_a3 += sizeof(UnkStruct_64);
  }

  if (obj->unk10.unk28 != NULL) {
    var_v0_3 = obj->unk10.unk28;
    for (i = obj->unk10.unk4; i != 0; i--, var_v0_3++) {
      (*var_v0_3)->unk8.unk10 = (UnkStruct_65 *)var_a3;
      var_a3 += sizeof(UnkStruct_65);
    }
  }

  if (obj->unk10.unk2C != NULL) {
    var_t2 = obj->unk10.unk2C;
    for (i = obj->unk10.unk8; i != 0; i--, var_t2++) {
      if ((*var_t2)->unk10.unk18 != NULL) {
        var_a1 = (intptr_t)(*var_t2)->unk10.unk14;
        var_a3 = (var_a3 + 7) & ~7;
        (*var_t2)->unk10.unk14 = (Vtx *) var_a3;
        var_v0_4 = (*var_t2)->unk10.unk10;
        var_v1_5 = (Vtx *) var_a3;
        for (j = var_a1; j != 0; j--, var_v0_4++, var_v1_5++) {
          *var_v1_5 = *var_v0_4;
        }
        var_a3 += var_a1 * sizeof(Vtx);
      }

      if ((*var_t2)->unk8 != NULL) {
        (*var_t2)->unk8 = (UnkStruct_66 *)var_a3;
        var_a3 += sizeof(UnkStruct_66);
      }

      if ((*var_t2)->unkC != NULL) {
        (*var_t2)->unkC = (UnkStruct_67 *)var_a3;
        var_a3 += sizeof(UnkStruct_67);
      }
    }
  }

  if (obj->unk10.unk1C != NULL) {
    func_800ABD64(obj->unk10.unk1C);
    var_v1_6 = obj->unk10.unk1C->unk14;
    for (i = obj->unk10.unk1C->unk4; i != 0; i--, var_v1_6++) {
      if ((intptr_t)var_v1_6->unk0 == -1) {
        var_v1_6->unk0 = NULL;
      } else {
        var_v1_6->unk0 = obj->unk10.unk18 + (intptr_t)var_v1_6->unk0;
      }
    }
  }

  return 0;
}

void func_800AB5E0(UnkStruct_48 *obj) {
  UnkStruct_39 **p_obj1;
  UnkStruct_46 **p_obj2;
  UnkStruct_44 **p_obj3;
  s32 i;

  if (obj->unk10.unk24 != NULL) {
    func_800AA940(obj->unk10.unk24);
  }
  if (obj->unk10.unk28 != NULL) {
    p_obj1 = obj->unk10.unk28;
    for (i = obj->unk10.unk4; i != 0; i--) {
      func_800AA8DC(*p_obj1);
      p_obj1++;
    }
  }
  if (obj->unk10.unk2C != NULL) {
    p_obj2 = obj->unk10.unk2C;
    for (i = obj->unk10.unk8; i != 0; i--) {
      func_800AA874(*p_obj2);
      p_obj2++;
    }
  }
  if (obj->unk10.unk30 != NULL) {
    p_obj3 = obj->unk10.unk30;
    for (i = obj->unk10.unkC; i != 0; i--) {
      func_800AA638(*p_obj3);
      p_obj3++;
    }
  }

  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj->unk8);
    n64HeapUnalloc(obj);
    return;
  }

  if (func_800AA3DC(obj->basehdr.id) == 1) {
    n64HeapUnalloc(obj->unk8);
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AB700(void *addr) {
  UnkStruct_50 *obj = addr;
  UnkStruct_51 *lst_1;
  UnkStruct_52 *lst_2;
  UnkStruct_53 *lst_3;
  s32 i, j;
  s32 tmp_1, tmp_2;

  OFFSET_TO_PTR(obj->unk20.unk8, addr, 0x20);

  tmp_1 = obj->unk20.unk4;
  lst_1 = obj->unk20.unk8;
  for (i = 0; i < tmp_1; i++, lst_1++) {
    lst_1->unk20 = obj;
    OFFSET_TO_PTR(lst_1->unk1C, addr, 0x20);

    tmp_2 = lst_1->unk18;
    lst_2 = lst_1->unk1C;
    for (j = 0; j < tmp_2; j++, lst_2++) {
      OFFSET_TO_PTR(lst_2->unkC, addr, 0x20);

      lst_3 = lst_2->unkC;
      for (; ; lst_3++) {
        OFFSET_TO_PTR(lst_3->unk4, addr, 0x20);
        if (lst_3->unk0 == lst_2->unk4) {
          break;
        }
      }
    }
  }
}

static s32 func_800AB794(void *addr) {
  UnkStruct_50 *obj = addr;
  UnkStruct_51 *var_t2;
  UnkStruct_52 *var_a3;
  UnkStruct_53 *var_v0;
  s32 var_a1;
  s32 var_t3;
  s32 i, j, k;
  s32 temp_a0;
  f32 *var_a1_2;
  s32 temp_v1;
  f32 *var_a0;
  f32 *temp_v0;

  obj->unk14 = 0;
  obj->unk18 = 1.0;
  var_t3 = obj->unk20.unk4;
  var_t2 = obj->unk20.unk8;
  var_a1 = 0;
  for (i = 0; i < var_t3; i++, var_t2++) {
    var_t2->unk20 = obj;

    temp_a0 = var_t2->unk18;
    var_a3 = var_t2->unk1C;
    for (j = 0; j < temp_a0; j++, var_a3++) {
      var_a3->unk6 = 1;
      var_a3->unk8 = var_a3->unkC;
      var_v0 = var_a3->unk8;
      for (; ; var_v0++) {
        if (var_v0->unk0 == var_a3->unk4) {
          break;
        }
      }
      var_a1 += 4 * sizeof(f32);
    }

    var_t2->unk4 = 0;
    var_t2->unk8 = 0;
  }

  var_a1_2 = n64HeapAlloc(var_a1);
  var_t2 = obj->unk20.unk8;
  for (i = var_t3; i != 0; i--, var_t2++) {
    var_a3 = var_t2->unk1C;
    for (j = var_t2->unk18; j != 0; j--, var_a3++) {
      var_a3->unk10 = var_a1_2;

      temp_v1 = var_a3->unkC->unk2;
      var_a0 = var_a3->unkC->unk4;
      temp_v0 = var_a1_2;
      for (k = 0; k < 4; k++) {
        if (temp_v1 & 1) {
          *temp_v0 = *var_a0;
          var_a0++;
        } else {
          *temp_v0 = 0.0;
        }
        temp_v1 >>= 1;
        temp_v0++;
      }
      var_a1_2 += 4;
    }
  }

  obj->unk8 = NULL;
  obj->unkC = NULL;
  return 0;
}

void func_800AB934(UnkStruct_50 *obj) {
  if (obj->basehdr.id == -1) {
    n64HeapUnalloc(obj->unk20.unk8->unk1C->unk10);
    n64HeapUnalloc(obj);
    return;
  }

  if (func_800AA3DC(obj->basehdr.id) == 1) {
    n64HeapUnalloc(obj->unk20.unk8->unk1C->unk10);
  }

  func_800AA3F4(obj->basehdr.id);
}

static void func_800AB9B4(UnkStruct_56 *obj, void *addr) {
  UnkStruct_57 *temp_v0_2;
  UnkStruct_58 *temp_v0_3;

  OFFSET_TO_PTR(obj->unk4, addr, 0);

  if ((intptr_t)obj->unk8 != 0) {
    OFFSET_TO_PTR(obj->unk8, addr, 0);
  }

  if ((intptr_t)obj->unkC != 0) {
    OFFSET_TO_PTR(obj->unkC, addr, 0);
  }

  switch (obj->unk2) {
  case 0:
    temp_v0_2 = obj->unk4;
    if ((intptr_t)temp_v0_2->unk10 != 0) {
      OFFSET_TO_PTR(temp_v0_2->unk10, addr, 0);
    }
    break;
  case 1:
    temp_v0_3 = obj->unk4;
    OFFSET_TO_PTR(temp_v0_3->unk0, addr, 0);
    OFFSET_TO_PTR(temp_v0_3->unk4, addr, 0);
    OFFSET_TO_PTR(temp_v0_3->unk8, addr, 0);
    if ((intptr_t)temp_v0_3->unkC != 0) {
      OFFSET_TO_PTR(temp_v0_3->unkC, addr, 0);
    }
    if ((intptr_t)temp_v0_3->unk10 != 0) {
      OFFSET_TO_PTR(temp_v0_3->unk10, addr, 0);
    }
    if ((intptr_t)temp_v0_3->unk14 != 0) {
      OFFSET_TO_PTR(temp_v0_3->unk14, addr, 0);
    }
    if ((intptr_t)temp_v0_3->unk24 != 0) {
      OFFSET_TO_PTR(temp_v0_3->unk24, addr, 0);
    }
    break;
  }
}

static void func_800ABAB8(UnkStruct_54 *obj, void *addr) {
  s32 i;
  UnkStruct_59 *lst_1;
  UnkStruct_56 *lst_2;
  UnkStruct_55 *lst_3;
  UnkStruct_60 *lst_4;

  if ((intptr_t)obj->unk10 != 0) {
    OFFSET_TO_PTR(obj->unk10, addr, 0);
  }
  if ((intptr_t)obj->unk14 != 0) {
    OFFSET_TO_PTR(obj->unk14, addr, 0);
  }
  if ((intptr_t)obj->unk18 != 0) {
    OFFSET_TO_PTR(obj->unk18, addr, 0);
  }
  if ((intptr_t)obj->unk1C != 0) {
    OFFSET_TO_PTR(obj->unk1C, addr, 0);
  }

  lst_1 = obj->unk14;
  for (i = obj->unk4; i != 0; i--, lst_1++) {
    OFFSET_TO_PTR(lst_1->unk4, addr, 0);
  }

  lst_2 = obj->unk10;
  for (i = obj->unk0; i != 0; i--, lst_2++) {
    func_800AB9B4(lst_2, addr);
  }

  lst_3 = obj->unk18;
  for (i = obj->unk8; i != 0; i--, lst_3++) {
    if (lst_3->unk10 != 0) {
      OFFSET_TO_PTR(lst_3->unk14, addr, 0);
    }
  }

  lst_4 = obj->unk1C;
  for (i = obj->unkC; i != 0; i--, lst_4++) {
    OFFSET_TO_PTR(lst_4->unk0, addr, 0);
    OFFSET_TO_PTR(lst_4->unk4, addr, 0);
    lst_4->unk8 = 0;
  }
}

static void func_800ABD64(UnkStruct_54 *obj) {
  UnkStruct_55 *lst;
  s32 i, j;
  void **pp;

  lst = obj->unk18;
  for (i = obj->unk8; i != 0; i--, lst++) {
    pp = lst->unk14;
    for (j = lst->unk10; j != 0; j--, pp++) {
      *pp = func_800AA14C((intptr_t)*pp);
    }
  }
}

// unused
s32 func_800ABDDC(s32 id) {
  return *(s32 *)((u8 *)func_800AA14C(id) + 0xC);
}
