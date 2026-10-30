typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InsertPathzoneEndpoints {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
M2C_UNK memmove(...);          /* extern */
void InsertPathzoneEndpoints(s32 arg0, f32 *arg1, s16 arg2, f32 fparg0, f32 fparg1) {
    f32 *temp_v0;
    f32 *var_v1;
    f32 *var_v1_2;
    s32 temp_s5;
    s32 var_a0;
    s32 var_s2;
    s32 var_s3;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s1;
    var_s3 = 0;
    if (arg0 > 0) {
        var_s2 = 0;
        if (!(fparg0 <= *arg1)) {
            var_v1 = arg1;
            var_s3 = 1;
loop_3:
            var_v1 += 8;
            if (var_s3 < arg0) {
                if (!(fparg0 <= *var_v1)) {
                    var_s3 += 1;
                    goto loop_3;
                }
            }
            goto block_7;
        }
    } else {
block_7:
        var_s2 = var_s3;
    }
    temp_s5 = var_s3 * 8;
    if (var_s3 < arg0) {
        temp_v0 = temp_s5 + arg1;
        var_a0 = var_s2 * 8;
        if (!(fparg1 < *temp_v0)) {
            var_v1_2 = temp_v0;
loop_11:
            var_s2 += 1;
            var_v1_2 += 8;
            if (var_s2 < arg0) {
                if (!(fparg1 < *var_v1_2)) {
                    goto loop_11;
                }
            }
            goto block_13;
        }
    } else {
block_13:
        var_a0 = var_s2 * 8;
    }
    temp_s0 = (s8 *)(var_a0 + arg1);
    temp_s1 = (s8 *)(temp_s5 + arg1);
    memmove(temp_s0 + 0x10, temp_s0, (arg0 - var_s2) * 8, arg0);
    M2C_FIELD(temp_s0, f32 *, 8) = fparg1;
    temp_s0_2 = temp_s0 + 8;
    M2C_FIELD(temp_s0_2, s16 *, 6) = arg2;
    M2C_FIELD(temp_s0_2, s16 *, 4) = 0;
    memmove(temp_s1 + 8, temp_s1, (var_s2 - var_s3) * 8);
    M2C_FIELD(temp_s1, s16 *, 6) = arg2;
    M2C_FIELD(temp_s1, f32 *, 0) = fparg0;
    M2C_FIELD(temp_s1, s16 *, 4) = 1;
}
}
