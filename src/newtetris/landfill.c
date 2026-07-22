#include "common.h"

Landfill *g_landfill_ptr;

static u8 func_80072494(u8);
static u8 func_800724C0(u8, u8);
static void func_80072610(u8);

void func_80072300(u8 arg0) {
  register Landfill *landfill_ptr = g_landfill_ptr;

  if (landfill_ptr->unk30.unk0 == arg0) {
    landfill_ptr->unk30.unk1 = TRUE;
  }
}

u32 func_8007232C(void) {
  register Landfill *landfill_ptr = g_landfill_ptr;
  register s32 var_a1;
  register s32 var_a2 = 0;

  for (var_a1 = 0; var_a1 < g_playercount; var_a1++) {
    if (g_landfill_ptr->list[var_a1].unk0) {
      var_a2++;
    }
  }

  // (bug?) Missing "return var_a2;"
}

void Landfill_800723a0_calls_garbage_fun(u8 arg0, u8 arg1, u8 arg2) {
  func_80072CC8(g_landfill_ptr->list + arg0, arg1, arg2);
  func_80073690(&g_landfill_ptr->unk8, arg0, arg1, arg2);
}

void Landfill_8007240c_fiveliner(u8 arg0, u8 arg1) {
  register Landfill *landfill_ptr = g_landfill_ptr;
  register Garbage *garbage_ptr = g_landfill_ptr->list + arg0;

  if (garbage_ptr->unk0) {
    func_80072E34(garbage_ptr, arg1);
    landfill_ptr->unk8.list[arg0].unkA = arg1;
  }
}

static u8 func_80072494(u8 arg0) {
  return g_landfill_ptr->list[arg0].unk1D;
}

static u8 func_800724C0(u8 arg0, u8 arg1) {
  return func_80072D24(g_landfill_ptr->list + arg0, arg1);
}

void func_80072508(u8 arg0) {
  register s32 var_s0;
  register s32 var_s1;

  var_s0 = func_80072494(arg0);
  if (var_s0 > 0) {
    var_s1 = var_s0;
    while (TRUE) {
      var_s1--;
      if (func_800724C0(arg0, var_s1) || (var_s1 < 0)) {
        break;
      }
    }

    if (var_s1 >= 0) {
      Landfill_8007240c_fiveliner(arg0, var_s1);
    }
  }
}

void func_8007257C(u8 arg0) {
  register s32 var_s0;
  register s32 var_s1;
  register s32 var_s2;

  var_s0 = g_landfill_ptr->garbage_idx - 1;
  var_s1 = func_80072494(arg0);
  if (var_s1 < var_s0) {
    var_s2 = var_s1;
    while (TRUE) {
      var_s2++;
      if (func_800724C0(arg0, var_s2) || (var_s2 > var_s0)) {
        break;
      }
    }

    if (var_s0 >= var_s2) {
      Landfill_8007240c_fiveliner(arg0, var_s2);
    }
  }
}

static void func_80072610(u8 arg0) {
  register s32 var_s0;
  register s32 var_s1;
  register s32 var_s2;

  var_s0 = g_landfill_ptr->garbage_idx - 1;
  var_s1 = func_80072494(arg0);
  var_s2 = var_s1;
  while (TRUE) {
    var_s2++;
    if (var_s2 > var_s0) {
      var_s2 = 0;
    }

    if (func_800724C0(arg0, var_s2) || (var_s2 == var_s1)) {
      break;
    }
  }

  if (var_s2 != var_s1) {
    Landfill_8007240c_fiveliner(arg0, var_s2);
  }
}

void func_800726A4(Landfill *arg0, u8 arg1) {
  register s32 var_s0;
  register Garbage *var_s1;
  register s32 var_s2;

  Garbage_80072e2c_set_arg0p_to_arg1(g_landfill_ptr->list + arg1, FALSE);

  for (var_s0 = 0; var_s0 < arg0->garbage_idx; var_s0++) {
    var_s1 = g_landfill_ptr->list + var_s0;
    func_80072CC8(var_s1, arg1, FALSE);
  }

  func_800736E0(&arg0->unk8, arg1, FALSE);

  switch (arg0->type) {
  case LANDFILLTYPE_HOTPOTATO:
    if (arg0->unk30.unk0 == arg1) {
      arg0->unk30.unk1 = TRUE;
    }
    break;
  case LANDFILLTYPE_DIRECTED:
    for (var_s2 = 0; var_s2 < arg0->garbage_idx; var_s2++) {
      if (g_landfill_ptr->list[var_s2].unk1D == arg1) {
        func_80072610(var_s2);
      }
    }
    break;
  }
}

Garbage *Landfill_Garbage(void) {
  register Landfill *landfill_ptr = g_landfill_ptr;
  register Garbage *garbage_ptr;

  garbage_ptr = &g_landfill_ptr->list[landfill_ptr->garbage_idx];
  landfill_ptr->garbage_idx++;

  return garbage_ptr;
}

void Landfill_Init(Landfill *landfill_ptr) {
  landfill_ptr->garbage_idx = 0;
  landfill_ptr->list = n64HeapAlloc(g_playercount * sizeof(Garbage));

  switch (landfill_ptr->type) {
  case LANDFILLTYPE_NONE:
    AimedAt_Init();
    func_80073940(&landfill_ptr->unk8);  // aimedat
    func_80073784(&landfill_ptr->unk8, FALSE);  // aimedat
    break;
  case LANDFILLTYPE_HOTPOTATO:
    AimedAt_Init();
    func_80073940(&landfill_ptr->unk8);  // aimedat
    HotPotato_Init(&landfill_ptr->unk30);
    break;
  case LANDFILLTYPE_DIRECTED:
    AimedAt_Init();
    func_80073940(&landfill_ptr->unk8);  // aimedat
    break;
  default:
    debug_print_reason_routine_linenum("Invalid Landfill type", "landfill.c", 276);
    break;
  }
}

void Landfill_Deinit(Landfill *arg0) {
  switch (arg0->type) {
  case LANDFILLTYPE_NONE:
    func_80073AC4(&arg0->unk8);  // aimedat
    AimedAt_Deinit();
    break;
  case LANDFILLTYPE_HOTPOTATO:
    func_80073AC4(&arg0->unk8);  // aimedat
    AimedAt_Deinit();
    HotPotato_Deinit(&arg0->unk30);
    break;
  case LANDFILLTYPE_DIRECTED:
    func_80073AC4(&arg0->unk8);  // aimedat
    AimedAt_Deinit();
    break;
  default:
    debug_print_reason_routine_linenum("Invalid Landfill type", "landfill.c", 307);
    break;
  }
  n64HeapUnalloc(arg0->list);
  arg0->list = NULL;
  arg0->garbage_idx = 0;
  arg0->type = LANDFILLTYPE_NONE;
}

void Landfill_Render(void) {
  register Landfill *landfill_ptr = g_landfill_ptr;

  switch (landfill_ptr->type) {
  case LANDFILLTYPE_NONE:
    AimedAt_Render(&landfill_ptr->unk8);
    break;
  case LANDFILLTYPE_HOTPOTATO:
    HotPotato_Render(&landfill_ptr->unk30);
    AimedAt_Render(&landfill_ptr->unk8);
    break;
  case LANDFILLTYPE_DIRECTED:
    AimedAt_Render(&landfill_ptr->unk8);
    break;
  default:
    debug_print_reason_routine("Invalid landfill type for Landfill", "Landfill_Render(), landfill.c");
    break;
  }
}
