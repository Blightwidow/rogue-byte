#include "sly2.h"
// lane 0 of a QW into an FP register (mtc1 reads the low word)
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }

static inline QW DistanceSquared(QW a, QW b)
{
    QW result;
    QW one;
    asm("vsub.xyzw %0, %2, %3\n\tvmul.xyz %0, %0, %0\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z"
        : "=j"(result), "=j"(one) : "j"(a), "j"(b));
    return result;
}

extern "C" char *Swarm_PriderNearest(char *self, QW pos)
{
    float best = 3.402823466e+38f;
    char *nearest = 0;
    int count = *(int *)(self + 0x1C8);
    int index;
    for (index = 0; index < count; index++) {
        char *node = *(char **)(self + index * 0x30 + 0x1DC);
        if (node != 0) {
            QW target = pos;
            do {
                float dist = LaneX(DistanceSquared(*(QW *)node, target));
                if (dist < best) {
                    best = dist;
                    nearest = node;
                }
                node = *(char **)(node + 0x60);
            } while (node != 0);
        }
    }
    return nearest;
}
