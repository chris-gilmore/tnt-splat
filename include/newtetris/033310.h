#ifndef _033310_H_
#define _033310_H_

typedef struct {
  /* 0x0 */ PieceDefinition  *pieceDef_ptr;
  /* 0x4 */ u8                board_width;   // set to 10
  /* 0x5 */ u8                board_height;  // set to 20
} UnkStruct_16; // 0x6 bytes

extern void    FUN_033310_setPieceDef(UnkStruct_16 *, u8);
extern Point  *FUN_033310_getPhysicalCurPieceSpawnPos(Point *, UnkStruct_16 *);
extern Point  *FUN_033310_getPhysicalStartingRotOrigin(Point *, UnkStruct_16 *);
extern void    FUN_033310_Init(UnkStruct_16 *, u8, u8);
extern void    FUN_033310_Deinit(UnkStruct_16 *);

#endif /* !_033310_H_ */
