#include "m2c_macros.h"

M2C_UNK CpdprizeAttractSwDprizes(); /* extern */
s32 FIsBasicDerivedFrom();          /* extern */
f32 GetSuck();                  /* extern */
s32 NRandInRange();                    /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;

void OnDifficultyBreak(void *arg0, s32 arg2, s32 arg3) {
    M2C_UNK temp_s3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;

    var_s2 = arg2;
    temp_s3 = M2C_ERROR(/* Read from unset register $t0 */);
    M2C_ERROR(/* unknown instruction: por $s4, $zero, $a1 */);
    if (M2C_FIELD(arg0, s32 *, 0) <= 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x14);
        temp_f4 = GetSuck(&B_002DE578);
        temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x30);
        temp_a0 = M2C_FIELD(temp_v0, s32 *, 0x28);
        if (temp_a0 == temp_v1) {
            var_s0 = temp_v1;
        } else if (temp_a0 < temp_v1) {
            var_s0 = temp_a0 + 0x3F7FBE77;
        } else {
            var_s0 = temp_v1 + M2C_BITWISE(s32, (((f32) temp_a0 + 0.999f) - (f32) temp_v1));
        }
        temp_v0_2 = M2C_FIELD(arg0, void **, 0x14);
        temp_v1_2 = M2C_FIELD(temp_v0_2, s32 *, 0x34);
        temp_a1 = M2C_FIELD(temp_v0_2, s32 *, 0x2C);
        temp_f4_2 = GetSuck(&B_002DE578, &B_002DE578);
        if (temp_a1 == temp_v1_2) {
            var_a1 = temp_v1_2;
        } else if (temp_a1 < temp_v1_2) {
            var_a1 = temp_a1 + 0x3F7FBE77;
        } else {
            var_a1 = temp_v1_2 + M2C_BITWISE(s32, (((f32) temp_a1 + 0.999f) - (f32) temp_v1_2));
        }
        M2C_FIELD(arg0, s32 *, 0) = NRandInRange(var_s0, var_a1);
    }
    if (M2C_FIELD(arg0, s32 *, 4) <= 0) {
        temp_v0_3 = M2C_FIELD(arg0, void **, 0x14);
        temp_f4_3 = GetSuck(&B_002DE578);
        temp_v1_3 = M2C_FIELD(temp_v0_3, s32 *, 0x40);
        temp_a0_2 = M2C_FIELD(temp_v0_3, s32 *, 0x38);
        if (temp_a0_2 == temp_v1_3) {
            var_s0_2 = temp_v1_3;
        } else if (temp_a0_2 < temp_v1_3) {
            var_s0_2 = temp_a0_2 + 0x3F7FBE77;
        } else {
            var_s0_2 = temp_v1_3 + M2C_BITWISE(s32, (((f32) temp_a0_2 + 0.999f) - (f32) temp_v1_3));
        }
        temp_v0_4 = M2C_FIELD(arg0, void **, 0x14);
        temp_v1_4 = M2C_FIELD(temp_v0_4, s32 *, 0x44);
        temp_a1_2 = M2C_FIELD(temp_v0_4, s32 *, 0x3C);
        temp_f4_4 = GetSuck(&B_002DE578, &B_002DE578);
        if (temp_a1_2 == temp_v1_4) {
            var_a1_2 = temp_v1_4;
        } else if (temp_a1_2 < temp_v1_4) {
            var_a1_2 = temp_a1_2 + 0x3F7FBE77;
        } else {
            var_a1_2 = temp_v1_4 + M2C_BITWISE(s32, (((f32) temp_a1_2 + 0.999f) - (f32) temp_v1_4));
        }
        M2C_FIELD(arg0, s32 *, 4) = NRandInRange(var_s0_2, var_a1_2);
    }
    temp_a2 = M2C_FIELD(arg0, s32 *, 0) + ((FIsBasicDerivedFrom(temp_s3, 0x38) != 0) ? -2 : -1);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + arg3);
    M2C_FIELD(arg0, s32 *, 0) = temp_a2;
    if (var_s2 < 0) {
        temp_v0_5 = M2C_FIELD(arg0, void **, 0x14);
        if (temp_a2 <= 0) {
            var_a1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x14);
            var_a0 = M2C_FIELD(temp_v0_5, s32 *, 0x10);
        } else {
            var_a1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x1C);
            var_a0 = M2C_FIELD(temp_v0_5, s32 *, 0x18);
        }
        var_s2 = NRandInRange(var_a0, var_a1_3, temp_a2);
    }
    if (var_s2 > 0) {
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5B, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s4 */), temp_s3);
    }
    if (M2C_FIELD(arg0, s32 *, 4) <= 0) {
        CpdprizeAttractSwDprizes(&B_003DD490, 0x5D, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s4 */), temp_s3);
    }
}
