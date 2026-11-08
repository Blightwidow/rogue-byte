typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
extern int __ieee754_rem_pio2f(float x, float *y);
extern float __kernel_cosf(float x, float y);
extern float __kernel_sinf(float x, float y, int iy);
float cosf(float x)
{
    float y[2];
    int n, ix;
    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return __kernel_cosf(x, 0.0f);
    else if (ix > 0x7f7fffff) return x - x;
    else {
        n = __ieee754_rem_pio2f(x, y);
        switch (n & 3) {
        case 0: return __kernel_cosf(y[0], y[1]);
        case 1: return -__kernel_sinf(y[0], y[1], 1);
        case 2: return -__kernel_cosf(y[0], y[1]);
        default: return __kernel_sinf(y[0], y[1], 1);
        }
    }
}
