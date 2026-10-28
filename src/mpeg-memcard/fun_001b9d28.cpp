#include "sly2.h"
struct LO;
struct LOV {
    char pad[0xE8];
    short delta;
    short idx;
    void (*fn)(void *, QW);
};
struct LO {
    char pad[0xC];
    LOV *vptr;
    char pad2[0x18];
    unsigned long grf;
};
struct MURRAY { char pad[0x1AD0]; LO *plo; void *paseg; };
extern "C" int FGadgetAcquired(int);
extern "C" void ApplyAseg(void *, void *, float, float, int, void *);
void func_001B9D28(MURRAY *pmurray, QW pos)
{
    if (FGadgetAcquired(0x11) == 0)
        return;
    LO *plo = pmurray->plo;
    unsigned long bit = (plo->grf >> 60) & 1;
    if (bit)
        return;
    plo->vptr->fn((char *)plo + plo->vptr->delta, pos);
    ApplyAseg(pmurray->paseg, pmurray->plo, 0.0f, 1.0f, 0, 0);
}
