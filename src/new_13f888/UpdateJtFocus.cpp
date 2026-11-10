#include "sly2.h"
struct GUARD { char pad[0xFE0]; GUARD *pnext; };
#include "jt.h"
extern "C" int func_00208E70(GUARD *, JT *, float *);
extern "C" GUARD *B_003E1444;
extern "C" const float RO_FLT_002A4D18;

extern "C" void UpdateJtFocus(JT *pjt)
{
    if (pjt->fFocusBusy != 0) return;
    float sBest = RO_FLT_002A4D18;
    GUARD *pguardBest = 0;
    GUARD *pguardNear = 0;
    int prioBest = -1;
    int prioNear = -1;
    float sNear = sBest;
    for (GUARD *pguard = B_003E1444; pguard != 0; pguard = pguard->pnext) {
        float sa[2];
        int prio = func_00208E70(pguard, pjt, &sa[1]);
        float s = sa[1];
        if (s < sNear) {
            sNear = s;
            prioNear = prio;
            pguardNear = pguard;
        }
        if (prioBest < prio || (prio == prioBest && s < sBest)) {
            sBest = s;
            prioBest = prio;
            pguardBest = pguard;
        }
    }
    pjt->SetFocus(prioNear, pguardNear, prioBest, pguardBest);
}
