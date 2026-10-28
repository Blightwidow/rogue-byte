#include "sly2.h"
extern "C" int NRandRaw();
extern "C" float GRandInRange(float gLow, float gHigh)
{
    if (gLow == gHigh) {
        return gLow;
    }
    int remainder = NRandRaw() % 0x16A1B;
    float converted;
    asm("mtc1 %1,%0\n\tnop\n\tcvt.s.w %0,%0" : "=f"(converted) : "r"(remainder));
    return gLow + (gHigh - gLow) * converted * 0.000010787603f;
}
