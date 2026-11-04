#include "m2c_macros.h"

M2C_UNK EvaluateCrvFromU(s32, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK FindCrvClosestPointFromU(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32, s128); /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK SetSlotSoState(void *, M2C_UNK);            /* extern */
f32 UMaxCrv(s32);                                   /* extern */
f32 UMinCrv(s32);                                   /* extern */
f32 UWrapCrv(s32, f32);                             /* extern */

void SteerSlotSoAlongCrv(void *arg0) {
    M2C_UNK sp10;
    f32 temp_f20;
    s32 temp_v1;
    s32 var_s0;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x220);
    if (temp_v1 != 1) {
        var_s0 = 0;
        if (temp_v1 != 4) {

        } else {
            var_s0 = M2C_FIELD(arg0, s32 *, 0x170);
        }
    } else {
        var_s0 = M2C_FIELD(arg0, s32 *, 0x16C);
    }
    if (var_s0 != 0) {
        FindCrvClosestPointFromU(var_s0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, 0, M2C_FIELD(arg0, f32 *, 0x174), PosLoWorld(arg0));
        temp_f20 = UWrapCrv(var_s0, M2C_FIELD(arg0, f32 *, 0x174) + M2C_FIELD(arg0, f32 *, 0x178));
        if (!(temp_f20 < UMinCrv(var_s0))) {
            if (!(UMaxCrv(var_s0) < temp_f20)) {
                EvaluateCrvFromU(var_s0, &sp10, 0, temp_f20);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf1, $vf4 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f)) {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf4, $q */);
                }
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
            } else {
                goto block_10;
            }
        } else {
block_10:
            if (M2C_FIELD(arg0, s32 *, 0x220) == 1) {
                SetSlotSoState(arg0, 2);
            }
        }
    }
}
