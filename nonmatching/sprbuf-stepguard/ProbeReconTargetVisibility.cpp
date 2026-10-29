#include "m2c_macros.h"
extern "C" {

M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK func_00202350;

void ProbeReconTargetVisibility(void *arg0, void *arg1) {
    char sp[0x60];
    s128 sp10;
    s32 sp60;
    s32 sp64;
    f32 temp_f20;
    s128 *var_s0;
    s128 temp_a2;
    s32 var_s1;
    s32 var_v0;
    u32 var_s4;

    var_s1 = 0;
    var_s4 = 0;
    CStackFrame_Construct(sp);
    PosLoWorld(arg1);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
    temp_f20 = M2C_FIELD(arg1, f32 *, 0xE4);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x70($sp) */);
    bevy_camera_follow_push_out(&B_003DD490, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */), M2C_FIELD(arg0, s128 *, 0x20), &func_00202350);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf6 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf4 */);
    var_s0 = &sp10;
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf7, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf7, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf5x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf6, $vf6, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf4, $vf5x */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf6, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf5x */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf6, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf6, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    do {
        temp_a2 = *var_s0;
        var_s4 += 1;
        var_s0 += 0x10;
        var_s1 = (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, M2C_FIELD(arg0, s128 *, 0x20), temp_a2, sp60) != 0) ? (var_s1 + 1) : var_s1;
    } while (var_s4 < 4U);
    if (var_s1 < 4) {
        var_v0 = 3;
        if (var_s1 <= 0) {
            if (var_s1 != 0) {

            } else {
                var_v0 = 1;
                goto block_10;
            }
        } else {
            goto block_10;
        }
    } else if (var_s1 != 4) {

    } else {
        var_v0 = 2;
block_10:
        M2C_FIELD(arg1, s32 *, 0x108) = var_v0;
    }
    CStackFrame_Destructor(sp, 2);
}
}
