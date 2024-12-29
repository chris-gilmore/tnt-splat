#include "common.h"

static u32 D_80110570; // unused

void debug_print_reason_routine_linenum(u8 *reason, u8 *routine, u32 linenum) {
  u8 routine_linenum[80];

  sprintf(routine_linenum, "%s line %d", routine, linenum);
  debug_print_reason_routine(reason, routine_linenum);
}
