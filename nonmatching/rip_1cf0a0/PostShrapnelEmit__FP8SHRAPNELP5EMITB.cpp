#include "sly2.h"
struct SHRAPNEL { char pad0[0x18]; float dtLifetime; char pad1[0x90 - 0x1C]; QW v; char pad2[0xD0 - 0xA0]; float w[3]; char pad3[0xF0 - 0xDC]; float radius; float elasticity; float friction; };
struct EMITB { char pad[0xF0]; float radius; float elasticity; float friction; };
extern "C" {
extern float g_2c1f78[2];
extern float g_2c1f80[3];
extern float g_2bbb60[2];
void func_001CE9B8();
float GRandInRange(float, float);
void PostShrapnelEmit__FP8SHRAPNELP5EMITB(SHRAPNEL *pshrapnel, EMITB *pemitb)
{
    func_001CE9B8();
    float lifetime = GRandInRange(g_2c1f78[0], g_2c1f78[1]);
    float scaled = pshrapnel->dtLifetime;
    asm("lqc2 vf1, %0" : : "m" (pshrapnel->v));
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    int bits;
    asm("qmfc2.ni %0, vf1" : "=r" (bits));
    float speed;
    asm("mtc1 %1, %0" : "=f" (speed) : "r" (bits));
    pshrapnel->dtLifetime = scaled * lifetime;
    pshrapnel->radius = pemitb->radius;
    pshrapnel->elasticity = pemitb->elasticity;
    pshrapnel->friction = pemitb->friction;
    float spin = g_2c1f80[0] + speed * (g_2c1f80[1] + speed * g_2c1f80[2]);
    if (spin < g_2bbb60[0])
        spin = g_2bbb60[0];
    else if (g_2bbb60[1] < spin)
        spin = g_2bbb60[1];
    float spinMax = spin * 10.0f;
    float *axis = pshrapnel->w;
    for (int index = 2; index >= 0; index--)
        *axis++ = GRandInRange(-spinMax, spinMax);
}
}
