#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *, void *);   /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
void *PentryFindSensorLo(s32, void *);              /* extern */
s128 PosLoWorld(void *);                            /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK SetSensorEntryState(void *, void *, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern void *B_003E1444;
extern M2C_UNK FFilterSensorSight;
extern f32 g_2bf638;

void ForgetJtGuards(void **arg0) {
    M2C_UNK sp1;
    s32 sp4;
    s32 sp8;
    s128 sp10;
    s128 sp20;
    s32 var_a0;
    s32 var_v0;
    void *temp_v0;
    void *var_s0;

    var_s0 = B_003E1444;
    if (var_s0 != NULL) {
        var_a0 = M2C_FIELD(var_s0, s32 *, 0xF64);
loop_2:
        temp_v0 = PentryFindSensorLo(var_a0, *arg0);
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 4) != 0) && !(M2C_FIELD(M2C_FIELD(var_s0, void **, 0xF64), s32 *, 0xF8) & 1)) {
            sp10 = PosLoWorld(var_s0);
            sp20 = PosLoWorld(*arg0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
            var_v0 = 1;
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (!(g_2bf638 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                var_v0 = 0;
            }
            if (var_v0 != 0) {
                SetSensorEntryState(M2C_FIELD(var_s0, void **, 0xF64), temp_v0, 0);
            } else {
                CStackFrame_Construct(&sp1, temp_v0);
                bevy_camera_follow_push_out(&B_003DD490, sp10, sp20, &FFilterSensorSight);
                if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp20, sp4) != 0) {
                    SetSensorEntryState(M2C_FIELD(var_s0, void **, 0xF64), temp_v0, 0);
                    CStackFrame_Destructor(&sp1, 2);
                } else {
                    CStackFrame_Destructor(&sp1, 2);
                }
            }
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0xFE0);
        if (var_s0 != NULL) {
            var_a0 = M2C_FIELD(var_s0, s32 *, 0xF64);
            goto loop_2;
        }
    }
}
