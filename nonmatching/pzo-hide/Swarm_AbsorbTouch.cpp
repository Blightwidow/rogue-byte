#include "sly2.h"
struct SWARM { char pad[0x188]; int absorbDamage; int absorbFlag; void *pexpl; };
struct RIDER { QW pos; };
struct WKR { SWARM *src; char pad4[4]; void *target; int grftak; int ndamage; char pad[0xC]; QW pos; QW vel; char pad2[0x20]; };
extern "C" {
QW PosLoWorld(void *);
RIDER *Swarm_PriderNearest(SWARM *, QW);
int PaloAbsorbWkr(void *);
void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(void *, unsigned, void *, QW, QW, float, float);
void Swarm_SetRiderState(SWARM *, RIDER *, int);
extern QW g_2a2dd0;
}

extern "C" void Swarm_AbsorbTouch(SWARM *pswarm, void *ptarget)
{
    if (ptarget == 0)
        return;
    if (pswarm->absorbDamage == 0)
        return;
    RIDER *prider = Swarm_PriderNearest(pswarm, PosLoWorld(ptarget));
    WKR wkr;
    memset(&wkr, 0, 0x60);
    wkr.src = pswarm;
    wkr.target = ptarget;
    wkr.grftak = 0x100;
    wkr.ndamage = -pswarm->absorbDamage;
    wkr.pos = prider->pos;
    if (PaloAbsorbWkr(&wkr) == 0) {
        pswarm->absorbFlag = 0;
        return;
    }
    if (pswarm->pexpl != 0) {
        ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(pswarm->pexpl, 4, 0, g_2a2dd0, prider->pos, 0.0f, 0.0f);
    }
    Swarm_SetRiderState(pswarm, prider, 2);
    pswarm->absorbFlag = 0;
}
