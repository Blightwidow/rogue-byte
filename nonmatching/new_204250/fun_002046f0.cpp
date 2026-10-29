#include "sly2.h"
extern "C" QW PosLoWorld(char *);
extern "C" void SetStepRadTargetDir(char *, QW);
extern "C" void func_002046F0(char *a, char *b)
{
    QW first = PosLoWorld(b);
    QW p;
    asm volatile("sq %1, %0" : "=m"(p) : "r"(first));
    QW q = PosLoWorld(a);
    QW r;
    int fence, fence2;
    asm volatile("lqc2 vf1, %1" : "=r"(fence) : "m"(p));
    int fence3;
    asm("qmtc2.ni %1, vf2" : "=r"(fence3) : "r"(q));
    asm("vsub.xyzw vf1, vf1, vf2" : "=r"(fence2) : "r"(fence), "r"(fence3));
    asm("qmfc2.ni %0, vf1" : "=r"(r) : "r"(fence2));
    SetStepRadTargetDir(a, r);
}
