#include "common.h"

static void   GhostPiece_8006677c_fourliner_loops(GhostPiece *);

void GhostPiece_800666d0_sixliner_loops_arg1_times(GhostPiece *ghostPiece_ptr, s32 arg1) {
  register s32 i;

  MobilePiece_800655c4_oneliner_if_calls_fun(&ghostPiece_ptr->flasher, arg1);
  for (i = arg1; i > 0; i--) {
    MobilePiece_80064f54_fourliner_loops_4_times(&ghostPiece_ptr->piece, arg1);
  }
}

void GhostPiece_Render(GhostPiece *ghostPiece_ptr) {
  register Piece *piece_ptr;

  piece_ptr = &ghostPiece_ptr->piece;
  if ((ghostPiece_ptr->unk0) && (MobilePiece_800651c8_sevenliner_loops_4_times_v2_retbool(piece_ptr))) {
    MobilePiece_Render(piece_ptr);
  }
}

static void GhostPiece_8006677c_fourliner_loops(GhostPiece *ghostPiece_ptr) {
  do {
    ghostPiece_ptr->piece.physicalPos.y += 0x100;
  } while (MobilePiece_800651c8_sevenliner_loops_4_times_v2_retbool(&ghostPiece_ptr->piece));
  ghostPiece_ptr->piece.physicalPos.y -= 0x100;
}

/*
  sp30.x = currentPiece_ptr->piece.physicalPos.x;
  sp30.y = currentPiece_ptr->logicalPos.y << 8;
  sp2C.x = currentPiece_ptr->piece.physicalRotOrigin.x;
  sp2C.y = (currentPiece_ptr->logicalRotOrigin.y << 8) + 0x80;
  GhostPiece_800667dc_twelveliner_sets_struct(&currentPiece_ptr->ghostPiece, sp30, sp2C, currentPiece_ptr->logicalRotCkwState << 14);
*/
void GhostPiece_800667dc_twelveliner_sets_struct(GhostPiece *ghostPiece_ptr, Point arg1, Point arg2, u16 arg3) {
  ghostPiece_ptr->unk52A = 0;
  if ((ghostPiece_ptr->unk528 != arg3) || (ghostPiece_ptr->unk524 != arg2.x) || (ghostPiece_ptr->unk526 != arg1.x)) {
    ghostPiece_ptr->unk52A = 1;
    ghostPiece_ptr->unk528 = arg3;
    ghostPiece_ptr->unk524 = arg2.x;
    ghostPiece_ptr->unk526 = arg1.x;
    MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(&ghostPiece_ptr->piece, ghostPiece_ptr->pieceDef_ptr, arg1, arg2, arg3, 0xFF);
    MobilePiece_8006553c_nineliner_sets_arg0_struct(&ghostPiece_ptr->flasher, &ghostPiece_ptr->piece);
    GhostPiece_8006677c_fourliner_loops(ghostPiece_ptr);
  }
}

// GhostPiece_800668ec_sixliner_inits_struct(&currentPiece_ptr->ghostPiece, g_pieceDef_ptr_arr[currentPiece_ptr->pieceType], currentPiece_ptr->unk538);
void GhostPiece_800668ec_sixliner_inits_struct(GhostPiece *ghostPiece_ptr, PieceDefinition *pieceDef_ptr, u8 arg2) {
  ghostPiece_ptr->pieceDef_ptr = pieceDef_ptr;
  ghostPiece_ptr->unk528 = 0XFFFF;
  ghostPiece_ptr->unk524 = 0xFFFF;
  ghostPiece_ptr->unk526 = 0xFFFF;
  ghostPiece_ptr->unk0 = arg2;
  ghostPiece_ptr->unk52A = 0;
}
