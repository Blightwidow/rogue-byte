#include "sly2.h"
struct CRV; struct CONSTR;
struct CRVMC { CRV *pcrv; CONSTR *pconstr; int pad[2]; QW pos; };
extern "C" void EvaluateCrvFromU(CRV *, float, QW *, QW *);
extern "C" QW ApplyConstr(CONSTR *, QW);
extern "C" float GMeasureCrvU(CRVMC *pcrvmc, float u)
{
    QW posCurve;
    int bits;
    EvaluateCrvFromU(pcrvmc->pcrv, u, &posCurve, 0);
    CONSTR *pconstr = pcrvmc->pconstr;
    if (pconstr == 0) {
        asm("lqc2 vf1, %0" : : "m" (pcrvmc->pos));
        asm("lqc2 vf2, %0" : : "m" (posCurve));
        asm("vsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z");
        asm("qmfc2.ni %0, vf1" : "=r" (bits));
    } else {
        QW diff;
        asm("lqc2 vf2, %0" : : "m" (pcrvmc->pos));
        asm("lqc2 vf1, %0" : : "m" (posCurve));
        asm("vsub.xyzw vf3, vf1, vf2");
        asm("qmfc2.ni %0, vf3" : "=r" (diff));
        QW delta = ApplyConstr(pconstr, diff);
        asm("qmtc2.ni %0, vf4" : : "r" (delta));
        asm("vmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        asm("qmfc2.ni %0, vf1" : "=r" (bits));
    }
    return *(float *)&bits;
}
