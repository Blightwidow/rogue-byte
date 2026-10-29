typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MarkClockTickRealOnly__FP5CLOCK {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
f32 __floatdisf(s64);                               /* extern */
f32 MarkClockTickRealOnly__FP5CLOCK(s8 *arg0) {
    s32 count = M2C_FIELD(arg0, s32 *, 0x204);
    s8 *timer;
    if (count > 0) {
        timer = M2C_FIELD(((count * 4) + arg0), s8 **, 0x204);
    } else {
        timer = NULL;
    }
    if (timer == NULL) {
        return 0.0f;
    }
    s64 ticks = M2C_FIELD(timer, s64 *, 0x68);
    f32 value;
    if (ticks >= 0) {
        value = __floatdisf(ticks);
    } else {
        value = 2.0f * __floatdisf((ticks & 1) | ((u64) ticks >> 1));
    }
    return value * 3.390842e-9f;
}
}
