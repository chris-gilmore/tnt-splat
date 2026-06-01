#ifndef _dcm_H_
#define _dcm_H_

// raw, signed 8-bit PCM audio data
#define H2O_RAW8_WAVE 2

typedef struct {
  /* 0x0 */ s32   dcm1;  // 'DCM1' as int
  /* 0x4 */ u8    num_channels;
  /* 0x5 */ u8    num_samples;
  /* 0x8 */ s32   stream_sz;
  /* 0xC */ s32   unkC;  // 0
} DcmHeader; // 0x10 bytes

typedef struct {
  /* 0x0 */ u32   smplen;
  /* 0x4 */ u32   loopBegin;
  /* 0x8 */ u32   loopEnd;
  /* 0xC */ u16   flags;
  /* 0xE */ u16   id;
} Sample; // 0x10 bytes

typedef struct {
  /* 0x0   */ ALWaveTable   wt[66];
  /* 0x528 */ u8           *wt_base[66];
  /* 0x630 */ s32           wt_len[66];
  /* 0x738 */ u32           loopBegin[66];
  /* 0x840 */ u32           loopEnd[66];
  /* 0x948 */ ALRawLoop     rawLoop[66];
} UnkStruct_96; // 0xC60 bytes

typedef struct {
  /* 0x0  */ ALVoice       v;
  /* 0x1C */ ALWaveTable  *wt;
  /* 0x20 */ f32           pitch;
  /* 0x24 */ s16           vol;
  /* 0x26 */ s8            pan;
  /* 0x27 */ u8            state;
  /* 0x28 */ s16           unk28;  // vol index
} Channel; // 0x2C bytes

typedef struct {
  /* 0x0    */ ALPlayer       node;
  /* 0x14   */ ALGlobals     *alGlobals;
  /* 0x18   */ Sample         unk18[64];
  /* 0x418  */ DcmHeader      unk418;
  /* 0x428  */ u8             unk428[16];
  /* 0x438  */ UnkStruct_96  *unk438;
  /* 0x43C  */ Channel       *channels;
  /* 0x440  */ s32            unk440;  // number of channels
  /* 0x444  */ u8            *unk444;  // stream
  /* 0x448  */ u8            *unk448;
  /* 0x44C  */ u8            *unk44C;  // stream
  /* 0x450  */ u32            unk450;
  /* 0x454  */ u8             unk454;
  /* 0x458  */ UnkStruct_85   unk458;
  /* 0x1468 */ u8             unk1468[256];
  /* 0x1568 */ u16            unk1568;
  /* 0x156A */ u16            unk156A;
  /* 0x156C */ u32            unk156C;
  /* 0x1570 */ u8             unk1570;  // boolean
  /* 0x1571 */ u8             unk1571;
  /* 0x1572 */ u8             unk1572;
  /* 0x1574 */ u8            *unk1574;
  /* 0x1578 */ s32            unk1578;
  /* 0x157C */ s16            unk157C;  // music_level (volume)
  /* 0x157E */ s16            unk157E;
  /* 0x1580 */ u16            unk1580;  // song num
  /* 0x1582 */ u16            unk1582;  // song num
  /* 0x1584 */ u8             unk1584;  // boolean
  /* 0x1585 */ u8             unk1585;
  /* 0x1586 */ u8             unk1586;
  /* 0x1587 */ u8             unk1587;  // boolean
  /* 0x1588 */ s16            unk1588;
  /* 0x158A */ s16            unk158A;
  /* 0x158C */ u8             unk158C;  // boolean
  /* 0x158D */ s8             unk158D;  // pan_level
  /* 0x158E */ u8             unk158E;  // boolean
  /* 0x1590 */ u8            *unk1590;
  /* 0x1594 */ u8             pad1594[0x4];
  /* 0x1598 */ u8             unk1598;
  /* 0x1599 */ u8             unk1599;  // boolean
  /* 0x159A */ u8             pad159A[0x6];
} SongPlayer; // 0x15A0 bytes

typedef struct {
  /* 0x0  */ u8   *unk0;
  /* 0x4  */ s32   unk4;  // size of stream
  /* 0x8  */ u8    pad4[0x4];
  /* 0xC  */ s32   unkC;  // number of channels
  /* 0x10 */ u8    unk10[8];
} UnkStruct_79; // 0x18 bytes

typedef struct {
  /* 0x0  */ u8   *unk0;
  /* 0x4  */ u8    unk4[4];
  /* 0x8  */ u8   *unk8;  // stream
  /* 0xC  */ u8   *unkC;  // after stream
  /* 0x10 */ u8   *unk10;
  /* 0x14 */ u8    unk14;  // boolean
  /* 0x18 */ s32   unk18;  // size of stream
  /* 0x1C */ u8    unk1C[8];
} UnkStruct_95; // 0x24 bytes

typedef struct {
  /* 0x0   */ ALPlayer       unk0;
  /* 0x14  */ ALGlobals     *alGlobals;
  /* 0x18  */ UnkStruct_96  *unk18;
  /* 0x1C  */ Channel       *channels;
  /* 0x20  */ u32            unk20[16];
  /* 0x60  */ s32            unk60[8];
  /* 0x80  */ s32            unk80;
  /* 0x84  */ s32            unk84;
  /* 0x88  */ s32            unk88;
  /* 0x8C  */ u32            unk8C;
  /* 0x90  */ s32            unk90[16];
  /* 0xD0  */ s32            unkD0[16];
  /* 0x110 */ UnkStruct_95   unk110[16];
  /* 0x350 */ UnkStruct_79 **unk350;
  /* 0x354 */ u8             unk354[16];
  /* 0x364 */ u8             unk364[256];
} SfxPlayer; // 0x464 bytes

typedef struct {
  /* 0x0 */ u8   unk0;  // 2
  /* 0x1 */ u8   unk1;
  /* 0x2 */ u8   unk2;
  /* 0x3 */ u8   unk3[8];
} UnkStruct_104; // 0xB bytes

typedef struct {
  /* 0x0  */ UnkStruct_104  *unk0;
  /* 0x4  */ u16             unk4;    // number of sound effects
  /* 0x6  */ u16             dcm_id;  // starting position in lut
  /* 0x8  */ u8             *unk8;
  /* 0xC  */ u16             unkC;
  /* 0x10 */ u32             size;
} SfxBank; // 0x14 bytes

typedef struct {
  /* 0x0 */ SfxPlayer  *player;
  /* 0x4 */ SfxBank    *bank;
  /* 0x8 */ u8          sfx_id;
  /* 0xA */ s16         unkA;  // something about 32000
} UnkStruct_97; // 0xC bytes

typedef struct {
  /* 0x0  */ s32           unk0;
  /* 0x4  */ u8            pad4[0x4];
  /* 0x8  */ s32           unk8;  // set to 2
  /* 0xC  */ u8            padC[0x4];
  /* 0x10 */ OSTask        tlist;
  /* 0x50 */ OSMesgQueue  *unk50;
  /* 0x54 */ s16          *unk54;
} UnkStruct_103; // 0x58 bytes

typedef struct UnkStruct_100 UnkStruct_100;
struct UnkStruct_100 {
  /* 0x0  */ s16            *audioBuffer;
  /* 0x4  */ s16             audioSamples;
  /* 0x8  */ UnkStruct_103   unk8;
  /* 0x60 */ u8              pad60[0x10];
  /* 0x70 */ s16             unk70;  // set to 2
  /* 0x74 */ UnkStruct_100  *unk74;
  /* 0x78 */ u8              pad78[0x18];
}; // 0x90 bytes

typedef struct {
  /* 0x0   */ Acmd           *cmdList[2];
  /* 0x8   */ UnkStruct_100  *unk8[3];
  /* 0x14  */ u8              pad14[0x4];
  /* 0x18  */ OSThread        unk18;
  /* 0x1C8 */ OSMesgQueue     unk1C8;
  /* 0x1E0 */ OSMesg          unk1E0[8];
  /* 0x200 */ OSMesgQueue     unk200;
  /* 0x218 */ OSMesg          unk218[8];
  /* 0x238 */ ALGlobals       alGlobals;
} UnkStruct_101; // 0x284 bytes

typedef struct {
  /* 0x0 */ s16    unk0;
  /* 0x4 */ void  *unk4;
} UnkStruct_102; // 0x8 bytes

extern SongPlayer D_80122010;
extern SfxPlayer D_801235B0;
extern UnkStruct_96 D_80123A18;
extern Channel D_80124678[];
extern UnkStruct_96 D_80124938;
extern Channel D_80125598[];
extern UnkStruct_96 D_80125858;
extern Channel D_801264B8[];
extern ALHeap D_80126778;
extern u8 *D_80126788;
extern u8 *D_8012678C;
extern void *D_80126790;
extern void *D_80126794;
extern u8 *D_80126798;
extern s32 D_8012679C;  // unused
extern OSMesgQueue *D_801267A0;
extern UnkStruct_101 D_801267A8;
extern u64 D_80126A30[];
extern s32 D_80128A30[9];  // unused
extern u32 D_80128A54;
extern u32 D_80128A58;
extern u32 D_80128A5C;
extern u32 D_80128A60;  // max_clist_size
extern OSMesgQueue D_80128A68;  // unused
extern OSMesgQueue D_80128A80;
extern OSMesg D_80128A98[1];
extern uintptr_t D_80128A9C;
extern uintptr_t D_80128AA0;
extern void *D_80128AA4;
extern s32 D_80128AA8;  // unused
extern SfxBank *gp_sfxBank;
extern OSMesgQueue D_80128CE0;
extern OSMesg D_80128CF8[8];
extern OSMesgQueue D_80128D18;
extern OSMesg D_80128D30[8];
extern OSMesgQueue D_80128D50;
extern OSMesg D_80128D68[8];  // unused
extern OSMesgQueue D_80128D88;
extern OSMesg D_80128DA0[8];  // unused
extern UnkStruct_102 D_80128DC0;
extern UnkStruct_102 D_80128DC8;
extern UnkStruct_102 D_80128DD0;  // unused
extern u16 D_80128DD8;
extern s32 D_80128DDC;

extern u32 D_800D3910;
extern s32 D_800D3918;
extern UnkStruct_100 *D_800D391C;
extern s32 D_800D3920;
extern SfxBank g_menuSfxBank;
extern SfxBank g_gameSfxBank;
extern SfxBank g_introSfxBank;
extern u16 D_800D3B50;

extern void           Dcm_Init(SongPlayer *, UnkStruct_96 *, Channel *, u8, s16, u8);
extern void           Audio2_AllocDcmHeader(SongPlayer *, u8 *);
extern void          *Audio2_80086138_largeliner_channels(SongPlayer *, u8 *, void *, u8);
extern void           Audio2_AllocDcmScratch8(SongPlayer *);
extern void           func_800875E4(s32);
extern void           func_800875EC(u16, SongPlayer *);
extern void           func_80087600(s8, SongPlayer *);  // unused
extern void           Audio2_80087618_fourteenliner_loops_256t(u16);
extern void           Audio2_80087770_oneliner_turn_on(SongPlayer *);
extern void           Audio2_8008777c_oneliner_turn_off(SongPlayer *);
extern void           Audio2_GFXDone_SendPlayMessage(SongPlayer *);
extern void           Audio2_8008780c_sixliner_v1(SongPlayer *);
extern void           Audio2_8008787c_sixliner_v2(SongPlayer *);  // unused
extern void           Audio2_80088ba4_fiveliner(SfxPlayer *);
extern void           Audio2_GFXDone_SendStopMessage(SfxPlayer *);
extern void           Audio2_80088c84_largeliner(SfxPlayer *, s32, u8);
extern u8            *Audio2_80089030_hugeliner_SFX_Channel(SfxPlayer *, u8 *, u8 *, s32);
extern void           Audio2_80089d5c_twentyfourliner_sendstop(SfxPlayer *);
extern UnkStruct_95  *Audio2_Play_SFX(SfxPlayer *, SfxBank *, u8);
extern void           Audio2_8008a6ec_nineliner(SfxPlayer *, SfxBank *, u8, s16);  // unused
extern void           Audio2_SFX_Debug_Print(Sample *);

#endif /* !_dcm_H_ */
