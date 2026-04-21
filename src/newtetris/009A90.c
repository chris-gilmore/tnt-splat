#include "common.h"

static UnkStruct_32 *D_800E1F60;
static UnkStruct_50 *D_800E1F64;
static UnkStruct_50 *D_800E1F68;
static u16 D_800E1F6C;
static u8 D_800E1F6E;
static u8 D_800E1F6F;
static u8 D_800E1F70;

WonderAnim *g_wonderAnim = NULL;

static UnkStruct_11 D_800C5E14 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0x440, 0 };
static UnkStruct_11 D_800C5E44 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x45B };
static UnkStruct_11 D_800C5E74 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x471 };
static UnkStruct_11 D_800C5EA4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x487 };
static UnkStruct_11 D_800C5ED4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4AC };
static UnkStruct_11 D_800C5F04 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4CD };
static UnkStruct_11 D_800C5F34 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4FE };
static UnkStruct_11 D_800C5F64 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x518 };
static UnkStruct_11 D_800C5F94 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x451 };
static UnkStruct_11 D_800C5FC4 = { NULL, NULL, 4.6f, 0.0f, 0.52f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x3EF };
static UnkStruct_11 D_800C5FF4 = { NULL, NULL, 1.53f, 0.0f, 0.52f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6024 = { NULL, NULL, 1.53f, 0.0f, -2.54f, 0.0f, 0.0f, 0.0f, 0, 18.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6054 = { NULL, NULL, 4.6f, 0.0f, -2.54f, 0.0f, 0.0f, 0.0f, 0, 59.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6084 = { NULL, NULL, 1.53f, 0.0f, -5.6f, 0.0f, 0.0f, 0.0f, 0, 77.0f, 0, 0x3EF };
static UnkStruct_11 D_800C60B4 = { NULL, NULL, 4.6f, 0.0f, -5.6f, 0.0f, 0.0f, 0.0f, 0, 103.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C60E4[10] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C5F94,
  &D_800C5FC4,
  &D_800C5FF4,
  &D_800C6024,
  &D_800C6054,
  &D_800C6084,
  &D_800C60B4,
  NULL,
};
static UnkStruct_11 D_800C610C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x452 };
static UnkStruct_11 D_800C613C = { NULL, NULL, 1.53f, 0.0f, 9.74f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800C616C = { NULL, NULL, 4.6f, 0.0f, 6.65f, 0.0f, 0.0f, 0.0f, 0, 72.0f, 0, 0x3EF };
static UnkStruct_11 D_800C619C = { NULL, NULL, 1.53f, 0.0f, 6.65f, 0.0f, 0.0f, 0.0f, 0, 21.0f, 0, 0x3EF };
static UnkStruct_11 D_800C61CC = { NULL, NULL, 1.53f, 0.0f, 3.58f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C61FC = { NULL, NULL, 4.6f, 0.0f, 3.58f, 0.0f, 0.0f, 0.0f, 0, 54.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C622C[9] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C610C,
  &D_800C613C,
  &D_800C616C,
  &D_800C619C,
  &D_800C61CC,
  &D_800C61FC,
  NULL,
};
static UnkStruct_11 D_800C6250 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x453 };
static UnkStruct_11 D_800C6280 = { NULL, NULL, -4.56f, 0.01f, 0.51f, 0.0f, 0.0f, 0.0f, 0, 112.0f, 0, 0x3EF };
static UnkStruct_11 D_800C62B0 = { NULL, NULL, -1.51f, 0.01f, 3.55f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C62E0 = { NULL, NULL, -4.58f, 0.01f, 3.56f, 0.0f, 0.0f, 0.0f, 0, 32.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6310 = { NULL, NULL, -4.59f, 0.01f, 6.64f, 0.0f, 0.0f, 0.0f, 0, 76.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6340 = { NULL, NULL, -1.53f, 0.01f, 6.64f, 0.0f, 0.0f, 0.0f, 0, 56.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6370 = { NULL, NULL, -1.53f, 0.01f, 9.73f, 0.0f, 0.0f, 0.0f, 0, 92.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C63A0[10] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C6250,
  &D_800C6280,
  &D_800C62B0,
  &D_800C62E0,
  &D_800C6310,
  &D_800C6340,
  &D_800C6370,
  NULL,
};
static UnkStruct_11 D_800C63C8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x454 };
static UnkStruct_11 D_800C63F8 = { NULL, NULL, -1.53f, 0.0f, 0.52f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6428 = { NULL, NULL, -1.53f, 0.0f, -2.54f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6458 = { NULL, NULL, -1.53f, 0.0f, -5.6f, 0.0f, 0.0f, 0.0f, 0, 85.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6488 = { NULL, NULL, -4.59f, 0.0f, -5.6f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0, 0x3EF };
static UnkStruct_11 D_800C64B8 = { NULL, NULL, -4.59f, 0.0f, -2.54f, 0.0f, 0.0f, 0.0f, 0, 61.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C64E8[9] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C63C8,
  &D_800C63F8,
  &D_800C6428,
  &D_800C6458,
  &D_800C6488,
  &D_800C64B8,
  NULL,
};
static UnkStruct_11 D_800C650C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x455 };
static UnkStruct_11 D_800C653C = { NULL, NULL, 2.99f, 3.06f, 2.32f, 0.0f, 0.0f, 0.0f, 0, 64.0f, 0, 0x3EF };
static UnkStruct_11 D_800C656C = { NULL, NULL, -0.07f, 3.06f, 5.38f, 0.0f, 0.0f, 0.0f, 0, 120.0f, 0, 0x3EF };
static UnkStruct_11 D_800C659C = { NULL, NULL, -0.07f, 3.06f, 2.32f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C65CC = { NULL, NULL, -3.14f, 3.06f, 2.32f, 0.0f, 0.0f, 0.0f, 0, 36.0f, 0, 0x3EF };
static UnkStruct_11 D_800C65FC = { NULL, NULL, -3.14f, 3.06f, -0.74f, 0.0f, 0.0f, 0.0f, 0, 98.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C662C[9] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C650C,
  &D_800C653C,
  &D_800C656C,
  &D_800C659C,
  &D_800C65CC,
  &D_800C65FC,
  NULL,
};
static UnkStruct_11 D_800C6650 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x456 };
static UnkStruct_11 D_800C6680 = { NULL, NULL, 2.99f, 3.06f, -0.74f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800C66B0 = { NULL, NULL, 2.99f, 3.06f, -3.81f, 0.0f, 0.0f, 0.0f, 0, 44.0f, 0, 0x3EF };
static UnkStruct_11 D_800C66E0 = { NULL, NULL, -0.07f, 3.06f, -0.74f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6710 = { NULL, NULL, -0.07f, 3.06f, -3.81f, 0.0f, 0.0f, 0.0f, 0, 26.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6740 = { NULL, NULL, -3.14f, 3.06f, -3.81f, 0.0f, 0.0f, 0.0f, 0, 63.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C6770[9] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C6650,
  &D_800C6680,
  &D_800C66B0,
  &D_800C66E0,
  &D_800C6710,
  &D_800C6740,
  NULL,
};
static UnkStruct_11 D_800C6794 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x457 };
static UnkStruct_11 D_800C67C4 = { NULL, NULL, 1.5f, 6.13f, -0.59f, 0.0f, 0.0f, 0.0f, 0, 210.0f, 0, 0x3EF };
static UnkStruct_11 D_800C67F4 = { NULL, NULL, 1.5f, 6.13f, -3.59f, 0.0f, 0.0f, 0.0f, 0, 10.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6824 = { NULL, NULL, -1.5f, 6.13f, -0.59f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6854 = { NULL, NULL, -1.5f, 6.13f, -3.59f, 0.0f, 0.0f, 0.0f, 0, 110.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C6884[8] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C6794,
  &D_800C67C4,
  &D_800C67F4,
  &D_800C6824,
  &D_800C6854,
  NULL,
};
static UnkStruct_11 D_800C68A4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0xBD };
static UnkStruct_11 *D_800C68D4[4] = {
  &D_800C5E44,
  &D_800C5E14,
  &D_800C68A4,
  NULL,
};
static UnkStruct_11 D_800C68E4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0xBB };
static UnkStruct_11 *D_800C6914[2] = {
  &D_800C68E4,
  NULL,
};
static UnkStruct_11 D_800C691C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0xBC };
static UnkStruct_11 *D_800C694C[2] = {
  &D_800C691C,
  NULL,
};
static UnkStruct_11 D_800C6954 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x466 };
static UnkStruct_11 D_800C6984 = { NULL, NULL, -10.6f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 288.0f, 0, 0x3EF };
static UnkStruct_11 D_800C69B4 = { NULL, NULL, -10.6f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 262.0f, 0, 0x3EF };
static UnkStruct_11 D_800C69E4 = { NULL, NULL, -10.6f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 248.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6A14 = { NULL, NULL, -10.6f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 237.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6A44 = { NULL, NULL, -10.6f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 216.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6A74 = { NULL, NULL, -10.6f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 300.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6AA4 = { NULL, NULL, -7.59f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6AD4 = { NULL, NULL, -4.58f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 136.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6B04 = { NULL, NULL, -1.57f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 106.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6B34 = { NULL, NULL, -1.57f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 44.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6B64 = { NULL, NULL, -1.57f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6B94 = { NULL, NULL, -4.58f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 66.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6BC4 = { NULL, NULL, -7.59f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 128.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6BF4 = { NULL, NULL, -7.59f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 174.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6C24 = { NULL, NULL, -4.58f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 27.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6C54 = { NULL, NULL, -4.58f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 91.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6C84 = { NULL, NULL, -7.59f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 271.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6CB4 = { NULL, NULL, -7.59f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 289.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6CE4 = { NULL, NULL, -7.59f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 188.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C6D14[23] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C6954,
  &D_800C6984,
  &D_800C69B4,
  &D_800C69E4,
  &D_800C6A14,
  &D_800C6A44,
  &D_800C6A74,
  &D_800C6AA4,
  &D_800C6AD4,
  &D_800C6B04,
  &D_800C6B34,
  &D_800C6B64,
  &D_800C6B94,
  &D_800C6BC4,
  &D_800C6BF4,
  &D_800C6C24,
  &D_800C6C54,
  &D_800C6C84,
  &D_800C6CB4,
  &D_800C6CE4,
  NULL,
};
static UnkStruct_11 D_800C6D70 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x467 };
static UnkStruct_11 D_800C6DA0 = { NULL, NULL, -4.58f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 111.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6DD0 = { NULL, NULL, -4.58f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 175.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6E00 = { NULL, NULL, -1.57f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 126.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6E30 = { NULL, NULL, 1.44f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 161.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6E60 = { NULL, NULL, 4.45f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 260.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6E90 = { NULL, NULL, -1.57f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6EC0 = { NULL, NULL, 1.44f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 78.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6EF0 = { NULL, NULL, 4.45f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 225.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6F20 = { NULL, NULL, 4.45f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 246.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6F50 = { NULL, NULL, 1.44f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 202.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6F80 = { NULL, NULL, -1.57f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C6FB0 = { NULL, NULL, 1.44f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 57.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C6FE0[16] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C6D70,
  &D_800C6DA0,
  &D_800C6DD0,
  &D_800C6E00,
  &D_800C6E30,
  &D_800C6E60,
  &D_800C6E90,
  &D_800C6EC0,
  &D_800C6EF0,
  &D_800C6F20,
  &D_800C6F50,
  &D_800C6F80,
  &D_800C6FB0,
  NULL,
};
static UnkStruct_11 D_800C7020 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x468 };
static UnkStruct_11 D_800C7050 = { NULL, NULL, 1.44f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 126.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7080 = { NULL, NULL, 1.44f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 162.0f, 0, 0x3EF };
static UnkStruct_11 D_800C70B0 = { NULL, NULL, 4.45f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 139.0f, 0, 0x3EF };
static UnkStruct_11 D_800C70E0 = { NULL, NULL, 4.45f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 70.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7110 = { NULL, NULL, 4.45f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7140 = { NULL, NULL, 7.46f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 147.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7170 = { NULL, NULL, 7.46f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 32.0f, 0, 0x3EF };
static UnkStruct_11 D_800C71A0 = { NULL, NULL, 7.46f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 45.0f, 0, 0x3EF };
static UnkStruct_11 D_800C71D0 = { NULL, NULL, 7.46f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 107.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7200 = { NULL, NULL, 7.46f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 196.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7230 = { NULL, NULL, 7.46f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 238.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7260 = { NULL, NULL, 10.47f, 0.0f, 7.52f, 0.0f, 0.0f, 0.0f, 0, 260.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7290 = { NULL, NULL, 10.47f, 0.0f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 D_800C72C0 = { NULL, NULL, 10.47f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 173.0f, 0, 0x3EF };
static UnkStruct_11 D_800C72F0 = { NULL, NULL, 10.47f, 0.0f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 95.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7320 = { NULL, NULL, 10.47f, 0.0f, -4.53f, 0.0f, 0.0f, 0.0f, 0, 134.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7350 = { NULL, NULL, 10.47f, 0.0f, -7.54f, 0.0f, 0.0f, 0.0f, 0, 206.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C7380[21] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C7020,
  &D_800C7050,
  &D_800C7080,
  &D_800C70B0,
  &D_800C70E0,
  &D_800C7110,
  &D_800C7140,
  &D_800C7170,
  &D_800C71A0,
  &D_800C71D0,
  &D_800C7200,
  &D_800C7230,
  &D_800C7260,
  &D_800C7290,
  &D_800C72C0,
  &D_800C72F0,
  &D_800C7320,
  &D_800C7350,
  NULL,
};
static UnkStruct_11 D_800C73D4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x469 };
static UnkStruct_11 D_800C7404 = { NULL, NULL, 7.46f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 215.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7434 = { NULL, NULL, 4.45f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 129.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7464 = { NULL, NULL, 1.44f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 43.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7494 = { NULL, NULL, -1.57f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C74C4 = { NULL, NULL, -4.58f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 117.0f, 0, 0x3EF };
static UnkStruct_11 D_800C74F4 = { NULL, NULL, -7.59f, 3.0f, 2.91f, 0.0f, 0.0f, 0.0f, 0, 224.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7524 = { NULL, NULL, -7.59f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 240.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7554 = { NULL, NULL, -4.58f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 183.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7584 = { NULL, NULL, -1.57f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 66.0f, 0, 0x3EF };
static UnkStruct_11 D_800C75B4 = { NULL, NULL, 1.44f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 84.0f, 0, 0x3EF };
static UnkStruct_11 D_800C75E4 = { NULL, NULL, 4.45f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 174.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7614 = { NULL, NULL, 7.46f, 3.0f, 5.92f, 0.0f, 0.0f, 0.0f, 0, 239.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C7644[16] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C73D4,
  &D_800C7404,
  &D_800C7434,
  &D_800C7464,
  &D_800C7494,
  &D_800C74C4,
  &D_800C74F4,
  &D_800C7524,
  &D_800C7554,
  &D_800C7584,
  &D_800C75B4,
  &D_800C75E4,
  &D_800C7614,
  NULL,
};
static UnkStruct_11 D_800C7684 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x46A };
static UnkStruct_11 D_800C76B4 = { NULL, NULL, -7.59f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 181.0f, 0, 0x3EF };
static UnkStruct_11 D_800C76E4 = { NULL, NULL, 7.46f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 222.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7714 = { NULL, NULL, 7.46f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 194.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7744 = { NULL, NULL, -7.59f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7774 = { NULL, NULL, 4.45f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 148.0f, 0, 0x3EF };
static UnkStruct_11 D_800C77A4 = { NULL, NULL, 4.45f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 134.0f, 0, 0x3EF };
static UnkStruct_11 D_800C77D4 = { NULL, NULL, 1.44f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 95.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7804 = { NULL, NULL, -1.57f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7834 = { NULL, NULL, 1.44f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 61.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7864 = { NULL, NULL, -4.58f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 102.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7894 = { NULL, NULL, -1.57f, 3.0f, -5.95f, 0.0f, 0.0f, 0.0f, 0, 33.0f, 0, 0x3EF };
static UnkStruct_11 D_800C78C4 = { NULL, NULL, -4.58f, 3.0f, -2.94f, 0.0f, 0.0f, 0.0f, 0, 47.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C78F4[16] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C7684,
  &D_800C76B4,
  &D_800C76E4,
  &D_800C7714,
  &D_800C7744,
  &D_800C7774,
  &D_800C77A4,
  &D_800C77D4,
  &D_800C7804,
  &D_800C7834,
  &D_800C7864,
  &D_800C7894,
  &D_800C78C4,
  NULL,
};
static UnkStruct_11 D_800C7934 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x46B };
static UnkStruct_11 D_800C7964 = { NULL, NULL, -1.57f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 202.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7994 = { NULL, NULL, 7.46f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 142.0f, 0, 0x3EF };
static UnkStruct_11 D_800C79C4 = { NULL, NULL, 7.46f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 177.0f, 0, 0x3EF };
static UnkStruct_11 D_800C79F4 = { NULL, NULL, -1.57f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 160.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7A24 = { NULL, NULL, 1.44f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7A54 = { NULL, NULL, 4.45f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 48.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7A84 = { NULL, NULL, 1.44f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 33.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7AB4 = { NULL, NULL, 7.46f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 104.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7AE4 = { NULL, NULL, 7.46f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 216.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7B14 = { NULL, NULL, 4.45f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7B44 = { NULL, NULL, 4.45f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 71.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7B74 = { NULL, NULL, 4.45f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C7BA4[16] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C7934,
  &D_800C7964,
  &D_800C7994,
  &D_800C79C4,
  &D_800C79F4,
  &D_800C7A24,
  &D_800C7A54,
  &D_800C7A84,
  &D_800C7AB4,
  &D_800C7AE4,
  &D_800C7B14,
  &D_800C7B44,
  &D_800C7B74,
  NULL,
};
static UnkStruct_11 D_800C7BE4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x46C };
static UnkStruct_11 D_800C7C14 = { NULL, NULL, -7.59f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 240.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7C44 = { NULL, NULL, 1.44f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7C74 = { NULL, NULL, -7.59f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7CA4 = { NULL, NULL, -4.58f, 5.75f, 4.51f, 0.0f, 0.0f, 0.0f, 0, 205.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7CD4 = { NULL, NULL, 1.44f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 302.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7D04 = { NULL, NULL, -4.58f, 5.75f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 140.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7D34 = { NULL, NULL, -7.59f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 183.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7D64 = { NULL, NULL, -7.59f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 277.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7D94 = { NULL, NULL, -1.57f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 81.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7DC4 = { NULL, NULL, -4.58f, 5.75f, -4.52f, 0.0f, 0.0f, 0.0f, 0, 96.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7DF4 = { NULL, NULL, -1.57f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C7E24 = { NULL, NULL, -4.58f, 5.75f, -1.51f, 0.0f, 0.0f, 0.0f, 0, 54.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C7E54[16] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C7BE4,
  &D_800C7C14,
  &D_800C7C44,
  &D_800C7C74,
  &D_800C7CA4,
  &D_800C7CD4,
  &D_800C7D04,
  &D_800C7D34,
  &D_800C7D64,
  &D_800C7D94,
  &D_800C7DC4,
  &D_800C7DF4,
  &D_800C7E24,
  NULL,
};
static UnkStruct_11 D_800C7E94 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x13D };
static UnkStruct_11 *D_800C7EC4[4] = {
  &D_800C5E74,
  &D_800C5E14,
  &D_800C7E94,
  NULL,
};
static UnkStruct_11 D_800C7ED4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x13B };
static UnkStruct_11 *D_800C7F04[2] = {
  &D_800C7ED4,
  NULL,
};
static UnkStruct_11 D_800C7F0C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x13C };
static UnkStruct_11 *D_800C7F3C[2] = {
  &D_800C7F0C,
  NULL,
};
static UnkStruct_11 D_800C7F44 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x47D };
static UnkStruct_11 D_800C7F74 = { NULL, NULL, 8.23f, 0.0f, -13.92f, 0.0f, 0.0f, 0.0f, 0, 215.0f, 0, 0x417 };
static UnkStruct_11 D_800C7FA4 = { NULL, NULL, 9.62f, 0.0f, -10.01f, 0.0f, 0.0f, 0.0f, 0, 198.0f, 0, 0x417 };
static UnkStruct_11 D_800C7FD4 = { NULL, NULL, 9.62f, 0.0f, -6.01f, 0.0f, 0.0f, 0.0f, 0, 167.0f, 0, 0x417 };
static UnkStruct_11 D_800C8004 = { NULL, NULL, 4.31f, 0.0f, -13.92f, 0.0f, 0.0f, 0.0f, 0, 228.0f, 0, 0x417 };
static UnkStruct_11 D_800C8034 = { NULL, NULL, 4.31f, 0.0f, -10.01f, 0.0f, 0.0f, 0.0f, 0, 131.0f, 0, 0x417 };
static UnkStruct_11 D_800C8064 = { NULL, NULL, 4.31f, 0.0f, -6.01f, 0.0f, 0.0f, 0.0f, 0, 73.0f, 0, 0x417 };
static UnkStruct_11 D_800C8094 = { NULL, NULL, 4.3f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 32.0f, 0, 0x417 };
static UnkStruct_11 D_800C80C4 = { NULL, NULL, 0.3f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C80F4 = { NULL, NULL, 0.3f, 0.0f, -6.01f, 0.0f, 0.0f, 0.0f, 0, 57.0f, 0, 0x417 };
static UnkStruct_11 D_800C8124 = { NULL, NULL, 0.3f, 0.0f, -10.01f, 0.0f, 0.0f, 0.0f, 0, 109.0f, 0, 0x417 };
static UnkStruct_11 D_800C8154 = { NULL, NULL, 0.3f, 0.0f, -15.24f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x417 };
static UnkStruct_11 D_800C8184 = { NULL, NULL, -3.71f, 0.0f, -6.01f, 0.0f, 0.0f, 0.0f, 0, 95.0f, 0, 0x417 };
static UnkStruct_11 D_800C81B4 = { NULL, NULL, -3.71f, 0.0f, -10.01f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x417 };
static UnkStruct_11 D_800C81E4 = { NULL, NULL, -9.18f, 0.0f, -6.01f, 0.0f, 0.0f, 0.0f, 0, 180.0f, 0, 0x417 };
static UnkStruct_11 D_800C8214 = { NULL, NULL, -7.71f, 0.0f, -10.01f, 0.0f, 0.0f, 0.0f, 0, 212.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8244[19] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C7F44,
  &D_800C7F74,
  &D_800C7FA4,
  &D_800C7FD4,
  &D_800C8004,
  &D_800C8034,
  &D_800C8064,
  &D_800C8094,
  &D_800C80C4,
  &D_800C80F4,
  &D_800C8124,
  &D_800C8154,
  &D_800C8184,
  &D_800C81B4,
  &D_800C81E4,
  &D_800C8214,
  NULL,
};
static UnkStruct_11 D_800C8290 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x47E };
static UnkStruct_11 D_800C82C0 = { NULL, NULL, -3.71f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 201.0f, 0, 0x417 };
static UnkStruct_11 D_800C82F0 = { NULL, NULL, -7.71f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 233.0f, 0, 0x417 };
static UnkStruct_11 D_800C8320 = { NULL, NULL, -3.71f, 0.0f, 2.01f, 0.0f, 0.0f, 0.0f, 0, 57.0f, 0, 0x417 };
static UnkStruct_11 D_800C8350 = { NULL, NULL, -7.71f, 0.0f, 2.01f, 0.0f, 0.0f, 0.0f, 0, 93.0f, 0, 0x417 };
static UnkStruct_11 D_800C8380 = { NULL, NULL, -3.71f, 0.0f, 6.01f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C83B0 = { NULL, NULL, 0.3f, 0.0f, 6.01f, 0.0f, 0.0f, 0.0f, 0, 31.0f, 0, 0x417 };
static UnkStruct_11 D_800C83E0 = { NULL, NULL, -9.18f, 0.0f, 6.01f, 0.0f, 0.0f, 0.0f, 0, 185.0f, 0, 0x417 };
static UnkStruct_11 D_800C8410 = { NULL, NULL, -3.71f, 0.0f, 10.02f, 0.0f, 0.0f, 0.0f, 0, 42.0f, 0, 0x417 };
static UnkStruct_11 D_800C8440 = { NULL, NULL, 4.31f, 0.0f, 6.01f, 0.0f, 0.0f, 0.0f, 0, 108.0f, 0, 0x417 };
static UnkStruct_11 D_800C8470 = { NULL, NULL, 0.3f, 0.0f, 10.02f, 0.0f, 0.0f, 0.0f, 0, 78.0f, 0, 0x417 };
static UnkStruct_11 D_800C84A0 = { NULL, NULL, 4.31f, 0.0f, 10.02f, 0.0f, 0.0f, 0.0f, 0, 137.0f, 0, 0x417 };
static UnkStruct_11 D_800C84D0 = { NULL, NULL, -9.18f, 0.0f, 10.02f, 0.0f, 0.0f, 0.0f, 0, 169.0f, 0, 0x417 };
static UnkStruct_11 D_800C8500 = { NULL, NULL, -3.71f, 0.0f, 14.03f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x417 };
static UnkStruct_11 D_800C8530 = { NULL, NULL, -7.71f, 0.0f, 14.03f, 0.0f, 0.0f, 0.0f, 0, 212.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8560[18] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8290,
  &D_800C82C0,
  &D_800C82F0,
  &D_800C8320,
  &D_800C8350,
  &D_800C8380,
  &D_800C83B0,
  &D_800C83E0,
  &D_800C8410,
  &D_800C8440,
  &D_800C8470,
  &D_800C84A0,
  &D_800C84D0,
  &D_800C8500,
  &D_800C8530,
  NULL,
};
static UnkStruct_11 D_800C85A8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x47F };
static UnkStruct_11 D_800C85D8 = { NULL, NULL, -2.02f, 4.0f, -5.86f, 0.0f, 0.0f, 0.0f, 0, 85.0f, 0, 0x417 };
static UnkStruct_11 D_800C8608 = { NULL, NULL, 2.02f, 4.0f, -5.86f, 0.0f, 0.0f, 0.0f, 0, 130.0f, 0, 0x417 };
static UnkStruct_11 D_800C8638 = { NULL, NULL, 2.02f, 4.0f, -1.86f, 0.0f, 0.0f, 0.0f, 0, 70.0f, 0, 0x417 };
static UnkStruct_11 D_800C8668 = { NULL, NULL, -2.02f, 4.0f, -1.86f, 0.0f, 0.0f, 0.0f, 0, 47.0f, 0, 0x417 };
static UnkStruct_11 D_800C8698 = { NULL, NULL, -6.05f, 4.0f, -1.86f, 0.0f, 0.0f, 0.0f, 0, 118.0f, 0, 0x417 };
static UnkStruct_11 D_800C86C8 = { NULL, NULL, -6.05f, 4.0f, -5.86f, 0.0f, 0.0f, 0.0f, 0, 178.0f, 0, 0x417 };
static UnkStruct_11 D_800C86F8 = { NULL, NULL, -2.02f, 4.0f, -9.86f, 0.0f, 0.0f, 0.0f, 0, 198.0f, 0, 0x417 };
static UnkStruct_11 D_800C8728 = { NULL, NULL, 2.02f, 4.0f, -9.86f, 0.0f, 0.0f, 0.0f, 0, 183.0f, 0, 0x417 };
static UnkStruct_11 D_800C8758 = { NULL, NULL, 6.05f, 4.0f, -5.86f, 0.0f, 0.0f, 0.0f, 0, 175.0f, 0, 0x417 };
static UnkStruct_11 D_800C8788 = { NULL, NULL, 6.05f, 4.0f, -1.86f, 0.0f, 0.0f, 0.0f, 0, 164.0f, 0, 0x417 };
static UnkStruct_11 D_800C87B8 = { NULL, NULL, 6.05f, 4.0f, 2.14f, 0.0f, 0.0f, 0.0f, 0, 143.0f, 0, 0x417 };
static UnkStruct_11 D_800C87E8 = { NULL, NULL, 2.02f, 4.0f, 2.14f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0, 0x417 };
static UnkStruct_11 D_800C8818 = { NULL, NULL, -2.02f, 4.0f, 2.14f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C8848 = { NULL, NULL, -6.05f, 4.0f, 2.14f, 0.0f, 0.0f, 0.0f, 0, 104.0f, 0, 0x417 };
static UnkStruct_11 D_800C8878 = { NULL, NULL, -6.05f, 4.0f, 6.14f, 0.0f, 0.0f, 0.0f, 0, 192.0f, 0, 0x417 };
static UnkStruct_11 D_800C88A8 = { NULL, NULL, 2.02f, 4.0f, -13.86f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x417 };
static UnkStruct_11 *D_800C88D8[20] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C85A8,
  &D_800C85D8,
  &D_800C8608,
  &D_800C8638,
  &D_800C8668,
  &D_800C8698,
  &D_800C86C8,
  &D_800C86F8,
  &D_800C8728,
  &D_800C8758,
  &D_800C8788,
  &D_800C87B8,
  &D_800C87E8,
  &D_800C8818,
  &D_800C8848,
  &D_800C8878,
  &D_800C88A8,
  NULL,
};
static UnkStruct_11 D_800C8928 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x480 };
static UnkStruct_11 D_800C8958 = { NULL, NULL, 2.18f, 8.0f, 2.08f, 0.0f, 0.0f, 0.0f, 0, 110.0f, 0, 0x417 };
static UnkStruct_11 D_800C8988 = { NULL, NULL, 2.18f, 8.0f, -10.25f, 0.0f, 0.0f, 0.0f, 0, 170.0f, 0, 0x417 };
static UnkStruct_11 D_800C89B8 = { NULL, NULL, 2.18f, 8.0f, -2.03f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C89E8 = { NULL, NULL, 2.18f, 8.0f, -6.14f, 0.0f, 0.0f, 0.0f, 0, 61.0f, 0, 0x417 };
static UnkStruct_11 D_800C8A18 = { NULL, NULL, -1.93f, 8.0f, 2.08f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x417 };
static UnkStruct_11 D_800C8A48 = { NULL, NULL, -1.93f, 8.0f, -2.03f, 0.0f, 0.0f, 0.0f, 0, 37.0f, 0, 0x417 };
static UnkStruct_11 D_800C8A78 = { NULL, NULL, -1.93f, 8.0f, -6.14f, 0.0f, 0.0f, 0.0f, 0, 85.0f, 0, 0x417 };
static UnkStruct_11 D_800C8AA8 = { NULL, NULL, -1.93f, 8.0f, -10.25f, 0.0f, 0.0f, 0.0f, 0, 135.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8AD8[12] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8928,
  &D_800C8958,
  &D_800C8988,
  &D_800C89B8,
  &D_800C89E8,
  &D_800C8A18,
  &D_800C8A48,
  &D_800C8A78,
  &D_800C8AA8,
  NULL,
};
static UnkStruct_11 D_800C8B08 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x481 };
static UnkStruct_11 D_800C8B38 = { NULL, NULL, -2.01f, 8.0f, 10.15f, 0.0f, 0.0f, 0.0f, 0, 59.0f, 0, 0x417 };
static UnkStruct_11 D_800C8B68 = { NULL, NULL, -6.05f, 8.0f, 10.15f, 0.0f, 0.0f, 0.0f, 0, 147.0f, 0, 0x417 };
static UnkStruct_11 D_800C8B98 = { NULL, NULL, -6.05f, 8.0f, 6.13f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x417 };
static UnkStruct_11 D_800C8BC8 = { NULL, NULL, 6.06f, 8.0f, 10.15f, 0.0f, 0.0f, 0.0f, 0, 161.0f, 0, 0x417 };
static UnkStruct_11 D_800C8BF8 = { NULL, NULL, -2.01f, 8.0f, 6.13f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C8C28 = { NULL, NULL, 2.03f, 8.0f, 10.15f, 0.0f, 0.0f, 0.0f, 0, 84.0f, 0, 0x417 };
static UnkStruct_11 D_800C8C58 = { NULL, NULL, 2.03f, 8.0f, 6.13f, 0.0f, 0.0f, 0.0f, 0, 35.0f, 0, 0x417 };
static UnkStruct_11 D_800C8C88 = { NULL, NULL, 6.06f, 8.0f, 6.13f, 0.0f, 0.0f, 0.0f, 0, 125.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8CB8[12] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8B08,
  &D_800C8B38,
  &D_800C8B68,
  &D_800C8B98,
  &D_800C8BC8,
  &D_800C8BF8,
  &D_800C8C28,
  &D_800C8C58,
  &D_800C8C88,
  NULL,
};
static UnkStruct_11 D_800C8CE8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x482 };
static UnkStruct_11 D_800C8D18 = { NULL, NULL, -3.23f, 12.0f, 8.97f, 0.0f, 0.0f, 0.0f, 0, 36.0f, 0, 0x417 };
static UnkStruct_11 D_800C8D48 = { NULL, NULL, -3.23f, 12.0f, 4.86f, 0.0f, 0.0f, 0.0f, 0, 81.0f, 0, 0x417 };
static UnkStruct_11 D_800C8D78 = { NULL, NULL, 3.7f, 12.0f, 8.97f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C8DA8 = { NULL, NULL, 3.7f, 12.0f, 4.86f, 0.0f, 0.0f, 0.0f, 0, 52.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8DD8[8] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8CE8,
  &D_800C8D18,
  &D_800C8D48,
  &D_800C8D78,
  &D_800C8DA8,
  NULL,
};
static UnkStruct_11 D_800C8DF8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x483 };
static UnkStruct_11 D_800C8E28 = { NULL, NULL, 2.3f, 16.03f, 8.97f, 0.0f, 0.0f, 0.0f, 0, 5.0f, 0, 0x417 };
static UnkStruct_11 D_800C8E58 = { NULL, NULL, -1.81f, 16.03f, 8.97f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x417 };
static UnkStruct_11 D_800C8E88 = { NULL, NULL, -1.81f, 16.03f, 4.86f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0, 0x417 };
static UnkStruct_11 D_800C8EB8 = { NULL, NULL, 2.3f, 16.03f, 4.86f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x417 };
static UnkStruct_11 *D_800C8EE8[8] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8DF8,
  &D_800C8E28,
  &D_800C8E58,
  &D_800C8E88,
  &D_800C8EB8,
  NULL,
};
static UnkStruct_11 D_800C8F08 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x178 };
static UnkStruct_11 *D_800C8F38[4] = {
  &D_800C5EA4,
  &D_800C5E14,
  &D_800C8F08,
  NULL,
};
static UnkStruct_11 D_800C8F48 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x177 };
static UnkStruct_11 *D_800C8F78[2] = {
  &D_800C8F48,
  NULL,
};
static UnkStruct_11 D_800C8F80 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x179 };
static UnkStruct_11 *D_800C8FB0[2] = {
  &D_800C8F80,
  NULL,
};
static UnkStruct_11 D_800C8FB8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A2 };
static UnkStruct_11 D_800C8FE8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x498 };
static UnkStruct_11 D_800C9018 = { NULL, NULL, -14.0f, 0.0f, 22.0f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0, 0x417 };
static UnkStruct_11 D_800C9048 = { NULL, NULL, -13.5f, 0.0f, 18.5f, 0.0f, 0.0f, 0.0f, 0, 101.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9078 = { NULL, NULL, -16.5f, 0.0f, 18.5f, 0.0f, 0.0f, 0.0f, 0, 67.0f, 0, 0x3EF };
static UnkStruct_11 D_800C90A8 = { NULL, NULL, -17.0f, 0.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0, 36.0f, 0, 0x417 };
static UnkStruct_11 D_800C90D8 = { NULL, NULL, -13.5f, 0.0f, 15.5f, 0.0f, 0.0f, 0.0f, 0, 50.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9108 = { NULL, NULL, -13.55f, 2.94f, 18.45f, 0.0f, 0.0f, 0.0f, 0, 198.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9138 = { NULL, NULL, -13.55f, 3.94f, 22.45f, 0.0f, 0.0f, 0.0f, 0, 245.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9168 = { NULL, NULL, -17.0f, 4.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0, 124.0f, 0, 0x417 };
static UnkStruct_11 D_800C9198 = { NULL, NULL, -13.5f, 3.0f, 15.5f, 0.0f, 0.0f, 0.0f, 0, 164.0f, 0, 0x3EF };
static UnkStruct_11 D_800C91C8 = { NULL, NULL, -10.55f, 5.9f, 22.5f, 0.0f, 0.0f, 0.0f, 0, 136.0f, 0, 0x3EF };
static UnkStruct_11 D_800C91F8 = { NULL, NULL, -20.5f, 0.0f, 15.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9228 = { NULL, NULL, -19.5f, 6.0f, 10.5f, 0.0f, 0.0f, 0.0f, 0, 91.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9258 = { NULL, NULL, -20.5f, 3.0f, 15.5f, 0.0f, 0.0f, 0.0f, 0, 98.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9288 = { NULL, NULL, -19.5f, 6.0f, 7.5f, 0.0f, 0.0f, 0.0f, 0, 117.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C92B8[19] = {
  &D_800C5ED4,
  &D_800C8FB8,
  &D_800C5E14,
  &D_800C8FE8,
  &D_800C9018,
  &D_800C9048,
  &D_800C9078,
  &D_800C90A8,
  &D_800C90D8,
  &D_800C9108,
  &D_800C9138,
  &D_800C9168,
  &D_800C9198,
  &D_800C91C8,
  &D_800C91F8,
  &D_800C9228,
  &D_800C9258,
  &D_800C9288,
  NULL,
};
static UnkStruct_11 D_800C9304 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A3 };
static UnkStruct_11 D_800C9334 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x499 };
static UnkStruct_11 D_800C9364 = { NULL, NULL, -9.92f, 0.0f, 4.67f, 17.77f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800C9394 = { NULL, NULL, -9.3f, 4.0f, 4.99f, 17.77f, 0.0f, 0.0f, 0, 91.0f, 0, 0x3EF };
static UnkStruct_11 D_800C93C4 = { NULL, NULL, -9.3f, 7.0f, 4.99f, 17.77f, 0.0f, 0.0f, 0, 198.0f, 0, 0x3EF };
static UnkStruct_11 D_800C93F4 = { NULL, NULL, -8.38f, 5.9f, 7.85f, 17.77f, 0.0f, 0.0f, 0, 19.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9424 = { NULL, NULL, -7.46f, 5.9f, 10.7f, 17.77f, 0.0f, 0.0f, 0, 53.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9454 = { NULL, NULL, -10.32f, 5.9f, 11.62f, 17.77f, 0.0f, 0.0f, 0, 85.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9484 = { NULL, NULL, -11.24f, 5.9f, 8.76f, 17.77f, 0.0f, 0.0f, 0, 66.0f, 0, 0x3EF };
static UnkStruct_11 D_800C94B4 = { NULL, NULL, -8.71f, 8.9f, 8.47f, 17.77f, 0.0f, 0.0f, 0, 147.0f, 0, 0x417 };
static UnkStruct_11 D_800C94E4 = { NULL, NULL, -12.69f, 0.0f, -2.39f, -28.25f, 0.0f, 0.0f, 0, 33.0f, 0, 0x417 };
static UnkStruct_11 D_800C9514 = { NULL, NULL, -10.8f, 0.0f, -5.91f, -28.25f, 0.0f, 0.0f, 0, 52.0f, 0, 0x417 };
static UnkStruct_11 D_800C9544 = { NULL, NULL, -8.7f, 0.0f, -8.76f, -28.25f, 0.0f, 0.0f, 0, 107.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9574 = { NULL, NULL, -8.7f, 3.0f, -8.76f, -28.25f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 D_800C95A4 = { NULL, NULL, -11.34f, 0.0f, -10.18f, -28.25f, 0.0f, 0.0f, 0, 129.0f, 0, 0x3EF };
static UnkStruct_11 D_800C95D4 = { NULL, NULL, -12.69f, 4.0f, -2.39f, -28.25f, 0.0f, 0.0f, 0, 140.0f, 0, 0x417 };
static UnkStruct_11 D_800C9604 = { NULL, NULL, -10.59f, 4.0f, -5.23f, -28.25f, 0.0f, 0.0f, 0, 155.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C9634[20] = {
  &D_800C5ED4,
  &D_800C9304,
  &D_800C5E14,
  &D_800C9334,
  &D_800C9364,
  &D_800C9394,
  &D_800C93C4,
  &D_800C93F4,
  &D_800C9424,
  &D_800C9454,
  &D_800C9484,
  &D_800C94B4,
  &D_800C94E4,
  &D_800C9514,
  &D_800C9544,
  &D_800C9574,
  &D_800C95A4,
  &D_800C95D4,
  &D_800C9604,
  NULL,
};
static UnkStruct_11 D_800C9684 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A4 };
static UnkStruct_11 D_800C96B4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x49A };
static UnkStruct_11 D_800C96E4 = { NULL, NULL, -20.0f, 6.03f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 30.0f, 0, 0x417 };
static UnkStruct_11 D_800C9714 = { NULL, NULL, -20.0f, 6.03f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 101.0f, 0, 0x417 };
static UnkStruct_11 D_800C9744 = { NULL, NULL, -23.5f, 6.03f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9774 = { NULL, NULL, -23.5f, 6.03f, 1.0f, 0.0f, 0.0f, 0.0f, 0, 48.0f, 0, 0x3EF };
static UnkStruct_11 D_800C97A4 = { NULL, NULL, -23.5f, 9.03f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 124.0f, 0, 0x3EF };
static UnkStruct_11 D_800C97D4 = { NULL, NULL, -20.0f, 6.03f, -3.0f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9804 = { NULL, NULL, -26.0f, 6.03f, 8.0f, 0.0f, 0.0f, 0.0f, 0, 144.0f, 0, 0x417 };
static UnkStruct_11 D_800C9834 = { NULL, NULL, -26.5f, 6.03f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 77.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9864 = { NULL, NULL, -26.5f, 6.03f, 1.0f, 0.0f, 0.0f, 0.0f, 0, 94.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9894 = { NULL, NULL, -24.0f, 6.03f, -2.5f, 0.0f, 0.0f, 0.0f, 0, 134.0f, 0, 0x417 };
static UnkStruct_11 D_800C98C4 = { NULL, NULL, -20.0f, 6.03f, -6.0f, 0.0f, 0.0f, 0.0f, 0, 154.0f, 0, 0x3EF };
static UnkStruct_11 D_800C98F4 = { NULL, NULL, -20.0f, 9.03f, -3.0f, 0.0f, 0.0f, 0.0f, 0, 210.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9924 = { NULL, NULL, -23.0f, 6.03f, -6.0f, 0.0f, 0.0f, 0.0f, 0, 178.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9954 = { NULL, NULL, -23.0f, 9.03f, -6.0f, 0.0f, 0.0f, 0.0f, 0, 247.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C9984[19] = {
  &D_800C5ED4,
  &D_800C9684,
  &D_800C5E14,
  &D_800C96B4,
  &D_800C96E4,
  &D_800C9714,
  &D_800C9744,
  &D_800C9774,
  &D_800C97A4,
  &D_800C97D4,
  &D_800C9804,
  &D_800C9834,
  &D_800C9864,
  &D_800C9894,
  &D_800C98C4,
  &D_800C98F4,
  &D_800C9924,
  &D_800C9954,
  NULL,
};
static UnkStruct_11 D_800C99D0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A5 };
static UnkStruct_11 D_800C9A00 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x49B };
static UnkStruct_11 D_800C9A30 = { NULL, NULL, 8.0f, 0.0f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9A60 = { NULL, NULL, 8.0f, 0.0f, -22.5f, 0.0f, 0.0f, 0.0f, 0, 44.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9A90 = { NULL, NULL, 8.0f, 3.0f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 117.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9AC0 = { NULL, NULL, 11.5f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0, 0x417 };
static UnkStruct_11 D_800C9AF0 = { NULL, NULL, 15.0f, 0.0f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 56.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9B20 = { NULL, NULL, 14.0f, 0.0f, -16.0f, 0.0f, 0.0f, 0.0f, 0, 68.0f, 0, 0x417 };
static UnkStruct_11 D_800C9B50 = { NULL, NULL, 17.5f, 0.0f, -16.5f, 0.0f, 0.0f, 0.0f, 0, 80.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9B80 = { NULL, NULL, 20.5f, 0.0f, -16.5f, 0.0f, 0.0f, 0.0f, 0, 97.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9BB0 = { NULL, NULL, 17.5f, 3.0f, -16.5f, 0.0f, 0.0f, 0.0f, 0, 216.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9BE0 = { NULL, NULL, 20.5f, 3.0f, -16.5f, 0.0f, 0.0f, 0.0f, 0, 245.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9C10 = { NULL, NULL, 17.5f, 0.0f, -13.5f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9C40 = { NULL, NULL, 20.5f, 0.0f, -13.5f, 0.0f, 0.0f, 0.0f, 0, 132.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9C70 = { NULL, NULL, 20.0f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f, 0, 155.0f, 0, 0x417 };
static UnkStruct_11 D_800C9CA0 = { NULL, NULL, 24.0f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f, 0, 196.0f, 0, 0x417 };
static UnkStruct_11 D_800C9CD0 = { NULL, NULL, 27.5f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f, 0, 216.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9D00 = { NULL, NULL, 19.5f, 0.0f, -6.5f, 0.0f, 0.0f, 0.0f, 0, 188.0f, 0, 0x3EF };
static UnkStruct_11 *D_800C9D30[21] = {
  &D_800C5ED4,
  &D_800C99D0,
  &D_800C5E14,
  &D_800C9A00,
  &D_800C9A30,
  &D_800C9A60,
  &D_800C9A90,
  &D_800C9AC0,
  &D_800C9AF0,
  &D_800C9B20,
  &D_800C9B50,
  &D_800C9B80,
  &D_800C9BB0,
  &D_800C9BE0,
  &D_800C9C10,
  &D_800C9C40,
  &D_800C9C70,
  &D_800C9CA0,
  &D_800C9CD0,
  &D_800C9D00,
  NULL,
};
static UnkStruct_11 D_800C9D84 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A6 };
static UnkStruct_11 D_800C9DB4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x49C };
static UnkStruct_11 D_800C9DE4 = { NULL, NULL, 2.0f, 6.03f, 20.0f, 0.0f, 0.0f, 0.0f, 0, 42.0f, 0, 0x417 };
static UnkStruct_11 D_800C9E14 = { NULL, NULL, 2.0f, 6.03f, 23.5f, 0.0f, 0.0f, 0.0f, 0, 22.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9E44 = { NULL, NULL, 2.0f, 6.03f, 26.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9E74 = { NULL, NULL, 6.0f, 6.03f, 20.0f, 0.0f, 0.0f, 0.0f, 0, 107.0f, 0, 0x417 };
static UnkStruct_11 D_800C9EA4 = { NULL, NULL, 5.0f, 6.03f, 23.5f, 0.0f, 0.0f, 0.0f, 0, 74.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9ED4 = { NULL, NULL, 9.5f, 6.03f, 20.5f, 0.0f, 0.0f, 0.0f, 0, 138.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9F04 = { NULL, NULL, 5.5f, 6.03f, 27.0f, 0.0f, 0.0f, 0.0f, 0, 62.0f, 0, 0x417 };
static UnkStruct_11 D_800C9F34 = { NULL, NULL, 8.0f, 6.03f, 23.5f, 0.0f, 0.0f, 0.0f, 0, 99.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9F64 = { NULL, NULL, 9.0f, 6.03f, 26.5f, 0.0f, 0.0f, 0.0f, 0, 123.0f, 0, 0x3EF };
static UnkStruct_11 D_800C9F94 = { NULL, NULL, 13.0f, 6.03f, 22.0f, 0.0f, 0.0f, 0.0f, 0, 156.0f, 0, 0x417 };
static UnkStruct_11 D_800C9FC4 = { NULL, NULL, 14.0f, 6.03f, 18.0f, 0.0f, 0.0f, 0.0f, 0, 161.0f, 0, 0x417 };
static UnkStruct_11 D_800C9FF4 = { NULL, NULL, 13.5f, 6.03f, 14.5f, 0.0f, 0.0f, 0.0f, 0, 171.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA024 = { NULL, NULL, 13.5f, 9.03f, 14.5f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA054 = { NULL, NULL, 16.5f, 6.03f, 14.5f, 0.0f, 0.0f, 0.0f, 0, 200.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CA084[19] = {
  &D_800C5ED4,
  &D_800C9D84,
  &D_800C5E14,
  &D_800C9DB4,
  &D_800C9DE4,
  &D_800C9E14,
  &D_800C9E44,
  &D_800C9E74,
  &D_800C9EA4,
  &D_800C9ED4,
  &D_800C9F04,
  &D_800C9F34,
  &D_800C9F64,
  &D_800C9F94,
  &D_800C9FC4,
  &D_800C9FF4,
  &D_800CA024,
  &D_800CA054,
  NULL,
};
static UnkStruct_11 D_800CA0D0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A7 };
static UnkStruct_11 D_800CA100 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x49D };
static UnkStruct_11 D_800CA130 = { NULL, NULL, 9.5f, 9.03f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA160 = { NULL, NULL, 9.5f, 6.03f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA190 = { NULL, NULL, 16.5f, 9.03f, -17.5f, 0.0f, 0.0f, 0.0f, 0, 154.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA1C0 = { NULL, NULL, 13.0f, 6.03f, -21.0f, 0.0f, 0.0f, 0.0f, 0, 20.0f, 0, 0x417 };
static UnkStruct_11 D_800CA1F0 = { NULL, NULL, 13.5f, 6.03f, -17.5f, 0.0f, 0.0f, 0.0f, 0, 44.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA220 = { NULL, NULL, 16.5f, 6.03f, -20.5f, 0.0f, 0.0f, 0.0f, 0, 51.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA250 = { NULL, NULL, 16.5f, 6.03f, -17.5f, 0.0f, 0.0f, 0.0f, 0, 68.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA280 = { NULL, NULL, 19.5f, 9.03f, -10.5f, 0.0f, 0.0f, 0.0f, 0, 246.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA2B0 = { NULL, NULL, 16.0f, 6.03f, -14.0f, 0.0f, 0.0f, 0.0f, 0, 85.0f, 0, 0x417 };
static UnkStruct_11 D_800CA2E0 = { NULL, NULL, 22.5f, 6.03f, -14.5f, 0.0f, 0.0f, 0.0f, 0, 170.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA310 = { NULL, NULL, 19.5f, 6.03f, -13.5f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA340 = { NULL, NULL, 22.5f, 6.03f, -11.5f, 0.0f, 0.0f, 0.0f, 0, 189.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA370 = { NULL, NULL, 19.5f, 6.03f, -10.5f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA3A0 = { NULL, NULL, 19.5f, 6.03f, -7.5f, 0.0f, 0.0f, 0.0f, 0, 155.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA3D0 = { NULL, NULL, 23.0f, 6.03f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 224.0f, 0, 0x417 };
static UnkStruct_11 *D_800CA400[20] = {
  &D_800C5ED4,
  &D_800CA0D0,
  &D_800C5E14,
  &D_800CA100,
  &D_800CA130,
  &D_800CA160,
  &D_800CA190,
  &D_800CA1C0,
  &D_800CA1F0,
  &D_800CA220,
  &D_800CA250,
  &D_800CA280,
  &D_800CA2B0,
  &D_800CA2E0,
  &D_800CA310,
  &D_800CA340,
  &D_800CA370,
  &D_800CA3A0,
  &D_800CA3D0,
  NULL,
};
static UnkStruct_11 D_800CA450 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4A8 };
static UnkStruct_11 D_800CA480 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x49E };
static UnkStruct_11 D_800CA4B0 = { NULL, NULL, 8.64f, 5.9f, 8.1f, -23.51f, 0.0f, 0.0f, 0, 10.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA4E0 = { NULL, NULL, 7.44f, 5.9f, 10.85f, -23.51f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA510 = { NULL, NULL, 10.19f, 5.9f, 12.05f, -23.51f, 0.0f, 0.0f, 0, 23.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA540 = { NULL, NULL, 11.39f, 5.9f, 9.3f, -23.51f, 0.0f, 0.0f, 0, 31.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA570 = { NULL, NULL, 8.64f, 8.9f, 8.1f, -23.51f, 0.0f, 0.0f, 0, 99.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA5A0 = { NULL, NULL, 7.44f, 8.9f, 10.85f, -23.51f, 0.0f, 0.0f, 0, 89.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA5D0 = { NULL, NULL, 10.19f, 8.9f, 12.05f, -23.51f, 0.0f, 0.0f, 0, 115.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA600 = { NULL, NULL, 11.39f, 8.9f, 9.3f, -23.51f, 0.0f, 0.0f, 0, 125.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA630 = { NULL, NULL, 9.92f, 11.98f, 5.15f, -23.51f, 0.0f, 0.0f, 0, 183.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA660 = { NULL, NULL, 8.73f, 11.98f, 7.9f, -23.51f, 0.0f, 0.0f, 0, 177.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA690 = { NULL, NULL, 11.48f, 11.98f, 9.09f, -23.51f, 0.0f, 0.0f, 0, 194.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA6C0 = { NULL, NULL, 12.68f, 11.98f, 6.34f, -23.51f, 0.0f, 0.0f, 0, 200.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA6F0 = { NULL, NULL, 9.92f, 14.98f, 5.15f, -23.51f, 0.0f, 0.0f, 0, 289.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA720 = { NULL, NULL, 8.73f, 14.98f, 7.9f, -23.51f, 0.0f, 0.0f, 0, 280.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA750 = { NULL, NULL, 11.48f, 14.98f, 9.09f, -23.51f, 0.0f, 0.0f, 0, 302.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA780 = { NULL, NULL, 12.68f, 14.98f, 6.34f, -23.51f, 0.0f, 0.0f, 0, 310.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CA7B0[21] = {
  &D_800C5ED4,
  &D_800CA450,
  &D_800C5E14,
  &D_800CA480,
  &D_800CA4B0,
  &D_800CA4E0,
  &D_800CA510,
  &D_800CA540,
  &D_800CA570,
  &D_800CA5A0,
  &D_800CA5D0,
  &D_800CA600,
  &D_800CA630,
  &D_800CA660,
  &D_800CA690,
  &D_800CA6C0,
  &D_800CA6F0,
  &D_800CA720,
  &D_800CA750,
  &D_800CA780,
  NULL,
};
static UnkStruct_11 D_800CA804 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x1D8 };
static UnkStruct_11 *D_800CA834[4] = {
  &D_800C5ED4,
  &D_800C5E14,
  &D_800CA804,
  NULL,
};
static UnkStruct_11 D_800CA844 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x1D7 };
static UnkStruct_11 *D_800CA874[2] = {
  &D_800CA844,
  NULL,
};
static UnkStruct_11 D_800CA87C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x1D9 };
static UnkStruct_11 *D_800CA8AC[2] = {
  &D_800CA87C,
  NULL,
};
static UnkStruct_11 D_800CA8B4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C3 };
static UnkStruct_11 D_800CA8E4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4B9 };
static UnkStruct_11 D_800CA914 = { NULL, NULL, -8.95f, 0.0f, 13.08f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800CA944 = { NULL, NULL, -4.95f, 0.0f, 13.08f, 0.0f, 0.0f, 0.0f, 0, 29.0f, 0, 0x417 };
static UnkStruct_11 D_800CA974 = { NULL, NULL, -9.45f, 0.0f, 16.58f, 0.0f, 0.0f, 0.0f, 0, 59.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA9A4 = { NULL, NULL, -6.45f, 0.0f, 16.58f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800CA9D4 = { NULL, NULL, -9.45f, 3.0f, 16.58f, 0.0f, 0.0f, 0.0f, 0, 152.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAA04 = { NULL, NULL, -6.45f, 3.0f, 16.58f, 0.0f, 0.0f, 0.0f, 0, 200.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAA34 = { NULL, NULL, -9.45f, 3.0f, 13.58f, 0.0f, 0.0f, 0.0f, 0, 111.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAA64 = { NULL, NULL, -2.95f, 0.0f, 17.08f, 0.0f, 0.0f, 0.0f, 0, 139.0f, 0, 0x417 };
static UnkStruct_11 D_800CAA94 = { NULL, NULL, -1.45f, 0.0f, 13.58f, 0.0f, 0.0f, 0.0f, 0, 109.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAAC4 = { NULL, NULL, -1.45f, 3.0f, 13.58f, 0.0f, 0.0f, 0.0f, 0, 237.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAAF4 = { NULL, NULL, -1.45f, 0.0f, 7.58f, 0.0f, 0.0f, 0.0f, 0, 221.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAB24 = { NULL, NULL, -1.45f, 0.0f, 10.58f, 0.0f, 0.0f, 0.0f, 0, 163.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAB54 = { NULL, NULL, 1.55f, 0.0f, 15.58f, 0.0f, 0.0f, 0.0f, 0, 231.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAB84 = { NULL, NULL, 2.05f, 0.0f, 12.08f, 0.0f, 0.0f, 0.0f, 0, 196.0f, 0, 0x417 };
static UnkStruct_11 *D_800CABB4[19] = {
  &D_800C5F04,
  &D_800CA8B4,
  &D_800C5E14,
  &D_800CA8E4,
  &D_800CA914,
  &D_800CA944,
  &D_800CA974,
  &D_800CA9A4,
  &D_800CA9D4,
  &D_800CAA04,
  &D_800CAA34,
  &D_800CAA64,
  &D_800CAA94,
  &D_800CAAC4,
  &D_800CAAF4,
  &D_800CAB24,
  &D_800CAB54,
  &D_800CAB84,
  NULL,
};
static UnkStruct_11 D_800CAC00 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C4 };
static UnkStruct_11 D_800CAC30 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BA };
static UnkStruct_11 D_800CAC60 = { NULL, NULL, 8.55f, 0.02f, -6.96f, 0.0f, 0.0f, 0.0f, 0, 184.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAC90 = { NULL, NULL, 11.55f, 3.02f, -6.96f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x3EF };
static UnkStruct_11 D_800CACC0 = { NULL, NULL, 15.05f, 0.02f, -6.46f, 0.0f, 0.0f, 0.0f, 0, 201.0f, 0, 0x417 };
static UnkStruct_11 D_800CACF0 = { NULL, NULL, 11.55f, 0.02f, -6.96f, 0.0f, 0.0f, 0.0f, 0, 154.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAD20 = { NULL, NULL, 11.55f, 4.02f, -2.96f, 0.0f, 0.0f, 0.0f, 0, 238.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAD50 = { NULL, NULL, 7.05f, 0.02f, -3.46f, 0.0f, 0.0f, 0.0f, 0, 222.0f, 0, 0x417 };
static UnkStruct_11 D_800CAD80 = { NULL, NULL, 11.05f, 0.02f, -3.46f, 0.0f, 0.0f, 0.0f, 0, 133.0f, 0, 0x417 };
static UnkStruct_11 D_800CADB0 = { NULL, NULL, 11.55f, 0.02f, 0.04f, 0.0f, 0.0f, 0.0f, 0, 109.0f, 0, 0x3EF };
static UnkStruct_11 D_800CADE0 = { NULL, NULL, 13.55f, 3.02f, 0.04f, 0.0f, 0.0f, 0.0f, 0, 120.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAE10 = { NULL, NULL, 17.05f, 3.02f, -0.46f, 0.0f, 0.0f, 0.0f, 0, 106.0f, 0, 0x417 };
static UnkStruct_11 D_800CAE40 = { NULL, NULL, 14.55f, 0.02f, -2.96f, 0.0f, 0.0f, 0.0f, 0, 96.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAE70 = { NULL, NULL, 14.55f, 0.02f, 0.04f, 0.0f, 0.0f, 0.0f, 0, 21.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAEA0 = { NULL, NULL, 17.55f, 0.02f, -2.96f, 0.0f, 0.0f, 0.0f, 0, 67.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAED0 = { NULL, NULL, 17.55f, 0.02f, 0.04f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CAF00 = { NULL, NULL, 17.05f, 0.02f, 3.54f, 0.0f, 0.0f, 0.0f, 0, 50.0f, 0, 0x417 };
static UnkStruct_11 *D_800CAF30[20] = {
  &D_800C5F04,
  &D_800CAC00,
  &D_800C5E14,
  &D_800CAC30,
  &D_800CAC60,
  &D_800CAC90,
  &D_800CACC0,
  &D_800CACF0,
  &D_800CAD20,
  &D_800CAD50,
  &D_800CAD80,
  &D_800CADB0,
  &D_800CADE0,
  &D_800CAE10,
  &D_800CAE40,
  &D_800CAE70,
  &D_800CAEA0,
  &D_800CAED0,
  &D_800CAF00,
  NULL,
};
static UnkStruct_11 D_800CAF80 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C5 };
static UnkStruct_11 D_800CAFB0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BB };
static UnkStruct_11 D_800CAFE0 = { NULL, NULL, -12.95f, 6.02f, 7.58f, 0.0f, 0.0f, 0.0f, 0, 82.0f, 0, 0x417 };
static UnkStruct_11 D_800CB010 = { NULL, NULL, -12.45f, 6.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB040 = { NULL, NULL, -9.45f, 6.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 9.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB070 = { NULL, NULL, -9.45f, 6.02f, 1.08f, 0.0f, 0.0f, 0.0f, 0, 93.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB0A0 = { NULL, NULL, -12.45f, 6.02f, 1.08f, 0.0f, 0.0f, 0.0f, 0, 56.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB0D0 = { NULL, NULL, -12.95f, 6.02f, 11.58f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0, 0x417 };
static UnkStruct_11 D_800CB100 = { NULL, NULL, -15.95f, 6.02f, 0.58f, 0.0f, 0.0f, 0.0f, 0, 244.0f, 0, 0x417 };
static UnkStruct_11 D_800CB130 = { NULL, NULL, -15.45f, 6.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 37.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB160 = { NULL, NULL, -15.45f, 9.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 240.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB190 = { NULL, NULL, -16.45f, 6.02f, 7.08f, 0.0f, 0.0f, 0.0f, 0, 212.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB1C0 = { NULL, NULL, -18.45f, 6.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 160.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB1F0 = { NULL, NULL, -12.45f, 6.02f, -1.92f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB220 = { NULL, NULL, -6.45f, 6.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 203.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB250 = { NULL, NULL, -9.45f, 9.02f, 4.08f, 0.0f, 0.0f, 0.0f, 0, 138.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB280 = { NULL, NULL, -8.95f, 6.02f, -2.42f, 0.0f, 0.0f, 0.0f, 0, 207.0f, 0, 0x417 };
static UnkStruct_11 *D_800CB2B0[20] = {
  &D_800C5F04,
  &D_800CAF80,
  &D_800C5E14,
  &D_800CAFB0,
  &D_800CAFE0,
  &D_800CB010,
  &D_800CB040,
  &D_800CB070,
  &D_800CB0A0,
  &D_800CB0D0,
  &D_800CB100,
  &D_800CB130,
  &D_800CB160,
  &D_800CB190,
  &D_800CB1C0,
  &D_800CB1F0,
  &D_800CB220,
  &D_800CB250,
  &D_800CB280,
  NULL,
};
static UnkStruct_11 D_800CB300 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C6 };
static UnkStruct_11 D_800CB330 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BC };
static UnkStruct_11 D_800CB360 = { NULL, NULL, -25.42f, 15.0f, -9.07f, 0.0f, 0.0f, 0.0f, 0, 172.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB390 = { NULL, NULL, -25.42f, 12.0f, -6.07f, 0.0f, 0.0f, 0.0f, 0, 134.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB3C0 = { NULL, NULL, -16.92f, 12.0f, -12.57f, 0.0f, 0.0f, 0.0f, 0, 164.0f, 0, 0x417 };
static UnkStruct_11 D_800CB3F0 = { NULL, NULL, -18.42f, 12.0f, -9.07f, 0.0f, 0.0f, 0.0f, 0, 126.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB420 = { NULL, NULL, -25.42f, 12.0f, -9.07f, 0.0f, 0.0f, 0.0f, 0, 66.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB450 = { NULL, NULL, -20.42f, 15.0f, -12.07f, 0.0f, 0.0f, 0.0f, 0, 201.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB480 = { NULL, NULL, -27.42f, 15.0f, -15.07f, 0.0f, 0.0f, 0.0f, 0, 101.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB4B0 = { NULL, NULL, -27.42f, 12.0f, -15.07f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB4E0 = { NULL, NULL, -27.42f, 12.0f, -12.07f, 0.0f, 0.0f, 0.0f, 0, 17.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB510 = { NULL, NULL, -24.42f, 19.0f, -12.57f, 0.0f, 0.0f, 0.0f, 0, 235.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB540 = { NULL, NULL, -24.42f, 16.0f, -12.57f, 0.0f, 0.0f, 0.0f, 0, 132.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB570 = { NULL, NULL, -20.42f, 12.0f, -15.07f, 0.0f, 0.0f, 0.0f, 0, 110.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB5A0 = { NULL, NULL, -20.42f, 12.0f, -12.07f, 0.0f, 0.0f, 0.0f, 0, 81.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB5D0 = { NULL, NULL, -23.92f, 12.0f, -12.57f, 0.0f, 0.0f, 0.0f, 0, 47.0f, 0, 0x417 };
static UnkStruct_11 D_800CB600 = { NULL, NULL, -21.92f, 12.0f, -8.57f, 0.0f, 0.0f, 0.0f, 0, 92.0f, 0, 0x417 };
static UnkStruct_11 *D_800CB630[20] = {
  &D_800C5F04,
  &D_800CB300,
  &D_800C5E14,
  &D_800CB330,
  &D_800CB360,
  &D_800CB390,
  &D_800CB3C0,
  &D_800CB3F0,
  &D_800CB420,
  &D_800CB450,
  &D_800CB480,
  &D_800CB4B0,
  &D_800CB4E0,
  &D_800CB510,
  &D_800CB540,
  &D_800CB570,
  &D_800CB5A0,
  &D_800CB5D0,
  &D_800CB600,
  NULL,
};
static UnkStruct_11 D_800CB680 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C7 };
static UnkStruct_11 D_800CB6B0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BD };
static UnkStruct_11 D_800CB6E0 = { NULL, NULL, 3.05f, 6.02f, 3.54f, 0.0f, 0.0f, 0.0f, 0, 60.0f, 0, 0x417 };
static UnkStruct_11 D_800CB710 = { NULL, NULL, 3.05f, 6.02f, -0.46f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0, 0x417 };
static UnkStruct_11 D_800CB740 = { NULL, NULL, 2.55f, 6.02f, 7.04f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB770 = { NULL, NULL, -0.45f, 6.02f, 7.04f, 0.0f, 0.0f, 0.0f, 0, 21.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB7A0 = { NULL, NULL, -2.45f, 6.02f, 7.54f, 0.0f, 0.0f, 0.0f, 0, 156.0f, 0, 0x417 };
static UnkStruct_11 D_800CB7D0 = { NULL, NULL, -0.45f, 6.02f, 10.04f, 0.0f, 0.0f, 0.0f, 0, 170.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB800 = { NULL, NULL, -0.45f, 9.02f, 7.04f, 0.0f, 0.0f, 0.0f, 0, 135.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB830 = { NULL, NULL, 3.05f, 6.02f, 10.54f, 0.0f, 0.0f, 0.0f, 0, 99.0f, 0, 0x417 };
static UnkStruct_11 D_800CB860 = { NULL, NULL, 6.55f, 6.02f, 4.04f, 0.0f, 0.0f, 0.0f, 0, 73.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB890 = { NULL, NULL, 6.55f, 6.02f, 1.04f, 0.0f, 0.0f, 0.0f, 0, 112.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB8C0 = { NULL, NULL, 6.55f, 6.02f, -1.96f, 0.0f, 0.0f, 0.0f, 0, 160.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB8F0 = { NULL, NULL, 6.55f, 9.02f, 4.04f, 0.0f, 0.0f, 0.0f, 0, 219.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB920 = { NULL, NULL, 6.55f, 9.02f, 1.04f, 0.0f, 0.0f, 0.0f, 0, 246.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB950 = { NULL, NULL, 5.55f, 6.02f, 7.04f, 0.0f, 0.0f, 0.0f, 0, 132.0f, 0, 0x3EF };
static UnkStruct_11 D_800CB980 = { NULL, NULL, 10.05f, 6.02f, 3.54f, 0.0f, 0.0f, 0.0f, 0, 214.0f, 0, 0x417 };
static UnkStruct_11 *D_800CB9B0[20] = {
  &D_800C5F04,
  &D_800CB680,
  &D_800C5E14,
  &D_800CB6B0,
  &D_800CB6E0,
  &D_800CB710,
  &D_800CB740,
  &D_800CB770,
  &D_800CB7A0,
  &D_800CB7D0,
  &D_800CB800,
  &D_800CB830,
  &D_800CB860,
  &D_800CB890,
  &D_800CB8C0,
  &D_800CB8F0,
  &D_800CB920,
  &D_800CB950,
  &D_800CB980,
  NULL,
};
static UnkStruct_11 D_800CBA00 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C8 };
static UnkStruct_11 D_800CBA30 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BE };
static UnkStruct_11 D_800CBA60 = { NULL, NULL, 5.56f, 15.0f, 15.1f, 0.0f, 0.0f, 0.0f, 0, 300.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBA90 = { NULL, NULL, 2.06f, 12.0f, 14.6f, 0.0f, 0.0f, 0.0f, 0, 173.0f, 0, 0x417 };
static UnkStruct_11 D_800CBAC0 = { NULL, NULL, -1.44f, 15.0f, 12.57f, 0.0f, 0.0f, 0.0f, 0, 204.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBAF0 = { NULL, NULL, 5.56f, 12.0f, 15.1f, 0.0f, 0.0f, 0.0f, 0, 181.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBB20 = { NULL, NULL, -5.44f, 16.0f, 12.57f, 0.0f, 0.0f, 0.0f, 0, 150.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBB50 = { NULL, NULL, -5.44f, 15.0f, 16.57f, 0.0f, 0.0f, 0.0f, 0, 224.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBB80 = { NULL, NULL, -1.44f, 12.0f, 15.57f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBBB0 = { NULL, NULL, -1.44f, 12.0f, 12.57f, 0.0f, 0.0f, 0.0f, 0, 93.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBBE0 = { NULL, NULL, -5.44f, 12.0f, 16.57f, 0.0f, 0.0f, 0.0f, 0, 77.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBC10 = { NULL, NULL, -4.94f, 12.0f, 13.07f, 0.0f, 0.0f, 0.0f, 0, 35.0f, 0, 0x417 };
static UnkStruct_11 D_800CBC40 = { NULL, NULL, -8.94f, 12.0f, 17.07f, 0.0f, 0.0f, 0.0f, 0, 67.0f, 0, 0x417 };
static UnkStruct_11 D_800CBC70 = { NULL, NULL, -8.94f, 16.0f, 13.07f, 0.0f, 0.0f, 0.0f, 0, 102.0f, 0, 0x417 };
static UnkStruct_11 D_800CBCA0 = { NULL, NULL, -8.94f, 12.0f, 13.07f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 *D_800CBCD0[18] = {
  &D_800C5F04,
  &D_800CBA00,
  &D_800C5E14,
  &D_800CBA30,
  &D_800CBA60,
  &D_800CBA90,
  &D_800CBAC0,
  &D_800CBAF0,
  &D_800CBB20,
  &D_800CBB50,
  &D_800CBB80,
  &D_800CBBB0,
  &D_800CBBE0,
  &D_800CBC10,
  &D_800CBC40,
  &D_800CBC70,
  &D_800CBCA0,
  NULL,
};
static UnkStruct_11 D_800CBD18 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4C9 };
static UnkStruct_11 D_800CBD48 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4BF };
static UnkStruct_11 D_800CBD78 = { NULL, NULL, 20.52f, 21.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 292.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBDA8 = { NULL, NULL, 20.52f, 21.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 299.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBDD8 = { NULL, NULL, 23.52f, 21.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBE08 = { NULL, NULL, 23.52f, 21.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 303.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBE38 = { NULL, NULL, 20.52f, 18.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 214.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBE68 = { NULL, NULL, 20.52f, 18.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 205.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBE98 = { NULL, NULL, 23.52f, 18.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBEC8 = { NULL, NULL, 23.52f, 18.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 199.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBEF8 = { NULL, NULL, 20.52f, 15.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 115.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBF28 = { NULL, NULL, 20.52f, 15.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 99.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBF58 = { NULL, NULL, 23.52f, 15.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 122.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBF88 = { NULL, NULL, 23.52f, 15.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 112.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBFB8 = { NULL, NULL, 20.52f, 12.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CBFE8 = { NULL, NULL, 20.52f, 12.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 9.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC018 = { NULL, NULL, 23.52f, 12.0f, 12.6f, 0.0f, 0.0f, 0.0f, 0, 19.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC048 = { NULL, NULL, 23.52f, 12.0f, 15.6f, 0.0f, 0.0f, 0.0f, 0, 12.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CC078[21] = {
  &D_800C5F04,
  &D_800CBD18,
  &D_800C5E14,
  &D_800CBD48,
  &D_800CBD78,
  &D_800CBDA8,
  &D_800CBDD8,
  &D_800CBE08,
  &D_800CBE38,
  &D_800CBE68,
  &D_800CBE98,
  &D_800CBEC8,
  &D_800CBEF8,
  &D_800CBF28,
  &D_800CBF58,
  &D_800CBF88,
  &D_800CBFB8,
  &D_800CBFE8,
  &D_800CC018,
  &D_800CC048,
  NULL,
};
static UnkStruct_11 D_800CC0CC = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x230 };
static UnkStruct_11 *D_800CC0FC[4] = {
  &D_800C5F04,
  &D_800C5E14,
  &D_800CC0CC,
  NULL,
};
static UnkStruct_11 D_800CC10C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x22E };
static UnkStruct_11 *D_800CC13C[2] = {
  &D_800CC10C,
  NULL,
};
static UnkStruct_11 D_800CC144 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x22F };
static UnkStruct_11 *D_800CC174[2] = {
  &D_800CC144,
  NULL,
};
static UnkStruct_11 D_800CC17C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F3 };
static UnkStruct_11 D_800CC1AC = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4DD };
static UnkStruct_11 D_800CC1DC = { NULL, NULL, 27.68f, 4.0f, 14.5f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC20C = { NULL, NULL, 26.18f, 3.0f, 5.5f, 0.0f, 0.0f, 0.0f, 0, 203.0f, 0, 0x417 };
static UnkStruct_11 D_800CC23C = { NULL, NULL, 23.68f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0, 231.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC26C = { NULL, NULL, 26.68f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0, 131.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC29C = { NULL, NULL, 26.68f, 3.0f, 9.0f, 0.0f, 0.0f, 0.0f, 0, 226.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC2CC = { NULL, NULL, 30.68f, 4.0f, 11.5f, 0.0f, 0.0f, 0.0f, 0, 182.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC2FC = { NULL, NULL, 29.68f, 4.0f, 5.5f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC32C = { NULL, NULL, 23.68f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0, 166.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC35C = { NULL, NULL, 26.68f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0, 95.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC38C = { NULL, NULL, 26.68f, 0.0f, 9.0f, 0.0f, 0.0f, 0.0f, 0, 72.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC3BC = { NULL, NULL, 30.68f, 4.0f, 14.5f, 0.0f, 0.0f, 0.0f, 0, 146.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC3EC = { NULL, NULL, 30.18f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x417 };
static UnkStruct_11 D_800CC41C = { NULL, NULL, 30.18f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 45.0f, 0, 0x417 };
static UnkStruct_11 D_800CC44C = { NULL, NULL, 26.68f, 0.0f, 14.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800CC47C = { NULL, NULL, 30.18f, 0.0f, 14.0f, 0.0f, 0.0f, 0.0f, 0, 22.0f, 0, 0x417 };
static UnkStruct_11 *D_800CC4AC[20] = {
  &D_800C5F34,
  &D_800CC17C,
  &D_800C5E14,
  &D_800CC1AC,
  &D_800CC1DC,
  &D_800CC20C,
  &D_800CC23C,
  &D_800CC26C,
  &D_800CC29C,
  &D_800CC2CC,
  &D_800CC2FC,
  &D_800CC32C,
  &D_800CC35C,
  &D_800CC38C,
  &D_800CC3BC,
  &D_800CC3EC,
  &D_800CC41C,
  &D_800CC44C,
  &D_800CC47C,
  NULL,
};
static UnkStruct_11 D_800CC4FC = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F4 };
static UnkStruct_11 D_800CC52C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4DE };
static UnkStruct_11 D_800CC55C = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 30.0f, 0, 0x417 };
static UnkStruct_11 D_800CC58C = { NULL, NULL, -4.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 131.0f, 0, 0x417 };
static UnkStruct_11 D_800CC5BC = { NULL, NULL, 0.0f, 0.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 65.0f, 0, 0x417 };
static UnkStruct_11 D_800CC5EC = { NULL, NULL, 4.0f, 0.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 77.0f, 0, 0x417 };
static UnkStruct_11 D_800CC61C = { NULL, NULL, -3.5f, 0.0f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC64C = { NULL, NULL, -3.5f, 0.0f, -6.5f, 0.0f, 0.0f, 0.0f, 0, 48.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC67C = { NULL, NULL, 3.5f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 54.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC6AC = { NULL, NULL, -0.5f, 4.0f, -1.5f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC6DC = { NULL, NULL, -0.5f, 4.0f, -4.5f, 0.0f, 0.0f, 0.0f, 0, 226.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC70C = { NULL, NULL, -3.5f, 3.0f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 158.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC73C = { NULL, NULL, 3.5f, 3.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0, 173.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC76C = { NULL, NULL, -3.5f, 3.0f, -6.5f, 0.0f, 0.0f, 0.0f, 0, 196.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC79C = { NULL, NULL, -7.0f, 0.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 103.0f, 0, 0x417 };
static UnkStruct_11 D_800CC7CC = { NULL, NULL, 4.0f, 4.0f, 1.5f, 0.0f, 0.0f, 0.0f, 0, 186.0f, 0, 0x417 };
static UnkStruct_11 *D_800CC7FC[19] = {
  &D_800C5F34,
  &D_800CC4FC,
  &D_800C5E14,
  &D_800CC52C,
  &D_800CC55C,
  &D_800CC58C,
  &D_800CC5BC,
  &D_800CC5EC,
  &D_800CC61C,
  &D_800CC64C,
  &D_800CC67C,
  &D_800CC6AC,
  &D_800CC6DC,
  &D_800CC70C,
  &D_800CC73C,
  &D_800CC76C,
  &D_800CC79C,
  &D_800CC7CC,
  NULL,
};
static UnkStruct_11 D_800CC848 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F5 };
static UnkStruct_11 D_800CC878 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4DF };
static UnkStruct_11 D_800CC8A8 = { NULL, NULL, -0.09f, 8.03f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800CC8D8 = { NULL, NULL, 3.41f, 8.03f, -0.5f, 0.0f, 0.0f, 0.0f, 0, 58.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC908 = { NULL, NULL, 3.41f, 8.03f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 76.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC938 = { NULL, NULL, 0.41f, 8.03f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 35.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC968 = { NULL, NULL, 0.41f, 8.03f, -6.5f, 0.0f, 0.0f, 0.0f, 0, 133.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC998 = { NULL, NULL, 3.41f, 8.03f, -6.5f, 0.0f, 0.0f, 0.0f, 0, 156.0f, 0, 0x3EF };
static UnkStruct_11 D_800CC9C8 = { NULL, NULL, -4.09f, 8.03f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x417 };
static UnkStruct_11 D_800CC9F8 = { NULL, NULL, 0.91f, 11.03f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 223.0f, 0, 0x417 };
static UnkStruct_11 D_800CCA28 = { NULL, NULL, 3.41f, 11.03f, -0.5f, 0.0f, 0.0f, 0.0f, 0, 185.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCA58 = { NULL, NULL, 3.41f, 8.03f, 2.5f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCA88 = { NULL, NULL, -0.09f, 8.03f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 127.0f, 0, 0x417 };
static UnkStruct_11 D_800CCAB8 = { NULL, NULL, 0.41f, 12.03f, -0.5f, 0.0f, 0.0f, 0.0f, 0, 105.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCAE8 = { NULL, NULL, -2.59f, 12.03f, -0.5f, 0.0f, 0.0f, 0.0f, 0, 248.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CCB18[18] = {
  &D_800C5F34,
  &D_800CC848,
  &D_800C5E14,
  &D_800CC878,
  &D_800CC8A8,
  &D_800CC8D8,
  &D_800CC908,
  &D_800CC938,
  &D_800CC968,
  &D_800CC998,
  &D_800CC9C8,
  &D_800CC9F8,
  &D_800CCA28,
  &D_800CCA58,
  &D_800CCA88,
  &D_800CCAB8,
  &D_800CCAE8,
  NULL,
};
static UnkStruct_11 D_800CCB60 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F6 };
static UnkStruct_11 D_800CCB90 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E0 };
static UnkStruct_11 D_800CCBC0 = { NULL, NULL, -1.41f, 20.4f, 1.69f, 0.0f, 0.0f, 0.0f, 0, 202.0f, 0, 0x417 };
static UnkStruct_11 D_800CCBF0 = { NULL, NULL, -4.91f, 19.4f, 1.19f, 0.0f, 0.0f, 0.0f, 0, 239.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCC20 = { NULL, NULL, -4.91f, 16.4f, 1.19f, 0.0f, 0.0f, 0.0f, 0, 90.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCC50 = { NULL, NULL, 2.59f, 16.4f, -8.31f, 0.0f, 0.0f, 0.0f, 0, 175.0f, 0, 0x417 };
static UnkStruct_11 D_800CCC80 = { NULL, NULL, -0.91f, 16.4f, -7.81f, 0.0f, 0.0f, 0.0f, 0, 132.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCCB0 = { NULL, NULL, 2.09f, 19.4f, -4.81f, 0.0f, 0.0f, 0.0f, 0, 213.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCCE0 = { NULL, NULL, 2.09f, 20.4f, -1.81f, 0.0f, 0.0f, 0.0f, 0, 229.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCD10 = { NULL, NULL, -0.91f, 19.4f, -4.81f, 0.0f, 0.0f, 0.0f, 0, 162.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCD40 = { NULL, NULL, -0.91f, 19.4f, -1.81f, 0.0f, 0.0f, 0.0f, 0, 193.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCD70 = { NULL, NULL, -1.41f, 16.4f, 1.69f, 0.0f, 0.0f, 0.0f, 0, 73.0f, 0, 0x417 };
static UnkStruct_11 D_800CCDA0 = { NULL, NULL, 2.09f, 16.4f, -4.81f, 0.0f, 0.0f, 0.0f, 0, 65.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCDD0 = { NULL, NULL, -0.91f, 16.4f, -1.81f, 0.0f, 0.0f, 0.0f, 0, 49.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCE00 = { NULL, NULL, -0.91f, 16.4f, -4.81f, 0.0f, 0.0f, 0.0f, 0, 29.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCE30 = { NULL, NULL, 2.59f, 16.4f, -1.31f, 0.0f, 0.0f, 0.0f, 0, 109.0f, 0, 0x417 };
static UnkStruct_11 D_800CCE60 = { NULL, NULL, -4.41f, 16.4f, -2.31f, 0.0f, 0.0f, 0.0f, 0, 18.0f, 0, 0x417 };
static UnkStruct_11 *D_800CCE90[20] = {
  &D_800C5F34,
  &D_800CCB60,
  &D_800C5E14,
  &D_800CCB90,
  &D_800CCBC0,
  &D_800CCBF0,
  &D_800CCC20,
  &D_800CCC50,
  &D_800CCC80,
  &D_800CCCB0,
  &D_800CCCE0,
  &D_800CCD10,
  &D_800CCD40,
  &D_800CCD70,
  &D_800CCDA0,
  &D_800CCDD0,
  &D_800CCE00,
  &D_800CCE30,
  &D_800CCE60,
  NULL,
};
static UnkStruct_11 D_800CCEE0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F7 };
static UnkStruct_11 D_800CCF10 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E1 };
static UnkStruct_11 D_800CCF40 = { NULL, NULL, -7.17f, 24.46f, -7.19f, 0.0f, 0.0f, 0.0f, 0, 53.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCF70 = { NULL, NULL, -4.17f, 24.46f, -7.19f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCFA0 = { NULL, NULL, -7.17f, 24.46f, -4.19f, 0.0f, 0.0f, 0.0f, 0, 69.0f, 0, 0x3EF };
static UnkStruct_11 D_800CCFD0 = { NULL, NULL, -7.17f, 27.46f, -7.19f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD000 = { NULL, NULL, -4.17f, 24.46f, -4.19f, 0.0f, 0.0f, 0.0f, 0, 19.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD030 = { NULL, NULL, -1.17f, 24.46f, -4.19f, 0.0f, 0.0f, 0.0f, 0, 86.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD060 = { NULL, NULL, -1.17f, 24.46f, -7.19f, 0.0f, 0.0f, 0.0f, 0, 37.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD090 = { NULL, NULL, -3.67f, 27.46f, -6.69f, 0.0f, 0.0f, 0.0f, 0, 109.0f, 0, 0x417 };
static UnkStruct_11 D_800CD0C0 = { NULL, NULL, -5.17f, 24.46f, -1.19f, 0.0f, 0.0f, 0.0f, 0, 94.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD0F0 = { NULL, NULL, -2.17f, 24.46f, -1.19f, 0.0f, 0.0f, 0.0f, 0, 132.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD120 = { NULL, NULL, -4.67f, 27.46f, -2.69f, 0.0f, 0.0f, 0.0f, 0, 229.0f, 0, 0x417 };
static UnkStruct_11 D_800CD150 = { NULL, NULL, 2.33f, 24.46f, -6.69f, 0.0f, 0.0f, 0.0f, 0, 98.0f, 0, 0x417 };
static UnkStruct_11 D_800CD180 = { NULL, NULL, 1.83f, 24.46f, -3.19f, 0.0f, 0.0f, 0.0f, 0, 126.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD1B0 = { NULL, NULL, 2.83f, 28.46f, -7.19f, 0.0f, 0.0f, 0.0f, 0, 198.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD1E0 = { NULL, NULL, 4.83f, 24.46f, -3.19f, 0.0f, 0.0f, 0.0f, 0, 155.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD210 = { NULL, NULL, 1.83f, 27.46f, -3.19f, 0.0f, 0.0f, 0.0f, 0, 207.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CD240[21] = {
  &D_800C5F34,
  &D_800CCEE0,
  &D_800C5E14,
  &D_800CCF10,
  &D_800CCF40,
  &D_800CCF70,
  &D_800CCFA0,
  &D_800CCFD0,
  &D_800CD000,
  &D_800CD030,
  &D_800CD060,
  &D_800CD090,
  &D_800CD0C0,
  &D_800CD0F0,
  &D_800CD120,
  &D_800CD150,
  &D_800CD180,
  &D_800CD1B0,
  &D_800CD1E0,
  &D_800CD210,
  NULL,
};
static UnkStruct_11 D_800CD294 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F8 };
static UnkStruct_11 D_800CD2C4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E2 };
static UnkStruct_11 D_800CD2F4 = { NULL, NULL, 1.97f, 36.88f, 0.97f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0, 0x417 };
static UnkStruct_11 D_800CD324 = { NULL, NULL, 5.47f, 36.88f, 4.47f, 0.0f, 0.0f, 0.0f, 0, 227.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD354 = { NULL, NULL, 5.97f, 32.88f, 4.97f, 0.0f, 0.0f, 0.0f, 0, 114.0f, 0, 0x417 };
static UnkStruct_11 D_800CD384 = { NULL, NULL, 5.47f, 32.88f, 1.47f, 0.0f, 0.0f, 0.0f, 0, 33.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD3B4 = { NULL, NULL, 1.97f, 35.88f, -2.53f, 0.0f, 0.0f, 0.0f, 0, 151.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD3E4 = { NULL, NULL, 2.47f, 35.88f, 4.47f, 0.0f, 0.0f, 0.0f, 0, 172.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD414 = { NULL, NULL, 1.97f, 35.88f, -2.53f, 0.0f, 0.0f, 0.0f, 0, 151.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD444 = { NULL, NULL, 1.47f, 32.88f, -6.03f, 0.0f, 0.0f, 0.0f, 0, 195.0f, 0, 0x417 };
static UnkStruct_11 D_800CD474 = { NULL, NULL, 4.97f, 32.88f, -5.53f, 0.0f, 0.0f, 0.0f, 0, 169.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD4A4 = { NULL, NULL, 4.97f, 32.88f, -2.53f, 0.0f, 0.0f, 0.0f, 0, 144.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD4D4 = { NULL, NULL, 1.97f, 32.88f, -2.53f, 0.0f, 0.0f, 0.0f, 0, 54.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD504 = { NULL, NULL, 2.47f, 32.88f, 4.47f, 0.0f, 0.0f, 0.0f, 0, 79.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD534 = { NULL, NULL, 2.47f, 32.88f, 4.47f, 0.0f, 0.0f, 0.0f, 0, 79.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD564 = { NULL, NULL, 1.97f, 32.88f, 0.97f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800CD594 = { NULL, NULL, -2.03f, 32.88f, 0.97f, 0.0f, 0.0f, 0.0f, 0, 96.0f, 0, 0x417 };
static UnkStruct_11 *D_800CD5C4[20] = {
  &D_800C5F34,
  &D_800CD294,
  &D_800C5E14,
  &D_800CD2C4,
  &D_800CD2F4,
  &D_800CD324,
  &D_800CD354,
  &D_800CD384,
  &D_800CD3B4,
  &D_800CD3E4,
  &D_800CD414,
  &D_800CD444,
  &D_800CD474,
  &D_800CD4A4,
  &D_800CD4D4,
  &D_800CD504,
  &D_800CD534,
  &D_800CD564,
  &D_800CD594,
  NULL,
};
static UnkStruct_11 D_800CD614 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4F9 };
static UnkStruct_11 D_800CD644 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E3 };
static UnkStruct_11 D_800CD674 = { NULL, NULL, 1.5f, 43.93f, -4.61f, 0.0f, 0.0f, 0.0f, 0, 268.0f, 0, 0x417 };
static UnkStruct_11 D_800CD6A4 = { NULL, NULL, 2.0f, 40.93f, -7.11f, 0.0f, 0.0f, 0.0f, 0, 180.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD6D4 = { NULL, NULL, -1.0f, 40.93f, -7.11f, 0.0f, 0.0f, 0.0f, 0, 165.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD704 = { NULL, NULL, -1.0f, 40.93f, -4.11f, 0.0f, 0.0f, 0.0f, 0, 96.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD734 = { NULL, NULL, 0.0f, 48.93f, -0.11f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD764 = { NULL, NULL, 3.0f, 47.93f, -0.11f, 0.0f, 0.0f, 0.0f, 0, 270.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD794 = { NULL, NULL, -0.5f, 44.93f, -0.61f, 0.0f, 0.0f, 0.0f, 0, 173.0f, 0, 0x417 };
static UnkStruct_11 D_800CD7C4 = { NULL, NULL, 3.0f, 46.93f, 2.89f, 0.0f, 0.0f, 0.0f, 0, 258.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD7F4 = { NULL, NULL, 2.0f, 40.93f, -4.11f, 0.0f, 0.0f, 0.0f, 0, 108.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD824 = { NULL, NULL, -1.5f, 40.93f, -0.61f, 0.0f, 0.0f, 0.0f, 0, 55.0f, 0, 0x417 };
static UnkStruct_11 D_800CD854 = { NULL, NULL, 0.0f, 43.93f, 2.89f, 0.0f, 0.0f, 0.0f, 0, 187.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD884 = { NULL, NULL, 3.0f, 44.93f, -0.11f, 0.0f, 0.0f, 0.0f, 0, 130.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD8B4 = { NULL, NULL, 3.0f, 43.93f, 2.89f, 0.0f, 0.0f, 0.0f, 0, 149.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD8E4 = { NULL, NULL, 2.5f, 40.93f, -0.61f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x417 };
static UnkStruct_11 D_800CD914 = { NULL, NULL, 0.0f, 40.93f, 2.89f, 0.0f, 0.0f, 0.0f, 0, 76.0f, 0, 0x3EF };
static UnkStruct_11 D_800CD944 = { NULL, NULL, 3.0f, 40.93f, 2.89f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CD974[21] = {
  &D_800C5F34,
  &D_800CD614,
  &D_800C5E14,
  &D_800CD644,
  &D_800CD674,
  &D_800CD6A4,
  &D_800CD6D4,
  &D_800CD704,
  &D_800CD734,
  &D_800CD764,
  &D_800CD794,
  &D_800CD7C4,
  &D_800CD7F4,
  &D_800CD824,
  &D_800CD854,
  &D_800CD884,
  &D_800CD8B4,
  &D_800CD8E4,
  &D_800CD914,
  &D_800CD944,
  NULL,
};
static UnkStruct_11 D_800CD9C8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x502 };
static UnkStruct_11 D_800CD9F8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0x446, 0 };
static UnkStruct_11 D_800CDA28 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x2F5 };
static UnkStruct_11 *D_800CDA58[4] = {
  &D_800CD9C8,
  &D_800CD9F8,
  &D_800CDA28,
  NULL,
};
static UnkStruct_11 D_800CDA68 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x2F4 };
static UnkStruct_11 *D_800CDA98[2] = {
  &D_800CDA68,
  NULL,
};
static UnkStruct_11 D_800CDAA0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x2F6 };
static UnkStruct_11 *D_800CDAD0[2] = {
  &D_800CDAA0,
  NULL,
};
static UnkStruct_11 D_800CDAD8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E8 };
static UnkStruct_11 D_800CDB08 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x50D };
static UnkStruct_11 D_800CDB38 = { NULL, NULL, 25.68f, 6.01f, -19.5f, 0.0f, 0.0f, 0.0f, 0, 173.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDB68 = { NULL, NULL, 20.18f, 6.0f, -26.0f, 0.0f, 0.0f, 0.0f, 0, 126.0f, 0, 0x417 };
static UnkStruct_11 D_800CDB98 = { NULL, NULL, 28.68f, 0.0f, -25.5f, 0.0f, 0.0f, 0.0f, 0, 20.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDBC8 = { NULL, NULL, 28.68f, 0.0f, -28.5f, 0.0f, 0.0f, 0.0f, 0, 56.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDBF8 = { NULL, NULL, 25.68f, 0.0f, -25.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDC28 = { NULL, NULL, 25.68f, 0.0f, -28.5f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDC58 = { NULL, NULL, 28.68f, 3.0f, -25.5f, 0.0f, 0.0f, 0.0f, 0, 88.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDC88 = { NULL, NULL, 28.68f, 3.0f, -28.5f, 0.0f, 0.0f, 0.0f, 0, 117.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDCB8 = { NULL, NULL, 25.68f, 3.0f, -25.5f, 0.0f, 0.0f, 0.0f, 0, 75.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDCE8 = { NULL, NULL, 25.68f, 3.0f, -28.5f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDD18 = { NULL, NULL, 25.68f, 6.01f, -22.5f, 0.0f, 0.0f, 0.0f, 0, 152.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDD48 = { NULL, NULL, 28.68f, 6.01f, -22.5f, 0.0f, 0.0f, 0.0f, 0, 163.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDD78 = { NULL, NULL, 24.18f, 6.0f, -26.0f, 0.0f, 0.0f, 0.0f, 0, 140.0f, 0, 0x417 };
static UnkStruct_11 D_800CDDA8 = { NULL, NULL, 28.18f, 6.0f, -26.0f, 0.0f, 0.0f, 0.0f, 0, 158.0f, 0, 0x417 };
static UnkStruct_11 D_800CDDD8 = { NULL, NULL, 10.68f, 6.0f, -25.49f, 0.0f, 0.0f, 0.0f, 0, 130.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDE08 = { NULL, NULL, 10.68f, 6.0f, -28.49f, 0.0f, 0.0f, 0.0f, 0, 158.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDE38 = { NULL, NULL, 7.68f, 6.0f, -25.49f, 0.0f, 0.0f, 0.0f, 0, 199.0f, 0, 0x3EF };
static UnkStruct_11 D_800CDE68 = { NULL, NULL, 10.68f, 9.0f, -25.49f, 0.0f, 0.0f, 0.0f, 0, 230.0f, 0, 0x3EF };
static UnkStruct_11 *D_800CDE98[23] = {
  &D_800C5F64,
  &D_800CDAD8,
  &D_800C5E14,
  &D_800CDB08,
  &D_800CDB38,
  &D_800CDB68,
  &D_800CDB98,
  &D_800CDBC8,
  &D_800CDBF8,
  &D_800CDC28,
  &D_800CDC58,
  &D_800CDC88,
  &D_800CDCB8,
  &D_800CDCE8,
  &D_800CDD18,
  &D_800CDD48,
  &D_800CDD78,
  &D_800CDDA8,
  &D_800CDDD8,
  &D_800CDE08,
  &D_800CDE38,
  &D_800CDE68,
  NULL,
};
static UnkStruct_11 D_800CDEF4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4E9 };
static UnkStruct_11 D_800CDF24 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x50E };
static UnkStruct_11 D_800CDF54 = { NULL, NULL, 4.18f, 0.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CDF84 = { NULL, NULL, 4.18f, 0.0f, -12.0f, 0.0f, 0.0f, 0.0f, 0, 38.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CDFB4 = { NULL, NULL, 4.18f, 0.0f, -16.0f, 0.0f, 0.0f, 0.0f, 0, 95.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CDFE4 = { NULL, NULL, 0.18f, 0.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 57.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE014 = { NULL, NULL, 0.18f, 0.0f, -12.0f, 0.0f, 0.0f, 0.0f, 0, 81.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE044 = { NULL, NULL, -3.32f, 0.0f, -7.5f, 0.0f, 0.0f, 0.0f, 0, 128.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE074 = { NULL, NULL, 0.68f, 0.0f, -15.5f, 0.0f, 0.0f, 0.0f, 0, 110.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE0A4 = { NULL, NULL, 4.18f, 4.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 140.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE0D4 = { NULL, NULL, 4.18f, 4.0f, -12.0f, 0.0f, 0.0f, 0.0f, 0, 150.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE104 = { NULL, NULL, 0.68f, 4.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 164.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE134 = { NULL, NULL, 4.18f, 4.0f, -15.5f, 0.0f, 0.0f, 0.0f, 0, 186.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE164 = { NULL, NULL, -3.32f, 0.0f, -10.5f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE194 = { NULL, NULL, 4.18f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0, 118.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE1C4 = { NULL, NULL, 0.68f, 7.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0, 221.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE1F4 = { NULL, NULL, 0.68f, 4.0f, -11.0f, 0.0f, 0.0f, 0.0f, 0, 176.0f, 0x3EE, 0x3EF };
static UnkStruct_11 *D_800CE224[20] = {
  &D_800C5F64,
  &D_800CDEF4,
  &D_800C5E14,
  &D_800CDF24,
  &D_800CDF54,
  &D_800CDF84,
  &D_800CDFB4,
  &D_800CDFE4,
  &D_800CE014,
  &D_800CE044,
  &D_800CE074,
  &D_800CE0A4,
  &D_800CE0D4,
  &D_800CE104,
  &D_800CE134,
  &D_800CE164,
  &D_800CE194,
  &D_800CE1C4,
  &D_800CE1F4,
  NULL,
};
static UnkStruct_11 D_800CE274 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4EA };
static UnkStruct_11 D_800CE2A4 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x50F };
static UnkStruct_11 D_800CE2D4 = { NULL, NULL, 0.18f, 12.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 74.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE304 = { NULL, NULL, 4.18f, 12.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE334 = { NULL, NULL, 4.18f, 12.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 52.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE364 = { NULL, NULL, 4.18f, 12.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0, 101.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE394 = { NULL, NULL, 0.18f, 12.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 37.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE3C4 = { NULL, NULL, 8.18f, 12.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 196.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE3F4 = { NULL, NULL, 7.68f, 12.0f, -3.0f, 0.0f, 0.0f, 0.0f, 0, 130.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE424 = { NULL, NULL, 7.68f, 12.0f, -6.0f, 0.0f, 0.0f, 0.0f, 0, 154.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE454 = { NULL, NULL, 2.68f, 16.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 146.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE484 = { NULL, NULL, 5.68f, 16.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 175.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE4B4 = { NULL, NULL, 4.68f, 16.0f, -3.0f, 0.0f, 0.0f, 0.0f, 0, 164.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE4E4 = { NULL, NULL, 7.68f, 15.0f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 220.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE514 = { NULL, NULL, 1.18f, 16.0f, -3.5f, 0.0f, 0.0f, 0.0f, 0, 113.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE544 = { NULL, NULL, 7.68f, 12.0f, 3.5f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE574 = { NULL, NULL, -3.32f, 12.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 92.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE5A4 = { NULL, NULL, -6.32f, 12.0f, -4.0f, 0.0f, 0.0f, 0.0f, 0, 139.0f, 0x3EE, 0x3EF };
static UnkStruct_11 *D_800CE5D4[21] = {
  &D_800C5F64,
  &D_800CE274,
  &D_800C5E14,
  &D_800CE2A4,
  &D_800CE2D4,
  &D_800CE304,
  &D_800CE334,
  &D_800CE364,
  &D_800CE394,
  &D_800CE3C4,
  &D_800CE3F4,
  &D_800CE424,
  &D_800CE454,
  &D_800CE484,
  &D_800CE4B4,
  &D_800CE4E4,
  &D_800CE514,
  &D_800CE544,
  &D_800CE574,
  &D_800CE5A4,
  NULL,
};
static UnkStruct_11 D_800CE628 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4EB };
static UnkStruct_11 D_800CE658 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x510 };
static UnkStruct_11 D_800CE688 = { NULL, NULL, 6.33f, 24.0f, 5.8f, 0.0f, 0.0f, 0.0f, 0, 122.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE6B8 = { NULL, NULL, 2.33f, 24.0f, 5.8f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE6E8 = { NULL, NULL, -1.67f, 24.0f, 5.8f, 0.0f, 0.0f, 0.0f, 0, 41.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE718 = { NULL, NULL, -5.17f, 24.0f, 5.8f, 0.0f, 0.0f, 0.0f, 0, 103.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE748 = { NULL, NULL, -1.67f, 24.0f, 1.8f, 0.0f, 0.0f, 0.0f, 0, 77.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE778 = { NULL, NULL, -5.17f, 24.0f, 2.8f, 0.0f, 0.0f, 0.0f, 0, 148.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE7A8 = { NULL, NULL, 1.83f, 24.0f, 2.3f, 0.0f, 0.0f, 0.0f, 0, 52.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE7D8 = { NULL, NULL, 4.83f, 24.0f, 2.3f, 0.0f, 0.0f, 0.0f, 0, 116.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE808 = { NULL, NULL, 4.83f, 24.0f, -0.7f, 0.0f, 0.0f, 0.0f, 0, 145.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE838 = { NULL, NULL, 1.83f, 24.0f, -0.7f, 0.0f, 0.0f, 0.0f, 0, 90.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE868 = { NULL, NULL, 2.33f, 27.0f, 1.8f, 0.0f, 0.0f, 0.0f, 0, 227.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CE898 = { NULL, NULL, 0.83f, 24.0f, 9.3f, 0.0f, 0.0f, 0.0f, 0, 179.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE8C8 = { NULL, NULL, 3.83f, 24.0f, 9.3f, 0.0f, 0.0f, 0.0f, 0, 135.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE8F8 = { NULL, NULL, 2.33f, 27.0f, 9.3f, 0.0f, 0.0f, 0.0f, 0, 218.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CE928 = { NULL, NULL, -5.17f, 27.0f, 4.3f, 0.0f, 0.0f, 0.0f, 0, 235.0f, 0x3EE, 0x3EF };
static UnkStruct_11 *D_800CE958[20] = {
  &D_800C5F64,
  &D_800CE628,
  &D_800C5E14,
  &D_800CE658,
  &D_800CE688,
  &D_800CE6B8,
  &D_800CE6E8,
  &D_800CE718,
  &D_800CE748,
  &D_800CE778,
  &D_800CE7A8,
  &D_800CE7D8,
  &D_800CE808,
  &D_800CE838,
  &D_800CE868,
  &D_800CE898,
  &D_800CE8C8,
  &D_800CE8F8,
  &D_800CE928,
  NULL,
};
static UnkStruct_11 D_800CE9A8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4EC };
static UnkStruct_11 D_800CE9D8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x511 };
static UnkStruct_11 D_800CEA08 = { NULL, NULL, -23.37f, 40.0f, -0.05f, 0.0f, 0.0f, 0.0f, 0, 210.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEA38 = { NULL, NULL, -20.37f, 40.0f, 3.45f, 0.0f, 0.0f, 0.0f, 0, 156.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEA68 = { NULL, NULL, -19.87f, 39.0f, 0.45f, 0.0f, 0.0f, 0.0f, 0, 197.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEA98 = { NULL, NULL, -23.37f, 36.0f, -0.05f, 0.0f, 0.0f, 0.0f, 0, 91.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEAC8 = { NULL, NULL, -10.91f, 40.11f, 13.0f, 0.0f, 0.0f, 0.0f, 0, 177.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEAF8 = { NULL, NULL, -13.91f, 40.11f, 13.0f, 0.0f, 0.0f, 0.0f, 0, 207.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEB28 = { NULL, NULL, -23.37f, 36.0f, 3.45f, 0.0f, 0.0f, 0.0f, 0, 115.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEB58 = { NULL, NULL, -19.87f, 36.0f, 0.45f, 0.0f, 0.0f, 0.0f, 0, 76.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEB88 = { NULL, NULL, -19.87f, 36.0f, 3.95f, 0.0f, 0.0f, 0.0f, 0, 39.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEBB8 = { NULL, NULL, -15.91f, 36.11f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 125.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEBE8 = { NULL, NULL, -13.91f, 36.11f, 13.5f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEC18 = { NULL, NULL, -10.91f, 39.11f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 215.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEC48 = { NULL, NULL, -9.91f, 36.11f, 13.5f, 0.0f, 0.0f, 0.0f, 0, 69.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEC78 = { NULL, NULL, -12.91f, 36.11f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 62.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CECA8 = { NULL, NULL, -9.91f, 36.11f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 98.0f, 0x3EE, 0x3EF };
static UnkStruct_11 *D_800CECD8[20] = {
  &D_800C5F64,
  &D_800CE9A8,
  &D_800C5E14,
  &D_800CE9D8,
  &D_800CEA08,
  &D_800CEA38,
  &D_800CEA68,
  &D_800CEA98,
  &D_800CEAC8,
  &D_800CEAF8,
  &D_800CEB28,
  &D_800CEB58,
  &D_800CEB88,
  &D_800CEBB8,
  &D_800CEBE8,
  &D_800CEC18,
  &D_800CEC48,
  &D_800CEC78,
  &D_800CECA8,
  NULL,
};
static UnkStruct_11 D_800CED28 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4ED };
static UnkStruct_11 D_800CED58 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x512 };
static UnkStruct_11 D_800CED88 = { NULL, NULL, -0.59f, 55.35f, 2.1f, 0.0f, 0.0f, 0.0f, 0, 197.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEDB8 = { NULL, NULL, -3.59f, 56.35f, 1.1f, 0.0f, 0.0f, 0.0f, 0, 250.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEDE8 = { NULL, NULL, 4.41f, 48.35f, -2.9f, 0.0f, 0.0f, 0.0f, 0, 135.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEE18 = { NULL, NULL, 1.41f, 48.35f, -2.9f, 0.0f, 0.0f, 0.0f, 0, 100.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEE48 = { NULL, NULL, -1.59f, 48.35f, -2.9f, 0.0f, 0.0f, 0.0f, 0, 121.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEE78 = { NULL, NULL, -0.59f, 52.35f, 1.1f, 0.0f, 0.0f, 0.0f, 0, 171.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEEA8 = { NULL, NULL, -4.09f, 52.35f, 0.6f, 0.0f, 0.0f, 0.0f, 0, 203.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEED8 = { NULL, NULL, -3.59f, 51.35f, 4.1f, 0.0f, 0.0f, 0.0f, 0, 190.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEF08 = { NULL, NULL, -3.59f, 48.35f, 4.1f, 0.0f, 0.0f, 0.0f, 0, 89.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEF38 = { NULL, NULL, 3.41f, 48.35f, 3.1f, 0.0f, 0.0f, 0.0f, 0, 85.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEF68 = { NULL, NULL, -0.59f, 52.35f, 4.1f, 0.0f, 0.0f, 0.0f, 0, 152.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEF98 = { NULL, NULL, -0.09f, 48.35f, 4.6f, 0.0f, 0.0f, 0.0f, 0, 42.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CEFC8 = { NULL, NULL, 3.41f, 48.35f, 0.1f, 0.0f, 0.0f, 0.0f, 0, 76.0f, 0x3EE, 0x3EF };
static UnkStruct_11 D_800CEFF8 = { NULL, NULL, -0.09f, 48.35f, 0.6f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF028 = { NULL, NULL, -4.09f, 48.35f, 0.6f, 0.0f, 0.0f, 0.0f, 0, 59.0f, 0x416, 0x417 };
static UnkStruct_11 *D_800CF058[20] = {
  &D_800C5F64,
  &D_800CED28,
  &D_800C5E14,
  &D_800CED58,
  &D_800CED88,
  &D_800CEDB8,
  &D_800CEDE8,
  &D_800CEE18,
  &D_800CEE48,
  &D_800CEE78,
  &D_800CEEA8,
  &D_800CEED8,
  &D_800CEF08,
  &D_800CEF38,
  &D_800CEF68,
  &D_800CEF98,
  &D_800CEFC8,
  &D_800CEFF8,
  &D_800CF028,
  NULL,
};
static UnkStruct_11 D_800CF0A8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x4EE };
static UnkStruct_11 D_800CF0D8 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x513 };
static UnkStruct_11 D_800CF108 = { NULL, NULL, 4.6f, 72.38f, 5.17f, 0.0f, 0.0f, 0.0f, 0, 22.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF138 = { NULL, NULL, 0.6f, 72.38f, 5.17f, 0.0f, 0.0f, 0.0f, 0, 8.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF168 = { NULL, NULL, -3.4f, 72.38f, 5.17f, 0.0f, 0.0f, 0.0f, 0, 39.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF198 = { NULL, NULL, 4.6f, 72.38f, 1.17f, 0.0f, 0.0f, 0.0f, 0, 26.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF1C8 = { NULL, NULL, 0.6f, 72.38f, 1.17f, 0.0f, 0.0f, 0.0f, 0, 1.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF1F8 = { NULL, NULL, -3.4f, 72.38f, 1.17f, 0.0f, 0.0f, 0.0f, 0, 29.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF228 = { NULL, NULL, 4.6f, 72.38f, -2.83f, 0.0f, 0.0f, 0.0f, 0, 17.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF258 = { NULL, NULL, 0.6f, 72.38f, -2.83f, 0.0f, 0.0f, 0.0f, 0, 34.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF288 = { NULL, NULL, -3.4f, 72.38f, -2.83f, 0.0f, 0.0f, 0.0f, 0, 41.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF2B8 = { NULL, NULL, 2.6f, 76.38f, 3.17f, 0.0f, 0.0f, 0.0f, 0, 117.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF2E8 = { NULL, NULL, -1.4f, 76.38f, 3.17f, 0.0f, 0.0f, 0.0f, 0, 138.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF318 = { NULL, NULL, 2.6f, 76.38f, -0.83f, 0.0f, 0.0f, 0.0f, 0, 131.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF348 = { NULL, NULL, -1.4f, 76.38f, -0.83f, 0.0f, 0.0f, 0.0f, 0, 123.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF378 = { NULL, NULL, 0.6f, 80.38f, 1.17f, 0.0f, 0.0f, 0.0f, 0, 207.0f, 0x416, 0x417 };
static UnkStruct_11 D_800CF3A8 = { NULL, NULL, 0.6f, 84.38f, 1.17f, 0.0f, 0.0f, 0.0f, 0, 310.0f, 0x3EE, 0x3EF };
static UnkStruct_11 *D_800CF3D8[20] = {
  &D_800C5F64,
  &D_800CF0A8,
  &D_800C5E14,
  &D_800CF0D8,
  &D_800CF108,
  &D_800CF138,
  &D_800CF168,
  &D_800CF198,
  &D_800CF1C8,
  &D_800CF1F8,
  &D_800CF228,
  &D_800CF258,
  &D_800CF288,
  &D_800CF2B8,
  &D_800CF2E8,
  &D_800CF318,
  &D_800CF348,
  &D_800CF378,
  &D_800CF3A8,
  NULL,
};
static UnkStruct_11 D_800CF428 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x37B };
static UnkStruct_11 *D_800CF458[4] = {
  &D_800C5F64,
  &D_800C5E14,
  &D_800CF428,
  NULL,
};
static UnkStruct_11 D_800CF468 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x379 };
static UnkStruct_11 *D_800CF498[2] = {
  &D_800CF468,
  NULL,
};
static UnkStruct_11 D_800CF4A0 = { NULL, NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 40.0f, 0, 0x37A };
static UnkStruct_11 *D_800CF4D0[2] = {
  &D_800CF4A0,
  NULL,
};
static UnkStruct_11 **D_800CF4D8[14] = {
  D_800C60E4,
  D_800C622C,
  D_800C63A0,
  D_800C64E8,
  D_800C662C,
  D_800C6770,
  D_800C6884,
  D_800C6D14,
  D_800C6FE0,
  D_800C7380,
  D_800C7644,
  D_800C78F4,
  D_800C7BA4,
  D_800C7E54,
};
static UnkStruct_11 **D_800CF510[35] = {
  D_800C8244,
  D_800C8560,
  D_800C88D8,
  D_800C8AD8,
  D_800C8CB8,
  D_800C8DD8,
  D_800C8EE8,
  D_800C92B8,
  D_800C9634,
  D_800C9984,
  D_800C9D30,
  D_800CA084,
  D_800CA400,
  D_800CA7B0,
  D_800CABB4,
  D_800CAF30,
  D_800CB2B0,
  D_800CB630,
  D_800CB9B0,
  D_800CBCD0,
  D_800CC078,
  D_800CC4AC,
  D_800CC7FC,
  D_800CCB18,
  D_800CCE90,
  D_800CD240,
  D_800CD5C4,
  D_800CD974,
  D_800CDE98,
  D_800CE224,
  D_800CE5D4,
  D_800CE958,
  D_800CECD8,
  D_800CF058,
  D_800CF3D8,
};
static UnkStruct_11 **D_800CF59C[7] = {
  D_800C68D4,
  D_800C7EC4,
  D_800C8F38,
  D_800CA834,
  D_800CC0FC,
  D_800CDA58,
  D_800CF458,
};
static UnkStruct_11 **D_800CF5B8[14] = {
  D_800C6914,
  D_800C7F04,
  D_800C8F78,
  D_800CA874,
  D_800CC13C,
  D_800CDA98,
  D_800CF498,
  D_800C694C,
  D_800C7F3C,
  D_800C8FB0,
  D_800CA8AC,
  D_800CC174,
  D_800CDAD0,
  D_800CF4D0,
};
static u8 D_800CF5F0[49] = {
  8, 3, 3, 6, 4, 3, 5,
  8, 7, 14, 9, 4, 14, 5,
  13, 4, 18, 4, 6, 4, 5,
  10, 15, 17, 13, 16, 11, 19,
  13, 5, 10, 13, 16, 4, 6,
  10, 11, 16, 5, 7, 4, 8,
  21, 17, 15, 18, 15, 5, 18,
};
static UnkStruct_90 D_800CF624 = { 0, 0xFFFF };
static UnkStruct_90 D_800CF628 = { 0xFFFF, 0xFFFF };
static UnkStruct_90 D_800CF62C = { 0x1F3, 0xFFFF };
static UnkStruct_90 D_800CF630 = { 0, 0x258 };
static UnkStruct_90 *D_800CF634[3] = {
  &D_800CF624,
  &D_800CF628,
  &D_800CF628,
  // (bug?) -- missing NULL
};
static UnkStruct_90 *D_800CF640[5] = {
  &D_800CF62C,
  &D_800CF630,
  &D_800CF628,
  &D_800CF628,
  NULL,
};
static UnkStruct_90 *D_800CF654[4] = {
  &D_800CF624,
  &D_800CF628,
  &D_800CF628,
  NULL,
};
static UnkStruct_90 D_800CF664 = { 0, 0xABD };
static UnkStruct_90 *D_800CF668[2] = {
  &D_800CF664,
  NULL,
};
static UnkStruct_90 D_800CF670 = { 0, 0xF9F };
static UnkStruct_90 *D_800CF674[2] = {
  &D_800CF670,
  NULL,
};
static UnkStruct_90 D_800CF67C = { 0, 0xD6F };
static UnkStruct_90 *D_800CF680[2] = {
  &D_800CF67C,
  NULL,
};
static UnkStruct_90 D_800CF688 = { 0, 0x112B };
static UnkStruct_90 *D_800CF68C[2] = {
  &D_800CF688,
  NULL,
};
static UnkStruct_90 D_800CF694 = { 0, 0xBB7 };
static UnkStruct_90 *D_800CF698[2] = {
  &D_800CF694,
  NULL,
};
static UnkStruct_90 D_800CF6A0 = { 0, 0x95F };
static UnkStruct_90 *D_800CF6A4[2] = {
  &D_800CF6A0,
  NULL,
};
static UnkStruct_90 D_800CF6AC = { 0, 0xF9F };
static UnkStruct_90 *D_800CF6B0[2] = {
  &D_800CF6AC,
  NULL,
};
static UnkStruct_90 D_800CF6B8 = { 0, 0x7CF };
static UnkStruct_90 *D_800CF6BC[2] = {
  &D_800CF6B8,
  NULL,
};
static UnkStruct_90 D_800CF6C4 = { 0, 0x76D };
static UnkStruct_90 *D_800CF6C8[2] = {
  &D_800CF6C4,
  NULL,
};
static UnkStruct_90 D_800CF6D0 = { 0, 0x971 };
static UnkStruct_90 *D_800CF6D4[2] = {
  &D_800CF6D0,
  NULL,
};
static UnkStruct_90 D_800CF6DC = { 0, 0x77F };
static UnkStruct_90 *D_800CF6E0[2] = {
  &D_800CF6DC,
  NULL,
};
static UnkStruct_90 D_800CF6E8 = { 0, 0x757 };
static UnkStruct_90 *D_800CF6EC[2] = {
  &D_800CF6E8,
  NULL,
};
static UnkStruct_90 D_800CF6F4 = { 0, 0x90F };
static UnkStruct_90 *D_800CF6F8[2] = {
  &D_800CF6F4,
  NULL,
};
static UnkStruct_90 D_800CF700 = { 0, 0x937 };
static UnkStruct_90 *D_800CF704[2] = {
  &D_800CF700,
  NULL,
};
static UnkStruct_90 **D_800CF70C[14] = {
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
};
static UnkStruct_90 **D_800CF744[35] = {
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF634,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
  D_800CF640,
};
static UnkStruct_90 **D_800CF7D0[7] = {
  D_800CF654,
  D_800CF654,
  D_800CF654,
  D_800CF654,
  D_800CF654,
  D_800CF654,
  D_800CF654,
};
static UnkStruct_90 **D_800CF7EC[14] = {
  D_800CF668,
  D_800CF674,
  D_800CF680,
  D_800CF68C,
  D_800CF698,
  D_800CF6A4,
  D_800CF6B0,
  D_800CF6BC,
  D_800CF6C8,
  D_800CF6D4,
  D_800CF6E0,
  D_800CF6EC,
  D_800CF6F8,
  D_800CF704,
};

static void wonders1_80043810_eightliner(WonderAnim *);
static void wonders1_800438a8_mediumliner_loop(WonderAnim *);
static void wonders1_80043c7c_thirtyliner_loop(WonderAnim *);
static void wonders1_80043ed8_thirtyliner_loop(WonderAnim *);
static void wonders1_8004411c_tenliner_loop(WonderAnim *);
static void wonders1_80044218_tenliner_loop(WonderAnim *);
static void wonders1_checks_num_wonders_completed_q(WonderAnim *);
static void wonders1_80044424_threeliner(WonderAnim *);
static void wonders1_80044464_threeliner(WonderAnim *);
static void wonders1_800445dc_calls_4_funcs(UnkStruct_32 *);
static void wonders1_80044628_eightliner(UnkStruct_11 *);
static void wonders1_800446ac_eightliner(u8);
static void wonders1_hall_or_exit(void);
static void wonders1_display_complete_message(void);
static void wonders1_finale_or_hall(void);
static void wonders1_800455bc_inc_won_compl_q(void);
static void wonders1_calls_music_400x300_magic(void);

static void wonders1_80043810_eightliner(WonderAnim *wndrAnm) {
  register u32 temp_s0 = g_PV_arr[0].unk24;

  if (temp_s0 & 0x8000) {  // A_BUTTON / CONT_A
    if (wndrAnm->state == 10) {
      func_8007E9F8(90);
      wndrAnm->state = 11;
    } else {
      wndrAnm->state = 14;
    }
  } else if (temp_s0 & 0x4000) {  // B_BUTTON / CONT_B
    wndrAnm->state = 15;
  }
}

static void wonders1_800438a8_mediumliner_loop(WonderAnim *wndrAnm) {
  wndrAnm->unk8 = D_800CF4D8[wndrAnm->unk1];
  wndrAnm->unk4 = D_800CF70C[wndrAnm->unk1];
  D_800E1F70 = 0;
  while (wndrAnm->unk8[D_800E1F70] != NULL) {
    func_80076EC0(wndrAnm->unk8[D_800E1F70], TRUE);
    if (wonders2_divide_by_seven(wndrAnm->unk1) > 2) {
      if (D_800E1F70 != 1) {
        func_800A4620(wndrAnm->unk8[D_800E1F70]->unk0);
      }
      if (D_800E1F70 == 2) {
        func_800A4654(wndrAnm->unk8[D_800E1F70]->unk0);
      } else {
        func_800A4644(wndrAnm->unk8[D_800E1F70]->unk0);
      }
      if (D_800E1F70 == 3) {
        wndrAnm->unk8[D_800E1F70]->unk20 |= 4;
      }
    } else {
      if (D_800E1F70 != 0) {
        func_800A4620(wndrAnm->unk8[D_800E1F70]->unk0);
      }
      if (D_800E1F70 == 2) {
        wndrAnm->unk8[D_800E1F70]->unk20 |= 4;
      }
      if (D_800E1F70 == 1) {
        func_800A4654(wndrAnm->unk8[D_800E1F70]->unk0);
      } else {
        func_800A4644(wndrAnm->unk8[D_800E1F70]->unk0);
      }
    }
    if (((wonders2_divide_by_seven(wndrAnm->unk1) > 2) && (D_800E1F70 > 3)) || ((wonders2_divide_by_seven(wndrAnm->unk1) < 3) && (D_800E1F70 > 2))) {
      wndrAnm->unk8[D_800E1F70]->unk14 += func_800A35EC(0, 3) * 90;
    }
    func_800773B8(wndrAnm->unk8[D_800E1F70]);
    D_800E1F70++;
  }
}

static void wonders1_80043c7c_thirtyliner_loop(WonderAnim *wndrAnm) {
  register u8 i;

  main_8004A34C_threeliner();
  wndrAnm->unk8 = D_800CF59C[wonders2_divide_by_seven(wndrAnm->unk1)];
  wndrAnm->unk4 = D_800CF7D0[wonders2_divide_by_seven(wndrAnm->unk1)];
  for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
    func_80076EC0(wndrAnm->unk8[i], TRUE);
    if (i != 0) {
      func_800A4620(wndrAnm->unk8[i]->unk0);
    }
    if (i == 1) {
      func_800A4654(wndrAnm->unk8[i]->unk0);
    } else {
      func_800A4644(wndrAnm->unk8[i]->unk0);
    }
    if (i == 2) {
      wndrAnm->unk8[i]->unk20 |= 0x4;
      wndrAnm->unk8[i]->unk0->unk8->unk10.unk20 = NULL;  // FogParams
    }
    func_800773B8(wndrAnm->unk8[i]);
  }
  wonders4_800476f0_thirtyliner(wonders2_divide_by_seven(wndrAnm->unk1), 1);
}

static void wonders1_80043ed8_thirtyliner_loop(WonderAnim *wndrAnm) {
  register u8 i;
  register s8 temp_v0;

  temp_v0 = wonders2_divide_by_seven(wndrAnm->unk1);
  wndrAnm->unk8 = D_800CF5B8[temp_v0];
  wndrAnm->unk4 = D_800CF7EC[temp_v0];
  for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
    func_80076EC0(wndrAnm->unk8[i], TRUE);
    func_800A4654(wndrAnm->unk8[i]->unk0);
    if (temp_v0 == 0) {
      wndrAnm->unk8[i]->unk0->unk1D0->unk18 = 1;
      D_800E1F68 = func_800A6A74(1396);
    } else if (temp_v0 == 6) {
      wndrAnm->unk8[i]->unk0->unk1D0->unk18 = 1;
      D_800E1F68 = func_800A6A74(1400);
    } else {
      D_800E1F68 = NULL;
    }
    if (D_800E1F68 != NULL) {
      func_800A678C(wndrAnm->unk8[i]->unk0, D_800E1F68);
      wndrAnm->unk8[i]->unk0->unk1D0->unk18 = 0;
    }
  }
  wonders4_800476f0_thirtyliner(wonders2_divide_by_seven(wndrAnm->unk1), 2);
}

static void wonders1_8004411c_tenliner_loop(WonderAnim *wndrAnm) {
  register u8 i;

  wndrAnm->unk8 = D_800CF510[wndrAnm->unk1];
  wndrAnm->unk4 = D_800CF744[wndrAnm->unk1];
  for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
    func_80076EC0(wndrAnm->unk8[i], TRUE);
    func_800A4654(wndrAnm->unk8[i]->unk0);
  }
}

static void wonders1_80044218_tenliner_loop(WonderAnim *wndrAnm) {
  register u8 i;

  if (wndrAnm == NULL) {
    return;
  }

  if (wndrAnm->unk8 != NULL) {
    if (D_800E1F68 != NULL) {
      func_800A6AA8(D_800E1F68);
      D_800E1F68 = NULL;
    }
    for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
      func_80077028(wndrAnm->unk8[i]);
    }
    wndrAnm->unk8 = NULL;
    main_8004A34C_threeliner();
  }
}

static void wonders1_checks_num_wonders_completed_q(WonderAnim *wndrAnm) {
  register u8 var_s0 = FALSE;

  if (D_800CF834 != D_800CF830) {
    wndrAnm->unk1 = D_800CF830;
    wonders1_800438a8_mediumliner_loop(wndrAnm);
    D_800CF834 = D_800CF830;
  } else if (D_800CF83C != D_800CF838) {
    wndrAnm->unk1 = wonders2_8004624c_mult_7_add_6_etc(D_800CF838 - 1);
    wonders1_80043ed8_thirtyliner_loop(wndrAnm);
    D_800CF83C = D_800CF838;
    func_8007ECC8(90);
    var_s0 = TRUE;
  } else if (wonders2_8004619c_sixliner_crazy_if(wndrAnm->unk1)) {
    wonders1_80043ed8_thirtyliner_loop(wndrAnm);
  } else {
    wonders1_800438a8_mediumliner_loop(wndrAnm);
  }
  wndrAnm->unk2 = 0;
  if (var_s0) {
    wndrAnm->state = 8;
  } else {
    wndrAnm->state = 0;
  }
}

static void wonders1_80044424_threeliner(WonderAnim *wndrAnm) {
  wonders1_80043c7c_thirtyliner_loop(wndrAnm);
  wndrAnm->unk2 = 0;
  wndrAnm->state = 4;
}

static void wonders1_80044464_threeliner(WonderAnim *wndrAnm) {
  wonders1_8004411c_tenliner_loop(wndrAnm);
  wndrAnm->unk2 = 0;
  wndrAnm->state = 0;
}

void wonders1_case6_calls_music_magic(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;

  if (wndrAnm == NULL) {
    return;
  }

  switch (wndrAnm->state) {
  case 0:
  case 10:
    wonders1_80043810_eightliner(wndrAnm);
    break;
  case 1:
    if (wndrAnm->unk1 < 49) {
      wonders1_checks_num_wonders_completed_q(wndrAnm);
    } else {
      wonders1_80044464_threeliner(wndrAnm);
    }
    break;
  case 9:
    wonders1_80044218_tenliner_loop(wndrAnm);
    wonders1_checks_num_wonders_completed_q(wndrAnm);
    break;
  case 5:
    wonders1_80044218_tenliner_loop(wndrAnm);
    wonders1_80044424_threeliner(wndrAnm);
    break;
  case 13:
    if (!D_800CF840) {
      wndrAnm->unk1++;
      D_800CF840 = TRUE;
      wonders1_80044218_tenliner_loop(wndrAnm);
      wonders1_80044464_threeliner(wndrAnm);
      wndrAnm->state = 12;
    } else {
      wonders1_80044218_tenliner_loop(wndrAnm);
      wonders1_80044464_threeliner(wndrAnm);
    }
    break;
  case 14:
  case 15:
    wonders1_calls_music_400x300_magic();
    break;
  }
}

static void wonders1_800445dc_calls_4_funcs(UnkStruct_32 *arg0) {
  func_800A4590(arg0);
  func_800A45D8(arg0);
  func_800A4620(arg0);
  func_800A4644(arg0);
}

static void wonders1_80044628_eightliner(UnkStruct_11 *arg0) {
  arg0->unk4 = NULL;
  arg0->unk0 = NULL;
  if (arg0->unk2C == 1007) {
    arg0->unk0 = func_800A6990(1057);
  } else {
    arg0->unk0 = func_800A6990(1066);
  }
  wonders1_800445dc_calls_4_funcs(arg0->unk0);
}

static void wonders1_800446ac_eightliner(u8 arg0) {
  register u16 temp_t6;

  temp_t6 = arg0 * 10;
  if (D_800E1F6F != 0) {
    if ((D_800E1F6E + temp_t6) < 0x100) {
      D_800E1F6E += temp_t6;
    } else {
      D_800E1F6F = 0;
    }
  } else if (D_800E1F6E >= temp_t6) {
    D_800E1F6E -= temp_t6;
  } else {
    D_800E1F6F = 0xFF;
  }
}

static void wonders1_hall_or_exit(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;
  register u16 i;
  register u16 var_s2;
  register u16 var_s3;
  register u8 temp_s4;
  register u32 temp_v0;
  register u16 temp_s6;
  register u16 temp_s7;
  char sp58[20];

  temp_s4 = frametime_delta();
  if ((wndrAnm->unk2 + temp_s4) < 0xFFFF) {
    wndrAnm->unk2 += temp_s4;
  } else {
    wndrAnm->unk2 = 0xFFFF;
  }

  for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
    if (((wndrAnm->state == 0) || (wndrAnm->state == 2)) && (wndrAnm->unk8[i]->unk2C != 0)) {
      if (((wonders2_divide_by_seven(wndrAnm->unk1) > 2) && (i > 3)) || ((wonders2_divide_by_seven(wndrAnm->unk1) < 3) && (i > 2))) {
        var_s2 = wndrAnm->unk8[i]->unk24;
        var_s3 = var_s2 + 190;
      } else {
        var_s2 = wndrAnm->unk4[i]->unk0;
        var_s3 = wndrAnm->unk4[i]->unk2;
      }

      if (!(wndrAnm->unk8[i]->unk20 & 0x1) && (var_s2 != 0xFFFF) && (wndrAnm->unk2 < var_s3) && (wndrAnm->unk2 >= var_s2)) {
        func_800773A4(wndrAnm->unk8[i]);
        wndrAnm->unk8[i]->unk24 = wndrAnm->unk2 - temp_s4;
        if ((wonders2_divide_by_seven(wndrAnm->unk1) > 2) && (i == 0)) {
          func_800A4620(wndrAnm->unk8[1]->unk0);
          func_800A4630(wndrAnm->unk8[0]->unk0);
          func_800773B8(wndrAnm->unk8[1]);
        }
      }

      if ((wndrAnm->unk8[i]->unk20 & 0x1) && (var_s3 != 0xFFFF) && (wndrAnm->unk2 >= var_s3)) {
        func_800773B8(wndrAnm->unk8[i]);
        if (((wonders2_divide_by_seven(wndrAnm->unk1) > 2) && (i > 3)) || ((wonders2_divide_by_seven(wndrAnm->unk1) < 3) && (i > 2))) {
          D_800E1F64 = wndrAnm->unk8[i]->unk4;
          D_800E1F60 = wndrAnm->unk8[i]->unk0;
          wonders1_80044628_eightliner(wndrAnm->unk8[i]);
          func_800A6AA8(D_800E1F64);
          D_800E1F64 = NULL;
          func_800A6A2C(D_800E1F60);
          D_800E1F60 = NULL;
          main_8004A34C_threeliner();
        }

        if ((D_800CF5F0[wndrAnm->unk1] == i) && wonders2_8004619c_sixliner_crazy_if(wndrAnm->unk1)) {
          if (wonders2_divide_by_seven(wndrAnm->unk1) > 2) {
            wndrAnm->state = 2;
          } else {
            func_8007EFB0(10);
            wndrAnm->state = 3;
          }
        }
      }
    }
    func_80077098(wndrAnm->unk8[i]);
  }

  temp_v0 = wonders2_80046388_fiveliner(wonders2_divide_by_seven(wndrAnm->unk1));
  if (temp_v0 == 0) {
    sprintf(sp58, "WONDER COMPLETE");
    wonders1_800446ac_eightliner(temp_s4);
  } else if (temp_v0 == 1) {
    sprintf(sp58, "1 LINE NEEDED");
  } else {
    sprintf(sp58, "%u LINES NEEDED", temp_v0);
  }

  func_8005BBFC(&g_gdl);
  i = 200 - (get_text_width(&wndrAnm->font_0, sp58) / 2);
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 250, sp58, 0xFF, 0xFF, 0xFF, D_800E1F6E);
  if (wndrAnm->state == 0) {
    temp_s6 = wndrAnm->font_0.width;
    temp_s7 = temp_s6 + (wndrAnm->font_1.width * 4);
    i = 130;
    sprintf(sp58, "A");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp58, 0x7F, 0x7F, 0xFF, 0xFF);
    i += temp_s6;
    sprintf(sp58, "HALL");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp58, 0xFF, 0xFF, 0xFF, 0xFF);
    i += temp_s7;
    sprintf(sp58, "B");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp58, 0x7F, 0xFF, 0x7F, 0xFF);
    i += temp_s6;
    sprintf(sp58, "EXIT");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp58, 0xFF, 0xFF, 0xFF, 0xFF);
  }
  func_8005BE40(&g_gdl);
}

static void wonders1_display_complete_message(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;
  register u16 i;
  register u16 temp_s2;
  register u16 temp_s3;
  register u8 temp_s4;
  char sp4C[24];

  temp_s4 = frametime_delta();
  if ((wndrAnm->unk2 + temp_s4) < 0xFFFF) {
    wndrAnm->unk2 += temp_s4;
  } else {
    wndrAnm->unk2 = 0xFFFF;
  }

  for (i = 0; wndrAnm->unk8[i] != NULL; i++) {
    if (wndrAnm->unk8[i]->unk2C != 0) {
      temp_s2 = wndrAnm->unk4[i]->unk0;
      temp_s3 = wndrAnm->unk4[i]->unk2;
      if (!(wndrAnm->unk8[i]->unk20 & 0x1) && (temp_s2 != 0xFFFF) && (wndrAnm->unk2 < temp_s3) && (wndrAnm->unk2 >= temp_s2)) {
        func_800773A4(wndrAnm->unk8[i]);
        wndrAnm->unk8[i]->unk24 = wndrAnm->unk2 - temp_s4;
      }
      if ((wndrAnm->unk8[i]->unk20 & 0x1) && (temp_s3 != 0xFFFF) && (wndrAnm->unk2 >= temp_s3)) {
        func_800773B8(wndrAnm->unk8[i]);
      }
    }
    func_80077098(wndrAnm->unk8[i]);
  }

  sprintf(sp4C, "WONDER COMPLETE");
  wonders1_800446ac_eightliner(temp_s4);
  func_8005BBFC(&g_gdl);
  i = 200 - (get_text_width(&wndrAnm->font_0, sp4C) / 2);
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 250, sp4C, 0xFF, 0xFF, 0xFF, D_800E1F6E);
  wonders4_display_contribs_or_story(&wndrAnm->font_1);
  func_8005BE40(&g_gdl);
}

static void wonders1_finale_or_hall(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;
  register u8 temp_s1;
  register u16 i;
  register UnkStruct_50 *temp_s3;
  register u16 temp_s4;
  register u16 temp_s5;
  char sp4C[20];

  if ((wndrAnm->state == 0) && !(wndrAnm->unk8[0]->unk20 & 0x1)) {
    func_800773A4(wndrAnm->unk8[0]);
  }

  temp_s1 = frametime_delta();
  if ((wndrAnm->unk2 + temp_s1) < 0xFFFF) {
    wndrAnm->unk2 += temp_s1;
  } else {
    wndrAnm->unk2 = 0xFFFF;
  }

  i = wonders2_divide_by_seven(wndrAnm->unk1);
  if ((wndrAnm->unk8[0]->unk20 & 0x1) && (wndrAnm->unk2 >= wndrAnm->unk4[0]->unk2)) {
    if ((i == 0) || (i == 6)) {
      temp_s3 = wndrAnm->unk8[0]->unk0->unk1D0;
      if (temp_s3->unk18 == 0) {
        temp_s3->unk18 = 1;
        temp_s3->unkC->unk18 = 0;
      }
    } else {
      func_800773B8(wndrAnm->unk8[0]);
    }
    if ((wndrAnm->state == 0) && (wndrAnm->unk1 == 48) && !D_800CF840) {
      wndrAnm->state = 10;
    }
  }

  func_80077098(wndrAnm->unk8[0]);

  if ((wndrAnm->state == 0) || (wndrAnm->state == 10)) {
    func_8005BBFC(&g_gdl);
    if (!(wndrAnm->unk8[0]->unk20 & 0x1) || ((i == 0) && (wndrAnm->unk2 >= 2749)) || ((i == 6) && (wndrAnm->unk2 >= 3999))) {
      wonders4_display_contribs_or_story(&wndrAnm->font_0);
    }
    temp_s4 = wndrAnm->font_0.width;
    temp_s5 = temp_s4 + (wndrAnm->font_1.width * 4);
    i = 130;
    sprintf(sp4C, "A");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp4C, 0x7F, 0x7F, 0xFF, 0xFF);
    i += temp_s4;
    if (wndrAnm->state == 10) {
      sprintf(sp4C, "FINALE");
    } else {
      sprintf(sp4C, "HALL");
    }
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp4C, 0xFF, 0xFF, 0xFF, 0xFF);
    i += temp_s5;
    sprintf(sp4C, "B");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp4C, 0x7F, 0xFF, 0x7F, 0xFF);
    i += temp_s4;
    sprintf(sp4C, "EXIT");
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp4C, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8005BE40(&g_gdl);
  }
}

static void wonders1_800455bc_inc_won_compl_q(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;
  register u8 temp_s1;
  register u16 temp_s2;
  register u16 temp_s3;
  register u16 i;
  char sp48[20];

  if ((wndrAnm->state == 0) && !(wndrAnm->unk8[0]->unk20 & 0x1)) {
    func_800773A4(wndrAnm->unk8[0]);
  }

  temp_s1 = frametime_delta();
  if ((wndrAnm->unk2 + temp_s1) < 0xFFFF) {
    wndrAnm->unk2 += temp_s1;
  } else {
    wndrAnm->unk2 = 0xFFFF;
  }

  if ((wndrAnm->unk8[0]->unk20 & 0x1) && (wndrAnm->unk2 >= wndrAnm->unk4[0]->unk2)) {
    func_800773B8(wndrAnm->unk8[0]);
    if (wndrAnm->unk1 < 55) {
      wndrAnm->unk1++;
    } else {
      wndrAnm->unk1 = 49;
    }
    wndrAnm->state = 13;
  }

  func_80077098(wndrAnm->unk8[0]);

  func_8005BBFC(&g_gdl);
  if (wndrAnm->state == 0) {
    sprintf(sp48, "%s", D_800CF844[wndrAnm->unk1 - 49]);
    i = 200 - (get_text_width(&wndrAnm->font_0, sp48) / 2);
    displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 250, sp48, 0xFF, 0xFF, 0xFF, 0xFF);
  }
  temp_s2 = wndrAnm->font_0.width;
  temp_s3 = temp_s2 + (wndrAnm->font_1.width * 4);
  i = 130;
  sprintf(sp48, "A");
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp48, 0x7F, 0x7F, 0xFF, 0xFF);
  i += temp_s2;
  sprintf(sp48, "HALL");
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp48, 0xFF, 0xFF, 0xFF, 0xFF);
  i += temp_s3;
  sprintf(sp48, "B");
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_0, i, 266, sp48, 0x7F, 0xFF, 0x7F, 0xFF);
  i += temp_s2;
  sprintf(sp48, "EXIT");
  displayText_XY_RGBA_2(&g_gdl, &wndrAnm->font_1, i, 266, sp48, 0xFF, 0xFF, 0xFF, 0xFF);
  func_8005BE40(&g_gdl);
}

void wonders1_something_hall_or_exit_case(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;

  if (wndrAnm == NULL) {
    return;
  }

  switch (wndrAnm->state) {
  case 2:
    wonders1_hall_or_exit();
    if (wndrAnm->unk2 >= 1490) {
      func_8007EFB0(10);
      wndrAnm->state = 3;
    }
    break;
  case 3:
    wonders1_hall_or_exit();
    if (func_8007ED00() != 0) {
      func_8007F288(45);
      wndrAnm->state = 5;
    }
    break;
  case 4:
    wonders1_display_complete_message();
    if (func_8007EFE4() != 0) {
      wndrAnm->unk2 = 0;
      wndrAnm->state = 6;
      D_800E1F6C = (D_800CFB60[wonders2_divide_by_seven(wndrAnm->unk1)] - 2) * wndrAnm->font_1.height * 8;
    }
    break;
  case 6:
    wonders1_display_complete_message();
    if (wndrAnm->unk2 >= D_800E1F6C) {
      func_8007E9F8(90);
      wndrAnm->state = 7;
    }
    break;
  case 7:
    wonders1_display_complete_message();
    if (func_8007E750() != 0) {
      func_8007ECC8(90);
      wndrAnm->state = 9;
    }
    break;
  case 8:
    wonders1_finale_or_hall();
    if (func_8007EA2C() != 0) {
      wndrAnm->state = 0;
    }
    break;
  case 11:
    wonders1_finale_or_hall();
    if (func_8007E750() != 0) {
      func_8007ECC8(90);
      wndrAnm->state = 13;
    }
    break;
  case 12:
    wonders1_800455bc_inc_won_compl_q();
    if (func_8007EA2C() != 0) {
      wndrAnm->state = 0;
    }
    break;
  default:
    if (wndrAnm->unk1 > 48) {
      wonders1_800455bc_inc_won_compl_q();
    } else if ((D_800CF83C == D_800CF838) && wonders2_8004619c_sixliner_crazy_if(wndrAnm->unk1)) {
      wonders1_finale_or_hall();
    } else {
      wonders1_hall_or_exit();
    }
    break;
  }
}

void wonders1_anim_related(s8 arg0) {
  register WonderAnim *wndrAnm;

  main_8004A34C_threeliner();
  g_wonderAnim = n64HeapAlloc(sizeof(WonderAnim));
  wndrAnm = g_wonderAnim;
  if (wndrAnm == NULL) {
    debug_print_reason_routine("Not enough memory", "for WonderAnim");
  }
  wndrAnm->unk8 = NULL;
  Font_Init46Char(&wndrAnm->font_0, IMG_FONT_B);
  Font_Init46Char(&wndrAnm->font_1, IMG_FONT_C);
  if (arg0 == -1) {
    wndrAnm->state = 14;
    wndrAnm->unk1 = 0;
  } else {
    wndrAnm->state = 1;
    wndrAnm->unk1 = arg0;
  }
  D_800E1F6E = 0xFF;
  D_800E1F6F = 0;
}

static void wonders1_calls_music_400x300_magic(void) {
  register WonderAnim *wndrAnm = g_wonderAnim;
  register u8 temp_s1;
  register u8 temp_s2;

  Font_Deinit(&wndrAnm->font_0);
  Font_Deinit(&wndrAnm->font_1);
  wonders1_80044218_tenliner_loop(wndrAnm);
  temp_s1 = wndrAnm->state;
  temp_s2 = wndrAnm->unk1;
  n64HeapUnalloc(g_wonderAnim);
  g_wonderAnim = NULL;
  main_8004A34C_threeliner();
  D_800D3CF0 = 0;
  if (temp_s1 == 14) {
    D_800CFEE8 = 8;
    wonders3_wonder_viewer(wonders2_divide_by_seven(temp_s2), 1, 0);
  } else if (D_801109F0 == 5) {
    func_8009035C(D_800D5850, D_800D5808);
    D_800CFEE8 = 4;
    D_800CFD48 = TRUE;
  } else if (D_801109F0 == 6) {
    func_8009035C(D_800D5D48, D_800D5CE8);
    D_800CFEE8 = 4;
    D_800CFD48 = TRUE;
  } else if (D_801109F0 == 4) {
    func_800905E8(1);
    D_800CFEE8 = 4;
    D_800CFD48 = TRUE;
  } else {
    Game_80051618_twentyliner(&g_game);
    D_800CFEE8 = 9;
    D_800CFD48 = TRUE;
  }
}
