#ifndef _AIPLAYER_H_
#define _AIPLAYER_H_

typedef struct {
  /* 0x0  */ u8              player_idx;
  /* 0x1  */ u8              unk1;
  /* 0x2  */ u8              unk2;
  /* 0x3  */ u8              unk3;
  /* 0x4  */ u8              unk4;
  /* 0x5  */ UnkStruct_105   unk5;
  /* 0x2E */ UnkStruct_107   unk2E;
} UnkStruct_85; // 0x47 bytes

extern u8 D_800E1F50;

extern UnkStruct_85 *D_800C5E04;

extern void   aiplayer_gameinit_related(u8, u8, u8);
extern void   aiplayer_80042b3c_calls_heap_unalloc(void);
extern void   aiplayer_8004311c_largefunction(void);
extern void   aiplayer_8004370c_threeliner(void);
extern void   aiplayer_8004376c_fiveliner(void);

#endif /* !_AIPLAYER_H_ */
