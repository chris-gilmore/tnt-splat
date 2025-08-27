#include "common.h"

static u8 D_800D3200[0xC0] = {
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};

static s32    EndScroller_8007fdb0_returns_0_1_2(ScrollLine *, s32);
static void   EndScroller_8007fe54_twoliner(ScrollLine *);
static void   EndScroller_font_size_scrolltext(ScrollLine *, char *, Font *);
static void   EndScroller_8007ffb0_doesnothing(ScrollLine *);
static void   EndScroller_8007ffb8_oneliner_if(UnkStruct_82 *);

static s32 EndScroller_8007fdb0_returns_0_1_2(ScrollLine *p_scrollLine, s32 arg1) {
  if ((p_scrollLine->y + p_scrollLine->h) < 0) {
    return 0;
  }

  if ((p_scrollLine->y + p_scrollLine->h) >= 300) {
    p_scrollLine->y -= arg1;
    if ((p_scrollLine->y + p_scrollLine->h) < 300) {
      return 2;  // new line scrolling in from the bottom
    }
  } else {
    p_scrollLine->y -= arg1;
    if ((p_scrollLine->y + p_scrollLine->h) < 0) {
      return 1;  // old line scrolling out from the top
    }
  }

  return 0;
}

static void EndScroller_8007fe54_twoliner(ScrollLine *p_scrollLine) {
  if (p_scrollLine->y >= 300) {
    return;
  }

  if ((p_scrollLine->y + p_scrollLine->h) < 0) {
    return;
  }

  displayText_80078244_7(p_scrollLine->p_font, p_scrollLine->str, p_scrollLine->len, &g_gdl, p_scrollLine->x, p_scrollLine->y, 0xFF, 0xFF, 0xFF, 0xFF);
}

static void EndScroller_font_size_scrolltext(ScrollLine *p_scrollLine, char *line_str, Font *p_font) {
  p_scrollLine->p_font = p_font;
  p_scrollLine->str = line_str;
  p_scrollLine->len = strutil_linelen(line_str, '\n');
  p_scrollLine->w = Font_800781a8_elevenliner_loops_arg2_t(p_font, line_str, p_scrollLine->len);
  p_scrollLine->h = p_font->height + 2;
  p_scrollLine->x = (400 - p_scrollLine->w) >> 1;
  p_scrollLine->y = 300;
}

static void EndScroller_8007ffb0_doesnothing(ScrollLine *p_scrollLine) {
}

static void EndScroller_8007ffb8_oneliner_if(UnkStruct_82 *arg0) {
  register u32 var_a1 = g_PV_arr->unk24;

  if (var_a1 & 0x8000) {  // A_BUTTON / CONT_A
    arg0->unk1 = TRUE;
  }
}

void EndScroller_Init(UnkStruct_82 *arg0, char *text) {
  u32 line_num;
  register char *line_str;
  register ScrollLine *p_scrollLine;  // line

  FUN_046770_800804f0_many_heapallocs_for_arg0_elems(&arg0->unk104);
  Font_Init46Char(&arg0->font[0], IMG_FONT_C);
  Font_Init46Char(&arg0->font[1], IMG_FONT_B);
  arg0->num_lines = strutil_linecnt(text);
  arg0->line_pool = n64HeapAlloc(arg0->num_lines * sizeof(ScrollLine));
  rmonPrintf("number of lines in scroll text %d\n", arg0->num_lines);
  rmonPrintf("line pool allocated at %x\n", arg0->line_pool);

  p_scrollLine = arg0->line_pool;
  line_num = 0;
  for (line_str = text; *line_str != 0; line_str++) {
    EndScroller_font_size_scrolltext(p_scrollLine, line_str, &arg0->font[D_800D3200[line_num]]);
    line_num++;
    line_str = strutil_nextline(line_str, '\n');
    p_scrollLine++;
  }

  arg0->unkFC = 0;
  arg0->unk100 = 0;
  arg0->is_active = TRUE;
  arg0->unk1 = FALSE;
  rmonPrintf("EndScroller_Init() : Done\n");
}

void EndScroller_Deinit(UnkStruct_82 *arg0) {
  register u32 line_num;
  register ScrollLine *p_scrollLine;

  if (!arg0->is_active) {
    debug_print_reason_routine_linenum("deinit when not active", "endscroller.c", 416);
  }

  p_scrollLine = arg0->line_pool;
  for (line_num = 0; line_num < arg0->num_lines; line_num++) {
    EndScroller_8007ffb0_doesnothing(p_scrollLine);
    p_scrollLine++;
  }

  n64HeapUnalloc(arg0->line_pool);
  Font_Deinit(&arg0->font[1]);
  Font_Deinit(&arg0->font[0]);
  FUN_046770_8008074c_nineliner_calls_9funcs_warg0_elems(&arg0->unk104);
  arg0->is_active = FALSE;
  rmonPrintf("EndScroller_Deinit() : Done\n");
}

s32 EndScroller_8008023c_line_452(UnkStruct_82 *arg0, s32 arg1) {
  s32 sp3C;
  register u32 var_s0;
  register ScrollLine *p_scrollLine;
  register s32 var_s2;

  sp3C = 0;

  if (!arg0->is_active) {
    debug_print_reason_routine_linenum("called when not active", "endscroller.c", 452);
  }

  EndScroller_8007ffb8_oneliner_if(arg0);
  if (arg0->unk1) {
    return 1;
  }

  FUN_046770_8008080c_threeliner_sets_arg0(&arg0->unk104, arg1 + 1);

  for (; sp3C < arg1; sp3C++) {
    var_s0 = arg0->unkFC;
    p_scrollLine = arg0->line_pool + var_s0;
    for (; var_s0 <= arg0->unk100; var_s0++) {
      var_s2 = EndScroller_8007fdb0_returns_0_1_2(p_scrollLine, 1);
      switch (var_s2) {
      case 1:  // old line scrolling out from the top
        arg0->unkFC++;
        break;
      case 2:  // new line scrolling in from the bottom
        if (arg0->unk100 < (arg0->num_lines - 1)) {
          arg0->unk100++;
        }
        break;
      }
      p_scrollLine++;
    }
    if (arg0->unkFC > arg0->unk100) {
      return 1;
    }
  }

  return 0;
}

void EndScroller_80080400_line_502(UnkStruct_82 *arg0) {
  register u32 var_s0;
  register ScrollLine *p_scrollLine;

  if (!arg0->is_active) {
    debug_print_reason_routine_linenum("called when not active", "endscroller.c", 502);
  }

  if (arg0->unk1) {
    return;
  }

  FUN_046770_magic_150_is_it_ultra_related(&arg0->unk104);

  var_s0 = arg0->unkFC;
  p_scrollLine = arg0->line_pool + var_s0;
  func_8005BBFC(&g_gdl);
  for (; var_s0 <= arg0->unk100; var_s0++) {
    EndScroller_8007fe54_twoliner(p_scrollLine);
    p_scrollLine++;
  }
  func_8005BE40(&g_gdl);
}
