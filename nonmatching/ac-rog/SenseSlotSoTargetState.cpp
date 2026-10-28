#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct LO { char pad0[0xC]; VT *vt; };
struct SO { char pad0[0xC]; VT *vt; char pad1[0x150 - 0x10]; float sNoticeMin; float sNoticeMax; char pad2[0x220 - 0x158]; int state; };
extern "C" QW PosLoWorld(void *);
extern "C" void *func_001C4AF8(void *, QW);
extern "C" void SetSlotSoHeading(SO *, float);
extern "C" float atan2f(float, float);
extern "C" char B_003DD490[];
extern "C" int SenseSlotSoTargetState(SO *pso)
{
    int stateCurrent = pso->state;
    struct { float vecToTarget[4]; QW posSelf; } l;
    l.posSelf = PosLoWorld(pso);
    LO *ploTarget = (LO *)func_001C4AF8(B_003DD490, l.posSelf);
    if (ploTarget == 0) return stateCurrent;
    QW posTarget = PosLoWorld(ploTarget);
    float sToTarget;
    asm("qmtc2.ni %0, vf2" : : "r" (posTarget));
    float limitMax = pso->sNoticeMax;
    asm("lqc2 vf3, %0" : : "m" (l.posSelf));
    asm("vsub.xyzw vf1, vf2, vf3");
    asm("vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
    asm("sqc2 vf1, %0" : "=m" (l.vecToTarget));
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
    int raw0;
    asm("qmfc2.ni %1, vf2\n\tmtc1 %1, %0\n\tnop" : "=f" (sToTarget), "=&r" (raw0));
    if (limitMax < sToTarget) return stateCurrent;
    if (pso->sNoticeMin < sToTarget) {
        VT *vt = ploTarget->vt;
        QW velocity = vt->fn((char *)ploTarget + vt->delta);
        float gSpeed;
        asm("qmtc2.ni %0, vf3" : : "r" (velocity));
        float speedMin = 150.0f;
        asm volatile("" : : "f" (speedMin));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        int raw1;
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (gSpeed), "=&r" (raw1));
        if (gSpeed < speedMin) return stateCurrent;
    }
    SetSlotSoHeading(pso, atan2f(l.vecToTarget[1], l.vecToTarget[0]));
    return 3;
}
