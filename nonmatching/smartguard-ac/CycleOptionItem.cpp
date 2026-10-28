#include "sly2.h"
struct ITEM { int kind; int pad; int count; int *kinds; char pad2[0xC]; int flags; };
extern char B_003D9ED0;
extern "C" void PauseMenu_ApplyOption(char *, ITEM *);

extern "C" void CycleOptionItem(ITEM *item)
{
    int index = 0;
    if (item->count > 0) {
        int *kinds = item->kinds;
        int kind = item->kind;
        if (kind == kinds[0]) {
            item->kind = kinds[1 % item->count];
        } else {
            for (;;) {
                index++;
                if (!(index < item->count))
                    break;
                if (kind == kinds[index]) {
                    item->kind = kinds[(index + 1) % item->count];
                    break;
                }
            }
        }
    }
    PauseMenu_ApplyOption(&B_003D9ED0, item);
    item->flags |= 2;
}
