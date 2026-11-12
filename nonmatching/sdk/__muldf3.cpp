extern "C" {
typedef unsigned long long UDI;
typedef unsigned int USI;
typedef struct { USI cls; USI sign; int exp; UDI frac; } fpd;
extern void func_0023D468(double *, fpd *);
extern double func_0023D338(fpd *);
extern fpd B_00450230;
static inline int iszero(fpd *p) { return p->cls == 2; }
static inline int isnan(fpd *p) { return p->cls < 2; }
static inline int isinf(fpd *p) { return p->cls == 4; }
static inline fpd *fpmulParts(fpd *a, fpd *b, fpd *tmp) {
    UDI low = 0;
    UDI high = 0;
    if (isnan(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isnan(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    if (isinf(a)) {
        if (iszero(b))
            return &B_00450230;
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isinf(b)) {
        if (iszero(a))
            return &B_00450230;
        b->sign = a->sign != b->sign;
        return b;
    }
    if (iszero(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    {
        UDI nl = a->frac & 0xffffffff;
        UDI nh = a->frac >> 32;
        UDI ml = b->frac & 0xffffffff;
        UDI mh = b->frac >> 32;
        UDI partialLowLow = ml * nl;
        UDI partialHighLow = mh * nl;
        UDI partialLowHigh = ml * nh;
        UDI partialHighHigh = mh * nh;
        UDI result2 = 0;
        UDI result0 = 0;
        UDI middle = partialHighLow + partialLowHigh;
        if (middle < partialHighLow)
            result2 += (UDI)1 << 32;
        partialHighLow = (middle << 32) & 0xffffffff00000000ULL;
        result0 = partialLowLow + partialHighLow;
        if (result0 < partialLowLow)
            result2++;
        result2 += ((middle >> 32) & 0xffffffff) + partialHighHigh;
        high = result2;
        low = result0;
    }
    tmp->exp = a->exp + b->exp + 4;
    tmp->sign = a->sign != b->sign;
    while (high >= 0x2000000000000000ULL) {
        tmp->exp++;
        if (high & 1) {
            low >>= 1;
            low |= 0x8000000000000000ULL;
        }
        high >>= 1;
    }
    while (high < 0x1000000000000000ULL) {
        tmp->exp--;
        high <<= 1;
        if (low & 0x8000000000000000ULL)
            high |= 1;
        low <<= 1;
    }
    if ((high & 0xFF) == 0x80) {
        if (high & 0x100)
            high += 0x80;
        else if (low)
            high += 0x80;
    }
    tmp->cls = 3;
    tmp->frac = high;
    return tmp;
}
double __muldf3(double a, double b) {
    fpd x, y, z;
    func_0023D468(&a, &x);
    func_0023D468(&b, &y);
    return func_0023D338(fpmulParts(&x, &y, &z));
}
}
