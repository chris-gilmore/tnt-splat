#include "common.h"

Color g_color_L = { 0xA0, 0x1E, 0x8C, 0xFF, 0xFF, 0xFF };
Color g_color_J = { 0x5A, 0x1E, 0xA0, 0xFF, 0xFF, 0xFF };
Color g_color_Z = { 0xA0, 0x28, 0x28, 0xFF, 0xFF, 0xFF };
Color g_color_S = { 0, 0xA0, 0x28, 0xFF, 0xFF, 0xFF };
Color g_color_T = { 0xB4, 0xA0, 0, 0xFF, 0xFF, 0xFF };
Color g_color_I = { 0, 0x78, 0xBE, 0xFF, 0xFF, 0xFF };
Color g_color_O = { 0x78, 0x78, 0x78, 0xFF, 0xFF, 0xFF };

Color g_color_silver = { 0x320, 0x3C0, 0x500, 0xDC0, 0xF50, 0xFF0 };
Color g_color_gold = { 0x800, 0x500, 0x0, 0xFF0, 0xF50, 0xDC0 };
Color g_color_white = { 0xFF0, 0xFF0, 0xFF0, 0xFF0, 0xFF0, 0xFF0 };
Color g_color_black = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
Color g_color_red = { 0xFF0, 0x0, 0x0, 0xFF0, 0x0, 0x0 };
Color g_color_metal = { 0x0, 0x0, 0x0, 0xFF0, 0xFF0, 0xFF0 };

// unused
void Color_Tint(Color *src, u32 alpha) {
  src->diffuse_red    = (((0xFF0 - src->diffuse_red)    * alpha) / 0xFF) + src->diffuse_red;
  src->diffuse_green  = (((0xFF0 - src->diffuse_green)  * alpha) / 0xFF) + src->diffuse_green;
  src->diffuse_blue   = (((0xFF0 - src->diffuse_blue)   * alpha) / 0xFF) + src->diffuse_blue;
  src->specular_red   = (((0xFF0 - src->specular_red)   * alpha) / 0xFF) + src->specular_red;
  src->specular_green = (((0xFF0 - src->specular_green) * alpha) / 0xFF) + src->specular_green;
  src->specular_blue  = (((0xFF0 - src->specular_blue)  * alpha) / 0xFF) + src->specular_blue;
}

// unused
void Color_Brighten(Color *src, u32 alpha) {
  src->diffuse_red    = ((src->diffuse_red    * alpha) / 0xFF) + src->diffuse_red;
  src->diffuse_green  = ((src->diffuse_green  * alpha) / 0xFF) + src->diffuse_green;
  src->diffuse_blue   = ((src->diffuse_blue   * alpha) / 0xFF) + src->diffuse_blue;
  src->specular_red   = ((src->specular_red   * alpha) / 0xFF) + src->specular_red;
  src->specular_green = ((src->specular_green * alpha) / 0xFF) + src->specular_green;
  src->specular_blue  = ((src->specular_blue  * alpha) / 0xFF) + src->specular_blue;
}

void Color_Blend(Color *src, Color *dst, u32 dst_alpha) {
  src->diffuse_red    = (((dst->diffuse_red    - src->diffuse_red)    * dst_alpha) / 0xFF) + src->diffuse_red;
  src->diffuse_green  = (((dst->diffuse_green  - src->diffuse_green)  * dst_alpha) / 0xFF) + src->diffuse_green;
  src->diffuse_blue   = (((dst->diffuse_blue   - src->diffuse_blue)   * dst_alpha) / 0xFF) + src->diffuse_blue;
  src->specular_red   = (((dst->specular_red   - src->specular_red)   * dst_alpha) / 0xFF) + src->specular_red;
  src->specular_green = (((dst->specular_green - src->specular_green) * dst_alpha) / 0xFF) + src->specular_green;
  src->specular_blue  = (((dst->specular_blue  - src->specular_blue)  * dst_alpha) / 0xFF) + src->specular_blue;
}
