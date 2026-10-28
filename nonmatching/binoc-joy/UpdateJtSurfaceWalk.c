#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, s128); /* extern */
M2C_UNK InvertMatrix3(M2C_UNK *, void *);           /* extern */
s32 PmatLoWorld(void *, s128);                      /* extern */
s128 PosLoWorld();                                  /* extern */
M2C_UNK PosSmooth(s128, s128, M2C_UNK *, s128 *, f32); /* extern */
M2C_UNK SetJtState(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK SmoothMatrix(s32, void *, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK SolvePlainBlendWeights(void *, void *, void *); /* extern */
M2C_UNK Spire_FindClosestPoint(s32, M2C_UNK, void *, void *); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);  /* extern */
M2C_UNK func_001856B8(s32, s32 *);                  /* extern */
M2C_UNK func_001856C0(s32, s32 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_00185A80(s32, s32 *, M2C_UNK);         /* extern */
extern M2C_UNK D_002BE920;
extern M2C_UNK D_002BE930;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;

void UpdateJtSurfaceWalk(void *arg0) {
    M2C_UNK sp230;
    M2C_UNK spC0;
    M2C_UNK unksp2C;
    M2C_UNK unkspB4;
    M2C_UNK unkspB8;
    M2C_UNK sp10;
    s128 sp20;
    s32 sp3C;
    s32 sp4C;
    M2C_UNK sp50;
    M2C_UNK sp60;
    s128 sp90;
    s128 spA0;
    s128 spB0;                                      /* compiler-managed */
    s32 spD0;
    M2C_UNK sp160;
    M2C_UNK sp190;
    M2C_UNK sp1C0;
    s128 sp220;
    s128 sp240;
    M2C_UNK *sp250;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_v1;
    void *temp_a2;
    void *temp_s5;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;

    sp220 = PosLoWorld();
    temp_a2 = arg0 + 0x1F1C;
    Spire_FindClosestPoint(M2C_FIELD(arg0, s32 *, 0x1F18), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), temp_a2, temp_a2);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x220($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf4, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf4 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf2, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf4x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    temp_s5 = arg0 + 0x1B0;
    var_s4 = 2;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x230($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&spA0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), g_2a2dc0);
    __as__6VECTORG9VU_VECTOR(&sp50, sp230);
    sp250 = &sp160;
    sp20 = spA0;
    M2C_FIELD(&sp20, s128 *, 0x10) = spB0;
    M2C_FIELD(&sp20, s128 *, 0x20) = spC0;
    sp4C = 0;
    sp3C = 0;
    unksp2C = 0;
    M2C_FIELD(&sp20, f32 *, 0x3C) = 1.0f;
    do {
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s2) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
        var_s4 -= 1;
        Spire_FindClosestPoint(M2C_FIELD(arg0, s32 *, 0x1F18), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */), arg0 + 0x1F1C, NULL);
    } while (var_s4 >= 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf1, $q */);
    var_s4_2 = 2;
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp90, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), g_2a2dc0);
    M2C_FIELD(arg0, s128 *, 0x1D0) = spB0;
    M2C_FIELD(arg0, s128 *, 0x1B0) = sp90;
    M2C_FIELD(arg0, s128 *, 0x1C0) = spA0;
    SmoothMatrix(PmatLoWorld(arg0, sp90), temp_s5, &D_002BE920, 0, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x120), sp90);
    PosSmooth(sp220, sp230, &D_002BE930, &spA0, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x230($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x1b0($s1) */);
    do {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        var_s4_2 -= 1;
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($a0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf5, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
    } while (var_s4_2 >= 0);
    func_001856B8(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0);
    func_001856C0(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0, 3, sp250, 0x41200000);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x150);
    if (M2C_FIELD(temp_v0_2, f32 *, 0x1C) > 0.0f) {
        spB0 = 0.0f;
        unkspB8 = M2C_FIELD(temp_v0_2, M2C_UNK32 *, 0x14);
        unkspB4 = -M2C_FIELD(temp_v0_2, f32 *, 0x10);
        InvertMatrix3(&sp1C0, temp_s5);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1d0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1e0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x1c0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf7x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf7y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf7, $vf2, $vf7z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf2, $vf6z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf4z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x190($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf7, $vf1z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x1a0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
        spB0 = 0.0f;
        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x1b0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x1f0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x200($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x210($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc0($sp) */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        } else {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        }
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1e40($s1) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1e60($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc0($sp) */);
    } else {
        temp_v0_3 = arg0 + 0x190;
        M2C_FIELD(temp_v0_3, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_v0_3, f32 *, 8) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x190) = 0.0f;
    }
    if (spD0 > 0) {
        sp240 = 0xBF800000;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x1b0($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($s5) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s5) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf1z */);
        spB0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        func_00185A80(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf5 */));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x260($sp) */);
        InvertMatrix3(&sp190, temp_s5);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x240($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x260($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x190($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf6x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1a0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1b0($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf2z */);
        spB0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf6 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s1) */);
    var_v1 = 0;
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    if ((M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */) > 1.0f) || (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C) != 0.0f)) {
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        SetJtState(arg0, 0x15, 0xB);
        SolvePlainBlendWeights(arg0, arg0 + 0x1E10, M2C_FIELD(arg0, void **, 0x1F10));
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf5x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s5) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($s5) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xb0($sp) */);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
        return;
    }
    SetJtState(arg0, 0x15, 0xA);
    temp_v0_4 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x118), spA0);
}
