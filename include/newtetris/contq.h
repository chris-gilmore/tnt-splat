#ifndef _CONTQ_H_
#define _CONTQ_H_

typedef struct {
  /* 0x0 */ u32   button;
  /* 0x4 */ s16   stick_x;  /* -80 <= stick_x <= 80 */
  /* 0x6 */ s16   stick_y;  /* -80 <= stick_y <= 80 */
} ControllerInfo; // 0x8 bytes

typedef struct {
  /* 0x0  */ s16              tail;
  /* 0x2  */ s16              head;
  /* 0x4  */ s16              InfoSize;
  /* 0x8  */ s32              enqueue_cnt;
  /* 0xC  */ s32              dequeue_cnt;
  /* 0x10 */ ControllerInfo  *_ControllerQueue;
  /* 0x14 */ Controller      *unk14;
} ControllerQueue; // 0x18 bytes

extern void         FUN_069580_800A3300_nineliner_mod300(ControllerQueue *, OSContPad *);
extern void         func_800A33E4(ControllerQueue *);
extern void         func_800A3460(ControllerQueue *);
extern void         FUN_069580_800A34A8_tenliner_allocs_heap(ControllerQueue *);
extern Controller  *func_800A352C(ControllerQueue *);
extern s16          func_800A3534(ControllerQueue *);

#endif /* !_CONTQ_H_ */
