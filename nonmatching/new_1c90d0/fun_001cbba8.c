#include "m2c_macros.h"

f32 GRandInRange(M2C_UNK, f32);                     /* extern */
M2C_UNK GetPathPosFromS(s32, void *, M2C_UNK *, f32); /* extern */
f32 SRandNearCrv(f32);                              /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, M2C_UNK, M2C_UNK); /* extern */
extern f32 g_2c1ec4;
extern f32 g_2c1ec8;
extern f32 g_2c1ecc;

void func_001CBBA8(s32 arg0, s32 arg1, s128 *arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp60;
    M2C_UNK sp30;
    s128 sp50;
    s128 sp70;
    f32 temp_f0;

    GetPathPosFromS(arg0, sp, &sp30, SRandNearCrv(g_2c1ec4));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f)) {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    temp_f0 = GRandInRange(0xBF800000, 1.0f);
    SetVectorCylind__FP6VECTORfff(temp_f0 * fabsf(temp_f0) * g_2c1ec8, 0x3F800000, 0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x60($sp) */);
    sp50 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
    if (arg1 != 0) {
        sp70 = sp0;
        GRandInRange(0, g_2c1ecc);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    }
    if (arg2 != NULL) {
        *arg2 = sp60;
    }
}
