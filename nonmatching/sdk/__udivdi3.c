/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;

typedef union {
    u64 whole;
    struct {
        s32 low;
        s32 high;
    } half;
} Word64;

/* 0x2AB018 (this object's copy): bit length of every byte value (0 for 0, 8 for 0x80 and up). */
extern const unsigned char RO_002AB018[256];

#define HALF_BASE 0x10000UL

#define WORD_BITS 32

/* Leading zero bits of a word: a byte search for wide words, two comparisons and the table for 32-bit ones. */
#define COUNT_LEADING_ZEROS(count, value) \
    do { \
        u32 shiftedValue = (value); \
        u32 byteShift; \
        if (WORD_BITS <= 32) { \
            byteShift = shiftedValue < 0x10000 ? (shiftedValue < 0x100 ? 0 : 8) : (shiftedValue < 0x1000000 ? 16 : 24); \
        } else { \
            for (byteShift = WORD_BITS - 8; byteShift > 0; byteShift -= 8) \
                if (((shiftedValue >> byteShift) & 0xFF) != 0) \
                    break; \
        } \
        (count) = WORD_BITS - (RO_002AB018[shiftedValue >> byteShift] + byteShift); \
    } while (0)

/* Divides the two-word numerator by a normalized one-word divisor, sixteen bits of quotient at a time. */
#define DIVIDE_TWO_WORDS(quotient, remainder, numeratorHigh, numeratorLow, divisor) \
    do { \
        u32 divisorUpper = (divisor) >> 16; \
        u32 divisorLower = (divisor) & 0xFFFF; \
        u32 upperQuotient, lowerQuotient, upperRemainder, lowerRemainder, product; \
        upperRemainder = (numeratorHigh) % divisorUpper; \
        upperQuotient = (numeratorHigh) / divisorUpper; \
        product = upperQuotient * divisorLower; \
        upperRemainder = upperRemainder * HALF_BASE | ((numeratorLow) >> 16); \
        if (upperRemainder < product) { \
            upperQuotient--; \
            upperRemainder += (divisor); \
            if (upperRemainder >= (divisor)) \
                if (upperRemainder < product) { \
                    upperQuotient--; \
                    upperRemainder += (divisor); \
                } \
        } \
        upperRemainder -= product; \
        lowerRemainder = upperRemainder % divisorUpper; \
        lowerQuotient = upperRemainder / divisorUpper; \
        product = lowerQuotient * divisorLower; \
        lowerRemainder = lowerRemainder * HALF_BASE | ((numeratorLow) & 0xFFFF); \
        if (lowerRemainder < product) { \
            lowerQuotient--; \
            lowerRemainder += (divisor); \
            if (lowerRemainder >= (divisor)) \
                if (lowerRemainder < product) { \
                    lowerQuotient--; \
                    lowerRemainder += (divisor); \
                } \
        } \
        lowerRemainder -= product; \
        (quotient) = upperQuotient * HALF_BASE | lowerQuotient; \
        (remainder) = lowerRemainder; \
    } while (0)

/* Two-word subtraction with borrow. */
#define SUBTRACT_TWO_WORDS(differenceHigh, differenceLow, leftHigh, leftLow, rightHigh, rightLow) \
    do { \
        u32 borrowLow = (leftLow) - (rightLow); \
        (differenceHigh) = (leftHigh) - (rightHigh) - (borrowLow > (leftLow)); \
        (differenceLow) = borrowLow; \
    } while (0)

static inline u64 DivideWithRemainder(u64 numerator, u64 denominator, u64 *remainderPointer) {
    Word64 numeratorWord;
    Word64 denominatorWord;
    Word64 remainderWord;
    Word64 result;
    u32 denominatorLow, denominatorHigh;
    u32 numeratorLow, numeratorHigh, numeratorTop;
    u32 quotientHigh, quotientLow;
    u32 leadingZeros, complement;

    numeratorWord.whole = numerator;
    denominatorWord.whole = denominator;
    denominatorLow = denominatorWord.half.low;
    denominatorHigh = denominatorWord.half.high;
    numeratorLow = numeratorWord.half.low;
    numeratorHigh = numeratorWord.half.high;

    if (denominatorHigh == 0) {
        if (denominatorLow > numeratorHigh) {
            COUNT_LEADING_ZEROS(leadingZeros, denominatorLow);
            if (leadingZeros != 0) {
                denominatorLow = denominatorLow << leadingZeros;
                numeratorHigh = (numeratorHigh << leadingZeros) | (numeratorLow >> (32 - leadingZeros));
                numeratorLow = numeratorLow << leadingZeros;
            }
            DIVIDE_TWO_WORDS(quotientLow, numeratorLow, numeratorHigh, numeratorLow, denominatorLow);
            quotientHigh = 0;
        } else {
            if (denominatorLow == 0) {
                denominatorLow = 1 / denominatorLow;
            }
            COUNT_LEADING_ZEROS(leadingZeros, denominatorLow);
            if (leadingZeros == 0) {
                numeratorHigh -= denominatorLow;
                quotientHigh = 1;
            } else {
                complement = 32 - leadingZeros;
                denominatorLow = denominatorLow << leadingZeros;
                numeratorTop = numeratorHigh >> complement;
                numeratorHigh = (numeratorHigh << leadingZeros) | (numeratorLow >> complement);
                numeratorLow = numeratorLow << leadingZeros;
                DIVIDE_TWO_WORDS(quotientHigh, numeratorHigh, numeratorTop, numeratorHigh, denominatorLow);
            }
            DIVIDE_TWO_WORDS(quotientLow, numeratorLow, numeratorHigh, numeratorLow, denominatorLow);
        }
        if (remainderPointer != 0) {
            remainderWord.half.low = numeratorLow >> leadingZeros;
            remainderWord.half.high = 0;
            *remainderPointer = remainderWord.whole;
        }
    } else {
        if (denominatorHigh > numeratorHigh) {
            quotientLow = 0;
            quotientHigh = 0;
            if (remainderPointer != 0) {
                remainderWord.half.low = numeratorLow;
                remainderWord.half.high = numeratorHigh;
                *remainderPointer = remainderWord.whole;
            }
        } else {
            COUNT_LEADING_ZEROS(leadingZeros, denominatorHigh);
            if (leadingZeros == 0) {
                if (numeratorHigh > denominatorHigh || numeratorLow >= denominatorLow) {
                    quotientLow = 1;
                    SUBTRACT_TWO_WORDS(numeratorHigh, numeratorLow, numeratorHigh, numeratorLow, denominatorHigh, denominatorLow);
                } else {
                    quotientLow = 0;
                }
                quotientHigh = 0;
                if (remainderPointer != 0) {
                    remainderWord.half.low = numeratorLow;
                    remainderWord.half.high = numeratorHigh;
                    *remainderPointer = remainderWord.whole;
                }
            } else {
                u32 productHigh, productLow;
                complement = 32 - leadingZeros;
                denominatorHigh = (denominatorHigh << leadingZeros) | (denominatorLow >> complement);
                denominatorLow = denominatorLow << leadingZeros;
                numeratorTop = numeratorHigh >> complement;
                numeratorHigh = (numeratorHigh << leadingZeros) | (numeratorLow >> complement);
                numeratorLow = numeratorLow << leadingZeros;
                DIVIDE_TWO_WORDS(quotientLow, numeratorHigh, numeratorTop, numeratorHigh, denominatorHigh);
                productHigh = ((u64)quotientLow * denominatorLow) >> 32;
                productLow = quotientLow * denominatorLow;
                if (productHigh > numeratorHigh || (productHigh == numeratorHigh && productLow > numeratorLow)) {
                    quotientLow--;
                    SUBTRACT_TWO_WORDS(productHigh, productLow, productHigh, productLow, denominatorHigh, denominatorLow);
                }
                quotientHigh = 0;
                if (remainderPointer != 0) {
                    SUBTRACT_TWO_WORDS(numeratorHigh, numeratorLow, numeratorHigh, numeratorLow, productHigh, productLow);
                    remainderWord.half.low = (numeratorHigh << complement) | (numeratorLow >> leadingZeros);
                    remainderWord.half.high = numeratorHigh >> leadingZeros;
                    *remainderPointer = remainderWord.whole;
                }
            }
        }
    }

    result.half.low = quotientLow;
    result.half.high = quotientHigh;
    return result.whole;
}

u64 __udivdi3(u64 numerator, u64 denominator) {
    return DivideWithRemainder(numerator, denominator, (u64 *)0);
}
