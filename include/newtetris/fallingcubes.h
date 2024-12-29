#ifndef _FALLINGCUBES_H_
#define _FALLINGCUBES_H_

typedef struct {
  /* 0x0 */ Cube **cube_ptr_list;  // allocated list of Cube pointers
  /* 0x4 */ u8     max_allowed;    // max pointers
  /* 0x5 */ u8     num_active;     // num pointers
  /* 0x6 */ u8     alpha;          // mino color alpha
} FallingCubes; // 0x8 bytes

extern FallingCubes *g_fallingCubes_ptr;

extern void   FallingCubes_Update(void);
extern void   FallingCubes_SetAlpha(FallingCubes *, u8);
extern Cube **FallingCubes_Alloc(void);
extern void   FallingCubes_Init(s32);
extern void   FallingCubes_Deinit(void);

#endif /* !_FALLINGCUBES_H_ */
