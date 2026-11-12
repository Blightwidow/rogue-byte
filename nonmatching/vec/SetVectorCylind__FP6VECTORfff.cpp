#include "sly2.h"
#include "ps2inline.h"
void CalculateSinCos__FfPfT1(float rad, float *pgSin, float *pgCos);
extern "C" QW SetVectorCylind__FP6VECTORfff(void *pvec, float rad, float sXY, float sZ)
{
    struct { QW vec; float gSin; float gCos; } l;
    CalculateSinCos__FfPfT1(rad, &l.gSin, &l.gCos);
    float cosScaled = l.gCos * sXY;
    QW sinCosLanes = InterleaveLowWords(l.gSin * sXY, cosScaled);
    l.vec = JoinLowDoublewords(sZ, sinCosLanes);
    return l.vec;
}
