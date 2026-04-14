#include "common.h"

s8 D_800CF830 = -1;
s8 D_800CF834 = -1;
s8 D_800CF838 = 0;
s8 D_800CF83C = 0;
u8 D_800CF840 = FALSE;
char *D_800CF844[8] = {
  "MAYAN",
  "GREEK",
  "EGYPTIAN",
  "CELTIC",
  "AFRICAN",
  "JAPANESE",
  "RUSSIAN",
  "FINALE",
};
static u32 D_800CF864[49] = {
     357,    714,   1071,   1428,   1785,   2142,   2500,
    3214,   3928,   4642,   5356,   6070,   6784,   7500,
    9285,  11070,  12855,  14640,  16425,  18210,  20000,
   24285,  28570,  32855,  37140,  41425,  45710,  50000,
   57142,  64284,  71426,  78568,  85710,  92852, 100000,
  121428, 142856, 164284, 185712, 207140, 228568, 250000,
  285714, 321428, 357142, 392856, 428570, 464284, 500000,
};
static u32 D_800CF928[7] = {
  2500,
  7500,
  20000,
  50000,
  100000,
  250000,
  500000,
};

void wonders2_80045e50_sets_num_won_compl_q(void) {
  register s8 i;
  register u8 j;
  register u32 temp_s2 = get_total_wonder_lines(g_sram_ptr);

  for (i = -1; i < 48 && temp_s2 >= D_800CF864[i + 1]; i++);
  D_800CF830 = i;
  D_800CF834 = D_800CF830;
  for (j = 0; j < 6 && temp_s2 >= D_800CF928[j]; j++);
  if ((j == 6) && (temp_s2 >= D_800CF928[j])) {
    D_800CF838 = 7;
  } else {
    D_800CF838 = j;
  }
  D_800CF83C = D_800CF838;
  D_800CF840 = (D_800CF838 == 7);
}

u8 wonders2_80045fdc_sets_num_won_compl_q(void) {
  register s8 i;
  register u8 j;
  register u32 temp_v0;

  if (D_800CF830 == 48) {
    return FALSE;
  }

  temp_v0 = get_total_wonder_lines(g_sram_ptr);
  D_800CF834 = D_800CF830;
  for (i = -1; i < 48 && temp_v0 >= D_800CF864[i + 1]; i++);
  D_800CF830 = i;
  if (D_800CF834 != D_800CF830) {
    D_800CF83C = D_800CF838;
    for (j = 0; j < 6 && temp_v0 >= D_800CF928[j]; j++);
    if ((j == 6) && (temp_v0 >= D_800CF928[j])) {
      D_800CF838 = 7;
    } else {
      D_800CF838 = j;
    }
    return TRUE;
  }

  return FALSE;
}

u8 wonders2_8004619c_sixliner_crazy_if(s8 arg0) {
  return
    (arg0 == 6) ||
    (arg0 == 13) ||
    (arg0 == 20) ||
    (arg0 == 27) ||
    (arg0 == 34) ||
    (arg0 == 41) ||
    (arg0 == 48);
}

s8 wonders2_divide_by_seven(s8 arg0) {
  register s8 ret = arg0 / 7;
  return ret;
}

s8 wonders2_8004624c_mult_7_add_6_etc(s8 arg0) {
  register s8 ret = (arg0 * 7) + 6;
  return ret;
}

u32 wonders2_80046280_tenliner_trap(s8 arg0) {
  register u8 ret;
  register u32 var_s1;
  register u32 temp_s2;
  register u32 temp_s3 = get_total_wonder_lines(g_sram_ptr);

  ret = 0;
  if (arg0 > D_800CF838) {
    ret = 0;
  } else if (arg0 < D_800CF838) {
    ret = 100;
  } else {
    if (arg0 != 0) {
      var_s1 = D_800CF928[arg0 - 1];
    } else {
      var_s1 = 0;
    }
    temp_s2 = D_800CF928[arg0] - var_s1;
    ret = 100 * (temp_s3 - var_s1) / temp_s2;
  }
  return ret;
}

u32 wonders2_80046388_fiveliner(s8 arg0) {
  register u32 temp_s0;
  register u32 var_s1;
  register u32 temp_v0;

  temp_v0 = get_total_wonder_lines(g_sram_ptr);
  temp_s0 = D_800CF928[arg0];
  if (temp_v0 >= temp_s0) {
    var_s1 = 0;
  } else {
    var_s1 = temp_s0 - temp_v0;
  }

  return var_s1;
}
