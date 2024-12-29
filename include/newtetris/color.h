#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct {
  /* 0x0 */ s16   diffuse_red;
  /* 0x2 */ s16   diffuse_green;
  /* 0x4 */ s16   diffuse_blue;
  /* 0x6 */ s16   specular_red;
  /* 0x8 */ s16   specular_green;
  /* 0xA */ s16   specular_blue;
} Color; // 0xC bytes

extern Color g_color_L;  // pink
extern Color g_color_J;  // purple
extern Color g_color_Z;  // red
extern Color g_color_S;  // green
extern Color g_color_T;  // yellow
extern Color g_color_I;  // blue
extern Color g_color_O;  // gray

extern Color g_color_silver;
extern Color g_color_gold;
extern Color g_color_white;
extern Color g_color_black;
extern Color g_color_red;
extern Color g_color_metal;

extern void   Color_Tint(Color *, u32);            // unused
extern void   Color_Brighten(Color *, u32);        // unused
extern void   Color_Blend(Color *, Color *, u32);

#endif /* !_COLOR_H_ */
