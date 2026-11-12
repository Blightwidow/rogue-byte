typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___ieee754_atan2f {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
f32 atanf(...);                 /* extern */
f32 fabsf(s32, s32, f32, f32, f32);                 /* extern */
extern f32 RO_FLT_002ABBFC;
f32 __ieee754_atan2f(f32 fparg0, f32 fparg1) {
    f32 temp_a2;
    f32 var_f0;
    f32 var_v1;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0;
    var_f0 = fparg0;
    temp_a1 = M2C_BITWISE(s32, fparg1) & 0x7FFFFFFF;
    temp_a2 = var_f0;
    temp_a0 = M2C_BITWISE(s32, temp_a2) & 0x7FFFFFFF;
    if ((temp_a1 > 0x7F800000) || (temp_a0 > 0x7F800000)) {
        var_f0 += fparg1;
        goto block_56;
    }
    if (M2C_BITWISE(s32, fparg1) == 0x3F800000) {
        var_f0 = atanf(temp_a0, temp_a1, temp_a2, fparg1, var_f0);
        goto block_56;
    }
    temp_s0 = (M2C_BITWISE(u32, temp_a2) >> 0x1F) | ((M2C_BITWISE(s32, fparg1) >> 0x1E) & 2);
    if (temp_a0 == 0) {
        if (temp_s0 != 2) {
            if (temp_s0 >= 3) {
                if (temp_s0 != 3) {
                    goto block_11;
                }
                goto block_37;
            }
            if (temp_s0 < 0) {
                goto block_11;
            }
            /* Duplicate return node #57. Try simplifying control flow for better match */
            return var_f0;
        }
        goto block_36;
    }
block_11:
    if (temp_a1 == 0) {
        goto block_12;
    }
    if (temp_a1 == 0x7F800000) {
        if (temp_a0 == temp_a1) {
            switch (temp_s0) {                      /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                var_f0 = 0.7853982f;
                goto block_56;
            case 1:                                 /* switch 1 */
                var_f0 = -0.7853982f;
                goto block_56;
            case 2:                                 /* switch 1 */
                var_f0 = 2.3561945f;
                goto block_56;
            case 3:                                 /* switch 1 */
                var_f0 = -2.3561945f;
                goto block_56;
            }
        } else {
            switch (temp_s0) {                      /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                var_f0 = 0.0f;
                goto block_56;
            case 1:                                 /* switch 2 */
                var_f0 = RO_FLT_002ABBFC;
                goto block_56;
            case 2:                                 /* switch 2 */
block_36:
                var_f0 = 3.1415925f;
                goto block_56;
            case 3:                                 /* switch 2 */
block_37:
                var_f0 = -3.1415925f;
                goto block_56;
            }
        }
    } else {
        if (temp_a0 != 0x7F800000) {
            temp_v0 = (s32) (temp_a0 - temp_a1) >> 0x17;
            if (temp_v0 >= 0x3D) {
                var_v1 = 1.5707965f;
            } else if ((M2C_BITWISE(s32, fparg1) >= 0) || (var_v1 = 0.0f, ((temp_v0 < -0x3C) == 0))) {
                var_v1 = atanf(M2C_BITWISE(s32, fabsf(temp_a0, temp_a1, temp_a2, fparg1, var_f0 / fparg1)));
            }
            switch (temp_s0) {                      /* switch 3; irregular */
            case 1:                                 /* switch 3 */
                var_v1 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_v1) ^ 0x80000000));
                /* fallthrough */
            case 0:                                 /* switch 3 */
                var_f0 = var_v1;
                break;
            case 2:                                 /* switch 3 */
                var_f0 = 3.1415925f - (var_v1 - 0.00000015099579f);
                break;
            default:                                /* switch 3 */
                var_f0 = (var_v1 - 0.00000015099579f) - 3.1415925f;
                break;
            }
block_56:
            /* Duplicate return node #57. Try simplifying control flow for better match */
            return var_f0;
        }
block_12:
        var_f0 = 1.5707964f;
        if (M2C_BITWISE(s32, temp_a2) < 0) {
            return -1.5707964f;
        }
        return var_f0;
    }
}
}
