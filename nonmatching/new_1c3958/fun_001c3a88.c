#include "m2c_macros.h"

f32 GRandInRange(M2C_UNK, f32);                     /* extern */
M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(s32, M2C_UNK, M2C_UNK *, f32); /* extern */
M2C_UNK GetPathPosFromS(s32, void *, M2C_UNK, f32); /* extern */
f32 SRandNearCrv(f32);                              /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, M2C_UNK, M2C_UNK); /* extern */
extern f32 g_2c0d08;
extern f32 g_2c0d0c;
extern f32 g_2c0d10;

void func_001C3A88(s32 arg0, s32 arg1, s128 *arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    s128 sp60;
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = SRandNearCrv(g_2c0d10);
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(arg0, 1, &sp10, temp_f0);
    GetPathPosFromS(arg0, sp, 0, temp_f0);
    temp_f0_2 = GRandInRange(0xBF800000, 1.0f);
    SetVectorCylind__FP6VECTORfff(temp_f0_2 * fabsf(temp_f0_2) * g_2c0d08, 0xBF800000, 0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x50($sp) */);
    sp60 = sp0;
    GRandInRange(0, g_2c0d0c);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    *arg2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
}
