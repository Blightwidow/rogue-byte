typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ImrsgLookUp__FffiP4MRSGPf {};     /* size 0x0 */
s32 ImrsgLookUp__FffiP4MRSGPf(s32 arg0, s8 *arg1, f32 *arg2, f32 fparg0, f32 fparg1) {
    f32 temp_f2;
    f32 var_f1;
    s32 var_v1;
    s8 *var_a1;
    var_a1 = arg1;
    var_v1 = 0;
loop_3:
    if (var_v1 < arg0) {
        temp_f2 = M2C_FIELD(var_a1, f32 *, 4);
        if (temp_f2 == 0.0f) {
            var_a1 += 8;
            goto block_2;
        }
        var_f1 = fparg0 - M2C_FIELD(var_a1, f32 *, 0);
        if (var_f1 < 0.0f) {
            var_f1 += fparg1;
        }
        if (!(var_f1 < (temp_f2 + 0.0001f))) {
            var_a1 += 8;
block_2:
            var_v1 += 1;
            goto loop_3;
        }
        if (arg2 != NULL) {
            *arg2 = var_f1;
        }
    }
    return var_v1;
}
}
