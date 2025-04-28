#ifndef _CUBETILES_H_
#define _CUBETILES_H_

typedef struct {
  /* 0x0 */ s8   y;
  /* 0x1 */ s8   x;
} Gradient2D; // 0x2 bytes

typedef struct {
  /* 0x0 */ Gradient2D   gradients[16];
} PartialTile; // 0x20 bytes

typedef struct {
  /* 0x0 */ Gradient2D   gradients[64];
} CubeTile; // 0x80 bytes

typedef struct {
  /* 0x0    */ CubeTile   unk0[440];
  /* 0xDC00 */ CubeTile  *unkDC00[256];
} CubeTiles; // 0xE000 bytes

extern CubeTiles *g_cubeTiles_ptr;

extern void   CubeTiles_Init(CubeTiles *);
extern void   CubeTiles_Deinit(CubeTiles *);
extern void   func_80075DF4(void);

#endif /* !_CUBETILES_H_ */
