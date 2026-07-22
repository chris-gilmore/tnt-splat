#ifndef _LANDFILL_H_
#define _LANDFILL_H_

#define LANDFILLTYPE_NONE        0
#define LANDFILLTYPE_HOTPOTATO   1
#define LANDFILLTYPE_DIRECTED    2

typedef struct {
  /* 0x0  */ Garbage        *list;
  /* 0x4  */ u8              garbage_idx;
  /* 0x5  */ u8              type;
  /* 0x8  */ UnkStruct_112   unk8;   // aimedat
  /* 0x30 */ UnkStruct_29    unk30;  // hotpotato
} Landfill; // 0x44 bytes

extern Landfill *g_landfill_ptr;

extern void      func_80072300(u8);
extern u32       func_8007232C(void);
extern void      Landfill_800723a0_calls_garbage_fun(u8, u8, u8);
extern void      Landfill_8007240c_fiveliner(u8, u8);
extern void      func_80072508(u8);
extern void      func_8007257C(u8);
extern void      func_800726A4(Landfill *, u8);
extern Garbage  *Landfill_Garbage(void);
extern void      Landfill_Init(Landfill *);
extern void      Landfill_Deinit(Landfill *);
extern void      Landfill_Render(void);

#endif /* !_LANDFILL_H_ */
