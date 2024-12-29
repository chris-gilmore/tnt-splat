#ifndef _BOARDPIECES_H_
#define _BOARDPIECES_H_

#define EMPTY_CELL 7

typedef struct {
  /* 0x0 */ Position  *minoLockedPos_ptr;
  /* 0x4 */ u8         pieceType;
  /* 0x5 */ u8         numMinos;
} UnkStruct_4; // 0x6 bytes

typedef struct Cell_s {
  /* 0x0   */ u8              properties;  // bitfield; [bit_0]=broken, [bit_1]=empty, [bit_2]=adjacent
  /* 0x1   */ u8              piece_type;  // 7 if empty
  /* 0x2   */ u8              piece_id;    // otherwise 0
  /* 0x3   */ u8              square_id;   // otherwise 0xFF or 0xFE
  /* 0x4   */ struct Cell_s  *next;        // pointer to next linked cell
  /* 0x8   */ CubeInfo        cubeInfo;    // cell_id, pos, cube_ptr
} Cell; // 0x10 bytes

typedef void *Entry;

typedef struct {
  /* 0x0 */  Entry   entry;
  /* 0x4 */  u8      type;
} TypedEntry; // 0x8 bytes

typedef struct {
  /* 0x0    */ TypedEntry   entries[600];
  /* 0x12C0 */ u16          maxlen;        // set to 600
  /* 0x12C2 */ u16          curlen;
} TypedQueue; // 0x12C4 bytes

typedef struct {
  /* 0x0    */ Cell        *cell_list;          // allocated list of cells
  /* 0x4    */ Cell        *cell_ptr_arr[200];  // array of 200 cell pointers
  /* 0x324  */ Cell         cell_200;           // 030700FE self_ptr C8FFFFFB 00000000
  /* 0x334  */ Cell         cell_201;           // 050800FE self_ptr C9FFFFFB 00000000
  /* 0x344  */ TypedQueue   updQ;
  /* 0x1608 */ Ids          pieceIds;
  /* 0x1614 */ u16          num_cells;          // set to 200
} BoardPieces; // 0x1618 bytes

extern BoardPieces *g_boardPieces_ptr;

extern Color  *BoardP_8006d3c0_fourliner(Cell *);
extern void    BoardP_8006d450_fourteenliner_pf_logic_cell_loops(Cell *, Cell *);
extern void    BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry(Cell *);
extern void    BoardP_8006d674_tenliner_alloc_fallingcubes(Cell *);
extern u8      BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops(Cell *, s32, s32);
extern s32     BoardP_8006dcd0_eightliner_loops_upto_19_times_increment(void);
extern s32     BoardP_8006dd1c_eightliner_loops_upto_19_times_decrement(void);
extern u8      BoardP_8006dd64_check_for_nonempty_cell_downwards(s32);
extern u8      BoardP_8006ddd0_check_for_nonempty_cell_upwards(s32);
extern void    BoardP_8006de40_nineliner(s32, s32, u8);
extern void    BoardP_8006df38_twentyfiveliner_3_loops(UnkStruct_4 *);
extern void    BoardPieces_SwapCubes(s32, s32, s32, s32);
extern void    BoardP_8006e288_adds_8_entries_and_swaps_cubes(Cell *);
extern void    BoardPieces_RemoveLine(s32);  // never called
extern u8      BoardP_IsPositionEmpty(s32, s32);
extern u8      BoardP_IsPointEmpty(s32, s32);
extern Cell   *BoardP_playfield_xy_to_logic_cell_struct_8006e5e0(s32, s32);
extern void    BoardP_8006e64c_calls_UpdateQueue_AddEntry(s32, s32);
extern void    BoardPieces_Update(BoardPieces *, s32);
extern void    BoardPieces_Init(BoardPieces *);
extern void    BoardPieces_Deinit(BoardPieces *);

#endif /* !_BOARDPIECES_H_ */
