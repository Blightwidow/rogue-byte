typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_memmove {};                       /* size 0x0 */
u32 memmove(u32 arg0, u32 arg1, u32 arg2) {
    s128 temp_v0;
    s32 var_a2_2;
    s32 var_a2_3;
    s64 temp_v1;
    u32 temp_a3;
    u32 var_a1;
    u32 var_a1_2;
    u32 var_a2;
    u32 var_a3;
    u32 var_v1;
    u8 *var_v1_2;
    u8 temp_v0_2;
    var_a1 = arg1;
    var_a2 = arg2;
    var_v1 = arg0;
    if (var_a1 < arg0) {
        temp_a3 = var_a1 + var_a2;
        if (arg0 < temp_a3) {
            var_v1_2 = (u8 *)(arg0 + var_a2);
            var_a2_2 = var_a2 - 1;
            var_a1_2 = temp_a3;
            if (var_a2_2 != -1) {
                do {
                    var_a1_2 -= 1;
                    var_v1_2 -= 1;
                    var_a2_2 -= 1;
                    *var_v1_2 = *(s32 *)var_a1_2;
                } while (var_a2_2 != -1);
                return arg0;
            }
            /* Duplicate return node #15. Try simplifying control flow for better match */
            return arg0;
        }
    }
    if ((var_a2 >= 0x20U) && !((var_a1 | var_v1) & 0xF)) {
        var_a3 = var_v1;
        do {
            var_a2 -= 0x20;
            M2C_FIELD(var_a3, s128 *, 0) = (s128) M2C_FIELD(var_a1, s128 *, 0);
            temp_v0 = M2C_FIELD(var_a1, s128 *, 0x10);
            var_a1 = var_a1 + 0x10 + 0x10;
            M2C_FIELD(var_a3, s128 *, 0x10) = temp_v0;
            var_a3 = var_a3 + 0x10 + 0x10;
        } while (var_a2 >= 0x20U);
        var_v1 = var_a3;
        if (var_a2 >= 8U) {
            do {
                temp_v1 = *(s32 *)var_a1;
                var_a2 -= 8;
                var_a1 += 8;
                *(s32 *)var_a3 = temp_v1;
                var_a3 += 8;
            } while (var_a2 >= 8U);
            var_v1 = var_a3;
        }
    }
    var_a2_3 = var_a2 - 1;
    if (var_a2_3 != -1) {
        do {
            temp_v0_2 = *(s32 *)var_a1;
            var_a2_3 -= 1;
            var_a1 += 1;
            *(s32 *)var_v1 = temp_v0_2;
            var_v1 += 1;
        } while (var_a2_3 != -1);
    }
    return arg0;
}
}
