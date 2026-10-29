typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetBlotLabelList {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */

void SetBlotLabelList(s8 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 *var_a2;
    s32 *var_a3;
    s32 var_a0;
    s32 var_v1;
    s8 *temp_v0;

    var_a2 = arg2;
    var_a3 = arg3;
    var_a0 = 0;
    if (arg1 > 0) {
        var_a3 = (s32 *)(arg0 + 0xCC);
        var_v1 = *var_a2;
loop_2:
        var_a0 += 1;
        var_a2 += 4;
        *var_a3 = var_v1;
        var_a3 += 4;
        if (var_a0 < arg1) {
            if ((u32) var_a0 < 0xAU) {
                var_v1 = *var_a2;
                goto loop_2;
            }
        }
    }
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, s32 *, s32 *), 0x18C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x188), -1, var_a2, var_a3);
}

}
