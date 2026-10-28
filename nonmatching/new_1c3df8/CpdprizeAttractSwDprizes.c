#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DtSolveJumpLaunch(M2C_UNK, s128, f32, f32, f32, f32); /* extern */
s32 FClipEdgeToPathzone(s32, s128, s128, M2C_UNK);  /* extern */
s32 FFindPathzoneClosestPoint(s32, s128, s128 *, M2C_UNK); /* extern */
f32 GRandInRange(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s32 PpathzoneFindPos(s128, M2C_UNK, s128 *);        /* extern */
void *PpoSwFocusBase(s32);                          /* extern */
void **PvAllocStackImpl__Fi(s32 *, s32 *);          /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_001C6BD0(void *, M2C_UNK, M2C_UNK, f32, f32); /* extern */
s32 func_001C6CE8(s32, s32, s32, void **);          /* extern */
s32 func_001C6DE8(M2C_UNK, s32, s32, s128 *, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C0D60;
extern f32 D_FLT_002C0D70;
extern f32 D_FLT_002C0E80;
extern f32 D_FLT_002C0E84;
extern f32 D_FLT_002C0E88;
extern f32 D_FLT_002C0E8C;
extern f32 D_FLT_002C0E90;
extern f32 D_FLT_002C0E94;
extern M2C_UNK D_FLT_002C0EA0;
extern M2C_UNK D_FLT_002C0EB0;
extern f32 D_FLT_002C0EB8;
extern f32 D_FLT_002C0EBC;
extern f32 D_FLT_002C0EC0;
extern M2C_UNK FFilterDprizeObjects;

s32 CpdprizeAttractSwDprizes(s32 arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp90;
    M2C_UNK unksp8;
    s128 sp10;
    f32 sp18;
    M2C_UNK sp20;
    s32 sp30;
    s128 sp50;
    s32 sp70;
    s32 sp74;
    s128 sp80;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f21;
    f32 var_f22;
    s32 temp_s2;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1_2;
    void **temp_v0_3;
    void **var_s0_2;
    void **var_s2;
    void *temp_a0;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_5;
    void *var_v1;

    temp_s2 = M2C_ERROR(/* Read from unset register $t0 */);
    if (func_001C6DE8(M2C_ERROR(/* unknown instruction: por $a0, $zero, $a2 */), 0, 0, sp, 0, 0x43960000, -3.4028235e38f) != 0) {
        var_s5 = 0;
        temp_v0 = PpoSwFocusBase(arg0);
        if (temp_v0 != NULL) {
            temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xE8);
            var_v1 = NULL;
            if (temp_v0_2 != NULL) {
                var_v1 = M2C_FIELD(temp_v0_2, void **, 0xDC);
            }
            var_v0 = 0;
            if (var_v1 != NULL) {
                var_v0 = M2C_FIELD(var_v1, s32 *, 0x10);
            }
            var_s5 = var_v0;
        }
        if (var_s5 == 0) {
            var_s5 = PpathzoneFindPos(sp0, 1, &sp10);
        }
        var_f0 = unksp8;
        if (FFindPathzoneClosestPoint(var_s5, sp0, &sp10, 1) == 0) {
            PosLoWorld(temp_v0);
            M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
            if (FFindPathzoneClosestPoint(var_s5, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), &sp10, 1) != 0) {
                var_f0 = M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
                goto block_12;
            }
        } else {
block_12:
            sp18 = var_f0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
            var_v1_2 = 1;
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (!(D_FLT_002C0E80 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) {
                var_v1_2 = 0;
            }
            if ((var_v1_2 == 0) && (func_001C6DE8(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), 0, 0, &sp10, 0xC37A0000, 0x44BB8000, -3.4028235e38f) != 0)) {
                CStackFrame_Construct(&sp20);
                sp30 = temp_s2 * 4;
                M2C_FIELD(&sp30, s32 *, 4) = 0x10;
                temp_v0_3 = PvAllocStackImpl__Fi(&sp30, &sp30);
                temp_v0_4 = func_001C6CE8(arg0, arg1, temp_s2, temp_v0_3);
                if (temp_v0_4 == 0) {
                    CStackFrame_Destructor(&sp20, 2);
                } else {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf2, $vf5x */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
                    var_s3 = 0;
                    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
                    var_s1 = 0;
                    bevy_camera_follow_push_out(&B_003DD490, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */), &FFilterDprizeObjects);
                    var_f22 = GRandInRange(0xC0490FDB, 0x40490FDB);
                    var_f21 = D_FLT_002C0E8C;
                    if (temp_v0_4 > 0) {
                        var_s2 = temp_v0_3;
loop_20:
                        temp_f0 = (f32) var_s3 * 0.02f;
                        temp_f4 = M2C_FIELD(&D_FLT_002C0EA0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C0EA0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C0EA0, f32 *, 8))));
                        if (temp_f4 < M2C_FIELD(&D_FLT_002C0EB0, f32 *, 0)) {

                        } else if (M2C_FIELD(&D_FLT_002C0EB0, f32 *, 4) < temp_f4) {

                        }
                        sp80 = sp10;
                        SetVectorCylind__FP6VECTORfff(var_f22, var_f21, 0);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf5, $vf1, $vf2 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf5, $vf3 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
                        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf7, $vf5 */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                        } else {
                            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
                        }
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf7 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf6x */);
                        var_s0 = 0;
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xb0($sp) */);
                        if (FClipEdgeToPathzone(var_s5, sp10, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf5 */), 0) == 0) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xb0($sp) */);
                            var_s0 = FClipEdgeToPathzone(var_s5, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */), sp90, 0) == 0;
                        }
                        if ((var_s0 != 0) && (func_001C6DE8(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf5 */), sp70, sp74, &sp50, 0xC3960000, 0x43960000, 0.7f) != 0)) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf3, $vf2x */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf4, $vf1 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
                            DtSolveJumpLaunch(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), D_002C0D60, D_FLT_002C0EB8, D_FLT_002C0EBC, D_FLT_002C0EC0, D_FLT_002C0EC0);
                            temp_f1 = (f32) var_s1;
                            var_s1 += 1;
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xa0($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s7) */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf1 */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
                            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf4, $vf2x */);
                            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf3, $vf1x */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
                            temp_a0 = *var_s2;
                            var_s2 += 4;
                            func_001C6BD0(temp_a0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf5 */), (f32) var_s1 * D_FLT_002C0D70, 3.4028235e38f);
                        }
                        var_f21 += D_FLT_002C0E90;
                        var_f22 = RadNormalize__Ff(var_f22 + D_FLT_002C0E94);
                        if (D_FLT_002C0E84 < var_f21) {
                            var_f21 -= D_FLT_002C0E84 - D_FLT_002C0E88;
                        }
                        var_s3 += 1;
                        temp_v1 = var_s1 < temp_v0_4;
                        if ((var_s3 < 0x32) && (temp_v1 != 0)) {
                            goto loop_20;
                        }
                        if (temp_v1 != 0) {
                            var_s0_2 = &temp_v0_3[var_s1];
                            var_s1_2 = temp_v0_4 - var_s1;
                            do {
                                temp_a2 = *var_s0_2;
                                var_s0_2 += 4;
                                var_s1_2 -= 1;
                                temp_v0_5 = M2C_FIELD(temp_a2, void **, 0xC);
                                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(temp_a2 + M2C_FIELD(temp_v0_5, s16 *, 0x260), 2, temp_a2);
                            } while (var_s1_2 != 0);
                        }
                    }
                    CStackFrame_Destructor(&sp20, 2);
                }
            }
        }
    }
}
