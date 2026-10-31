typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00236E30 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s32 func_0023AFE8(M2C_UNK, s8 *, M2C_UNK, s32, s32, s32); /* extern */
s32 func_00236E30(s8 * unused_arg0, s8 * unused_arg1, s8 * unused_arg2, s8 *arg3) {
    return (func_0023AFE8(0x80000008, arg3, 0x40, M2C_FIELD(arg3, s32 *, 0x24), M2C_FIELD(arg3, s32 *, 0x28), M2C_FIELD(arg3, s32 *, 0x2C)) != 0) ? 0 : 0x800;
}
}
