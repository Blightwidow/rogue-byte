// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
extern const double RO_002AC140[2];
union DoubleWords {
    double value;
    struct { unsigned int low; int high; } word;
};
#define SPLIT_WORDS(hi_out, lo_out, source) \
    do { \
        DoubleWords split; \
        split.value = (source); \
        (hi_out) = split.word.high; \
        (lo_out) = split.word.low; \
    } while (0)
#define JOIN_WORDS(target, hi_in, lo_in) \
    do { \
        DoubleWords join; \
        join.word.high = (hi_in); \
        join.word.low = (lo_in); \
        (target) = join.value; \
    } while (0)
#define SET_HIGH_WORD(target, hi_in) \
    do { \
        DoubleWords edit; \
        edit.value = (target); \
        edit.word.high = (hi_in); \
        (target) = edit.value; \
    } while (0)
#define GET_HIGH_WORD(hi_out, source) \
    do { \
        DoubleWords read; \
        read.value = (source); \
        (hi_out) = read.word.high; \
    } while (0)
double rint(double x) {
    int highWord;
    unsigned int lowWord;
    int exponent;
    int sign;
    unsigned int mask;
    double sum;
    double result;
    DoubleWords frameSlot;
    SPLIT_WORDS(highWord, lowWord, x);
    sign = (highWord >> 31) & 1;
    exponent = ((highWord >> 20) & 0x7FF) - 0x3FF;
    if (exponent < 20) {
        if (exponent < 0) {
            if (((highWord & 0x7FFFFFFF) | lowWord) == 0) {
                return x;
            }
            lowWord |= highWord & 0xFFFFF;
            highWord &= 0xFFFE0000;
            highWord |= ((lowWord | -lowWord) >> 12) & 0x80000;
            SET_HIGH_WORD(x, highWord);
            sum = RO_002AC140[sign] + x;
            result = sum - RO_002AC140[sign];
            GET_HIGH_WORD(highWord, result);
            SET_HIGH_WORD(result, (highWord & 0x7FFFFFFF) | (sign << 31));
            return result;
        }
        mask = 0xFFFFF >> exponent;
        if (((highWord & mask) | lowWord) == 0) {
            return x;
        }
        mask >>= 1;
        if (((highWord & mask) | lowWord) != 0) {
            if (exponent == 19) {
                lowWord = 0x40000000;
            } else {
                highWord = (highWord & ~mask) | (0x20000 >> exponent);
            }
        }
    } else if (exponent > 51) {
        if (exponent == 0x400) {
            return x + x;
        }
        return x;
    } else {
        mask = 0xFFFFFFFFU >> (exponent - 20);
        if ((lowWord & mask) == 0) {
            return x;
        }
        mask >>= 1;
        if ((lowWord & mask) != 0) {
            lowWord = (lowWord & ~mask) | (0x40000000 >> (exponent - 20));
        }
    }
    JOIN_WORDS(x, highWord, lowWord);
    sum = RO_002AC140[sign] + x;
    return sum - RO_002AC140[sign];
}
}
