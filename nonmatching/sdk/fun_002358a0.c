int func_002358A0(unsigned long bits)
{
    unsigned long mantissa;
    long exponent;
    mantissa = bits;
    exponent = (long)((mantissa << 1) >> 53) - 0x433;
    if (exponent < -0x35) {
        return 0;
    }
    if (exponent >= 0xD) {
        return 0x270F;
    }
    mantissa = ((mantissa << 12) >> 12) | 0x10000000000000UL;
    if (exponent < 0) {
        mantissa >>= (int)(-exponent - 2);
        if ((mantissa & 3) == 3) {
            mantissa = (mantissa >> 2) + 1;
        } else {
            mantissa >>= 2;
        }
    } else {
        mantissa <<= (int)exponent;
    }
    return mantissa;
}
