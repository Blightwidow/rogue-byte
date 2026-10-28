#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DecomposeCylind(M2C_UNK, f32 *, f32 *, f32 *); /* extern */
M2C_UNK FFindCmClearInterval(s32, s32, s128, s128, f32); /* extern */
s128 FindCmClosestClearPos(s32, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, f32); /* extern */
M2C_UNK SquishCmEye(M2C_UNK *, s32, s32, M2C_UNK *, f32, f32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
extern M2C_UNK FtndCptnSquishConstraint;
extern M2C_UNK func_0014F030;

void FindCptnClearEyePosition(void *arg0, s128 arg1, s128 arg2, s32 arg3) {
    M2C_UNK sp0;
    M2C_UNK sp70;
    s128 sp20;
    s128 sp30;
    M2C_UNK sp40;
    s32 sp90;
    s32 sp94;
    f32 sp98;
    f32 sp9C;
    f32 spA0;
    f32 spA4;
    f32 spA8;
    s128 spB0;
    s128 spC0;
    f32 temp_f1;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    s128 var_v0;
    s32 temp_s1;

    spC0 = arg2;
    spB0 = arg1;
    temp_s1 = M2C_FIELD(arg0, s32 *, 0);
    CStackFrame_Construct(&sp40);
    var_f20 = 0.0f;
    PosLoWorld(temp_s1);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmini.xyz $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: vmini.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    PosLoWorld(temp_s1);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmax.xyz $vf1, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: vmax.xyz $vf1, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    bevy_camera_follow_push_out(&B_003DD490, sp0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), &func_0014F030);
    PosLoWorld(temp_s1);
    sp20 = FindCmClosestClearPos(sp90, sp94, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), 0x43FA0000);
    FFindCmClearInterval(sp90, sp94, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), spC0, 0.0f);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($sp) */);
    if (sp9C < 1.0f) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_FIELD(arg0, s32 *, 0x34) = 4;
        DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &spA0, &spA4, &spA8);
        var_f21 = 3.4028235e38f;
loop_2:
        SetVectorCylind__FP6VECTORfff(spA0 + var_f20, spA4, spA8);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
        FFindCmClearInterval(sp90, sp94, sp20, M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf2 */), 0.0f);
        temp_f1 = (1.25f - sp9C) * (fabsf(var_f20) + 0.47123894f);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
        if (temp_f1 < var_f21) {
            var_f21 = temp_f1;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf4x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x80($sp) */);
        }
        var_f1 = -var_f20;
        if (var_f20 <= 0.0f) {
            var_f1 += 0.28559935f;
        }
        var_f20 = var_f1;
        if (!(var_f21 < ((fabsf(var_f1) + 0.47123894f) * 0.25f)) && (var_f1 < 3.1415927f)) {
            goto loop_2;
        }
        var_v0 = sp70;
    } else {
        var_v0 = spC0;
    }
    sp30 = var_v0;
    M2C_ERROR(/* unknown instruction: por $t1, $zero, $t0 */);
    SquishCmEye(&B_002DDF40, sp90, sp94, &FtndCptnSquishConstraint, M2C_FIELD(&B_002DDF40, f32 *, 0x48), M2C_FIELD(&B_002DDF40, f32 *, 0x48));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xd0($sp) */);
    FFindCmClearInterval(sp90, sp94, sp30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf4 */), 0.0f);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xd0($sp) */);
    if (sp9C != 1.0f) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($s3) */);
    CStackFrame_Destructor(&sp40, 2);
}
