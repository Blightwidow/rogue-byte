typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;

typedef union {
    s64 whole;
    struct {
        s32 low;
        s32 high;
    } half;
} Word64;

s64 __muldi3(s64 left, s64 right) {
    Word64 leftWord;
    Word64 rightWord;
    Word64 result;
    leftWord.whole = left;
    rightWord.whole = right;
    result.whole = (u64)(u32)leftWord.half.low * (u32)rightWord.half.low;
    result.half.high += (u32)leftWord.half.high * (u32)rightWord.half.low
                      + (u32)leftWord.half.low * (u32)rightWord.half.high;
    return result.whole;
}
