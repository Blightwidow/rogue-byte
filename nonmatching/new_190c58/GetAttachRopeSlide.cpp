#include "m2c_macros.h"
extern "C" {

M2C_UNK EvaluateCrvFromU(s32, void *, M2C_UNK *);   /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(f32 *, f32 *, f32, f32, f32); /* extern */
f32 SFromCrvU(s32, f32);                            /* extern */
f32 SMaxCrv(s32);                                   /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
extern f32 D_FLT_002BF668;
extern M2C_UNK g_2dded0;

s32 GetAttachRopeSlide(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    char sp[0x70];
    M2C_UNK sp10;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp50;
    f32 sp54;
    f32 temp_f20;
    f32 temp_v0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x150);
    EvaluateCrvFromU(arg1, sp, &sp10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    SetVectorCylind__FP6VECTORfff(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x150), f32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x2A0) * M2C_FIELD(temp_s0, f32 *, 0x1C), 0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f20 = SFromCrvU(arg1, fparg0);
    sp34 = M2C_FIELD(arg0, f32 *, 0x260);
    sp30 = M2C_FIELD(arg0, f32 *, 0x2A0);
    sp38 = D_FLT_002BF668;
    GSmooth__FfffP3SMPPf(&sp30, &sp50, temp_f20, 50.0f, M2C_FIELD(&g_2dded0, f32 *, 4));
    GSmooth__FfffP3SMPPf(&sp30, &sp54, temp_f20, SMaxCrv(arg1) - 50.0f, M2C_FIELD(&g_2dded0, f32 *, 4));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($v0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s4) */);
    if (!(temp_v0 < sp50) && (sp54 < temp_v0)) {

    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s5) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
}
}
