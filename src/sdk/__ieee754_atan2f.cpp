// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float atanf(float);
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
extern const float D_002ABBFC[3];
float __ieee754_atan2f(float y, float x) {
    float z;
    int quadrant, difference, xbits, ybits, xmagnitude, ymagnitude;
    GET_FLOAT_WORD(xbits, x);
    xmagnitude = xbits & 0x7fffffff;
    GET_FLOAT_WORD(ybits, y);
    ymagnitude = ybits & 0x7fffffff;
    if (xmagnitude > 0x7f800000 || ymagnitude > 0x7f800000) {
        return x + y;
    }
    if (xbits == 0x3f800000) {
        return atanf(y);
    }
    quadrant = ((ybits >> 31) & 1) | ((xbits >> 30) & 2);
    if (ymagnitude == 0) {
        switch (quadrant) {
        case 0:
        case 1:
            return y;
        case 2:
            return 3.1415925f;
        case 3:
            return -3.1415925f;
        }
    }
    if (xmagnitude == 0) {
        return ybits < 0 ? -1.5707964f : 1.5707964f;
    }
    if (xmagnitude == 0x7f800000) {
        if (ymagnitude == 0x7f800000) {
            switch (quadrant) {
            case 0:
                return 0.7853982f;
            case 1:
                return -0.7853982f;
            case 2:
                return 2.3561945f;
            case 3:
                return -2.3561945f;
            }
        } else {
            switch (quadrant) {
            case 0:
                return 0.0f;
            case 1:
                return D_002ABBFC[0];
            case 2:
                return 3.1415925f;
            case 3:
                return -3.1415925f;
            }
        }
    }
    if (ymagnitude == 0x7f800000) {
        return ybits < 0 ? -1.5707964f : 1.5707964f;
    }
    difference = (ymagnitude - xmagnitude) >> 23;
    if (difference > 60) {
        z = 1.5707965f;
    } else if (xbits < 0 && difference < -60) {
        z = 0.0f;
    } else {
        z = atanf(func_00244EF8(y / x));
    }
    switch (quadrant) {
    case 0:
        return z;
    case 1: {
        unsigned int zbits;
        GET_FLOAT_WORD(zbits, z);
        SET_FLOAT_WORD(z, zbits ^ 0x80000000);
        return z;
    }
    case 2:
        return 3.1415925f - (z - 1.5099579e-07f);
    default:
        return (z - 1.5099579e-07f) - 3.1415925f;
    }
}
}
