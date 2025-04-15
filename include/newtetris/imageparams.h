#ifndef _IMAGEPARAMS_H_
#define _IMAGEPARAMS_H_

typedef union {
  s32    id;
  void  *data;
} Img_u;

typedef union {
  s32    id;
  void  *data;
} Pal_u;

typedef struct {
  /* 0x0  */ Img_u   img;
  /* 0x4  */ s32     x;
  /* 0x8  */ s32     y;
  /* 0xC  */ s32     red;
  /* 0x10 */ s32     green;
  /* 0x14 */ s32     blue;
  /* 0x18 */ s32     alpha;
  /* 0x1C */ Pal_u   pal;
} ImageParams; // 0x20 bytes

// 1p
extern ImageParams D_800D0930[24];

// 2p
extern ImageParams D_800D0C30[16];

// 3p, 4p
extern ImageParams D_800D0E30[16];

#endif /* !_IMAGEPARAMS_H_ */
