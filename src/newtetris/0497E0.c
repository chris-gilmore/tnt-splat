#include "common.h"
#include "os_internal_error.h"

static OSThread D_801203D0;
static u64 D_80120580[0x400/sizeof(u64)];
static OSMesgQueue D_80120980;
static OSMesg D_80120998[1];
static void (*D_8012099C)(void);
static u16 *D_801209A0;
static u16 *D_801209A4;
static u16 D_801209A8;
static u16 D_801209AA;
static OSMesgQueue D_801209B0;
static char D_801209C8[88];
static OSMesg *D_80120A20;
static s32 D_80120A24;  // unused
static u32 D_80120A28;
static OSThread *D_80120A2C;
static s32 D_80120A30;

static UnkStruct_92 D_800D3340[28] = {
  { CAUSE_BD, CAUSE_BD, "BD" },                                       /* Branch delay slot */
  { CAUSE_IP8, CAUSE_IP8, "IP8" },                                    /* External level 8 pending - COMPARE */
  { CAUSE_IP7, CAUSE_IP7, "IP7" },                                    /* External level 7 pending - INT4 */
  { CAUSE_IP6, CAUSE_IP6, "IP6" },                                    /* External level 6 pending - INT3 */
  { CAUSE_IP5, CAUSE_IP5, "IP5" },                                    /* External level 5 pending - INT2 */
  { CAUSE_IP4, CAUSE_IP4, "IP4" },                                    /* External level 4 pending - INT1 */
  { CAUSE_IP3, CAUSE_IP3, "IP3" },                                    /* External level 3 pending - INT0 */
  { CAUSE_SW2, CAUSE_SW2, "IP2" },                                    /* Software level 2 pending */
  { CAUSE_SW1, CAUSE_SW1, "IP1" },                                    /* Software level 1 pending */
  { CAUSE_EXCMASK, EXC_INT, "Interrupt" },                            /* interrupt */
  { CAUSE_EXCMASK, EXC_MOD, "TLB modification exception" },           /* TLB mod */
  { CAUSE_EXCMASK, EXC_RMISS, "TLB load or instruction fetch" },      /* Read TLB Miss */
  { CAUSE_EXCMASK, EXC_WMISS, "TLB exception on store" },             /* Write TLB Miss */
  { CAUSE_EXCMASK, EXC_RADE, "Address load or instruction fetch" },   /* Read Address Error */
  { CAUSE_EXCMASK, EXC_WADE, "Address error on store" },              /* Write Address Error */
  { CAUSE_EXCMASK, EXC_IBE, "Bus error instruction fetch" },          /* Instruction Bus Error */
  { CAUSE_EXCMASK, EXC_DBE, "Bus error data reference" },             /* Data Bus Error */
  { CAUSE_EXCMASK, EXC_SYSCALL, "System call exception" },            /* SYSCALL */
  { CAUSE_EXCMASK, EXC_BREAK, "Breakpoint exception" },               /* BREAKpoint */
  { CAUSE_EXCMASK, EXC_II, "Reserved instruction exception" },        /* Illegal Instruction */
  { CAUSE_EXCMASK, EXC_CPU, "Coprocessor unusable exception" },       /* CoProcessor Unusable */
  { CAUSE_EXCMASK, EXC_OV, "Arithmetic overflow exception" },         /* OVerflow */
  { CAUSE_EXCMASK, EXC_TRAP, "Trap exception" },                      /* Trap exception */
  { CAUSE_EXCMASK, EXC_VCEI, "Virtual coherency intruction fetch" },  /* Virt. Coherency on Inst. fetch */
  { CAUSE_EXCMASK, EXC_FPE, "Floating point (see fpcsr)" },           /* Floating Point Exception */
  { CAUSE_EXCMASK, EXC_WATCH, "Watchpoint exception" },               /* Watchpoint reference */
  { CAUSE_EXCMASK, EXC_VCED, "Virtual coherency data reference" },    /* Virt. Coherency on data read */
  { NULL, NULL, "" },
};
static UnkStruct_92 D_800D3490[31] = {
  { SR_CU3, SR_CU3, "CU3" },           /* Coprocessor 3 usable */
  { SR_CU2, SR_CU2, "CU2" },           /* Coprocessor 2 usable */
  { SR_CU1, SR_CU1, "CU1" },           /* Coprocessor 1 usable */
  { SR_CU0, SR_CU0, "CU0" },           /* Coprocessor 0 usable */
  { SR_RP, SR_RP, "RP" },              /* Reduced power (quarter speed) */
  { SR_FR, SR_FR, "FR" },              /* MIPS III FP register mode */
  { SR_RE, SR_RE, "RE" },              /* Reverse endian */
  { SR_BEV, SR_BEV, "BEV" },           /* Use boot exception vectors */
  { SR_TS, SR_TS, "TS" },              /* TLB shutdown */
  { SR_SR, SR_SR, "SR" },              /* Soft reset occured */
  { SR_CH, SR_CH, "CH" },              /* Cache hit for last 'cache' op */
  { SR_CE, SR_CE, "CE" },              /* Create ECC */
  { SR_DE, SR_DE, "DE" },              /* ECC of parity does not cause error */
  { SR_IBIT8, SR_IBIT8, "IM8" },       /* bit level 8 */
  { SR_IBIT7, SR_IBIT7, "IM7" },       /* bit level 7 */
  { SR_IBIT6, SR_IBIT6, "IM6" },       /* bit level 6 */
  { SR_IBIT5, SR_IBIT5, "IM5" },       /* bit level 5 */
  { SR_IBIT4, SR_IBIT4, "IM4" },       /* bit level 4 */
  { SR_IBIT3, SR_IBIT3, "IM3" },       /* bit level 3 */
  { SR_IBIT2, SR_IBIT2, "IM2" },       /* bit level 2 */
  { SR_IBIT1, SR_IBIT1, "IM1" },       /* bit level 1 */
  { SR_KX, SR_KX, "KX" },              /* extended-addr TLB vec in kernel */
  { SR_SX, SR_SX, "SX" },              /* xtended-addr TLB vec supervisor */
  { SR_UX, SR_UX, "UX" },              /* xtended-addr TLB vec in user mode */
  { SR_KSU_MASK, SR_KSU_USR, "USR" },  /* user mode */
  { SR_KSU_MASK, SR_KSU_SUP, "SUP" },  /* supervisor mode */
  { SR_KSU_MASK, SR_KSU_KER, "KER" },  /* kernel mode */
  { SR_ERL, SR_ERL, "ERL" },           /* Error level, 1=>cache error */
  { SR_EXL, SR_EXL, "EXL" },           /* Exception level, 1=>exception */
  { SR_IE, SR_IE, "IE" },              /* interrupt enable, 1=>enable */
  { NULL, NULL, "" },         
};
static UnkStruct_92 D_800D3604[23] = {
  { FPCSR_FS, FPCSR_FS, "FS" },                       /* flush denorm to zero */
  { FPCSR_C, FPCSR_C, "C" },                          /* condition bit */
  { FPCSR_CE, FPCSR_CE, "Unimplemented operation" },  /* cause: unimplemented operation */
  { FPCSR_CV, FPCSR_CV, "Invalid operation" },        /* cause: invalid operation */
  { FPCSR_CZ, FPCSR_CZ, "Division by zero" },         /* cause: division by zero */
  { FPCSR_CO, FPCSR_CO, "Overflow" },                 /* cause: overflow */
  { FPCSR_CU, FPCSR_CU, "Underflow" },                /* cause: underflow */
  { FPCSR_CI, FPCSR_CI, "Inexact operation" },        /* cause: inexact operation */
  { FPCSR_EV, FPCSR_EV, "EV" },                       /* enable: invalid operation */
  { FPCSR_EZ, FPCSR_EZ, "EZ" },                       /* enable: division by zero */
  { FPCSR_EO, FPCSR_EO, "EO" },                       /* enable: overflow */
  { FPCSR_EU, FPCSR_EU, "EU" },                       /* enable: underflow */
  { FPCSR_EI, FPCSR_EI, "EI" },                       /* enable: inexact operation */
  { FPCSR_FV, FPCSR_FV, "FV" },                       /* flag: invalid operation */
  { FPCSR_FZ, FPCSR_FZ, "FZ" },                       /* flag: division by zero */
  { FPCSR_FO, FPCSR_FO, "FO" },                       /* flag: overflow */
  { FPCSR_FU, FPCSR_FU, "FU" },                       /* flag: underflow */
  { FPCSR_FI, FPCSR_FI, "FI" },                       /* flag: inexact operation */
  { FPCSR_RM_MASK, FPCSR_RM_RN, "RN" },               /* round to nearest */
  { FPCSR_RM_MASK, FPCSR_RM_RZ, "RZ" },               /* round to zero */
  { FPCSR_RM_MASK, FPCSR_RM_RP, "RP" },               /* round to positive infinity */
  { FPCSR_RM_MASK, FPCSR_RM_RM, "RM" },               /* round to negative infinity */
  { NULL, NULL, "" },
};
// font
static u8 D_800D3718[59 * 8] = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0,
  0x10,
  0x10,
  0,
  0,
  0x6C,
  0,
  0,
  0,
  0,
  0,
  0,
  0x24,
  0x7E,
  0x24,
  0x24,
  0x7E,
  0x24,
  0,
  0x30,
  0x7C,
  0xC0,
  0x78,
  0xC,
  0xF8,
  0x30,
  0,
  0,
  0xC6,
  0xCC,
  0x18,
  0x30,
  0x66,
  0xC6,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x38,
  0x20,
  0x20,
  0x20,
  0x20,
  0x38,
  0,
  0,
  0x1C,
  4,
  4,
  4,
  4,
  0x1C,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x30,
  0x30,
  0xFC,
  0x30,
  0x30,
  0,
  0,
  0,
  0,
  0,
  0x30,
  0x30,
  0x60,
  0,
  0,
  0,
  0,
  0,
  0xFC,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x30,
  0x30,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x7C,
  0xC6,
  0xCE,
  0xDE,
  0xF6,
  0xE6,
  0x7C,
  0,
  0x30,
  0x70,
  0x30,
  0x30,
  0x30,
  0x30,
  0x78,
  0,
  0xF8,
  0xC,
  0xC,
  0x38,
  0x60,
  0xC0,
  0xFC,
  0,
  0xF8,
  0xC,
  0xC,
  0x38,
  0xC,
  0xC,
  0xF8,
  0,
  0x1C,
  0x3C,
  0x6C,
  0xCC,
  0xFE,
  0xC,
  0xC,
  0,
  0xFC,
  0xC0,
  0xF8,
  0xC,
  0xC,
  0xC,
  0xF8,
  0,
  0x3C,
  0x60,
  0xC0,
  0xF8,
  0xCC,
  0xCC,
  0x78,
  0,
  0xFC,
  0xC,
  0x18,
  0x30,
  0x60,
  0xC0,
  0xC0,
  0,
  0x78,
  0xCC,
  0xCC,
  0x78,
  0xCC,
  0xCC,
  0x78,
  0,
  0x78,
  0xCC,
  0xCC,
  0x7C,
  0xC,
  0xC,
  0x78,
  0,
  0,
  0x10,
  0x10,
  0,
  0,
  0x10,
  0x10,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  8,
  0x10,
  0x20,
  0x10,
  8,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x20,
  0x10,
  8,
  4,
  8,
  0x10,
  0x20,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0xF8,
  0xC,
  0x7C,
  0xCC,
  0x7C,
  0,
  0xC0,
  0xC0,
  0xF8,
  0xCC,
  0xCC,
  0xCC,
  0xF8,
  0,
  0,
  0,
  0x7C,
  0xC0,
  0xC0,
  0xC0,
  0x7C,
  0,
  0xC,
  0xC,
  0x7C,
  0xCC,
  0xCC,
  0xCC,
  0x7C,
  0,
  0,
  0,
  0x78,
  0xCC,
  0xFC,
  0xC0,
  0x7C,
  0,
  0x3C,
  0x60,
  0x60,
  0xF8,
  0x60,
  0x60,
  0x60,
  0,
  0,
  0,
  0x7C,
  0xCC,
  0xCC,
  0x7C,
  0xC,
  0xF8,
  0xC0,
  0xC0,
  0xF8,
  0xCC,
  0xCC,
  0xCC,
  0xCC,
  0,
  0x30,
  0,
  0x30,
  0x30,
  0x30,
  0x30,
  0x30,
  0,
  0x18,
  0,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0xF0,
  0xC0,
  0xC0,
  0xCC,
  0xD8,
  0xF0,
  0xD8,
  0xCC,
  0,
  0x70,
  0x30,
  0x30,
  0x30,
  0x30,
  0x30,
  0x30,
  0,
  0,
  0,
  0xC6,
  0xFE,
  0xD6,
  0xC6,
  0xC6,
  0,
  0,
  0,
  0xF8,
  0xCC,
  0xCC,
  0xCC,
  0xCC,
  0,
  0,
  0,
  0x78,
  0xCC,
  0xCC,
  0xCC,
  0x78,
  0,
  0,
  0,
  0xF8,
  0xCC,
  0xCC,
  0xCC,
  0xF8,
  0xC0,
  0,
  0,
  0x7C,
  0xCC,
  0xCC,
  0xCC,
  0x7C,
  0xC,
  0,
  0,
  0xDC,
  0xE0,
  0xC0,
  0xC0,
  0xC0,
  0,
  0,
  0,
  0x7C,
  0xC0,
  0x78,
  0xC,
  0xF8,
  0,
  0x60,
  0x60,
  0xFC,
  0x60,
  0x60,
  0x60,
  0x3C,
  0,
  0,
  0,
  0xCC,
  0xCC,
  0xCC,
  0xCC,
  0x7C,
  0,
  0,
  0,
  0xCC,
  0xCC,
  0xCC,
  0x78,
  0x30,
  0,
  0,
  0,
  0xC6,
  0xC6,
  0xD6,
  0xFE,
  0xC6,
  0,
  0,
  0,
  0xC6,
  0x6C,
  0x38,
  0x6C,
  0xC6,
  0,
  0,
  0,
  0xCC,
  0xCC,
  0xCC,
  0x7C,
  0xC,
  0xF8,
  0,
  0,
  0xFC,
  0x18,
  0x30,
  0x60,
  0xFC,
  0,
};
static s32 D_800D38F0 = 0;
static s32 *D_800D38F4 = NULL;
static f32 D_800D38F8 = 0;
static f32 D_800D38FC = 0.04;
static f32 D_800D3900 = 0;
static f32 D_800D3904 = 0.03;
static f32 D_800D3908 = 0;
static f32 D_800D390C = 0.01;

static void func_8008369C(char, u32, u32, u16 *, u8, u8, u8);
static u32 func_800837FC(char *, u32, u32, u16 *, u8, u8, u8);
static void func_80083910(OSThread *);
static void func_80084390(u32, UnkStruct_92 *);  // unused
static void func_80084490(u32, char *, UnkStruct_92 *);
static void func_8008457C(void);

void debug_print_reason_routine(char *arg0, char *arg1) {
  s32 sp1C;

  if (strlen(arg0) > 40) {
    arg0[40] = 0;
  }
  if (strlen(arg1) > 40) {
    arg1[40] = 0;
  }
  for (sp1C = 0; sp1C < strlen(arg0); sp1C++) {
    if ((arg0[sp1C] > 64) && (arg0[sp1C] < 96)) {
      arg0[sp1C] += 32;  // convert to lowercase
    }
  }
  sprintf(D_801209C8, "%s\n%s\n", arg0, arg1);
  D_800D38F0 = 1;
  rmonPrintf("Reason: %s\n Routine: %s\n String: %s\n", arg0, arg1, D_801209C8);
  osWritebackDCacheAll();
  *D_800D38F4 = 0;  // (bug?) dereferencing a null pointer
}

static void func_8008369C(char arg0, u32 arg1, u32 arg2, u16 *arg3, u8 arg4, u8 arg5, u8 arg6) {
  s32 sp24;
  s32 sp20;
  s32 sp1C;
  s32 sp18;

  if (arg0 > 96) {
    arg0 -= 32;  // convert to uppercase
  }
  arg0 -= 32;
  sp24 = arg0 * 8;
  sp18 = (arg2 * 320) + arg1;
  for (sp20 = 0; sp20 < 8; sp20++) {
    for (sp1C = 0; sp1C < 8; sp1C++) {
      if (D_800D3718[sp24] & (1 << (8 - sp1C)) & 0xFFFF) {  // why "& 0xFFFF" ?
        arg3[sp18 + sp1C] = ((arg4 << 8) & 0xF800) | ((arg5 << 3) & 0x7C0) | ((arg6 >> 2) & 0x3E);
      } else {
        arg3[sp18 + sp1C] = 0xFFFE;
      }
    }
    sp18 += 320;
    sp24++;
  }
  osWritebackDCacheAll();
}

static u32 func_800837FC(char *arg0, u32 arg1, u32 arg2, u16 *arg3, u8 arg4, u8 arg5, u8 arg6) {
  char sp2F;
  u8 sp2E;
  u8 sp2D;
  u8 sp2C;

  sp2C = arg1;
  for (sp2E = 0, sp2D = 0; sp2E < strlen(arg0); sp2E++, sp2D++) {
    sp2F = arg0[sp2E];
    if (sp2F == '\n') {
      sp2D = 0xFF;
      arg2 += 9;
      arg1 = sp2C;
    } else {
      arg1 = sp2C + (sp2D * 8);
      func_8008369C(sp2F, arg1, arg2, arg3, arg4, arg5, arg6);
    }
  }
  return (arg1 << 0x10) | arg2;
}

static void func_80083910(OSThread *thd) {
  s32 sp88C;
  s32 sp884[2];  // unused
  OSMesg sp880[1];
  OSMesgQueue sp868;
  char sp68[0x800];
  s32 sp64;  // unused
  u32 sp60;
  s32 sp5C;
  s32 sp58;
  s32 sp50[2];  // unused
  s32 sp4C;
  u16 sp4A;
  u16 sp48;
  OSContPad sp30[4];
  __OSThreadContext *sp2C;
  s32 sp28;  // unused

  sp4C = 0;
  sp2C = &thd->context;
  osCreateMesgQueue(&sp868, sp880, 1);
  osSetEventMesg(OS_EVENT_SI, &sp868, (OSMesg)1);
  n64HeapStats();
  rmonPrintf("My God, That Musta Hurt!\n");
  osCreateMesgQueue(&D_801209B0, D_80120A20, 8);  // (bug?) D_80120A20 is an unallocated array
  osSpTaskYield();
  osStopThread(&scheduler.thread);
  osCreateViManager(OS_PRIORITY_VIMGR);
  if (osTvType == OS_TV_PAL) {
    osViSetMode(&osViModeTable[OS_VI_PAL_LPN1]);
  }
  if (osTvType == OS_TV_NTSC) {
    osViSetMode(&osViModeTable[OS_VI_NTSC_LPN1]);
  }
  if (osTvType == OS_TV_MPAL) {
    osViSetMode(&osViModeTable[OS_VI_MPAL_LPN1]);
  }
  osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
  osViSwapBuffer(D_801209A0);
  osViSetEvent(&D_801209B0, (OSMesg)666, 1);
  osWritebackDCacheAll();
  rmonPrintf("\nFault in thread %d:\n\n", thd->id);
  rmonPrintf("epc\t\t0x%08x\n", sp2C->pc);
  func_80084490(sp2C->cause, "cause", D_800D3340);
  func_80084490(sp2C->sr, "sr", D_800D3490);
  rmonPrintf("badvaddr\t0x%08x\n\n", sp2C->badvaddr);
  rmonPrintf("at 0x%016llx v0 0x%016llx v1 0x%016llx\n", sp2C->at, sp2C->v0, sp2C->v1);
  rmonPrintf("a0 0x%016llx a1 0x%016llx a2 0x%016llx\n", sp2C->a0, sp2C->a1, sp2C->a2);
  rmonPrintf("a3 0x%016llx t0 0x%016llx t1 0x%016llx\n", sp2C->a3, sp2C->t0, sp2C->t1);
  rmonPrintf("t2 0x%016llx t3 0x%016llx t4 0x%016llx\n", sp2C->t2, sp2C->t3, sp2C->t4);
  rmonPrintf("t5 0x%016llx t6 0x%016llx t7 0x%016llx\n", sp2C->t5, sp2C->t6, sp2C->t7);
  rmonPrintf("s0 0x%016llx s1 0x%016llx s2 0x%016llx\n", sp2C->s0, sp2C->s1, sp2C->s2);
  rmonPrintf("s3 0x%016llx s4 0x%016llx s5 0x%016llx\n", sp2C->s3, sp2C->s4, sp2C->s5);
  rmonPrintf("s6 0x%016llx s7 0x%016llx t8 0x%016llx\n", sp2C->s6, sp2C->s7, sp2C->t8);
  rmonPrintf("t9 0x%016llx gp 0x%016llx sp 0x%016llx\n", sp2C->t9, sp2C->gp, sp2C->sp);
  rmonPrintf("s8 0x%016llx ra 0x%016llx\n\n", sp2C->s8, sp2C->ra);
  func_80084490(sp2C->fpcsr, "fpcsr", D_800D3604);
  sp60 = D_80120A28;
  sp5C = 1;
  sp4A = 0x400;  // D_JPAD / CONT_DOWN
  for (sp88C = 0; sp88C < 0x12C00; sp88C++) {
    D_801209A0[sp88C] = 0xFFFE;
  }

  for (;;) {
    D_800D38F8 += D_800D38FC;
    D_800D3900 += D_800D3904;
    D_800D3908 += D_800D390C;
    if (D_800D38F8 >= 0.8) {
      D_800D38F8 = 0.8;
      D_800D38FC *= -1;
    }
    if (D_800D38F8 <= 0.1) {
      D_800D38F8 = 0.1f;
      D_800D38FC *= -1;
    }
    if (D_800D3900 >= 0.8) {
      D_800D3900 = 0.8;
      D_800D3904 *= -1;
    }
    if (D_800D3900 <= 0.1) {
      D_800D3900 = 0.1;
      D_800D3904 *= -1;
    }
    if (D_800D3908 >= 0.8) {
      D_800D3908 = 0.8;
      D_800D390C *= -1;
    }
    if (D_800D3908 <= 0.1) {
      D_800D3908 = 0.1;
      D_800D390C *= -1;
    }
    sprintf(sp68, "You have found the Secret Cheat.");
    D_80120A28 = func_800837FC(sp68, 30, 20, D_801209A0, 0, 0, 0);
    sprintf(sp68, "Enter:");
    D_80120A28 = func_800837FC(sp68, 30, 30, D_801209A0, 0, 0, 0);
    sprintf(sp68, "2FAST4U");
    D_80120A28 = func_800837FC(sp68, 80, 30, D_801209A0, 0xFF * D_800D38F8, 0xFF * D_800D3900, 0xFF * D_800D3908);
    sprintf(sp68, "in the Single Player Name entry");
    D_80120A28 = func_800837FC(sp68, 30, 40, D_801209A0, 0, 0, 0);
    sprintf(sp68, "Screen for Intense game play.");
    D_80120A28 = func_800837FC(sp68, 30, 50, D_801209A0, 0, 0, 0);
    sprintf(sp68, "please power off the control");
    D_80120A28 = func_800837FC(sp68, 30, 80, D_801209A0, 0, 0, 0);
    sprintf(sp68, "deck and then power on the");
    D_80120A28 = func_800837FC(sp68, 30, 90, D_801209A0, 0, 0, 0);
    sprintf(sp68, "control deck to continue.");
    D_80120A28 = func_800837FC(sp68, 30, 100, D_801209A0, 0, 0, 0);
    sp58 = sp5C;
    sp5C = 0;
    osSetTime(0);

    if ((sp5C == 0) && (sp4C == 0)) {
      osContStartReadData(&sp868);
      osRecvMesg(&sp868, sp880, OS_MESG_BLOCK);
      osContGetReadData(&sp30[0]);
      sp48 = sp4A = sp30[0].button;
      sp4C = 0;
    }
  }
}

// unused
static void func_80084390(u32 arg0, UnkStruct_92 *arg1) {
  s32 sp12C;
  char sp2C[256];

  sp12C = 1;
  if (D_800D38F0 == 1) {
    sprintf(sp2C, "%s", D_801209C8);
  } else {
    while (arg1->unk0 != 0) {
      if ((arg1->unk0 & arg0) == arg1->unk4) {
        sprintf(sp2C, "%s\n", arg1->unk8);
      }
      arg1++;
    }
  }
  D_80120A28 = func_800837FC(sp2C, D_80120A28 >> 0x10, (D_80120A28 & 0xFF) + 2, D_801209A0, 200, 0, 0);
}

static void func_80084490(u32 arg0, char *arg1, UnkStruct_92 *arg2) {
  s32 sp1C;

  sp1C = 1;
  rmonPrintf("%s\t\t0x%08x ", arg1, arg0);
  rmonPrintf("<");
  while (arg2->unk0 != 0) {
    if ((arg2->unk0 & arg0) == arg2->unk4) {
      if (sp1C != 0) {
        sp1C = 0;
      } else {
        rmonPrintf(",");
      }
      rmonPrintf("%s", arg2->unk8);
    }
    arg2++;
  }
  rmonPrintf(">\n");
}

static void func_8008457C(void) {
  OSMesg sp1C;

  osSetEventMesg(OS_EVENT_FAULT, &D_80120980, (OSMesg)0x10);
  D_80120A30 = 0;

  for (;;) {
    osRecvMesg(&D_80120980, &sp1C, OS_MESG_BLOCK);
    if (D_8012099C != NULL) {
      D_8012099C();
      osSetThreadPri(&D_801203D0, 1);
      for (;;) {}
    }

    D_80120A2C = __osGetCurrFaultedThread();
    if (D_80120A2C != NULL) {
      func_80083910(D_80120A2C);
      for (;;) {}
    }
  }
}

void func_80084630(void (*arg0)(void), u16 *arg1, u16 arg2, u16 arg3) {
  D_8012099C = arg0;
  osCreateMesgQueue(&D_80120980, D_80120998, 1);
  // (bug) stack parameter should have been:
  // D_80120580 + 0x400/sizeof(u64)
  osCreateThread(&D_801203D0, 2, (void (*)(void *))func_8008457C, NULL, D_80120580 + (0x400/sizeof(u64))/sizeof(u64), 50);
  osStartThread(&D_801203D0);
  D_801209A0 = arg1;
  D_801209A4 = &arg1[arg2 * arg3];
  D_801209A8 = arg2;
  D_801209AA = arg3;
}
