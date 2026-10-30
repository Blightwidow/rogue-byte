/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SLOT { short delta; short index; void (*fn)(void *, int, void *, QW, QW, QW); };
struct VT { char pad[0x290]; SLOT slot; };
struct GUARD { char pad0[0xC]; VT *vt; char pad1[0x218 - 0x10]; QW *pdir; char pad2[0xF80 - 0x21C]; int mode; void *target; float s; int pad3; void *from; };
extern "C" {
extern QW g_2a2da0;
void func_001F4FA8(void);
void GetPathPosFromS(void *, QW *, QW *, float);
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
void func_00209C88(GUARD *guard)
{
    QW bufA;
    QW bufB;
    QW posA;
    QW posB;
    SLOT *slot;
    char *self;
    func_001F4FA8();
    switch (guard->mode) {
    case 0:
        GetPathPosFromS(guard->target, &bufA, &bufB, guard->s);
        slot = &guard->vt->slot;
        slot->fn((char *)guard + slot->delta, 0x22, guard->target, bufA, bufB, *guard->pdir);
        break;
    case 1:
        slot = &guard->vt->slot;
        GetPathPosFromS(guard->target, &bufA, &bufB, guard->s);
        self = (char *)guard + slot->delta;
        posA = bufA;
        posB = bufB;
        goto common;
    case 2:
        slot = &guard->vt->slot;
        self = (char *)guard + slot->delta;
        posA = PosLoWorld(guard->target);
        posB = *PmatLoWorld(guard->target);
    common: {
        QW posFrom = PosLoWorld(guard->from);
        slot->fn(self, 7, guard->target, posA, posB, posFrom);
        break;
    }
    case 3:
        slot = &guard->vt->slot;
        self = (char *)guard + slot->delta;
        posA = PosLoWorld(guard->target);
        slot->fn(self, 7, guard->target, posA, g_2a2da0, *guard->pdir);
        break;
    }
}
}
