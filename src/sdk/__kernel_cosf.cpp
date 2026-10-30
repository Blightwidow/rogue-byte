extern "C" {
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; unsigned long l; } ieee_double_shape_type;
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define EXTRACT_WORDS(ix0, ix1, d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i, d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i, d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define SET_HIGH_WORD(d, v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const float one = 1.0f;
static const float C1 = 4.1666667908e-02f;
static const float C2 = -1.3888889225e-03f;
static const float C3 = 2.4801587642e-05f;
static const float C4 = -2.7557314297e-07f;
static const float C5 = 2.0875723372e-09f;
static const float C6 = -1.1359647598e-11f;
float __kernel_cosf(float x, float y) {
    float a, hz, z, r, qx;
    int ix;
    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000) {
        if ((int)x == 0) {
            return one;
        }
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3e99999a) {
        return one - (0.5f * z - (z * r - x * y));
    } else {
        if (ix > 0x3f480000) {
            qx = 0.28125f;
        } else {
            SET_FLOAT_WORD(qx, ix - 0x01000000);
        }
        hz = 0.5f * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
}
