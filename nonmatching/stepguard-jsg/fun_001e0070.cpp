typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001E0070 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK memmove(s32 *, s8 *, s32, s32);           /* extern */

void func_001E0070(s8 *arg0, s32 arg1) {
    s32 *var_a0;
    s32 var_a2;
    s8 *var_a1;

    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x84) > 0) {
        var_a1 = arg0 + 0x8C;
        var_a0 = (s32 *)(arg0 + 0x88);
loop_2:
        if (*var_a0 != arg1) {
            var_a2 += 1;
            var_a1 += 4;
            var_a0 += 4;
            if (var_a2 >= M2C_FIELD(arg0, s32 *, 0x84)) {

            } else {
                goto loop_2;
            }
        } else {
            memmove(var_a0, var_a1, ((M2C_FIELD(arg0, s32 *, 0x84) - var_a2) * 4) - 4, arg1);
            M2C_FIELD(arg0, s32 *, 0x84) = (s32) (M2C_FIELD(arg0, s32 *, 0x84) - 1);
        }
    }
}

}
