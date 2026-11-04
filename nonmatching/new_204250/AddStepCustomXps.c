#include "m2c_macros.h"

s32 ClsgClipEdgeToObjectPruned(void *, M2C_UNK, M2C_UNK, s128); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK PxpAdd(M2C_UNK *, s32, void *, M2C_UNK, M2C_UNK, s32); /* extern */
s32 bevy_physics_motor_2048c8(void *, s128, void *, s32); /* extern */
M2C_UNK func_001F5990();                            /* extern */
extern M2C_UNK B_003DD490;

void AddStepCustomXps(void *arg0, void *arg1) {
    M2C_UNK sp38;
    M2C_UNK sp50;
    M2C_UNK sp58;
    M2C_UNK sp5C;
    M2C_UNK sp10;
    s128 *var_a3;
    s32 temp_v0;
    void *temp_v1;

    func_001F5990();
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, s32 (**)(void *), 0x2AC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x2A8));
    if ((temp_v0 & 1) && (FIsBasicDerivedFrom(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, void **, 4), void **, 0xEC), s32 *, 0x60), 0x33) == 0)) {
        PosLoWorld(arg0);
        if (!(temp_v0 & 2)) {
            var_a3 = M2C_FIELD(arg0, s128 **, 0x218);
        } else {
            var_a3 = M2C_FIELD(arg0, s128 **, 0x21C);
        }
        if ((ClsgClipEdgeToObjectPruned(arg1, M2C_ERROR(/* Read from unset register $t0 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), *var_a3) > 0) && (sp50 > 0.0f)) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
            if (!(temp_v0 & 8)) {
                if (!(sp38 > 0.7f)) {
                    if (sp58 == 0) {
                        if (bevy_physics_motor_2048c8(arg0, *M2C_FIELD(arg0, s128 **, 0x218), arg1, sp5C) != 0) {
                            goto block_12;
                        }
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                    }
                } else {
block_12:
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
                }
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf4 */);
            PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf2 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */), M2C_ERROR(/* Read from unset register $t1 */));
        }
    }
}
