#ifndef _06FFD0_H_
#define _06FFD0_H_

#define OFFSET_TO_PTR(offset2ptr, base_addr, base_offset) (offset2ptr) = (void *)((u8 *)(base_addr) + (s32)(base_offset) + *(intptr_t *)&(offset2ptr))

typedef struct {
  /* 0x0 */ s32   id;
  /* 0x4 */ s32   unk4;
} BaseHeader; // 0x8 bytes


typedef struct {
  /* 0x0 */ s32   unk0;
  /* 0x4 */ u8   *unk4;
} UnkStruct_70; // 0x8 bytes

typedef struct {
  /* 0x0 */ BaseHeader     basehdr;  // .id = 0

  /* 0x8 */ UnkStruct_70   unk8;
} UnkStruct_43; // 0x10 bytes


// gSPTexture related
typedef struct {
  /* 0x0 */ s16    unk0;
  /* 0x2 */ s16    unk2;  // sc
  /* 0x4 */ s16    unk4;  // tc
  /* 0x6 */ u8     unk6;
  /* 0x7 */ u8     unk7;  // level
  /* 0x8 */ Gfx   *unk8;  // displaylist
  /* 0xC */ void  *unkC;  // image data
} UnkStruct_71; // 0x10 bytes

typedef struct {
  /* 0x0  */ BaseHeader     basehdr;  // .id = 1

  /* 0x8  */ UnkStruct_71   unk8;
} UnkStruct_44; // 0x18 bytes


#pragma pack(1)
typedef struct {
  /* 0x0  */ s32   unk0;
  /* 0x4  */ f32   unk4;
  /* 0x8  */ f32   unk8;
  /* 0xC  */ f32   unkC;
  /* 0x10 */ f32   unk10;
} UnkStruct_62; // 0x14 bytes
#pragma pack(0)

typedef struct {
  /* 0x0 */ LookAt   unk0[2];
} UnkStruct_66; // 0x40 bytes

typedef struct {
  /* 0x0 */ u8   pad0[0x20];
} UnkStruct_67; // 0x20 bytes

typedef struct {
  /* 0x0 */ s32   unk0;
  /* 0x4 */ u8   *unk4;
} UnkStruct_47; // 0x8 bytes

typedef struct {
  /* 0x0 */ s32            unk0;  // cnt of unk8
  /* 0x4 */ u8            *unk4;
  /* 0x8 */ UnkStruct_47  *unk8;  // list
} UnkStruct_61; // 0xC bytes

typedef struct {
  /* 0x0  */ f32            unk0;
  /* 0x4  */ s32            unk4;   // cnt of unkC and of unk1C
  /* 0x8  */ f32            unk8;
  /* 0xC  */ Gfx          **unkC;   // displaylist list
  /* 0x10 */ Vtx           *unk10;  // vertex list
  /* 0x14 */ Vtx           *unk14;  // cnt of unk10, then set to a ptr
  /* 0x18 */ UnkStruct_61  *unk18;
  /* 0x1C */ UnkStruct_62  *unk1C;  // list
} UnkStruct_72; // 0x20 bytes

typedef struct {
  /* 0x0  */ BaseHeader     basehdr;  // .id = 2
  /* 0x8  */ UnkStruct_66  *unk8;
  /* 0xC  */ UnkStruct_67  *unkC;

  /* 0x10 */ UnkStruct_72   unk10;
} UnkStruct_46; // 0x30 bytes


typedef struct {
  /* 0x0 */ Mtx   unk0[2];
} UnkStruct_64; // 0x80 bytes

typedef struct {
  /* 0x0  */ f32            unk0;
  /* 0x4  */ f32            unk4;   // fovy
  /* 0x8  */ f32            unk8;   // near
  /* 0xC  */ f32            unkC;   // far
  /* 0x10 */ f32            unk10;
  /* 0x14 */ f32            unk14;  // aspect
  /* 0x18 */ Vp            *unk18;  // viewport
  /* 0x1C */ UnkStruct_64  *unk1C;
} UnkStruct_73; // 0x20 bytes

typedef struct {
  /* 0x0  */ BaseHeader     basehdr;  // .id = 3
  /* 0x8  */ u16            unk8[2];  // perspNorm[2]
  /* 0xC  */ s32            unkC;

  /* 0x10 */ UnkStruct_73   unk10;
} UnkStruct_45; // 0x30 bytes


typedef struct {
  /* 0x0 */ Light   lights[2];
} UnkStruct_65; // 0x20 bytes

typedef struct {
  /* 0x0  */ f32            unk0;
  /* 0x4  */ f32            red;
  /* 0x8  */ f32            green;
  /* 0xC  */ f32            blue;
  /* 0x10 */ UnkStruct_65  *unk10;
} UnkStruct_74; // 0x14 bytes

typedef struct {
  /* 0x0 */  BaseHeader    basehdr;  // .id = 4

  /* 0x8 */ UnkStruct_74   unk8;
} UnkStruct_39; // 0x1C bytes


typedef struct UnkStruct_49 UnkStruct_49;

typedef struct {
  /* 0x0 */ f32   unk0;
  /* 0x4 */ s16   unk4;
  /* 0x4 */ s16   unk6;
} UnkStruct_68; // 0x8 bytes

typedef struct {
  /* 0x0  */ u8   *unk0;
  /* 0x4  */ u8   *unk4;
  /* 0x8  */ u8   *unk8;
  /* 0xC  */ u8   *unkC;
  /* 0x10 */ u8   *unk10;
  /* 0x14 */ u8   *unk14;
  /* 0x18 */ s32   unk18;
  /* 0x1C */ s32   unk1C;
  /* 0x20 */ s32   unk20;
  /* 0x24 */ u8   *unk24;
} UnkStruct_58; // 0x28 bytes

typedef struct {
  /* 0x0  */ s32   unk0;
  /* 0x4  */ s32   unk4;
  /* 0x8  */ s32   unk8;
  /* 0xC  */ s32   unkC;
  /* 0x10 */ u8   *unk10;
} UnkStruct_57; // 0x14 bytes

typedef struct {
  /* 0x0 */ s16    unk0;
  /* 0x2 */ s16    unk2;  // 0 or 1
  /* 0x4 */ void  *unk4;  // UnkStruct_57 or UnkStruct_58
  /* 0x8 */ u8    *unk8;
  /* 0xC */ u8    *unkC;
} UnkStruct_56; // 0x10 bytes

typedef struct {
  /* 0x0 */ UnkStruct_49  *unk0;
  /* 0x4 */ u8            *unk4;
} UnkStruct_59; // 0x8 bytes

typedef struct {
  /* 0x0  */ s32    unk0;
  /* 0x4  */ s32    unk4;
  /* 0x8  */ s32    unk8;
  /* 0xC  */ s32    unkC;
  /* 0x10 */ s32    unk10;  // cnt of unk14
  /* 0x14 */ void **unk14;  // list of ids turned into assets
} UnkStruct_55; // 0x18 bytes

typedef struct {
  /* 0x0 */ u8   *unk0;
  /* 0x4 */ u8   *unk4;
  /* 0x8 */ s32   unk8;
} UnkStruct_60; // 0xC bytes

typedef struct {
  /* 0x0  */ s32            unk0;  // cnt of unk10
  /* 0x4  */ s32            unk4;  // cnt of unk14
  /* 0x8  */ s32            unk8;  // cnt of unk18
  /* 0xC  */ s32            unkC;  // cnt of unk1C
  /* 0x10 */ UnkStruct_56  *unk10;
  /* 0x14 */ UnkStruct_59  *unk14;
  /* 0x18 */ UnkStruct_55  *unk18;
  /* 0x1C */ UnkStruct_60  *unk1C;
} UnkStruct_54; // 0x20 bytes

typedef struct {
  /* 0x0   */ Mtx    unk0[2];
  /* 0x80  */ MtxF   unk80;
  /* 0xC0  */ MtxF   unkC0;
  /* 0x100 */ u8     pad100[0x40];
  /* 0x140 */ f32    unk140;
  /* 0x144 */ f32    unk144;
  /* 0x148 */ f32    unk148;
  /* 0x14C */ f32    unk14C;
  /* 0x150 */ f32    unk150;
  /* 0x154 */ f32    unk154;
  /* 0x158 */ f32    unk158;
  /* 0x15C */ f32    unk15C;
  /* 0x160 */ f32    unk160;
  /* 0x164 */ f32    unk164;
  /* 0x168 */ f32    unk168;
  /* 0x16C */ f32    unk16C;
  /* 0x170 */ u8     pad170[0x18];
} UnkStruct_63; // 0x188 bytes

struct UnkStruct_49 {
  /* 0x0  */ u16            unk0;
  /* 0x2  */ u8             unk2;
  /* 0x3  */ u8             unk3;  // cnt of unk4
  /* 0x4  */ UnkStruct_49 **unk4;
  /* 0x8  */ s32            unk8;
  /* 0xC  */ UnkStruct_63  *unkC;
  /* 0x10 */ f32            unk10[12];
}; // 0x40 bytes

typedef struct {
  /* 0x0  */ f32   min;
  /* 0x4  */ f32   max;
  /* 0x8  */ f32   red;
  /* 0xC  */ f32   green;
  /* 0x10 */ f32   blue;
  /* 0x14 */ f32   alpha;
} FogParams; // 0x18 bytes

typedef struct {
  /* 0x0  */ s32            unk0;   // cnt of unk18
  /* 0x4  */ s32            unk4;   // cnt of unk28
  /* 0x8  */ s32            unk8;   // cnt of unk2C
  /* 0xC  */ s32            unkC;   // cnt of unk30
  /* 0x10 */ s32            unk10;
  /* 0x14 */ s32            unk14;  // cnt of unk38
  /* 0x18 */ UnkStruct_49  *unk18;  // list
  /* 0x1C */ UnkStruct_54  *unk1C;
  /* 0x20 */ FogParams     *unk20;
  /* 0x24 */ UnkStruct_45  *unk24;  // id = 3
  /* 0x28 */ UnkStruct_39 **unk28;  // id = 4[unk4]
  /* 0x2C */ UnkStruct_46 **unk2C;  // id = 2[unk8]
  /* 0x30 */ UnkStruct_44 **unk30;  // id = 1[unkC]
  /* 0x34 */ UnkStruct_68  *unk34;  // list
  /* 0x38 */ s16           *unk38;  // [unk14]
} UnkStruct_75; // 0x3C bytes

typedef struct {
  /* 0x0  */ BaseHeader     basehdr;  // .id = 5
  /* 0x8  */ u8            *unk8;
  /* 0xC  */ s32            unkC;

  /* 0x10 */ UnkStruct_75   unk10;
} UnkStruct_48; // 0x4C bytes


typedef struct UnkStruct_50 UnkStruct_50;

typedef struct {
  /* 0x0 */ s16   unk0;
  /* 0x2 */ s16   unk2;
  /* 0x4 */ f32  *unk4;
} UnkStruct_53; // 0x8 bytes

typedef struct {
  /* 0x0  */ s32            unk0;
  /* 0x4  */ s16            unk4;
  /* 0x6  */ s16            unk6;
  /* 0x8  */ UnkStruct_53  *unk8;
  /* 0xC  */ UnkStruct_53  *unkC;
  /* 0x10 */ f32           *unk10;
} UnkStruct_52; // 0x14 bytes

typedef struct {
  /* 0x0  */ void          *unk0;   // id turned into an asset
  /* 0x4  */ s32            unk4;
  /* 0x8  */ s32            unk8;
  /* 0xC  */ s32            unkC;   // 0, 1, 2, or 3
  /* 0x10 */ void          *unk10;
  /* 0x14 */ s32            unk14;
  /* 0x18 */ s32            unk18;  // cnt of unk1C
  /* 0x1C */ UnkStruct_52  *unk1C;
  /* 0x20 */ UnkStruct_50  *unk20;
} UnkStruct_51; // 0x24 bytes

typedef struct {
  /* 0x0 */ UnkStruct_48  *unk0;
  /* 0x4 */ s32            unk4;  // cnt of unk8
  /* 0x8 */ UnkStruct_51  *unk8;
} UnkStruct_76; // 0xC bytes

struct UnkStruct_50 {
  /* 0x0  */ BaseHeader     basehdr;  // .id = 6
  /* 0x8  */ UnkStruct_50  *unk8;     // parent node
  /* 0xC  */ UnkStruct_50  *unkC;     // child node
  /* 0x10 */ void          *unk10;    // UnkStruct_32 * ?
  /* 0x14 */ s32            unk14;
  /* 0x18 */ f32            unk18;
  /* 0x1C */ s32            unk1C;

  /* 0x20 */ UnkStruct_76   unk20;
}; // 0x2C bytes


typedef struct {
  /* 0x0 */ s32   num_assets;
  /* 0x4 */ s32   end;
} UnkStruct_42; // 0x8 bytes

#pragma pack(1)
typedef struct {
  /* 0x0 */ s16   type;
  /* 0x2 */ s16   is_compressed;
  /* 0x4 */ s32   compressed_len;
  /* 0x8 */ s32   decompressed_len;
  /* 0xC */ s32   offset;
} UnkStruct_41; // 0x10 bytes
#pragma pack(0)

typedef struct {
  /* 0x0 */ s32    unk0;
  /* 0x4 */ void  *unk4;
} UnkStruct_40; // 0x8 bytes

extern void   func_800A9D50(void);
extern void   func_800A9D60(void);
extern s32    func_800A9D6C(void);
extern void   func_800A9DD8(void);
extern void   func_800A9E44(void *, void *);
extern void   func_800A9EF0(void *, void *);
extern s16    func_800AA038(s32);
extern s16    func_800AA0AC(UnkStruct_41 *, s32);
extern void  *func_800AA134(s32);
extern void  *func_800AA14C(s32);
extern void   func_800AA470(s32);
extern void   func_800AA514(void);
extern void   func_800AA5C8(UnkStruct_43 *);  // 0
extern void   func_800AA638(UnkStruct_44 *);  // 1
extern void   func_800AA874(UnkStruct_46 *);  // 2
extern void   func_800AA8DC(UnkStruct_39 *);  // 4
extern void   func_800AA940(UnkStruct_45 *);  // 3
extern void   func_800AB5E0(UnkStruct_48 *);  // 5
extern void   func_800AB934(UnkStruct_50 *);  // 6
extern s32    func_800ABDDC(s32);

#endif /* !_06FFD0_H_ */
