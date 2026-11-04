#include "m2c_macros.h"

M2C_UNK PxpAdd(M2C_UNK, f32, s32);                  /* extern */

void MarkSoContactsSphereSphere(void *arg1, void *arg2, s32 arg3) {
    f32 temp_f1;
    f32 temp_v0;
    f32 var_f12;

    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
    temp_f1 = M2C_FIELD(arg1, f32 *, 8) + M2C_FIELD(arg2, f32 *, 8);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($v1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    if (!((temp_f1 * temp_f1) < temp_v0)) {
        if (temp_v0 < 0.0001f) {
            var_f12 = 0.0f;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
        } else {
            M2C_ERROR(/* unknown instruction: c1 0xc0004 */);
            var_f12 = 0.0001f;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
        }
        M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf2 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        PxpAdd(M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf3 */), var_f12 - temp_f1, arg3);
    }
}
