#include "common.h"

static N64Heap *n64Heap = NULL;
static s32 D_800D3194 = 0; // unused
static s32 n64HeapAllocCumulative = 0;

static u8 *n64HeapStart;
static u8 *n64HeapEnd;

static u8    *n64HeapAllocAppend(s32); // unused
static s32    n64HeapGetTotalMemUsed(void); // unused
static s32    n64HeapGetNumFragments(void); // unused
static s32    n64HeapGetTotalHandles(void); // unused
static void   n64HeapResetAllocCumulative(void); // unused
static s32    n64HeapGetAllocCumulative(void); // unused

void n64HeapInit(u8 *base, s32 len) {
  register s32 baseAligned = (s32)base;

  baseAligned = (baseAligned + 0xF) & ~0xF;
  len = (len + 0xF) & ~0xF;

  n64Heap = (N64Heap *)baseAligned;
  n64Heap->pBlock = NULL;
  n64Heap->size = len - sizeof(N64Heap);
  n64Heap->next = NULL;
  n64Heap->prev = NULL;

  n64HeapStart = base;
  n64HeapEnd = base + len;
}

u8 *n64HeapAlloc(s32 size) {
  s32 bytes;
  s32 unused_bytes;
  N64Heap *handle = n64Heap;
  N64Heap *new_handle;

  bytes = (size + 0xF) & ~0xF;
  n64HeapAllocCumulative += bytes;
  while (handle) {
    if ((handle->pBlock == NULL) && (handle->size >= bytes)) {
      handle->pBlock = (u8 *)((s32)handle + sizeof(N64Heap));
      unused_bytes = handle->size - bytes;
      if (unused_bytes > sizeof(N64Heap)) {
        unused_bytes -= sizeof(N64Heap);
        if (FALSE);
        new_handle = (N64Heap *)((s32)handle + sizeof(N64Heap) + bytes);
        new_handle->size = unused_bytes;
        new_handle->pBlock = NULL;
        new_handle->prev = handle;
        new_handle->next = handle->next;
        handle->next = new_handle;
        if (new_handle->next) {
          new_handle->next->prev = new_handle;
        }
        handle->size = bytes;
      }
      return handle->pBlock;
    }
    handle = handle->next;
  }
  rmonPrintf("Out of memory\n");
  n64HeapStats();
  debug_print_reason_routine("OUT OF MEMORY", "n64HeapAlloc");
  return NULL;
}

static u8 *n64HeapAllocAppend(s32 size) {
  s32 bytes;
  s32 bytes_plus_header;
  N64Heap *handleA = n64Heap;
  N64Heap *handleB;

  bytes = (size + 0xF) & ~0xF;
  bytes_plus_header = bytes + sizeof(N64Heap);

  /* walk heap until last handle is reached */
  while (handleA) {
    handleB = handleA;
    handleA = handleA->next;
  }
  /* after above, handleB points to last handle */

  /* if last handle's block is *used*, return zero */
  if (handleB->pBlock) {
    return NULL;
  }

  /* if we got this far, the last handle's block is unused (free) */
  /* if requested data bytes is greater than size of that last block, return zero */
  if (bytes > handleB->size) {
    return NULL;
  }

  /* check if size of that last block is exactly equal to requested data bytes */
  /* if so then allocate the block and return its address */
  if (handleB->size == bytes) {
    handleB->pBlock = (u8 *)((s32)handleB + sizeof(N64Heap));
    handleB->next = NULL; /* is this necessary?  wasn't this already NULL if we got this far? */
    return handleB->pBlock;
  }

  /* if we got this far, then size of that last block is strictly greater than the requested data bytes */
  /* and we have enough room to create a new handle, which becomes the new last handle on the heap */
  handleA = (N64Heap *)((s32)n64HeapEnd - bytes_plus_header);
  handleA->pBlock = (u8 *)((s32)handleA + sizeof(N64Heap));
  handleA->size = bytes;
  handleA->prev = handleB;
  handleA->next = NULL;
  handleB->next = handleA;
  return handleA->pBlock;
}

void n64HeapUnalloc(u8 *pBlock) {
  register N64Heap *handle = n64Heap;
  register N64Heap *tmpHandle;

  while (handle) {
    if (handle->pBlock == pBlock) {
      tmpHandle = handle->prev;
      handle->pBlock = NULL;
      while (tmpHandle) {
        if (tmpHandle->pBlock) {
          break;
        }
        tmpHandle->pBlock = NULL;
        tmpHandle->size += handle->size + sizeof(N64Heap);
        tmpHandle->next = handle->next;
        if (tmpHandle->next) {
          tmpHandle->next->prev = tmpHandle;
        }
        handle = tmpHandle;
        tmpHandle = tmpHandle->prev;
      }
      tmpHandle = handle->next;
      while (tmpHandle) {
        if (tmpHandle->pBlock) {
          break;
        }
        tmpHandle->pBlock = NULL;
        handle->size += tmpHandle->size + sizeof(N64Heap);
        handle->next = tmpHandle->next;
        if (handle->next) {
          handle->next->prev = handle;
        }
        handle = tmpHandle;
        tmpHandle = tmpHandle->next;
      }
      return;
    } else {
      handle = handle->next;
    }
  }
}

static s32 n64HeapGetTotalMemUsed(void) {
  register N64Heap *handle = n64Heap;
  s32 sum = 0;

  while (handle) {
    sum += handle->size + sizeof(N64Heap);
    handle = handle->next;
  }
  return sum;
}

s32 n64HeapGetTotalMemFree(void) {
  register N64Heap *handle = n64Heap;
  register s32 sum = 0;

  while (handle) {
    if (handle->pBlock == NULL) {
      sum += handle->size - sizeof(N64Heap);
    }
    handle = handle->next;
  }
  return sum;
}

s32 n64HeapGetMaxFreeBlockSize(void) {
  register s32 max = 0;
  register N64Heap *handle = n64Heap;

  while (handle) {
    if ((handle->pBlock == NULL) && (handle->size) > max) {
      max = handle->size;
    }
    handle = handle->next;
  }
  return max - sizeof(N64Heap);
}

static s32 n64HeapGetNumFragments(void) {
  register s32 cnt = 0;
  register N64Heap *handle = n64Heap;

  while (handle) {
    if ((handle->pBlock == NULL) && handle->next) {
      cnt += 1;
    }
    handle = handle->next;
  }
  return cnt;
}

static s32 n64HeapGetTotalHandles(void) {
  register s32 cnt = 0;
  register N64Heap *handle = n64Heap;

  while (handle) {
    handle = handle->next;
    cnt += 1;
  }
  return cnt;
}

void n64HeapStats(void) {
  register N64Heap *handle = n64Heap;
  s32 data_mem = 0;
  s32 hanlde_mem = 0; // heehee
  s32 handles = 0;

  rmonPrintf("Heap Walk statistics\n");
  while (handle) {
    rmonPrintf("  size   :%d\n", handle->size);
    rmonPrintf("  pBlock :0x%08X\n", handle->pBlock);
    rmonPrintf("  next   :0x%08X\n", handle->next);
    rmonPrintf("  prev   :0x%08X\n", handle->prev);
    data_mem += handle->size;
    hanlde_mem += sizeof(N64Heap);
    handles += 1;
    handle = handle->next;
  }
  rmonPrintf("Handles      :%d\n", handles);
  rmonPrintf("Hanlde Mem   :%d\n", hanlde_mem);
  rmonPrintf("Data   Mem   :%d\n", data_mem);
  rmonPrintf("Efficiency   :%.2f%%\n", (f32)data_mem * 100.0 / (data_mem + hanlde_mem));
  data_mem += hanlde_mem;
  rmonPrintf("Total mem    :%d(0x%08X)\n", data_mem, data_mem);
}

static void n64HeapResetAllocCumulative(void) {
  n64HeapAllocCumulative = 0;
}

static s32 n64HeapGetAllocCumulative(void) {
  return n64HeapAllocCumulative;
}
