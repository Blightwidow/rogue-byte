#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */

s32 PredictLoLead(void *arg0, void *arg1, f32 fparg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    PosLoWorld(arg0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($s1) */);
    M2C_FIELD(arg1, f32 *, 4) = 150.0f;
    M2C_FIELD(arg1, f32 *, 8) = 75.0f;
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_FIELD(arg1, s32 *, 0) = 0;
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
}
