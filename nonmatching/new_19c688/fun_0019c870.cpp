typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0019C870 {};                 /* size 0x0 */
s32 func_0019C870(s8 *arg0, s32 *arg1) {
    s32 temp_v1;
    s32 var_v0;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (temp_v1 < 0xB) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC0);
    } else if (temp_v1 < 0xE) {
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x520);
    } else if (temp_v1 == 0x11) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC4);
    } else {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC0);
    }
    *arg1 = 0;
    return var_v0;
}
}
