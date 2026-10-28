#include "sly2.h"
float GTrunc(float value)
{
    union { float f; unsigned u; } bits;
    bits.f = value;
    unsigned raw = bits.u;
    int exponent = (int)((raw >> 23) & 0xFF) - 0x7F;
    if (exponent < 0)
        return 0.0f;
    if (exponent < 0x17) {
        int dropped = (int)((1UL << (0x17 - exponent)) - 1);
        unsigned mantissa = raw & 0x7FFFFF;
        if ((mantissa & dropped) == dropped) {
            bits.u = (raw & 0xFF800000u) | (mantissa & ~dropped & 0x7FFFFF);
            value = bits.f;
            value += 1.0f;
        } else {
            bits.u = (raw & 0xFF800000u) | (mantissa & ~dropped & 0x7FFFFF);
            value = bits.f;
        }
    }
    return value;
}
