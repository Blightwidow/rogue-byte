// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "sw.h"

/* as in src/sensor-bbmark/PoxaAllocSw_file.cpp: an axis entry, its sort key the first float behind ps */
struct OBR { int obrf; void *poxa; void *ps; };

struct SwPoxNode;
struct SwWorld;
extern "C" void UpdateSwPox(SwWorld *, SwPoxNode *, SwPoxNode *, s32); /* extern */
extern "C" void *memmove(void *, const void *, unsigned int);

/* the flag at 0x3CCC (not yet a field of SW in include/sw.h) asks for the axis lists to be sorted again */
#define SW_AAOX_DIRTY(psw) (*(int *)((char *)(psw) + 0x3CCC))

/* Insertion sort of the three axis lists by key; every pair of entries of different owners that changes
   order is passed to UpdateSwPox. */
extern "C" void UpdateSwAaox__FP2SW(SW *psw)
{
    if (SW_AAOX_DIRTY(psw) == 0)
        return;
    SW_AAOX_DIRTY(psw) = 0;
    if (psw->cobr == 0)
        return;
    int remaining;
    for (int axis = 0; axis < 3; axis++) {
        OBR *current = psw->aobr[axis];
        float highest = *(float *)current->ps;
        OBR *first = current;
        current++;
        for (remaining = psw->cobr; --remaining > 0;) {
            float key = *(float *)current->ps;
            if (highest <= key) {
                highest = key;
            } else {
                OBR *scan = current - 1;
                for (; scan >= first; scan--) {
                    if (*(float *)scan->ps <= key)
                        break;
                    if (current->obrf != scan->obrf)
                        UpdateSwPox((SwWorld *)psw, (SwPoxNode *)current->poxa, (SwPoxNode *)scan->poxa, 0);
                }
                scan++;
                OBR saved = *current;
                memmove(scan + 1, scan, (current - scan) * sizeof(OBR));
                *scan = saved;
            }
            current++;
        }
    }
}
