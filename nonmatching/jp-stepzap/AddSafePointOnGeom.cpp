#include "sly2.h"
struct GEOM { int a; void *owner; char pad[8]; unsigned long grf; };
struct SP { void *plo; int pad4; GEOM *pgeom; float tStamp; QW pos; };
struct SPL { void *pjt; int count; int pad[2]; SP items[1]; };
extern float g_2dded0;
void *memmove(void *, const void *, unsigned int);
static inline float LaneNop(QW q) { float f; asm volatile("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }

void AddSafePointOnGeom(SPL *list, GEOM *pgeom, QW pos)
{
    SP *slot;
    SP *history;
    int found = 1;
    for (; found < list->count; found++) {
        history = &list->items[found];
        if (pgeom == history->pgeom) {
            QW bits;
            asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "m" (pos), "m" (history->pos));
            float dist = LaneNop(bits);
            if (dist < 50.0f) {
                if (found != 1) {
                    SP saved = *history;
                    memmove(&list->items[2], &list->items[1], (found - 1) * 32);
                    list->items[1] = saved;
                }
                break;
            }
        }
    }
    if (found < list->count) {
        slot = &list->items[0];
    } else {
        unsigned count = list->count;
        if (count < 0x20)
            list->count = count + 1;
        slot = &list->items[0];
        memmove(&list->items[1], slot, list->count * 32 - 32);
    }
    asm volatile("" : : "r" (found));
    SP *first = slot;
    memset(slot, 0, 0x20);
    if (pgeom != 0) {
        list->items[0].plo = pgeom->owner;
        first->pgeom = pgeom;
        pgeom->grf |= 1UL << 51;
    }
    list->items[0].pos = pos;
    first->tStamp = g_2dded0;
}
