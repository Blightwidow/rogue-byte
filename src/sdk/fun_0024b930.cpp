typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024B930 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK func_0024FA38(s32, M2C_UNK *);              /* extern */
s32 func_0024B930(s32 arg0, s8 *arg1, s32 arg2, u32 arg3) {
    s32 temp_v0;
    u32 temp_a0;
    temp_v0 = ((u32) ((M2C_FIELD(arg1, u32 *, 8) + arg3) - 1) / arg3) * arg3;
    temp_a0 = temp_v0 + arg2;
    if ((u32) (M2C_FIELD(arg1, s32 *, 0) + M2C_FIELD(arg1, s32 *, 4)) < temp_a0) {
        func_0024FA38(arg0, (M2C_UNK *)("work area size is too small"));
        return 0;
    }
    M2C_FIELD(arg1, u32 *, 8) = temp_a0;
    return temp_v0;
}
}
