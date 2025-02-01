#include "common.h"

GameStats *g_gameStats_ptr;
f32 g_pieceFallAcceleration = 0.000003;

static void   initLinesInfo(LinesInfo *);
static void   updateLineCount(LinesInfo *);
static void   setLineCount(LinesInfo *, u32);
static void   displayLineCount(LinesInfo *);

static void initLinesInfo(LinesInfo *linesInfo_ptr) {
  linesInfo_ptr->odd_bits = 0;
  linesInfo_ptr->even_bits = 0;
  linesInfo_ptr->linesToBeAdded = 0;
  linesInfo_ptr->linesMultiplier = 1;
  linesInfo_ptr->unk14 = 0;
}

static void updateLineCount(LinesInfo *linesInfo_ptr) {
  if (linesInfo_ptr->linesToBeAdded != 0) {
    if (FALSE) {}
    setLineCount(linesInfo_ptr, getLineCount(linesInfo_ptr) + (linesInfo_ptr->linesToBeAdded * linesInfo_ptr->linesMultiplier));
    linesInfo_ptr->linesMultiplier = 1;
    linesInfo_ptr->linesToBeAdded = 0;
  }
}

u32 getLineCount(LinesInfo *linesInfo_ptr) {
  return linesInfo_ptr->odd_bits | linesInfo_ptr->even_bits;
}

static void setLineCount(LinesInfo *linesInfo_ptr, u32 lines) {
  linesInfo_ptr->odd_bits = lines & 0xAAAAAAAA;
  linesInfo_ptr->even_bits = lines & 0x55555555;
}

static void displayLineCount(LinesInfo *linesInfo_ptr) {
  char strLineCount[8];

  sprintf(strLineCount, "%d", getLineCount(linesInfo_ptr));
  func_8005BBFC(&g_gdl);
  displayText_XY_RGBA_2(&g_gdl, &g_game.unk8, linesInfo_ptr->x, linesInfo_ptr->y, strLineCount, 0xFF, 0xFF, 0xFF, 0xFF);
  func_8005BE40(&g_gdl);
}

void GameStats_saveCurrentPieceFallVelocity(GameStats *gameStats_ptr) {
  register f32 velocity;

  velocity = gameStats_ptr->pieceFallVelocityInitial + (g_game.unkE4E8 * gameStats_ptr->pieceFallAcceleration);
  if (velocity > gameStats_ptr->pieceFallVelocityMax) {
    velocity = gameStats_ptr->pieceFallVelocityMax;
  }
  g_currentPiece_ptr->fallVelocityCopy = func_800A2EF0(velocity * 0x100);
}

void updateLinesToBeAdded(LinesInfo *linesInfo_ptr, s32 lines) {
  linesInfo_ptr->linesToBeAdded += lines;
}

void GameStats_Update(GameStats *gameStats_ptr, u32 arg1) {
  updateLineCount(&gameStats_ptr->linesInfo);
  gameStats_ptr->elapsedTime += arg1;
}

void GameStats_Render(GameStats *gameStats_ptr) {
  displayLineCount(&gameStats_ptr->linesInfo);
}

void GameStats_Init(GameStats *gameStats_ptr) {
  initLinesInfo(&gameStats_ptr->linesInfo);
  gameStats_ptr->pieceFallVelocityInitial = 0.01;
  gameStats_ptr->pieceFallVelocityMax = 1.0;
  gameStats_ptr->pieceFallAcceleration = g_pieceFallAcceleration;
  GameStats_saveCurrentPieceFallVelocity(gameStats_ptr);
}

void GameStats_Deinit(GameStats *gameStats_ptr) {
}
