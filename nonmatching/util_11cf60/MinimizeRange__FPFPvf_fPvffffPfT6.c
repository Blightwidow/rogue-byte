#include "m2c_macros.h"

s32 MinimizeRange__FPFPvf_fPvffffPfT6(f32 (*arg0)(s32, f32), s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_ret;
    f32 var_f12;
    f32 var_f12_2;
    s32 var_s2;
    s32 var_v0;

    if (fparg0 < fparg2) {
        var_f12 = fparg2;
    } else {
        var_f12 = fparg0;
        if (fparg3 < fparg0) {
            var_f12 = fparg3;
        }
    }
    temp_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f22, $f0 */);
    sp0 = temp_f0;
    temp_f0_2 = arg0(arg1, temp_f0);
    sp10 = var_f12;
    sp4 = temp_f0_2;
    sp14 = arg0(arg1, var_f12);
    temp_f1 = M2C_ERROR(/* unknown instruction: min.s $f1, $f21, $f1 */);
    var_f12_2 = temp_f1;
    sp20 = temp_f1;
loop_5:
    sp24 = arg0(arg1, var_f12_2);
loop_6:
    if (sp4 < sp14) {
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0x27($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a2, 0x7($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a2, ($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $a2, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $a2, 0x10($sp) */);
        temp_f0_3 = M2C_ERROR(/* unknown instruction: max.s $f0, $f22, $f0 */);
        sp0 = temp_f0_3;
        sp4 = arg0(arg1, temp_f0_3);
        goto loop_6;
    }
    var_s2 = 9;
    if (sp24 < sp14) {
        M2C_ERROR(/* unknown instruction: ldl $a2, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $a2, 0x7($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $a2, ($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a1, 0x27($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $a1, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $a1, 0x10($sp) */);
        temp_f0_4 = M2C_ERROR(/* unknown instruction: min.s $f0, $f21, $f0 */);
        var_f12_2 = temp_f0_4;
        sp20 = temp_f0_4;
        goto loop_5;
    }
    do {
        temp_f1_2 = (sp0 + sp10) * 0.5f;
        sp8 = temp_f1_2;
        spC = arg0(arg1, temp_f1_2);
        temp_f1_3 = (sp10 + sp20) * 0.5f;
        sp18 = temp_f1_3;
        temp_ret = arg0(arg1, temp_f1_3);
        var_v0 = M2C_BITWISE(s32, temp_ret);
        temp_f0_5 = temp_ret;
        sp1C = temp_f0_5;
        if (spC < sp14) {
            if (spC < temp_f0_5) {
                M2C_ERROR(/* unknown instruction: ldl $a0, 0x17($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $a0, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $a0, 0x27($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $a0, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: ldl $v1, 0xf($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x8($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x17($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x10($sp) */);
                var_s2 -= 1;
            } else {
                M2C_ERROR(/* unknown instruction: ldl $v0, 0x17($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $v0, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
                var_v0 = M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
                M2C_ERROR(/* unknown instruction: ldl $a2, 0x1f($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, 0x18($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0x17($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $a2, 0x10($sp) */);
                var_s2 -= 1;
            }
        } else {
            var_s2 -= 1;
            if (sp14 <= temp_f0_5) {
                M2C_ERROR(/* unknown instruction: ldl $a1, 0xf($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, 0x8($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, ($sp) */);
                M2C_ERROR(/* unknown instruction: ldl $a0, 0x1f($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $a0, 0x18($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $a0, 0x27($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $a0, 0x20($sp) */);
            } else {
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x17($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, ($sp) */);
                M2C_ERROR(/* unknown instruction: ldl $v0, 0x1f($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $v0, 0x18($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v0, 0x17($sp) */);
                var_v0 = M2C_ERROR(/* unknown instruction: sdr $v0, 0x10($sp) */);
            }
        }
    } while (var_s2 >= 0);
    if (arg2 != NULL) {
        *arg2 = sp10;
    }
    if (arg3 != NULL) {
        *arg3 = sp14;
    }
    return var_v0;
}
