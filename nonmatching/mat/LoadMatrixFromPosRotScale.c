#include "m2c_macros.h"

void *LoadMatrixFromPosRotScale(void *arg0, s128 arg1, void *arg3) {
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a2) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a2) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_FIELD(arg0, s128 *, 0x30) = arg1;
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_FIELD(arg0, f32 *, 0xC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 0.0f;
    return arg0;
}
