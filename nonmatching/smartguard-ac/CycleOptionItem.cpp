#include "sly2.h"
struct ITEM1AFFC0 { int kind; int pad; int count; int *kinds; char pad2[0xC]; int flags; };
extern char B_003D9ED0;
extern "C" void PauseMenu_ApplyOption(char *, ITEM1AFFC0 *);

extern "C" void CycleOptionItem(ITEM1AFFC0 *item)
{
    int index = 0;
    int count = item->count;
    if (count > 0) {
        int *kinds = item->kinds;
        int kind = item->kind;
        int next;
        if (kind == kinds[0]) {
            index = 1;
            next = index % count;
        } else {
        again:
            index++;
            if (index < item->count) {
                if (kind != kinds[index])
                    goto again;
                index++;
                next = index % item->count;
            } else {
                goto done;
            }
        }
        item->kind = kinds[next];
    }
done:
    PauseMenu_ApplyOption(&B_003D9ED0, item);
    item->flags |= 2;
}
