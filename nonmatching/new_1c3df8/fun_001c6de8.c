#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterDprizeObjects;

s32 func_001C6DE8(s128 arg0, s32 arg1, s32 arg2, s128 *arg3, f32 fparg0, f32 fparg1, f32 fparg2) {
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp28;
    M2C_UNK sp38;
    M2C_UNK sp40;
    M2C_UNK sp44;
    M2C_UNK spA0;
    M2C_UNK spB0;
    M2C_UNK sp60;
    s32 sp80;
    s32 sp84;
    s128 sp90;
    s128 var_v0;

    sp90 = arg0;
    sp84 = arg2;
    sp80 = arg1;
    CStackFrame_Construct(&sp60);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
    if (sp84 == 0) {
        bevy_camera_follow_push_out(&B_003DD490, sp90, spA0, &FFilterDprizeObjects);
    }
    if (fparg1 > 0.0f) {
        if ((PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80) != 0) && (sp40 == 0.0f)) {
            if (sp44 != 1.0f) {
                var_v0 = sp10;
                if (!(sp38 < fparg2)) {
                    goto block_17;
                }
            }
            goto block_15;
        }
        goto block_9;
    }
block_9:
    if (fparg0 < 0.0f) {
        if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spB0, sp80) != 0) {
            if (sp40 != 0.0f) {
                var_v0 = sp0;
                if (!(sp28 < fparg2)) {
                    goto block_17;
                }
            }
            goto block_15;
        }
block_15:
        CStackFrame_Destructor(&sp60, 2);
        return 0;
    }
    var_v0 = sp90;
block_17:
    *arg3 = var_v0;
    CStackFrame_Destructor(&sp60, 2);
    return 1;
}
