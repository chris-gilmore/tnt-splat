#ifndef _PLAYERVARS_H_
#define _PLAYERVARS_H_

typedef struct {
  /* 0x0  */ s16               cont_no;
  /* 0x4  */ ControllerQueue   contQ;
  /* 0x1C */ Controller       *unk1C;
  /* 0x20 */ u32               unk20;      // buttons
  /* 0x24 */ u32               unk24;      // buttons
  /* 0x28 */ UnkStruct_1       unk28;
} PlayerVars; // 0xB8 bytes

extern PlayerVars g_PV_arr[];
extern PlayerVars *g_PV_ptr;

extern void   FUN_80053500_fiveliner(void);
extern void   FUN_80053538_fiveliner(void);
extern void   PV_set_controller_no(s16);
extern void   FUN_800535B8_fiveliner(PlayerVars *PV_ptr);

#endif /* !_PLAYERVARS_H_ */
