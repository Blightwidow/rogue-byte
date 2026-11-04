#include "m2c_macros.h"

s32 SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(void *arg0, void *arg2, f32 fparg0, f32 fparg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x300);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */);
    if (temp_v0 != 0) {
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($a1) */);
        M2C_FIELD(arg2, s32 *, 0) = 0;
        M2C_FIELD(arg2, s32 *, 8) = 0;
        M2C_FIELD(arg2, s32 *, 4) = 0;
        return temp_v0;
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a2) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf5x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($a2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a1) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
}
