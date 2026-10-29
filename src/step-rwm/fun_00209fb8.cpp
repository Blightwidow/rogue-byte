typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00209FB8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 FIsGuardInSgs(s32, s32);                    /* extern */
M2C_UNK func_0017A8C8(s32, M2C_UNK);                /* extern */
s32 func_00205458(s32, M2C_UNK);                    /* extern */
void func_00209FB8(s32 arg0) {
    if ((FIsGuardInSgs(arg0, 0x16) != 0) || (FIsGuardInSgs(arg0, 0x13) != 0)) {
        func_0017A8C8(func_00205458(arg0, 0xB0), 3);
    }
}
}
