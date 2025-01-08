#ifndef _LINESCAN_H_
#define _LINESCAN_H_

typedef struct {
  /* 0x0 */ u8   unk0;
  /* 0x1 */ u8   unk1;
} UnkStruct_5; // 0x2 bytes

typedef struct {
  /* 0x0   */ u8           unk0;
  /* 0x1   */ u8           unk1;
  /* 0x2   */ u8           unk2;
  /* 0x3   */ UnkStruct_5  unk3[20];
  /* 0x2C  */ LineEffect   unk2C[20];
  /* 0x3EC */ s32          unk3EC;
  /* 0x3F0 */ s32          unk3F0;
  /* 0x3F4 */ u8           unk3F4;  // lowest scanable line
} LineScan; // 0x3F8 bytes

extern LineScan *g_lineScan_ptr;

extern void   LineScan_80069e84_sevenliner_loops_20_times(void);
extern void   LineScan_80069ec0_sevenliner_loops_4_times(void);
extern void   LineScan_80069f10_threeliner_lowestscanableline(u8);
extern void   LineScan_Init(void);
extern void   LineScan_80069fb8_elevenliner_case_and_loop_interesting(void);

#endif /* !_LINESCAN_H_ */
