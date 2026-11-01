#include "sly2.h"
void CalculateSinCos__FfPfT1(float rad, float *pgSin, float *pgCos);
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
extern "C" QW SetVectorCylind__FP6VECTORfff(void *pvec, float rad, float sXY, float sZ)
{
    struct { QW vec; float gSin; float gCos; } l;
    CalculateSinCos__FfPfT1(rad, &l.gSin, &l.gCos);
    l.vec = Vec3(l.gCos * sXY, l.gSin * sXY, sZ);
    return l.vec;
}
