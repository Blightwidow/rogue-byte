#include "m2c_macros.h"

M2C_UNK SetSoMass__FP2SOf(f32);                     /* extern */

void *SetStepGravityRatio__FP4STEPf(void *arg0) {
    f32 temp_f20;

    temp_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f20, $f12 */);
    SetSoMass__FP2SOf((M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), f32 *, 0xD0) * M2C_FIELD(arg0, f32 *, 0x260)) / temp_f20);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($v0) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf1, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($v0) */);
    M2C_FIELD(arg0, f32 *, 0x260) = temp_f20;
    return M2C_FIELD(arg0, void **, 0xE8);
}
