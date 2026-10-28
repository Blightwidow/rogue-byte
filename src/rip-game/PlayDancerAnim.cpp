#include "sly2.h"
struct Dancer { char pad[0x408]; char handle[4]; };
extern "C" void ApplyAsegToHandle(float, float, void *, Dancer *, unsigned, char *);
void PlayDancerAnim(Dancer *dancer, void *aseg, unsigned flags)
{
    ApplyAsegToHandle(0.0f, 1.0f, aseg, dancer, flags | 1, dancer->handle);
}
