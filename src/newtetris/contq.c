#include "common.h"

#ifndef H2O_DEBUG
  #define H2O_DEBUG_PRINT1(f_) (f_)
  #define H2O_DEBUG_PRINT2(f_, a_) (f_)
#else
  #define H2O_DEBUG_PRINT1(f_) rmonPrintf((f_))
  #define H2O_DEBUG_PRINT2(f_, a_) rmonPrintf((f_), (a_))
#endif

#ifndef H2O_ControllerQueueSize
  #define H2O_ControllerQueueSize 300
#endif

// enqueue
void FUN_069580_800A3300_nineliner_mod300(ControllerQueue *contQ_ptr, OSContPad *contpad_ptr) {
  s16 qlag = ((contQ_ptr->tail - contQ_ptr->head) + H2O_ControllerQueueSize) % H2O_ControllerQueueSize;
  ControllerInfo *continfo_ptr;

  if (qlag > 0.75 * H2O_ControllerQueueSize) {
    H2O_DEBUG_PRINT2("Warning, Queue Lag: %d\n", qlag);
    if (qlag >= H2O_ControllerQueueSize - 1) {
      H2O_DEBUG_PRINT1("Error.  Lag will force overwrite.  Ignore input.\n");
      return;
    }
  }

  continfo_ptr = contQ_ptr->_ControllerQueue;
  continfo_ptr += contQ_ptr->tail;
  contQ_ptr->enqueue_cnt++;
  contQ_ptr->tail = (contQ_ptr->tail + 1) % H2O_ControllerQueueSize;
  continfo_ptr->button = contpad_ptr->button;
  continfo_ptr->stick_x = contpad_ptr->stick_x;
  continfo_ptr->stick_y = contpad_ptr->stick_y;
}

// dequeue
void func_800A33E4(ControllerQueue *contQ_ptr) {
  s16 qlen = func_800A3534(contQ_ptr);
  ControllerInfo *continfo_ptr;
  OSContPad contpad;

  if (qlen <= 0) {
    H2O_DEBUG_PRINT1("ERROR! H2O_HandleQueuedController -> There is no queued data!\n");
    return;
  }

  continfo_ptr = contQ_ptr->_ControllerQueue;
  continfo_ptr += contQ_ptr->head;
  contQ_ptr->dequeue_cnt++;
  contQ_ptr->head = (contQ_ptr->head + 1) % H2O_ControllerQueueSize;
  contpad.button = continfo_ptr->button;
  contpad.stick_x = continfo_ptr->stick_x;
  contpad.stick_y = continfo_ptr->stick_y;
  func_800B1770(contQ_ptr->unk14, &contpad);
}

void func_800A3460(ControllerQueue *contQ_ptr) {
  contQ_ptr->head = 0;
  contQ_ptr->tail = 0;
  contQ_ptr->dequeue_cnt = 0;
  contQ_ptr->enqueue_cnt = 0;
  bzero(contQ_ptr->_ControllerQueue, contQ_ptr->InfoSize);
  func_800B1A7C(contQ_ptr->unk14);
}

void FUN_069580_800A34A8_tenliner_allocs_heap(ControllerQueue *contQ_ptr) {
  bzero(contQ_ptr, sizeof(ControllerQueue));
  H2O_DEBUG_PRINT2("_ControllerQueue Size: %d\n", H2O_ControllerQueueSize);
  contQ_ptr->_ControllerQueue = (ControllerInfo *)n64HeapAlloc(sizeof(ControllerInfo) * H2O_ControllerQueueSize);
  if (contQ_ptr->_ControllerQueue == NULL) {
    H2O_DEBUG_PRINT1("ERROR!  Not enough Memory!\n");
    return;
  }

  H2O_DEBUG_PRINT2("Setting InfoSize: %d\n", sizeof(ControllerInfo));
  contQ_ptr->InfoSize = sizeof(ControllerInfo);
  bzero(contQ_ptr->_ControllerQueue, contQ_ptr->InfoSize * H2O_ControllerQueueSize);
  contQ_ptr->unk14 = (UnkStruct_3 *)n64HeapAlloc(sizeof(UnkStruct_3));  // OSContPad buttons and stick (see sprite's func_800B1770)
  if (contQ_ptr->unk14 == NULL) {
    H2O_DEBUG_PRINT1("ERROR!  Not enough Memory!\n");
    return;
  }

  func_800B1A7C(contQ_ptr->unk14);  // init for buttons and stick
}

UnkStruct_3 *func_800A352C(ControllerQueue *contQ_ptr) {
  return contQ_ptr->unk14;
}

// get queue length
s16 func_800A3534(ControllerQueue *contQ_ptr) {
  return contQ_ptr->enqueue_cnt - contQ_ptr->dequeue_cnt;
}
