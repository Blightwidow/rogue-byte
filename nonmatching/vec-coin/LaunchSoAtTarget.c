#include "m2c_macros.h"

M2C_UNK FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(); /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
f32 GRandInRange();                 /* extern */
M2C_UNK GetSoDvGravity();                     /* extern */
M2C_UNK InferExpl();                  /* extern */
M2C_UNK LoadLookAtMatrix();             /* extern */
s128 PosLoWorld();                            /* extern */
M2C_UNK PredictXfTransform(); /* extern */
M2C_UNK RecalcSwOxfFilterForObject(); /* extern */
M2C_UNK SetSoCnstrForce();           /* extern */
M2C_UNK SetSoCnstrTorque();          /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(); /* extern */
M2C_UNK func_001A58D0();    /* extern */
M2C_UNK func_001F4898();             /* extern */
M2C_UNK memset();           /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C44F0;

void LaunchSoAtTarget(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp100;
    M2C_UNK spF0;
    s128 sp40;
    s128 sp80;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    M2C_UNK *var_s2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_v0_3;
    f32 temp_v1_2;
    f32 var_f12;
    s128 temp_v0;
    void *temp_a2;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_v0 = PosLoWorld(arg1);
    spC0 = temp_v0;
    temp_a2 = M2C_FIELD(arg0, void **, 0x60);
    spD0 = temp_v0;
    if (temp_a2 != NULL) {
        temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
        var_s2 = M2C_FIELD(temp_v1, M2C_UNK *(**)(void *, void *, void *), 0x104)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x100), sp, temp_a2);
    } else {
        var_s2 = &D_002C44F0;
        memset(sp, 0, 0x40);
    }
    __ml__FRC7MATRIX4T0(&sp40, var_s2 + 0x40, sp);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
    temp_v0_2 = arg0 + 0x70;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_f4 = M2C_FIELD(arg0, f32 *, 0x80);
    temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f5 = M2C_FIELD(arg0, f32 *, 0x84);
    var_f12 = M2C_FIELD(arg0, f32 *, 0x70) + (temp_v0_3 * (M2C_FIELD(temp_v0_2, f32 *, 4) + (temp_v0_3 * M2C_FIELD(temp_v0_2, f32 *, 8))));
    if (var_f12 < temp_f4) {
        var_f12 = temp_f4;
    } else if (temp_f5 < var_f12) {
        var_f12 = temp_f5;
    }
    if (var_f12 != 0.0f) {
        PredictXfTransform(var_s2, 0, &sp40, 0, var_f12);
        __ml__FRC7MATRIX4T0(&sp80, &sp40, sp);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    }
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_v0_4 = arg0 + 0x90;
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v1_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x90) + (temp_v1_2 * (M2C_FIELD(temp_v0_4, f32 *, 4) + (temp_v1_2 * M2C_FIELD(temp_v0_4, f32 *, 8))));
    if (temp_f0 < M2C_FIELD(arg0, f32 *, 0xA0)) {

    } else if (M2C_FIELD(arg0, f32 *, 0xA4) < temp_f0) {

    }
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xf0($sp) */);
    spE0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
    if (FIsBasicDerivedFrom(arg1, 0x4F) != 0) {
        InferExpl(arg1, arg0);
        RecalcSwOxfFilterForObject(&B_003DD490, arg1);
    }
    temp_v0_5 = M2C_FIELD(arg1, void **, 0xC);
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *), 0x44)(arg1 + M2C_FIELD(temp_v0_5, s16 *, 0x40));
    SetSoCnstrForce(arg1, 0);
    SetSoCnstrTorque(arg1, 0);
    func_001A58D0(arg1, 0, 3);
    if (FIsBasicDerivedFrom(arg1, 0x52) != 0) {
        M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
        sp40 = M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        func_001F4898(arg1, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    } else {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($sp) */);
        if (FIsBasicDerivedFrom(arg1, 0x51) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            }
            temp_v1_3 = M2C_FIELD(arg1, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x100($sp) */);
            M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, s128), 0x11C)(arg1 + M2C_FIELD(temp_v1_3, s16 *, 0x118), sp100);
            LoadLookAtMatrix(&sp40, sp100);
            temp_v0_6 = M2C_FIELD(arg1, void **, 0xC);
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, s128 *), 0xF4)(arg1 + M2C_FIELD(temp_v0_6, s16 *, 0xF0), &sp40);
        } else {
            GetSoDvGravity(arg1);
            FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(spC0, spF0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, f32 *, 0xB0));
            temp_v1_4 = M2C_FIELD(arg1, void **, 0xC);
            M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, s128), 0x11C)(arg1 + M2C_FIELD(temp_v1_4, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        }
    }
    temp_f1 = M2C_FIELD(arg0, f32 *, 0xAC);
    if (temp_f1 > 0.0f) {
        temp_f24 = GRandInRange(arg1, M2C_FIELD(arg0, f32 *, 0xA8), temp_f1);
        temp_f23 = GRandInRange((void *)0xBF800000, 1.0f);
        temp_f20 = GRandInRange((void *)0xBF800000, 1.0f);
        GRandInRange((void *)0xBF800000, 1.0f);
        M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
        M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        sp40 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f)) {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
        }
        temp_v1_5 = M2C_FIELD(arg1, void **, 0xC);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
        M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, M2C_UNK), 0x124)(arg1 + M2C_FIELD(temp_v1_5, s16 *, 0x120), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    }
    if (FIsBasicDerivedFrom(arg1, 0x50) != 0) {
        temp_v1_6 = M2C_FIELD(arg1, void **, 0xC);
        sp40 = M2C_FIELD(arg0, s128 *, 0x50);
        M2C_FIELD(temp_v1_6, M2C_UNK (**)(void *, void *, s128 *), 0x274)(arg1 + M2C_FIELD(temp_v1_6, s16 *, 0x270), M2C_FIELD(arg0, void **, 0x60), &sp40);
    }
}
