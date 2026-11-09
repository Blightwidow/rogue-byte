#include "types.h"
extern "C" void func_001CC168(void *, QW, void *, float *);
extern "C" float Carry_SDistStartCurves(char *probe)
{
    float dist;
    func_001CC168(*(void **)probe, *(QW *)(probe + 0x10), 0, &dist);
    return dist;
}
