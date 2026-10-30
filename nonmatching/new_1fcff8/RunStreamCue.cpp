typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK SetAloEyesClosed(s8 *, s32, s8 *, M2C_UNK, s32); /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID(s32, s32, s8 *, f32); /* extern */

void RunStreamCue(s8 *arg0, s8 *arg1) {
    s16 temp_v1;
    s32 temp_a0;
    s32 temp_a1;

    temp_v1 = M2C_FIELD(arg1, s16 *, 2);
    if ((temp_v1 != -1) && (temp_a0 = M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x22C), (temp_a0 != 0))) {
        if (temp_v1 != 3) {
            temp_a1 = M2C_FIELD(arg1, s32 *, 4);
            if (temp_a1 != -1) {
                SetSmaGoal__FP3SMA3OID(temp_a0, temp_a1, arg0, -1);
            }
        } else {
            SetAloEyesClosed(arg0, M2C_FIELD(arg0, s32 *, 0x238), arg0, -1, M2C_FIELD(arg1, s32 *, 4));
        }
    }
}

}
