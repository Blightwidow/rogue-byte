#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern const float g_2a5130;
extern int g_2bdc50;
struct POST { char pad0[4]; void *ploA; char pad1[0x14 - 0x8]; void *ploB; char pad2[0x20 - 0x18]; int fUsed; char pad3[0x24 - 0x24]; };
struct GUARD { char pad[0x1010]; int cpost; POST *apost; };
struct GOAL { char pad0[0x10]; GUARD *pguard; char pad1[0x38 - 0x14]; void *ploTarget; };
extern "C" POST *func_00155868(GOAL *pgoal)
{
    POST *pbest = 0;
    int index = 0;
    QW target;
    QW posA;
    asm volatile("" : "=m"(target));
    asm volatile("" : "=m"(posA));
    target = PosLoWorld(pgoal->ploTarget);
    float best = g_2a5130;
    if (pgoal->pguard->cpost > 0) {
        int offset = 0;
        for (; index < pgoal->pguard->cpost; ) {
            POST *ppost = (POST *)((char *)pgoal->pguard->apost + offset);
            if (g_2bdc50 != 0 || ppost->fUsed == 0) {
                QW a = PosLoWorld(ppost->ploA);
                asm volatile("qmtc2.ni %0, vf2" : : "r" (a));
                register void *arg asm("$4") = ppost->ploB;
                asm volatile("sqc2 vf2, %0" : "=m" (posA) : "r" (arg));
                QW b = PosLoWorld(arg);
                asm volatile("lqc2 vf1, %0" : : "m" (target));
                asm volatile("lqc2 vf2, %0" : : "m" (posA));
                asm volatile("qmtc2.ni %0, vf3" : : "r" (b));
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                asm volatile("vsub.xyzw vf1, vf3, vf1");
                asm volatile("vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
                asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z");
                float lenA, lenB;
                asm volatile("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
                asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                asm volatile("qmfc2.ni $2, vf2\n\tmtc1 $2, %0" : "=f" (lenA) : : "$2");
                asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (lenB) : : "$2");
                float nearer = lenA < lenB ? lenA : lenB;
                if (best < nearer) {
                    best = nearer;
                    pbest = ppost;
                }
            }
            index++;
            offset += 0x24;
        }
    }
    return pbest;
}
