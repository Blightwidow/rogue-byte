extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
float __ieee754_sqrtf(float);
float func_00244EF8(float);
static const float one = 1.0f;
static const float huge = 1.0e30f;
static const float pio2_hi = 1.5707962513e+00f;
static const float pio2_lo = 7.5497894159e-08f;
static const float pio4_hi = 7.8539818525e-01f;
static const float pS0 = 1.6666667163e-01f;
static const float pS1 = -3.2556581497e-01f;
static const float pS2 = 2.0121252537e-01f;
static const float pS3 = -4.0055535734e-02f;
static const float pS4 = 7.9153501429e-04f;
static const float pS5 = 3.4793309169e-05f;
static const float qS1 = -2.4033949375e+00f;
static const float qS2 = 2.0209457874e+00f;
static const float qS3 = -6.8828397989e-01f;
static const float qS4 = 7.7038154006e-02f;
float __ieee754_asinf(float x) {
    float t, w, p, q, c, r, s;
    int hx, ix;
    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000) {
        return x * pio2_hi + x * pio2_lo;
    } else if (ix > 0x3f800000) {
        return (x - x) / (x - x);
    } else if (ix < 0x3f000000) {
        if (ix < 0x32000000) {
            if (huge + x > one) {
                return x;
            }
        }
        t = x * x;
        p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
        q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
        w = p / q;
        return x + x * w;
    }
    w = one - func_00244EF8(x);
    t = w * 0.5f;
    p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
    q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
    s = __ieee754_sqrtf(t);
    if (ix > 0x3f799999) {
        w = p / q;
        t = pio2_hi - (2.0f * (s + s * w) - pio2_lo);
    } else {
        int sbits;
        GET_FLOAT_WORD(sbits, s);
        SET_FLOAT_WORD(w, sbits & 0xfffff000);
        c = (t - w * w) / (s + w);
        r = p / q;
        p = 2.0f * s * r - (pio2_lo - 2.0f * c);
        q = pio4_hi - 2.0f * w;
        t = pio4_hi - (p - q);
    }
    if (hx > 0) {
        return t;
    } else {
        return -t;
    }
}
}
