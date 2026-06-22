#include "common.h"
#include "synthInternals.h"

extern u8 D_7C1960;  // sample_lut

SongPlayer D_80122010;
SfxPlayer D_801235B0;
UnkStruct_96 D_80123A18;
Channel D_80124678[16];
UnkStruct_96 D_80124938;
Channel D_80125598[16];
UnkStruct_96 D_80125858;
Channel D_801264B8[16];
ALHeap D_80126778;
u8 *D_80126788;
u8 *D_8012678C;
void *D_80126790;
void *D_80126794;
u8 *D_80126798;
s32 D_8012679C;  // unused
OSMesgQueue *D_801267A0;
UnkStruct_101 D_801267A8;
u64 D_80126A30[0x2000/sizeof(u64)];
s32 D_80128A30[9];  // unused
u32 D_80128A54;
u32 D_80128A58;
u32 D_80128A5C;
u32 D_80128A60;  // max_clist_size
OSMesgQueue D_80128A68;  // unused
OSMesgQueue D_80128A80;
OSMesg D_80128A98[1];
uintptr_t D_80128A9C;
uintptr_t D_80128AA0;
void *D_80128AA4;
s32 D_80128AA8;  // unused
static UnkStruct_95 D_80128AB0;
SfxBank *gp_sfxBank;
static u16 D_80128AD8[256];
static u16 D_80128CD8;
OSMesgQueue D_80128CE0;
OSMesg D_80128CF8[8];
OSMesgQueue D_80128D18;
OSMesg D_80128D30[8];
OSMesgQueue D_80128D50;
OSMesg D_80128D68[8];  // unused
OSMesgQueue D_80128D88;
OSMesg D_80128DA0[8];  // unused
UnkStruct_102 D_80128DC0;
UnkStruct_102 D_80128DC8;
UnkStruct_102 D_80128DD0;  // unused
u16 D_80128DD8;
s32 D_80128DDC;
static u8 D_80128DE0[8];
static UnkStruct_97 D_80128DE8[16];

u32 D_800D3910 = 0;
static s32 D_800D3914 = 0;  // unused
s32 D_800D3918 = 0;
UnkStruct_100 *D_800D391C = NULL;
s32 D_800D3920 = 1;
static s32 D_800D3924 = 0;  // unused
static s32 D_800D3928 = 0;  // unused
static s32 D_800D392C = 0;  // unused
static u8 D_800D3930 = 1;  // unused
static u8 D_800D3934 = 1;  // unused
static s32 D_800D3938 = 0;  // unused
static s32 D_800D393C = 20000;  // unused
static s32 D_800D3940 = 20000;  // microtime (50 hz)
static UnkStruct_104 D_800D3944[6] = {
  { 2, 1, 12, { 0, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 13, { 1, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 14, { 2, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 15, { 3, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 16, { 4, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 17, { 5, 0, 0, 0, 0, 0, 0, 0 } },
};
SfxBank g_menuSfxBank = { D_800D3944, 6, 0x200, NULL, 0x100, 0x6800 };
static UnkStruct_104 D_800D399C[22] = {
  { 2, 1, 2, { 0, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 4, { 1, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 2, 30, { 3, 2, 0, 0, 0, 0, 0, 0 } },
  { 2, 3, 20, { 4, 5, 6, 0, 0, 0, 0, 0 } },
  { 2, 1, 20, { 7, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 9, { 8, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 8, { 9, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 7, { 10, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 11, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 12, { 12, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 12, { 13, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 12, { 14, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 12, { 15, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 4, { 16, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 7, { 17, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 18, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 19, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 20, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 21, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 25, { 22, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 4, 25, { 23, 24, 25, 26, 0, 0, 0, 0 } },
  { 2, 4, 25, { 27, 28, 29, 30, 0, 0, 0, 0 } },
};
SfxBank g_gameSfxBank = { D_800D399C, 31, 0x100, NULL, 0x100, 0x24100 };
static UnkStruct_104 D_800D3AA4[12] = {
  { 2, 3, 30, { 0, 1, 2, 0, 0, 0, 0, 0 } },
  { 2, 2, 29, { 3, 4, 0, 0, 0, 0, 0, 0 } },
  { 2, 2, 28, { 5, 6, 0, 0, 0, 0, 0, 0 } },
  { 2, 2, 27, { 7, 8, 0, 0, 0, 0, 0, 0 } },
  { 2, 2, 26, { 9, 10, 0, 0, 0, 0, 0, 0 } },
  { 2, 4, 25, { 11, 12, 13, 14, 0, 0, 0, 0 } },
  { 2, 3, 24, { 15, 16, 17, 0, 0, 0, 0, 0 } },
  { 2, 2, 23, { 18, 19, 0, 0, 0, 0, 0, 0 } },
  { 2, 1, 22, { 20, 0, 0, 0, 0, 0, 0, 0 } },
  { 2, 3, 21, { 21, 22, 23, 0, 0, 0, 0, 0 } },
  { 2, 2, 20, { 24, 25, 0, 0, 0, 0, 0, 0 } },
  { 2, 2, 19, { 26, 27, 0, 0, 0, 0, 0, 0 } },
};
SfxBank g_introSfxBank = { D_800D3AA4, 28, 0x400, NULL, 0x100, 0x2B000 };
static s32 D_800D3B3C = 0;
static s32 D_800D3B40[4] = { 0, 0x4000, 0xC000, 0x1C000 };
u16 D_800D3B50 = 0;

static void Audio2_80087478_oneliner_calls_fun(void *, u16);
static void Audio2_800874ac_sevenliner(SongPlayer *);
static void Audio2_8008756c_eightliner(SongPlayer *);
static ALMicroTime Dcm_VoiceHandler(void *);
static u8 Audio2_80089edc_thirtyfourliner_loops(SfxPlayer *, u8);
static UnkStruct_95 *Audio2_Play_SFX_Bank_Channel(SfxPlayer *, SfxBank *, u8, u8);
static void Audio2_8008a61c_twelveliner(void);
static void Audio2_8008a7c0_fiveliner(void);
static ALMicroTime Dcm_VoiceHandler_2(void *);
static f32 Dcm_SetPitch_2(s16);
static f32 Dcm_SetPitch(u16);
static void Audio2_8008bf58_eightliner(u8 *, DcmHeader *);
static void Audio2_8008c014_tenliner(u8 *, Sample *);
static s16 Audio2_8008c0e0_oneliner_arg0_math(u8 *);
static s32 Audio2_8008c104_oneliner_arg0_math_2(u8 *);
static s32 Audio2_8008c130_oneliner_arg0_math_3(u8 *);

void Dcm_Init(SongPlayer *arg0, UnkStruct_96 *arg1, Channel *channels, u8 arg3, s16 arg4, u8 arg5) {
  s32 i;
  ALVoiceConfig vc;

  arg0->unk454 = 0;
  arg0->alGlobals = alGlobals;
  arg0->unk1578 = 20000;
  arg0->unk1570 = FALSE;
  arg0->unk1571 = 1;
  arg0->unk1587 = FALSE;
  arg0->unk158C = FALSE;
  arg0->unk1584 = FALSE;
  arg0->unk1572 = 0;
  arg0->unk157E = 0;
  arg0->unk1580 = 0;
  arg0->unk1585 = 0;
  arg0->unk1582 = 0;
  arg0->unk1586 = 0;
  arg0->unk157C = arg4;  // music_level (volume)
  arg0->unk158A = 0x7FFF;  // max volume
  arg0->unk1588 = 0;
  arg0->unk1598 = 0;
  arg0->unk1599 = FALSE;
  arg0->unk438 = arg1;
  arg0->channels = channels;
  arg0->unk158E = arg5;

  arg0->node.next = NULL;
  arg0->node.handler = Dcm_VoiceHandler;
  arg0->node.clientData = arg0;
  arg0->node.callTime = 0;

  alSynAddPlayer(&alGlobals->drvr, &arg0->node);

  vc.priority = 10;
  vc.fxBus = 0;
  vc.unityPitch = 0;

  for (i = 0; i < 66; i++) {
    arg0->unk438->wt[i].base = NULL;
  }

  if (arg3 != 0) {
    for (i = 0; i < arg3; i++) {
      alSynAllocVoice(&arg0->alGlobals->drvr, &arg0->channels[i].v, &vc);
    }
  }

  rmonPrintf("voices Init\n");
}

void Audio2_AllocDcmHeader(SongPlayer *arg0, u8 *arg1) {
  s8 *sp34;
  u8 *sp30;
  s32 sp2C;

  Audio2_8008bf58_eightliner(arg1, &arg0->unk418);
  arg1 += 14;
  arg0->unk440 = arg0->unk418.num_channels;
  arg0->unk44C = n64HeapAlloc(arg0->unk418.stream_sz);
  rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "allocDcmHeader", arg0->unk418.stream_sz, arg0->unk418.stream_sz, arg0->unk44C, n64HeapGetTotalMemFree());
  arg0->unk448 = arg0->unk44C;
  sp34 = (s8 *) (arg1 + (arg0->unk418.num_samples * 16));
  arg0->unk450 = (u8)sp34[3] + ((u8)sp34[2] << 8) + ((u8)sp34[1] << 16) + ((u8)sp34[0] << 24);
  sp34 += 4;
  sp30 = arg0->unk44C;
  sp2C = arg0->unk418.stream_sz;
  rmonPrintf("Stream Size: $%x %d bytes at: %x\n", sp2C, sp2C, sp30);
  while (sp2C--) {
    *sp30++ = *sp34++;
  }
  func_8008EFA0(arg0->unk44C, &arg0->unk458);
  Audio2_8008756c_eightliner(arg0);
}

void *Audio2_80086138_largeliner_channels(SongPlayer *arg0, u8 *arg1, void *arg2, u8 arg3) {
  s32 i;
  s8 *sp38;
  u8 *sp34;
  Channel *channel;
  ALVoiceConfig vc;  // unused

  D_800D3B3C = 0;

  vc.priority = 10;
  vc.fxBus = 0;
  vc.unityPitch = 0;

  if (arg3 == 2) {
    for (i = 0; i < 16; i++) {
      channel = &arg0->channels[i];
      if (channel->state != 0) {
        channel->state = 0;
        alSynStopVoice(&arg0->alGlobals->drvr, &channel->v);
      }
    }
  }

  if (arg3 == 1) {
    osCreateMesgQueue(&D_80128CE0, D_80128CF8, 8);
    osCreateMesgQueue(&D_80128D18, D_80128D30, 8);
    osCreateMesgQueue(&D_80128D50, D_80128CF8, 8);
    osCreateMesgQueue(&D_80128D88, D_80128D30, 8);
  }

  Audio2_8008bf58_eightliner(arg1, &arg0->unk418);
  arg1 += 14;
  arg0->unk440 = arg0->unk418.num_channels;
  rmonPrintf("Number of Channels: %x \n", arg0->unk418.num_channels);
  arg0->unk1574 = arg0->heap;
  arg0->unk444 = arg0->unk1574;
  arg0->unk448 = arg0->unk444;
  arg0->unk1574 += (arg0->unk418.stream_sz + 0xF) & ~0xF;
  D_800D3B3C += (arg0->unk418.stream_sz + 0xF) & ~0xF;
  arg0->unk418.stream_sz -= 4;
  sp38 = (s8 *) (arg1 + (arg0->unk418.num_samples * 16));
  arg0->unk450 = (u8)sp38[3] + ((u8)sp38[2] << 8) + ((u8)sp38[1] << 16) + ((u8)sp38[0] << 24);
  sp38 += 4;
  sp34 = arg0->unk444;
  i = arg0->unk418.stream_sz;
  rmonPrintf("Stream Size: $%x %d bytes at: %x\n", i, i, sp34);
  while (i--) {
    *sp34++ = *sp38++;
  }
  func_8008EFA0(arg0->unk444, &arg0->unk458);
  Audio2_8008756c_eightliner(arg0);
  for (i = 0; i < arg0->unk418.num_samples; i++) {
    Audio2_8008c014_tenliner(arg1, &arg0->unk18[i]);
    arg1 += 16;
  }
  arg0->unk1572 = 0;
  arg0->unk1570 = TRUE;
  arg0->unk1571 = 1;

  return arg2;
}

void Audio2_AllocDcmScratch8(SongPlayer *arg0) {
  s32 sp54;
  s32 sp50;
  s8 *sp4C;
  s8 *sp48;
  s32 sp44;
  s16 *sp40;
  s16 *sp3C;
  u32 sp38;
  void *sp34;
  void *sp30;
  u8 sp2F;
  u8 sp2E;
  u8 sp2D;
  u8 sp2C;

  if (arg0->unk1570) {
    if (arg0->unk1571 != 1) {
      arg0->unk1571--;
      return;
    }

    arg0->unk1571 = 1;
    sp44 = LZO_BUF;
    sp54 = arg0->unk1572;

    if (arg0->unk18[sp54].flags & 1) {  // 16-bit
      sp34 = n64HeapAlloc((arg0->unk18[sp54].smplen * 2) + 16*2);
      rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "AllocDcm Scratch16", (arg0->unk18[sp54].smplen * 2) + 16*2, (arg0->unk18[sp54].smplen * 2) + 16*2, sp34, n64HeapGetTotalMemFree());
      Audio2_80087478_oneliner_calls_fun(sp34, arg0->unk18[sp54].id);
      arg0->unk438->wt[sp54].base = arg0->unk1574;
      arg0->unk438->wt_base[sp54] = arg0->unk438->wt[sp54].base;

      if (arg0->unk18[sp54].flags & 4) {  // loop
        arg0->unk1574 += ((arg0->unk18[sp54].smplen * 2) + 16*2 + 0xF) & ~0xF;
        D_800D3B3C += ((arg0->unk18[sp54].smplen * 2) + 16*2 + 0xF) & ~0xF;
      } else {  // no loop
        arg0->unk1574 += (arg0->unk18[sp54].smplen + 16*2 + 0xF) & ~0xF;
        D_800D3B3C += (arg0->unk18[sp54].smplen + 16*2 + 0xF) & ~0xF;
      }

      if (arg0->unk18[sp54].flags & 4) {  // loop
        arg0->unk438->wt[sp54].len = arg0->unk18[sp54].smplen * 2;
        arg0->unk438->wt_len[sp54] = arg0->unk18[sp54].smplen * 2;
        arg0->unk438->wt[sp54].type = AL_RAW16_WAVE;
        arg0->unk438->wt[sp54].flags = 0xFF;
        sp4C = sp34;
        sp3C = (s16 *) arg0->unk438->wt[sp54].base;
        sp38 = arg0->unk18[sp54].smplen;

        while (sp38--) {
          *sp3C++ = ((sp4C[1] << 8) & 0xFF00) + (sp4C[0] & 0xFF);
          sp4C += 2;
        }

        if (arg0->unk18[sp54].flags & 4) {  // loop
          sp3C = (s16 *) arg0->unk438->wt[sp54].base;
          sp40 = (s16 *) arg0->unk438->wt[sp54].base;

          if (arg0->unk18[sp54].flags & 8) {  // bidi-loop
            for (sp50 = 0; sp50 < 16; sp50++) {
              sp3C[arg0->unk18[sp54].loopEnd + sp50] = sp40[(arg0->unk18[sp54].loopBegin - 1) - sp50];
            }
          } else {  // no bidi-loop
            for (sp50 = 0; sp50 < 16; sp50++) {
              sp3C[arg0->unk18[sp54].loopEnd + sp50] = sp40[arg0->unk18[sp54].loopBegin + sp50];
            }
          }
        }
      } else {  // no loop
        arg0->unk438->wt[sp54].len = arg0->unk18[sp54].smplen;
        arg0->unk438->wt_len[sp54] = arg0->unk18[sp54].smplen;
        arg0->unk438->wt[sp54].type = H2O_RAW8_WAVE;
        arg0->unk438->wt[sp54].flags = 0xFF;
        sp4C = sp34;
        sp48 = (s8 *) arg0->unk438->wt[sp54].base;
        sp38 = arg0->unk18[sp54].smplen;

        while (sp38--) {
          *sp48++ = Audio2_8008c0e0_oneliner_arg0_math((u8 *)sp4C) >> 8;
          sp4C += 2;
        }

        sp48 = (s8 *) arg0->unk438->wt[sp54].base;
        sp2E = sp48[arg0->unk18[sp54].smplen] >> 4;

        for (sp50 = 0, sp2F = 0; sp50 < 16; sp50++) {
          sp48[sp50 + arg0->unk18[sp54].smplen] = sp48[arg0->unk18[sp54].smplen] - sp2F;
          sp2F += sp2E;
        }
      }
      rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "Allocdcm Scratch16", sp34, n64HeapGetTotalMemFree());
      n64HeapUnalloc(sp34);
    } else {  // 8-bit
      sp30 = n64HeapAlloc(arg0->unk18[sp54].smplen + 16*2);
      rmonPrintf("\x1b[1;41m%s Allocated:  %x %d bytes Handle: %x AVAIL: %d\x1b[0m\n", "AllocDcm Scratch8", arg0->unk18[sp54].smplen + 16*2, arg0->unk18[sp54].smplen + 16*2, sp30, n64HeapGetTotalMemFree());
      Audio2_80087478_oneliner_calls_fun(sp30, arg0->unk18[sp54].id);
      arg0->unk438->wt[sp54].base = arg0->unk1574;
      arg0->unk438->wt_base[sp54] = arg0->unk438->wt[sp54].base;

      if (arg0->unk18[sp54].flags & 4) {  // loop
        arg0->unk1574 += ((arg0->unk18[sp54].smplen * 2) + 16*2 + 0xF) & ~0xF;
        D_800D3B3C += ((arg0->unk18[sp54].smplen * 2) + 16*2 + 0xF) & ~0xF;
      } else {  // no loop
        arg0->unk1574 += (arg0->unk18[sp54].smplen + 16*2 + 0xF) & ~0xF;
        D_800D3B3C += (arg0->unk18[sp54].smplen + 16*2 + 0xF) & ~0xF;
      }

      if (arg0->unk18[sp54].flags & 4) {  // loop
        arg0->unk438->wt[sp54].len = arg0->unk18[sp54].smplen * 2;
        arg0->unk438->wt[sp54].type = AL_RAW16_WAVE;
        arg0->unk438->wt[sp54].flags = 0xFF;
        arg0->unk438->wt_len[sp54] = arg0->unk18[sp54].smplen * 2;
        sp4C = sp30;
        sp3C = (s16 *) arg0->unk438->wt[sp54].base;
        sp38 = arg0->unk18[sp54].smplen;

        while (sp38--) {
          *sp3C++ = *sp4C++ << 8;
        }

        sp3C = (s16 *) arg0->unk438->wt[sp54].base;
        sp40 = (s16 *) arg0->unk438->wt[sp54].base;

        if (arg0->unk18[sp54].flags & 8) {  // bidi-loop
          for (sp50 = 0; sp50 < 16; sp50++) {
            sp3C[arg0->unk18[sp54].loopEnd + sp50] = sp40[(arg0->unk18[sp54].loopBegin - 1) - sp50];
          }
        } else {  // no bidi-loop
          for (sp50 = 0; sp50 < 16; sp50++) {
            sp3C[arg0->unk18[sp54].loopEnd + sp50] = sp40[arg0->unk18[sp54].loopBegin + sp50];
          }
        }
      } else {  // no loop
        arg0->unk438->wt[sp54].len = arg0->unk18[sp54].smplen;
        arg0->unk438->wt[sp54].type = H2O_RAW8_WAVE;
        arg0->unk438->wt[sp54].flags = 0xFF;
        arg0->unk438->wt_len[sp54] = arg0->unk18[sp54].smplen;
        sp4C = sp30;
        sp48 = (s8 *) arg0->unk438->wt[sp54].base;
        sp38 = arg0->unk18[sp54].smplen;

        while (sp38--) {
          *sp48++ = *sp4C++;
        }

        sp48 = (s8 *) arg0->unk438->wt[sp54].base;
        sp2C = sp48[arg0->unk18[sp54].smplen] >> 4;

        for (sp50 = 0, sp2D = 0; sp50 < 16; sp50++) {
          sp48[sp50 + arg0->unk18[sp54].smplen] = sp48[arg0->unk18[sp54].smplen] - sp2D;
          sp2D += sp2C;
        }
      }
      rmonPrintf("\x1b[1;45m%s Released Handle: %x AVAIL: %d\x1b[0m\n", "Allocdcm Scratch8", sp30, n64HeapGetTotalMemFree());
      n64HeapUnalloc(sp30);
    }

    if (arg0->unk18[sp54].flags & 4) {  // loop
      arg0->unk438->wt[sp54].waveInfo.rawWave.loop = &arg0->unk438->rawLoop[sp54];
      arg0->unk438->rawLoop[sp54].start = arg0->unk18[sp54].loopBegin;
      arg0->unk438->rawLoop[sp54].end = arg0->unk18[sp54].loopEnd;
      arg0->unk438->loopBegin[sp54] = arg0->unk18[sp54].loopBegin;
      arg0->unk438->loopEnd[sp54] = arg0->unk18[sp54].loopEnd;
      arg0->unk438->rawLoop[sp54].count = -1;
    } else {  // no loop
      arg0->unk438->wt[sp54].waveInfo.rawWave.loop = NULL;
      arg0->unk438->rawLoop[sp54].count = 0;
    }

    arg0->unk1572++;

    if (arg0->unk1572 == arg0->unk418.num_samples) {
      arg0->unk1570 = FALSE;
      for (sp54 = 0; sp54 < 16; sp54++) {
        arg0->channels[sp54].wt = arg0->unk438->wt;
        arg0->channels[sp54].pitch = 1.0;
        arg0->channels[sp54].vol = 0;
        arg0->channels[sp54].pan = 64;
        arg0->channels[sp54].state = 0;
      }
      arg0->unk1584 = TRUE;
      rmonPrintf("**Last sample load at : %x SIZE: %x %d\n", arg0->unk1574, D_800D3B3C, D_800D3B3C);
      osWritebackDCacheAll();
    }
  }
}

static void Audio2_80087478_oneliner_calls_fun(void *arg0, u16 smp_id) {
  FUN_03A750_800746c0_twentyliner(&D_7C1960, arg0, smp_id);
}

static void Audio2_800874ac_sevenliner(SongPlayer *arg0) {
  arg0->unk1568 = arg0->unk1568 & 0xFF;
  arg0->unk156A = arg0->unk156A & 0xFF;

  while ((u8)arg0->unk156A != (u8)arg0->unk1568) {
    arg0->unk1468[(u8)arg0->unk156A] = func_8008F0D0(&arg0->unk458);
    arg0->unk156A = (arg0->unk156A + 1) & 0xFF;
  }
}

static void Audio2_8008756c_eightliner(SongPlayer *arg0) {
  s32 i;

  arg0->unk1568 = 0;
  arg0->unk156A = 0;
  arg0->unk156C = 0;
  for (i = 0; i < 0x100; i++) {
    arg0->unk1468[(u8)i] = func_8008F0D0(&arg0->unk458);
  }
}

void func_800875E4(s32 arg0) {
}

// set music_level (volume)
void func_800875EC(u16 arg0, SongPlayer *arg1) {
  arg1->unk157C = arg0;
  arg1->unk1587 = TRUE;
}

// set pan_level
// unused
void func_80087600(s8 arg0, SongPlayer *arg1) {
  arg1->unk158D = arg0;
  arg1->unk158C = TRUE;
}

// set sfx_level (volume)
void Audio2_80087618_fourteenliner_loops_256t(u16 arg0) {
  u16 i;

  if (arg0 >= 0x8000) {
    arg0 = 0x7FFF;
  }
  D_80128CD8 = arg0;
  for (i = 0; i < 256; i++) {
    D_80128AD8[i] = (sqrtf(i) * arg0) / 16;
  }
}

void Audio2_80087770_oneliner_turn_on(SongPlayer *arg0) {
  arg0->unk1599 = TRUE;
}

void Audio2_8008777c_oneliner_turn_off(SongPlayer *arg0) {
  arg0->unk1599 = FALSE;
}

void Audio2_GFXDone_SendPlayMessage(SongPlayer *arg0) {
  OSMesg sp1C;

  if (!arg0->unk1599 && (arg0->unk454 != 1)) {
    D_80128DC0.unk0 = 1;
    D_80128DC0.unk4 = arg0;
    osJamMesg(&D_80128CE0, (OSMesg)&D_80128DC0, OS_MESG_NOBLOCK);
    osRecvMesg(&D_80128D18, &sp1C, OS_MESG_BLOCK);
    rmonPrintf("GFX done send PLAY message\n");
  }
}

void Audio2_8008780c_sixliner_v1(SongPlayer *arg0) {
  s32 i;  // unused
  OSMesg sp20;
  s32 sp1C;  // unused

  Audio2_80087770_oneliner_turn_on(arg0);
  D_80128DC0.unk0 = 0;
  D_80128DC0.unk4 = arg0;
  osJamMesg(&D_80128CE0, (OSMesg)&D_80128DC0, OS_MESG_NOBLOCK);
  osRecvMesg(&D_80128D18, &sp20, OS_MESG_BLOCK);
  Audio2_8008777c_oneliner_turn_off(arg0);
}

// unused
void Audio2_8008787c_sixliner_v2(SongPlayer *arg0) {
  OSMesg sp1C;

  Audio2_8008780c_sixliner_v1(arg0);
  Audio2_8008777c_oneliner_turn_off(arg0);
  D_80128DC0.unk0 = 4;
  D_80128DC0.unk4 = arg0;
  osJamMesg(&D_80128CE0, (OSMesg)&D_80128DC0, OS_MESG_NOBLOCK);
  osRecvMesg(&D_80128D18, &sp1C, OS_MESG_BLOCK);
}

static ALMicroTime Dcm_VoiceHandler(void *arg0) {
  SongPlayer *sp5C;
  SongPlayer *sp58;
  u8 sp57;
  u8 sp56;
  Channel *channel;
  s32 sp4C;
  u32 sp48;
  s32 sp44;
  u8 sp43;
  ALParam *param;
  ALFilter *filter;
  UnkStruct_102 *sp34;

  sp5C = (SongPlayer *)arg0;
  if (osRecvMesg(&D_80128CE0, (OSMesg *)&sp34, 0) == 0) {
    sp58 = sp34->unk4;
    switch (sp34->unk0) {
    case 0:
      for (sp4C = 0; sp4C < sp58->unk440; sp4C++) {
        channel = &sp58->channels[sp4C];
        if (channel->state != 0) {
          channel->state = 0;
          alSynStopVoice(&sp58->alGlobals->drvr, &channel->v);
        }
      }
      sp58->unk454 = 3;
      osSendMesg(&D_80128D18, NULL, OS_MESG_NOBLOCK);
      sp34->unk0 = 0;
      return sp58->unk1578;
    case 1:
      sp58->unk454 = 1;
      sp34->unk0 = 0;
      osSendMesg(&D_80128D18, NULL, OS_MESG_NOBLOCK);
      break;
    case 4:
      sp58->unk1586 = 0;
      func_8008EFA0(sp58->unk444, &sp58->unk458);
      Audio2_8008756c_eightliner(sp58);
      sp34->unk0 = 0;
      osSendMesg(&D_80128D18, NULL, OS_MESG_NOBLOCK);
      return sp58->unk1578;
    default:
      sp34->unk0 = 0;
      break;
    }
  }

  if (sp5C->unk454 == 3) {
    return sp5C->unk1578;
  }

  if (sp5C->unk454 == 1) {
    if (sp5C->unk156C >= sp5C->unk450) {
      if (sp5C->unk158E) {
        rmonPrintf("RESTART: BASE: %x CUR: %x\n", D_80128DDC, sp5C->unk1580);
        for (sp4C = 0; sp4C < sp5C->unk440; sp4C++) {
          channel = &sp5C->channels[sp4C];
          if (channel->state != 0) {
            channel->state = 0;
            alSynStopVoice(&sp5C->alGlobals->drvr, &channel->v);
          }
          channel->v.state = 0;
        }
        sp5C->unk444 = sp5C->unk448;
        func_8008EFA0(sp5C->unk444, &sp5C->unk458);
        Audio2_8008756c_eightliner(sp5C);
        return sp5C->unk1578;
      }
      sp5C->unk454 = 0;
      return sp5C->unk1578;
    }
    Audio2_800874ac_sevenliner(sp5C);

    if (sp5C->unk1587) {
      for (sp4C = 0; sp4C < sp5C->unk440; sp4C++) {
        channel = &sp5C->channels[sp4C];
        if (channel->state != 0) {
          if (channel->unk28 == 0) {
            channel->unk28 = 1;
          }
          channel->vol = (u16) ((sqrtf(channel->unk28) * sp5C->unk157C) / 16);
          alSynSetVol(&sp5C->alGlobals->drvr, &channel->v, channel->vol, 1);
        }
      }
      sp5C->unk1587 = FALSE;
    }

    if (sp5C->unk158C) {
      for (sp4C = 0; sp4C < sp5C->unk440; sp4C++) {
        channel = &sp5C->channels[sp4C];
        if (channel->state != 0) {
          channel->pan = sp5C->unk158D;
          alSynSetPan(&sp5C->alGlobals->drvr, &channel->v, channel->pan);
        }
      }
      sp5C->unk158C = FALSE;
    }

    for (sp4C = 0; sp4C < sp5C->unk440; sp4C++) {
      channel = &sp5C->channels[sp4C];
      if (sp5C->unk1586 != 0) {
        sp5C->unk1586--;
      } else {
        sp57 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)];
        sp5C->unk1568++;
        sp5C->unk156C++;
        if (sp5C->unk1598 == 0) {
          sp5C->unk1598 = 1;
          osWritebackDCacheAll();
        }

        if (sp57 & 0x80) {
          sp5C->unk1586 = sp57 & 0x7F;
        } else {
          if (sp57 & 0x40) {  // set pitch
            sp48 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)] + (sp5C->unk1468[(u8) ((sp5C->unk1568 + 1) & 0xFF)] << 8);
            sp5C->unk156C += 2;
            sp5C->unk1568 += 2;
            sp48 &= 0xFFFF;
            sp43 = sp48 >> 14;
            sp48 &= 0x3FFF;
            sp48 = D_800D3B40[sp43] + (sp48 << sp43);
            channel->pitch = Dcm_SetPitch(sp48);
          }

          if (sp57 & 0x20) {  // set vol
            channel->unk28 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)];
            sp5C->unk1568++;
            sp5C->unk156C++;
            channel->unk28 &= 0xFF;
            if (channel->unk28 == 0) {
              channel->unk28 = 1;
            }
            channel->vol = (u16) ((sqrtf(channel->unk28) * sp5C->unk157C) / 16);
          }

          if (sp57 & 0x10) {  // set pan
            channel->pan = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)] >> 1;
            sp5C->unk1568++;
            sp5C->unk156C++;
          }

          if (sp57 & 8) {
            sp56 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)];
            sp5C->unk1568++;
            sp5C->unk156C++;
            channel->wt = &sp5C->unk438->wt[sp56];
            sp5C->unk428[sp4C] = sp56;

            if (channel->state == 1) {
              if (channel->v.pvoice != NULL) {
                // See /opt/ultralib/src/audio/synallocvoice.c
                filter = channel->v.pvoice->channelKnob;
                channel->v.pvoice->offset = 320;

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples;
                  param->type = AL_FILTER_SET_VOLUME;
                  param->data.i = 0;
                  param->moredata.i = channel->v.pvoice->offset - 64;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
                  param->type = AL_FILTER_STOP_VOICE;
                  param->next = NULL;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }
              }
            }
          }

          if (sp57 & 4) {
            sp44 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)] << 8;
            sp5C->unk1568++;
            sp5C->unk156C++;
            // (bug?) Does this ever get reset back?
            channel->wt->base = sp5C->unk438->wt_base[sp5C->unk428[sp4C]] + sp44;
            channel->wt->len = sp5C->unk438->wt_len[sp5C->unk428[sp4C]] - (channel->wt->base - sp5C->unk438->wt_base[sp5C->unk428[sp4C]]);

            if (channel->state == 1) {
              if (channel->v.pvoice != NULL) {
                filter = channel->v.pvoice->channelKnob;
                channel->v.pvoice->offset = 320;

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples;
                  param->type = AL_FILTER_SET_VOLUME;
                  param->data.i = 0;
                  param->moredata.i = channel->v.pvoice->offset - 64;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
                  param->type = AL_FILTER_STOP_VOICE;
                  param->next = NULL;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }
              }
            }
          }

          if (sp57 & 2) {
            if (channel->state == 1) {
              if (channel->v.pvoice != NULL) {
                filter = channel->v.pvoice->channelKnob;
                channel->v.pvoice->offset = 320;

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples;
                  param->type = AL_FILTER_SET_VOLUME;
                  param->data.i = 0;
                  param->moredata.i = channel->v.pvoice->offset - 64;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }

                param = __allocParam();
                if (param != NULL) {
                  param->delta = sp5C->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
                  param->type = AL_FILTER_STOP_VOICE;
                  param->next = NULL;
                  filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                }
              }
            }

            if (sp57 & 4) {
              if (sp5C->alGlobals != NULL) {
                if (channel->wt != NULL) {
                  alSynStartVoiceParams(&sp5C->alGlobals->drvr, &channel->v, channel->wt, channel->pitch, channel->vol, channel->pan, 0, 100);
                }
              }
            } else {
              alSynStartVoiceParams(&sp5C->alGlobals->drvr, &channel->v, channel->wt, channel->pitch, channel->vol, channel->pan, 0, 1);
            }
            channel->state = 1;
          }

          if ((channel->state != 0) && (sp57 & 0x40) && !(sp57 & 2)) {
            alSynSetPitch(&sp5C->alGlobals->drvr, &channel->v, channel->pitch);
          }

          if ((channel->state != 0) && (sp57 & 0x20) && !(sp57 & 2)) {
            channel->vol = (u16) ((sqrtf(channel->unk28) * sp5C->unk157C) / 16);
            if (sp57 & 4) {
              alSynSetVol(&sp5C->alGlobals->drvr, &channel->v, channel->vol, 100);
            } else {
              alSynSetVol(&sp5C->alGlobals->drvr, &channel->v, channel->vol, 1);
            }
          }

          if ((channel->state != 0) && (sp57 & 0x10) && !(sp57 & 2)) {
            alSynSetPan(&sp5C->alGlobals->drvr, &channel->v, channel->pan);
          }

          if (sp57 & 1) {
            sp57 = sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)];
            sp5C->unk1568++;
            sp5C->unk156C++;
            if (sp57 & 0x40) {
              // bpm?  125 (default bpm) * 1000000 (microtime) / (bpm * 50 (hz))
              sp5C->unk1578 = 125 * 1000000 / (sp5C->unk1468[(u8) (sp5C->unk1568 & 0xFF)] * 50);
              sp5C->unk1568++;
              sp5C->unk156C++;
            }
            if (sp57 & 0x20) {
              sp5C->unk1568++;
              sp5C->unk156C++;
            }
          }
        }
      }
    }
  }

  return sp5C->unk1578;
}

void Audio2_80088ba4_fiveliner(SfxPlayer *arg0) {
  OSMesg sp1C;
  SfxPlayer *sp18;

  sp18 = arg0;
  if (arg0->unk88 != 1) {
    D_80128DC8.unk0 = 1;
    D_80128DC8.unk4 = sp18;
    osJamMesg(&D_80128D50, (OSMesg)&D_80128DC8, OS_MESG_NOBLOCK);
    osRecvMesg(&D_80128D18, &sp1C, OS_MESG_BLOCK);
  }
}

void Audio2_GFXDone_SendStopMessage(SfxPlayer *arg0) {
  OSMesg sp1C;

  D_80128DC8.unk0 = 0;
  D_80128DC8.unk4 = arg0;
  rmonPrintf("GFX send STOP message to SFXPLAYER\n");
  osJamMesg(&D_80128D50, (OSMesg)&D_80128DC8, OS_MESG_NOBLOCK);
  osRecvMesg(&D_80128D18, &sp1C, OS_MESG_BLOCK);
  rmonPrintf("GFX done send STOP message to SFXPLAYER\n");
}

void Audio2_80088c84_largeliner(SfxPlayer *arg0, s32 arg1, u8 arg2) {
  s32 i;
  ALVoiceConfig vc;
  Channel *channel;

  if (arg1 == 0) {
    arg0->unk18 = &D_80124938;
    arg0->channels = D_80125598;
    arg0->alGlobals = alGlobals;
    arg0->unk8C = arg2;
    arg0->unk0.next = NULL;
    arg0->unk0.handler = Dcm_VoiceHandler_2;
    arg0->unk0.clientData = arg0;
    arg0->unk0.callTime = 0;
    alSynAddPlayer(&alGlobals->drvr, &arg0->unk0);
    vc.priority = 5;
    vc.fxBus = 0;
    vc.unityPitch = 0;

    for(i = 0; i < arg2; i++) {
      alSynAllocVoice(&arg0->alGlobals->drvr, &arg0->channels[i].v, &vc);
    }

    for(i = 0; i < arg2; i++) {
      arg0->channels[i].wt = arg0->unk18->wt;
      arg0->channels[i].pitch = 1.0;
      arg0->channels[i].vol = 0;
      arg0->channels[i].pan = 64;
      arg0->channels[i].state = 0;
    }
  }

  for(i = 0; i < arg2; i++) {
    channel = &arg0->channels[i];
    arg0->unk20[i] = 0;
    arg0->unk110[i].unk0 = arg0->unk110[i].unk4;
    arg0->unk110[i].unk0[0] = 0;

    if (channel->state == 1) {
      channel->state = 0;
      alSynStopVoice(&arg0->alGlobals->drvr, &channel->v);
    }

    arg0->unk20[i] = 0;
    arg0->unk90[i] = 0;
    arg0->unkD0[i] = 0;
  }

  for(i = 0; i < 255; i++) {
    arg0->unk364[i] = 255;
  }

  for(i = 0; i < (arg2 >> 1); i++) {
    arg0->unk60[i] = 0;
  }

  arg0->unk80 = 0;
  arg0->unk84 = 0;
}

u8 *Audio2_80089030_hugeliner_SFX_Channel(SfxPlayer *arg0, u8 *arg1, u8 *arg2, s32 arg3) {
  DcmHeader sp60;
  Sample sp50;
  s32 sp4C;
  s32 sp48;
  s8 *sp44;
  u8 *sp40;
  u8 *sp3C;
  s16 *sp38;
  s16 *sp34;
  s32 sp30;
  u16 sp2E;
  u16 sp2C;
  s32 sp28;

  sp2E = arg0->unk84;
  Audio2_8008bf58_eightliner(arg1, &sp60);
  arg1 += 14;
  arg0->unk350[sp2E] = (UnkStruct_79 *) arg2;
  arg2 += sizeof(UnkStruct_79);
  arg2 = (u8 *) (((intptr_t) arg2 + 0xF) & ~0xF);
  arg0->unk350[sp2E]->unkC = sp60.num_channels;
  arg0->unk350[sp2E]->unk0 = arg2;
  arg0->unk350[sp2E]->unk4 = sp60.stream_sz;
  arg2 += sp60.stream_sz;
  arg2 = (u8 *) (((intptr_t) arg2 + 0xF) & ~0xF);

  sp4C = sp60.stream_sz;
  sp44 = (s8 *) (arg1 + (sp60.num_samples * sizeof(Sample)));
  sp40 = arg0->unk350[sp2E]->unk0;
  while (sp4C--) {
    *sp40++ = *sp44++;
  }
  sp3C = (u8 *) ((sp60.num_samples * sizeof(Sample) + (intptr_t) arg1 + sp60.stream_sz + 0xF) & ~0xF);

  if (sp60.num_channels > 2) {
    rmonPrintf("***************************** SFX CHANNEL ERR\n");
  }

  for (sp4C = 0; sp4C < sp60.num_samples; sp4C++) {
    Audio2_8008c014_tenliner(arg1, &sp50);
    osWritebackDCacheAll();

    sp28 = 1;
    for (sp2C = 0; sp2C < 255; sp2C++) {
      if (arg0->unk364[sp2C] == (sp50.id - D_800D3B50)) {
        sp28 = 0;
        arg0->unk350[sp2E]->unk10[sp4C] = sp2C;
        break;
      }
    }

    if (sp28 != 0) {
      arg0->unk364[arg0->unk80] = sp50.id - D_800D3B50;
      arg0->unk350[sp2E]->unk10[sp4C] = arg0->unk80;
      if (sp50.flags & 1) {  // 16-bit
        if (sp50.flags & 4) {  // loop
          Audio2_80087478_oneliner_calls_fun(arg2, sp50.id);
          arg0->unk18->wt[arg0->unk80].base = arg2;
          arg0->unk18->wt_base[arg0->unk80] = arg2;
          arg0->unk18->wt[arg0->unk80].len = sp50.smplen * 2;
          arg0->unk18->wt_len[arg0->unk80] = sp50.smplen * 2;
          arg0->unk18->wt[arg0->unk80].type = AL_RAW16_WAVE;
          arg0->unk18->wt[arg0->unk80].flags = 1;

          sp44 = (s8 *) arg0->unk18->wt[arg0->unk80].base;
          sp34 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
          sp30 = sp50.smplen;
          while (sp30--) {
            *sp34++ = ((sp44[1] << 8) & 0xFF00) + (sp44[0] & 0xFF);
            sp44 += 2;
          }

          arg2 += sp50.smplen * 2;
          arg2 = (u8 *) (((intptr_t) arg2 + 16 + 0xF) & ~0xF);  // (bug?) shouldn't this be 16*2?

          if (sp50.flags & 4) {  // loop
            sp34 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
            sp38 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
            if (sp50.flags & 8) {  // bidi-loop
              for (sp48 = 0; sp48 < 16; sp48++) {
                sp34[sp50.loopEnd + sp48] = sp38[(sp50.loopBegin - 1) - sp48];
              }
            } else {  // no bidi-loop
              for (sp48 = 0; sp48 < 16; sp48++) {
                sp34[sp50.loopEnd + sp48] = sp38[sp50.loopBegin + sp48];
              }
            }
          } else {  // no loop
            sp34 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
            sp38 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
            for (sp48 = 0; sp48 < 16; sp48++) {
              sp34[(sp48 + sp50.smplen) * 2] = 0;  // (bug?) why "* 2"?
            }
          }
        } else if (sp50.flags & 4) {  // loop
          /*
            This block will never be entered, because its `else if`
            clause is the same as the `if` clause before it.
          */

          Audio2_80087478_oneliner_calls_fun(arg2 + sp50.smplen, sp50.id);
          arg0->unk18->wt[arg0->unk80].base = arg2;
          arg0->unk18->wt_base[arg0->unk80] = arg2;
          arg0->unk18->wt[arg0->unk80].len = sp50.smplen;
          arg0->unk18->wt_len[arg0->unk80] = sp50.smplen;
          arg0->unk18->wt[arg0->unk80].type = AL_RAW16_WAVE;
          arg0->unk18->wt[arg0->unk80].flags = 1;

          sp44 = (s8 *) arg0->unk18->wt[arg0->unk80].base + sp50.smplen;
          sp34 = (s16 *) arg0->unk18->wt[arg0->unk80].base;
          sp30 = sp50.smplen;
          while (sp30--) {
            *sp34++ = *sp44++ << 8;
          }

          arg2 += sp50.smplen;
          arg2 = (u8 *) (((intptr_t) arg2 + 16 + 0xF) & ~0xF);
        } else {  // no loop
          Audio2_80087478_oneliner_calls_fun(arg2, sp50.id);
          arg0->unk18->wt[arg0->unk80].base = arg2;
          arg0->unk18->wt_base[arg0->unk80] = arg2;
          arg0->unk18->wt[arg0->unk80].len = sp50.smplen;
          arg0->unk18->wt_len[arg0->unk80] = sp50.smplen;
          arg0->unk18->wt[arg0->unk80].type = H2O_RAW8_WAVE;
          arg0->unk18->wt[arg0->unk80].flags = 1;

          sp44 = (s8 *) arg0->unk18->wt[arg0->unk80].base;
          sp40 = arg0->unk18->wt[arg0->unk80].base;
          sp30 = sp50.smplen;

          while (sp30--) {
            *sp40++ = (s16) (Audio2_8008c0e0_oneliner_arg0_math((u8 *)sp44) >> 8);
            sp44 += 2;
          }

          arg2 += sp50.smplen * 2;
          arg2 = (u8 *) (((intptr_t) arg2 + 16 + 0xF) & ~0xF);
        }
      } else {  // 8-bit
        Audio2_80087478_oneliner_calls_fun(arg2, sp50.id);
        arg0->unk18->wt[arg0->unk80].base = arg2;
        arg0->unk18->wt_base[arg0->unk80] = arg2;
        arg0->unk18->wt[arg0->unk80].len = sp50.smplen;
        arg0->unk18->wt[arg0->unk80].type = H2O_RAW8_WAVE;
        arg0->unk18->wt[arg0->unk80].flags = 1;
        arg0->unk18->wt_len[arg0->unk80] = sp50.smplen;

        sp44 = (s8 *) sp3C;
        sp40 = arg0->unk18->wt[arg0->unk80].base;
        sp30 = sp50.smplen;

        arg2 += sp50.smplen;
        arg2 = (u8 *) (((intptr_t) arg2 + 16 + 0xF) & ~0xF);

        if (sp50.flags & 4) {  // loop
          sp40 = arg0->unk18->wt[arg0->unk80].base;
          if (sp50.flags & 8) {  // bidi-loop
            for (sp48 = 0; sp48 < 16; sp48++) {
              sp40[sp50.loopEnd + sp48] = (s8) sp40[sp50.loopBegin - 1 - sp48];
            }
          } else {  // no bidi-loop
            for (sp48 = 0; sp48 < 16; sp48++) {
              sp40[sp50.loopEnd + sp48] = (s8) sp40[sp50.loopBegin + sp48];
            }
          }
        } else {  // no loop
          sp40 = arg0->unk18->wt[arg0->unk80].base;
          for (sp48 = 0; sp48 < 16; sp48++) {
            sp40[sp48 + sp50.smplen] = 0;
          }
        }
      }

      if (sp50.flags & 4) {  // loop
        arg0->unk18->wt[arg0->unk80].waveInfo.rawWave.loop = &arg0->unk18->rawLoop[arg0->unk80];
        arg0->unk18->rawLoop[arg0->unk80].start = sp50.loopBegin;
        arg0->unk18->rawLoop[arg0->unk80].end = sp50.loopEnd;
        arg0->unk18->rawLoop[arg0->unk80].count = -1;
      } else {  // no loop
        arg0->unk18->wt[arg0->unk80].waveInfo.rawWave.loop = NULL;
      }

      arg0->unk80++;
    }

    arg1 += 16;
  }

  arg0->unk84++;
  return arg2;
}

void Audio2_80089d5c_twentyfourliner_sendstop(SfxPlayer *arg0) {
  u32 i = 0;
  Channel *channel;
  s32 unused;

  Audio2_GFXDone_SendStopMessage(arg0);
  Audio2_8008a7c0_fiveliner();

  for (i = 0; i < arg0->unk8C; i++) {
    channel = &arg0->channels[i];
    if (channel->state == 1) {
      alSynStopVoice(&arg0->alGlobals->drvr, &channel->v);
      channel->state = 0;
    }
    arg0->unk20[i] = 0;
    arg0->unk110[i].unk0[0] = 0;
    arg0->unk354[i] = 1;
  }

  for (i = 0; i < (arg0->unk8C >> 1); i++) {
    arg0->unk60[i] = 0;
    D_80128DE0[i] = 0xFF;
  }

  Audio2_80088ba4_fiveliner(arg0);
}

// return a free channel, or 0xFF if no free channels
static u8 Audio2_80089edc_thirtyfourliner_loops(SfxPlayer *arg0, u8 arg1) {
  u8 sp4F;
  u8 sp4E;
  u32 sp48;
  u32 sp8[16] = {0};
  u8 sp7 = 0;

  sp48 = 0;

  for (sp4F = 0; sp4F < (arg0->unk8C >> 1); sp4F++) {
    if (arg0->unk20[sp4F] == 0) {
      return sp4F;
    }

    if (arg1 >= arg0->unk20[sp4F]) {
      sp8[sp4F] = arg0->unk60[sp4F];
      sp7++;
    } else {
      sp8[sp4F] = 0;
    }
  }

  if (sp7 == 0) {
    return 0xFF;
  }

  sp48 = -1U;  // UINT_MAX or U32_MAX
  sp4E = 0;

  for (sp4F = 0; sp4F < 8; sp4F++) {
    if ((sp8[sp4F] != 0) && (sp8[sp4F] < sp48)) {
      sp4E = sp4F;
      sp48 = sp8[sp4F];
    }
  }

  return sp4E;
}

static UnkStruct_95 *Audio2_Play_SFX_Bank_Channel(SfxPlayer *player, SfxBank *bank, u8 sfx_id, u8 arg3) {
  u8 sp37;
  u8 sp36;
  u8 sp35;
  u8 sp34;
  u8 sp33;
  u8 sp28[8];
  s32 i;
  s32 j;
  s32 sp1C;

  if (gp_sfxBank != bank) {
    rmonPrintf("***** Dont Play Sound effects that belong to a bank thats not loaded  Sperm Head\n\0\0\0SFX# %x NS: %x \0S%x : %x \0\0\0\n");
    return &D_80128AB0;
  }

  sp1C = 0xFF;
  for (i = 0; i < 8; i++) {
    if (D_80128DE0[i] == sfx_id) {
      player->unk110[i].unk14 = TRUE;
      if (sp1C == 0xFF) {
        sp1C = i;
      }
    }
  }

  if (sp1C != 0xFF) {
    return &player->unk110[sp1C];
  }

  sp36 = bank->unk0[sfx_id].unk2;
  sp35 = bank->unk0[sfx_id].unk1;

  if (FALSE) {}

  for (i = 0; i < sp35; i++) {
    sp28[i] = bank->unk0[sfx_id].unk3[i];
  }

  sp33 = 0xFF;

  for (i = 0; i < sp35; i++) {
    sp37 = Audio2_80089edc_thirtyfourliner_loops(player, sp36 - i);
    if (sp37 == 0xFF) {
      sp37 = Audio2_80089edc_thirtyfourliner_loops(player, 0xF0);  // 0xF0 == 240
      if (sp37 == 0xFF) {
        rmonPrintf("No Free Channel\n");
        return &D_80128AB0;
      }
    }

    player->unk110[sp37].unk0 = player->unk110[sp33].unk4;  // (bug?) sp33 = 0xFF (out of range for unk110 array)
    player->unk354[sp37 * 2] = 2;
    player->unk354[sp37 * 2 + 1] = 2;
    if (sp33 == 0xFF) {
      sp33 = sp37;
    }

    for (sp34 = 0; sp34 < 2; sp34++) {
      // (bug?) sp34 isn't used inside this loop
      player->unk20[sp37] = 0;
      player->unk60[sp37] = 0;
    }

    if (arg3 != 0) {
      player->unk110[sp37].unk0[1] = arg3;
      player->unk110[sp37].unk0[2] = TRUE;
    } else {
      player->unk110[sp37].unk0[1] = 0;
      player->unk110[sp37].unk0[2] = FALSE;
    }

    D_80128DE0[sp37] = sfx_id;

    player->unk110[sp37].unk14 = FALSE;
    player->unk110[sp37].unk8 = player->unk350[sp28[i]]->unk0;  // stream
    player->unk110[sp37].unkC = player->unk110[sp37].unk8 + player->unk350[sp28[i]]->unk4;  // after stream
    player->unk110[sp37].unk18 = player->unk350[sp28[i]]->unk4;  // stream size

    for (j = 0; j < 8; j++) {
      player->unk110[sp37].unk1C[j] = player->unk350[sp28[i]]->unk10[j];
    }

    player->unk20[sp37] = sp36 - i;
    player->unk60[sp37] = D_800D3910 - i;
  }

  return &player->unk110[sp33];
}

UnkStruct_95 *Audio2_Play_SFX(SfxPlayer *player, SfxBank *bank, u8 sfx_id) {
  if (gp_sfxBank != NULL) {
    return Audio2_Play_SFX_Bank_Channel(player, bank, sfx_id, 0);
  }

  return &D_80128AB0;
}

static void Audio2_8008a61c_twelveliner(void) {
  s16 i;

  for (i = 0; i < 16; i++) {
    if (D_80128DE8[i].unkA != 32000) {
      D_80128DE8[i].unkA--;
      if (D_80128DE8[i].unkA <= 0) {
        Audio2_Play_SFX(D_80128DE8[i].player, D_80128DE8[i].bank, D_80128DE8[i].sfx_id);
        D_80128DE8[i].unkA = 32000;
      }
    }
  }
}

// unused
void Audio2_8008a6ec_nineliner(SfxPlayer *player, SfxBank *bank, u8 sfx_id, s16 arg3) {
  s16 i;

  for (i = 0; i < 16; i++) {
    if (D_80128DE8[i].unkA == 32000) {
      break;
    }
  }
  D_80128DE8[i].player = player;
  D_80128DE8[i].bank = bank;
  D_80128DE8[i].sfx_id = sfx_id;
  D_80128DE8[i].unkA = arg3;
}

static void Audio2_8008a7c0_fiveliner(void) {
  s16 i;
  s16 temp_t0;

  for (i = 0; i < 16; i++) {
    D_80128DE8[i].unkA = 32000;
  }
}

static ALMicroTime Dcm_VoiceHandler_2(void *arg0) {
  Channel *channel;
  u32 sp58;
  u8 sp57;
  u8 sp56;
  u8 sp55;
  u8 sp54;
  ALParam *param;
  ALFilter *filter;
  SfxPlayer *sp48;
  SfxPlayer *sp44;
  UnkStruct_102 *sp40;
  u8 *sp3C;
  u8 sp3B;

  sp48 = (SfxPlayer *)arg0;
  if (osRecvMesg(&D_80128D50, (OSMesg *)&sp40, OS_MESG_NOBLOCK) == 0) {
    sp44 = sp40->unk4;
    switch (sp40->unk0) {
    case 0:
      for (sp56 = 0; sp56 < sp44->unk8C; sp56++) {
        channel = &sp44->channels[sp56];
        if (channel->state != 0) {
          channel->state = 0;
          alSynStopVoice(&sp44->alGlobals->drvr, &channel->v);
        }
      }
      sp44->unk88 = 3;
      osSendMesg(&D_80128D18, NULL, 0);
      sp40->unk0 = 0;
      return D_800D3940;
    case 1:
      sp44->unk88 = 1;
      sp40->unk0 = 0;
      osSendMesg(&D_80128D18, NULL, 0);
      break;
    default:
      sp40->unk0 = 0;
      break;
    }
  }

  if (sp48->unk88 == 3) {
    return D_800D3940;
  }

  if (sp48->unk88 == 1) {
    static s32 D_800D3B94 = 0;  // unused
    static u8 D_800D3B98[8] = {0};
    static u8 D_800D3BA0 = 0;

    Audio2_8008a61c_twelveliner();

    for (sp56 = 0; sp56 < sp48->unk8C; sp56++) {
      channel = &sp48->channels[sp56];
      if (sp48->unk110[sp56 >> 1].unk14) {
        D_800D3B98[sp56 >> 1] = 0;
        sp48->unk110[sp56 >> 1].unk14 = FALSE;
        sp48->unk110[sp56 >> 1].unk8 = sp48->unk110[sp56 >> 1].unkC - sp48->unk110[sp56 >> 1].unk18;
        channel = &sp48->channels[sp56 >> 1];

        if (channel->state != 0) {
          if (channel->v.pvoice != NULL) {
            // See /opt/ultralib/src/audio/synallocvoice.c
            filter = channel->v.pvoice->channelKnob;
            channel->v.pvoice->offset = 576;

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples;
              param->type = AL_FILTER_SET_VOLUME;
              param->data.i = 0;
              param->moredata.i = channel->v.pvoice->offset - 64;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
              param->type = AL_FILTER_STOP_VOICE;
              param->next = NULL;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }
          }
          alSynStopVoice(&sp48->alGlobals->drvr, &channel->v);
          channel->state = 0;
        }
      }

      if (sp48->unk354[sp56] != 0) {
        D_800D3B98[sp56 >> 1] = 0;
        if (sp48->unk354[sp56] != 2) {
          D_80128DE0[sp56 >> 1] = 0xFF;
        }
        sp48->unk354[sp56] = 0;

        if (channel->state == 1) {
          if (channel->v.pvoice != NULL) {
            filter = channel->v.pvoice->channelKnob;
            channel->v.pvoice->offset = 576;

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples;
              param->type = AL_FILTER_SET_VOLUME;
              param->data.i = 0;
              param->moredata.i = channel->v.pvoice->offset - 64;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
              param->type = AL_FILTER_STOP_VOICE;
              param->next = NULL;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }
          }
          alSynStopVoice(&sp48->alGlobals->drvr, &channel->v);
          channel->state = 0;
        } else {
          if (sp48->alGlobals != NULL) {
            if (channel->wt != NULL) {
              alSynStartVoiceParams(&sp48->alGlobals->drvr, &channel->v, channel->wt, 0, 0, 0, 0, 100);
            }
          }

          if (channel->v.pvoice != NULL) {
            filter = channel->v.pvoice->channelKnob;
            channel->v.pvoice->offset = 576;

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples;
              param->type = AL_FILTER_SET_VOLUME;
              param->data.i = 0;
              param->moredata.i = channel->v.pvoice->offset - 64;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }

            param = __allocParam();
            if (param != NULL) {
              param->delta = sp48->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
              param->type = AL_FILTER_STOP_VOICE;
              param->next = NULL;
              filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
            }
          }
          alSynStopVoice(&sp48->alGlobals->drvr, &channel->v);
          channel->state = 0;
        }
      }
    }

    for (D_800D3BA0 = 0; D_800D3BA0 < (sp48->unk8C >> 1); D_800D3BA0++) {
      sp3C = sp48->unk110[D_800D3BA0].unk8;
      if ((sp48->unk20[D_800D3BA0] != 0) && (sp3C != NULL)) {
        if (sp48->unk110[D_800D3BA0].unk0[0] == 3) {
          sp48->unk110[D_800D3BA0].unk0[0] = 0;
          rmonPrintf("******************* loop off\n");
        }

        for (sp56 = 0; sp56 < 2; sp56++) {
          channel = &sp48->channels[sp56 + (D_800D3BA0 * 2)];
          if (D_800D3B98[D_800D3BA0] != 0) {
            D_800D3B98[D_800D3BA0]--;
          } else if (sp48->unk110[D_800D3BA0].unk8 >= sp48->unk110[D_800D3BA0].unkC) {
            D_80128DE0[D_800D3BA0] = 0xFF;
            channel->state = 0;
            D_800D3B98[D_800D3BA0] = 0;
            sp48->unk20[D_800D3BA0] = 0;
            sp48->unk354[D_800D3BA0 * 2] = 1;
            sp48->unk354[D_800D3BA0 * 2 + 1] = 1;
          } else {
            sp55 = *sp48->unk110[D_800D3BA0].unk8;
            sp48->unk110[D_800D3BA0].unk8++;

            if (sp55 & 0x80) {
              D_800D3B98[D_800D3BA0] = sp55 & 0x7F;
            } else {
              if (sp55 & 0x40) {  // set pitch
                sp58 = Audio2_8008c0e0_oneliner_arg0_math(sp48->unk110[D_800D3BA0].unk8);
                sp48->unk110[D_800D3BA0].unk8 += 2;
                sp58 &= 0xFFFF;
                sp57 = sp58 >> 14;
                sp58 &= 0x3FFF;
                sp58 = D_800D3B40[sp57] + (sp58 << sp57);
                channel->pitch = Dcm_SetPitch_2(sp58);
              }

              if (sp55 & 0x20) {  // set vol
                sp3B = *sp48->unk110[D_800D3BA0].unk8;  // index into a volume table (D_80128AD8)
                sp48->unk110[D_800D3BA0].unk8++;
                if (sp48->unk110[D_800D3BA0].unk0[2]) {
                  channel->vol = D_80128AD8[sp48->unk110[D_800D3BA0].unk0[1]];
                } else {
                  channel->vol = D_80128AD8[sp3B];
                }
              }

              if (sp55 & 0x10) {  // set pan
                channel->pan = *sp48->unk110[D_800D3BA0].unk8 >> 1;
                sp48->unk110[D_800D3BA0].unk8++;
              }

              if (sp55 & 8) {
                sp54 = *sp48->unk110[D_800D3BA0].unk8;
                sp48->unk110[D_800D3BA0].unk8++;
                channel->wt = &sp48->unk18->wt[sp48->unk110[D_800D3BA0].unk1C[sp54]];
                sp48->unkD0[sp56 + (D_800D3BA0 * 2)] = sp54;

                if (channel->state == 1) {
                  if (channel->v.pvoice != NULL) {
                    filter = channel->v.pvoice->channelKnob;
                    channel->v.pvoice->offset = 576;

                    param = __allocParam();
                    if (param != NULL) {
                      param->delta = sp48->alGlobals->drvr.paramSamples;
                      param->type = AL_FILTER_SET_VOLUME;
                      param->data.i = 0;
                      param->moredata.i = channel->v.pvoice->offset - 64;
                      filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                    }

                    param = __allocParam();
                    if (param != NULL) {
                      param->delta = sp48->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
                      param->type = AL_FILTER_STOP_VOICE;
                      param->next = NULL;
                      filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                    }
                  }
                }
              }

              if (sp55 & 4) {
                channel->wt->base = sp48->unk18->wt_base[sp48->unk110[D_800D3BA0].unk1C[sp48->unkD0[sp56 + (D_800D3BA0 * 2)]]] + (*sp48->unk110[D_800D3BA0].unk8 << 8);
                sp48->unk110[D_800D3BA0].unk8++;
                channel->wt->len = sp48->unk18->wt_len[sp48->unk110[D_800D3BA0].unk1C[sp48->unkD0[sp56 + (D_800D3BA0 * 2)]]] - (channel->wt->base - sp48->unk18->wt_base[sp48->unk110[D_800D3BA0].unk1C[sp48->unkD0[sp56 + (D_800D3BA0 * 2)]]]);
              } else if (sp55 & 2) {
                channel->wt->base = sp48->unk18->wt_base[sp48->unk110[D_800D3BA0].unk1C[sp48->unkD0[sp56 + (D_800D3BA0 * 2)]]];
                channel->wt->len = sp48->unk18->wt_len[sp48->unk110[D_800D3BA0].unk1C[sp48->unkD0[sp56 + (D_800D3BA0 * 2)]]];
              }

              if (sp55 & 2) {
                if (channel->state == 1) {
                  if (channel->v.pvoice != NULL) {
                    filter = channel->v.pvoice->channelKnob;
                    channel->v.pvoice->offset = 576;

                    param = __allocParam();
                    if (param != NULL) {
                      param->delta = sp48->alGlobals->drvr.paramSamples;
                      param->type = AL_FILTER_SET_VOLUME;
                      param->data.i = 0;
                      param->moredata.i = channel->v.pvoice->offset - 64;
                      filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                    }

                    param = __allocParam();
                    if (param != NULL) {
                      param->delta = sp48->alGlobals->drvr.paramSamples + channel->v.pvoice->offset;
                      param->type = AL_FILTER_STOP_VOICE;
                      param->next = NULL;
                      filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
                    }
                  }
                }

                if (sp48->alGlobals != NULL) {
                  if (channel->wt != NULL) {
                    alSynStartVoiceParams(&sp48->alGlobals->drvr, &channel->v, channel->wt, channel->pitch, channel->vol, channel->pan, 0, 500);
                  }
                }
                channel->state = 1;
              }

              if ((channel->state != 0) && (sp55 & 0x40) && !(sp55 & 2)) {
                alSynSetPitch(&sp48->alGlobals->drvr, &channel->v, channel->pitch);
              }

              if ((channel->state != 0) && (sp55 & 0x20) && !(sp55 & 2)) {
                alSynSetVol(&sp48->alGlobals->drvr, &channel->v, channel->vol, 500);
              }

              if ((channel->state != 0) && (sp55 & 0x10) && !(sp55 & 2)) {
                alSynSetPan(&sp48->alGlobals->drvr, &channel->v, channel->pan);
              }

              if (channel->state != 0) {
                if (sp48->unk110[D_800D3BA0].unk0[2]) {
                  channel->vol = D_80128AD8[sp48->unk110[D_800D3BA0].unk0[1]];
                  alSynSetVol(&sp48->alGlobals->drvr, &channel->v, channel->vol, 500);
                }
              }

              if (sp55 & 1) {
                sp55 = *sp48->unk110[D_800D3BA0].unk8;
                sp48->unk110[D_800D3BA0].unk8++;

                if (sp55 & 0x40) {
                  if (*sp48->unk110[D_800D3BA0].unk8 != 0) {
                    // bpm?  125 (default bpm) * 1000000 (microtime) / (bpm * 50 (hz))
                    D_800D3940 = 125 * 1000000 / (*sp48->unk110[D_800D3BA0].unk8 * 50);
                    sp48->unk110[D_800D3BA0].unk8++;
                  } else {
                    rmonPrintf("DIVIDE BY ERROR IN SFX SPEED CHANGE\n");
                    sp48->unk110[D_800D3BA0].unk8++;
                  }
                }

                if (sp55 & 0x20) {
                  sp55 = *sp48->unk110[D_800D3BA0].unk8;
                  sp48->unk110[D_800D3BA0].unk8++;
                  if (sp48->unk110[D_800D3BA0].unk0[0] == 1) {
                    if (sp55 == 1) {
                      sp48->unk110[D_800D3BA0].unk10 = sp48->unk110[D_800D3BA0].unk8;
                    }
                    if (sp55 == 2) {
                      sp48->unk110[D_800D3BA0].unk8 = sp48->unk110[D_800D3BA0].unk10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return D_800D3940;
}

/*
  Significance of the number 14318184.

  14.318184 MHz is a standard, widely used clock crystal frequency in computer hardware, chosen to be an exact multiple of the NTSC color television subcarrier frequency (3.579545 MHz).

  Its prevalence stems from computing history and architecture:

  - Television Roots: The exact frequency is 4 x 3.579545 MHz (the NTSC color burst frequency). When early IBM PCs and graphics cards were being designed, it was cheaper to use readily available, mass-produced crystals from the television industry to generate the clock signals for the system.

  - PC Clock Generation: In many computer architectures -- particularly older motherboards and legacy ports -- this frequency is the base clock from which various system buses (like ISA) are derived.

  - Audio and I/O Codecs: It is still frequently used as the primary clock generator for inexpensive audio codecs and sound cards.

  Because these quartz crystals have been in mass production for personal computers for over two decades, they are highly cost-effective and easy to source.
*/

/*
  Significance of the number 8363.

  A reference to 8363 Hz refers to the vintage Amiga computer audio sample rate. In early tracker software, this specific frequency was tied to the Amiga's hardware clock and remains a point of reference for tracking old-school digital music.

  - The Amiga Clock: Early trackers (like Protracker) used the NTSC Amiga's 8363 Hz Paula chip interrupt rate as the system's baseline sample rate for a Middle C (C-4) note.

  - The "32 Samples" Math: The pitch for C-4 is roughly 261.63 Hz. If you divide 8363 Hz by 261.63 Hz, you get approximately 32. Because 32 is a power of 2, it made looping and pitching waveforms much cleaner and less prone to digital clicking on hardware with limited memory.
*/

static f32 Dcm_SetPitch_2(s16 arg0) {
  f32 sp1C;

  if (arg0 <= 0) {
    return 0;
  }

  sp1C = 8363 * (1712.0 / (f32) (14318184 / arg0)) / 36000;
  if (sp1C >= 2.0) {
    rmonPrintf("pitch %f out of range\n", sp1C);
    sp1C = 1;
  }
  if (sp1C < 0.0) {
    sp1C *= -1.0;
    rmonPrintf("\nNEGATIVE PITCH\n");
  }

  return sp1C;
}

static f32 Dcm_SetPitch(u16 arg0) {
  f32 sp1C;

  if (arg0 <= 0) {
    return 0;
  }

  sp1C = 8363 * (1712.0 / (f32) (14318184 / arg0)) / 36000;
  if (sp1C >= 2.0) {
    rmonPrintf("pitch %f out of range\n", sp1C);
    sp1C = 1;
  }
  if (sp1C < 0.0) {
    sp1C *= -1.0;
    rmonPrintf("\nNEGATIVE PITCH\n");
  }

  return sp1C;
}

static void Audio2_8008bf58_eightliner(u8 *arg0, DcmHeader *arg1) {
  arg1->dcm1 = Audio2_8008c130_oneliner_arg0_math_3(arg0);
  arg0 += 4;
  arg1->num_channels = *arg0++;
  arg1->num_samples = *arg0++;
  arg1->stream_sz = Audio2_8008c104_oneliner_arg0_math_2(arg0);
  arg0 += 4;
  arg1->unkC = Audio2_8008c104_oneliner_arg0_math_2(arg0);
  arg0 += 4;
}

static void Audio2_8008c014_tenliner(u8 *arg0, Sample *arg1) {
  arg1->smplen = Audio2_8008c104_oneliner_arg0_math_2(arg0);
  arg0 += 4;
  arg1->loopBegin = Audio2_8008c104_oneliner_arg0_math_2(arg0);
  arg0 += 4;
  arg1->loopEnd = Audio2_8008c104_oneliner_arg0_math_2(arg0);
  arg0 += 4;
  arg1->flags = Audio2_8008c0e0_oneliner_arg0_math(arg0);
  arg0 += 2;
  arg1->id = Audio2_8008c0e0_oneliner_arg0_math(arg0);
  arg0 += 2;
}

static s16 Audio2_8008c0e0_oneliner_arg0_math(u8 *arg0) {
  return arg0[0] + (arg0[1] << 8);
}

static s32 Audio2_8008c104_oneliner_arg0_math_2(u8 *arg0) {
  return arg0[0] + (arg0[1] << 8) + (arg0[2] << 16) + (arg0[3] << 24);
}

static s32 Audio2_8008c130_oneliner_arg0_math_3(u8 *arg0) {
  return arg0[3] + (arg0[2] << 8) + (arg0[1] << 16) + (arg0[0] << 24);
}

void Audio2_SFX_Debug_Print(Sample *arg0) {
  rmonPrintf("\n\tflags: ", arg0->flags);
  arg0->flags & 0x1 ? rmonPrintf("16-BIT ") : rmonPrintf("8-BIT ");
  arg0->flags & 0x2 ? rmonPrintf("SIGNED ") : rmonPrintf("UNSIGNED ");
  arg0->flags & 0x4 ? rmonPrintf("LOOP ") : rmonPrintf("NO-LOOP ");
  arg0->flags & 0x8 ? rmonPrintf("BIDI-LOOP ") : rmonPrintf("NO_BIDI ");
  rmonPrintf("\n");
  rmonPrintf("\tloopBegin16: %x 8Bit: %x\n", arg0->loopBegin * 2, arg0->loopBegin);
  rmonPrintf("\tloopEnd16: %x 8Bit: %x\n", arg0->loopEnd * 2, arg0->loopEnd);
  rmonPrintf("\tsmplen16: %x 8Bit: %x\n", arg0->smplen * 2, arg0->smplen);
  rmonPrintf("\tSample ID: %x\n\n", arg0->id);
}
