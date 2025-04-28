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
  /* 0x0    */ s32   unk0[4][24][16];
  /* 0x1800 */ u8    unk1800;
} UnkStruct_38; // 0x1804 bytes

extern void   func_8007635C(void);
extern void   func_800763B4(void);
extern void   func_800763EC(u32);
extern void   func_8007641C(UnkStruct_14 *, UnkStruct_23 *);
extern void   func_80076458(UnkStruct_14 *, UnkStruct_23 *);

#endif /* !_03C220_H_ */
