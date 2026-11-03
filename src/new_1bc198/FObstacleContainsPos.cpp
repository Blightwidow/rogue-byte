// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct OBSTACLE {
    char pad[0xE8];
    int cpos;
    char pad2[0x1EC - 0xEC];
    QW *aplane;
};
extern "C" void Obstacle_UpdatePlanes(OBSTACLE *);
extern "C" void *func_002564B8(void *);

/* lane 0 of a vector as a float */
static inline float FloatX(QW v)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(v));
    return f;
}

extern "C" int FObstacleContainsPos(OBSTACLE *pobstacle, QW pos)
{
    Obstacle_UpdatePlanes(pobstacle);
    for (int iedge = 0; iedge < pobstacle->cpos - 1; iedge++) {
        QW a, b;
        QW plane = pobstacle->aplane[iedge];
        func_002564B8(&a);
        func_002564B8(&b);
        QW dist4, one;
        asm("vmul.xyz %0, %2, %3\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddaz.x ACC, %1, %0z\n\tvmsubw.x %0, %1, %0w"
            : "=j"(dist4), "=j"(one) : "j"(plane), "j"(pos));
        b = one;
        a = dist4;
        if (0.0f < FloatX(dist4))
            return 0;
    }
    return 1;
}
