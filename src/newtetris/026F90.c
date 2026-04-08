#include "common.h"

static OSViMode D_8011FA80;

static u32 D_800D0280 = 1290;
static u32 D_800D0284 = 640;
static s32 D_800D0288 = 0;
static u32 D_800D028C = 400;
static u32 D_800D0290 = 240;
static u32 D_800D0294 = 800;
static u32 D_800D0298 = 0x4089A728;

void func_80060D10(OSViMode arg0) {
  D_800D0288 = 1;
  bcopy(&arg0, &D_8011FA80, sizeof(OSViMode));
}

void FUN_026900_80060d58_elevenliner(u8 arg0) {
  OSIntMask mask;

  mask = osSetIntMask(OS_IM_VI);
  if (arg0 == 1) {
    if (osTvType == OS_TV_NTSC) {
      osViModeTable[OS_VI_NTSC_LAN1].comRegs.xScale = 0;
    }
    if (osTvType == OS_TV_MPAL) {
      osViModeTable[OS_VI_MPAL_LAN1].comRegs.xScale = 0;
    }
  } else {
    if (osTvType == OS_TV_NTSC) {
      osViModeTable[OS_VI_NTSC_LAN1].comRegs.xScale = D_800D0284;
    }
    if (osTvType == OS_TV_MPAL) {
      osViModeTable[OS_VI_MPAL_LAN1].comRegs.xScale = D_800D0284;
    }
  }
  osSetIntMask(mask);
}

void func_80060E30(void) {
  OSIntMask mask;

  if (D_800D0288 != 0) {
    if (osTvType == OS_TV_NTSC) {
      func_80060D10(osViModeNtscLan1);
    }
    if (osTvType == OS_TV_MPAL) {
      func_80060D10(osViModeMpalLan1);
    }
    if (osTvType == OS_TV_PAL) {
      func_80060D10(osViModePalLan1);
    }

    if (osTvType == OS_TV_NTSC) {
      osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
    }
    if (osTvType == OS_TV_MPAL) {
      osViSetMode(&osViModeTable[OS_VI_MPAL_LAN1]);
    }

    mask = osSetIntMask(OS_IM_VI);
    if (osTvType == OS_TV_NTSC) {
      osViModeTable[OS_VI_NTSC_LAN1].comRegs.width = D_800D028C;
      osViModeTable[OS_VI_NTSC_LAN1].comRegs.xScale = D_800D0284;
      osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].origin = D_800D0294;
      osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].yScale = D_800D0280;
    }
    if (osTvType == OS_TV_MPAL) {
      osViModeTable[OS_VI_MPAL_LAN1].comRegs.width = 400;
      osViModeTable[OS_VI_MPAL_LAN1].comRegs.xScale = 640;
      osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].origin = 800;
      osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].origin = 800;
      osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].yScale = 1290;
      osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].yScale = 1290;
    }
    osSetIntMask(mask);

    osWritebackDCacheAll();
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
    D_800D0288 = 0;
  }
}

void func_8006110C(s32 arg0, s32 arg1) {
  D_800D0288 = 1;
}

void func_80061124(void) {
  D_800D0288 = 1;
}

// clears cfb[][]
void func_80061134(s32 width, s32 height) {
  s32 i;

  for (i = 0; i < width * height; i++) {
    cfb[0][i] = 0;
    cfb[1][i] = 0;
  }
}

void func_80061198(void) {
  if (D_800CFE34) {
    func_800614A8();
    FUN_026900_80060d58_elevenliner(1);
    return;
  }

  osResetType = 0;
  func_800611E0();
}

void func_800611E0(void) {
  if (osResetType == 1) {
    func_80061198();
    if (osTvType == OS_TV_MPAL) {

    }
  } else {
    if (osTvType == OS_TV_PAL) {
      osAppNMIBuffer[0] = osViModeTable[OS_VI_PAL_LAN1].comRegs.width;
      osAppNMIBuffer[1] = osViModeTable[OS_VI_PAL_LAN1].comRegs.xScale;
      osAppNMIBuffer[2] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].vStart;
      osAppNMIBuffer[3] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].vStart;
      osAppNMIBuffer[4] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].origin;
      osAppNMIBuffer[5] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].origin;
      osAppNMIBuffer[6] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[0].yScale;
      osAppNMIBuffer[7] = osViModeTable[OS_VI_PAL_LAN1].fldRegs[1].yScale;
    }
    if (osTvType == OS_TV_NTSC) {
      osAppNMIBuffer[0] = osViModeTable[OS_VI_NTSC_LAN1].comRegs.width;
      osAppNMIBuffer[1] = osViModeTable[OS_VI_NTSC_LAN1].comRegs.xScale;
      osAppNMIBuffer[2] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].vStart;
      osAppNMIBuffer[3] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].vStart;
      osAppNMIBuffer[4] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].origin;
      osAppNMIBuffer[5] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].origin;
      osAppNMIBuffer[6] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].yScale;
      osAppNMIBuffer[7] = osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].yScale;
    }
    if (osTvType == OS_TV_MPAL) {
      osAppNMIBuffer[0] = osViModeTable[OS_VI_MPAL_LAN1].comRegs.width;
      osAppNMIBuffer[1] = osViModeTable[OS_VI_MPAL_LAN1].comRegs.xScale;
      osAppNMIBuffer[2] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].vStart;
      osAppNMIBuffer[3] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].vStart;
      osAppNMIBuffer[4] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].origin;
      osAppNMIBuffer[5] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].origin;
      osAppNMIBuffer[6] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].yScale;
      osAppNMIBuffer[7] = osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].yScale;
    }
  }
}

void func_800614A8(void) {
  OSIntMask mask;

  mask = osSetIntMask(OS_IM_VI);
  if (osTvType == OS_TV_PAL) {
    D_8011FA80.comRegs.width = osAppNMIBuffer[0];
    D_8011FA80.comRegs.xScale = osAppNMIBuffer[1];
    D_8011FA80.fldRegs[0].vStart = osAppNMIBuffer[2];
    D_8011FA80.fldRegs[1].vStart = osAppNMIBuffer[3];
    D_8011FA80.fldRegs[0].origin = osAppNMIBuffer[4];
    D_8011FA80.fldRegs[1].origin = osAppNMIBuffer[5];
    D_8011FA80.fldRegs[0].yScale = osAppNMIBuffer[6];
    D_8011FA80.fldRegs[1].yScale = osAppNMIBuffer[7];
  }
  if (osTvType == OS_TV_NTSC) {
    osViModeTable[OS_VI_NTSC_LAN1].comRegs.width = osAppNMIBuffer[0];
    osViModeTable[OS_VI_NTSC_LAN1].comRegs.xScale = osAppNMIBuffer[1];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].vStart = osAppNMIBuffer[2];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].vStart = osAppNMIBuffer[3];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].origin = osAppNMIBuffer[4];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].origin = osAppNMIBuffer[5];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[0].yScale = osAppNMIBuffer[6];
    osViModeTable[OS_VI_NTSC_LAN1].fldRegs[1].yScale = osAppNMIBuffer[7];
  }
  if (osTvType == OS_TV_MPAL) {
    osViModeTable[OS_VI_MPAL_LAN1].comRegs.width = osAppNMIBuffer[0];
    osViModeTable[OS_VI_MPAL_LAN1].comRegs.xScale = osAppNMIBuffer[1];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].vStart = osAppNMIBuffer[2];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].vStart = osAppNMIBuffer[3];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].origin = osAppNMIBuffer[4];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].origin = osAppNMIBuffer[5];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[0].yScale = osAppNMIBuffer[6];
    osViModeTable[OS_VI_MPAL_LAN1].fldRegs[1].yScale = osAppNMIBuffer[7];
  }
  osSetIntMask(mask);
}
