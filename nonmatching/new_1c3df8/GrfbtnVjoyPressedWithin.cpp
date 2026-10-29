typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GrfbtnVjoyPressedWithin {};       /* size 0x0 */

extern f32 g_2dded0;

s32 GrfbtnVjoyPressedWithin(s32 arg0, u32 arg1, f32 fparg0) {
    f32 *var_a0;
    s32 var_a2;
    s32 var_v1;
    u32 var_a1;

    var_a1 = arg1;
    var_a2 = 0;
    var_v1 = 0;
    if (var_a1 != 0) {
        var_a0 = (f32 *)(arg0 + 0x88);
        do {
            if ((var_a1 & 1) && ((g_2dded0 - *var_a0) <= fparg0)) {
                var_a2 |= 1 << var_v1;
            }
            var_a1 = var_a1 >> 1;
            var_a0 += 1;
            var_v1 += 1;
        } while (var_a1 != 0);
    }
    return var_a2;
}

}
