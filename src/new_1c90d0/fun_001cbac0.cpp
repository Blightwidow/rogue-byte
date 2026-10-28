#include "sly2.h"
struct CRV { char pad[0xE4]; int closed; };
struct JT { char pad[0x218]; QW *ppos; };
extern "C" {
void FindCrvClosestPointAll(CRV *, QW, void *, QW *, void *, void *, float *);
float SMaxCrv(CRV *);
}

void func_001CBAC0(CRV *pcrv, JT *pjt, float *ps)
{
    QW posClosest;
    FindCrvClosestPointAll(pcrv, *pjt->ppos, 0, &posClosest, 0, 0, ps);
    if (pcrv->closed == 0) {
        float sMax = SMaxCrv(pcrv) - 50.0f;
        float s = *ps;
        if (s < 50.0f)
            s = 50.0f;
        else if (sMax < s)
            s = sMax;
        *ps = s;
    }
}
