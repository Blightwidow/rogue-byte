// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRV { char pad0[0xE8]; int ccv; float *mpicvu; };
extern "C" void EvaluateCrvFromU(CRV *, float, QW *, QW *);
extern "C" float SFromCrvU(CRV *, float);
extern "C" const float RO_FLT_002A813C;

extern "C" void bevy_player_p5_target_1e7410(CRV *pcrv, float (*pfnMeasure)(void *, float), void *pvContext,
                                             QW *ppos, QW *pnormTangent, float *pu, float *ps)
{
    float uBest = 0.0f;
    float gBest = RO_FLT_002A813C;
    for (int icv = 0; icv < pcrv->ccv; icv++) {
        float u = pcrv->mpicvu[icv];
        float g = pfnMeasure(pvContext, u);
        if (g < gBest) {
            gBest = g;
            uBest = u;
        }
    }
    if (ppos != 0 || pnormTangent != 0)
        EvaluateCrvFromU(pcrv, uBest, ppos, pnormTangent);
    if (pu != 0)
        *pu = uBest;
    if (ps != 0)
        *ps = SFromCrvU(pcrv, uBest);
}
