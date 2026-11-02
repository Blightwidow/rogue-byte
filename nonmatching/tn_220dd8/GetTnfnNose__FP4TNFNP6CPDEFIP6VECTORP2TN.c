#include "m2c_macros.h"

M2C_UNK CalculateTnCrv(void *, s128, void *, M2C_UNK *); /* extern */
s32 CalculateTnPos__FP2TNP6VECTORffP3CLQP2LM4FTNDT1(void *, void *, M2C_UNK *, void *, f32, M2C_UNK); /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */

s32 GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(void *arg0, s32 arg1, s128 *arg2, void *arg3) {
    char sp[0x400];
    M2C_UNK sp10;
    f32 sp14;
    f32 sp24;
    f32 sp34;
    M2C_UNK sp40;
    s32 temp_s1;
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s4) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    if (arg3 != NULL) {
        memset(&sp10, 0, 0x30);
        temp_s1 = M2C_FIELD(arg3, s32 *, 0x120);
        M2C_FIELD(arg3, s32 *, 0x120) = 0;
        sp14 = M2C_FIELD(arg0, f32 *, 0x70);
        sp24 = M2C_FIELD(arg0, f32 *, 0x74);
        sp34 = M2C_FIELD(arg0, f32 *, 0x78);
        CalculateTnCrv(arg3, *arg2, sp, &sp40);
        var_v0 = CalculateTnPos__FP2TNP6VECTORffP3CLQP2LM4FTNDT1(arg3, sp, &sp10, arg0 + 0x40, M2C_FIELD(arg3, f32 *, 0x140), 0);
        M2C_FIELD(arg3, s32 *, 0x120) = temp_s1;
    }
    return var_v0;
}
