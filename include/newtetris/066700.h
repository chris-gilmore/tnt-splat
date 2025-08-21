#ifndef _066700_H_
#define _066700_H_

#define GUI_TITLE     (1 <<  0)
#define GUI_PIC       (1 <<  1)
#define GUI_FUNC      (1 <<  2)
#define GUI_NULL      (1 <<  3)
#define GUI_MENU      (1 <<  4)
#define GUI_DIS       (1 <<  5)
#define GUI_CENTX     (1 <<  6)
#define GUI_CENTY     (1 <<  7)
#define GUI_NUM       (1 <<  8)
#define GUI_TEXTBOX   (1 <<  9)
#define GUI_TOGGLE    (1 << 10)
#define GUI_WINDOW    (1 << 11)
#define GUI_SLIDER    (1 << 12)
#define GUI_QUIT      (1 << 15)

typedef struct {
  /* 0x0  */ union { void *img; char *str; } data;
  /* 0x4  */ void  *pal;
  /* 0x8  */ s32    x;
  /* 0xC  */ s32    y;
  /* 0x10 */ s32    r;
  /* 0x14 */ s32    g;
  /* 0x18 */ s32    b;
  /* 0x1C */ s32    a;
  /* 0x20 */ u8     font;
} UnkStruct_80; // 0x24 bytes

typedef struct {
  /* 0x0   */ u8             num_ticks;
  /* 0x4   */ UnkStruct_80   track;
  /* 0x28  */ UnkStruct_80   marks[25];
  /* 0x3AC */ u32           *ids;
  /* 0x3B0 */ u8             cur;
} GUI_Slider; // 0x3B4 bytes

typedef struct {
  /* 0x0 */ u8             num;
  /* 0x4 */ UnkStruct_80  *unk4;
  /* 0x8 */ u32           *ids;
  /* 0xC */ u8             cur;
} GUI_Toggle; // 0x10 bytes

typedef struct {
  /* 0x0  */ u32            id;
  /* 0x4  */ u8             unk4;  // name idx
  /* 0x5  */ s8             unk5;  // char idx
  /* 0x8  */ PlayerNode    *node;  // maybe a better name is TextList?
  /* 0xC  */ s32            unkC;
  /* 0x10 */ s32            unk10;
  /* 0x14 */ UnkStruct_80   unk14;
  /* 0x38 */ UnkStruct_80   unk38;
  /* 0x5C */ u8             unk5C;
  /* 0x5D */ u8             unk5D;
  /* 0x5E */ u8             unk5E;
  /* 0x5F */ u8             unk5F;
  /* 0x60 */ u8             unk60;
  /* 0x61 */ u8             unk61;  // boolean
  /* 0x62 */ u8             unk62;
} GUI_Textbox; // 0x64 bytes

typedef struct UnkStruct_77 UnkStruct_77;

struct UnkStruct_77 {
  /* 0x0  */ UnkStruct_80   unk0;
  /* 0x24 */ u16            unk24;  // gui flag
  /* 0x28 */ void         (*unk28)(void *, ...);
  /* 0x2C */ UnkStruct_77  *unk2C;
  /* 0x30 */ void          *unk30;
  /* 0x34 */ s32            unk34;
}; // 0x38 bytes

typedef struct {
  /* 0x0   */ u8    unk0[4];
  /* 0x4   */ f32   unk4;   // translate_x
  /* 0x8   */ f32   unk8;   // translate_y
  /* 0xC   */ f32   unkC;   // translate_z
  /* 0x10  */ f32   unk10;
  /* 0x14  */ f32   unk14;
  /* 0x18  */ f32   unk18;
  /* 0x1C  */ f32   unk1C;  // rotate_roll
  /* 0x20  */ f32   unk20;  // rotate_pitch
  /* 0x24  */ f32   unk24;  // rotate_yaw
  /* 0x28  */ Mtx   unk28[2];
  /* 0xA8  */ Mtx   unkA8[2];
  /* 0x128 */ Mtx   unk128[2];
  /* 0x1A8 */ u8    unk1A8;
  /* 0x1AC */ f32   unk1AC;
  /* 0x1B0 */ f32   unk1B0;
  /* 0x1B4 */ f32   unk1B4;
  /* 0x1B8 */ f32   unk1B8;
  /* 0x1BC */ f32   unk1BC;
  /* 0x1C0 */ s32   unk1C0;
  /* 0x1C4 */ s32   unk1C4;
  /* 0x1C8 */ u8    unk1C8;
} UnkStruct_81; // 0x1D0 bytes

typedef struct {
  /* 0x0   */ Mtx            unk0[2];
  /* 0x80  */ Mtx            unk80[2];
  /* 0x100 */ u8             pad100[0xC];
  /* 0x10C */ void          *img;
  /* 0x110 */ s32            unk110;
  /* 0x114 */ s32            unk114;
  /* 0x118 */ s32            width;
  /* 0x11C */ s32            height;
  /* 0x120 */ s32            unk120;
  /* 0x124 */ UnkStruct_77  *unk124;
  /* 0x128 */ f32            unk128;
  /* 0x12C */ Vtx           *unk12C;
  /* 0x130 */ UnkStruct_81  *unk130;
  /* 0x134 */ s32            unk134;
} UnkStruct_78; // 0x138 bytes

extern UnkStruct_78 D_801290D0;
extern UnkStruct_78 D_80129208;

// 055500.c
extern u32 D_800D3FB0[18];
extern UnkStruct_77 D_800D3FF8[9];

// unused
extern GUI_Textbox D_800D41F0;

// 055500.c
extern u32 D_800D4254[24];
extern UnkStruct_77 D_800D42B4[12];

extern GUI_Slider D_800D4564;

extern GUI_Slider D_800D4928;

extern GUI_Textbox D_800D4CDC;

// 055500.c
extern GUI_Toggle D_800D4DC4;
extern u32 D_800D4DD4[18];
extern UnkStruct_77 D_800D4E1C[9];

extern GUI_Textbox D_800D5014;

// 055500.c
extern GUI_Toggle D_800D5170;
extern UnkStruct_77 D_800D5180[9];

// credits.c
extern u32 D_800D5378[20];
extern UnkStruct_77 D_800D53C8[10];

extern GUI_Toggle D_800D567C;

extern GUI_Toggle D_800D5794;

extern GUI_Textbox D_800D57A4;

// tally.c
extern u32 D_800D5808[18];
extern UnkStruct_77 D_800D5850[9];

extern GUI_Toggle D_800D5AB4;

extern GUI_Textbox D_800D5AC4;  // player 1

extern GUI_Textbox D_800D5B28;  // player 2

extern GUI_Textbox D_800D5B8C;  // player 3

extern GUI_Textbox D_800D5BF0;  // player 4

extern GUI_Toggle D_800D5CD8;

// tally.c
extern u32 D_800D5CE8[24];
extern UnkStruct_77 D_800D5D48[12];

// tally.c
extern u32 D_800D5FE8[10];
extern UnkStruct_77 D_800D6010[5];

// credits.c
extern u32 D_800D6128[4];
extern UnkStruct_77 D_800D6138[2];

// unused
extern u32 D_800D61A8[2];
extern UnkStruct_77 D_800D61B0[1];

extern void   func_800A2E2C(void);

#endif /* !_066700_H_ */
