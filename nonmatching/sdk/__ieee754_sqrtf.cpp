typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___ieee754_sqrtf {};               /* size 0x0 */
f32 __ieee754_sqrtf(f32 fparg0) {
    f32 temp_f0;
    f32 var_a1;
    f32 var_f0;
    s32 temp_a2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a3;
    u32 var_a2_2;
    var_a1 = fparg0;
    if ((M2C_BITWISE(s32, var_a1) & 0x7F800000) == 0x7F800000) {
        return (fparg0 * fparg0) + fparg0;
    }
    var_a2 = M2C_BITWISE(s32, var_a1) >> 0x17;
    if (M2C_BITWISE(s32, var_a1) <= 0) {
        var_f0 = fparg0;
        if (M2C_BITWISE(s32, var_a1) & 0x7FFFFFFF) {
            if (M2C_BITWISE(s32, var_a1) < 0) {
                temp_f0 = fparg0 - fparg0;
                var_f0 = temp_f0 / temp_f0;
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return var_f0;
            }
            goto block_8;
        }
        return var_f0;
    }
block_8:
    if (var_a2 == 0) {
        var_a0_2 = 0;
        if (!(M2C_BITWISE(s32, var_a1) & 0x800000)) {
            do {
                var_a1 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_a1) * 2));
                var_a0_2 += 1;
            } while (!(M2C_BITWISE(s32, var_a1) & 0x800000));
        }
        var_a2 = 1 - var_a0_2;
    }
    temp_a2 = var_a2 - 0x7F;
    var_a1_2 = (((M2C_BITWISE(s32, var_a1) & 0x7FFFFF) | 0x800000) << (temp_a2 & 1)) * 2;
    var_a3 = 0;
    var_a0 = 0;
    var_a2_2 = 0x01000000;
    do {
        temp_v1 = var_a3 + var_a2_2;
        if (var_a1_2 >= temp_v1) {
            var_a1_2 -= temp_v1;
            var_a3 = temp_v1 + var_a2_2;
            var_a0 += var_a2_2;
        }
        var_a2_2 = var_a2_2 >> 1;
        var_a1_2 *= 2;
    } while (var_a2_2 != 0);
    if (var_a1_2 != 0) {
        var_a0 += var_a0 & 1;
    }
    return M2C_BITWISE(f32, ((var_a0 >> 1) + 0x3F000000 + ((temp_a2 >> 1) << 0x17)));
}
}
