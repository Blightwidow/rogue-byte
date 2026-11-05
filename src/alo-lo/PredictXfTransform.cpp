#include "sly2.h"
extern "C" void PredictXfTransformAdjust(void *, void *, float, float *, float *);
extern "C" void PredictXfTransform(void *pa0, void *pa1, float t, float *pm0, float *pm1)
{
    if (pm0 != 0) {
        memset(pm0, 0, 0x40);
        pm0[15] = 1.0f;
        pm0[10] = 1.0f;
        pm0[5] = 1.0f;
        pm0[0] = 1.0f;
    }
    if (pm1 != 0) {
        memset(pm1, 0, 0x40);
    }
    PredictXfTransformAdjust(pa0, pa1, t, pm0, pm1);
}
