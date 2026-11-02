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
        QW spill;
        spill = murray->pos = PosLoWorld(target);
        QW current = PosLoWorld(murray);
        asm volatile("lqc2 vf1, %0" : : "m" (spill));
        QW diff;
        asm("qmtc2.ni %1, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (diff) : "r" (current));
        SetStepRadTargetDir(murray, diff);
    }
}
