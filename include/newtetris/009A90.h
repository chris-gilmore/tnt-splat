#ifndef _009A90_H_
#define _009A90_H_

typedef struct {
  /* 0x0 */ u16   unk0;
  /* 0x2 */ u16   unk2;
} UnkStruct_90; // 0x4 bytes

typedef struct {
  /* 0x0  */ u8             state;
  /* 0x1  */ s8             unk1;
  /* 0x2  */ u16            unk2;
  /* 0x4  */ UnkStruct_90 **unk4;
  /* 0x8  */ UnkStruct_11 **unk8;
  /* 0xC  */ Font           font_0;
  /* 0x84 */ Font           font_1;
} WonderAnim; // 0xFC bytes

extern void   wonders1_case6_calls_music_magic(void);
extern void   wonders1_something_hall_or_exit_case(void);
extern void   wonders1_anim_related(s8);

#endif /* !_009A90_H_ */
