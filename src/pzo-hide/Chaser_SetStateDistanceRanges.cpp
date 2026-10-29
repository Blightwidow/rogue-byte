typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct Bytes8 { u8 b[8]; };
struct Range181330 { s32 state; s32 pad; Bytes8 lo; Bytes8 hi; s32 pad2[4]; };
void Chaser_SetStateDistanceRanges(s8 *arg0, u32 arg1, Bytes8 *arg2, Bytes8 *arg3) {
    if (arg1 < 5U) {
        Range181330 *range = (Range181330 *)(arg0 + 0x270) + arg1;
        range->state = 1;
        range->lo = *arg2;
        range->hi = *arg3;
    }
}
}
