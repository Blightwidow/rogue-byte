#include "sly2.h"
struct CRV { char pad0[0xE4]; int closed; };
extern "C" {
float SMaxCrv(CRV *);
float SWrapCrv(CRV *, float);
float GRandInRange(float, float);
extern int g_2c3650;
}
float SRandNearCrv(CRV *pcrv, float s, float ds)
{
    float bounds[2];
    if (pcrv->closed == 0) {
        float sMax = SMaxCrv(pcrv);
        float sLimit = sMax - ds;
        float sCenter = s;
        if (s < ds) {
            sCenter = ds;
        } else if (sLimit < s) {
            sCenter = sLimit;
        }
        float sTop = sCenter + ds;
        bounds[1] = (sTop < sMax) ? sTop : sMax;
        float sBottom = sCenter - ds;
        bounds[0] = (0.0f < sBottom) ? sBottom : 0.0f;
    } else {
        bounds[1] = s + ds;
        bounds[0] = s - ds;
    }
    float gRand = GRandInRange(-1.0f, 1.0f);
    if (g_2c3650 == 1) {
        gRand = gRand * (gRand < 0.0f ? -gRand : gRand);
    } else if (g_2c3650 == 2) {
        float gSign = (0.0f < gRand) ? 3.0f : -3.0f;
        gRand = gRand * gRand * (gSign - (gRand + gRand));
    } else if (g_2c3650 == 3) {
        if (0.0f < gRand)
            gRand = __builtin_sqrtf(gRand);
        else
            gRand = -__builtin_sqrtf(-gRand);
    }
    float unit = gRand * 0.5f + 0.5f;
    float result = (1.0f - unit) * bounds[0] + unit * bounds[1];
    if (pcrv->closed != 0)
        return SWrapCrv(pcrv, result);
    return result;
}
