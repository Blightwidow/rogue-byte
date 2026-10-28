#include "sly2.h"
struct LEASE { int pad; LEASE *next; };
struct SET { int pad; int *items; };
struct POOL { char pad[0xE0]; SET *set; int pad4; LEASE *head; };
extern "C" int IcloneFromLease(POOL *, LEASE *);
extern "C" void func_00200F58(void *, int, int, int *);

void *func_001CB360(void *result, POOL *pool)
{
    int items[32];
    unsigned count = 0;
    LEASE *lease = pool->head;
    int *out;
    if (lease) {
        out = items;
        do {
            int index = IcloneFromLease(pool, lease);
            count = count + 1;
            *out = pool->set->items[index];
            lease = lease->next;
            out = out + 1;
            if (!lease)
                break;
        } while (count < 0x20);
    }
    func_00200F58(result, count, 0x2002, items);
    return result;
}
