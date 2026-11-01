#include "m2c_macros.h"

M2C_UNK ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(s32, M2C_UNK, M2C_UNK, s128, M2C_UNK, M2C_UNK); /* extern */
f32 GRandInRange(M2C_UNK, M2C_UNK);                 /* extern */
void *Swarm_PriderNearest(void *, s128);            /* extern */
M2C_UNK Swarm_SetRiderState(void *, void *, M2C_UNK); /* extern */
extern f32 D_FLT_002BE8A8;
extern s128 g_2a2dd0;

s32 Swarm_FTakeHit(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_v0_2;
    void *temp_v0;

    if (!(M2C_FIELD(arg1, s32 *, 0x44) & 8)) {
        return 0;
    }
    temp_v0 = Swarm_PriderNearest(arg0, M2C_FIELD(arg1, s128 *, 0x20));
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, s32 *, 0x4C) + M2C_FIELD(arg1, s32 *, 0x10);
        M2C_FIELD(temp_v0, s32 *, 0x4C) = temp_v0_2;
        if (temp_v0_2 > 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf3 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_FIELD(temp_v0, f32 *, 0x58) = (f32) (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) * D_FLT_002BE8A8);
            M2C_FIELD(temp_v0, f32 *, 0x5C) = GRandInRange(0xC1700000, 0x41700000);
            Swarm_SetRiderState(arg0, temp_v0, 1);
        } else {
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x190);
            if (temp_a0 != 0) {
                ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(temp_a0, 4, 0, g_2a2dd0, 0, 0);
            }
            Swarm_SetRiderState(arg0, temp_v0, 2);
        }
    }
    return 1;
}
