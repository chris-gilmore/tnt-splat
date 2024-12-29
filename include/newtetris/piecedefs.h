#ifndef _PIECEDEFS_H_
#define _PIECEDEFS_H_

typedef struct {
  /* 0x0 */ s8   x;
  /* 0x1 */ s8   y;
} Position; // 0x2 bytes

typedef struct {
  /* 0x0 */ s16   x;
  /* 0x2 */ s16   y;
} Point; // 0x4 bytes

typedef struct {
  /* 0x0  */ u8         piece_type;                 // 0:L, 1:J, 2:Z, 3:S, 4:T, 5:I, 6:O
  /* 0x1  */ Position   local_mino_pos_arr[4];      // local x,y position for piece mino in initial rotation state of 0deg
  /* 0xA  */ Point      center;                     // center of mass point for piece in initial rotation state of 0deg
  /* 0xE  */ Position   rot_origin_pos_arr[4];      // origin of rotation position per rotation state
  /* 0x18 */ Color     *color_ptr;                  // color address
  /* 0x1C */ Position   curpiece_spawn_offset_pos;  // x,y offset position for currentpiece spawn
  /* 0x1E */ u8         starting_rot_state;          // starting clockwise rotation state; [0]=0deg, [1]=90deg, [2]=180deg, [3]=270deg
} PieceDefinition; // 0x20 bytes

extern PieceDefinition *g_pieceDef_ptr_arr[7];

extern Point  *getCurPieceSpawnOffsetAsPoint(Point *, PieceDefinition *);
extern Point  *getStartingRotOriginAsPoint(Point *, PieceDefinition *);
extern void    initPieceColorsScale16(void);

#endif /* !_PIECEDEFS_H_ */
