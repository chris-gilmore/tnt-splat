#include "common.h"
#include "minilzo.h"

static u32 _lzo1x_1_do_compress(u8 *, u32, u8 *, u32 *, void *);

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/__lzo_ptr_linear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/__lzo_align_gap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_assert.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_copyright.s")

u32 lzo_version(void) {
  return LZO_VERSION;
}

const char *lzo_version_string(void) {
  return LZO_VERSION_STRING;
}

const char *lzo_version_date(void) {
  return LZO_VERSION_DATE;
}

const char *_lzo_version_string(void) {
  return LZO_VERSION_STRING;
}

const char *_lzo_version_date(void) {
  return LZO_VERSION_DATE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_adler32.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_memcmp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_memcpy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_memmove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo_memset.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/basic_integral_check.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/basic_ptr_check.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/ptr_check.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/_lzo_config_check.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/schedule_insns_bug.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/strength_reduce_bug.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/__lzo_init2.s")

static u32 _lzo1x_1_do_compress(u8 *in, u32 in_len, u8 *out, u32 *out_len, void *wrkmem) {
  register u8 *ip;
  u8 *op;
  u8 *in_end = in + in_len;
  u8 *ip_end = in + in_len - 13;
  u8 *ii;
  u8 **dict = wrkmem;
  register u8 *m_pos;
  u32 m_off;
  u32 m_len;
  u32 dindex;
  register u32 t;
  register u32 tt;
  u8 *end;
  u8 *m;

  op = out;
  ip = in;
  ii = ip;
  ip += 4;
  for (;;) {
    dindex = ((0x21 * (((((((u32)ip[3] << 6) ^ ip[2]) << 5) ^ ip[1]) << 5) ^ ip[0])) >> 5) & 0x3FFF;
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
          op[-2] |= (u8)t;
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
          *op++ = ((m_len - 1) << 5) | ((m_off & 7) << 2);
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

s32 lzo1x_1_compress(u8 *in, u32 in_len, u8 *out, u32 *out_len, void *wrkmem) {
  u8 *op = out;
  u32 t;
  u8 *ii;
  u32 tt;

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
      op[-2] |= (u8)t;
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

s32 lzo1x_decompress(u8 *in, u32 in_len, u8 *out, u32 *out_len, void *wrkmem) {
  register u8 *op;
  register u8 *ip;
  register u32 t;
  register u8 *m_pos;
  u8 *ip_end = in + in_len;

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
        m_pos -= (t >> 2) & 7;
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
  return ip == ip_end ? 0 : (ip < ip_end ? -8 : -4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/lzo1x_decompress_safe.s")

#pragma GLOBAL_ASM("asm/nonmatchings/newtetris/minilzo/D_800DEA5C.s")
