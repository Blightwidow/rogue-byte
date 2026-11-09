struct PHYS {
    char pad0[0x80];
    float gravityX;
    float gravityY;
    float gravityZ;
    char pad1[0x14];
    int torque;
    char pad2[0x1C];
    int force;
};
#include "so.h"
extern "C" void func_001F3590(SO *so)
{
    float *gravity = &so->pphys->gravityX;
    gravity[0] = 0.0f;
    gravity[2] = -1750.0f;
    gravity[1] = 0.0f;
    so->pphys->force = 3;
    so->pphys->torque = 3;
}
