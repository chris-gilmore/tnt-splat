#include "common.h"

NextPieces *g_nextPieces_ptr;
static Point D_800D0530 = { 0x0000, 0x0000 };
static Point D_800D0534 = { 0x0000, 0x0000 };

static void   NextPieces_800680a0_sixliner(NextPieceShadow *, u8);
static void   NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1(NextPieceShadow *, UnkStruct_13 *);
static void   NextPieces_80068204_fourliner_sets_arg0_struct_math(NextPieceShadow *);
static void   NextPieceShadow_Render(NextPieceShadow *, u8);
static void   NextPieces_8006832c_sixliner_shift_0xe(NextPiece *, u8);
static void   NextPiece_Render(NextPiece *, u8);
static void   NextPieces_800684e0_sevenliner_sets_arg0_struct_math(NextPiece *);
static void   NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos(NextPiece *, UnkStruct_13 *, UnkStruct_13 *, u8);
static void   NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var(void);
static void   NextPieces_800689c4_tenliner_loops_4_times(NextPieces *);
static void   NextPieces_80068a84_calls_Bag63_GetNextPiece(void);

static void NextPieces_800680a0_sixliner(NextPieceShadow *shadow_ptr, u8 piece_type) {
  register PieceDefinition *pieceDef_ptr;
  Point sp28;

  pieceDef_ptr = g_pieceDef_ptr_arr[piece_type];
  sp28 = D_800D0530;
  shadow_ptr->piece_type = piece_type;
  shadow_ptr->starting_rot_state = pieceDef_ptr->starting_rot_state;
  MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&shadow_ptr->piece, pieceDef_ptr, sp28, pieceDef_ptr->center, pieceDef_ptr->starting_rot_state << 14, 0x0);
  MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(&shadow_ptr->piece, &g_color_black);
}

static void NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1(NextPieceShadow *shadow_ptr, UnkStruct_13 *arg1) {
  shadow_ptr->physicalPos = arg1->unk0;
  shadow_ptr->unk6.x = (arg1->unk4.x - arg1->unk0.x) / 20;
  shadow_ptr->unk6.y = (arg1->unk4.y - arg1->unk0.y) / 20;
  shadow_ptr->alpha_sl4b = arg1->unk8 << 4;
  shadow_ptr->unk10 = ((arg1->unk9 << 4) - (arg1->unk8 << 4)) / 20;
  shadow_ptr->mino_scale = arg1->unkA;
  shadow_ptr->unkC = (arg1->unkC - arg1->unkA) / 20;
}

static void NextPieces_80068204_fourliner_sets_arg0_struct_math(NextPieceShadow *shadow_ptr) {
  shadow_ptr->physicalPos.x += shadow_ptr->unk6.x;
  shadow_ptr->physicalPos.y += shadow_ptr->unk6.y;
  shadow_ptr->alpha_sl4b += shadow_ptr->unk10;
  shadow_ptr->mino_scale += shadow_ptr->unkC;
}

static void NextPieceShadow_Render(NextPieceShadow *shadow_ptr, u8 alpha) {
  register Piece *piece_ptr = &shadow_ptr->piece;

  piece_ptr->physicalPos = shadow_ptr->physicalPos;
  piece_ptr->physicalPos.x += 0x80;
  piece_ptr->physicalPos.y += 0x80;
  if (alpha == 0xFF) {
    piece_ptr->alpha = shadow_ptr->alpha_sl4b >> 4;
  } else {
    piece_ptr->alpha = (shadow_ptr->alpha_sl4b * alpha) / 4096U;
  }
  Minos_SetScale(shadow_ptr->mino_scale);
  debug_print2("NextPieceShadow:Render()", "Minos_SetScale");
  MobilePiece_Render(piece_ptr);
  debug_print2("NextPieceShadow:Render()", "MobilePiece_Render");
}

static void NextPieces_8006832c_sixliner_shift_0xe(NextPiece *nextPiece_ptr, u8 piece_type) {
  register PieceDefinition *pieceDef_ptr;
  Point sp28;

  pieceDef_ptr = g_pieceDef_ptr_arr[piece_type];
  sp28 = D_800D0534;
  nextPiece_ptr->piece_type = piece_type;
  nextPiece_ptr->starting_rot_state = pieceDef_ptr->starting_rot_state;
  MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&nextPiece_ptr->piece, pieceDef_ptr, sp28, sp28, pieceDef_ptr->starting_rot_state << 14, 0x0);
  NextPieces_800680a0_sixliner(&nextPiece_ptr->shadow, piece_type);
}

static void NextPiece_Render(NextPiece *nextPiece_ptr, u8 alpha) {
  register Piece *piece_ptr;

  NextPieceShadow_Render(&nextPiece_ptr->shadow, alpha);
  piece_ptr = &nextPiece_ptr->piece;
  piece_ptr->physicalPos = nextPiece_ptr->physicalPos;
  piece_ptr->physicalRotOrigin = nextPiece_ptr->physicalRotOrigin;
  if (alpha == 0xFF) {
    piece_ptr->alpha = nextPiece_ptr->alpha_sl4b >> 4;
  } else {
    piece_ptr->alpha = (nextPiece_ptr->alpha_sl4b * alpha) / 4096U;  // why not ">> 12"?
  }
  Minos_SetScale(nextPiece_ptr->mino_scale);
  debug_print2("AFTER", "Minos_SetScale");
  MobilePiece_Render(piece_ptr);
  debug_print2("AFTER", "MobilePiece_Render");
}

static void NextPieces_800684e0_sevenliner_sets_arg0_struct_math(NextPiece *nextPiece_ptr) {
  nextPiece_ptr->physicalPos.x       += nextPiece_ptr->unk6.x;
  nextPiece_ptr->physicalPos.y       += nextPiece_ptr->unk6.y;
  nextPiece_ptr->physicalRotOrigin.x += nextPiece_ptr->unkE.x;
  nextPiece_ptr->physicalRotOrigin.y += nextPiece_ptr->unkE.y;
  nextPiece_ptr->alpha_sl4b          += nextPiece_ptr->unk18;
  nextPiece_ptr->mino_scale          += nextPiece_ptr->unk14;
  NextPieces_80068204_fourliner_sets_arg0_struct_math(&nextPiece_ptr->shadow);
}

static void NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos(NextPiece *nextPiece_ptr, UnkStruct_13 *arg1, UnkStruct_13 *arg2, u8 pos) {
  register PieceDefinition *pieceDef_ptr;
  Point spawnPoint;
  Point rotOriginPoint;

  pieceDef_ptr = g_pieceDef_ptr_arr[nextPiece_ptr->piece_type];
  switch (pos) {
  case 0:
    getCurPieceSpawnPoint(&spawnPoint, nextPiece_ptr->piece_type);
    getStartingOriginOfRotationPoint(&rotOriginPoint, nextPiece_ptr->piece_type);
    nextPiece_ptr->physicalPos = arg1->unk0;
    nextPiece_ptr->unk6.x = (spawnPoint.x - nextPiece_ptr->physicalPos.x) / 20;
    nextPiece_ptr->unk6.y = (spawnPoint.y - nextPiece_ptr->physicalPos.y) / 20;
    nextPiece_ptr->physicalRotOrigin = pieceDef_ptr->center;
    nextPiece_ptr->unkE.x = (rotOriginPoint.x - nextPiece_ptr->physicalRotOrigin.x) / 20;
    nextPiece_ptr->unkE.y = (rotOriginPoint.y - nextPiece_ptr->physicalRotOrigin.y) / 20;
    break;
  case 1:
  case 2:
  case 3:
    nextPiece_ptr->physicalPos = arg1->unk0;
    nextPiece_ptr->unk6.x = (arg1->unk4.x - arg1->unk0.x) / 20;
    nextPiece_ptr->unk6.y = (arg1->unk4.y - arg1->unk0.y) / 20;
    nextPiece_ptr->physicalRotOrigin = pieceDef_ptr->center;
    nextPiece_ptr->unkE.x = 0;
    nextPiece_ptr->unkE.y = 0;
    break;
  default:
    debug_print_reason_routine_linenum("oh oh", "nextpieces.c", 231);
    break;
  }
  nextPiece_ptr->alpha_sl4b = arg1->unk8 << 4;
  nextPiece_ptr->unk18 = ((arg1->unk9 << 4) - (arg1->unk8 << 4)) / 20;
  nextPiece_ptr->mino_scale = arg1->unkA;
  nextPiece_ptr->unk14 = (arg1->unkC - arg1->unkA) / 20;
  NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1(&nextPiece_ptr->shadow, arg2);
}

void NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;
  register s32 i;

  for (i = 0; i < 4; i++) {
    NextPieces_800684e0_sevenliner_sets_arg0_struct_math(&nextPieces_ptr->buf[i]);
  }
  nextPieces_ptr->spawnDelay--;
  if (nextPieces_ptr->spawnDelay == 0) {
    nextPieces_ptr->unk1 = 1;
    nextPieces_ptr->state = 0;
    return;
  }
  nextPieces_ptr->unk1 = 0;
}

void NextPieces_800688e0_sets_global_var_element(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;

  nextPieces_ptr->state = 1;
  nextPieces_ptr->spawnDelay = 20;
}

void NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;

  if (nextPieces_ptr->state == 1) {
    NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var();
  }
}

void NextPieces_Render(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;
  register s32 i;

  for (i = 0; i < 4; i++) {
    NextPiece_Render(&nextPieces_ptr->buf[i], nextPieces_ptr->alpha);
  }
  Minos_SetScale(0x100);
  Minos_SetAlpha(0xFF);
}

static void NextPieces_800689c4_tenliner_loops_4_times(NextPieces *nextPieces_ptr) {
  register s32 i;
  register s32 buf_idx;

  buf_idx = nextPieces_ptr->buf_idx;
  for (i = 0; i < 4; i++) {
    NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos(&nextPieces_ptr->buf[buf_idx], &nextPieces_ptr->unk2.unk0[i], &nextPieces_ptr->unk2.unk38[i], i);
    buf_idx = (buf_idx + 1) % 4;
  }
}

static void NextPieces_80068a84_calls_Bag63_GetNextPiece(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;

  NextPieces_8006832c_sixliner_shift_0xe(&nextPieces_ptr->buf[nextPieces_ptr->buf_idx], Bag63_GetNextPiece(nextPieces_ptr->bag63_ptr));
  nextPieces_ptr->buf_idx = (nextPieces_ptr->buf_idx + 1) % 4;
  NextPieces_800689c4_tenliner_loops_4_times(nextPieces_ptr);
}

u8 NextPieces_80068b18_threeliner(void) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;
  register u8 piece_type;

  piece_type = nextPieces_ptr->buf[nextPieces_ptr->buf_idx].piece_type;
  NextPieces_80068a84_calls_Bag63_GetNextPiece();
  return piece_type;
}

void NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(UnkStruct_17 *arg0) {
  register UnkStruct_18 *temp_a1 = &g_nextPieces_ptr->unk2;
  register s32 i;
  u8 spC[3];
  u16 sp4[3];

  spC[0] = arg0->unk11;
  spC[2] = arg0->unk10;
  spC[1] = (spC[0] + spC[2]) >> 1;
  sp4[0] = arg0->unk14;
  sp4[2] = arg0->unk12;
  sp4[1] = (sp4[0] + sp4[2]) >> 1;
  for (i = 0; i < 4; i++) {
    temp_a1->unk0[i].unk0 = arg0->unk0[i];
  }
  temp_a1->unk0[1].unk4 = arg0->unk0[0];
  temp_a1->unk0[2].unk4 = arg0->unk0[1];
  temp_a1->unk0[3].unk4 = arg0->unk0[2];

  temp_a1->unk0[3].unk8 = 0;
  temp_a1->unk0[3].unk9 = spC[2];
  temp_a1->unk0[2].unk8 = spC[2];
  temp_a1->unk0[2].unk9 = spC[1];
  temp_a1->unk0[1].unk8 = spC[1];
  temp_a1->unk0[1].unk9 = spC[0];
  temp_a1->unk0[0].unk8 = spC[0];
  temp_a1->unk0[0].unk9 = 0xFF;

  temp_a1->unk0[3].unkA = sp4[2];
  temp_a1->unk0[3].unkC = sp4[2];
  temp_a1->unk0[2].unkA = sp4[2];
  temp_a1->unk0[2].unkC = sp4[1];
  temp_a1->unk0[1].unkA = sp4[1];
  temp_a1->unk0[1].unkC = sp4[0];
  temp_a1->unk0[0].unkA = sp4[0];
  temp_a1->unk0[0].unkC = 0x100;

  for (i = 0; i < 4; i++) {
    temp_a1->unk38[i].unk0 = arg0->unk0[i];
  }
  temp_a1->unk38[3].unk4 = arg0->unk0[2];
  temp_a1->unk38[2].unk4 = arg0->unk0[1];
  temp_a1->unk38[1].unk4 = arg0->unk0[0];
  temp_a1->unk38[0].unk4 = arg0->unk0[0];

  temp_a1->unk38[3].unk8 = 0;
  temp_a1->unk38[3].unk9 = (spC[2] * 0xAA) >> 8;  // note: 0xAA/0xFF = 2/3
  temp_a1->unk38[2].unk8 = (spC[2] * 0xAA) >> 8;
  temp_a1->unk38[2].unk9 = (spC[1] * 0xAA) >> 8;
  temp_a1->unk38[1].unk8 = (spC[1] * 0xAA) >> 8;
  temp_a1->unk38[1].unk9 = (spC[0] * 0xAA) >> 8;
  temp_a1->unk38[0].unk8 = (spC[0] * 0xAA) >> 8;
  temp_a1->unk38[0].unk9 = 0;

  temp_a1->unk38[3].unkA = sp4[2];
  temp_a1->unk38[3].unkC = sp4[2];
  temp_a1->unk38[2].unkA = sp4[2];
  temp_a1->unk38[2].unkC = sp4[1];
  temp_a1->unk38[1].unkA = sp4[1];
  temp_a1->unk38[1].unkC = sp4[0];
  temp_a1->unk38[0].unkA = sp4[0];
  temp_a1->unk38[0].unkC = sp4[0];
}

void NextPieces_Init(Bag63 *bag63_ptr) {
  register NextPieces *nextPieces_ptr = g_nextPieces_ptr;
  register s32 i;

  nextPieces_ptr->bag63_ptr = bag63_ptr;
  nextPieces_ptr->buf_idx = 0;
  for (i = 0; i < 4; i++) {
    NextPieces_8006832c_sixliner_shift_0xe(&nextPieces_ptr->buf[nextPieces_ptr->buf_idx], Bag63_GetNextPiece(nextPieces_ptr->bag63_ptr));
    nextPieces_ptr->buf_idx = (nextPieces_ptr->buf_idx + 1) % 4;
  }
  NextPieces_800689c4_tenliner_loops_4_times(nextPieces_ptr);
  nextPieces_ptr->alpha = 0xFF;
}

void NextPieces_Deinit(void) {
}
