#include "m2c_macros.h"

M2C_UNK GoalFollowCrv_Update();                     /* extern */
M2C_UNK PmatLoWorld(s32, f32);                      /* extern */
s128 PosLoWorld(s32);                               /* extern */
M2C_UNK SetAsegaSpeed(void *, f32);                 /* extern */
M2C_UNK SetDirAnimDirection(void *, M2C_UNK);       /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
M2C_UNK func_00209818(s32, f32);                    /* extern */
extern M2C_UNK D_FLT_002BE6A0;
extern f32 D_FLT_002BE6B0;
extern M2C_UNK g_2bbb60;
extern f32 g_2be694;
extern f32 g_2dded4;

void GoalFollowCrvAnim_Update(void *arg0) {
    s128 sp10;
    f32 temp_f12;
    f32 temp_v0;
    f32 var_f0;
    f32 var_f20;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 var_v0;
    void *temp_s0;

    GoalFollowCrv_Update();
    if ((u32) M2C_FIELD(arg0, u32 *, 0x4C) < 2U) {
        sp10 = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($s1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf4, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        temp_f12 = M2C_FIELD(&D_FLT_002BE6A0, f32 *, 0) + (temp_v0 * (M2C_FIELD(&D_FLT_002BE6A0, f32 *, 4) + (temp_v0 * M2C_FIELD(&D_FLT_002BE6A0, f32 *, 8))));
        if (temp_f12 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f20 = temp_f12;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f12) {
                var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), void **, 0x40);
        temp_v1 = M2C_FIELD(temp_s0, s32 *, 0);
        switch (temp_v1) {                          /* irregular */
        case 3:
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
            PmatLoWorld(M2C_FIELD(arg0, s32 *, 0x10), temp_f12);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf2, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf7, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf9, $vf3, $vf4 */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf6, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf8, $vf7, $vf6z */);
            M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf5, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmaddz.y $vf8, $vf7, $vf5z */);
            M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf9, $vf9x */);
            M2C_ERROR(/* unknown instruction: vmaddy.z $vf8, $vf7, $vf9y */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a0) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf8, $vf8 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf3, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */) < 0.0001f) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf8, $q */);
            }
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
            SetDirAnimDirection(M2C_FIELD(temp_s0, void **, 8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
            SetAsegaSpeed(M2C_FIELD(M2C_FIELD(temp_s0, void **, 8), void **, 0x24), var_f20);
            break;
        case 0:
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
            SetAsegaSpeed(M2C_FIELD(temp_s0, void **, 8), M2C_FIELD(arg0, f32 *, 0xC4) * var_f20);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0;
            func_00209818(temp_s0_2, atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf4 */)));
            break;
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xd0($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf9, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf9, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        var_v0 = 1;
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(D_FLT_002BE6B0 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            var_f0 = g_2be694;
            M2C_FIELD(arg0, s128 *, 0xD0) = sp10;
        } else {
            var_f0 = M2C_FIELD(arg0, f32 *, 0xE0) - g_2dded4;
        }
        M2C_FIELD(arg0, f32 *, 0xE0) = var_f0;
    }
}
