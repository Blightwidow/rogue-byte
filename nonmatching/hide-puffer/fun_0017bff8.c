#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(M2C_UNK, s128, s128, s128 *); /* extern */
s32 ClsgClipEdgeToPathzoneObstacles(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK DecomposeCylind(M2C_UNK, f32 *, f32 *, M2C_UNK); /* extern */
s32 FCheckLm__FP2LMf(f32 *, f32);                   /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
f32 GLimitLm__FP2LMf(f32 *, f32);                   /* extern */
M2C_UNK PosLoWorld(void *, s32);                    /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
s32 func_001C0B50(s32, s128, void *);               /* extern */

s128 func_0017BFF8(void *arg0, s32 arg1, s128 arg2, f32 fparg0) {
    f32 saved_reg_f22;
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp10;
    f32 sp14;
    f32 sp20;
    f32 sp24;
    s32 sp30;
    f32 sp34;
    s128 sp40;
    M2C_UNK sp50;
    f32 sp350;
    f32 sp354;
    f32 sp358;
    f32 sp35C;
    f32 sp360;
    s128 sp370;
    s32 sp380;
    M2C_UNK *var_s0_2;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f20;
    f32 var_f22;
    s128 var_v0;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    void *temp_a0;
    void *temp_s5;
    void *temp_v0;
    void *temp_v1;

    var_f22 = saved_reg_f22;
    temp_v1 = M2C_FIELD(arg0, void **, 0x10);
    sp370 = arg2;
    M2C_ERROR(/* unknown instruction: ldl $a1, 0x323($v1) */);
    M2C_ERROR(/* unknown instruction: ldr $a1, 0x31c($v1) */);
    M2C_ERROR(/* unknown instruction: sdl $a1, 0x17($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $a1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $a1, 0x32b($v1) */);
    M2C_ERROR(/* unknown instruction: ldr $a1, 0x324($v1) */);
    M2C_ERROR(/* unknown instruction: sdl $a1, 0x27($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $a1, 0x20($sp) */);
    temp_a1 = M2C_FIELD(temp_v1, s32 *, 0xFBC);
    if ((temp_a1 == 8) || (temp_a1 == 0xD)) {
        temp_v0 = M2C_FIELD(temp_v1, void **, 0xFC4);
        if (temp_v0 != NULL) {
            temp_f0 = M2C_FIELD(temp_v0, f32 *, 0x20);
            sp10 *= temp_f0;
            sp14 *= temp_f0;
            sp20 *= temp_f0;
            sp24 *= temp_f0;
        }
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    temp_s5 = M2C_FIELD(temp_a0, void **, 0x3CC);
    PosLoWorld(temp_a0, temp_a1);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x370($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &sp350, &sp354, 0);
    temp_f20 = fparg0 + GLimitAbs__Fff(RadNormalize__Ff(sp350 - fparg0), M2C_FIELD(temp_s5, f32 *, 0x14));
    SetVectorCylind__FP6VECTORfff(temp_f20, GLimitLm__FP2LMf(&sp10, sp354), 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x370($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    if ((func_001C0B50(arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), sp) == 0) || (M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x370($sp) */), M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */), DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), &sp358, &sp35C, 0), !(fabsf(RadNormalize__Ff(sp358 - fparg0)) < M2C_FIELD(temp_s5, f32 *, 0x18))) || (var_v0 = sp0, (FCheckLm__FP2LMf(&sp20, sp35C) == 0))) {
        var_s3 = 0;
loop_8:
        switch (var_s3) {                           /* irregular */
        case 0:
            M2C_ERROR(/* unknown instruction: ldl $v0, 0x17($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $v0, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sdl $v0, 0x37($sp) */);
            M2C_ERROR(/* unknown instruction: sdr $v0, 0x30($sp) */);
            sp380 = 0xA;
            var_f22 = M2C_FIELD(temp_s5, f32 *, 0x14);
            break;
        case 1:
            M2C_ERROR(/* unknown instruction: ldl $a3, 0x27($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sdl $a3, 0x37($sp) */);
            M2C_ERROR(/* unknown instruction: sdr $a3, 0x30($sp) */);
            sp380 = 0xA;
            var_f22 = M2C_FIELD(temp_s5, f32 *, 0x18);
            break;
        case 2:
            sp380 = 0xF;
            sp30 = 0;
            sp34 = sp24;
            var_f22 = 3.1415927f;
            break;
        }
        if (M2C_FIELD(temp_s5, s32 *, 0x10) == -1) {
            var_f22 = 3.1415927f;
        }
        var_f20 = 3.4028235e38f;
        var_s0 = 0;
        if (sp380 > 0) {
            do {
                SetVectorCylind__FP6VECTORfff(fparg0 + ((((f32) var_s0 / ((f32) (sp380 - 1) * 0.5f)) + -1.0f) * var_f22), 1.0f, 0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $t0, $vf3 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x370($sp) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x370($sp) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
                temp_v0_2 = ClsgClipEdgeToPathzoneObstacles(arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */), 8);
                var_s0_2 = &sp50;
                if (temp_v0_2 > 0) {
                    var_s1 = temp_v0_2;
                    do {
                        ClosestPointOnSegment(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s7 */), M2C_FIELD(var_s0_2, s128 *, 0), M2C_FIELD(var_s0_2, s128 *, 0x10), &sp40);
                        var_s1 -= 1;
                        if (sp360 < var_f20) {
                            var_f20 = sp360;
                        }
                        var_s0_2 += 0x60;
                    } while (var_s1 != 0);
                }
                var_s0 += 1;
            } while (var_s0 < sp380);
        }
        var_s3 += 1;
        if (var_f20 == 3.4028235e38f) {
            if (var_s3 >= 3) {
                var_v0 = sp0;
                if (func_001C0B50(arg1, sp370, sp) == 0) {
                    return sp370;
                }
                /* Duplicate return node #32. Try simplifying control flow for better match */
                return var_v0;
            }
            goto loop_8;
        }
        var_v0 = M2C_ERROR(/* unknown instruction: por $v0, $zero, $s6 */);
        /* Duplicate return node #32. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
