#include "sly2.h"
struct OBSTACLE {
    char pad[0xE8];
    int cpos;
    char pad2[0x1EC - 0xEC];
    QW *aplane;
};
extern "C" void Obstacle_UpdatePlanes(OBSTACLE *);
extern "C" void *func_002564B8(void *);
extern "C" int FObstacleContainsPos(OBSTACLE *pobstacle, QW pos)
{
    struct L { QW a; QW b; QW pos; QW plane; } l;
    l.pos = pos;
    Obstacle_UpdatePlanes(pobstacle);
    for (int iedge = 0; iedge < pobstacle->cpos - 1; iedge++) {
        asm("lqc2 vf1, %1\n\tsqc2 vf1, %0" : "=m" (l.plane) : "m" (pobstacle->aplane[iedge]));
        func_002564B8(&l.a);
        func_002564B8(&l.b);
        QW bits; /* lane 0 of the distance, moved to an FP register */
        float dist;
        asm("lqc2 vf1, %2\n\tlqc2 vf3, %3\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %1, vf1\n\tmtc1 %1, %0" : "=f" (dist), "=r" (bits) : "m" (l.plane), "m" (l.pos));
        asm("sqc2 vf2, %0" : "=m" (l.b));
        asm("sqc2 vf1, %0" : "=m" (l.a));
        if (0.0f < dist)
            return 0;
    }
    return 1;
}
