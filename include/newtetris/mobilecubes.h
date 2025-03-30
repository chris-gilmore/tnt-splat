#ifndef _MOBILECUBES_H_
#define _MOBILECUBES_H_

typedef struct {
  /* 0x0 */ Cube   *cube_list;      // allocated list of Cubes
  /* 0x4 */ u8      max_allowed;    // max pointers
  /* 0x5 */ u8      num_active;     // num pointers
  /* 0x6 */ u8      alpha;          // mino color alpha
  /* 0x8 */ Minos  *minos_ptr;
} MobileCubes; // 0xC bytes

extern MobileCubes *g_mobileCubes_ptr;

extern void   MobileCubes_Update(void);
extern void   MobileCubes_Render(void);
extern Cube  *MobileCubes_Alloc(void);
extern void   MobileCubes_Unalloc(Cube *);
extern void   MobileCubes_Init(s32, Minos *);
extern void   MobileCubes_Deinit(void);

#endif /* !_MOBILECUBES_H_ */
