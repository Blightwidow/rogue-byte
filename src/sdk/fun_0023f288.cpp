typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023F288 {};                 /* size 0x0 */
u8 *func_0023F288(u8 *arg0, s32 *arg1) {
    s32 var_t0;
    u32 var_a3;
    u8 *var_a0;
    u8 temp_a2;
    var_a0 = arg0;
    var_a3 = 0;
    var_t0 = 0;
    do {
        temp_a2 = *var_a0;
        var_a0 += 1;
        var_t0 |= (temp_a2 & 0x7F) << var_a3;
        var_a3 += 7;
    } while (temp_a2 & 0x80);
    if ((var_a3 < 0x20U) && (temp_a2 & 0x40)) {
        var_t0 |= -1 << var_a3;
    }
    *arg1 = var_t0;
    return var_a0;
}
}
