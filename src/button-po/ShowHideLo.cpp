#include "lo.h"
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void FadeAloIn(void *, float);
extern "C" void FadeAloOut(void *, float);
LO *ShowHideLo(void *sw, int show, int oid, void *ctx, float dt)
{
    LO *lo = (LO *)PloFindSwObject_thunk(sw, 4, oid, ctx);
    if (lo) {
        if (dt != 0.0f && FIsBasicDerivedFrom(lo, 0x30)) {
            if (show) FadeAloIn(lo, dt);
            else FadeAloOut(lo, dt);
        } else {
            if (show) lo->Add();
            else lo->Remove();
        }
    }
    return lo;
}
