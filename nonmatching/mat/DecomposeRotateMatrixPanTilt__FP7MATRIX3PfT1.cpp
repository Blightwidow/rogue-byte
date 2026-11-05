#include "sly2.h"
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float atan2f(float, float);
extern "C" void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *mat, float *pan, float *tilt)
{
    float *values = (float *)mat;
    *pan = atan2f(values[1], values[0]);
    float lengthSquared = values[0] * values[0] + values[1] * values[1];
    float z = values[2];
    *tilt = atan2f(z, Sqrt(lengthSquared));
}
