#include "common.h"

extern u8 D_5B9AB0;  // dcm_lut

static s32 D_80120A40[12];  // unused
SongPlayer D_80120A70;

static void Audio_80085408_oneliner_calls_allocdcm(SongPlayer *);
static void Audio_ALManager(ALSynConfig *, s32, UnkStruct_93 *);
static void Audio_PreNmiAudio(void *);
static s32 Audio_80085924_fortyliner_sets_arg0_struct(UnkStruct_100 *, UnkStruct_100 *);
static void Audio_80085b9c_threeliner(UnkStruct_100 *);
static s32 Audio_80085bec_tenliner(s32, s32, void *);
static ALDMAproc func_80085CF4(void *);
static void Audio_Wrap(void);

void Audio_InitAudio(void) {
  ALSynConfig sp5C;
  UnkStruct_93 sp50;
  s32 sp4C;  // unused
  u8 *sp48;

  D_80128DD8 = 0x4000;  // volume (set in the middle -- half of max)
  rmonPrintf("%x %x : %x\n", D_80126778, audioheap_BASE, 0x40000);
  alHeapInit(&D_80126778, audioheap_BASE, 0x40000);
  rmonPrintf("Audio Start: %x\n", audioheap_BASE);
  D_80126798 = audioheap_BASE;

  sp5C.maxVVoices = 0;
  sp5C.maxPVoices = 48;
  sp5C.maxUpdates = 96;
  sp5C.dmaproc = NULL;
  sp5C.fxType = AL_FX_SMALLROOM;
  sp5C.outputRate = 0;
  sp5C.heap = &D_80126778;

  sp50.freq = 36000;
  sp50.unk4 = 1;
  sp50.max_clist_size = 0x1400;

  Audio_ALManager(&sp5C, 12, &sp50);
  rmonPrintf("Audio M Size: %x\n", audioheap_BASE - D_80126798);
  D_80126788 = alHeapAlloc(&D_80126778, 1, 0x10);
  D_8012678C = D_80126788;
  D_80120A70.unk1590 = D_80126788;
  Dcm_Init(&D_80120A70, &D_80123A18, D_80124678, 16, D_80128DD8, TRUE);
  Dcm_Init(&D_80122010, &D_80125858, D_801264B8, 16, 0x7FFF, FALSE);
  D_80120A70.unk1590 = n64HeapAlloc(0xBCF20);
  D_80126790 = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_5B9AB0, SONG_TITLE));
  rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "initAudio", FUN_03A750_80074888_twelveliner(&D_5B9AB0, SONG_TITLE), FUN_03A750_80074888_twelveliner(&D_5B9AB0, SONG_TITLE), D_80126790, n64HeapGetTotalMemFree());
  FUN_03A750_800746c0_twentyliner(&D_5B9AB0, D_80126790, SONG_TITLE);

  D_80126788 = Audio2_80086138_largeliner_channels(&D_80120A70, D_80126790, D_80126794, 1);
  D_80120A70.unk1580 = SONG_TITLE;
  D_80120A70.unk1582 = SONG_TITLE;
  D_80120A70.unk1584 = FALSE;
  D_80128DDC = 5;
  main_8004A34C_threeliner();
  while (!D_80120A70.unk1584) {
    Audio_80085408_oneliner_calls_allocdcm(&D_80120A70);
  }
  rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "initAudio", D_80126790, n64HeapGetTotalMemFree());
  n64HeapUnalloc(D_80126790);

  D_80126788 = g_menuSfxBank.unk8;
  sp48 = g_menuSfxBank.unk8;
  Audio2_80088c84_largeliner(&D_801235B0, 0, 16);
  gp_sfxBank = NULL;
  Audio_LoadSFX(&g_introSfxBank);
  rmonPrintf("SFX Size = %d $%x At: %x\n", D_80126788 - sp48, D_80126788 - sp48, sp48);
  osWritebackDCacheAll();
}

// unused
void Audio_ChangeSong(s32 song, SongPlayer *arg1) {
  u8 *sp3C;

  D_80128DC0.unk0 = 0;
  rmonPrintf("ChangeSong Loading: %d Base: %d\n", song, D_80128DDC);
  sp3C = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_5B9AB0, song));
  rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "ChangeSongLoad", FUN_03A750_80074888_twelveliner(&D_5B9AB0, song), FUN_03A750_80074888_twelveliner(&D_5B9AB0, song), sp3C, n64HeapGetTotalMemFree());
  FUN_03A750_800746c0_twentyliner(&D_5B9AB0, sp3C, song);
  Audio2_AllocDcmHeader(&D_80120A70, sp3C);
  rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "ChangeSongLoad", sp3C, n64HeapGetTotalMemFree());
  n64HeapUnalloc(sp3C);
  if (arg1->unk444 != NULL) {
    rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "ChangeSongLoad", arg1->unk444, n64HeapGetTotalMemFree());
    n64HeapUnalloc(arg1->unk444);
    arg1->unk444 = NULL;
  }
  arg1->unk444 = arg1->unk44C;
  arg1->unk1580 = song;
  arg1->unk1582 = song;
  arg1->unk1584 = TRUE;
  Audio2_8008777c_oneliner_turn_off(arg1);
  Audio2_GFXDone_SendPlayMessage(arg1);
}

// unused
void func_80084C90(s32 arg0, SongPlayer *arg1) {
  arg1->unk1582 = arg0;
}

// unused
void Audio_FreeAudio(SongPlayer *arg0) {
  s32 i;

  Audio2_8008780c_sixliner_v1(arg0);
  main_8004A34C_threeliner();
  if (arg0->unk444 != NULL) {
    rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "FreeAudio Rleasing Strem", arg0->unk444, n64HeapGetTotalMemFree());
    n64HeapUnalloc(arg0->unk444);
    arg0->unk444 = NULL;
  }
  for (i = 0; i < arg0->unk418.num_samples; i++) {
    if (arg0->unk438->wt[i].base != NULL) {
      rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "FreeAudio Rleasing Sample", arg0->unk438->wt[i].base, n64HeapGetTotalMemFree());
      n64HeapUnalloc(arg0->unk438->wt[i].base);
      arg0->unk438->wt[i].base = NULL;
    }
  }
}

// change song
void Audio_80084e20_twentyliner(s32 song, SongPlayer *arg1, u8 arg2) {
  s32 unused;
  u8 *sp18;

  if (D_800CFEE8 != 12) {
    Audio2_8008780c_sixliner_v1(arg1);
    if (arg2 != 2) {
      g_sram_ptr->song = song;
    }
    arg1->unk1580 = song;
    arg1->unk1582 = song;
    main_8004A34C_threeliner();
    arg1->unk1598 = 0;
    main_8004A34C_threeliner();
    sp18 = (u8 *) cfb[draw_buffer];
    FUN_03A750_800746c0_twentyliner(&D_5B9AB0, sp18, song);
    D_80126788 = Audio2_80086138_largeliner_channels(arg1, sp18, NULL, 2);
    arg1->unk157E = 0;
    arg1->unk1584 = FALSE;
    while (!arg1->unk1584) {
      Audio_80085408_oneliner_calls_allocdcm(arg1);
    }
    Audio2_8008777c_oneliner_turn_off(arg1);
  }
}

void Audio_UnloadSFX(void) {
  if ((gp_sfxBank != NULL) && (gp_sfxBank->unk8 != NULL)) {
    Audio2_80089d5c_twentyfourliner_sendstop(&D_801235B0);
    Audio2_GFXDone_SendStopMessage(&D_801235B0);
    rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "UNLoadSFX Rel SFX", gp_sfxBank->unk8, n64HeapGetTotalMemFree());
    n64HeapUnalloc(gp_sfxBank->unk8);
    gp_sfxBank->unk8 = NULL;
  }
  gp_sfxBank = NULL;
}

void Audio_LoadSFX(SfxBank *bank) {
  s32 i;
  u32 dcm_id;
  s32 unused[2];
  void *sp3C;

  if (gp_sfxBank == bank) {
    rmonPrintf("SFX Bank Not Loaded\n");
    return;
  }
  Audio2_80089d5c_twentyfourliner_sendstop(&D_801235B0);
  Audio2_GFXDone_SendStopMessage(&D_801235B0);
  if ((gp_sfxBank != NULL) && (gp_sfxBank->unk8 != NULL)) {
    rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "LoadSFX Rel SFX", gp_sfxBank->unk8, n64HeapGetTotalMemFree());
    n64HeapUnalloc(gp_sfxBank->unk8);
    gp_sfxBank->unk8 = NULL;
  }
  gp_sfxBank = NULL;
  D_800D3B50 = bank->unkC;
  dcm_id = bank->dcm_id;
  Audio2_80088c84_largeliner(&D_801235B0, 1, 16);
  rmonPrintf("SFX Size: %x Bank: %x SongLoaded: %x\n", bank->size, bank, D_80120A70.unk1580);
  if (n64HeapGetMaxFreeBlockSize() < bank->size) {
    rmonPrintf("Not Enuff Mem.. SFX NOT LOADED\n");
    debug_print_reason_routine("NOT ENUFF MEM FOR SFX", "audio.c");
    return;
  }
  bank->unk8 = n64HeapAlloc(bank->size);
  rmonPrintf("loading Bank: %x At: %x\n", bank, bank->unk8);
  D_80126788 = bank->unk8;
  rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "LoadSFX For SFX", bank->size, bank->size, bank->unk8, n64HeapGetTotalMemFree());
  D_801235B0.unk350 = (UnkStruct_79 **) D_80126788;
  D_80126788 += bank->unk4 * sizeof(UnkStruct_79);  // (bug?) should this have been sizeof(UnkStruct_79 *) instead?

  for (i = 0; i < bank->unk4; i++) {
    sp3C = n64HeapAlloc(FUN_03A750_80074888_twelveliner(&D_5B9AB0, dcm_id));
    rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "LoadSFX", FUN_03A750_80074888_twelveliner(&D_5B9AB0, dcm_id), FUN_03A750_80074888_twelveliner(&D_5B9AB0, dcm_id), sp3C, n64HeapGetTotalMemFree());
    FUN_03A750_800746c0_twentyliner(&D_5B9AB0, sp3C, dcm_id);
    dcm_id++;
    D_80126788 = Audio2_80089030_hugeliner_SFX_Channel(&D_801235B0, sp3C, D_80126788, 3);
    rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "LoadSFX", sp3C, n64HeapGetTotalMemFree());
    n64HeapUnalloc(sp3C);
  }

  rmonPrintf("SFX Audio Heap Ends At: %x Size: %x\n", D_80126788, D_80126788 - bank->unk8);
  if ((uintptr_t)D_80126788 > 0x8038AD00) {
    debug_print_reason_routine("Audio overwriting CFB", "tell dave");
  }
  gp_sfxBank = bank;
  Audio2_80088ba4_fiveliner(&D_801235B0);
  osWritebackDCacheAll();
  rmonPrintf("SFX LOAD END\n");
}

static void Audio_80085408_oneliner_calls_allocdcm(SongPlayer *arg0) {
  s32 unused = 0;

  Audio2_AllocDcmScratch8(arg0);
}

static void Audio_ALManager(ALSynConfig *arg0, s32 arg1, UnkStruct_93 *arg2) {
  u32 i;
  f32 sp28;
  u8 sp27 = FALSE;  // unused

  D_801267A0 = osScGetCmdQ(&scheduler);
  arg0->dmaproc = &func_80085CF4;
  arg0->outputRate = osAiSetFrequency(arg2->freq);

  sp28 = (f32) arg2->unk4 * arg0->outputRate / 60;
  D_80128A58 = (s32) sp28;
  if (D_80128A58 < sp28) {
    D_80128A58++;
  }
  if (D_80128A58 & 0xF) {
    D_80128A58 = (D_80128A58 & ~0xF) + 0x10;
  }
  D_80128A54 = D_80128A58 - 0x10;
  D_80128A5C = D_80128A58 + 0x60;
  alInit(&D_801267A8.alGlobals, arg0);

  for (i = 0; i < 2; i++) {
    D_801267A8.cmdList[i] = alHeapAlloc(arg0->heap, 1, arg2->max_clist_size * sizeof(Acmd));
  }

  D_80128A60 = arg2->max_clist_size;

  for (i = 0; i < 3; i++) {
    D_801267A8.unk8[i] = alHeapAlloc(arg0->heap, 1, sizeof(UnkStruct_100));
    D_801267A8.unk8[i]->unk70 = 2;
    D_801267A8.unk8[i]->unk74 = D_801267A8.unk8[i];
    D_801267A8.unk8[i]->audioBuffer = alHeapAlloc(arg0->heap, 1, D_80128A5C * sizeof(s32));
  }

  D_80128A9C = (uintptr_t)alHeapAlloc(arg0->heap, 1, 0xFFFF);
  D_80128AA0 = D_80128A9C;
  rmonPrintf("ALManager End: %x\n", D_80128A9C + 0x1FFFE);
  osCreateMesgQueue(&D_801267A8.unk200, D_801267A8.unk218, 8);
  osCreateMesgQueue(&D_801267A8.unk1C8, D_801267A8.unk1E0, 8);
  osCreateMesgQueue(&D_80128A80, D_80128A98, 1);
  osCreateThread(&D_801267A8.unk18, 3, Audio_PreNmiAudio, NULL, D_80126A30 + 0x2000/sizeof(u64), arg1);
  osStartThread(&D_801267A8.unk18);
}

static void Audio_PreNmiAudio(void *arg0) {
  s32 sp34 = 0;
  s32 sp30 = 0;
  UnkStruct_102 *sp2C = NULL;
  OSScClient sp24;

  osScAddClient(&scheduler, &sp24, &D_801267A8.unk1C8);
  while (sp30 == 0) {
    osRecvMesg(&D_801267A8.unk1C8, (OSMesg *)&sp2C, OS_MESG_BLOCK);
    switch (sp2C->unk0) {
    case 1:
      sp34 = Audio_80085924_fortyliner_sets_arg0_struct(D_801267A8.unk8[D_800D3910 % 3], D_800D391C);
      if (sp34 != 0) {
        osRecvMesg(&D_801267A8.unk200, (OSMesg *)&sp2C, OS_MESG_BLOCK);
        Audio_80085b9c_threeliner(sp2C->unk4);
        D_800D391C = sp2C->unk4;
      }
      break;
    case 4:
      rmonPrintf("PRE NMI AUDIO************************************************************\n");
      func_80061198();
      break;
    case 10:
      sp30 = 1;
      break;
    }
  }
  alClose(&D_801267A8.alGlobals);
}

static s32 Audio_80085924_fortyliner_sets_arg0_struct(UnkStruct_100 *arg0, UnkStruct_100 *arg1) {
  s16 *audioOp;
  Acmd *cmdlp;
  s32 clcount;
  u32 sp20;
  UnkStruct_103 *sp1C;

  sp20 = 0;
  Audio_Wrap();
  audioOp = (s16 *) osVirtualToPhysical(arg0->audioBuffer);
  if (arg1 != NULL) {
    osAiSetNextBuffer(arg1->audioBuffer, arg1->audioSamples << 2);
  }
  sp20 = osAiGetLength() >> 2;
  arg0->audioSamples = ((D_80128A58 - sp20) + 0x60) & ~0xF;
  if (arg0->audioSamples < D_80128A54) {
    arg0->audioSamples = D_80128A54;
  }
  clcount = 0;
  cmdlp = alAudioFrame(D_801267A8.cmdList[D_800D3918], &clcount, audioOp, arg0->audioSamples);
  if (clcount == 0) {
    return 0;
  }
  if (clcount == 0) {
    return 0;
  }
  sp1C = &arg0->unk8;
  sp1C->unk0 = 0;
  sp1C->unk50 = &D_801267A8.unk200;
  sp1C->unk54 = &arg0->unk70;
  sp1C->unk8 = 2;
  sp1C->tlist.t.data_ptr = (u64 *) D_801267A8.cmdList[D_800D3918];
  sp1C->tlist.t.data_size = (cmdlp - D_801267A8.cmdList[D_800D3918]) * sizeof(Acmd);
  sp1C->tlist.t.type = M_AUDTASK;
  sp1C->tlist.t.ucode_boot = (u64 *) rspbootTextStart;
  sp1C->tlist.t.ucode_boot_size = (intptr_t)gspF3DEX2_NoN_fifoTextStart - (intptr_t)rspbootTextStart;
  sp1C->tlist.t.flags = 0;
  sp1C->tlist.t.ucode = (u64 *) aspMainTextStart;
  sp1C->tlist.t.ucode_data = (u64 *) aspMainDataStart;
  sp1C->tlist.t.ucode_data_size = 0x800;
  sp1C->tlist.t.dram_stack = NULL;
  sp1C->tlist.t.output_buff = NULL;
  sp1C->tlist.t.output_buff_size = 0;
  sp1C->tlist.t.yield_data_ptr = NULL;
  sp1C->tlist.t.yield_data_size = 0;
  osSendMesg(D_801267A0, sp1C, OS_MESG_BLOCK);
  D_800D3918 ^= 1;
  return 1;
}

static void Audio_80085b9c_threeliner(UnkStruct_100 *arg0) {
  u32 sp1C;

  sp1C = osAiGetLength() >> 2;
  if ((sp1C == 0) && (D_800D3920 == 0)) {
    D_800D3920 = 0;  // if it gets here, then it was already 0
  }
}

static s32 Audio_80085bec_tenliner(s32 addr, s32 len, void *state) {
  if ((addr <= 0x80000000) || (addr >= 0x80400000)) {
    return addr;
  }
  D_80128AA4 = (void *)D_80128A9C;
  len = (len + 0xF) & ~0xF;
  if (len > 0xFFFF) {
    return D_80128A9C;
  }
  if ((D_80128A9C + 0x1FFFE) < ((len * 2) + D_80128A9C)) {
    return D_80128A9C;
  }
  D_80128A9C = (uintptr_t)func_800A2F00((s8 *)addr, (s16 *)D_80128A9C, len);
  D_80128A9C = (D_80128A9C + 0xF) & ~0xF;
  return osVirtualToPhysical(D_80128AA4);
}

static ALDMAproc func_80085CF4(void *state) {
  state = NULL;
  return Audio_80085bec_tenliner;
}

static void Audio_Wrap(void) {
  D_800D3910++;
  if (D_800D3910 == 0) {
    rmonPrintf("audio wrap\n");
  }
  D_80128A9C = D_80128AA0;
}
