#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK SquishCmEye(s32, s32, s32, M2C_UNK *, f32, f32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BD8D8;
extern f32 D_FLT_002BD8DC;
extern M2C_UNK SvSquishCmEyeConstraint;
extern M2C_UNK func_0014F030;

s128 ClipCmEye(s32 arg0, s128 arg1) {
    M2C_UNK sp40;
    M2C_UNK sp50;
    M2C_UNK sp60;
    M2C_UNK sp10;
    s32 sp14;
    s32 sp18;
    s128 sp20;

    sp20 = arg1;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf5 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf5, $vf5, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf4, $q */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v1) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf4, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x50($sp) */);
    CStackFrame_Construct(&sp10, M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf4 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */));
    bevy_camera_follow_push_out(&B_003DD490, sp40, sp50, &func_0014F030);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    SquishCmEye(arg0, sp14, sp18, &SvSquishCmEyeConstraint, D_FLT_002BD8D8, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) + D_FLT_002BD8DC);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    CStackFrame_Destructor(&sp10, 2);
    return sp60;
}
