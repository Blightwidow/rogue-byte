extern "C" double __adddf3(double, double);
double GTrunc(double value)
{
    union { double d; unsigned long u; } in, out;
    double result;
    in.d = value;
    unsigned long bits = in.u;
    int exponent = (int)((unsigned short)(bits >> 52) & 0x7FF) - 0x3FF;
    if (exponent < 0) {
        return 0.0;
    }
    result = value;
    if (exponent < 52) {
        unsigned long mask = (1UL << (52 - exponent)) - 1;
        unsigned long fraction = ~0UL >> 12;
        unsigned long mantissa = bits & fraction;
        if ((mantissa & mask) == mask) {
            out.u = (bits & (~0UL << 52)) | (mantissa & ~mask & fraction);
            result = __adddf3(out.d, 1.0);
        } else {
            out.u = (bits & (~0UL << 52)) | (mantissa & ~mask & fraction);
            result = out.d;
        }
    }
    return result;
}
