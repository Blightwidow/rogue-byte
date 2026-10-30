static inline float GMax(float a, float b) { return a >? b; }
int FFloatsNear(float a, float b, float eps)
{
    return __builtin_fabsf(a - b) / GMax(1.0f, __builtin_fabsf(a)) < eps;
}
