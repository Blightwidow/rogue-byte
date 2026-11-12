typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023ADA8 {};                 /* size 0x0 */
extern M2C_UNK B_0044EDD8;
s32 func_0023ADA8(s32 arg0, s32 arg1, s32 arg2) {
    s32 saved_reg_gp;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_v0;
    s8 *temp_v0_2;
    if (arg0 < 0) {
        var_v1 = (arg0 & 0x7FFFFFFF) * 0xC;
        temp_v0 = (s8 *)(var_v1 + M2C_FIELD(&B_0044EDD8, s32 *, 0xC));
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        var_v0 = M2C_FIELD(&B_0044EDD8, s32 *, 0xC);
    } else {
        var_v1 = arg0 * 0xC;
        temp_v0_2 = (s8 *)(var_v1 + M2C_FIELD(&B_0044EDD8, s32 *, 0x14));
        M2C_FIELD(temp_v0_2, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0_2, s32 *, 4) = arg2;
        var_v0 = M2C_FIELD(&B_0044EDD8, s32 *, 0x14);
    }
    M2C_FIELD((var_v1 + var_v0), s32 *, 8) = (s32) saved_reg_gp;
    return var_v0;
}
}
