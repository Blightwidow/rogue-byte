#include "sly2.h"
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
    asm("sqrt.s %0, %1" : "=f" (gCos) : "f" (gCosSquared));
    if (fOdd)
        gCos = -gCos;
    *pgCos = gCos;
    *pgSin = gSin;
}
