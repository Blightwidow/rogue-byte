/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef struct Slot {
    int field00;
    int field04;
    int field08;
    int field0C;
    unsigned int flags;
    struct Slot *self;
    int generation;
    int pad1C[9];
} Slot;
typedef struct SlotPool {
    int counter;
    Slot *slots;
    int count;
} SlotPool;
extern int func_00239450();
extern int func_002394A0();
Slot *func_00236C28(SlotPool *pool)
{
    int index;
    int generation;
    Slot *slot;
    func_00239450();
    slot = pool->slots;
    for (index = 0; index < pool->count; index++, slot++) {
        if (!(slot->flags & 1)) {
            slot->flags = (index << 16) | 5;
            pool->counter++;
            if (pool->counter == 1) {
                pool->counter++;
                generation = 1;
            } else {
                generation = pool->counter;
            }
            slot->self = slot;
            slot->generation = generation;
            func_002394A0();
            return slot;
        }
    }
    func_002394A0();
    return 0;
}
