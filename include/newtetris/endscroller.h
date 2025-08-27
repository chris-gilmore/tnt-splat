#ifndef _ENDSCROLLER_H_
#define _ENDSCROLLER_H_

typedef struct {
  /* 0x0  */ Font  *p_font;
  /* 0x4  */ char  *str;
  /* 0x8  */ s32    len;
  /* 0xC  */ s32    w;
  /* 0x10 */ s32    h;
  /* 0x14 */ s32    x;
  /* 0x18 */ s32    y;
} ScrollLine; // 0x1C bytes

typedef struct {
  /* 0x0   */ u8             is_active;
  /* 0x1   */ u8             unk1;
  /* 0x4   */ Font           font[2];
  /* 0xF4  */ u32            num_lines;
  /* 0xF8  */ ScrollLine    *line_pool;
  /* 0xFC  */ u32            unkFC;
  /* 0x100 */ u32            unk100;
  /* 0x104 */ UnkStruct_12   unk104;
} UnkStruct_82; // 0x188 bytes

extern void   EndScroller_Init(UnkStruct_82 *, char *);
extern void   EndScroller_Deinit(UnkStruct_82 *);
extern s32    EndScroller_8008023c_line_452(UnkStruct_82 *, s32);
extern void   EndScroller_80080400_line_502(UnkStruct_82 *);

#endif /* !_ENDSCROLLER_H_ */
