typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertUserHsvToUserRgb__FP6VECTORT0 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ f32 sp8;                             /* inferred */
    /* 0x0C */ char padC[0x24];
};                                                  /* size = 0x30 */

M2C_UNK ConvertHsvToRgb__FP6VECTORT0(s8 *, s128); /* extern */

void ConvertUserHsvToUserRgb__FP6VECTORT0(s128 *arg0, s8 *arg1) {
    s8 sp[0x30] __attribute__((aligned(16)));
    f32 sp4;
    f32 sp8;

    sp4 *= 0.003921569f;
    sp8 *= 0.003921569f;
    ConvertHsvToRgb__FP6VECTORT0(sp, *arg0);
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) * 255.0f);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) * 255.0f);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) * 255.0f);
}

}
