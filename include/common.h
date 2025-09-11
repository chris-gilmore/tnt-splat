#ifndef _COMMON_H_
#define	_COMMON_H_

#include "ultra64.h"
#include "PR/sched.h"

typedef long           intptr_t;
typedef unsigned long  uintptr_t;

typedef struct {
  f32 x, y, z;
} Vec3;

typedef struct {
  f32 m00, m01, m02, m03; // Row 0
  f32 m10, m11, m12, m13; // Row 1
  f32 m20, m21, m22, m23; // Row 2
  f32 m30, m31, m32, m33; // Row 3
} MtxF;

#include "newtetris/sram.h"
#include "newtetris/066700.h"
#include "newtetris/069170.h"
#include "newtetris/074B00.h"
#include "newtetris/06FFD0.h"
#include "newtetris/borganim.h"
#include "newtetris/072C40.h"
#include "newtetris/06F220.h"
#include "newtetris/069D80.h"

#include "newtetris/img_defs.h"
#include "newtetris/anim_defs.h"
#include "newtetris/cfb.h"
#include "newtetris/03D120.h"
#include "newtetris/003E40.h"
#include "newtetris/006B30.h"
#include "newtetris/078FE0.h"
#include "newtetris/077340.h"
#include "newtetris/073D50.h"
#include "newtetris/073120.h"
#include "newtetris/haluci.h"
#include "newtetris/0449D0.h"
#include "newtetris/frametime.h"
#include "newtetris/049380.h"
#include "newtetris/finalrom_datetime.h"
#include "newtetris/046DD0.h"
#include "newtetris/0279C0.h"
#include "newtetris/font.h"
#include "newtetris/063BC0.h"
#include "newtetris/cubetiles.h"
#include "newtetris/03B700.h"
#include "newtetris/046770.h"
#include "newtetris/strutil.h"
#include "newtetris/endscroller.h"
#include "newtetris/055500.h"
#include "newtetris/009A90.h"
#include "newtetris/00C0D0.h"
#include "newtetris/00C680.h"
#include "newtetris/tally.h"
#include "newtetris/pausemenu.h"
#include "newtetris/032F00.h"
#include "newtetris/color.h"
#include "newtetris/piecedefs.h"
#include "newtetris/026900.h"
#include "newtetris/026C80.h"
#include "newtetris/026F90.h"
#include "newtetris/03AC20.h"
#include "newtetris/03C130.h"
#include "newtetris/gamevars.h"
#include "newtetris/cont.h"
#include "newtetris/contq.h"
#include "newtetris/playervars.h"
#include "newtetris/03C220.h"
#include "newtetris/minos.h"
#include "newtetris/mobilepiece.h"
#include "newtetris/ghostpiece.h"
#include "newtetris/cube.h"
#include "newtetris/mobilecubes.h"
#include "newtetris/fallingcubes.h"
#include "newtetris/currentpiece.h"
#include "newtetris/ids.h"
#include "newtetris/boardpieces.h"
#include "newtetris/033310.h"
#include "newtetris/piecehold.h"
#include "newtetris/gamestats.h"
#include "newtetris/boardinfo.h"
#include "newtetris/garbage.h"
#include "newtetris/landfill.h"
#include "newtetris/gamefinish.h"
#include "newtetris/frameact.h"
#include "newtetris/bag63.h"
#include "newtetris/nextpieces.h"
#include "newtetris/multisquareglow.h"
#include "newtetris/multisquare.h"
#include "newtetris/0073F0.h"
#include "newtetris/0074E0.h"
#include "newtetris/04BFD0.h"
#include "newtetris/board.h"
#include "newtetris/lineeffect.h"
#include "newtetris/linescan.h"
#include "newtetris/keyspin.h"
#include "newtetris/pfgfx.h"
#include "newtetris/n64heap.h"
#include "newtetris/001050.h"
#include "newtetris/00E440.h"
#include "newtetris/bootmain.h"
#include "newtetris/010870.h"
#include "newtetris/aiplayer.h"
#include "newtetris/tetris.h"
#include "newtetris/game.h"
#include "newtetris/setplayer.h"
#include "newtetris/0497E0.h"
#include "newtetris/dbgprntrrl.h"
#include "newtetris/03A750.h"
#include "newtetris/072080.h"
#include "newtetris/0470D0.h"
#include "newtetris/01D6E0.h"
#include "newtetris/creditstext.h"
#include "newtetris/credits.h"
#include "newtetris/audio.h"
#include "newtetris/imageparams.h"
#include "newtetris/animparams.h"
#include "newtetris/03D140.h"
#include "newtetris/formattime.h"
#include "newtetris/027BF0.h"
#include "newtetris/rand.h"
#include "newtetris/0691B0.h"

typedef union {
  struct {
    u32 hi;
    u32 lo;
  } word;
  f64 d;
} du;

typedef union {
  u32 i;
  f32 f;
} fu;

extern u8 D_273A00;  // image_lut
extern u8 D_5206B0;  // anim_lut

#endif /* !_COMMON_H_ */
