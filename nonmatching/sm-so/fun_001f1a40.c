#include "m2c_macros.h"

M2C_UNK ClearPrizeSpewer();                      /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
s32 FTaskComplete();                             /* extern */
f32 GRandInRange();                 /* extern */
s32 IEpisodeCurrent();                              /* extern */
s32 NRandInRange();                    /* extern */
void *PloFindSwObject_thunk(); /* extern */
M2C_UNK memset();           /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C3748;
extern M2C_UNK D_002C3968;

void *func_001F1A40(void *arg0) {
    char sp[0x400];
    s32 spC;
    M2C_UNK *var_v0_2;
    s32 *temp_s0_2;
    s32 *var_a0;
    s32 *var_v0_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a3;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    u32 var_a2;
    u32 var_a2_2;
    void *temp_s2;
    void *temp_v0_2;
    void *temp_v1_2;

    ClearPrizeSpewer(M2C_FIELD(arg0, s32 *, 0x494));
    var_v0 = M2C_FIELD(arg0, s32 *, 0x490);
    if (var_v0 == 0) {
        temp_v0 = IEpisodeCurrent();
        temp_s0 = (~temp_v0 != 0) ? temp_v0 : 1;
        if (FIsBasicDerivedFrom(arg0, 0x3A) != 0) {
            var_v1 = temp_s0 * 0x3C;
            var_v0_2 = &D_002C3968;
        } else {
            var_v1 = temp_s0 * 0x3C;
            var_v0_2 = &D_002C3748;
        }
        temp_s2 = var_v1 + var_v0_2;
        memset(sp, 0, 0x10);
        if (M2C_FIELD(arg0, s32 *, 0x484) > 0) {
            temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(arg0, s32 *, 0x404), M2C_FIELD(arg0, s32 *, 0x494));
            if ((temp_v0_2 != NULL) && (FIsBasicDerivedFrom(temp_v0_2, 0x5C) != 0)) {
                temp_a0 = M2C_FIELD(temp_v0_2, s32 *, 0x230);
                if ((temp_a0 != 0) && (FTaskComplete(temp_a0) != 0)) {
                    M2C_FIELD(arg0, s32 *, 0x484) = 0;
                }
            }
            if (M2C_FIELD(arg0, s32 *, 0x484) > 0) {
                M2C_ERROR(/* unknown instruction: ldl $v0, 0x40b($s1) */);
                M2C_ERROR(/* unknown instruction: ldr $v0, 0x404($s1) */);
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x413($s1) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x40c($s1) */);
                M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0xf($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x8($sp) */);
            } else {
                goto block_12;
            }
        } else {
block_12:
            if (M2C_FIELD(temp_s2, f32 *, 8) < GRandInRange(0, 0x3F800000)) {

            } else {
                temp_s0_2 = temp_s2 + 0xC;
                var_a1 = 0;
                var_a2 = 0;
                var_a0 = temp_s0_2;
                do {
                    temp_v1 = *var_a0;
                    var_a2 += 1;
                    var_a0 += 8;
                    var_a1 += temp_v1;
                } while (var_a2 < 6U);
                var_v1_2 = M2C_FIELD(temp_s2, s32 *, 0xC);
                var_a0_2 = NRandInRange(0, var_a1 - 1, var_a2);
                var_v0_3 = temp_s0_2;
                var_a2_2 = 0;
loop_19:
                if (var_a0_2 >= var_v1_2) {
                    var_a2_2 += 1;
                    var_a0_2 -= M2C_FIELD(var_v0_3, s32 *, 0);
                    if (var_a2_2 < 6U) {
                        var_v0_3 = temp_s2 + ((var_a2_2 * 8) + 0xC);
                        var_v1_2 = *var_v0_3;
                        goto loop_19;
                    }
                }
                spC = 1;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x484) = 0;
        var_s0 = NRandInRange(M2C_FIELD(temp_s2, s32 *, 0), M2C_FIELD(temp_s2, s32 *, 4));
        temp_v0_3 = NRandInRange(2, 3);
        var_a3 = 0;
        if (temp_v0_3 > 0) {
            var_a1_2 = temp_v0_3 - 0;
loop_26:
            temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x484);
            temp_lo = var_s0 / var_a1_2;
            M2C_FIELD(arg0, s32 *, 0x484) = (s32) (temp_v0_4 + 1);
            temp_v1_2 = arg0 + ((temp_v0_4 * 0x10) + 0x404);
            M2C_FIELD(temp_v1_2, s32 *, 0) = 0x2B3;
            M2C_FIELD(temp_v1_2, s32 *, 4) = 0;
            if (var_a1_2 == 0) {
                M2C_BREAK(0);
            }
            temp_a0_2 = (temp_lo > 0) ? temp_lo : 1;
            var_s0 -= temp_a0_2;
            M2C_FIELD(temp_v1_2, s32 *, 0xC) = temp_a0_2;
            if (var_s0 != 0) {
                var_a3 += 1;
                var_a1_2 = temp_v0_3 - var_a3;
                if (var_a3 < temp_v0_3) {
                    goto loop_26;
                }
            }
        }
        var_v0 = spC;
        if (var_v0 > 0) {
            temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x484);
            var_v0 = (s32) ((temp_v1_3 * 0x10) + arg0);
            M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a0, ($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a1, 0xf($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a1, 0x8($sp) */);
            M2C_ERROR(/* unknown instruction: sdl $a0, 0x40b($v0) */);
            M2C_ERROR(/* unknown instruction: sdr $a0, 0x404($v0) */);
            M2C_ERROR(/* unknown instruction: sdl $a1, 0x413($v0) */);
            M2C_ERROR(/* unknown instruction: sdr $a1, 0x40c($v0) */);
            M2C_FIELD(arg0, s32 *, 0x484) = (s32) (temp_v1_3 + 1);
        }
    }
    return (void *) var_v0;
}
