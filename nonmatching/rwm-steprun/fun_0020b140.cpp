#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
extern "C" QW PosLoWorld(void *);
extern "C" void PhitfxSpawn_156548(void *, QW, void *, char **);
extern "C" char *PhitfxSpawn(void *, QW, void *);
extern "C" char B_003DD490[];
extern "C" float D_002C3DB8;
extern "C" float g_2dded0;
void func_0020B140(char *guard, char *target)
{
    QW posTarget = PosLoWorld(target);
    char *slot = 0;
    char *fx;
    if (*(void **)(guard + 0xE60)) {
        PhitfxSpawn_156548(*(void **)(guard + 0xE60), PosLoWorld(guard), guard, &slot);
        fx = slot;
    } else {
        char *sw = B_003DD490;
        slot = PhitfxSpawn(*(void **)(sw + 0x4030), PosLoWorld(guard), guard);
        fx = slot;
    }
    float dt = D_002C3DB8;
    *(QW *)(slot + 0x30) = posTarget;
    *(char **)(slot + 0x44) = target;
    *(int *)(slot + 0x54) = 4;
    *(float *)(guard + 0xF44) = g_2dded0 + dt;
}
