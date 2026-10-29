typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0013FAD0 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 IdCurrentLevel();                               /* extern */
s32 func_0013FAD0(s32 arg0, s16 *arg1) {
    s16 *var_a1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    temp_v0 = IdCurrentLevel();
    var_a1 = arg1;
    if (temp_v0 != -1) {
        var_v1 = 0;
loop_4:
        var_v0 = 0;
        if (var_v1 < arg0) {
            var_a1 += 2;
            if (*var_a1 == temp_v0) {
                goto block_6;
            }
            var_v1 += 1;
            goto loop_4;
        }
    } else {
block_6:
        var_v0 = 1;
    }
    return var_v0;
}
}
