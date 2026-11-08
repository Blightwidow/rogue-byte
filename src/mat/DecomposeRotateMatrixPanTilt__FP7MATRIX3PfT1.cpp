#include "sly2.h"
// Sqrt: sqrt.s with an early-clobber output (=&f); retail's helper keeps the result out of the operand's register.
// The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=&f"(r) : "f"(x)); return r; }
extern "C" float atan2f(float, float);
// Retail loads mat[0][2] in the delay slot of the second atan2f call, after the sqrt.s: the source reads it
// directly in the call's argument list. A named local for it (earlier draft) moved the load above the
// multiplies (score 2).
extern "C" void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *mat, float *pan, float *tilt)
{
    float *values = (float *)mat;
    *pan = atan2f(values[1], values[0]);
    *tilt = atan2f(values[2], Sqrt(values[0] * values[0] + values[1] * values[1]));
}
