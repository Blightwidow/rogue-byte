#include "vu0inline.h"
#include "ps2inline.h"
#include "sly2.h"

struct Plo { char pad0[0x28]; unsigned long flags; };
struct Point { int kind; int oid; Plo *plo; };
struct Slot { Plo *actor; float tSpawn; float tFree; Point *point; int kindRelease; char pad14[0xC]; QW posRelease; };
struct Spawner { char pad0[0x5C]; int slotCount; Slot *slots; };
extern "C" float D_FLT_002BE5DC;
struct g_2dded0_T { float v; };
extern "C" g_2dded0_T g_2dded0;

/* squared distance in the xy plane compared with the constant: the vector difference, then the xy square and its sqrt */
static inline int FFar(QW from, QW to)
{
    return D_FLT_002BE5DC < LaneX(SqrtX(SquaredLengthXy(VectorSub(from, to))));
}

extern "C" void func_00173928(Spawner *, Slot *, long, long);
extern "C" void func_00173D18(Spawner *spawner, QW posFocus)
{
    int index;
    for (index = 0; index < spawner->slotCount; index++) {
        Slot *slot = spawner->slots + index;
        Plo *actor = slot->actor;
        if (actor == 0) {
            if (slot->kindRelease == 1) {
                if (FFar(slot->posRelease, posFocus)) {
                    slot->kindRelease = 0;
                    slot->tFree = g_2dded0.v;
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
