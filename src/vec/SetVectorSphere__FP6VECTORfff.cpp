#include "sly2.h"
void CalculateSinCos(float rad, float *psin, float *pcos);
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
extern "C" QW SetVectorSphere(float radPan, float radTilt, float sRadius)
{
    struct { QW vec; float gSinPan; float gCosPan; float gSinTilt; float gCosTilt; } l;
    CalculateSinCos(radPan, &l.gSinPan, &l.gCosPan);
    CalculateSinCos(radTilt, &l.gSinTilt, &l.gCosTilt);
    l.vec = Vec3(l.gCosTilt * l.gCosPan * sRadius, l.gCosTilt * l.gSinPan * sRadius, l.gSinTilt * sRadius);
    return l.vec;
}
