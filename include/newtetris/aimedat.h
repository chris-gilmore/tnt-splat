#ifndef _AIMEDAT_H_
#define _AIMEDAT_H_

typedef struct {
  /* 0x0 */ s16   red;
  /* 0x2 */ s16   green;
  /* 0x4 */ s16   blue;
  /* 0x6 */ s16   alpha;
} RGBA; // 0x8 bytes

typedef struct {
  /* 0x0 */ u8      unk0;
  /* 0x1 */ u8      unk1[4];
  /* 0x6 */ Point   unk6;
  /* 0xA */ u8      unkA;
} UnkStruct_111; // 0xC bytes

typedef struct {
  /* 0x0 */ UnkStruct_111  *list;
  /* 0x4 */ u8              numIndicators;
  /* 0x6 */ RGBA            color[4];
} UnkStruct_112; // 0x28 bytes

extern void   AimedAt_Render(UnkStruct_112 *);
extern void   func_80073688(UnkStruct_112 *);  // unused
extern void   func_80073690(UnkStruct_112 *, u8, u8, u8);
extern void   func_800736E0(UnkStruct_112 *, u8, u8);
extern void   func_80073784(UnkStruct_112 *, u8);
extern void   func_80073940(UnkStruct_112 *);
extern void   func_80073AC4(UnkStruct_112 *);
extern void   AimedAt_Init(void);
extern void   AimedAt_Deinit(void);

#endif /* !_AIMEDAT_H_ */
