#include "sly2.h"
struct SMP { float a, b, c, d; };
extern QW g_2a2dd0;
extern "C" float GSmooth__FfffP3SMPPf(float g, float gGoal, float dt, SMP *psmp, float *psv);
extern "C" QW PosSmooth(float dt, QW posCur, QW posGoal, SMP *psmp, QW *pvecVelocity)
{
    struct Frame { QW junk; float gVelocity; float pad[3]; QW posCurSaved; QW vecDelta; QW spill; } frame;
    frame.posCurSaved = posCur;
    float sDelta;
    QW result;
    asm("qmtc2.ni %0, vf1" : : "r" (posCur));
    asm("qmtc2.ni %0, vf4" : : "r" (posGoal));
    asm("vsub.xyzw vf1, vf4, vf1\n\tsqc2 vf1, %0" : "=m" (frame.vecDelta));
    asm("lqc2 vf3, %0" : : "m" (frame.vecDelta));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    asm("qmfc2.ni %0, vf1" : "=r" (sDelta));
    if (0.0001f < sDelta) {
        asm("sqc2 vf3, %0" : "=m" (frame.spill));
        float sSmoothed = GSmooth__FfffP3SMPPf(0.0f, sDelta, dt, psmp, &frame.gVelocity);
        asm("lqc2 vf3, %0" : : "m" (frame.spill));
        if (pvecVelocity) {
            float gScale = frame.gVelocity / sDelta;
            asm("qmtc2.ni %0, vf1\n\tvmulx.xyzw vf2, vf3, vf1x" : : "r" (gScale));
            asm("sqc2 vf1, %0" : "=m" (frame.junk));
            asm("sqc2 vf2, %0" : "=m" (*pvecVelocity));
        }
        float gScale2 = sSmoothed / sDelta;
        asm("lqc2 vf2, %0" : : "m" (frame.posCurSaved));
        asm("lqc2 vf3, %0" : : "m" (frame.vecDelta));
        asm("qmtc2.ni %0, vf1\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf3, vf1x" : : "r" (gScale2));
        asm("sqc2 vf1, %0" : "=m" (frame.junk));
        asm("qmfc2.ni %0, vf2" : "=r" (result));
    } else {
        if (pvecVelocity)
            *pvecVelocity = g_2a2dd0;
        asm("qmfc2.ni %0, vf4" : "=r" (result));
    }
    return result;
}
