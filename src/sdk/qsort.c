// SPDX-License-Identifier: GPL-3.0-or-later
typedef unsigned int size_t;
typedef int (*compare_function)(const void *, const void *);

#define SMALLER(first, second) ((first) < (second) ? (first) : (second))

#define SWAP_WORDS(TYPE, left_bytes, right_bytes, byte_count) {   \
    long remaining = (byte_count) / sizeof(TYPE);                \
    TYPE *left_item = (TYPE *)(left_bytes);                     \
    TYPE *right_item = (TYPE *)(right_bytes);                   \
    do {                                                        \
        TYPE held = *left_item;                                 \
        *left_item++ = *right_item;                             \
        *right_item++ = held;                                   \
    } while (--remaining > 0);                                  \
}

static inline void SwapBlocks(char *left, char *right, int byte_count, int swap_kind)
{
    if (swap_kind <= 1)
        SWAP_WORDS(long, left, right, byte_count)
    else
        SWAP_WORDS(char, left, right, byte_count)
}

#define SWAP_ELEMENTS(left, right)                        \
    if (swap_kind == 0) {                                 \
        long held = *(long *)(left);                      \
        *(long *)(left) = *(long *)(right);               \
        *(long *)(right) = held;                          \
    } else                                                \
        SwapBlocks(left, right, element_size, swap_kind)

#define SWAP_RANGE(left, right, byte_count) \
    if ((byte_count) > 0) SwapBlocks(left, right, byte_count, swap_kind)

static inline char *MedianOfThree(char *first, char *second, char *third, compare_function compare)
{
    return compare(first, second) < 0 ?
           (compare(second, third) < 0 ? second : (compare(first, third) < 0 ? third : first))
           : (compare(second, third) > 0 ? second : (compare(first, third) < 0 ? first : third));
}

void qsort(void *base, size_t count, size_t element_size, compare_function compare)
{
    char *equal_low, *scan_low, *scan_high, *equal_high, *lower, *middle, *upper;
    int distance, result, swap_kind, swapped;

restart:
    swap_kind = ((char *)base - (char *)0) % sizeof(long) || element_size % sizeof(long) ? 2 : element_size == sizeof(long) ? 0 : 1;
    swapped = 0;
    if (count < 7) {
        for (middle = (char *)base + element_size; middle < (char *)base + count * element_size; middle += element_size)
            for (lower = middle; lower > (char *)base && compare(lower - element_size, lower) > 0; lower -= element_size)
                SWAP_ELEMENTS(lower, lower - element_size);
        return;
    }
    middle = (char *)base + (count / 2) * element_size;
    if (count > 7) {
        lower = base;
        upper = (char *)base + (count - 1) * element_size;
        if (count > 40) {
            distance = (count / 8) * element_size;
            lower = MedianOfThree(lower, lower + distance, lower + 2 * distance, compare);
            middle = MedianOfThree(middle - distance, middle, middle + distance, compare);
            upper = MedianOfThree(upper - 2 * distance, upper - distance, upper, compare);
        }
        middle = MedianOfThree(lower, middle, upper, compare);
    }
    SWAP_ELEMENTS(base, middle);
    equal_low = scan_low = (char *)base + element_size;

    scan_high = equal_high = (char *)base + (count - 1) * element_size;
    for (;;) {
        while (scan_low <= scan_high && (result = compare(scan_low, base)) <= 0) {
            if (result == 0) {
                swapped = 1;
                SWAP_ELEMENTS(equal_low, scan_low);
                equal_low += element_size;
            }
            scan_low += element_size;
        }
        while (scan_low <= scan_high && (result = compare(scan_high, base)) >= 0) {
            if (result == 0) {
                swapped = 1;
                SWAP_ELEMENTS(scan_high, equal_high);
                equal_high -= element_size;
            }
            scan_high -= element_size;
        }
        if (scan_low > scan_high)
            break;
        SWAP_ELEMENTS(scan_low, scan_high);
        swapped = 1;
        scan_low += element_size;
        scan_high -= element_size;
    }
    if (swapped == 0) {
        for (middle = (char *)base + element_size; middle < (char *)base + count * element_size; middle += element_size)
            for (lower = middle; lower > (char *)base && compare(lower - element_size, lower) > 0; lower -= element_size)
                SWAP_ELEMENTS(lower, lower - element_size);
        return;
    }

    upper = (char *)base + count * element_size;
    result = SMALLER(equal_low - (char *)base, scan_low - equal_low);
    SWAP_RANGE(base, scan_low - result, result);
    result = SMALLER(equal_high - scan_high, upper - equal_high - element_size);
    SWAP_RANGE(scan_low, upper - result, result);
    if ((result = scan_low - equal_low) > element_size)
        qsort(base, result / element_size, element_size, compare);
    if ((result = equal_high - scan_high) > element_size) {
        base = upper - result;
        count = result / element_size;
        goto restart;
    }
}
