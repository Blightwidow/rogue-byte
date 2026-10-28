#include "sly2.h"
struct GUARD { char pad[0xFE0]; GUARD *pnext; };
struct VT { char pad[0x2F8]; short delta; short index; void (*fn)(void *, int, GUARD *, int, GUARD *); };
struct JT { char pad0[0xC]; VT *vptr; char pad1[0x10E0 - 0x10]; int fBusy; };
extern "C" int func_00208E70(GUARD *, JT *, float *);
extern "C" GUARD *B_003E1444;
extern "C" const float RO_FLT_002A4D18;

extern "C" void UpdateJtFocus(JT *pjt)
{
    if (pjt->fBusy != 0) return;
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
    VT *vt = pjt->vptr;
    vt->fn((char *)pjt + vt->delta, prioNear, pguardNear, prioBest, pguardBest);
}
