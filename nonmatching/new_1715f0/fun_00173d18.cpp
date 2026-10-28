#include "sly2.h"
struct Plo { char pad0[0x28]; unsigned long flags; };
struct Point { int kind; int oid; Plo *plo; };
struct Slot { Plo *actor; float tSpawn; float tFree; Point *point; int kindRelease; char pad14[0xC]; QW posRelease; };
struct Spawner { char pad0[0x5C]; int slotCount; Slot *slots; };
extern "C" float D_FLT_002BE5DC;
extern "C" float g_2dded0;
static inline int FFar(QW *from, QW *to)
{
    float length;
    int chain;
    asm("lqc2 vf1, %1" : "=r" (chain) : "m" (*from));
    asm("lqc2 vf2, %1" : "+r" (chain) : "m" (*to));
    asm("vsub.xyzw vf1, vf1, vf2" : "+r" (chain));
    asm("vmul.xy vf1, vf1, vf1" : "+r" (chain));
    asm("vaddy.x vf1, vf1, vf1y" : "+r" (chain));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (length) : "r" (chain));
    return D_FLT_002BE5DC < length;
}
extern "C" void func_00173928(Spawner *, Slot *, long, long);
extern "C" void func_00173D18(Spawner *spawner, QW posFocus)
{
    int index;
    for (index = 0; index < spawner->slotCount; index++) {
        Slot *slot = (Slot *)((char *)spawner->slots + index * 0x30);
        Plo *actor = slot->actor;
        if (actor == 0) {
            if (slot->kindRelease == 1) {
                if (FFar(&slot->posRelease, &posFocus)) {
                    slot->kindRelease = 0;
                    slot->tFree = g_2dded0;
                }
            }
        } else if (*(int *)((char *)actor + 0x330) != 0) {
            func_00173928(spawner, slot, 1, 0);
        } else if (((actor->flags >> 60) & 1) == 0 || ((slot->point->plo->flags >> 60) & 1) == 0) {
            func_00173928(spawner, slot, 0, 0);
        } else {
            float seen = *(float *)((char *)actor + 0x84);
            slot->tSpawn = seen < slot->tSpawn ? slot->tSpawn : seen;
        }
    }
}
