#include "sly2.h"
struct SMP { float a, b, c, d; };
struct SMPA { float a, b, c, dsvAccel; };
extern "C" float GSmooth__FfffP3SMPPf(float g, float gGoal, float dt, SMP *psmp, float *psv);
extern "C" float GSmoothA__FffffP4SMPAPf(float g, float sv, float gGoal, float dt, SMPA *psmpa, float *psvOut)
{
    float svSmoothed;
    float gResult = GSmooth__FfffP3SMPPf(g, gGoal, dt, (SMP *)psmpa, &svSmoothed);
    float dsvAccel = psmpa->dsvAccel;
    if (0.0f < dsvAccel) {
        float svMax = sv + dsvAccel * dt;
        float svMin = sv - dsvAccel * dt;
        if (svMax < svSmoothed) {
            float dtHalf = dt * 0.5f;
            gResult = g + sv * dt + dsvAccel * dtHalf * dt;
            svSmoothed = svMax;
        } else if (svSmoothed < svMin) {
            float dtHalf = dt * 0.5f;
            gResult = (g + sv * dt) - dsvAccel * dtHalf * dt;
            svSmoothed = svMin;
        }
    }
    if (psvOut != 0)
        *psvOut = svSmoothed;
    return gResult;
}
