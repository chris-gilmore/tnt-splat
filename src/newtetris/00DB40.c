#include "common.h"

//static u8 D_800E1F96;
extern u8 D_800E1F96;

/* static */ void wonders4_display_contributors(Font *, u8, u16, u16, u16);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/wonders4_800476f0_thirtyliner.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/wonders4_display_contributors.s")
/*
void wonders4_display_contributors(Font *font, u8 arg1, u16 arg2, u16 arg3, u16 arg4) {
  register void *temp_s0;
  register s32 temp_s1;
  register s32 temp_s2;
  char sp70[4];
  char sp5C[20];
  char sp48[20];

  temp_s2 = func_80079F74(g_sram_ptr, D_800E1F96);
  if (arg1 == 0) {
    sprintf(&sp70, "");
    sprintf(&sp5C, "       CONTRIBUTORS");
    sprintf(&sp48, "");
  } else if (arg1 == 2) {
    sprintf(&sp70, "");
    sprintf(&sp5C, "NAME");
    sprintf(&sp48, "LINES");
  } else if (arg1 >= 4) {
    arg1 -= 4;
    if (((arg1 % 2) == 0) && ((arg1 / 2) < 10)) {
      temp_s0 = temp_s2 + (((s32) (arg1 & 0xFF) / 2) * 0x18);
      if ((temp_s0->unkC == 0) || (temp_s0->unkA == 0) || (temp_s0->unkA == 0)) {
        sprintf(&sp70, "");
        sprintf(&sp5C, "");
        sprintf(&sp48, "");
      } else {
        sprintf(&sp70, "%2u", (arg1 / 2) + 1);
        sprintf(&sp5C, "%-10s", temp_s0);
        sprintf(&sp48, "%10u", temp_s0->unkC);
      }
    } else {
      sprintf(&sp70, "");
      sprintf(&sp5C, "");
      sprintf(&sp48, "");
    }
  } else {
    sprintf(&sp70, "");
    sprintf(&sp5C, "");
    sprintf(&sp48, "");
  }
  temp_s1 = (0x14A - get_text_width(font, &sp48)) & 0xFFFF;
  displayText_80077ee0_5(&g_gdl, font, 0x39, (s32) arg2, &sp70, 0xFF, 0xFF, 0xFF, 0xFF, (s32) arg3, (s32) arg4);
  displayText_80077ee0_5(&g_gdl, font, 0x55, (s32) arg2, &sp5C, 0xFF, 0xFF, 0xFF, 0xFF, (s32) arg3, (s32) arg4);
  displayText_80077ee0_5(&g_gdl, font, temp_s1, (s32) arg2, &sp48, 0xFF, 0xFF, 0xFF, 0xFF, (s32) arg3, (s32) arg4);
}
*/

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6A8.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6AC.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6B0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6B8.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6C0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6C4.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6C8.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6CC.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6D0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6D8.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6E0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6E4.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6E8.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6EC.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6F0.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB6F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/wonders4_display_contribs_or_story.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DB9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBA8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBAE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBE14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBE34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBEFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DBFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DC004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DC008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DC00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/00DB40/D_800DC010.s")
