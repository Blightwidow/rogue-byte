// SPDX-License-Identifier: GPL-3.0-or-later
extern int __ieee754_rem_pio2f(float x, float *y);
extern float __kernel_tanf(float x, float y, int iy);
typedef union { float value; int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
float tanf(float x) {
    float y[2];
    int n, ix, hx;
    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fda) {
        return __kernel_tanf(x, 0.0f, 1);
    } else if (ix >= 0x7f800000) {
        return x - x;
    } else {
        n = __ieee754_rem_pio2f(x, y);
        return __kernel_tanf(y[0], y[1], 1 - ((n & 1) << 1));
    }
}
