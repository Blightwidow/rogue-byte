#include "m2c_macros.h"

M2C_UNK ConvertAloPos(M2C_UNK, void *, s128);       /* extern */
M2C_UNK FindCrvClosestPointFromS(s32, s128, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(s32, void *, M2C_UNK); /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */

void UpdateCptnClosestPoint(void *arg0) {
    char sp[0x10];
    M2C_UNK sp0;
    f32 var_f2;
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x10);
    if ((temp_s0 != NULL) && ((M2C_FIELD(temp_s0, s32 *, 0x10C) != 0) || (M2C_FIELD(temp_s0, s32 *, 0x12C) != 0))) {
        GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(M2C_FIELD(arg0, s32 *, 0x14), sp, 0);
        temp_a0 = M2C_FIELD(temp_s0, s32 *, 0x10C);
        if (temp_a0 != 0) {
            FindCrvClosestPointFromS(temp_a0, sp0, 0, 0, M2C_FIELD(temp_s0, f32 *, 0x140));
            return;
        }
        ConvertAloPos(0, temp_s0, sp0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x150($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
        var_f2 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */));
        if (var_f2 < 0.0f) {
            var_f2 += 6.2831855f;
        }
        M2C_FIELD(temp_s0, f32 *, 0x140) = (f32) (var_f2 * M2C_FIELD(temp_s0, f32 *, 0x160));
    }
}
