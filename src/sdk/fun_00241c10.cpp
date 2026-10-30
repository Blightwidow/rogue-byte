typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00241C10 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 func_00239450();                                /* extern */
M2C_UNK func_002394A0();                            /* extern */
M2C_UNK func_0023ADA8(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern s32 D_002C6764;
extern s32 D_002C6788;
extern M2C_UNK func_00241BB8;
s32 func_00241C10(void) {
    s32 temp_s0;
    D_002C6764 = 1;
    temp_s0 = func_00239450();
    func_0023ADA8(0x80000012, &func_00241BB8, 0);
    if (temp_s0 != 0) {
        func_002394A0();
    }
    D_002C6764 = 0;
    D_002C6788 = 1;
    return 1;
}
}
