/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CRV;
struct PATHZONE;
extern "C" float g_2c0abc;
extern "C" float SWrapCrv(CRV *, float);
extern "C" void GetPathPosFromS(CRV *, void *, int, float);
extern "C" int FPosInPathzone(PATHZONE *, QW, int);
int FFindCrvSInPathzone(CRV *pcrv, PATHZONE *ppathzone, float *psFound, int fSafe, float s, float sRange)
{
    struct { QW posMinus; QW posPlus; } l;
    float ds = 0.0f;
    if (0.0f < sRange) {
        do {
            float sWrapped = SWrapCrv(pcrv, s - ds);
            GetPathPosFromS(pcrv, &l.posMinus, 0, sWrapped);
            if (!FPosInPathzone(ppathzone, l.posMinus, fSafe)) {
                sWrapped = SWrapCrv(pcrv, s + ds);
                GetPathPosFromS(pcrv, &l.posPlus, 0, sWrapped);
                if (!FPosInPathzone(ppathzone, l.posPlus, fSafe))
                    goto next;
            }
            if (psFound)
                *psFound = sWrapped;
            return 1;
        next:
            ds += g_2c0abc;
        } while (ds < sRange);
    }
    return 0;
}
