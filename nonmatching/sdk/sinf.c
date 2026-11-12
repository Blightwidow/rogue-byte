extern int __ieee754_rem_pio2f(float x, float *y);
extern float __kernel_cosf(float x, float y);
extern float __kernel_sinf(float x, float y, int tail);

float sinf(float x)
{
    float parts[2];
    int magnitude;
    int quadrant;

    magnitude = *(int *)&x;
    magnitude &= 0x7fffffff;

    if (magnitude <= 0x3f490fd8) {
        return __kernel_sinf(x, 0.0f, 0);
    }
    if (magnitude > 0x7f7fffff) {
        float self = x;
        return x - self;
    }
    quadrant = __ieee754_rem_pio2f(x, parts);
    switch (quadrant & 3) {
    case 0:
        return __kernel_sinf(parts[0], parts[1], 1);
    case 1:
        return __kernel_cosf(parts[0], parts[1]);
    case 2:
        return -__kernel_sinf(parts[0], parts[1], 1);
    default:
        return -__kernel_cosf(parts[0], parts[1]);
    }
}
