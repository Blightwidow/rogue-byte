#include "sly2.h"
struct LO { char pad[0x218]; QW *ppos; };
struct PT;
extern "C" int FIsBasicDerivedFrom(LO *, int);
extern "C" QW func_001C1EC0(PT *, QW);

int func_001C1FA0(float range, PT *point, LO *lo)
{
    int result;
    if (FIsBasicDerivedFrom(lo, 0x40))
        result = 1;
    else {
        QW pos;
        QW posSaved;
        asm("lqc2 vf1, %2; qmfc2 %0, vf1; sqc2 vf1, %1" : "=r"(pos), "=m"(posSaved) : "m"(*lo->ppos));
        QW closest = func_001C1EC0(point, pos);
        float length;
        asm("qmtc2 %2, vf2; lqc2 vf1, %1; vsub.xyzw vf1, vf1, vf2; vmul.xy vf1, vf1, vf1; vaddy.x vf1, vf1, vf1y; vsqrt Q, vf1x; vwaitq; vaddq.x vf1, vf0, Q; qmfc2 %0, vf1" : "=r"(length) : "m"(posSaved), "r"(closest));
        result = 0;
        if (length <= range) result = 1;
    }
    return result;
}
