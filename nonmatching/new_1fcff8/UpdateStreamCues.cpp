typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateStreamCues {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK RunStreamCue(s8 *, s16 *);                /* extern */
M2C_UNK StopStream(s8 *);                         /* extern */
f32 __floatdisf(...);                       /* extern */
extern f32 g_2ddf10;
void UpdateStreamCues(s8 *arg0) {
    f32 temp_f20;
    f32 var_f1;
    f32 var_f2;
    s16 *temp_s1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v1;
    s64 temp_a0;
    s64 temp_a0_2;
    s8 *temp_a1;
    s8 *temp_s2;
    s8 *temp_v1;
    s8 *temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x200);
    if (temp_v1 != NULL) {
        var_a0 = 0;
        if ((M2C_FIELD(temp_v1, u16 *, 0x52) != 0) || (M2C_FIELD(temp_v1, u16 *, 0x50) & 1)) {
            var_a0 = 1;
        }
        if ((var_a0 == 0) && (temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x200), (M2C_FIELD(temp_v1_2, s16 *, 0x4E) <= 0))) {
            temp_s2 = M2C_FIELD(temp_v1_2, s8 **, 0x60);
            M2C_FIELD(arg0, f32 *, 0x24C) = (f32) (M2C_FIELD(arg0, f32 *, 0x24C) + g_2ddf10);
            var_a0_2 = 0;
            if ((M2C_FIELD(temp_v1_2, s32 *, 0x40) == 0) && ((M2C_FIELD(temp_v1_2, u16 *, 0x52) != 0) || (var_a0_2 = 0 ^ 1, ((M2C_FIELD(temp_v1_2, u16 *, 0x50) & 1) != 0)))) {
                var_a0_2 = 1 ^ 1;
            }
            if (var_a0_2 == 0) {
                var_v1 = M2C_FIELD(arg0, s32 *, 0x244);
                if (var_v1 < M2C_FIELD(temp_s2, s32 *, 0x54)) {
loop_21:
                    temp_a1 = M2C_FIELD(arg0, s8 **, 0x200);
                    temp_s1 = (s16 *)(M2C_FIELD(temp_s2, s32 *, 0x58) + (var_v1 * 8));
                    temp_a0 = M2C_FIELD(temp_a1, s64 *, 0x68);
                    temp_f20 = (f32) *temp_s1 * 0.016666668f;
                    if (temp_a0 >= 0) {
                        var_f1 = __floatdisf(temp_a0, temp_a1);
                    } else {
                        var_f1 = 2.0f * __floatdisf((temp_a0 & 1) | ((u64) temp_a0 >> 1), temp_a1);
                    }
                    if (!((var_f1 * 3.390842e-9f) < (M2C_FIELD(arg0, f32 *, 0x248) + temp_f20))) {
                        RunStreamCue(arg0, temp_s1);
                        temp_v0 = M2C_FIELD(arg0, s32 *, 0x244) + 1;
                        M2C_FIELD(arg0, s32 *, 0x244) = temp_v0;
                        var_v1 = temp_v0;
                        M2C_FIELD(arg0, f32 *, 0x248) = (f32) (M2C_FIELD(arg0, f32 *, 0x248) + temp_f20);
                        if (var_v1 < M2C_FIELD(temp_s2, s32 *, 0x54)) {
                            goto loop_21;
                        }
                    }
                }
            } else {
                temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x200), s64 *, 0x68);
                if (temp_a0_2 >= 0) {
                    var_f2 = __floatdisf(temp_a0_2);
                } else {
                    var_f2 = 2.0f * __floatdisf((temp_a0_2 & 1) | ((u64) temp_a0_2 >> 1));
                }
                if (((var_f2 * 3.390842e-9f) > 0.0f) || (M2C_FIELD(temp_s2, f32 *, 0x50) <= M2C_FIELD(arg0, f32 *, 0x24C))) {
                    StopStream(arg0);
                }
            }
        }
    }
}
}
