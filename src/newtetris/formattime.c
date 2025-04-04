#include "common.h"

#define ABS(d) (((d) >= 0) ? (d) : -(d))

void displayTimeFormatted_XY_RGBA(u32 time, Font *p_font, s32 x, s32 y, s32 red, s32 green, s32 blue, s32 alpha) {
  char str[20];
  s32 unused;

  time /= 60;  // convert from jiffies to seconds

  // (bug) this should be moved above the statement (time /= 60;)
  // also, what is this trying to say?
  if (ABS(time - 5184000) < 216000) {  // 5184000 is 1 day in jiffies and 216000 is 1 hour in jiffies
    time = 0;
  }

  if (time >= 36000) {  // if >= 10 hours
    time = 35999;
  }

  if (time < 600) {  // if < 10 mins
    sprintf(str, "%1.1d:%1.1d%1.1d", ((time / 60) % 60) % 10, (time % 60) / 10, (time % 60) % 10);
  } else if (time < 3601) {  // (bug) if < 1 hour and 1 second (should be just 1 hour)
    sprintf(str, "%1.1d%1.1d:%1.1d%1.1d", ((time / 60) % 60) / 10, ((time / 60) % 60) % 10, (time % 60) / 10, (time % 60) % 10);
  } else {
    sprintf(str, "%1.1d:%1.1d%1.1d:%1.1d%1.1d", ((time / 60) / 60) % 10, ((time / 60) % 60) / 10, ((time / 60) % 60) % 10, (time % 60) / 10, (time % 60) % 10);
  }

  displayText_XY_RGBA_2(&g_gdl, p_font, x - get_text_width(p_font, str), y, str, red, green, blue, alpha);
}
