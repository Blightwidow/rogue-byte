#include "m2c_macros.h"

f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(M2C_UNK *, M2C_UNK *, M2C_UNK *, f32, f32, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_track_heading_weight(M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK func_002046F0(void *, s32);                 /* extern */
M2C_UNK func_00204E38(void *, f32);                 /* extern */
extern M2C_UNK D_FLT_002C0A20;
extern M2C_UNK g_2bbb60;

void MoveMurrayAttack(void *arg0) {
    f32 *temp_s0;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f4_2;
    s32 temp_a1_2;
    void *temp_a1;
    void *temp_v0;

    temp_a1 = M2C_FIELD(arg0, void **, 0x1030);
    if (temp_a1 != NULL) {
        func_00204E38(temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
        if (M2C_FIELD(arg0, s32 *, 0x1818) != 0) {
            temp_s0 = PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), s32 *, 0x14), 0x240);
            temp_f4 = *temp_s0;
            temp_f0 = (M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x1C) - temp_f4) / (*PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), s32 *, 0x14), 0x242) - temp_f4);
            temp_f4_2 = M2C_FIELD(&D_FLT_002C0A20, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C0A20, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C0A20, f32 *, 8))));
            if (temp_f4_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {

            } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f4_2) {

            }
            temp_v0 = M2C_FIELD(arg0, void **, 0x150);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1700($s1) */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            SetVectorCylind__FP6VECTORfff(&D_FLT_002C0A20, &g_2bbb60, &D_FLT_002C0A20, M2C_FIELD(temp_v0, f32 *, 0x18), M2C_FIELD(temp_v0, f32 *, 0x1C) * M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */), 0);
            bevy_camera_follow_track_heading_weight(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf4, $vf5x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
        }
    }
    temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x10DC);
    if (temp_a1_2 != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x10E4) == 4) {
            func_002046F0(arg0, temp_a1_2);
        }
    }
}
