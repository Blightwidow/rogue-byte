#include "sly2.h"
struct LO;
struct GoalFollowCrv { char pad0[0x10]; LO *plo; char pad14[0x3C - 0x14]; void *pcrv; char pad40[0x64 - 0x40]; float sEnd; char pad68[0xB0 - 0x68]; QW posEnd; };
extern "C" QW PosLoWorld(LO *);
extern "C" int GoalFollowCrv_FAtEnd(GoalFollowCrv *goal)
{
    if (goal->pcrv == 0)
        return 0;
    QW pos = PosLoWorld(goal->plo);
    asm("qmtc2.ni %0, vf3" : : "r" (pos));
    float sEnd = goal->sEnd;
    asm("lqc2 vf2, %0" : : "m" (goal->posEnd));
    int close = 1;
    asm("vsub.xyzw vf1, vf3, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    QW lane;
    asm("qmfc2.ni %0, vf1" : "=r" (lane));
    float distance;
    asm("mtc1 %1, %0\n\tnop" : "=f" (distance) : "r" (lane)); // lane 0, with the coprocessor-move hazard nop
    if (distance <= sEnd) {
    } else {
        close = 0;
    }
    return close;
}
