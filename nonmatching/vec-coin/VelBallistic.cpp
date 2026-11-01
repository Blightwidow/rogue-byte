#include "sly2.h"
static inline float Lane(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW UpperWord(QW q) { QW r; asm volatile("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern QW g_2a2dc0;
QW VelBallistic(float dt, QW from, QW to, QW accel)
{
    QW spill;
    float fall = (dt * 0.5f);
    QW accu = UpperWord(accel);
    asm volatile("qmtc2.ni %0, vf1" : : "r" (to));
    float accz = Lane(accu);
    fall = dt * fall;
    asm volatile("qmtc2.ni %0, vf2" : : "r" (from));
    asm volatile("vsub.xyzw vf3, vf1, vf2");
    float inv = 1.0f / dt;
    QW delta;
    asm volatile("qmfc2.ni %0, vf3" : "=r" (delta));
    QW du = UpperWord(delta);
    float dz = Lane(du);
    asm volatile("lqc2 vf2, %0" : : "m" (g_2a2dc0));
    fall = fall * accz;
    asm volatile("vmul.xyz vf1, vf3, vf2\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z");
    float sv = (dz - fall) / dt;
    asm volatile("vmulx.xyzw vf1, vf2, vf1x\n\tvsub.xyzw vf3, vf3, vf1");
    QW invq = Word(inv);
    asm volatile("qmtc2.ni %0, vf4" : : "r" (invq));
    asm volatile("sqc2 vf4, %0" : "=m" (spill));
    QW svq = Word(sv);
    asm volatile("qmtc2.ni %0, vf1" : : "r" (svq));
    asm volatile("vmulax.xyzw ACC, vf3, vf4x\n\tvmaddx.xyzw vf5, vf2, vf1x");
    asm volatile("sqc2 vf1, %0" : "=m" (spill));
    QW result;
    asm volatile("qmfc2.ni %0, vf5" : "=r" (result));
    return result;
}
