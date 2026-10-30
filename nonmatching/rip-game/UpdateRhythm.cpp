typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateRhythm {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
void AddRhythmScore(s8 *, f32);
f32 GSmooth__FfffP3SMPPf(s8 *, M2C_UNK, f32, f32, f32);
f32 MarkClockTickRealOnly__FP5CLOCK(M2C_UNK *);
void PlayDancerMove(s32, s32, s32, M2C_UNK);
void UpdateLo();
void UpdateRhythmCrowd(s8 *);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *);
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD040;
extern M2C_UNK g_2dded0;
void UpdateRhythm(s8 *arg0) {
    f32 temp_f20;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s2;
    s8 *temp_s0;
    s8 *var_s0;
    s8 *var_s4;
    UpdateLo();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x50);
    temp_f20 = MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
    if (temp_v1 != 1) {
        if (temp_v1 != 2) {
            var_s4 = arg0 + 0x28C;
        } else {
            var_s2 = 0;
            var_s4 = arg0 + 0x28C;
            if (M2C_FIELD(arg0, s32 *, 0x1C0) > 0) {
                var_s0 = arg0 + 0x1C4;
loop_12:
                if (M2C_FIELD(var_s0, s32 *, 0x20) != 0) {
                    goto block_23;
                }
                if ((M2C_FIELD(var_s0, s32 *, 0x18) == 0) && (M2C_FIELD(var_s0, f32 *, 0xC) < temp_f20)) {
                    M2C_FIELD(arg0, s32 *, 0x230) = (s32) M2C_FIELD(var_s0, s32 *, 4);
                    bevy_camera_follow_activity(&B_002DEB30, 0x34, arg0);
                    M2C_FIELD(var_s0, s32 *, 0x18) = 1;
                }
                if (!((M2C_FIELD(var_s0, f32 *, 0xC) + M2C_FIELD(arg0, f32 *, 0x5C)) < temp_f20)) {
block_23:
                    var_s2 += 1;
                    var_s0 += 0x24;
                    if (var_s2 < M2C_FIELD(arg0, s32 *, 0x1C0)) {
                        goto loop_12;
                    }
                } else {
                    M2C_FIELD(var_s0, s32 *, 0x20) = 1;
                    if (M2C_FIELD(var_s0, s32 *, 0x1C) == 0) {
                        PlayDancerMove(M2C_FIELD(var_s0, s32 *, 0), M2C_FIELD(var_s0, s32 *, 4), M2C_FIELD(var_s0, s32 *, 8), 2);
                        AddRhythmScore(arg0, M2C_FIELD(arg0, f32 *, 0x2A4));
                    }
                }
            }
        }
    } else {
        var_a0 = 0;
        var_s4 = arg0 + 0x28C;
loop_6:
        if (var_a0 < M2C_FIELD(arg0, s32 *, 0x1C0)) {
            temp_s0 = arg0 + ((var_a0 * 0x24) + 0x1C4);
            if ((M2C_FIELD(temp_s0, s32 *, 0x14) == 0) && (M2C_FIELD(temp_s0, f32 *, 0xC) < temp_f20)) {
                PlayDancerMove(M2C_FIELD(temp_s0, s32 *, 0), M2C_FIELD(temp_s0, s32 *, 4), M2C_FIELD(temp_s0, s32 *, 8), 0);
                M2C_FIELD(temp_s0, s32 *, 0x14) = 1;
            } else {
                var_a0 += 1;
                goto loop_6;
            }
        }
    }
    M2C_FIELD(arg0, f32 *, 0x288) = GSmooth__FfffP3SMPPf(var_s4, 0, M2C_FIELD(arg0, f32 *, 0x288), M2C_FIELD(arg0, f32 *, 0x284), M2C_FIELD(&g_2dded0, f32 *, 4));
    UpdateRhythmCrowd(arg0);
}
}
