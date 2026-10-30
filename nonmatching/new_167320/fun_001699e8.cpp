typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001699E8 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[0xA8];
};                                                  /* size = 0xD0 */
M2C_UNK func_00169AC8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
void func_001699E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0) {
    s32 sp20;
    s32 sp24;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    sp20 = arg0;
    sp24 = arg5;
    if (arg4 > 0) {
        var_s3 = arg4;
        var_s0 = arg3;
        var_s2 = arg2 + 0x28;
        var_s1 = arg1 + 0x14;
        do {
            var_s0 += 0x18;
            func_00169AC8(sp20, arg1, arg2, arg3, var_s1, var_s2, (arg3 != 0) ? var_s0 : 0, sp24, arg6, arg7, arg_sp0);
            var_s2 += 0x28;
            var_s3 -= 1;
            var_s1 += 0x14;
        } while (var_s3 != 0);
    }
}
}
