#include "sly2.h"
extern "C" void FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(void *, QW, void *);
extern "C" char g_2a2dc0[];
extern "C" void RenderOrbit__FP5ORBITP2CM(char *orbit, void *cm)
{
    QW b;
    QW a;
    QW pos;
    int fence;
    asm("lw $4, 0xF0(%1)\n\tqmtc2.ni $4, vf2\n\tlqc2 vf3, %2\n\tlqc2 vf1, 0x70(%1)" : "=r" (fence) : "r" (orbit), "m" (*(QW *)g_2a2dc0) : "$4");
    asm("vadda.xyzw ACC, vf1, vf0\n\tvmaddx.xyzw vf1, vf3, vf2x\n\tsqc2 vf2, %1\n\tqmfc2.ni %0, vf1" : "=r" (pos), "=m" (a) : "r" (fence));
    asm("sqc2 vf1, %0" : "=m" (b) : "r" (fence));
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(orbit, pos, orbit + 0x40);
}
