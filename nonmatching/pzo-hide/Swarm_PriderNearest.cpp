#include "sly2.h"
struct Slot { char *head; char pad[0x2C]; };
struct Obj { char pad[0x1C8]; int count; char pad2[0x10]; Slot slots[1]; };
extern "C" char *Swarm_PriderNearest(char *self, QW pos)
{
    float best = 3.402823466e+38f;
    char *nearest = 0;
    int count = *(int *)(self + 0x1C8);
    int index;
    for (index = 0; index < count; index++) {
        char *node = *(char **)(self + index * 0x30 + 0x1DC);
        for (; node != 0; node = *(char **)(node + 0x60)) {
            float dist;
            asm volatile("qmtc2.ni %0, vf3" : : "r" (pos));
            asm volatile("lqc2 vf1, 0(%0)" : : "r" (node));
            asm volatile("vsub.xyzw vf1, vf1, vf3\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            asm volatile("qmfc2.ni %0, vf1" : "=r" (dist));
            if (dist < best) {
                best = dist;
                nearest = node;
            }
        }
    }
    return nearest;
}
