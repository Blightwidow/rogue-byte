#include "sly2.h"
extern "C" int FInsideCmFrustrum(char *self, QW point, QW radius)
{
    int status;
    asm volatile("vmaxw.xyzw vf4, vf0, vf0w\n\tlqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tqmtc2.ni %4, vf5\n\tqmtc2.ni %5, vf6\n\tvmulax.xyzw ACC, vf2, vf5x\n\tvmadday.xyzw ACC, vf1, vf5y\n\tvmaddaz.xyzw ACC, vf3, vf5z\n\tvmsubax.xyzw ACC, vf4, vf6x\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tcfc2.ni %0, vi17"
        : "=r" (status) : "m" (*(QW *)(self + 0xC0)), "m" (*(QW *)(self + 0xA0)), "m" (*(QW *)(self + 0xB0)), "r" (point), "r" (radius));
    return (status ^ 0xF0) == 0;
}
