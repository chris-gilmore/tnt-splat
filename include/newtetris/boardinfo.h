#ifndef _BOARDINFO_H_
#define _BOARDINFO_H_

typedef struct {
  /* 0x0 */ Point   location;
  /* 0x4 */ s16     unitSize;
} BoardInfo; // 0x6 bytes

extern void    BoardInfo_Init(BoardInfo *, Point, s16);
extern Point  *get_board_center(Point *, BoardInfo *);

#endif /* !_BOARDINFO_H_ */
