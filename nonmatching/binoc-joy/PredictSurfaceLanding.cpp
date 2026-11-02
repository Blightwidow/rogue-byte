#include "sly2.h"
struct B8 { char b[8]; };
struct TRI { B8 first; int third; };
struct L { TRI tri; char pad[4]; QW closest; QW normal; QW scratch; QW grav; QW dtv; QW vel; };
extern "C" {
int Spire_FindClosestPoint(void *);
extern int D_002BE918;
}
extern "C" int PredictSurfaceLanding(void *plo, QW pos, QW vel, QW gravity, TRI *ptri, QW *pposLanding, QW *pvelLanding, float gStandoff, float dt)
{
    L l;
    float half = dt * 0.5f;
    asm("qmtc2.ni %0, vf6" : : "r" (vel));
    asm("qmtc2.ni %0, vf5" : : "r" (dt));
    l.grav = gravity;
    asm("qmtc2.ni %0, vf3" : : "r" (gravity));
    asm("qmtc2.ni %0, vf2" : : "r" (pos));
    float dtHalfSquared = dt * half;
    asm("qmtc2.ni %0, vf1" : : "r" (dtHalfSquared));
    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddax.xyzw ACC, vf6, vf5x\n\tvmaddx.xyzw vf2, vf3, vf1x");
    QW ballistic;
    asm("qmfc2.ni %0, vf2" : "=r" (ballistic));
    asm("sqc2 vf1, %0" : "=m" (l.scratch));
    asm("sqc2 vf5, %0" : "=m" (l.dtv));
    asm("sqc2 vf6, %0" : "=m" (l.vel));
    Spire_FindClosestPoint(plo);
    asm("lqc2 vf3, %0" : : "m" (l.normal));
    asm("lqc2 vf1, %0" : : "m" (l.closest));
    *ptri = l.tri;
    asm("qmtc2.ni %0, vf2" : : "r" (gStandoff));
    asm("lqc2 vf5, %0" : : "m" (l.dtv));
    asm("sqc2 vf2, %0" : "=m" (l.scratch));
    asm("vadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf3, vf2x");
    asm("lqc2 vf6, %0" : : "m" (l.vel));
    int push = D_002BE918;
    asm("lqc2 vf2, %0" : : "m" (l.grav));
    asm("qmtc2.ni %0, vf4" : : "r" (push));
    asm("sqc2 vf1, 0(%0)" : : "r" (pposLanding) : "memory");
    asm("vadda.xyzw ACC, vf0, vf6\n\tvmaddax.xyzw ACC, vf2, vf5x\n\tvmaddx.xyzw vf6, vf3, vf4x");
    asm("sqc2 vf5, %0" : "=m" (l.scratch));
    asm("sqc2 vf6, 0(%0)" : : "r" (pvelLanding) : "memory");
    asm("sqc2 vf4, %0" : "=m" (l.scratch));
    return 1;
}
