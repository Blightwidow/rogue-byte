// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "alloc.h"
#include "sw.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct NODE {
    u8 unknown_0x0[0x20];
    /* 0x20 */ QW posCenter;
    /* 0x30 */ f32 sRadius;
    /* 0x34 */ struct ALO *paloFirst;
    u8 unknown_0x38[0x8];
    /* 0x40 */ NODE *pnext;
};

struct ALO {
    u8 unknown_0x0[0x60];
    /* 0x60 */ ALO *paloNext;
};

extern "C" {
void *PvAllocStackImpl__Fi(ALLOCREQ *preq);
void UpdateSwAaox__FP2SW(SW *psw);
void func_00133E30(SW *psw);

void IntersectSwBoundingSphere(SW *psw, QW posCenter, int (*pfnFilter)(void *, ALO *), void *pvContext, int *pcalo, float sRadius, ALO ***papalo)
{
    int calo = 0;
    ALLOCREQ req;
    req.cb = 0x400;
    req.cbAlign = 0x10;
    ALO **apalo = (ALO **)PvAllocStackImpl__Fi(&req);
    func_00133E30(psw);
    UpdateSwAaox__FP2SW(psw);
    for (NODE *pnode = psw->pnodeFirst; pnode != 0; pnode = pnode->pnext) {
        float sRadiusNode = pnode->sRadius;
        QW dpos = VectorSub(posCenter, pnode->posCenter);
        float sDistanceSquared = LaneX(SquaredLength(dpos));
        float sReach = sRadius + sRadiusNode;
        float sReachSquared = sReach * sReach;
        if (sReachSquared < sDistanceSquared) continue;
        for (ALO *palo = pnode->paloFirst; palo != 0; palo = palo->paloNext) {
            if ((pfnFilter == 0 || pfnFilter(pvContext, palo) != 0) && calo < 0x100) {
                apalo[calo] = palo;
                calo++;
            }
        }
    }
    *papalo = apalo;
    *pcalo = calo;
}
}
