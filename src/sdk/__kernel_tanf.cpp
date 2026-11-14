// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
extern const float D_002AC0F8[14];
float __kernel_tanf(float x, float y, int iy) {
    float z, r, v, w, s, t, a;
    int ix, hx;
    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix < 0x31800000) {
        if ((int)x == 0) {
            if ((ix | (iy + 1)) == 0) {
                return 1.0f / func_00244EF8(x);
            } else if (iy != 1) {
                return -1.0f / x;
            } else {
                return x;
            }
        }
    }
    if (ix >= 0x3f2ca140) {
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = 0.7853981f - x;
        w = 3.7748947e-8f - y;
        x = z + w;
        y = 0.0f;
    }
    z = x * x;
    w = z * z;
    r = D_002AC0F8[1] + w * (D_002AC0F8[3] + w * (D_002AC0F8[5] + w * (D_002AC0F8[7] + w * (D_002AC0F8[9] + w * D_002AC0F8[11]))));
    v = z * (D_002AC0F8[2] + w * (D_002AC0F8[4] + w * (D_002AC0F8[6] + w * (D_002AC0F8[8] + w * (D_002AC0F8[10] + w * D_002AC0F8[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += D_002AC0F8[0] * s;
    w = x + r;
    if (ix >= 0x3f2ca140) {
        v = (float)iy;
        return (float)(1 - ((hx >> 30) & 2)) * (v - 2.0f * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1) {
        return w;
    } else {
        int bits;
        GET_FLOAT_WORD(bits, w);
        SET_FLOAT_WORD(z, bits & 0xfffff000);
        v = r - (z - x);
        a = -1.0f / w;
        GET_FLOAT_WORD(bits, a);
        SET_FLOAT_WORD(t, bits & 0xfffff000);
        s = 1.0f + t * z;
        return t + a * (s + t * v);
    }
}
}
