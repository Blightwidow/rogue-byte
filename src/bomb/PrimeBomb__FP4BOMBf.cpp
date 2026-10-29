// 0x13B5C8 PrimeBomb__FP4BOMBf
#include "sly2.h"

struct BOMB {
    char pad[0x154];
    float field_0x154;
};

extern "C" float g_2dded0;

void PrimeBomb(BOMB* arg0, float dt)
{
    float tDetonate = arg0->field_0x154;
    float tPrimed = g_2dded0 + dt;
    arg0->field_0x154 = (tDetonate < tPrimed) ? tDetonate : tPrimed;
}