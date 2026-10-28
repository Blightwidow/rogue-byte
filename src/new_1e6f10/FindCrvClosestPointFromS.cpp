#include "sly2.h"
struct CRV; struct CONSTR;
extern "C" float UFromCrvS(CRV *, float);
extern "C" void FindCrvClosestPointFromU(CRV *, QW, float, CONSTR *, QW *, QW *, float *, float *);
extern "C" void FindCrvClosestPointFromS(CRV *pcrv, QW pos, float s, CONSTR *pconstr, QW *pposClosest, QW *pnormTangentClosest, float *pu, float *ps)
{
    float u = UFromCrvS(pcrv, s);
    FindCrvClosestPointFromU(pcrv, pos, u, pconstr, pposClosest, pnormTangentClosest, pu, ps);
}
