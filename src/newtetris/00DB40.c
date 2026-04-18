#include "common.h"

static u8 D_800E1F90;
static u8 D_800E1F91;
static u8 D_800E1F92;
static u8 D_800E1F93;
static u8 D_800E1F94;
static u8 D_800E1F95;
static u8 D_800E1F96;
static u8 D_800E1F97;
static u8 D_800E1F98;

static void wonders4_display_contributors(Font *, u8, u16, u16, u16);

void wonders4_800476f0_thirtyliner(u8 font, u8 arg1) {
  register UnkStruct_3 *contributor;
  register u8 i;
  register Contributions *contributions;

  D_800E1F96 = font;
  D_800E1F90 = arg1;
  if (D_800E1F90 == 0) {
    D_800E1F94 = 115;
    D_800E1F95 = 195;
    D_800E1F91 = D_800CFB60[D_800E1F96] - 4;
    D_800E1F97 = 4;
    D_800E1F98 = D_800CFB60[D_800E1F96];
  } else if (D_800E1F90 == 2) {
    D_800E1F95 = 50;
    D_800E1F97 = 15;
    contributions = func_80079F74(g_sram_ptr, D_800E1F96);
    for (i = 0; i < 10; i++) {
      contributor = &contributions->contributors[i];
      if ((contributor->lines == 0) || (contributor->unkA == 0) || (contributor->unkA == 0)) {
        break;
      }
    }
    D_800E1F98 = (i * 2) + 19;
    D_800E1F91 = D_800E1F98 - 15;
  } else {
    D_800E1F94 = 80;
    D_800E1F95 = 30;
    D_800E1F91 = D_800CFB60[D_800E1F96] - 4;
    D_800E1F97 = 4;
    D_800E1F98 = D_800CFB60[D_800E1F96];
  }
  D_800E1F92 = 0;
  D_800E1F93 = 0;
}

static void wonders4_display_contributors(Font *font, u8 arg1, u16 arg2, u16 arg3, u16 arg4) {
  register UnkStruct_3 *contributor;
  register u16 lines_x;
  register Contributions *contributions;
  char rank[4];
  char name[20];
  char lines[20];

  contributions = func_80079F74(g_sram_ptr, D_800E1F96);
  if (arg1 == 0) {
    sprintf(rank, "");
    sprintf(name, "       CONTRIBUTORS");
    sprintf(lines, "");
  } else if (arg1 == 2) {
    sprintf(rank, "");
    sprintf(name, "NAME");
    sprintf(lines, "LINES");
  } else if (arg1 >= 4) {
    arg1 -= 4;
    if (!(arg1 % 2) && arg1 / 2 < 10) {
      contributor = &contributions->contributors[arg1 / 2];
      if ((contributor->lines == 0) || (contributor->unkA == 0) || (contributor->unkA == 0)) {
        sprintf(rank, "");
        sprintf(name, "");
        sprintf(lines, "");
      } else {
        sprintf(rank, "%2u", (arg1 / 2) + 1);
        sprintf(name, "%-10s", contributor->name);
        sprintf(lines, "%10u", contributor->lines);
      }
    } else {
      sprintf(rank, "");
      sprintf(name, "");
      sprintf(lines, "");
    }
  } else {
    sprintf(rank, "");
    sprintf(name, "");
    sprintf(lines, "");
  }
  lines_x = 330 - get_text_width(font, lines);
  displayText_80077ee0_5(&g_gdl, font, 57, arg2, rank, 0xFF, 0xFF, 0xFF, 0xFF, arg3, arg4);
  displayText_80077ee0_5(&g_gdl, font, 85, arg2, name, 0xFF, 0xFF, 0xFF, 0xFF, arg3, arg4);
  displayText_80077ee0_5(&g_gdl, font, lines_x, arg2, lines, 0xFF, 0xFF, 0xFF, 0xFF, arg3, arg4);
}

void wonders4_display_contribs_or_story(Font *font) {
  register u8 i;
  register u8 var_s1;
  register u8 var_s2;
  register u8 var_s3;
  char text[32];

  var_s1 = D_800E1F95;
  var_s2 = font->height;
  var_s3 = D_800E1F91;

  if (D_800E1F90 == 2) {
    wonders4_display_contributors(font, var_s3, var_s1, D_800E1F92, var_s2 - 1);
  } else {
    sprintf(text, "%s", D_800CFD18[D_800E1F96][var_s3]);
    displayText_80077ee0_5(&g_gdl, font, D_800E1F94, var_s1, text, 0xFF, 0xFF, 0xFF, 0xFF, D_800E1F92, var_s2 - 1);
  }
  var_s1 += var_s2 - D_800E1F92;
  var_s3++;
  if (var_s3 == D_800E1F98) {
    var_s3 = 0;
  }

  for (i = 1; i < D_800E1F97; i++) {
    if (D_800E1F90 == 2) {
      wonders4_display_contributors(font, var_s3, var_s1, 0, var_s2 - 1);
    } else {
      sprintf(text, "%s", D_800CFD18[D_800E1F96][var_s3]);
      displayText_XY_RGBA_2(&g_gdl, font, D_800E1F94, var_s1, text, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    var_s1 += var_s2;
    var_s3++;
    if (var_s3 == D_800E1F98) {
      var_s3 = 0;
    }
  }

  if (D_800E1F90 == 2) {
    wonders4_display_contributors(font, var_s3, var_s1, 0, D_800E1F92);
  } else {
    sprintf(text, "%s", D_800CFD18[D_800E1F96][var_s3]);
    displayText_80077ee0_5(&g_gdl, font, D_800E1F94, var_s1, text, 0xFF, 0xFF, 0xFF, 0xFF, 0, D_800E1F92);
  }

  D_800E1F93 += frametime_delta();
  if (D_800E1F93 >= 8) {
    D_800E1F92++;
    D_800E1F93 -= 8;
    if (D_800E1F92 >= var_s2) {
      D_800E1F92 = 0;
      D_800E1F91++;
      if (D_800E1F91 == D_800E1F98) {
        D_800E1F91 = 0;
      }
    }
  }
}

u8 D_800CFB60[] = { 18, 14, 16, 14, 14, 17, 15 };

char *D_800CFB68[] = {
  " THE CARACOL AT CHICHEN ITZA",
  "",
  "MADE BY THE MAYANS DURING THE",
  "FIRST MILLENNIUM, AND STANDING",
  "ABOUT 400 FT (122 M) TALL, IT",
  "IS ONE OF THE MAIN STRUCTURES",
  "OF THE GREAT MAYAN CITY CALLED",
  "CHICHEN ITZA. ITS PRESENT DAY",
  "NAME COMES FROM THE SPANISH",
  "WORD FOR SNAIL, WHICH ITS RUIN",
  "RESEMBLES. THIS IS HOW THE",
  "CARACOL MIGHT HAVE LOOKED WHEN",
  "CHICHEN ITZA WAS AT ITS MOST",
  "POWERFUL, IN 1180 A.D.",
  "",
  "",
  "",
  "",
};

char *D_800CFBB0[] = {
  "   THE SANCTUARY OF APOLLO",
  "          AT DELPHI",
  "",
  "FOR HUNDREDS OF YEARS IT SAT",
  "AT THE CENTER OF THE GREEK",
  "EMPIRE. THE FEMALE ORACLES OF",
  "APOLLO GAVE ENIGMATIC ANSWERS",
  "THAT OFTEN STUNNED THE WORLD'S",
  "LEADERS AND CHANGED THE COURSE",
  "OF HISTORY.",
  "",
  "",
  "",
  "",
};

char *D_800CFBE8[] = {
  "   THE GREAT SPHINX AT GIZA",
  "",
  "IT GUARDS THE APPROACH TO THE",
  "PYRAMID OF KHAFRE IN GIZA,",
  "EGYPT. CARVED IN 2500 B.C.,",
  "THIS HUGE MONUMENT SHOWS THE",
  "ROYAL VISAGE OF PHARAOH KHAFRE",
  "ATOP THE BODY OF A HUGE LION.",
  "WHAT YOU SEE HERE IS THE GREAT",
  "SPHINX AS IT MAY HAVE LOOKED",
  "IN 1500 B.C., AFTER BEING",
  "RESTORED BY THUTMOSE THE 4TH.",
  "",
  "",
  "",
  "",
};

char *D_800CFC28[] = {
  "          STONEHENGE",
  "",
  "AN ANCIENT MONUMENT LOCATED ON",
  "SALISBURY PLAIN IN ENGLAND, IT",
  "IS MADE UP OF SEVERAL GROUPS",
  "OF HUGE STANDING STONES, PLUS",
  "DITCHES AND EARTHWORKS. IT WAS",
  "PROBABLY USED AS A TEMPLE.",
  "THIS IS STONEHENGE AS IT MAY",
  "HAVE LOOKED IN 1500 B.C.",
  "",
  "",
  "",
  "",
};

char *D_800CFC60[] = {
  "  THE GREAT MOSQUE AT DJENNE",
  "",
  "THE CITY OF DJENNE, IN MALI,",
  "HAS HAD A MOSQUE AT ITS CENTER",
  "SINCE THE 8TH CENTURY. IT IS A",
  "MAGNIFICENT BLEND OF LOCAL AND",
  "MUSLIM ARCHITECTURAL STYLES.",
  "WHAT YOU SEE HERE IS THE GREAT",
  "MOSQUE AT DJENNE MUCH AS IT",
  "APPEARS TODAY.",
  "",
  "",
  "",
  "",
};

char *D_800CFC98[] = {
  "    THE HORYU JI MONASTERY",
  "       NEAR NARA, JAPAN",
  "",
  "THIS BUDDHIST TEMPLE CAPTURES",
  "WHAT WAS A SIGNIFICANT MOMENT",
  "IN JAPANESE HISTORY, WHEN THE",
  "CULTURAL EXCHANGE WITH CHINA",
  "BEGAN TO EXERT WIDE INFLUENCE",
  "OVER JAPANESE MEDICINE, ART,",
  "TECHNOLOGY, AND ARCHITECTURE.",
  "ITS GRACEFUL LINES INFLUENCED",
  "THE DESIGN OF NARA, JAPAN'S",
  "FIRST IMPERIAL CITY.",
  "",
  "",
  "",
  "",
};

char *D_800CFCDC[] = {
  "ST.BASIL'S CATHEDRAL IN MOSCOW",
  "",
  "THE 'STONE FLOWER IN RED",
  "SQUARE' WAS COMMISSIONED BY",
  "CZAR IVAN THE 4TH, ALSO KNOWN",
  "AS 'THE TERRIBLE,' IN 1552 TO",
  "COMMEMORATE THE CAPTURE OF THE",
  "TARTAR CITY KAZAN. IT SHOWS",
  "HOW BOTH BYZANTINE AND ASIATIC",
  "INFLUENCES HAVE COME TOGETHER",
  "IN RUSSIAN CULTURE.",
  "",
  "",
  "",
  "",
};

char **D_800CFD18[] = {
  D_800CFB68,
  D_800CFBB0,
  D_800CFBE8,
  D_800CFC28,
  D_800CFC60,
  D_800CFC98,
  D_800CFCDC,
};
