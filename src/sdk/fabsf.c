/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

/* Retail: mfc1 the argument's bits to $v1, mask the sign bit with 0x7FFFFFFF, mtc1 back to $f0,
   no stack frame. The float word is read and written through the same union macros as the
   matched fabs and __kernel_sinf, so the integer word stays in one register. */
float fabsf(float x) {
    unsigned int word;
    GET_FLOAT_WORD(word, x);
    SET_FLOAT_WORD(x, word & 0x7fffffff);
    return x;
}
