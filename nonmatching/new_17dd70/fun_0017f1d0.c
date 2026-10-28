#include "m2c_macros.h"

M2C_UNK ApplyConstrLocal(void *, s32, M2C_UNK);     /* extern */
M2C_UNK LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */

s32 func_0017F1D0(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f3;
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (!(M2C_FIELD(arg1, s32 *, 0x44) & 8)) {
        return 0;
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x184) + M2C_FIELD(arg1, s32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x184) = temp_v0;
    if (temp_v0 <= 0) {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x294)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x290), 0);
    } else {
        temp_v0_3 = M2C_FIELD(arg0, void **, 0xE8);
        if (temp_v0_3 != NULL) {
            if (M2C_FIELD(temp_v0_3, s32 *, 0xC0) != 3) {
                PosLoWorld(arg0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
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
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                }
                temp_v1 = arg0 + 0x1A0;
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                temp_f0 = (f32) -M2C_FIELD(arg1, s32 *, 0x10);
                temp_f3 = M2C_FIELD(arg0, f32 *, 0x1A0) + (temp_f0 * (M2C_FIELD(temp_v1, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v1, f32 *, 8))));
                if (temp_f3 < M2C_FIELD(arg0, f32 *, 0x1B0)) {

                } else if (M2C_FIELD(arg0, f32 *, 0x1B4) < temp_f3) {

                }
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                LimitVectorLength__FP6VECTORfT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), M2C_FIELD(arg0, f32 *, 0x1B4));
                ApplyConstrLocal(M2C_FIELD(arg0, void **, 0xE8) + 0xB0, M2C_FIELD(arg0, s32 *, 0x58), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
                temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
            }
        }
    }
    return 1;
}
