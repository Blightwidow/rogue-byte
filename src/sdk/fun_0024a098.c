// SPDX-License-Identifier: GPL-3.0-or-later
typedef union { float value; int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
int func_0024A098(float x) {
    int ix;
    GET_FLOAT_WORD(ix, x);
    return (int)(((unsigned)((ix & 0x7fffffff) - 0x7f800000)) >> 31);
}
