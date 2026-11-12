typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023DC18 {};                 /* size 0x0 */
s32 func_0023DC18(s8 *arg0, s8 *arg1) {
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    u32 temp_a2;
    u32 temp_v1;
    u64 temp_a0;
    u64 temp_v1_3;
    temp_a2 = M2C_FIELD(arg0, u32 *, 0);
    if ((temp_a2 < 2U) || (temp_v1 = M2C_FIELD(arg1, u32 *, 0), ((temp_v1 < 2U) != 0))) {
        return 1;
    }
    temp_v0 = temp_v1 ^ 4;
    if ((temp_a2 ^ 4) == 0) {
        if (temp_v0 != 0) {
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return (M2C_FIELD(arg0, s32 *, 4) == 0) ? 1 : -1;
        }
        return M2C_FIELD(arg1, s32 *, 4) - M2C_FIELD(arg0, s32 *, 4);
    }
    if (temp_v0 != 0) {
        temp_v0_2 = temp_v1 ^ 2;
        if ((temp_a2 ^ 2) == 0) {
            if (temp_v0_2 != 0) {
                return (M2C_FIELD(arg1, s32 *, 4) != 0) ? 1 : -1;
            }
            return 0;
        }
        if (temp_v0_2 == 0) {
            return (M2C_FIELD(arg0, s32 *, 4) == 0) ? 1 : -1;
        }
        temp_a3 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_a3 == M2C_FIELD(arg1, s32 *, 4)) {
            temp_a2_2 = M2C_FIELD(arg0, s32 *, 8);
            temp_v1_2 = M2C_FIELD(arg1, s32 *, 8);
            if (temp_v1_2 >= temp_a2_2) {
                if (temp_a2_2 >= temp_v1_2) {
                    temp_v1_3 = M2C_FIELD(arg0, u64 *, 0x10);
                    temp_a0 = M2C_FIELD(arg1, u64 *, 0x10);
                    if (temp_a0 >= temp_v1_3) {
                        if (temp_v1_3 >= temp_a0) {
                            return 0;
                        }
                        /* Duplicate return node #31. Try simplifying control flow for better match */
                        return (temp_a3 == 0) ? -1 : 1;
                    }
                    /* Duplicate return node #25. Try simplifying control flow for better match */
                    return (temp_a3 == 0) ? 1 : -1;
                }
                return (temp_a3 == 0) ? -1 : 1;
            }
            /* Duplicate return node #25. Try simplifying control flow for better match */
            return (temp_a3 == 0) ? 1 : -1;
        }
        return (temp_a3 == 0) ? 1 : -1;
    }
    return (M2C_FIELD(arg1, s32 *, 4) == 0) ? -1 : 1;
}
}
