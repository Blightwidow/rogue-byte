#include "sly2.h"
// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=&f"(r) : "f"(x)); return r; }
extern "C" void CalculateSinCos__FfPfT1(float rad, float *pgSin, float *pgCos)
{
    float gHalfTurns = (rad + 1.5707964f) * 0.31830987f;
    int nHalfTurns = (int)gHalfTurns;
    if (gHalfTurns < 0.0f)
        nHalfTurns = nHalfTurns - 1;
    rad = rad - (float)nHalfTurns * 3.1415927f;
    int fOdd = nHalfTurns & 1;
    if (fOdd)
        rad = -rad;
    float radSquared = rad * rad;
    float gSin = rad;
    rad = rad * radSquared;
    gSin = gSin + rad * -0.16666657f;
    rad = rad * radSquared;
    gSin = gSin + rad * 0.0083330255f;
    rad = rad * radSquared;
    gSin = gSin + rad * -0.00019807414f;
    rad = rad * radSquared;
    gSin = gSin + rad * 2.601887e-06f;
    float lowest = -1.0f;
    float highest = 1.0f;
    if (gSin < lowest)
        gSin = lowest;
    else if (highest < gSin)
        gSin = highest;
    float gCosSquared = 1.0f - gSin * gSin;
    float gCos;
    // cos = sqrt(1 - sin^2) through the Sqrt helper: retail computes the cosine from the clamped sine, not with a second polynomial.
    gCos = Sqrt(gCosSquared);
    if (fOdd)
        gCos = -gCos;
    *pgCos = gCos;
    *pgSin = gSin;
}
