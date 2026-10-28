#include "m2c_macros.h"

M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK GLimitAbs__Fff(f32, f32);                   /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, f32, f32, f32); /* extern */
M2C_UNK LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
extern M2C_UNK D_002BC9A8;
extern f32 D_FLT_002BC998;
extern f32 D_FLT_002BC99C;
extern f32 D_FLT_002BC9A0;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;

void PresetJtOrbitAccel(void **arg0) {
    M2C_UNK sp50;
    f32 sp80;
    s128 spA0;
    f32 temp_f22;
    f32 temp_v1_3;
    void *temp_a1;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_2;

    temp_a1 = *arg0;
    temp_s1 = M2C_FIELD(temp_a1, void **, 0x10DC);
    if (temp_s1 != NULL) {
        temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
        temp_f22 = ((D_FLT_002BC99C * D_FLT_002BC99C) / D_FLT_002BC998) + D_FLT_002BC9A0;
        temp_v1_2 = M2C_FIELD(temp_s1, void **, 0xC);
        spA0 = M2C_FIELD(temp_v1, s128 (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1);
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(temp_s1 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
        PosLoWorld(*arg0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
        PosLoWorld(temp_s1);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {

        } else {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf3, $vf1 */);
        temp_v1_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        GSmooth__FfffP3SMPPf(&D_002BC9A8, &sp80, temp_v1_3, D_FLT_002BC998, M2C_FIELD(&g_2dded0, f32 *, 4));
        GLimitAbs__Fff(sp80 - M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */), D_FLT_002BC9A0 * M2C_FIELD(&g_2dded0, f32 *, 4));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
        LoadRotateMatrixRad(&sp50, g_2a2dc0, (M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */) / temp_v1_3) * M2C_FIELD(&g_2dded0, f32 *, 4));
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf5 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf4, $vf1z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf5x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
        LimitVectorLength__FP6VECTORfT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), temp_f22);
        AddSoAcceleration(*arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    }
}
