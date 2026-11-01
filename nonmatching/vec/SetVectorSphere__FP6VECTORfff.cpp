#include "sly2.h"
void CalculateSinCos(float rad, float *psin, float *pcos);
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_11E208 { QW dead; float sc[4]; };
extern "C" QW SetVectorSphere(float radPan, float radTilt, float sRadius)
{
    Frame_11E208 frame;
    CalculateSinCos(radPan, &frame.sc[0], &frame.sc[1]);
    CalculateSinCos(radTilt, &frame.sc[2], &frame.sc[3]);
    float x = frame.sc[3] * frame.sc[1] * sRadius;
    float y = frame.sc[3] * frame.sc[0] * sRadius;
    float z = frame.sc[2] * sRadius;
    QW low = __builtin_pextlw(Word(y), Word(x));
    QW result = __builtin_pcpyld(Word(z), low);
    frame.dead = result;
    return result;
}
