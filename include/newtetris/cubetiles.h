#ifndef _CUBETILES_H_
#define _CUBETILES_H_

typedef struct {
  /* 0x0    */ u8     pad0[0xDC00];
  /* 0xDC00 */ void  *unkDC00[0x100];
} CubeTiles; // 0xE000 bytes

extern CubeTiles *g_cubeTiles_ptr;

extern void   CubeTiles_Init(CubeTiles *);
extern void   CubeTiles_Deinit(CubeTiles *);
extern void   func_80075DF4(void);

#endif /* !_CUBETILES_H_ */
