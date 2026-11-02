#include "sly2.h"
struct CRef { int tagk; union { int n; float g; QW *pv; }; };
extern "C" CRef *func_001227D0(CRef *prefReturn, int carg, CRef *aref)
{
    QW *pvec = aref[0].pv;
    int result;
    int tag = 0x16;
    asm("lqc2 vf1, %0\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : : "m" (*pvec));
    prefReturn->tagk = tag;
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (result));
    prefReturn->n = result;
    return prefReturn;
}
