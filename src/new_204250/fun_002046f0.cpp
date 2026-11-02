#include "sly2.h"
extern "C" QW PosLoWorld(char *);
extern "C" void SetStepRadTargetDir(char *, QW);
extern "C" void func_002046F0(char *a, char *b)
{
    QW first = PosLoWorld(b);
    QW p = first;
    QW q = PosLoWorld(a);
    QW r;
    int fence, fence2;
    asm volatile("lqc2 vf1, %1" : "=r"(fence) : "m"(p));
    asm("qmtc2.ni %2, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r"(r) : "r"(fence), "r"(q));
    SetStepRadTargetDir(a, r);
}
