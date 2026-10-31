#include "sly2.h"
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" QW PosLoWorld(char *);
extern const float D_002BCC7C;
extern const float D_002BCC80;
extern const float D_002BCC84;
extern const float D_002BCC88;
extern const float D_002BCC8C;
extern const float D_002BCC90;
int FJtInFocusRange(char *jt, int fWide)
{
    int result;
    if (*(int *)(jt + 0x10EC) != 4 || *(int *)(jt + 0x10E4) == 3)
        return 0;
    float range;
    if (FIsBasicDerivedFrom(*(void **)(jt + 0x10E8), 0x3A))
        range = D_002BCC7C;
    else
        range = D_002BCC80;
    float dzLow = D_002BCC84;
    float dzHigh = D_002BCC88;
    if (fWide) {
        range += D_002BCC8C;
        dzLow -= D_002BCC90;
        dzHigh += D_002BCC90;
    }
    struct { QW delta; QW save; } loc;
    int chain;
    float horizontal;
    QW posObj = PosLoWorld(*(char **)(jt + 0x10E8));
    asm("qmtc2.ni %0, vf1" : : "r" (posObj));
    asm("sqc2 vf1, %0" : "=m" (loc.save));
    QW posJt = PosLoWorld(jt);
    asm("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (posJt));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (loc.save));
    asm("vsub.xyzw vf1, vf1, vf2" : "+r" (chain));
    asm("vmul.xy vf2, vf1, vf1" : "+r" (chain));
    asm("vaddy.x vf2, vf2, vf2y" : "+r" (chain));
    asm("sqc2 vf1, %0" : "=m" (loc.delta) : "r" (chain));
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "+r" (chain));
    asm("qmfc2.ni %0, vf2" : "=r" (horizontal) : "r" (chain));
    result = 0;
    if (horizontal < range && dzLow < ((float *)&loc.delta)[2] && ((float *)&loc.delta)[2] < dzHigh)
        result = 1;
    return result;
}
