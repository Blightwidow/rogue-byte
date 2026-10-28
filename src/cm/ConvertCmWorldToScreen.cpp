#include "sly2.h"
struct CM { char pad0[0x40]; float xRange; float yRange; char pad1[0x60 - 0x48]; MATRIX4 mat; };
extern "C" void InvertMatrix4Affine(MATRIX4 *, MATRIX4 *);
struct LOCALS { VECTOR result; QW inv[4]; QW pos; };
extern "C" QW ConvertCmWorldToScreen(CM *pcm, QW posWorld)
{
    LOCALS l;
    l.pos = posWorld;
    InvertMatrix4Affine((MATRIX4 *)l.inv, &pcm->mat);
    asm("lqc2 vf2, %0" : : "m" (l.inv[0]));
    asm("lqc2 vf4, %0" : : "m" (l.inv[1]));
    asm("lqc2 vf3, %0" : : "m" (l.inv[2]));
    asm("lqc2 vf1, %0" : : "m" (l.inv[3]));
    asm("lqc2 vf5, %0" : : "m" (l.pos));
    float yRange = pcm->yRange;
    asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w");
    asm("sqc2 vf2, %0" : "=m" (l.result));
    float yNeg = -l.result.y;
    float zRaw = l.result.z;
    float xRange = pcm->xRange;
    float yScreen = zRaw / yRange;
    float depth = l.result.x;
    float xScreen = yNeg / xRange;
    l.result.z = depth;
    l.result.y = yScreen;
    l.result.x = xScreen;
    if (0.0001f < depth) {
        asm("nop\n\tnop");
        l.result.x = xScreen / depth;
        l.result.y = yScreen / depth;
    }
    return *(QW *)&l.result;
}
