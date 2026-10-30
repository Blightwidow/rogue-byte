typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001EC740 {};                 /* size 0x0 */
extern M2C_UNK B_003DA798;
void func_001EC740(s32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    s32 var_a0;
    u32 temp_a1;
    s8 *var_v1;
    if (arg0 < arg1) {
        var_a0 = arg1 - arg0;
        var_v1 = (s8 *)((arg0 * 0x14) + &B_003DA798);
        do {
            temp_a1 = M2C_FIELD(var_v1, u32 *, 8);
            if ((temp_a1 >= arg3) && (temp_a1 < (u32) (arg3 + arg2))) {
                M2C_FIELD(var_v1, u32 *, 8) = (u32) (arg4 + (temp_a1 - arg3));
            }
            var_a0 -= 1;
            var_v1 += 0x14;
        } while (var_a0 != 0);
    }
}
}
