typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___ieee754_sqrt {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
s64 __adddf3(s32, s64);                             /* extern */
s32 __muldf3(s64, s64, s64);                        /* extern */
s32 __subdf3(s64, s64, s64, s64);                   /* extern */
s32 dpcmp(...);  /* extern */
s64 func_0023DAB0(s32, s32);                        /* extern */
s64 __ieee754_sqrt(s64 arg0, s32 arg4) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a4;
    s32 var_a6;
    s32 var_a7;
    s32 var_s2;
    s32 var_v1;
    s64 temp_s0;
    s64 var_a2;
    s64 var_a3;
    s64 var_v0;
    u32 temp_a1_2;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 var_a3_2;
    u32 var_a3_3;
    u32 var_a5;
    u32 var_a5_2;
    u32 var_s1;
    u32 var_s1_2;
    u32 var_v0_2;
    var_a4 = arg4;
    var_a2 = arg0 >> 0x20;
    var_a3 = (s64) (arg0 << 0x20) >> 0x20;
    if ((var_a2 & 0x7FF00000) == 0x7FF00000) {
        return __adddf3(__muldf3(arg0, var_a2, var_a3), arg0);
    }
    var_a1 = var_a2 >> 0x14;
    if (var_a2 <= 0) {
        var_v0 = arg0;
        if (((var_a2 & 0x7FFFFFFF) | var_a3) != 0) {
            if (var_a2 < 0) {
                temp_v0 = __subdf3(arg0, arg0, var_a2, var_a3);
                return func_0023DAB0(temp_v0, temp_v0);
            }
            goto block_6;
        }
        /* Duplicate return node #42. Try simplifying control flow for better match */
        return var_v0;
    }
block_6:
    if (var_a1 == 0) {
        if (var_a2 == 0) {
            do {
                var_a1 -= 0x15;
                var_a2 |= (u32) var_a3 >> 0xB;
                var_a3 <<= 0x15;
            } while (var_a2 == 0);
        }
        var_a0 = 0;
        if (!(var_a2 & 0x100000)) {
            var_v1 = var_a1 + 1;
            do {
                var_a2 *= 2;
                var_a0 += 1;
            } while (!(var_a2 & 0x100000));
        } else {
            var_v1 = var_a1 + 1;
        }
        var_a1 = var_v1 - var_a0;
        var_a2 |= (u32) var_a3 >> -var_a0;
        var_a3 <<= var_a0;
    }
    temp_a1 = var_a1 - 0x3FF;
    var_a2_2 = (var_a2 & 0xFFFFF) | 0x100000;
    if (temp_a1 & 1) {
        temp_v0_2 = (u32) (var_a3 & 0x80000000) >> 0x1F;
        var_a3 *= 2;
        var_a2_2 += var_a2_2 + temp_v0_2;
    }
    var_a3_2 = var_a3 * 2;
    var_a2_3 = var_a2_2 + (var_a2_2 + ((u32) (var_a3 & 0x80000000) >> 0x1F));
    var_a7 = 0;
    var_a6 = 0;
    var_s1 = 0;
    var_s2 = 0;
    var_a5 = 0x200000;
    do {
        temp_a0 = var_a6 + var_a5;
        if (var_a2_3 >= temp_a0) {
            var_a2_3 -= temp_a0;
            var_a6 = temp_a0 + var_a5;
            var_s2 += var_a5;
        }
        var_a5 = var_a5 >> 1;
        temp_v0_3 = (u32) (var_a3_2 & 0x80000000) >> 0x1F;
        var_a3_2 *= 2;
        var_a2_3 += var_a2_3 + temp_v0_3;
    } while (var_a5 != 0);
    var_a5_2 = 0x80000000;
    do {
        temp_a1_2 = var_a7 + var_a5_2;
        if (var_a6 >= var_a2_3) {
            var_v0_2 = var_a3_2 & 0x80000000;
            if (var_a6 == var_a2_3) {
                var_a4 = var_a3_2 < temp_a1_2;
                if (var_a4 == 0) {
                    goto block_29;
                }
            }
        } else {
            var_a4 = var_a3_2 < temp_a1_2;
block_29:
            var_a7 = temp_a1_2 + var_a5_2;
            temp_a2 = var_a2_3 - var_a6;
            if ((temp_a1_2 & 0x80000000) == 0x80000000) {
                var_a6 = !(var_a7 & 0x80000000) ? (var_a6 + 1) : var_a6;
            }
            var_a3_2 -= temp_a1_2;
            var_a2_3 = temp_a2 - var_a4;
            var_s1 += var_a5_2;
            var_v0_2 = var_a3_2 & 0x80000000;
        }
        var_a5_2 = var_a5_2 >> 1;
        var_a3_2 *= 2;
        var_a2_3 += var_a2_3 + (var_v0_2 >> 0x1F);
    } while (var_a5_2 != 0);
    var_a3_3 = var_s1 >> 1;
    if ((var_a2_3 | var_a3_2) != 0) {
        temp_s0 = 0xFFC0 << 0x2E;
        var_a3_3 = var_s1 >> 1;
        if (dpcmp(temp_s0, temp_s0, var_a2_3, var_a3_3, var_a4, var_a5_2, var_a6, var_a7) >= 0) {
            if (var_s1 == 0xFFFFFFFF) {
                var_s1_2 = 0;
                var_s2 += 1;
            } else if (dpcmp(temp_s0, temp_s0) > 0) {
                var_s2 = ((var_s1 ^ 0xFFFFFFFE) == 0) ? (var_s2 + 1) : var_s2;
                var_s1_2 = var_s1 + 2;
            } else {
                var_s1_2 = var_s1 + (var_s1 & 1);
            }
            var_a3_3 = var_s1_2 >> 1;
        }
    }
    var_v0 = (((var_s2 >> 1) + 0x3FE00000 + ((temp_a1 >> 1) << 0x14)) << 0x20) | ((u64) ((s64) ((var_s2 & 1) ? (var_a3_3 | 0x80000000) : var_a3_3) << 0x20) >> 0x20);
    return var_v0;
}
}
