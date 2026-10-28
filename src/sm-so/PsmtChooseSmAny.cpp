#include "sly2.h"
struct SMT { int u0; int a; int b; unsigned flags; int pad[2]; };
struct SM { char pad[0x58]; int count; SMT *items; };
extern "C" SMT *PsmtChooseRandom(SM *, int, SMT **);

SMT *PsmtChooseSmAny(SM *sm, unsigned mask, int target)
{
    SMT *list[64];
    int n = 0;
    for (int i = 0; i < sm->count; i++) {
        SMT *item = &sm->items[i];
        unsigned flags = item->flags;
        if (flags & mask) {
            if (item->a == target || ((flags & 1) && item->b == target))
                list[n++] = item;
        }
    }
    if (n == 0)
        return 0;
    return PsmtChooseRandom(sm, n, list);
}
