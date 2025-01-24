#ifndef _MINOS_H_
#define _MINOS_H_

#define setPointAngle(pa, _x, _y, _angle) \
  (pa).p.x = (_x); \
  (pa).p.y = (_y); \
  (pa).angle = (_angle)

typedef struct {
  /* 0x0 */ Point   p;
  /* 0x4 */ u16     angle;
} PointAngle; // 0x6 bytes

typedef struct {
  /* 0x0  */ PointAngle   unk0;
  /* 0x6  */ PointAngle   unk6;
  /* 0xC  */ PointAngle   unkC;
} UnkStruct_8; // 0x12 bytes

typedef struct {
  /* 0x0 */ PointAngle   unk0;
  /* 0x6 */ Point        p;
} UnkStruct_14; // 0xA bytes

typedef struct {
  /* 0x0 */ s32   unk0;
  /* 0x4 */ s32   unk4;
} UnkStruct_23; // 0x8 bytes

typedef struct {
  /* 0x0  */ s8            *unk0;        // &(Mino *)->unk24
  /* 0x4  */ s8            *unk4;        // &(Mino *)->unk{B0,F0}
  /* 0x8  */ u8             pad8[0x1C];
  /* 0x24 */ UnkStruct_23   unk24[4];
} UnkStruct_24; // 0x44 bytes

typedef struct UnkStruct_15_s {
  /* 0x0  */ u8             pad0[0x14];
  /* 0x14 */ UnkStruct_24   unk14;
  /* 0x58 */ void         (*unk58)(struct UnkStruct_15_s *);
} UnkStruct_15; // 0x5C bytes

typedef struct {
  /* 0x0  */ UnkStruct_14   unk0[4];
  /* 0x28 */ UnkStruct_15  *unk28;
  /* 0x2C */ u8             unk2C;
  /* 0x2E */ s16            unk2E;  // dsdx
  /* 0x30 */ s16            unk30;  // dtdy
  /* 0x34 */ void         (*unk34)(UnkStruct_8 *);
  /* 0x38 */ u8             unk38;
  /* 0x39 */ u8             is_transparent;  // boolean; render mode: xlu (transparent) or opa (opaque)
  /* 0x3A */ u8             alpha;
} UnkStruct_22; // 0x3B bytes

typedef union {
  s16   s;
  struct {
    u8 hi;
    u8 lo;
  } c;
} cu;

typedef struct {
  /* 0x0   */ u8      unk0;
  /* 0x1   */ u8      unk1;         // update flag
  /* 0x2   */ u8      unk2;
  /* 0x4   */ Color   unk4;
  /* 0x10  */ Color   unk10;
  /* 0x1C  */ u8      unk1C;        // mino color alpha
  /* 0x1D  */ s8      unk1D;
  /* 0x1E  */ u8      unk1E;        // mino color alpha
  /* 0x20  */ cu      unk20;
  /* 0x22  */ s16     unk22;
  /* 0x24  */ s8      unk24;
  /* 0x25  */ u8      pad25[0x8B];
  /* 0xB0  */ s8      unkB0;
  /* 0xB1  */ u8      padB1[0x3F];
  /* 0xF0  */ s8      unkF0;
  /* 0xF1  */ u8      padF1[0x3F];
  /* 0x130 */ s8     *unk130;
  /* 0x134 */ u8      pad134[0x4];
} Mino; // 0x138 bytes

typedef struct {
  /* 0x0  */ u8      pattern;  // bit1 is "scale set"
  /* 0x2  */ u16     unk2;     // (unk2 >> 8) is unitSize (11, 10, or 8)
  /* 0x4  */ u16     unk4;
  /* 0x6  */ u16     scale;
  /* 0x8  */ u16     unk8;
  /* 0xA  */ Point   unkA;
  /* 0xE  */ Point   unkE;
  /* 0x12 */ Point   unk12;
  /* 0x16 */ Point   unk16;
  /* 0x1A */ Point   unk1A;
  /* 0x1E */ u8      unk1E;  // see Minos_SetVtxTransform()
  /* 0x20 */ Vtx     unk20[4];
} UnkStruct_0; // 0x60 bytes
// TODO: Rename this to Minos

extern UnkStruct_0 *D_8011FC10;

extern void   Minos_Mino_Render(Mino *, UnkStruct_8 *);
extern void   Minos_800702e4_nineliner(Mino *);
extern void   Minos_80070398_fourteenliner(Mino *, Mino *);
extern void   Minos_80070528_Morph(Mino *);
extern void   Minos_80070818_oneliner_sets_arg0_0x130_to_arg1(Mino *, s8 *);
extern void   Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(Mino *, Color *);
extern void   Minos_80070860_fortyliner(Mino *, Color *, s32);
extern void   Minos_800709d8_threeliner_sets_arg0_1c_1e_1d(Mino *, u8);
extern void   Minos_800709EC(Mino *, u8, s32);
extern void   Minos_80070a34_twentyliner(void);
extern void   Minos_80070c40_twoliner_set_OR_1(u16);
extern void   Minos_80070c70_threeliner_set_OR_8(s16, s16);
extern void   Minos_80070cb8_threeliner_set_OR_4(s16, s16);
extern void   Minos_SetScale(u16);
extern void   Minos_SetAlpha(u8);
extern void   Minos_Init(UnkStruct_0 *, void *);
extern void   Minos_Deinit_doesnothing(UnkStruct_0 *);
extern void   Minos_BeginRender(UnkStruct_0 *);
extern void   Minos_EndRender(UnkStruct_0 *);
extern void   Minos_80070fd8_notcalled_q(PointAngle *, Point *, u16);
extern void   Minos_8007104c_fiveliner_nuts(Point *, s16, s16);
extern void   Minos_80071100_fiveliner_nuts2(Point *, PointAngle *);
extern void   Minos_SetVtxTransform(u8);

#endif /* !_MINOS_H_ */
