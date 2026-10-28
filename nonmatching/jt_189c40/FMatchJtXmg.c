#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s128 ConvertAloPos(void *, void *, s128);           /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK SetActadjOffset(s32, s128);                 /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterOxa;
extern s128 g_2a2dd0;

s32 FMatchJtXmg(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK sp28;
    M2C_UNK sp40;
    M2C_UNK sp60;
    s32 sp80;
    s32 sp84;
    s128 sp90;
    s128 spA0;
    s128 spB0;

    if (M2C_FIELD(arg1, s32 *, 4) != 0) {
        CStackFrame_Construct(&sp60);
        sp90 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x30));
        spA0 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x40));
        spB0 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x50));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vmini.xyz $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vmini.xyz $vf4, $vf4, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmax.xyz $vf2, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vmax.xyz $vf1, $vf1, $vf2 */);
        bevy_camera_follow_push_out(&B_003DD490, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), &FFilterOxa);
        if ((PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80) != 0) || (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, spA0, spB0, sp80) != 0)) {
            if (sp40 != 0.0f) {
                if (sp28 > 0.7f) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                    ConvertAloPos(NULL, arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s1) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
                    SetActadjOffset(arg2, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
                    goto block_10;
                }
                goto block_6;
            }
            goto block_7;
        }
block_6:
block_7:
        SetActadjOffset(arg2, g_2a2dd0);
        if ((M2C_FIELD(arg0, s32 *, 0x208) != 0) && (M2C_FIELD(arg1, f32 *, 0x48) < -85.0f)) {
            CStackFrame_Destructor(&sp60, 2);
            return 0;
        }
block_10:
        CStackFrame_Destructor(&sp60, 2);
        goto block_11;
    }
block_11:
    return 1;
}
