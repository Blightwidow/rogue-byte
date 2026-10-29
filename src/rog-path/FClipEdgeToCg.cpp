typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 ClsgClipEdgeToCg(s32, s32, s32, s32, s8 *, s32);
s32 FClipEdgeToCg(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0xC0] __attribute__((aligned(16)));
    s32 clipped = ClsgClipEdgeToCg(arg0, arg1, arg2, 2, sp, arg3 | 2);
    s32 result = 0;
    if (clipped == 0 || *(f32 *)(sp + 0x40) != 0.0f || *(f32 *)(sp + 0x44) != 1.0f) {
        result = 1;
    }
    return result;
}
}
