#include "m2c_macros.h"

M2C_UNK CalculateVectorPanTilt__FP6VECTORPfT1(M2C_UNK, f32 *, f32 *); /* extern */
M2C_UNK ConvertXfVec(M2C_UNK, s32, s128);           /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK ResortXfActList(s32, void *);               /* extern */
s32 func_001C4AF8(M2C_UNK *, s128);                 /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;

void GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR(void *arg0) {
    M2C_UNK sp40;
    M2C_UNK unksp4;
    M2C_UNK unksp8;
    s128 sp0;                                       /* compiler-managed */
    s128 sp10;
    f32 sp30;
    f32 sp34;
    s128 sp50;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 var_f20;
    f32 var_f3;
    f32 var_f3_2;
    s128 temp_a1;
    s32 temp_a2;
    s32 var_a0;
    s32 var_v1;
    void *temp_a1_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    if (M2C_FIELD(arg0, s32 *, 0x70) == 0) {
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x6C);
        if (temp_a2 != -1) {
            M2C_FIELD(arg0, s32 *, 0x70) = PloFindSwObject_thunk(&B_003DD490, 0x104, temp_a2, M2C_FIELD(arg0, s32 *, 4));
        }
    }
    var_a0 = M2C_FIELD(arg0, s32 *, 0x70);
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0x70);
    sp50 = temp_a1;
    if ((var_a0 != 0) || (var_a0 = func_001C4AF8(&B_003DD490, temp_a1), (var_a0 != 0))) {
        PosLoWorld(var_a0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        var_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    } else {
        var_f20 = 3.4028235e38f;
    }
    if (!(M2C_FIELD(arg0, f32 *, 0x60) < var_f20)) {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x64);
    } else {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x68);
    }
    if (var_v1 == M2C_FIELD(arg0, s32 *, 0xC)) {
        goto block_18;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = var_v1;
    ResortXfActList(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, void **, 8));
    temp_a1_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0x90);
    if (temp_a1_2 == arg0) {
block_18:
        if (M2C_FIELD(arg0, f32 *, 0x60) < var_f20) {
            sp0 = M2C_FIELD(arg0, s128 *, 0x20);
            sp10 = g_2a2dd0;
            M2C_FIELD(arg0, s32 *, 0x74) = 0;
        } else {
            ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xA0), sp40);
            CalculateVectorPanTilt__FP6VECTORPfT1(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), &sp30, &sp34);
            temp_v0 = arg0 + 0x30;
            temp_f4 = M2C_FIELD(arg0, f32 *, 0x50);
            var_f3 = M2C_FIELD(arg0, f32 *, 0x30) + (sp30 * (M2C_FIELD(temp_v0, f32 *, 4) + (sp30 * M2C_FIELD(temp_v0, f32 *, 8))));
            temp_f5 = M2C_FIELD(arg0, f32 *, 0x54);
            if (var_f3 < temp_f4) {
                var_f3 = temp_f4;
            } else if (temp_f5 < var_f3) {
                var_f3 = temp_f5;
            }
            sp30 = var_f3;
            temp_v0_2 = arg0 + 0x40;
            temp_f4_2 = M2C_FIELD(arg0, f32 *, 0x58);
            temp_f0 = M2C_FIELD(arg0, f32 *, 0x40) + (sp34 * (M2C_FIELD(temp_v0_2, f32 *, 4) + (sp34 * M2C_FIELD(temp_v0_2, f32 *, 8))));
            temp_f5_2 = M2C_FIELD(arg0, f32 *, 0x5C);
            if (temp_f0 < temp_f4_2) {
                var_f3_2 = temp_f4_2;
            } else {
                var_f3_2 = temp_f0;
                if (temp_f5_2 < temp_f0) {
                    var_f3_2 = temp_f5_2;
                }
            }
            unksp8 = sp30;
            unksp4 = -var_f3_2;
            sp34 = var_f3_2;
            sp0 = 0;
            if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($v1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
            } else {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            }
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_FIELD(arg0, s32 *, 0x74) = 1;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xC0) = (s128) sp0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xD0) = sp10;
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 0x9A) = 3;
        return;
    }
    temp_v0_3 = M2C_FIELD(temp_a1_2, void **, 0x18);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x24)(temp_a1_2 + M2C_FIELD(temp_v0_3, s16 *, 0x20), temp_a1_2);
}
