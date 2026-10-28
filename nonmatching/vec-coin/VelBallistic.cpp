#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern QW g_2a2dc0;
QW VelBallistic(float dt, QW from, QW to, QW accel)
{
    register QW zeroReg asm("$0");
    QW spill;
    float accz = Lane(__builtin_pextuw(zeroReg, accel));
    asm("qmtc2.ni %0, vf1" : : "r" (to));
    float fall = (dt * 0.5f);
    asm("qmtc2.ni %0, vf2" : : "r" (from));
    asm("vsub.xyzw vf3, vf1, vf2");
    float inv = 1.0f / dt;
    QW delta;
    asm("qmfc2.ni %0, vf3" : "=r" (delta));
    fall = dt * fall;
    float dz = Lane(__builtin_pextuw(zeroReg, delta));
    asm("lqc2 vf2, %0" : : "m" (g_2a2dc0));
    fall = fall * accz;
    asm("vmul.xyz vf1, vf3, vf2\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z");
    float sv = (dz - fall) / dt;
    asm("vmulx.xyzw vf1, vf2, vf1x\n\tvsub.xyzw vf3, vf3, vf1");
    QW invq = Word(inv);
    asm("qmtc2.ni %0, vf4" : : "r" (invq));
    asm("sqc2 vf4, %0" : "=m" (spill));
    QW svq = Word(sv);
    asm("qmtc2.ni %0, vf1" : : "r" (svq));
    asm("vmulax.xyzw ACC, vf3, vf4x\n\tvmaddx.xyzw vf5, vf2, vf1x");
    asm("sqc2 vf1, %0" : "=m" (spill));
    QW result;
    asm("qmfc2.ni %0, vf5" : "=r" (result));
    return result;
}
