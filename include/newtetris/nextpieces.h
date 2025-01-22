#ifndef _NEXTPIECES_H_
#define _NEXTPIECES_H_

typedef struct {
  /* 0x0  */ Point   unk0[4];  // nextpieces locations
  /* 0x10 */ u8      unk10;    // alpha of bottom nextpiece
  /* 0x11 */ u8      unk11;    // alpha of top nextpiece
                               // Note: the alpha of the middle nextpiece
                               // is the average of the top and bottom
  /* 0x12 */ u16     unk12;    // scale of bottom nextpiece
  /* 0x14 */ u16     unk14;    // scale of top nextpiece
                               // Note: the scale of the middle nextpiece
                               // is the average of the top and bottom
} UnkStruct_17; // 0x16 bytes

typedef struct {
  /* 0x0 */ Point   unk0;  // src physicalPos
  /* 0x4 */ Point   unk4;  // dst physicalPos
  /* 0x8 */ u8      unk8;  // src alpha
  /* 0x9 */ u8      unk9;  // dst alpha
  /* 0xA */ u16     unkA;  // src mino_scale
  /* 0xC */ u16     unkC;  // dst mino_scale
} UnkStruct_13; // 0xE bytes

typedef struct {
  /* 0x0  */ UnkStruct_13   unk0[4];
  /* 0x38 */ UnkStruct_13   unk38[4];  // shadow
} UnkStruct_18; // 0x70 bytes

typedef struct {
  /* 0x0  */ u8      piece_type;
  /* 0x1  */ u8      starting_rot_state;
  /* 0x2  */ Point   physicalPos;
  /* 0x6  */ Point   unk6;
  /* 0xA  */ u16     mino_scale;
  /* 0xC  */ s16     unkC;
  /* 0xE  */ s16     alpha_sl4b;  // alpha shifted left 4 bits
  /* 0x10 */ s16     unk10;
  /* 0x12 */ u8      unk12[0x6];
  /* 0x18 */ Piece   piece;
} NextPieceShadow; // 0x510 bytes

typedef struct {
  /* 0x0   */ u8                piece_type;
  /* 0x1   */ u8                starting_rot_state;
  /* 0x2   */ Point             physicalPos;
  /* 0x6   */ Point             unk6;
  /* 0xA   */ Point             physicalRotOrigin;
  /* 0xE   */ Point             unkE;
  /* 0x12  */ u16               mino_scale;
  /* 0x14  */ s16               unk14;
  /* 0x16  */ s16               alpha_sl4b;  // alpha shifted left 4 bits
  /* 0x18  */ s16               unk18;
  /* 0x1A  */ u8                pad1A[0x6];
  /* 0x20  */ Piece             piece;
  /* 0x518 */ NextPieceShadow   shadow;
} NextPiece; // 0xA28 bytes

typedef struct {
  /* 0x0    */ u8             state;
  /* 0x1    */ u8             unk1;
  /* 0x2    */ UnkStruct_18   unk2;
  /* 0x72   */ u8             pad72[0x6];
  /* 0x78   */ NextPiece      buf[4];
  /* 0x2918 */ u8             buf_idx;
  /* 0x2919 */ u8             spawnDelay;  // initialized to 20 and decrements
  /* 0x291A */ u8             alpha;
  /* 0x291C */ Bag63         *bag63_ptr;
} NextPieces; // 0x2920 bytes

extern NextPieces *g_nextPieces_ptr;

extern void   NextPieces_800688e0_sets_global_var_element(void);
extern void   NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun(void);
extern void   NextPieces_Render(void);
extern u8     NextPieces_80068b18_threeliner(void);
extern void   NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(UnkStruct_17 *arg0);
extern void   NextPieces_Init(Bag63 *);
extern void   NextPieces_Deinit(void);

#endif /* !_NEXTPIECES_H_ */
