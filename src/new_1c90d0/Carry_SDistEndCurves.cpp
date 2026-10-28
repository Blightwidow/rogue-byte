#include "sly2.h"
struct CARRYPROBE { void *pcarry; char pad[0xC]; QW posFlat; };
extern "C" void func_001CC1F8(void *carry, float u, QW pos, void *unused, float *out);
extern "C" float Carry_SDistEndCurves(void *probe, float u)
{
    CARRYPROBE *pprobe = (CARRYPROBE *)probe;
    float dist;
    func_001CC1F8(pprobe->pcarry, u, pprobe->posFlat, 0, &dist);
    return dist;
}
