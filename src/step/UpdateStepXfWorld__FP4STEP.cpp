#include "sly2.h"
struct LM { int unk; };
struct STEP { float f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30; char pad[0x54]; float f88, f8C; };
extern LM D_002C41B0;
float GLimitLm(LM *, float);
// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float sqrtf(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=&f" (result) : "f" (value));
    return result;
}
extern "C" float atan2f(float, float);
void UpdateStepXfWorld(STEP *step)
{
    if (step->f88 == -3.402823466e+38f && step->f8C == 3.402823466e+38f) {
        float sum = step->f4 + step->f10;
        float other = step->f20;
        float length = sqrtf(sum * sum + other * other);
        float raw = atan2f(step->f30, length);
        float angle = GLimitLm(&D_002C41B0, raw);
        step->f8C = angle;
        step->f88 = angle;
    }
}
