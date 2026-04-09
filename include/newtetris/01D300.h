#ifndef _01D300_H_
#define _01D300_H_

typedef struct {
  /* 0x0 */ void  *img;
  /* 0x4 */ s16    x;
  /* 0x6 */ s16    y;
  /* 0x8 */ u8     red;
  /* 0x9 */ u8     green;
  /* 0xA */ u8     blue;
  /* 0xB */ u8     alpha;
} ImgParams; // 0xC bytes

typedef struct {
  /* 0x0  */ void  *img;
  /* 0x4  */ void  *pal;
  /* 0x8  */ s16    x;
  /* 0xA  */ s16    y;
  /* 0xC  */ s16    unkC;
  /* 0xE  */ s16    unkE;
  /* 0x10 */ u8     red;
  /* 0x11 */ u8     green;
  /* 0x12 */ u8     blue;
  /* 0x13 */ u8     alpha;
} ImgPalParams; // 0x14 bytes

extern void   FUN_01D300_80057080_nevercalled(ImgParams *);
extern void   FUN_01D300_800570b0_fiveliner(ImgParams *, u32);
extern void   FUN_01D300_n64HeapUnalloc(ImgParams *);
extern void   FUN_01D300_80057140_sixliner(ImgParams *);
extern void   FUN_01D300_800571d4_twentyliner(ImgPalParams *, u32, u32);
extern void   FUN_01D300_800572f8_twoliner(ImgPalParams *);
extern void   FUN_01D300_80057338_fifteenliner(ImgPalParams *);

#endif /* !_01D300_H_ */
