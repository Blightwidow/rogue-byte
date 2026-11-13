#include "ps2inline.h"
#include "vu0inline.h"
#include "sly2.h"

struct GEOM { int a; void *owner; char pad[8]; unsigned long grf; };
struct SP { void *plo; int pad4; GEOM *pgeom; float tStamp; VECTOR pos; };
struct SPL { void *pjt; int count; int pad[2]; SP items[1]; };
extern float g_2dded0;
extern "C" void *memmove(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);

extern "C" void AddSafePointOnGeom(SPL *list, GEOM *pgeom, QW pos)
{
    SP *slot;
    SP *history;
    int found = 1;
    for (; found < list->count; found++) {
        history = &list->items[found];
        if (pgeom == history->pgeom) {
            float distance = LaneX(SqrtX(SquaredLength(VectorSub(pos, *(QW *)&list->items[found].pos))));
            if (distance < 50.0f) {
                if (found != 1) {
                    SP saved = *history;
                    memmove(&list->items[2], &list->items[1], (found - 1) * 32);
                    list->items[1] = saved;
                }
                break;
            }
        }
    }
    if (found >= list->count) {
        unsigned count = list->count;
        if (count < 0x20)
            list->count = count + 1;
        memmove(&list->items[1], &list->items[0], list->count * 32 - 32);
    }
    slot = &list->items[0];
    SP *first = slot;
    memset(slot, 0, 0x20);
    if (pgeom != 0) {
        list->items[0].plo = pgeom->owner;
        first->pgeom = pgeom;
        pgeom->grf |= 1UL << 51;
    }
    *(QW *)&list->items[0].pos = pos;
    first->tStamp = g_2dded0;
}
