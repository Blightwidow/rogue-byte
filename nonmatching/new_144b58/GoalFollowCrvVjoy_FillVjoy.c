#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK Goal_FillVjoy();                            /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK UpdateVjoyPressTimes(void *, void *, s32);  /* extern */
f32 atan2f(M2C_UNK *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_FLT_002BD2E0;
extern f32 D_FLT_002BD2F0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;

void GoalFollowCrvVjoy_FillVjoy(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_v1_2;
    f32 var_f3;
    s32 temp_a2;
    s32 temp_v1;
    s32 var_s3;
    s32 var_v0;
    void *temp_a1;
    void *temp_s1;
    void *temp_v1_3;
    void *temp_v1_4;

    Goal_FillVjoy();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C);
    if ((temp_v1 < 2) && (temp_v1 >= 0)) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v1_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
        temp_f0 = M2C_FIELD(&D_FLT_002BD2E0, f32 *, 0) + (temp_v1_2 * (M2C_FIELD(&D_FLT_002BD2E0, f32 *, 4) + (temp_v1_2 * M2C_FIELD(&D_FLT_002BD2E0, f32 *, 8))));
        if (temp_f0 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f3 = temp_f0;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0) {
                var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        if (var_f3 > 0.0f) {
            M2C_FIELD(arg1, f32 *, 0x1C) = (f32) (var_f3 * M2C_FIELD(arg0, f32 *, 0xD0));
            M2C_FIELD(arg1, f32 *, 0x18) = atan2f(&D_FLT_002BD2E0, M2C_ERROR(/* unknown instruction: prot3w $v0, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */));
        }
        if (M2C_FIELD(arg0, s32 *, 0xCC) != 0) {
            M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | 8);
        }
        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC0);
        if (temp_v1_3 != NULL) {
            var_s3 = 1;
            if (M2C_FIELD(arg0, f32 *, 0xC8) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x50))) {
                temp_s1 = M2C_FIELD(temp_v1_3, void **, 0x7C);
                PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                PosLoWorld(temp_s1);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(D_FLT_002BD2F0 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                    var_v0 = 0;
                }
                if (var_v0 != 0) {
                    M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | 8);
                }
                if (FIsBasicDerivedFrom(temp_s1, 0x34) != 0) {
                    temp_v1_4 = M2C_FIELD(temp_s1, void **, 0xC);
                    var_s3 = M2C_FIELD(temp_v1_4, s32 (**)(void *), 0x2CC)(temp_s1 + M2C_FIELD(temp_v1_4, s16 *, 0x2C8)) != 0;
                }
                if (var_s3 != 0) {
                    temp_a1 = M2C_FIELD(arg0, void **, 0xC0);
                    temp_a2 = M2C_FIELD(arg0, s32 *, 0xC4);
                    M2C_FIELD(arg1, s32 *, 0x30) = (s32) (M2C_FIELD(arg1, s32 *, 0x30) | (M2C_FIELD(temp_a1, s32 *, 0x30) & temp_a2));
                    UpdateVjoyPressTimes(arg1, temp_a1, temp_a2);
                }
            }
        }
    }
}
