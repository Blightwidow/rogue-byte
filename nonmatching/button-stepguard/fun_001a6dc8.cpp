typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A6DC8 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK SetLoGrfzon(s8 *, s32);                    /* extern */
void func_001A6DC8(s8 *arg0, s32 arg1) {
    s8 *var_s0;
    var_s0 = M2C_FIELD(arg0, s8 **, 0x64);
    M2C_FIELD(arg0, s8 *, 0x2D) = arg1;
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, s64 *, 0x28) & (0x8000L << 0x2B))) {
                SetLoGrfzon(var_s0, arg1);
            }
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x24);
        } while (var_s0 != NULL);
    }
}
}
