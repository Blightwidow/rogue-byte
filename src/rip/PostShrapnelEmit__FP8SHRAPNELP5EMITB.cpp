#include "vu0inline.h"
#include "sly2.h"
#include "ps2inline.h"
extern "C" {
void func_001CE9B8();
float GRandInRange(float, float);
extern float g_2c1f78[];
extern float g_2c1f80[];
extern float g_2bbb60[];
}
struct EMITB { char pad[0xF0]; float vx, vy, vz; };
struct SHRAPNEL { char pad0[0x18]; float lifetime; char pad1[0x90 - 0x1C]; QW velocity; char pad2[0xD0 - 0xA0]; float spin[3]; char pad3[0xF0 - 0xDC]; float vx, vy, vz; };

void PostShrapnelEmit(SHRAPNEL *shrapnel, EMITB *emit)
{
    func_001CE9B8();
    shrapnel->lifetime = shrapnel->lifetime * GRandInRange(g_2c1f78[0], g_2c1f78[1]);
    float speed = LaneX(SqrtX(SquaredLength(shrapnel->velocity)));
    shrapnel->vx = emit->vx;
    shrapnel->vy = emit->vy;
    shrapnel->vz = emit->vz;
    float low = g_2bbb60[0];
    float high = g_2bbb60[1];
    float spread = g_2c1f80[0] + speed * (g_2c1f80[1] + speed * g_2c1f80[2]);
    if (spread < low)
        spread = low;
    else if (high < spread)
        spread = high;
    float range = spread * 10.0f;
    for (int index = 0; index < 3; index++)
        shrapnel->spin[index] = GRandInRange(-range, range);
}
