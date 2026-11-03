#include "sly2.h"
struct Actor { char pad0[0xE74]; void *target; int mode; char pad0xE7C[0x16C]; unsigned flags; };
struct Beh { char pad0[0x10]; Actor *actor; };
extern "C" QW PosLoWorld(void *);
extern "C" QW func_00172760(Beh *);
static inline float DistanceXY(QW from, QW to)
{
    QW delta;
    float distance;
    asm("vsub.xyzw %0, %1, %2" : "=j" (delta) : "j" (from), "j" (to));
    asm("vmul.xy %0, %0, %0\n\tvaddy.x %0, %0, %0y" : "+j" (delta));
    asm("vsqrt Q, %0x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "+j" (delta));
    asm("qmfc2.ni %0, %1" : "=r" (distance) : "j" (delta));
    return distance;
}
extern "C" int func_00172658(Beh *beh)
{
    Actor *actor = beh->actor;
    if ((actor->flags & 2) == 0 || actor->mode == 2)
        return 1;
    void *target = actor->target;
    if (target != 0) {
        QW save;
        float distTarget;
        {
            QW posTarget = PosLoWorld(target);
            asm("sqc2 %1, %0" : "=m" (save) : "j" (posTarget));
            distTarget = DistanceXY(save, PosLoWorld(beh->actor));
        }
        float distGoal;
        {
            QW posGoal = func_00172760(beh);
            asm("sqc2 %1, %0" : "=m" (save) : "j" (posGoal));
            distGoal = DistanceXY(save, PosLoWorld(beh->actor));
        }
        if (distGoal < distTarget + 50.0f)
            return 1;
    }
    return 0;
}
