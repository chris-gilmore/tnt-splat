#ifndef _03C220_H_
#define _03C220_H_

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
  /* 0x0  */ UnkStruct_14   unk0[4];
  /* 0x28 */ UnkStruct_0   *unk28;
  /* 0x2C */ u8             unk2C;
  /* 0x2E */ s16            unk2E;  // dsdx
  /* 0x30 */ s16            unk30;  // dtdy
  /* 0x34 */ void         (*unk34)(UnkStruct_8 *);
  /* 0x38 */ u8             unk38;
  /* 0x39 */ u8             is_transparent;  // boolean; render mode: xlu (transparent) or opa (opaque)
  /* 0x3A */ u8             alpha;
} UnkStruct_22; // 0x3B bytes

extern void   func_8007635C(void);
extern void   func_800763B4(void);
extern void   func_800763EC(u32);
extern void   func_8007641C(UnkStruct_14 *, UnkStruct_23 *);
extern void   func_80076458(UnkStruct_14 *, UnkStruct_23 *);

#endif /* !_03C220_H_ */
