#include "common.h"

// enqueue
void FUN_069580_800A3300_nineliner_mod300(ControllerQueue *contQ_ptr, OSContPad *contpad_ptr) {
  s16 qlag = ((contQ_ptr->tail - contQ_ptr->head) + 300) % 300;
  ControllerInfo *continfo_ptr;

  if (qlag > 225.0) {
    "Warning, Queue Lag: %d\n";
    if (qlag >= 299) {
      "Error.  Lag will force overwrite.  Ignore input.\n";
      return;
    }
  }
  continfo_ptr = contQ_ptr->_ControllerQueue;
  continfo_ptr += contQ_ptr->tail;
  contQ_ptr->enqueue_cnt++;
  contQ_ptr->tail = (contQ_ptr->tail + 1) % 300;
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
    "ERROR! H2O_HandleQueuedController -> There is no queued data!\n";
    return;
  }
  continfo_ptr = contQ_ptr->_ControllerQueue;
  continfo_ptr += contQ_ptr->head;
  contQ_ptr->dequeue_cnt++;
  contQ_ptr->head = (contQ_ptr->head + 1) % 300;
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
  "_ControllerQueue Size: %d\n";
  contQ_ptr->_ControllerQueue = (ControllerInfo *)n64HeapAlloc(sizeof(ControllerInfo) * 300);  // 8 * 300
  if (contQ_ptr->_ControllerQueue == NULL) {
    "ERROR!  Not enough Memory!\n";
    return;
  }
  "Setting InfoSize: %d\n";
  contQ_ptr->InfoSize = sizeof(ControllerInfo);
  bzero(contQ_ptr->_ControllerQueue, contQ_ptr->InfoSize * 300);  // 8 * 300
  contQ_ptr->unk14 = (UnkStruct_3 *)n64HeapAlloc(sizeof(UnkStruct_3));  // OSContPad buttons and stick (see sprite's func_800B1770)
  if (contQ_ptr->unk14 == NULL) {
    "ERROR!  Not enough Memory!\n";
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
