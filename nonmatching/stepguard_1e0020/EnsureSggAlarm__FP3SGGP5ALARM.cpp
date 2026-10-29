typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EnsureSggAlarm__FP3SGGP5ALARM {}; /* size 0x0 */

void EnsureSggAlarm__FP3SGGP5ALARM(s8 *arg0, s32 arg1) {
    s32 *var_v1;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;

    temp_a3 = M2C_FIELD(arg0, s32 *, 0x84);
    var_a2 = 0;
    if (temp_a3 > 0) {
        var_v1 = (s32 *)(arg0 + 0x88);
loop_2:
        var_a2 += 1;
        if (*var_v1 != arg1) {
            var_v1 += 4;
            if (var_a2 >= temp_a3) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x84);
        if ((u32) temp_v1 < 8U) {
            M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x88) = arg1;
            M2C_FIELD(arg0, s32 *, 0x84) = (s32) (temp_v1 + 1);
        }
    }
}

}
