#include "common.h"

// 1p
ImageParams D_800D0930[24] = {
  // img_u.id,                 x,   y,   red, green,  blue, alpha,  pal_u.id
  {IMG_MAYAN_MOON,           210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {IMG_MAYAN_PLAYFIELD,       87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_MAYAN_BACKGROUND,       0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_MAYAN_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_GREEK_BACKGROUND,       0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_GREEK_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_EGYPTIAN_BACKGROUND,    0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_EGYPTIAN_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_CELTIC_BACKGROUND,      0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_CELTIC_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_AFRICAN_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_AFRICAN_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_JAPANESE_BACKGROUND,    0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_JAPANESE_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_RUSSIAN_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_BACKGROUND_PAL},

  {0,                        210,  20,  0xFF,  0xFF,  0xFF,  0xFF,  0},
  {0,                         87,  30,  0xFF,  0xFF,  0xFF,  0x64,  0},
  {IMG_FINALE_BACKGROUND,      0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_FINALE_BACKGROUND_PAL}
};

// 2p
ImageParams D_800D0C30[16] = {
  // img_u.id,                    x,   y,   red, green,  blue, alpha,  pal_u.id
  {IMG_MAYAN_2P_BACKGROUND,       0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_MAYAN_2P_BACKGROUND_PAL},
  {IMG_MAYAN_TIME,              170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_MAYAN_TIME_PAL},

  {IMG_GREEK_2P_BACKGROUND,       0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_GREEK_2P_BACKGROUND_PAL},
  {IMG_GREEK_TIME,              170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_GREEK_TIME_PAL},

  {IMG_EGYPTIAN_2P_BACKGROUND,    0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_EGYPTIAN_2P_BACKGROUND_PAL},
  {IMG_EGYPTIAN_TIME,           170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_EGYPTIAN_TIME_PAL},

  {IMG_CELTIC_2P_BACKGROUND,      0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_CELTIC_2P_BACKGROUND_PAL},
  {IMG_CELTIC_TIME,             170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_CELTIC_TIME_PAL},

  {IMG_AFRICAN_2P_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_AFRICAN_2P_BACKGROUND_PAL},
  {IMG_AFRICAN_TIME,            170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_AFRICAN_TIME_PAL},

  {IMG_JAPANESE_2P_BACKGROUND,    0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_JAPANESE_2P_BACKGROUND_PAL},
  {IMG_JAPANESE_TIME,           170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_JAPANESE_TIME_PAL},

  {IMG_RUSSIAN_2P_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_2P_BACKGROUND_PAL},
  {IMG_RUSSIAN_TIME,            170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_TIME_PAL},

  {IMG_RUSSIAN_2P_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_2P_BACKGROUND_PAL},
  {IMG_RUSSIAN_TIME,            170, 246,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_TIME_PAL}
};

// 3p, 4p
ImageParams D_800D0E30[16] = {
  // img_u.id,                  x,   y,   red, green,  blue, alpha,  pal_u.id
  {IMG_MAYAN_4P_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_MAYAN_4P_BACKGROUND_PAL},
  {IMG_MAYAN_TIME,              0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_MAYAN_TIME_PAL},

  {IMG_GREEK_4P_BACKGROUND,     0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_GREEK_4P_BACKGROUND_PAL},
  {IMG_GREEK_TIME,              0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_GREEK_TIME_PAL},

  {IMG_EGYPTIAN_4P_BACKGROUND,  0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_EGYPTIAN_4P_BACKGROUND_PAL},
  {IMG_EGYPTIAN_TIME,           0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_EGYPTIAN_TIME_PAL},

  {IMG_CELTIC_4P_BACKGROUND,    0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_CELTIC_4P_BACKGROUND_PAL},
  {IMG_CELTIC_TIME,             0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_CELTIC_TIME_PAL},

  {IMG_AFRICAN_4P_BACKGROUND,   0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_AFRICAN_4P_BACKGROUND_PAL},
  {IMG_AFRICAN_TIME,            0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_AFRICAN_TIME_PAL},

  {IMG_JAPANESE_4P_BACKGROUND,  0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_JAPANESE_4P_BACKGROUND_PAL},
  {IMG_JAPANESE_TIME,           0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_JAPANESE_TIME_PAL},

  {IMG_RUSSIAN_4P_BACKGROUND,   0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_4P_BACKGROUND_PAL},
  {IMG_RUSSIAN_TIME,            0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_TIME_PAL},

  {IMG_RUSSIAN_4P_BACKGROUND,   0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_4P_BACKGROUND_PAL},
  {IMG_RUSSIAN_TIME,            0,   0,  0xFF,  0xFF,  0xFF,  0xFF,  IMG_RUSSIAN_TIME_PAL}
};
