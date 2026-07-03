#ifndef _AIPLAYER_H_
#define _AIPLAYER_H_

typedef struct {
  /* 0x0  */ u8   player_idx;

  /* 0x1  */ u8   unk1;
  /* 0x2  */ u8   unk2;
  /* 0x3  */ u8   unk3;

  /* 0x4  */ u8   unk4;

  /* 0x5  */ UnkStruct_105   unk5;

  /* 0x2E */ u8   unk2E;
  /* 0x2F */ u8   unk2F;
  /* 0x30 */ u8   unk30;
  /* 0x31 */ u8   unk31;
  /* 0x32 */ u8   unk32;
  /* 0x33 */ u8   unk33;
  /* 0x34 */ u8   unk34;
  /* 0x35 */ u8   unk35;
  /* 0x36 */ u8   unk36;
  /* 0x37 */ u8   unk37;
  /* 0x38 */ u8   unk38;
  /* 0x39 */ u8   unk39;
  /* 0x3A */ u8   unk3A;
  /* 0x3B */ u8   unk3B;
  /* 0x3C */ u8   unk3C;
  /* 0x3D */ u8   unk3D;
  /* 0x3E */ u8   unk3E;
  /* 0x3F */ u8   unk3F;
  /* 0x40 */ u8   unk40;
  /* 0x41 */ u8   unk41;
  /* 0x42 */ u8   unk42;
  /* 0x43 */ u8   unk43;
  /* 0x44 */ u8   unk44;
  /* 0x45 */ u8   unk45;
  /* 0x46 */ u8   unk46;
} UnkStruct_85; // 0x47 bytes

extern u8 D_800E1F50;

extern UnkStruct_85 *D_800C5E04;

extern void   aiplayer_gameinit_related(u8, u8, u8);
extern void   aiplayer_80042b3c_calls_heap_unalloc(void);
extern void   aiplayer_8004311c_largefunction(void);
extern void   aiplayer_8004370c_threeliner(void);
extern void   aiplayer_8004376c_fiveliner(void);

#endif /* !_AIPLAYER_H_ */
