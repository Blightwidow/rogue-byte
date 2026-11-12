typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024FAD0 {};                 /* size 0x0 */
s32 func_0024FAD0(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg3, s32 arg4) {
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v0;
    s32 var_v0_10;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    if (M2C_FIELD(arg0, s32 *, 0x184) == 3) {
        if (M2C_FIELD(arg0, s32 *, 0x188) == 0) {
            var_v0 = arg3 * 3;
            if (arg3 > 0) {
                var_v0 += 1;
            }
            M2C_FIELD(arg1, s32 *, 0) = (s32) ((var_v0 >> 1) + M2C_FIELD(arg2, s32 *, 0));
            var_v0_2 = arg4 * 3;
            if (arg4 > 0) {
                var_v0_2 += 1;
            }
            M2C_FIELD(arg1, s32 *, 4) = (s32) (((var_v0_2 >> 1) + M2C_FIELD(arg2, s32 *, 4)) - 1);
            if (arg3 > 0) {
                var_v0_3 = (s32) (arg3 + 1) >> 1;
            } else {
                var_v0_3 = arg3 >> 1;
            }
            M2C_FIELD(arg1, s32 *, 8) = (s32) (var_v0_3 + M2C_FIELD(arg2, s32 *, 0));
            if (arg4 > 0) {
                var_v0_4 = arg4 + 1;
                goto block_14;
            }
            var_v0_5 = arg4 >> 1;
        } else {
            if (arg3 > 0) {
                var_v0_6 = (s32) (arg3 + 1) >> 1;
            } else {
                var_v0_6 = arg3 >> 1;
            }
            M2C_FIELD(arg1, s32 *, 0) = (s32) (var_v0_6 + M2C_FIELD(arg2, s32 *, 0));
            if (arg4 > 0) {
                var_v0_7 = (s32) (arg4 + 1) >> 1;
            } else {
                var_v0_7 = arg4 >> 1;
            }
            M2C_FIELD(arg1, s32 *, 4) = (s32) ((var_v0_7 + M2C_FIELD(arg2, s32 *, 4)) - 1);
            var_v0_8 = arg3 * 3;
            if (arg3 > 0) {
                var_v0_8 += 1;
            }
            M2C_FIELD(arg1, s32 *, 8) = (s32) ((var_v0_8 >> 1) + M2C_FIELD(arg2, s32 *, 0));
            var_v0_4 = arg4 * 3;
            if (arg4 > 0) {
                var_v0_4 += 1;
            }
block_14:
            var_v0_5 = var_v0_4 >> 1;
        }
        temp_v0_3 = var_v0_5 + M2C_FIELD(arg2, s32 *, 4) + 1;
        M2C_FIELD(arg1, s32 *, 0xC) = temp_v0_3;
        return temp_v0_3;
    }
    if (arg3 > 0) {
        var_v0_9 = (s32) (arg3 + 1) >> 1;
    } else {
        var_v0_9 = arg3 >> 1;
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) (var_v0_9 + M2C_FIELD(arg2, s32 *, 0));
    if (arg4 > 0) {
        var_v0_10 = (s32) (arg4 + 1) >> 1;
    } else {
        var_v0_10 = arg4 >> 1;
    }
    temp_a2 = var_v0_10 + M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(arg1, s32 *, 4) = temp_a2;
    temp_v0 = temp_a2 + 1;
    if (M2C_FIELD(arg0, s32 *, 0x184) == 1) {
        temp_v0_2 = temp_a2 - 1;
        M2C_FIELD(arg1, s32 *, 4) = temp_v0_2;
        return temp_v0_2;
    }
    M2C_FIELD(arg1, s32 *, 4) = temp_v0;
    return temp_v0;
}
}
