#include "sly2.h"
struct Actor { char pad0[0xE74]; void *target; int mode; char pad0xE7C[0x16C]; unsigned flags; };
struct Beh { char pad0[0x10]; Actor *actor; };
extern "C" QW PosLoWorld(void *);
extern "C" QW func_00172760(Beh *);
extern "C" int func_00172658(Beh *beh)
{
    Actor *actor = beh->actor;
    QW save;
    int chain;
    float distTarget, distGoal;
    if ((actor->flags & 2) == 0 || actor->mode == 2)
        return 1;
    void *target = actor->target;
    if (target != 0) {
    QW posA = PosLoWorld(target);
    asm("qmtc2.ni %0, vf1" : : "r" (posA));
    asm("sqc2 vf1, %0" : "=m" (save));
    QW posB = PosLoWorld(beh->actor);
    asm("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (posB));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (save));
    asm("vsub.xyzw vf1, vf1, vf2" : "+r" (chain));
    asm("vmul.xy vf1, vf1, vf1" : "+r" (chain));
    asm("vaddy.x vf1, vf1, vf1y" : "+r" (chain));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (distTarget) : "r" (chain));
    QW posC = func_00172760(beh);
    asm("qmtc2.ni %0, vf1" : : "r" (posC));
    asm("sqc2 vf1, %0" : "=m" (save));
    QW posD = PosLoWorld(beh->actor);
    asm("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (posD));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (save));
    asm("vsub.xyzw vf1, vf1, vf2" : "+r" (chain));
    asm("vmul.xy vf1, vf1, vf1" : "+r" (chain));
    asm("vaddy.x vf1, vf1, vf1y" : "+r" (chain));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (distGoal) : "r" (chain));
    float limit = distTarget + 50.0f;
    asm("nop");

        if (distGoal < limit) return 1;
    }
    return 0;
}
