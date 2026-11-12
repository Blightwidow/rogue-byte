/* SPDX-License-Identifier: GPL-3.0-or-later */

extern "C" {
typedef struct SoftFloatNumber {
    unsigned int kind;
    unsigned int sign;
    int exponent;
    unsigned long long fraction;
} SoftFloatNumber;

extern SoftFloatNumber B_00450230;

static inline int iszero(SoftFloatNumber *number) { return number->kind == 2; }
static inline int isnan(SoftFloatNumber *number) { return number->kind < 2; }
static inline int isinf(SoftFloatNumber *number) { return number->kind == 4; }

SoftFloatNumber *func_0023D508(SoftFloatNumber *first, SoftFloatNumber *second, SoftFloatNumber *result)
{
    int firstExponent;
    int secondExponent;
    int difference;
    long long signedFraction;
    unsigned long long firstFraction;
    unsigned long long secondFraction;
    unsigned long long sum;
    unsigned long long fraction;

    if (isnan(first))
        return first;
    if (isnan(second))
        return second;
    if (isinf(first)) {
        if (isinf(second) && first->sign != second->sign)
            return &B_00450230;
        return first;
    }
    if (isinf(second))
        return second;
    if (iszero(second)) {
        if (iszero(first)) {
            *result = *first;
            result->sign = first->sign & second->sign;
            return result;
        }
        return first;
    }
    if (iszero(first))
        return second;
    firstExponent = first->exponent;
    secondExponent = second->exponent;
    firstFraction = first->fraction;
    difference = firstExponent - secondExponent;
    secondFraction = second->fraction;
    if (difference < 0)
        difference = -difference;
    if (difference < 0x40) {
        while (secondExponent < firstExponent) {
            secondExponent++;
            secondFraction = (secondFraction & 1) | (secondFraction >> 1);
        }
        while (firstExponent < secondExponent) {
            firstFraction = (firstFraction & 1) | (firstFraction >> 1);
            firstExponent++;
        }
    } else if (secondExponent < firstExponent) {
        secondFraction = 0;
    } else {
        firstExponent = secondExponent;
        firstFraction = 0;
    }
    sum = firstFraction + secondFraction;
    if (first->sign != second->sign) {
        if (first->sign)
            signedFraction = secondFraction - firstFraction;
        else
            signedFraction = firstFraction - secondFraction;
        if (signedFraction >= 0) {
            result->exponent = firstExponent;
            result->fraction = signedFraction;
            result->sign = 0;
        } else {
            result->exponent = firstExponent;
            result->fraction = -signedFraction;
            result->sign = 1;
        }
        fraction = result->fraction;
        while (fraction - 1 <= ((unsigned long long)-1 << 5) >> 4) {
            fraction = fraction << 1;
            result->fraction = fraction;
            result->exponent = result->exponent - 1;
        }
    } else {
        result->sign = first->sign;
        result->exponent = firstExponent;
        fraction = sum;
        result->fraction = sum;
    }
    result->kind = 3;
    if (fraction > (unsigned long long)-1 >> 3) {
        result->fraction = (fraction & 1) | (fraction >> 1);
        result->exponent = result->exponent + 1;
    }
    return result;
}
}
