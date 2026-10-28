// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct EXPL;
struct RIDER { char pad[0]; QW pos; };
struct SWARM { char pad[0x188]; int dhpTouch; int fTouchQueued; EXPL *pexpl; };
struct WKR { SWARM *pswarm; int pad4; void *pother; int flags; int dhp; char pad14[0xC]; QW pos; char pad30[0x30]; };
extern "C" QW PosLoWorld(void *);
extern "C" RIDER *Swarm_PriderNearest(SWARM *, QW);
extern "C" void *PaloAbsorbWkr(WKR *);
extern "C" void Swarm_SetRiderState(SWARM *, RIDER *, int);
extern "C" void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(EXPL *, unsigned, void *, QW, QW, float, float);
extern "C" QW g_2a2dd0;
void *memset(void *, int, unsigned int);
void Swarm_AbsorbTouch(SWARM *pswarm, void *ploOther)
{
    register void *plo asm("$16") = ploOther;
    if (plo != 0 && pswarm->dhpTouch != 0) {
        RIDER *prider = Swarm_PriderNearest(pswarm, PosLoWorld(plo));
        WKR wkr;
        memset(&wkr, 0, sizeof(wkr));
        wkr.pother = plo;
        wkr.pswarm = pswarm;
        wkr.pos = prider->pos;
        wkr.flags = 0x100;
        wkr.dhp = -pswarm->dhpTouch;
        if (PaloAbsorbWkr(&wkr) != 0) {
            if (pswarm->pexpl != 0)
                ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(pswarm->pexpl, 4, 0, g_2a2dd0, prider->pos, 0.0f, 0.0f);
            Swarm_SetRiderState(pswarm, prider, 2);
        }
        pswarm->fTouchQueued = 0;
    }
}
