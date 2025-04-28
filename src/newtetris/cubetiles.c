#include "common.h"

CubeTiles *g_cubeTiles_ptr;
static u8 surround[9];

static PartialTile D_800D0690 = {
  {
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D06B0 = {
  {
    {0xE,   0}, {0xE,   0}, {0xE,   0}, {0xE,   0},
    {0xF,   0}, {0xF,   0}, {0xF,   0}, {0xF,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D06D0 = {
  {
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D06F0 = {
  {
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  1,   0}, {  1,   0}, {  1,   0}, {  1,   0},
    {  2,   0}, {  2,   0}, {  2,   0}, {  2,   0},
  }
};

static PartialTile D_800D0710 = {
  {
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
  }
};

static PartialTile D_800D0730 = {
  {
    {0xE, 0xE}, {0xE,   0}, {0xE,   0}, {0xE,   0},
    {  0, 0xE}, {0xF, 0xF}, {0xF,   0}, {0xF,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D0750 = {
  {
    {0xE, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {0xF,   0}, {0xF, 0xF}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D0770 = {
  {
    {0xE,   0}, {0xE,   0}, {0xE,   0}, {0xE,   2},
    {0xF,   0}, {0xF,   0}, {0xF,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
  }
};

static PartialTile D_800D0790 = {
  {
    {  0,   0}, {  0,   0}, {  0,   1}, {0xE,   2},
    {  0,   0}, {  0,   0}, {0xF,   1}, {0xF,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
  }
};

static PartialTile D_800D07B0 = {
  {
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  0,   0}, {  0,   0}, {  0,   1}, {  0,   2},
    {  1,   0}, {  1,   0}, {  1,   1}, {  0,   2},
    {  2,   0}, {  2,   0}, {  2,   0}, {  2,   2},
  }
};

static PartialTile D_800D07D0 = {
  {
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  1,   1}, {  1,   0},
    {  0,   0}, {  0,   0}, {  0,   1}, {  2,   2},
  }
};

static PartialTile D_800D07F0 = {
  {
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
    {  0, 0xE}, {  1, 0xF}, {  1,   0}, {  1,   0},
    {  2, 0xE}, {  2,   0}, {  2,   0}, {  2,   0},
  }
};

static PartialTile D_800D0810 = {
  {
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  0,   0}, {  0,   0}, {  0,   0}, {  0,   0},
    {  1,   0}, {  1, 0xF}, {  0,   0}, {  0,   0},
    {  2, 0xE}, {  0, 0xF}, {  0,   0}, {  0,   0},
  }
};

static PartialTile *D_800D0830[4][16] = {
  { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &D_800D0730, NULL, &D_800D06D0, &D_800D06D0, &D_800D06B0, &D_800D06B0, &D_800D0750, &D_800D0690 },

  { NULL, NULL, NULL, NULL, &D_800D0770, &D_800D0710, NULL, &D_800D0710, NULL, NULL, NULL, NULL, &D_800D06B0, &D_800D0790, &D_800D06B0, &D_800D0690 },

  { NULL, NULL, &D_800D07F0, &D_800D06F0, NULL, NULL, NULL, &D_800D06F0, NULL, NULL, &D_800D06D0, &D_800D0810, NULL, NULL, &D_800D06D0, &D_800D0690 },

  { NULL, &D_800D07B0, NULL, &D_800D06F0, NULL, &D_800D0710, NULL, &D_800D07D0, NULL, NULL, NULL, &D_800D06F0, NULL, &D_800D0710, NULL, &D_800D0690 },
};

static void   CubeTiles_CopyPartialTile(s32, s32, Gradient2D *);
static void   CubeTiles_80075a84_thirteenliner(u8, CubeTile *);
static void   func_80075DBC(PartialTile *);

static void CubeTiles_CopyPartialTile(s32 arg0, s32 arg1, Gradient2D *arg2) {
  register PartialTile *temp_s0;
  register u8 var_s1;
  register u16 *var_s2;
  register u16 *var_s3;
  register s32 j;
  register s32 i;

  var_s1 = 0;
  if (surround[(arg1 * 3) + arg0]) {
    var_s1 |= 1;
  }
  if (surround[1 + (arg1 * 3) + arg0]) {
    var_s1 |= 2;
  }
  if (surround[3 + (arg1 * 3) + arg0]) {
    var_s1 |= 4;
  }
  if (surround[4 + (arg1 * 3) + arg0]) {
    var_s1 |= 8;
  }

  temp_s0 = D_800D0830[(arg1 * 2) + arg0][var_s1];
  if (temp_s0 == NULL) {
    debug_print_reason_routine("Null tile in CopyPartialTile()", "cubetiles.c");
  }

  var_s3 = (u16 *) arg2;
  var_s2 = (u16 *) temp_s0->gradients;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      *var_s3++ = *var_s2++;
    }
    var_s3 += 4;
  }
}

static void CubeTiles_80075a84_thirteenliner(u8 arg0, CubeTile *arg1) {
  surround[0] = (arg0 & 0x80) ? TRUE : FALSE;  // NW
  surround[1] = (arg0 & 0x01) ? TRUE : FALSE;  // N
  surround[2] = (arg0 & 0x10) ? TRUE : FALSE;  // NE
  surround[3] = (arg0 & 0x08) ? TRUE : FALSE;  // W
  surround[4] = TRUE;                          // CENTER
  surround[5] = (arg0 & 0x02) ? TRUE : FALSE;  // E
  surround[6] = (arg0 & 0x40) ? TRUE : FALSE;  // SW
  surround[7] = (arg0 & 0x04) ? TRUE : FALSE;  // S
  surround[8] = (arg0 & 0x20) ? TRUE : FALSE;  // SE

  CubeTiles_CopyPartialTile(0, 0, &arg1->gradients[0]);
  CubeTiles_CopyPartialTile(1, 0, &arg1->gradients[4]);
  CubeTiles_CopyPartialTile(0, 1, &arg1->gradients[32]);
  CubeTiles_CopyPartialTile(1, 1, &arg1->gradients[36]);
}

void CubeTiles_Init(CubeTiles *p_cubetiles) {
  register CubeTile *var_s0;
  register u16 i;
  register u16 var_s2;

  var_s0 = p_cubetiles->unk0;
  var_s2 = 0;
  for (i = 0; i < 256; i++) {
    p_cubetiles->unkDC00[i] = &p_cubetiles->unk0[0];

    if ((!(i & 0x80) || (i &  9)) &&  // ((not NW) or (N and W)) and
        (!(i & 0x10) || (i &  3)) &&  // ((not NE) or (N and E)) and
        (!(i & 0x40) || (i & 12)) &&  // ((not SW) or (S and W)) and
        (!(i & 0x20) || (i &  6))) {  // ((not SE) or (S and E))

      p_cubetiles->unkDC00[i] = var_s0;
      CubeTiles_80075a84_thirteenliner(i, var_s0);
      var_s0++;
      var_s2++;
    }
  }

  if (var_s2 > 200) {
    debug_print_reason_routine("CubeTiles:Init() more then 161 tiles", "cubetiles.c");
  }
}

void CubeTiles_Deinit(CubeTiles *p_cubetiles) {
}

static void func_80075DBC(PartialTile *arg0) {
  register u32 i;
  register u8 *ptr;

  ptr = (u8 *) arg0->gradients;
  for (i = 0; i < 32; i++, ptr++) {
    *ptr <<= 4;
  }
}

void func_80075DF4(void) {
  func_80075DBC(&D_800D0690);
  func_80075DBC(&D_800D06B0);
  func_80075DBC(&D_800D06F0);
  func_80075DBC(&D_800D06D0);
  func_80075DBC(&D_800D0710);
  func_80075DBC(&D_800D0730);
  func_80075DBC(&D_800D0750);
  func_80075DBC(&D_800D0770);
  func_80075DBC(&D_800D0790);
  func_80075DBC(&D_800D07F0);
  func_80075DBC(&D_800D0810);
  func_80075DBC(&D_800D07B0);
  func_80075DBC(&D_800D07D0);
}
