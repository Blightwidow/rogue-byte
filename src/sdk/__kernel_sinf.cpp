extern "C" {
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; unsigned long l; } ieee_double_shape_type;
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define EXTRACT_WORDS(ix0, ix1, d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i, d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i, d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define SET_HIGH_WORD(d, v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const float S1 = -1.6666667163e-01f;
static const float S2 = 8.3333337680e-03f;
static const float S3 = -1.9841270114e-04f;
static const float S4 = 2.7557314297e-06f;
static const float S5 = -2.5050759689e-08f;
static const float S6 = 1.5896910177e-10f;
static const float half = 5.0000000000e-01f;
float __kernel_sinf(float x, float y, int iy) {
    float z, r, v;
    int ix;
    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000) {
        if ((int)x == 0) {
            return x;
        }
    }
    z = x * x;
    v = z * x;
    r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
    if (iy == 0) {
        return x + v * (S1 + z * r);
    } else {
        return x - ((z * (half * y - v * r) - y) - v * S1);
    }
}
}
