#include "common.h"

char *strutil_nextline(char *str, char c) {
  while ((*str != c) && (*str != 0)) {
    str++;
  }

  return str;
}

s32 strutil_linelen(char *str, char c) {
  register s32 len = 0;

  while ((*str != c) && (*str != 0)) {
    str++;
    len++;
  }

  return len;
}

s32 strutil_linecnt(char *str) {
  register s32 cnt = 0;

  while (*str != 0) {
    if (*str == '\n') {
      cnt++;
    }
    str++;
  }

  return cnt;
}
