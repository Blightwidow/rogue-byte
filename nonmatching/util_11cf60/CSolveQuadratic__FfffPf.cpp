#include "sly2.h"
int CSolveQuadratic(float a, float b, float c, float *roots)
{
    float discriminant = b * b - a * (c * 4.0f);
    if (discriminant < 0.0f)
        return 0;
    float spread = __builtin_sqrtf(discriminant) / (a + a);
    float center = -(b / (a + a));
    if (__builtin_fabsf(spread) < 0.0001f) {
        roots[0] = center;
        return 1;
    }
    float high = spread + center;
    float low = center - spread;
    roots[1] = low;
    roots[0] = high;
    if (low < high) {
        roots[0] = low;
        roots[1] = high;
    }
    return 2;
}
