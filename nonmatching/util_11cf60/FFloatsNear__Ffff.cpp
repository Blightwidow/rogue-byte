int FFloatsNear(float a, float b, float eps)
{
    float absA = __builtin_fabsf(a);
    float absDiff = __builtin_fabsf(a - b);
    float scale = (absA < 1.0f) ? 1.0f : absA;
    return (absDiff / scale < eps) ? 1 : 0;
}
