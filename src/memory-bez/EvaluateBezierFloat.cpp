#include "sly2.h"
void EvaluateBezierFloat(float dtSeg, float tSeg, float svt, float g0, float gSlope0, float g1, float gSlope1, float *pg, float *pdg)
{
    asm volatile("nop\n\tnop");
    float u = tSeg / dtSeg;
    float uInv = 1.0f - u;
    float dg = g1 - g0;
    if (pg != 0) {
        float weightA = u * uInv * uInv;
        float weightB = u * u * uInv;
        float c0 = (uInv * uInv * uInv + weightA * 3.0f) * g0;
        float c3 = (u * u * u + weightB * 3.0f) * g1;
        float c1 = weightA * dtSeg * gSlope0;
        float c2 = weightB * dtSeg * gSlope1;
        *pg = c0 + c1 - c2 + c3;
    }
    if (pdg != 0) {
        float six = uInv * 6.0f;
        *pdg = ((u * six) / dtSeg * dg + (1.0f - u * (4.0f - u * 3.0f)) * gSlope0 +
                u * (u * 3.0f + -2.0f) * gSlope1) * svt;
    }
}
