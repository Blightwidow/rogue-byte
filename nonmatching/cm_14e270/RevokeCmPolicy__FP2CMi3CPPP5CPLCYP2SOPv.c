#include "m2c_macros.h"

extern f32 g_2dded0;

void RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 var_s3;
    s32 var_s5;
    void *temp_a2;
    void *temp_a3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_s0;
    void *var_s1;
    void *var_s4;

    var_s1 = arg0 + 0x310;
    var_s4 = NULL;
    var_s3 = 0;
    var_s0 = var_s1;
    var_s5 = 0;
    sp0 = arg2;
    sp4 = arg3;
    sp8 = M2C_ERROR(/* Read from unset register $t0 */);
    spC = M2C_ERROR(/* Read from unset register $t1 */);
    sp10 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30C) > 0) {
        sp14 = arg1 & 8;
        do {
            if ((((arg1 ^ 1) & 1) || (sp0 == M2C_FIELD(var_s0, s32 *, 0))) && (!(arg1 & 2) || (sp4 == M2C_FIELD(var_s0, void **, 4))) && (!(arg1 & 4) || (sp8 == M2C_FIELD(var_s0, s32 *, 8))) && ((sp14 == 0) || (spC == M2C_FIELD(var_s0, s32 *, 0xC)))) {
                temp_a2 = M2C_FIELD(var_s0, void **, 4);
                if (var_s3 == 0) {
                    var_s4 = temp_a2;
                    sp10 = M2C_FIELD(var_s0, s32 *, 8);
                    var_s5 = M2C_FIELD(var_s0, s32 *, 0xC);
                }
                temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32, void *), 0x2C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x28), M2C_FIELD(var_s0, s32 *, 0xC), temp_a2);
            } else {
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($s0) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, ($s0) */);
                M2C_ERROR(/* unknown instruction: ldl $a0, 0xf($s0) */);
                M2C_ERROR(/* unknown instruction: ldr $a0, 0x8($s0) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s1) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, ($s1) */);
                M2C_ERROR(/* unknown instruction: sdl $a0, 0xf($s1) */);
                M2C_ERROR(/* unknown instruction: sdr $a0, 0x8($s1) */);
                var_s1 += 0x10;
            }
            var_s3 += 1;
            var_s0 += 0x10;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x30C));
    }
    M2C_FIELD(arg0, s32 *, 0x30C) = (s32) ((s32) ((var_s1 - 0x310) - arg0) >> 4);
    if (var_s4 != NULL) {
        temp_v0_2 = M2C_FIELD(var_s4, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, s32, s32), 0x1C)(var_s4 + M2C_FIELD(temp_v0_2, s16 *, 0x18), sp10, var_s5);
        if (M2C_FIELD(arg0, s32 *, 0x30C) > 0) {
            temp_a3 = M2C_FIELD(arg0, void **, 0x314);
            M2C_FIELD(arg0, f32 *, 0x390) = (f32) g_2dded0;
            temp_v0_3 = M2C_FIELD(temp_a3, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s32, s32, void *), 0x14)(temp_a3 + M2C_FIELD(temp_v0_3, s16 *, 0x10), M2C_FIELD(arg0, s32 *, 0x318), M2C_FIELD(arg0, s32 *, 0x31C), temp_a3);
        }
    }
}
