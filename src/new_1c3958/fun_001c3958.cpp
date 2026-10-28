#include "sly2.h"
struct Crv { char pad[0xE4]; int closed; };
extern "C" QW PosLoWorld(void *);
extern "C" void FindCrvClosestPointAll(Crv *, QW, void *, int, int, int, float *);
extern "C" float SMaxCrv(Crv *);

void func_001C3958(Crv *crv, void *lo, float *ps)
{
    FindCrvClosestPointAll(crv, PosLoWorld(lo), 0, 0, 0, 0, ps);
    if (crv->closed == 0) {
        float hi = SMaxCrv(crv) - 35.0f;
        float value = *ps;
        float result;
        if (value < 100.0f)
            result = 100.0f;
        else if (hi < value)
            result = hi;
        else
            result = value;
        *ps = result;
    }
}
