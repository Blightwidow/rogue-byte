typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpAtan2 {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x28];
};                                                  /* size = 0x30 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
f32 atan2f(s32, M2C_UNK, s8 *, f32, f32);         /* extern */
s8 *RefOpAtan2(s8 *arg0, s8 * unused_arg1, s8 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 *var_v1;
    s32 var_a0;
    s32 var_f0;
    s8 *var_a2;
    var_a2 = arg2;
    var_v1 = (s32 *)(sp);
    var_a0 = 1;
    do {
        if (M2C_FIELD(var_a2, s32 *, 0) == 0x16) {
            var_f0 = M2C_FIELD(var_a2, s32 *, 4);
        } else {
            var_f0 = M2C_BITWISE(s32, (f32) M2C_FIELD(var_a2, s32 *, 4));
        }
        var_v1 += 1;
        *var_v1 = var_f0;
        var_a0 -= 1;
        var_a2 += 8;
    } while (var_a0 >= 0);
    M2C_FIELD(arg0, f32 *, 4) = atan2f(var_a0, 0x16, var_a2, sp0, sp4);
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
}
