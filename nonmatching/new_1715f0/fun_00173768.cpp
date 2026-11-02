#include "sly2.h"
extern "C" int ConvertCmWorldToScreen_dummy;
extern "C" QW ConvertCmWorldToScreen(void *, QW, float);
extern "C" int FInScreenBox(QW, float);
extern "C" int PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, int);
extern "C" char B_002DDF40[];
extern "C" float RO_002BE5B8, RO_002BE5BC, RO_002BE5C0, RO_002BE5C4, RO_002BE5C8;

int func_00173768(char *self, QW pos, int arg2, int arg3, float radius)
{
    QW target;
    VECTOR camPos = *(VECTOR *)(B_002DDF40 + 0x90);
    QW diff;
    int fenceA, fenceB;
    float length;
    QW bits;
    asm("lqc2 vf1, %2\n\tqmtc2.ni %3, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %1" : "=r" (fenceA), "=m" (diff) : "m" (pos), "r" (*(QW *)&camPos));
    radius = radius * RO_002BE5B8;
    asm("lqc2 vf3, %2\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceB) : "r" (fenceA), "m" (diff));
    asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (length), "=r" (bits) : "r" (fenceB));
    if (radius < length)
        return 0;
    QW screen = ConvertCmWorldToScreen(B_002DDF40, pos, radius);
    QW lane2;
    asm("pextuw %0, $0, %1" : "=r" (lane2) : "r" (screen));
    float depth;
    asm("mtc1 %1, %0" : "=f" (depth) : "r" (lane2));
    if (depth < RO_002BE5BC)
        return 0;
    if (FInScreenBox(screen, RO_002BE5C0) == 0)
        return 0;
    if (*(int *)(self + 0x84) != 0 && FInScreenBox(screen, RO_002BE5C4) == 0)
        return 1;
    if (*(int *)(self + 0x88) != 0) {
        int inside = 1;
        int fenceC, fenceD;
        float length2;
        QW bits2;
        asm("lqc2 vf2, %1\n\tvmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceC) : "m" (diff));
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (length2), "=r" (bits2) : "r" (fenceC));
        inside = *(float *)(self + 0x80) < length2;
        if (inside != 0)
            return 2;
    }
    if (*(int *)(self + 0x8C) != 0) {
        target = pos;
        ((float *)&target)[2] += RO_002BE5C8;
        if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, *(QW *)&camPos, target, arg2, arg3, 0) != 0)
            return 3;
    }
    return 0;
}
