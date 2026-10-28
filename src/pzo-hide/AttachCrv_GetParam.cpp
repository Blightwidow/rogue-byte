#include "sly2.h"
struct Crv { char pad[0xE4]; int closed; };
struct Jt { char pad[0x218]; QW *pole; };
extern "C" void FindCrvClosestPointAll(Crv *, QW, void *, QW *, void *, void *, float *);
extern "C" float SMaxCrv(Crv *);

extern "C" void AttachCrv_GetParam(Crv *crv, Jt *jt, float *arc)
{
    QW closest;
    FindCrvClosestPointAll(crv, *jt->pole, 0, &closest, 0, 0, arc);
    if (crv->closed == 0) {
        float maxArc = SMaxCrv(crv);
        float lo = 30.0f;
        float value = *arc;
        float hi = maxArc - lo;
        if (value < lo)
            value = lo;
        else if (hi < value)
            value = hi;
        *arc = value;
    }
}
