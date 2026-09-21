#include "minilzo.h"

#ifndef NULL
#define NULL 0
#endif

static int basic_integral_check(void);
static int basic_ptr_check(void);
static int ptr_check(void);
static int schedule_insns_bug(void);
static int strength_reduce_bug(int *x);
static unsigned int _lzo1x_1_do_compress(unsigned char *, unsigned int, unsigned char *, unsigned int *, void *);

unsigned int __lzo_ptr_linear(void *ptr) {
  unsigned int p;

  p = (unsigned int) ptr;

  return p;
}

unsigned int __lzo_align_gap(void *ptr, unsigned int size) {
  unsigned int p;
  unsigned int s;
  unsigned int n;

  p = __lzo_ptr_linear(ptr);
  s = size - 1;
  n = (((p + s) / size) * size) - p;

  return n;
}

int lzo_assert(int expr) {
  return (expr != 0) ? 1 : 0;
}

char *lzo_copyright(void) {
  return " $\n";
}

unsigned int lzo_version(void) {
  return LZO_VERSION;
}

char *lzo_version_string(void) {
  return LZO_VERSION_STRING;
}

char *lzo_version_date(void) {
  return LZO_VERSION_DATE;
}

char *_lzo_version_string(void) {
  return LZO_VERSION_STRING;
}

char *_lzo_version_date(void) {
  return LZO_VERSION_DATE;
}

unsigned int lzo_adler32(unsigned int adler, unsigned char *buf, unsigned int len) {
  unsigned int s1 = adler & 0xffff;
  unsigned int s2 = (adler >> 16) & 0xffff;
  int k;

  if (buf == NULL) {
    return 1;
  }

  while (len > 0) {
    k = (len < 5552) ? len : 5552;
    len -= k;
    while (k >= 16) {
      s1 += buf[0]; s2 += s1;
      s1 += buf[1]; s2 += s1;
      s1 += buf[2]; s2 += s1;
      s1 += buf[3]; s2 += s1;
      s1 += buf[4]; s2 += s1;
      s1 += buf[5]; s2 += s1;
      s1 += buf[6]; s2 += s1;
      s1 += buf[7]; s2 += s1;
      s1 += buf[8]; s2 += s1;
      s1 += buf[9]; s2 += s1;
      s1 += buf[10]; s2 += s1;
      s1 += buf[11]; s2 += s1;
      s1 += buf[12]; s2 += s1;
      s1 += buf[13]; s2 += s1;
      s1 += buf[14]; s2 += s1;
      s1 += buf[15]; s2 += s1;

      buf += 16;
      k -= 16;
    }

    if (k != 0) {
      do {
        s1 += *buf++;
        s2 += s1;
      } while (--k > 0);
    }

    s1 %= 65521;
    s2 %= 65521;
  }

  return (s2 << 16) | s1;
}

int lzo_memcmp(void *s1, void *s2, unsigned int len) {
  unsigned char *p1 = s1;
  unsigned char *p2 = s2;
  int d;

  for (; len > 0; len--) {
    d = *p1 - *p2;
    if (d != 0) {
      return d;
    }
    p1++;
    p2++;
  }

  return 0;
}

void *lzo_memcpy(void *dest, void *src, unsigned int len) {
  unsigned char *p1 = dest;
  unsigned char *p2 = src;

  if ((len <= 0) || (p1 == p2)) {
    return dest;
  }

  do {
    *p1++ = *p2++;
  } while (--len > 0);

  return dest;
}

void *lzo_memmove(void *dest, void *src, unsigned int len) {
  unsigned char *p1 = dest;
  unsigned char *p2 = src;

  if ((len <= 0) || (p1 == p2)) {
    return dest;
  }

  if (p1 < p2) {
    do {
      *p1++ = *p2++;
    } while (--len > 0);
  } else {
    p1 += len;
    p2 += len;
    do {
      *--p1 = *--p2;
    } while (--len > 0);
  }

  return dest;
}

void *lzo_memset(void *s, int c, unsigned int len) {
  unsigned char *p = s;

  for (; len > 0; len--) {
    *p++ = c;
  }

  return s;
}

static int basic_integral_check(void) {
  int r = 1;
  int sanity;

  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;

  sanity = 1;

  if (sanity) {
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
  }

  return r;
}

static int basic_ptr_check(void) {
  int r = 1;
  int sanity;

  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;
  r &= 1;

  sanity = 1;

  if (sanity) {
    r &= 1;
    r &= 1;
    r &= 1;
    r &= 1;
  }

  return r;
}

static int ptr_check(void) {
  int r = 1;
  int i;
  char _wrkmem[10 * 4 + 4];
  unsigned char *wrkmem;
  unsigned char **dict;
  unsigned char x[4 * 4];
  long d;
  union {
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    char *cp;
    unsigned char *ucp;
  } a;

  for (i = 0; i < (int) sizeof(x); i++) {
    x[i] = i;
  }

  wrkmem = _wrkmem + __lzo_align_gap(_wrkmem, 4);
  dict = (unsigned char **) wrkmem;

  d = (unsigned char *) dict - (unsigned char *) _wrkmem;
  r &= (d >= 0) ? 1 : 0;
  r &= (d < 4) ? 1 : 0;

  lzo_memset(&a, 0xFF, sizeof(a));
  r &= (a.us == 0xFFFF) ? 1 : 0;
  r &= (a.ui == 0xFFFFFFFF) ? 1 : 0;
  r &= (a.ul == 0xFFFFFFFF) ? 1 : 0;
  r &= (a.ui == 0xFFFFFFFF) ? 1 : 0;

  if (r == 1) {
    for (i = 0; i < 8; i++) {
      r &= ((void *) &dict[i] == (void *) &wrkmem[i * 4]) ? 1 : 0;
    }
  }

  lzo_memset(&a, 0, sizeof(a));
  r &= (a.cp == NULL) ? 1 : 0;
  r &= (a.ucp == NULL) ? 1 : 0;
  r &= 1;
  if (r == 1) {
    for (i = 0; i < 10; i++) {
      dict[i] = wrkmem;
    }
    lzo_memset(dict + 1, 0, sizeof(dict[0]) * 8);
    r &= (dict[0] == wrkmem) ? 1 : 0;
    for (i = 1; i < 9; i++) {
      r &= (dict[i] == NULL) ? 1 : 0;
    }
    r &= (dict[9] == wrkmem) ? 1 : 0;
  }

  if (r == 1) {
    unsigned int k = 1;
    unsigned int n = 4;
    unsigned char *p0;
    unsigned char *p1;

    k += __lzo_align_gap(&x[k], n);
    p0 = &x[k];
    r &= (((unsigned int)p0 & (n - 1)) == 0) ? 1 : 0;

    r &= (k >= 1) ? 1 : 0;
    p1 = &x[1];
    r &= ((unsigned int)p0 >= (unsigned int)p1) ? 1 : 0;

    r &= (k < (n + 1)) ? 1 : 0;
    p1 = &x[n + 1];
    r &= ((unsigned int)p0 < (unsigned int)p1) ? 1 : 0;

    if (r == 1) {
      unsigned int v0 = * (unsigned int *) &x[k];
      unsigned int v1 = * (unsigned int *) &x[k + n];

      r &= (v0 > 0) ? 1 : 0;
      r &= (v1 > 0) ? 1 : 0;
    }
  }

  return r;
}

int _lzo_config_check(void) {
  int r = 1;
  int i;
  unsigned int adler;
  unsigned char x[4 * 4];

  r &= basic_integral_check();
  r &= basic_ptr_check();
  if (r != 1) {
    return -1;
  }

  for (i = 0; i < (int) sizeof(x); i++) {
    x[i] = i;
  }

  r &= 1;
  if (r == 1) {
    adler = lzo_adler32(0, NULL, 0);
    adler = lzo_adler32(adler, lzo_copyright(), 200);
    r &= (adler == 0xFC1C43C4) ? 1 : 0;
  }

  if (r == 1) {
    r &= (!schedule_insns_bug()) ? 1 : 0;
  }

  if (r == 1) {
    static int x[3];
    static unsigned int xn = 3;
    register unsigned int j;

    for (j = 0; j < xn; j++) {
      x[j] = j - 3;
    }
    r &= (!strength_reduce_bug(x)) ? 1 : 0;
  }

  if (r == 1) {
    r &= ptr_check();
  }

  return (r == 1) ? 0 : -1;
}

static int schedule_insns_bug(void) {
  const int clone[] = {1, 2, 0};
  const int *q;

  q = clone;
  if (*q) {
    return 0;
  }
  return 1;
}

static int strength_reduce_bug(int *x) {
  return (x[0] != -3) || (x[1] != -2) || (x[2] != -1);
}

int __lzo_init_done = 0;

int __lzo_init2(unsigned int v, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9) {
  int r;

  __lzo_init_done = 1;

  if (v == 0) {
    return -1;
  }

  r =
    (s1 == -1 || s1 == 2) &&
    (s2 == -1 || s2 == 4) &&
    (s3 == -1 || s3 == 4) &&
    (s4 == -1 || s4 == 4) &&
    (s5 == -1 || s5 == 4) &&
    (s6 == -1 || s6 == 4) &&
    (s7 == -1 || s7 == 4) &&
    (s8 == -1 || s8 == 4) &&
    (s9 == -1 || s9 == 4);
  if (!r) {
    return -1;
  }

  r = _lzo_config_check();
  if (r != 0) {
    return r;
  }

  return r;
}

static unsigned int _lzo1x_1_do_compress(unsigned char *in, unsigned int in_len, unsigned char *out, unsigned int *out_len, void *wrkmem) {
  register unsigned char *ip;
  unsigned char *op;
  unsigned char *in_end = in + in_len;
  unsigned char *ip_end = in + in_len - 13;
  unsigned char *ii;
  unsigned char **dict = wrkmem;
  register unsigned char *m_pos;
  unsigned int m_off;
  unsigned int m_len;
  unsigned int dindex;
  register unsigned int t;
  register unsigned int tt;
  unsigned char *end;
  unsigned char *m;

  op = out;
  ip = in;
  ii = ip;
  ip += 4;
  for (;;) {
    dindex = ((0x21 * (((((((unsigned int)ip[3] << 6) ^ ip[2]) << 5) ^ ip[1]) << 5) ^ ip[0])) >> 5) & 0x3FFF;
    m_pos = dict[dindex];
    if (m_pos < in || (m_off = ip - m_pos) == 0 || m_off > 0xBFFF) {
      goto literal;
    }
    if (m_off <= 0x800 || m_pos[3] == ip[3]) {
      goto try_match;
    }
    dindex = (dindex & 0x7FF) ^ 0x201F;
    m_pos = dict[dindex];
    if (m_pos < in || (m_off = ip - m_pos) == 0 || m_off > 0xBFFF) {
      goto literal;
    }
    if (m_off <= 0x800 || m_pos[3] == ip[3]) {
      goto try_match;
    }
    goto literal;
  try_match:
    if (m_pos[0] != ip[0] || m_pos[1] != ip[1] || m_pos[2] != ip[2]) {
    literal:
      dict[dindex] = ip;
      ip++;
      if (ip >= ip_end) {
        break;
      }
      continue;
    } else {
      dict[dindex] = ip;
      if ((ip - ii) > 0) {
        t = ip - ii;
        if (t <= 3) {
          op[-2] |= (unsigned char)t;
        } else if (t <= 18) {
          *op++ = t - 3;
        } else {
          tt = t - 18;
          *op++ = 0;
          while (tt > 0xFF) {
            tt -= 0xFF;
            *op++ = 0;
          }
          *op++ = tt;
        }
        do {
          *op++ = *ii++;
        } while (--t > 0);
      }
      ip += 3;
      if (m_pos[3] != *ip++ || m_pos[4] != *ip++ || m_pos[5] != *ip++ || m_pos[6] != *ip++ || m_pos[7] != *ip++ || m_pos[8] != *ip++) {
        ip--;
        m_len = ip - ii;
        if (m_off <= 0x800) {
          m_off--;
          *op++ = ((m_len - 1) << 5) | ((m_off & 0x7) << 2);
          *op++ = m_off >> 3;
        } else {
          if (m_off <= 0x4000) {
            m_off--;
            *op++ = (m_len - 2) | 0x20;
          } else {
            m_off -= 0x4000;
            *op++ = ((m_off & 0x4000) >> 11) | 0x10 | (m_len - 2);
          }
          goto m3_m4_offset;
        }
      } else {
        end = in_end;
        m = m_pos + 9;
        while (ip < end && *m == *ip) {
          ip++;
          m++;
        }
        m_len = ip - ii;
        if (m_off <= 0x4000) {
          m_off--;
          if (m_len <= 33) {
            *op++ = (m_len - 2) | 0x20;
          } else {
            m_len -= 33;
            *op++ = 0x20;
            goto m3_m4_len;
          }
        } else {
          m_off -= 0x4000;
          if (m_len <= 9) {
            *op++ = ((m_off & 0x4000) >> 11) | 0x10 | (m_len - 2);
          } else {
            m_len -= 9;
            *op++ = ((m_off & 0x4000) >> 11) | 0x10;
          m3_m4_len:
            while (m_len > 0xFF) {
              m_len -= 0xFF;
              *op++ = 0;
            }
            *op++ = m_len;
          }
        }
      m3_m4_offset:
        *op++ = (m_off & 0x3F) << 2;
        *op++ = m_off >> 6;
      }
      ii = ip;
      if (ip >= ip_end) {
        break;
      }
    }
  }
  *out_len = op - out;
  return in_end - ii;
}

int lzo1x_1_compress(unsigned char *in, unsigned int in_len, unsigned char *out, unsigned int *out_len, void *wrkmem) {
  unsigned char *op = out;
  unsigned int t;
  unsigned char *ii;
  unsigned int tt;

  if (in_len < 14) {
    t = in_len;
  } else {
    t = _lzo1x_1_do_compress(in, in_len, op, out_len, wrkmem);
    op += *out_len;
  }
  if (t > 0) {
    ii = in + in_len - t;
    if (op == out && t < 0xEF) {
      *op++ = t + 0x11;
    } else if (t < 4) {
      op[-2] |= (unsigned char)t;
    } else if (t < 19) {
      *op++ = t - 3;
    } else {
      tt = t - 18;
      *op++ = 0;
      while (tt > 0xFF) {
        tt -= 0xFF;
        *op++ = 0;
      }
      *op++ = tt;
    }
    do {
      *op++ = *ii++;
    } while (--t > 0);
  }
  *op++ = 0x11;
  *op++ = 0;
  *op++ = 0;
  *out_len = op - out;
  return 0;
}

int lzo1x_decompress(unsigned char *in, unsigned int in_len, unsigned char *out, unsigned int *out_len, void *wrkmem) {
  register unsigned char *op;
  register unsigned char *ip;
  register unsigned int t;
  register unsigned char *m_pos;
  unsigned char *ip_end = in + in_len;

  *out_len = 0;
  ip = in;
  op = out;
  if (*ip > 17) {
    t = *ip++ - 17;
    if (t < 4) {
      goto match_next;
    }
    do {
      *op++ = *ip++;
    } while (--t > 0);
    goto first_literal_run;
  }
  while (1) {
    t = *ip++;
    if (t >= 16) {
      goto match;
    }
    if (t == 0) {
      while (*ip == 0) {
        t += 0xFF;
        ip++;
      }
      t += *ip++ + 15;
    }
    *op++ = *ip++; *op++ = *ip++; *op++ = *ip++;
    do {
      *op++ = *ip++;
    } while (--t > 0);
  first_literal_run:
    t = *ip++;
    if (t >= 16) {
      goto match;
    }
    m_pos = op - 0x801;
    m_pos -= t >> 2;
    m_pos -= *ip++ << 2;
    *op++ = *m_pos++; *op++ = *m_pos++; *op++ = *m_pos;
    goto match_done;
    while (1) {
    match:
      if (t >= 64) {
        m_pos = op - 1;
        m_pos -= (t >> 2) & 0x7;
        m_pos -= *ip++ << 3;
        t = (t >> 5) - 1;
        goto copy_match;
      } else if (t >= 32) {
        t &= 31;
        if (t == 0) {
          while (*ip == 0) {
            t += 0xFF;
            ip++;
          }
          t += *ip++ + 31;
        }
        m_pos = op - 1;
        m_pos -= (ip[0] >> 2) + (ip[1] << 6);
        ip += 2;
      } else if (t >= 16) {
        m_pos = op;
        m_pos -= (t & 8) << 11;
        t &= 7;
        if (t == 0) {
          while (*ip == 0) {
            t += 0xFF;
            ip++;
          }
          t += *ip++ + 7;
        }
        m_pos -= (ip[0] >> 2) + (ip[1] << 6);
        ip += 2;
        if (m_pos == op) {
          goto eof_found;
        }
        m_pos -= 0x4000;
      } else {
        m_pos = op - 1;
        m_pos -= t >> 2;
        m_pos -= *ip++ << 2;
        *op++ = *m_pos++; *op++ = *m_pos;
        goto match_done;
      }
    copy_match:
      *op++ = *m_pos++; *op++ = *m_pos++;
      do {
        *op++ = *m_pos++;
      } while (--t > 0);
    match_done:
      t = ip[-2] & 3;
      if (t == 0) {
        break;
      }
    match_next:
      do {
        *op++ = *ip++;
      } while (--t > 0);
      t = *ip++;
    }
  }
 eof_found:
  *out_len = op - out;
  return (ip == ip_end) ? 0 : ((ip < ip_end) ? -8 : -4);
}

int lzo1x_decompress_safe(unsigned char *in, unsigned int in_len, unsigned char *out, unsigned int *out_len, void *wrkmem) {
  register unsigned char *op;
  register unsigned char *ip;
  register unsigned int t;
  register unsigned char *m_pos;
  unsigned char *ip_end = in + in_len;
  unsigned char *op_end = out + *out_len;

  *out_len = 0;

  op = out;
  ip = in;

  if (*ip > 17) {
    t = *ip++ - 17;
    if (t < 4) {
      goto match_next;
    }

    if ((unsigned int) (op_end - op) < t) {
      goto output_overrun;
    }
    if ((unsigned int) (ip_end - ip) < (t + 1)) {
      goto input_overrun;
    }

    do {
      *op++ = *ip++;
    } while (--t > 0);

    goto first_literal_run;
  }

  while (ip < ip_end) {
    t = *ip++;
    if (t >= 16) {
      goto match;
    }
    if (t == 0) {
      if ((unsigned int) (ip_end - ip) < 1) {
        goto input_overrun;
      }
      while (*ip == 0) {
        t += 0xFF;
        ip++;
        if ((unsigned int) (ip_end - ip) < 1) {
          goto input_overrun;
        }
      }
      t += *ip++ + 15;
    }

    if ((unsigned int) (op_end - op) < (t + 3)) {
      goto output_overrun;
    }
    if ((unsigned int) (ip_end - ip) < (t + 4)) {
      goto input_overrun;
    }

    *op++ = *ip++; *op++ = *ip++; *op++ = *ip++;
    do {
      *op++ = *ip++;
    } while (--t > 0);
  first_literal_run:
    t = *ip++;
    if (t >= 16) {
      goto match;
    }

    m_pos = op - (1 + 0x800);
    m_pos -= t >> 2;
    m_pos -= *ip++ << 2;

    if (m_pos < out) {
      goto lookbehind_overrun;
    }
    if ((unsigned int) (op_end - op) < 3) {
      goto output_overrun;
    }
    *op++ = *m_pos++; *op++ = *m_pos++; *op++ = *m_pos;
    goto match_done;

    while (ip < ip_end) {
    match:
      if (t >= 64) {
        m_pos = op - 1;
        m_pos -= (t >> 2) & 0x7;
        m_pos -= *ip++ << 3;
        t = (t >> 5) - 1;

        if (m_pos < out) {
          goto lookbehind_overrun;
        }
        if ((unsigned int) (op_end - op) < (t + 2)) {
          goto output_overrun;
        }
        goto copy_match;
      } else if (t >= 32) {
        t &= 0x1F;
        if (t == 0) {
          if ((unsigned int) (ip_end - ip) < 1) {
            goto input_overrun;
          }
          while (*ip == 0) {
            t += 0xFF;
            ip++;
            if ((unsigned int) (ip_end - ip) < 1) {
              goto input_overrun;
            }
          }
          t += *ip++ + 31;
        }
        m_pos = op - 1;
        m_pos -= (ip[0] >> 2) + (ip[1] << 6);
        ip += 2;
      } else if (t >= 16) {
        m_pos = op;
        m_pos -= (t & 0x8) << 11;
        t &= 0x7;
        if (t == 0) {
          if ((unsigned int) (ip_end - ip) < 1) {
            goto input_overrun;
          }
          while (*ip == 0) {
            t += 0xFF;
            ip++;
            if ((unsigned int) (ip_end - ip) < 1) {
              goto input_overrun;
            }
          }
          t += *ip++ + 7;
        }
        m_pos -= (ip[0] >> 2) + (ip[1] << 6);
        ip += 2;
        if (m_pos == op) {
          goto eof_found;
        }
        m_pos -= 0x4000;
      } else {
        m_pos = op - 1;
        m_pos -= t >> 2;
        m_pos -= *ip++ << 2;
        if (m_pos < out) {
          goto lookbehind_overrun;
        }
        if ((unsigned int) (op_end - op) < 2) {
          goto output_overrun;
        }
        *op++ = *m_pos++; *op++ = *m_pos;
        goto match_done;
      }

      if (m_pos < out) {
        goto lookbehind_overrun;
      }
      if ((unsigned int) (op_end - op) < (t + 2)) {
        goto output_overrun;
      }

    copy_match:
      *op++ = *m_pos++; *op++ = *m_pos++;
      do {
        *op++ = *m_pos++;
      } while (--t > 0);

    match_done:
      t = ip[-2] & 3;
      if (t == 0) {
        break;
      }

    match_next:
      if ((unsigned int) (op_end - op) < t) {
        goto output_overrun;
      }
      if ((unsigned int) (ip_end - ip) < (t + 1)) {
        goto input_overrun;
      }
      do {
        *op++ = *ip++;
      } while (--t > 0);
      t = *ip++;
    }
  }

  *out_len = op - out;
  return -7;

 eof_found:
  *out_len = op - out;
  return (ip == ip_end) ? 0 : ((ip < ip_end) ? -8 : -4);

 input_overrun:
  *out_len = op - out;
  return -4;

 output_overrun:
  *out_len = op - out;
  return -5;

 lookbehind_overrun:
  *out_len = op - out;
  return -6;
}
