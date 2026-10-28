#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" const float D_FLT_002BD2D8;
extern "C" const float D_FLT_002BD2D0;
extern "C" float g_2dded0;

void func_001448F0(char *self, QW posNew)
{
    if (*(int *)(self + 0x28) == 0) {
    int chain;
    float length;
    asm volatile("qmtc2.ni %1, vf3" : "=r" (chain) : "r" (posNew));
    asm volatile("lqc2 vf1, %1" : "+r" (chain) : "m" (*(QW *)(self + 0x10)));
    float thr = D_FLT_002BD2D8;
    asm volatile("vsub.xyzw vf1, vf1, vf3" : "+r" (chain));
    asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (chain));
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain));
    asm volatile("qmfc2.ni %0, vf1\n\tnop" : "=r" (length) : "r" (chain));
    int tooClose = length < thr;
    if (!tooClose) {
    QW posJt = PosLoWorld(*(void **)self);
    int chain2;
    int sAnchor;
    asm volatile("sqc2 vf3, %0" : "=m" (*(QW *)(self + 0x10)));
    asm volatile("lqc2 vf2, %1" : "=r" (chain2) : "m" (*(QW *)(self + 0x10)));
    asm volatile("qmtc2.ni %1, vf3" : "+r" (chain2) : "r" (posJt));
    asm volatile("vsub.xyzw vf1, vf3, vf2" : "+r" (chain2));
    asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (chain2));
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain2));
    asm volatile("qmfc2.ni %0, vf1" : "=r" (sAnchor) : "r" (chain2));
    *(int *)(self + 0x20) = sAnchor;
    *(float *)(self + 0x24) = g_2dded0 + D_FLT_002BD2D0;
    }
    }
}
