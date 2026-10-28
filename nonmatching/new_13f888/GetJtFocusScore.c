#include "m2c_macros.h"

s128 PosLoWorld();                         /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(); /* extern */
extern M2C_UNK D_FLT_002BD280;
extern M2C_UNK D_FLT_002BD290;
extern M2C_UNK D_FLT_002BD2A0;
extern M2C_UNK D_FLT_002BD2B0;
extern M2C_UNK g_2bbb60;

void GetJtFocusScore(void *arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    f32 *temp_s4;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_v1;
    f32 temp_v1_2;
    f32 var_f22;
    f32 var_f23;
    f32 var_f3;
    void *temp_a0;

    temp_s4 = M2C_ERROR(/* Read from unset register $t0 */);
    var_f23 = 0.0f;
    PosLoWorld(arg1, PosLoWorld());
    var_f22 = 0.0f;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf2, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    temp_v1 = M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v1 */);
    temp_v1_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
    if (arg0 == *arg2) {
        var_f22 = M2C_FIELD(&D_FLT_002BD280, f32 *, 0) + (temp_v1_2 * (M2C_FIELD(&D_FLT_002BD280, f32 *, 4) + (temp_v1_2 * M2C_FIELD(&D_FLT_002BD280, f32 *, 8))));
        var_f23 = M2C_FIELD(&D_FLT_002BD290, f32 *, 0) + (temp_v1 * (M2C_FIELD(&D_FLT_002BD290, f32 *, 4) + (temp_v1 * M2C_FIELD(&D_FLT_002BD290, f32 *, 8))));
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x150);
    if ((temp_a0 != NULL) && (temp_v1_2 > 0.0001f)) {
        SetVectorCylind__FP6VECTORfff(temp_a0, M2C_FIELD(temp_a0, f32 *, 0x18), M2C_FIELD(temp_a0, f32 *, 0x1C), 0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        temp_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / temp_v1_2;
        temp_f2 = M2C_FIELD(&D_FLT_002BD2A0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002BD2A0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002BD2A0, f32 *, 8))));
        if (temp_f2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f3 = temp_f2;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f2) {
                var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        var_f22 += var_f3 * (M2C_FIELD(&D_FLT_002BD2B0, f32 *, 0) + (temp_v1_2 * (M2C_FIELD(&D_FLT_002BD2B0, f32 *, 4) + (temp_v1_2 * M2C_FIELD(&D_FLT_002BD2B0, f32 *, 8)))));
    }
    if (arg3 != NULL) {
        *arg3 = temp_v1_2 + var_f22;
    }
    if (temp_s4 != NULL) {
        *temp_s4 = temp_v1 + var_f23;
    }
}
