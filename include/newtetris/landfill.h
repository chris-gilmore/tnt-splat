#ifndef _LANDFILL_H_
#define _LANDFILL_H_

#define LANDFILLTYPE_NONE        0
#define LANDFILLTYPE_HOTPOTATO   1
#define LANDFILLTYPE_DIRECTED    2

typedef struct {
  /* 0x0  */ Garbage  *list;
  /* 0x4  */ u8        garbage_idx;
  /* 0x5  */ u8        type;
  /* 0x6  */ u8        pad6[0x2A];
  /* 0x30 */ u8        unk30;       // hotpotato related
  /* 0x31 */ u8        pad31[0x13];
} Landfill; // 0x44 bytes

extern Landfill *g_landfill_ptr;

extern void      Landfill_800723a0_calls_garbage_fun(u8, u8, u8);
extern void      Landfill_8007240c_fiveliner(u8, u8);
extern void      func_80072508(u8);
extern void      func_8007257C(u8);
extern void      func_800726A4(Landfill *, u8);
extern Garbage  *Landfill_Garbage(void);
extern void      Landfill_Init(Landfill *);
extern void      Landfill_Deinit(Landfill *);
extern void      func_80072A84(void);

#endif /* !_LANDFILL_H_ */
