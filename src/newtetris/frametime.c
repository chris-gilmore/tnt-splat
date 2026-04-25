#include "common.h"

FrameTime g_frameTime;

void frametime_clear(void) {
  g_frameTime.count = 0;
  g_frameTime.delta = 0;
  g_frameTime.jiffies = 0;
  g_frameTime.seconds = 0;
  g_frameTime.minutes = 0;
  g_frameTime.hours = 0;
}

void frametime_reset(u32 count) {
  frametime_clear();
  g_frameTime.count = count;
}

void frametime_add(s32 delta) {
  g_frameTime.delta = delta;
  g_frameTime.count += delta;
  g_frameTime.jiffies += delta;
  while (g_frameTime.jiffies >= 60) {
    g_frameTime.jiffies -= 60;
    g_frameTime.seconds++;
    if (g_frameTime.seconds == 60) {
      g_frameTime.seconds = 0;
      g_frameTime.minutes++;
      if (g_frameTime.minutes == 60) {
        g_frameTime.minutes = 0;
        g_frameTime.hours++;
        if (g_frameTime.hours == 24) {
          g_frameTime.hours = 0;
        }
      }
    }
  }
}

void frametime_update(u32 count) {
  frametime_add(count - g_frameTime.count);
}

u32 frametime_count(void) {
  return g_frameTime.count;
}

s32 frametime_jiffies(void) {
  return g_frameTime.jiffies;
}

s32 frametime_seconds(void) {
  return g_frameTime.seconds;
}

s32 frametime_minutes(void) {
  return g_frameTime.minutes;
}

s32 frametime_hours(void) {
  return g_frameTime.hours;
}

s32 frametime_delta(void) {
  return g_frameTime.delta;
}
