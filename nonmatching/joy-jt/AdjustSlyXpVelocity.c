#include "m2c_macros.h"

s32 AdjustStepXpVelocity();                         /* extern */
M2C_UNK PosLoWorld(void *, s128, s128);             /* extern */

s32 AdjustSlyXpVelocity(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1;

    var_v0 = AdjustStepXpVelocity();
    temp_s0 = arg1 + (arg2 << 6);
    temp_s1 = M2C_FIELD(temp_s0, void **, 0xC);
    if (temp_s1 == arg0) {
        temp_v1 = M2C_FIELD(temp_s1, void **, 0xC);
        PosLoWorld(temp_s1, M2C_FIELD(temp_v1, s128 (**)(void *, s128), 0x114)(temp_s1 + M2C_FIELD(temp_v1, s16 *, 0x110), M2C_FIELD(temp_s0, s128 *, 0x30)), M2C_FIELD(temp_s0, s128 *, 0x10));
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($s0) */);
    }
    return var_v0;
}
