#include "m2c_macros.h"

M2C_UNK BuildXfAngularRateMatrix(); /* extern */
M2C_UNK BuildXfLinearRateMatrix(); /* extern */
M2C_UNK BuildXfLocalMatrix();   /* extern */
M2C_UNK BuildXfSpinRateMatrix(); /* extern */
s32 FXfKindHasVelocity();                /* extern */
M2C_UNK GetXfDofValue();              /* extern */
M2C_UNK LoadRotateMatrix();          /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();     /* extern */
M2C_UNK memset();           /* extern */

void PredictXfLocal(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp60;
    s128 var_a0;
    s128 var_a1;
    s128 var_v0;
    s128 var_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    void *temp_a3;
    void *temp_v1;

    temp_a3 = M2C_FIELD(arg0, void **, 0x90);
    if (temp_a3 != NULL) {
        temp_v1 = M2C_FIELD(temp_a3, void **, 0x18);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *, s128 *, void *), 0x2C)(temp_a3 + M2C_FIELD(temp_v1, s16 *, 0x28), sp, &sp10, temp_a3);
        BuildXfLocalMatrix(&sp20, arg0, sp0);
        M2C_FIELD(arg1, s128 *, 0) = sp20;
        M2C_FIELD(arg1, s128 *, 0x10) = sp30;
        M2C_FIELD(arg1, s128 *, 0x20) = sp40;
        M2C_FIELD(arg1, s128 *, 0x30) = sp50;
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x94);
        if (temp_v1_2 < 8) {
            if (temp_v1_2 >= 6) {
                BuildXfAngularRateMatrix(&sp20, arg0, arg1, sp0);
                var_v1 = sp20;
                var_a0 = sp30;
                var_a1 = sp40;
                var_v0 = sp50;
            } else {
                goto block_5;
            }
        } else {
block_5:
            BuildXfLinearRateMatrix(&sp20, arg0, sp10);
            var_v1 = sp20;
            var_a0 = sp30;
            var_a1 = sp40;
            var_v0 = sp50;
        }
        goto block_14;
    }
    if (FXfKindHasVelocity(M2C_FIELD(arg0, s16 *, 0x98), temp_a3) == 0) {
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
        M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
        M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x30);
        memset(arg2, 0, 0x40);
        return;
    }
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x94);
    if (temp_v1_3 < 8) {
        if (temp_v1_3 >= 6) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s1) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
            LoadRotateMatrix(&sp60, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf5z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf6z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
            __as__6VECTORG9VU_VECTOR(arg1 + 0x30, M2C_FIELD(arg0, s128 *, 0x30));
            M2C_FIELD(arg1, s128 *, 0x10) = sp10;
            M2C_FIELD(arg1, s128 *, 0x20) = sp20;
            M2C_FIELD(arg1, s128 *, 0) = sp0;
            M2C_FIELD(arg1, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(arg1, s32 *, 0x2C) = 0;
            M2C_FIELD(arg1, s32 *, 0x1C) = 0;
            M2C_FIELD(arg1, s32 *, 0xC) = 0;
            BuildXfSpinRateMatrix(&sp30, arg0, arg1, M2C_FIELD(arg0, s128 *, 0xB0));
            var_v1 = sp30;
            var_a0 = sp40;
            var_a1 = sp50;
            var_v0 = sp60;
        } else {
            goto block_13;
        }
    } else {
block_13:
        GetXfDofValue(arg0, arg0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s1) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        BuildXfLocalMatrix(&sp10, arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
        M2C_FIELD(arg1, s128 *, 0x30) = sp40;
        M2C_FIELD(arg1, s128 *, 0x20) = sp30;
        M2C_FIELD(arg1, s128 *, 0) = sp10;
        M2C_FIELD(arg1, s128 *, 0x10) = sp20;
        BuildXfLinearRateMatrix(&sp10, arg0, M2C_FIELD(arg0, s128 *, 0xB0), sp20);
        var_v1 = sp10;
        var_a0 = sp20;
        var_a1 = sp30;
        var_v0 = sp40;
    }
block_14:
    M2C_FIELD(arg2, s128 *, 0) = var_v1;
    M2C_FIELD(arg2, s128 *, 0x30) = var_v0;
    M2C_FIELD(arg2, s128 *, 0x10) = var_a0;
    M2C_FIELD(arg2, s128 *, 0x20) = var_a1;
}
