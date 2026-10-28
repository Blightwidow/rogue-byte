#include "m2c_macros.h"

s32 FGadgetAcquired(s32);                           /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK SeekBlotLabel(void *, M2C_UNK, f32);        /* extern */
M2C_UNK func_00213928(void *, M2C_UNK);             /* extern */
M2C_UNK func_00213B00(void *, M2C_UNK);             /* extern */
extern s32 D_002C2DE8;
extern s32 D_002C3028;
extern s32 D_002C3148;

void SetMeterState(void *arg0, u32 arg1) {
    M2C_UNK spC;
    s32 *var_s0;
    s32 *var_s2;
    s32 var_a1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0x30);
    if ((temp_v1 != arg1) && (temp_a2 = M2C_FIELD(arg0, void **, 0x38), (temp_a2 != NULL))) {
        if ((temp_v1 == 2) || (var_v0 = arg1 < 8U, (temp_v1 == 6))) {
            temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x3C), temp_a2);
            var_v0 = arg1 < 8U;
        }
        M2C_FIELD(arg0, u32 *, 0x30) = arg1;
        if (var_v0 != 0) {
            switch (arg1) {
            case 0:
            case 5:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x44);
block_26:
                temp_v0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, s32, void *), 0x18C)(M2C_FIELD(arg0, void **, 0x38) + M2C_FIELD(temp_v0_2, s16 *, 0x188), var_a1, M2C_FIELD(arg0, void **, 0x38));
                return;
            case 1:
                temp_a2_2 = M2C_FIELD(arg0, void **, 0x38);
                var_s5 = 0;
                var_s0 = NULL;
                temp_v0_3 = M2C_FIELD(temp_a2_2, void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s32, void *), 0x18C)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x3C), temp_a2_2);
                func_00213B00(M2C_FIELD(arg0, void **, 0x38), 0x34F);
                SeekBlotLabel(M2C_FIELD(arg0, void **, 0x38), 0x34F, 1.0f - M2C_FIELD(arg0, f32 *, 0x20));
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x35) != 0) {
                    var_s5 = 0x12;
                    var_s0 = &D_002C2DE8;
                } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x37) != 0) {
                    var_s5 = 9;
                    var_s0 = &D_002C3028;
                } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x34), 0x36) != 0) {
                    var_s5 = 8;
                    var_s0 = &D_002C3148;
                }
                var_s2 = var_s0;
                var_s4 = 0;
                var_s3 = 0;
loop_17:
                if (var_s3 < var_s5) {
                    if (FGadgetAcquired(*var_s2) != 0) {
                        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($v0) */);
                        M2C_ERROR(/* unknown instruction: ldr $v1, ($v0) */);
                        M2C_ERROR(/* unknown instruction: ldl $a0, 0xf($v0) */);
                        M2C_ERROR(/* unknown instruction: ldr $a0, 0x8($v0) */);
                        M2C_ERROR(/* unknown instruction: ldl $a1, 0x17($v0) */);
                        M2C_ERROR(/* unknown instruction: ldr $a1, 0x10($v0) */);
                        M2C_ERROR(/* unknown instruction: ldl $a2, 0x1f($v0) */);
                        M2C_ERROR(/* unknown instruction: ldr $a2, 0x18($v0) */);
                        M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($sp) */);
                        M2C_ERROR(/* unknown instruction: sdr $v1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: sdl $a0, 0xf($sp) */);
                        M2C_ERROR(/* unknown instruction: sdr $a0, 0x8($sp) */);
                        M2C_ERROR(/* unknown instruction: sdl $a1, 0x17($sp) */);
                        M2C_ERROR(/* unknown instruction: sdr $a1, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: sdl $a2, 0x1f($sp) */);
                        M2C_ERROR(/* unknown instruction: sdr $a2, 0x18($sp) */);
                        var_s2 += 0x20;
                        if (spC > 0) {
                            var_s4 = 1;
                        } else {
                            goto block_16;
                        }
                    } else {
                        var_s2 += 0x20;
block_16:
                        var_s3 += 1;
                        goto loop_17;
                    }
                }
                temp_a0 = M2C_FIELD(arg0, void **, 0x38);
                if (var_s4 != 0) {
                    func_00213B00(temp_a0, 0x350);
                    SeekBlotLabel(M2C_FIELD(arg0, void **, 0x38), 0x350, 1.0f - M2C_FIELD(arg0, f32 *, 0x28));
                    return;
                }
                func_00213928(temp_a0, 0x350);
                return;
            case 2:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x40);
                goto block_26;
            case 6:
                var_a1 = M2C_FIELD(arg0, s32 *, 0x48);
                goto block_26;
            case 7:
                temp_a2_3 = M2C_FIELD(arg0, void **, 0x38);
                temp_v0_4 = M2C_FIELD(temp_a2_3, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s32, void *), 0x18C)(temp_a2_3 + M2C_FIELD(temp_v0_4, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x4C), temp_a2_3);
                break;
            }
        }
    }
}
