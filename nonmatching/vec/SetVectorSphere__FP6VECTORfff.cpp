#include "sly2.h"
void CalculateSinCos(float rad, float *psin, float *pcos);
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" QW SetVectorSphere(float radPan, float radTilt, float sRadius)
{
    float pad[4];
    float sc[4];
    QW junk;
    CalculateSinCos(radPan, &sc[0], &sc[1]);
    CalculateSinCos(radTilt, &sc[2], &sc[3]);
    float x = sc[3] * sc[1] * sRadius;
    float y = sc[3] * sc[0] * sRadius;
    float z = sc[2] * sRadius;
    QW low = __builtin_pextlw(Word(y), Word(x));
    QW result = __builtin_pcpyld(Word(z), low);
    junk = result;
    asm("" : : "m" (junk));
    return result;
}
