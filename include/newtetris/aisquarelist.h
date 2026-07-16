#ifndef _AISQUARELIST_H_
#define _AISQUARELIST_H_

typedef struct {
  /* 0x0 */ u8   unk0;  // x
  /* 0x1 */ u8   unk1;  // y
  /* 0x2 */ u8   unk2;  // boolean
} UnkStruct_106; // 0x3 bytes

typedef struct {
  /* 0x0 */ u8              unk0;
  /* 0x1 */ s8              unk1[6];
  /* 0x7 */ UnkStruct_106   unk7[6];
} UnkStruct_107; // 0x19 bytes

extern void   aisquarelist_8003e1e0_sevenliner_loops_6t(UnkStruct_107 *);
extern void   aisquarelist_8003e22c_tenliner_loops_6t(UnkStruct_107 *, u8, u8);
extern void   aisquarelist_8003e2c8_sevenliner(UnkStruct_107 *, u8);
extern u8     aisquarelist_8003e458_thirteenliner_loops_7t(UnkStruct_107 *, u8 *, u8 *);
extern u8     aisquarelist_8003e55c_eightliner_loops_arg0_t_1(UnkStruct_107 *);
extern void   aisquarelist_8003e608_eightliner_loops_arg0_t_2(UnkStruct_107 *, u8);
extern u8     aisquarelist_8003ed40_largeliner_many_loops(UnkStruct_107 *, u8, u8 *, u8, u8);

#endif /* !_AISQUARELIST_H_ */
