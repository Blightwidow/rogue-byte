// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float __ieee754_sqrtf(float x) {
    float z;
    int bits, exponent, root, sum, trial, shift;
    unsigned int bit;
    GET_FLOAT_WORD(bits, x);
    if ((bits & 0x7f800000) == 0x7f800000) {
        return x * x + x;
    }
    if (bits <= 0) {
        if ((bits & 0x7fffffff) == 0) {
            return x;
        } else if (bits < 0) {
            return (x - x) / (x - x);
        }
    }
    exponent = bits >> 23;
    if (exponent == 0) {
        for (shift = 0; (bits & 0x00800000) == 0; shift++) {
            bits <<= 1;
        }
        exponent -= shift - 1;
    }
    exponent -= 127;
    bits = (bits & 0x007fffff) | 0x00800000;
    if (exponent & 1) {
        bits += bits;
    }
    exponent >>= 1;
    bits += bits;
    root = sum = 0;
    bit = 0x01000000;
    while (bit != 0) {
        trial = sum + bit;
        if (trial <= bits) {
            sum = trial + bit;
            bits -= trial;
            root += bit;
        }
        bits += bits;
        bit >>= 1;
    }
    if (bits != 0) {
        root += root & 1;
    }
    bits = (root >> 1) + 0x3f000000;
    bits += exponent << 23;
    SET_FLOAT_WORD(z, bits);
    return z;
}
}
