// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; unsigned long l; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0, ix1, d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i, d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define SET_HIGH_WORD(d, v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define SET_LOW_WORD(d, v) do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
double func_00249C28(double); /* fabs, called out of line (the compiler expands the fabs name inline) */
double __ieee754_sqrt(double);
double func_00249EE0(double, int); /* scalbn */
static const double bp[] = { 1.0, 1.5 };
static const double dp_h[] = { 0.0, 5.84962487220764160156e-01 }; /* 0x3FE2B803, 0x40000000 */
static const double dp_l[] = { 0.0, 1.35003920212974897128e-08 }; /* 0x3E4CFDEB, 0x43CFD006 */
static const double zero = 0.0;
static const double one = 1.0;
static const double two = 2.0;
static const double two53 = 9007199254740992.0; /* 0x43400000, 0x00000000 */
static const double huge = 1.0e300;
static const double tiny = 1.0e-300;
/* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
static const double L1 = 5.99999999999994648725e-01; /* 0x3FE33333, 0x33333303 */
static const double L2 = 4.28571428578550184252e-01; /* 0x3FDB6DB6, 0xDB6FABFF */
static const double L3 = 3.33333329818377432918e-01; /* 0x3FD55555, 0x518F264D */
static const double L4 = 2.72728123808534006489e-01; /* 0x3FD17460, 0xA91D4101 */
static const double L5 = 2.30660745775561754067e-01; /* 0x3FCD864A, 0x93C9DB65 */
static const double L6 = 2.06975017800338417784e-01; /* 0x3FCA7E28, 0x4A454EEF */
static const double P1 = 1.66666666666666019037e-01; /* 0x3FC55555, 0x5555553E */
static const double P2 = -2.77777777770155933842e-03; /* 0xBF66C16C, 0x16BEBD93 */
static const double P3 = 6.61375632143793436117e-05; /* 0x3F11566A, 0xAF25DE2C */
static const double P4 = -1.65339022054652515390e-06; /* 0xBEBBBD41, 0xC5D26BF1 */
static const double P5 = 4.13813679705723846039e-08; /* 0x3E663769, 0x72BEA4D0 */
static const double lg2 = 6.93147180559945286227e-01; /* 0x3FE62E42, 0xFEFA39EF */
static const double lg2_h = 6.93147182464599609375e-01; /* 0x3FE62E43, 0x00000000 */
static const double lg2_l = -1.90465429995776804525e-09; /* 0xBE205C61, 0x0CA86C39 */
static const double ovt = 8.0085662595372944372e-0017; /* 0x3C971547, 0x652B82FE */
static const double cp = 9.61796693925975554329e-01; /* 0x3FEEC709, 0xDC3A03FD */
static const double cp_h = 9.61796700954437255859e-01; /* 0x3FEEC709, 0xE0000000 */
static const double cp_l = -7.02846165095275826516e-09; /* 0xBE3E2FE0, 0x145B01F5 */
static const double ivln2 = 1.44269504088896338700e+00; /* 0x3FF71547, 0x652B82FE */
static const double ivln2_h = 1.44269502162933349609e+00; /* 0x3FF71547, 0x60000000 */
static const double ivln2_l = 1.92596299112661746887e-08; /* 0x3E54AE0B, 0xF85DDF44 */

double __ieee754_pow(double x, double y)
{
    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    int i, j, k, yisint, n;
    int hx, hy, ix, iy;
    unsigned int lx, ly;

    EXTRACT_WORDS(hx, lx, x);
    EXTRACT_WORDS(hy, ly, y);
    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    if ((iy | ly) == 0)
        return one;

    if (ix > 0x7ff00000 || (ix == 0x7ff00000 && lx != 0) || iy > 0x7ff00000 || (iy == 0x7ff00000 && ly != 0))
        return x + y;

    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x43400000)
            yisint = 2;
        else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;
            if (k > 20) {
                j = ly >> (52 - k);
                if ((j << (52 - k)) == ly)
                    yisint = 2 - (j & 1);
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy)
                    yisint = 2 - (j & 1);
            }
        }
    }

    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0)
                return y - y;
            else if (ix >= 0x3ff00000)
                return (hy >= 0) ? y : zero;
            else
                return (hy < 0) ? -y : zero;
        }
        if (iy == 0x3ff00000) {
            if (hy < 0)
                return one / x;
            else
                return x;
        }
        if (hy == 0x40000000)
            return x * x;
        if (hy == 0x3fe00000) {
            if (hx >= 0)
                return __ieee754_sqrt(x);
        }
    }

    ax = func_00249C28(x);
    if (lx == 0) {
        if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
            z = ax;
            if (hy < 0)
                z = one / z;
            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0)
                    z = (z - z) / (z - z);
                else if (yisint == 1)
                    z = -z;
            }
            return z;
        }
    }

    if (((((unsigned int)hx >> 31) - 1) | yisint) == 0)
        return (x - x) / (x - x);

    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff)
                return (hy < 0) ? huge * huge : tiny * tiny;
            if (ix >= 0x3ff00000)
                return (hy > 0) ? huge * huge : tiny * tiny;
        }
        if (ix < 0x3fefffff)
            return (hy < 0) ? huge * huge : tiny * tiny;
        if (ix > 0x3ff00000)
            return (hy > 0) ? huge * huge : tiny * tiny;
        t = x - one;
        w = (t * t) * (0.5 - t * (0.3333333333333333333333 - t * 0.25));
        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;
        t1 = u + v;
        SET_LOW_WORD(t1, 0);
        t2 = v - (t1 - u);
    } else {
        double s2, s_h, s_l, t_h, t_l;
        n = 0;
        if (ix < 0x00100000) {
            ax *= two53;
            n -= 53;
            GET_HIGH_WORD(ix, ax);
        }
        n += ((ix) >> 20) - 0x3ff;
        j = ix & 0x000fffff;
        ix = j | 0x3ff00000;
        if (j <= 0x3988E)
            k = 0;
        else if (j < 0xBB67A)
            k = 1;
        else {
            k = 0;
            n += 1;
            ix -= 0x00100000;
        }
        SET_HIGH_WORD(ax, ix);

        u = ax - bp[k];
        v = one / (ax + bp[k]);
        s = u * v;
        s_h = s;
        SET_LOW_WORD(s_h, 0);
        t_h = zero;
        SET_HIGH_WORD(t_h, ((ix >> 1) | 0x20000000) + 0x00080000 + (k << 18));
        t_l = ax - (t_h - bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);
        s2 = s * s;
        r = s2 * s2 * (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + s2 * L6)))));
        r += s_l * (s_h + s);
        s2 = s_h * s_h;
        t_h = 3.0 + s2 + r;
        SET_LOW_WORD(t_h, 0);
        t_l = r - ((t_h - 3.0) - s2);
        u = s_h * t_h;
        v = s_l * t_h + t_l * s;
        p_h = u + v;
        SET_LOW_WORD(p_h, 0);
        p_l = v - (p_h - u);
        z_h = cp_h * p_h;
        z_l = cp_l * p_h + p_l * cp + dp_l[k];
        t = (double)n;
        t1 = (((z_h + z_l) + dp_h[k]) + t);
        SET_LOW_WORD(t1, 0);
        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    s = one;
    if (((((unsigned int)hx >> 31) - 1) | (yisint - 1)) == 0)
        s = -one;

    y1 = y;
    SET_LOW_WORD(y1, 0);
    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    EXTRACT_WORDS(j, i, z);
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0)
            return s * huge * huge;
        else {
            if (p_l + ovt > z - p_h)
                return s * huge * huge;
        }
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - 0xc090cc00) | i) != 0)
            return s * tiny * tiny;
        else {
            if (p_l <= z - p_h)
                return s * tiny * tiny;
        }
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;
    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;
        t = zero;
        SET_HIGH_WORD(t, n & ~(0x000fffff >> k));
        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0)
            n = -n;
        p_h -= t;
    }
    t = p_l + p_h;
    SET_LOW_WORD(t, 0);
    u = t * lg2_h;
    v = (p_l - (t - p_h)) * lg2 + t * lg2_l;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
    r = (z * t1) / (t1 - two) - (w + z * w);
    z = one - (r - z);
    GET_HIGH_WORD(j, z);
    j += (n << 20);
    if ((j >> 20) <= 0)
        z = func_00249EE0(z, n);
    else
        SET_HIGH_WORD(z, j);
    return s * z;
}
}
