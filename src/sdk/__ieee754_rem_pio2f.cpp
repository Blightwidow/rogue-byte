// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const int RO_002ABFB0[];
extern const int RO_002ABC98[];
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
int __kernel_rem_pio2f(float *, float *, int, int, int, const int *);
static const float zero = 0.0f;
static const float half = 5.0000000000e-01f;
static const float two8 = 2.5600000000e+02f;
static const float invpio2 = 6.36619806e-01f;
static const float pio2_1 = 1.57078552e+00f;
static const float pio2_1t = 1.08043341e-05f;
static const float pio2_2 = 1.08042732e-05f;
static const float pio2_2t = 6.07709993e-11f;
static const float pio2_3 = 6.07709438e-11f;
static const float pio2_3t = 6.12323426e-17f;
int __ieee754_rem_pio2f(float x, float *y)
{
    float z, w, t, r, fn;
    float tx[3];
    int e0, i, j, nx, n, ix, hx;
    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fd8) {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4016cbe4) {
        if (hx > 0) {
            z = x - pio2_1;
            if ((ix & 0xfffffff0) != 0x3fc90fd0) {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = x + pio2_1;
            if ((ix & 0xfffffff0) != 0x3fc90fd0) {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            } else {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x43490f80) {
        t = func_00244EF8(x);
        n = (int)(t * invpio2 + half);
        fn = (float)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && (ix & 0xffffff00) != (unsigned)RO_002ABFB0[n - 1]) {
            y[0] = r - w;
        } else {
            unsigned int high;
            j = ix >> 23;
            y[0] = r - w;
            GET_FLOAT_WORD(high, y[0]);
            i = j - ((high >> 23) & 0xff);
            if (i > 8) {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                GET_FLOAT_WORD(high, y[0]);
                i = j - ((high >> 23) & 0xff);
                if (i > 25) {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        return n;
    }
    if (ix > 0x7f7fffff) {
        y[0] = y[1] = x - x;
        return 0;
    }
    e0 = (ix >> 23) - 134;
    SET_FLOAT_WORD(z, ix - (e0 << 23));
    for (i = 0; i < 2; i++) {
        tx[i] = (float)((int)z);
        z = (z - tx[i]) * two8;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero) {
        nx--;
    }
    n = __kernel_rem_pio2f(tx, y, e0, nx, 2, RO_002ABC98);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
}
