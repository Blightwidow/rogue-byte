#include "sly2.h"
extern "C" void FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(void *, QW, void *);
extern "C" char g_2a2dc0[];
extern "C" void RenderOrbit__FP5ORBITP2CM(char *orbit, void *cm)
{
    struct { QW b; QW a; } l;
    QW pos;
    int chain;
    int field = *(int *)(orbit + 0xF0);
    asm("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (field));
    asm("lqc2 vf3, %1" : "+r" (chain) : "m" (*(QW *)g_2a2dc0));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (*(QW *)(orbit + 0x70)));
    asm("vadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf3, vf2x" : "+r" (chain));
    asm("sqc2 vf2, %0" : "=m" (l.a) : "r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (pos) : "r" (chain));
    asm("sqc2 vf1, %0" : "=m" (l.b) : "r" (chain));
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(orbit, pos, orbit + 0x40);
}
