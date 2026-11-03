#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" const float D_FLT_002BD2D8;
extern "C" const float D_FLT_002BD2D0;
extern "C" float g_2dded0;

void func_001448F0(char *self, QW posNew)
{
    if (*(int *)(self + 0x28) == 0) {
        int fenceA, fenceB;
        int lengthBits;
        asm("qmtc2.ni %1, vf3\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf3" : "=r" (fenceA) : "r" (posNew), "m" (*(QW *)(self + 0x10)));
        float threshold = D_FLT_002BD2D8;
        asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceB) : "r" (fenceA));
        asm("qmfc2.ni %0, vf1" : "=r" (lengthBits) : "r" (fenceB));
        float length = *(float *)&lengthBits;
        int tooClose = length < threshold;
        if (!tooClose) {
            QW posJt = PosLoWorld(*(void **)self);
            int fenceC, fenceD, anchorBits;
            asm("sqc2 vf3, %1\n\tlqc2 vf2, %1\n\tqmtc2.ni %2, vf3\n\tvsub.xyzw vf1, vf3, vf2" : "=r" (fenceC), "=m" (*(QW *)(self + 0x10)) : "r" (posJt));
            asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceD) : "r" (fenceC));
            asm("qmfc2.ni %0, vf1" : "=r" (anchorBits) : "r" (fenceD));
            *(int *)(self + 0x20) = anchorBits;
            *(float *)(self + 0x24) = g_2dded0 + D_FLT_002BD2D0;
        }
    }
}
