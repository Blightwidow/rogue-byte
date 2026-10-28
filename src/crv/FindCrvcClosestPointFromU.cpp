// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CONSTR;
struct CRV { char pad0[0xE4]; int fClosed; int ccv; float *mpicvu; };
struct CRVMC { CRV *pcrv; CONSTR *pconstr; int pad[2]; QW pos; };
extern "C" float GMeasureCrvU(CRVMC *, float);
extern "C" float UWrapCrv(CRV *, float);
extern "C" float SFromCrvU(CRV *, float);
extern "C" void EvaluateCrvFromU(CRV *, float, QW *, QW *);
void MinimizeRange(float (*)(void *, float), void *, float, float, float, float, float *, float *);
extern "C" const float RO_FLT_002A8130;
extern "C" const float RO_FLT_002A8134;

extern "C" void FindCrvcClosestPointFromU(CRV *pcrv, QW pos, CONSTR *pconstr, float u, QW *pposClosest,
                                          QW *pnormTangentClosest, float *pu, float *ps)
{
    float (*pfnMeasure)(void *, float) = (float (*)(void *, float))GMeasureCrvU;
    CRVMC measure;
    float uClosest;
    measure.pcrv = pcrv;
    measure.pconstr = pconstr;
    measure.pos = pos;
    float uFirst = pcrv->mpicvu[0];
    float duStep = (pcrv->mpicvu[1] - uFirst) * 0.1f;
    float uMin = pcrv->fClosed ? RO_FLT_002A8130 : uFirst;
    float uMax = pcrv->fClosed ? RO_FLT_002A8134 : pcrv->mpicvu[pcrv->ccv - 1];
    MinimizeRange(pfnMeasure, &measure, u, duStep, uMin, uMax, &uClosest, 0);
    uClosest = UWrapCrv(pcrv, uClosest);
    if (pposClosest != 0 || pnormTangentClosest != 0)
        EvaluateCrvFromU(pcrv, uClosest, pposClosest, pnormTangentClosest);
    if (pu != 0)
        *pu = uClosest;
    if (ps != 0)
        *ps = SFromCrvU(pcrv, uClosest);
}
