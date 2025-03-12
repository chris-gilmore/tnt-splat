#ifndef _072080_H_
#define _072080_H_

typedef struct {
  /* 0x0  */ void         *addr[2];
  /* 0x8  */ u32           len;
  /* 0xC  */ u8            type;
  /* 0x10 */ OSMesgQueue  *retQueue;
} IoMsg; // 0x14 bytes

extern void   func_800ABFF0(void *, void *, u32);
extern void   func_800AC06C(OSId, OSPri);
extern void   func_800AC0F8(void);
extern u32    func_800AC1A8(void *, void *, u32);
extern u32    func_800AC22C(void *, void *, u32);

#endif /* !_072080_H_ */
