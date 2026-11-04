#include "sly2.h"
double GTrunc(double value)
{
    union { double d; unsigned long u; } bits;
    bits.d = value;
    unsigned long raw = bits.u;
    int exponent = (int)((unsigned short)(raw >> 52) & 0x7FF) - 0x3FF;
    if (exponent < 0)
        return 0.0;
    if (exponent < 52) {
        unsigned long dropped = (1UL << (52 - exponent)) - 1;
        unsigned long mantissa = raw & 0xFFFFFFFFFFFFFUL;
        if ((mantissa & dropped) == dropped) {
            bits.u = (raw & 0xFFF0000000000000UL) | (mantissa & ~dropped & 0xFFFFFFFFFFFFFUL);
            value = bits.d;
            value += 1.0;
        } else {
            bits.u = (raw & 0xFFF0000000000000UL) | (mantissa & ~dropped & 0xFFFFFFFFFFFFFUL);
            value = bits.d;
        }
    }
    return value;
}
