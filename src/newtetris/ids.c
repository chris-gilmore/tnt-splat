#include "common.h"

static void FUN_800507e4_twoliner(Ids *, u32);

void Ids_Init(Ids *ids, u32 max_ids) {
  register Id *id_ptr;
  register s32 i;

  ids->max_ids = max_ids;
  ids->next_id = 0;
  ids->list = (Id *)n64HeapAlloc(max_ids * sizeof(Id));
  id_ptr = ids->list;
  for (i = max_ids; i > 0; i--, id_ptr++) {
    id_ptr->cnt = 0;
  }
}

void Ids_Deinit(Ids *ids) {
  ids->max_ids = 0;
  ids->next_id = 0;
  n64HeapUnalloc((void *)ids->list);
}

u32 can_run_out_of_ids(Ids *ids) {
  register Id *id_ptr;
  register s32 i;  // unused
  register u32 id;

  id = ids->next_id;
  id_ptr = ids->list + id;
  while (id_ptr->cnt != 0) {
    id++;
    id_ptr++;
    if (ids->max_ids == id) {
      id_ptr = ids->list;
      id = 0;
    }
    if (ids->next_id == id) {
      debug_print_reason_routine("Ids:", "out of IDs");
    }
  }
  ids->next_id = (id + 1) % ids->max_ids;
  return id;
}

static void FUN_800507e4_twoliner(Ids *ids, u32 id) {
  register Id *id_ptr = ids->list + id;

  id_ptr->cnt = 0;
  ids->next_id = id;
}

void FUN_80050800_oneliner(Ids *ids, u32 id) {
  register Id *id_ptr = ids->list + id;

  id_ptr->cnt++;
}

void FUN_80050820_oneliner(Ids *ids, u32 id, u32 c) {
  register Id *id_ptr = ids->list + id;

  id_ptr->cnt += c;
}

void FUN_80050840_fiveliner(Ids *ids, u32 id) {
  register Id *id_ptr = ids->list + id;

  id_ptr->cnt--;
  if (id_ptr->cnt == 0) {
    FUN_800507e4_twoliner(ids, id);
  }
}

void FUN_800508a8_fiveliner(Ids *ids, u32 id, u32 c) {
  register Id *id_ptr = ids->list + id;

  if (c >= id_ptr->cnt) {
    id_ptr->cnt = 0;
    ids->next_id = id;
  } else {
    id_ptr->cnt -= c;
  }
}

void FUN_800508ec_fifteen_liner_allocs_heap(Ids *dest_ids, Ids *src_ids) {
  register Id *dest_id_ptr;
  register Id *src_id_ptr;
  register s32 max_ids;

  if (dest_ids->max_ids != src_ids->max_ids) {
    n64HeapUnalloc((void *)dest_ids->list);
    dest_ids->max_ids = src_ids->max_ids;
    dest_ids->next_id = 0;
    dest_ids->list = (Id *)n64HeapAlloc(dest_ids->max_ids);
  }
  dest_id_ptr = dest_ids->list;
  src_id_ptr = src_ids->list;
  for (max_ids = dest_ids->max_ids; max_ids > 0; max_ids--) {
    *dest_id_ptr++ = *src_id_ptr++;
  }
}
