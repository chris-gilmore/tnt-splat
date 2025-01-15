#ifndef _MULTISQUARE_H_
#define _MULTISQUARE_H_

typedef struct {
  /* 0x0  */ u8   square_type;  // 1 (silver) or 2 (gold)
  /* 0x1  */ u8   unk1;         // count ?
  /* 0x2  */ u8   pad2[0xE];
  /* 0x10 */ u8   alpha;
  /* 0x11 */ u8   pad11[0x1];
} UnkStruct_11; // 0x12 bytes

typedef struct {
  /* 0x0 */ u8             unk0;
  /* 0x1 */ u8             unk1;
  /* 0x2 */ u8             unk2;
  /* 0x3 */ u8             unk3;       // square count
  /* 0x4 */ UnkStruct_11   unk4[44];
} UnkStruct_12; // 0x31C bytes

extern UnkStruct_12 *D_8011FBA0;

extern UnkStruct_11  *Multisquare_8006a050_extralarge_manyloops_interesting(s32, s32, u8);
extern void           Multisquare_8006a3ec_twoliner(UnkStruct_11 *);
extern void           Multisquare_8006a410_fourliner(UnkStruct_11 *, u8 *);
extern Color         *Multisquare_pGetColor(UnkStruct_11 *);
extern s32            Multisquares_Test4x4byType(s32, s32, u8);
extern s32            Multisquare_8006a6bc_oneliner_calls_fun(void *);
extern void           Multisquare_8006a6f0_threeliner_sets_arg0_stuff(UnkStruct_12 *);
extern void           Multisquare_8006a708_fiveliner_sets_arg0_stuff(UnkStruct_12 *);

#endif /* !_MULTISQUARE_H_ */
