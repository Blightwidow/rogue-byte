#include "sly2.h"
struct VOL { char pad0[0xEC]; void *cbsp; char pad1[0x20]; QW center; float radius; };
extern "C" QW ConvertAloPos(void *, VOL *, QW);
extern "C" int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int);
int func_00227C90(VOL *vol, QW pos)
{
    QW local = ConvertAloPos(0, vol, pos);
    float fdist;
    int token1, token2;
    asm("qmtc2.ni %1, vf3" : "=r" (token1) : "r" (local));
    asm("lqc2 vf1, %1" : "=r" (token2) : "m" (vol->center), "r" (token1));
    asm("vsub.xyzw vf1, vf3, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni $3, vf1\n\tmtc1 $3, %0\n\tnop" : "=f" (fdist) : "r" (token2) : "$3");
    int outside = vol->radius < fdist;
    QW again;
    asm("qmfc2.ni %0, vf3" : "=r" (again));
    if (outside == 0)
        return PcgtPointInCbspQuick__FP4CBSPP6VECTOR(vol->cbsp, 0x7FFFFFFF) != 0;
    return 0;
}
