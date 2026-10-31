#include "sly2.h"
extern "C" {
QW PosLoWorld(void *);
void SetMurrayState(void *, int);
void SetStepRadTargetDir(void *, QW);
}
struct Murray_1B7A78 { char pad[0x1420]; QW pos; };
extern "C" void StartMurrayThrow(Murray_1B7A78 *murray, void *target)
{
    SetMurrayState(murray, 7);
    if (target != 0) {
        QW spill = PosLoWorld(target);
        murray->pos = spill;
        QW current = PosLoWorld(murray);
        int dummy;
        asm volatile("lqc2 vf1, %0\n\tqmtc2.ni %1, vf2" : : "m" (spill), "r" (current));
        asm volatile("vsub.xyzw vf1, vf1, vf2" : "=r" (dummy));
        QW diff;
        asm volatile("qmfc2.ni %0, vf1" : "=r" (diff) : "r" (dummy));
        SetStepRadTargetDir(murray, diff);
    }
}
