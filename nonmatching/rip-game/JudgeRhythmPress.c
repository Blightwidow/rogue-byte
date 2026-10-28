#include "m2c_macros.h"

M2C_UNK AddRhythmScore(void *, f32);                /* extern */
s32 FFloatsNear__Ffff(f32, f32, M2C_UNK);           /* extern */
s32 FVjoyButtonPressed(s32, s32);                   /* extern */
f32 GAccuracyRhythmCue(void *, void *);             /* extern */
s32 GrfbtnVjoyPressedWithin(s32, M2C_UNK, M2C_UNK); /* extern */
f32 MarkClockTickRealOnly__FP5CLOCK(M2C_UNK *);     /* extern */
M2C_UNK PlayDancerMove(void *, s32, s32, M2C_UNK);  /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
f32 func_00153638(void *, f32);                     /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD040;

void JudgeRhythmPress(void *arg0, void *arg1) {
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    void *var_s0;
    void *var_s1;

    temp_s3 = M2C_FIELD(arg1, s32 *, 0x150);
    temp_v0 = GrfbtnVjoyPressedWithin(temp_s3, 0xF0, 0);
    M2C_FIELD(arg0, s32 *, 0x230) = temp_v0;
    if ((temp_v0 != 0) && (temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C0), var_v1 = 0, (temp_v0_2 > 0))) {
        var_s1 = arg0 + 0x1C4;
loop_3:
        var_v1 += 1;
        if (M2C_FIELD(var_s1, s32 *, 0) == arg1) {
            var_v0 = var_v1 < temp_v0_2;
            if (M2C_FIELD(var_s1, s32 *, 0x20) == 0) {
                bevy_camera_follow_activity(&B_002DEB30, 0x35, arg0);
                if (MarkClockTickRealOnly__FP5CLOCK(&B_003DD040) < (M2C_FIELD(var_s1, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0x58))) {
                    PlayDancerMove(arg1, -1, -1, 1);
                    AddRhythmScore(arg0, M2C_FIELD(arg0, f32 *, 0x298));
                    return;
                }
                if (M2C_FIELD(var_s1, s32 *, 0x1C) != 0) {
                    PlayDancerMove(arg1, -1, -1, 1);
                    AddRhythmScore(arg0, M2C_FIELD(arg0, f32 *, 0x2A0));
                    return;
                }
                M2C_FIELD(var_s1, s32 *, 0x1C) = 1;
                if (FVjoyButtonPressed(temp_s3, M2C_FIELD(var_s1, s32 *, 4)) != 0) {
                    var_s3 = 0;
                    PlayDancerMove(arg1, M2C_FIELD(var_s1, s32 *, 4), M2C_FIELD(var_s1, s32 *, 8), 0);
                    var_s0 = arg0 + 0x70;
                    AddRhythmScore(arg0, func_00153638(arg0, GAccuracyRhythmCue(arg0, var_s1)));
loop_12:
                    if (var_s3 < M2C_FIELD(arg0, s32 *, 0x60)) {
                        if (FFloatsNear__Ffff(M2C_FIELD(var_s0, f32 *, 0), M2C_FIELD(var_s1, f32 *, 0xC), 0x3DCCCCCD) == 0) {
                            var_s0 += 0x30;
                            var_s3 += 1;
                            goto loop_12;
                        }
                        M2C_FIELD(var_s0, s32 *, 0x20) = 1;
                    }
                } else {
                    PlayDancerMove(arg1, -1, -1, 1);
                    AddRhythmScore(arg0, M2C_FIELD(arg0, f32 *, 0x29C));
                }
            } else {
                goto block_19;
            }
        } else {
            var_v0 = var_v1 < temp_v0_2;
block_19:
            var_s1 += 0x24;
            if (var_v0 == 0) {

            } else {
                goto loop_3;
            }
        }
    }
}
