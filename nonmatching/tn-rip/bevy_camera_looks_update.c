#include "m2c_macros.h"

f32 GRandInRange();              /* extern */
M2C_UNK SetCmPosMat();                /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK func_0012D108();                /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_FLT_002BDA10;
extern M2C_UNK D_FLT_002BDA20;
extern M2C_UNK D_FLT_002BDA30;
extern M2C_UNK D_FLT_002BDA40;
extern M2C_UNK D_FLT_002BDA48;
extern M2C_UNK D_FLT_002BDA50;
extern M2C_UNK D_FLT_002BDA58;
extern M2C_UNK g_2dded0;

void bevy_camera_looks_update(void *arg0, void *arg2) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    void *temp_v0;

    UpdateCplcy();
    if (!(M2C_FIELD(arg2, f32 *, 0x1078) > 0.0f)) {
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x4CC) != 9) {
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf0, $vf0 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf1 */);
        } else {
            if (M2C_FIELD(arg0, f32 *, 0x18) < M2C_FIELD(&g_2dded0, f32 *, 0)) {
                temp_f20 = GRandInRange((M2C_UNK *)9, M2C_FIELD(&D_FLT_002BDA48, f32 *, 0), M2C_FIELD(&D_FLT_002BDA48, f32 *, 4));
                temp_f0 = GRandInRange(M2C_FIELD(&D_FLT_002BDA50, M2C_UNK **, 0), M2C_FIELD(&D_FLT_002BDA50, f32 *, 4));
                M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
                temp_v0 = arg0 + 0x20;
                M2C_FIELD(temp_v0, f32 *, 8) = temp_f0;
                M2C_FIELD(temp_v0, f32 *, 4) = temp_f20;
                temp_f20_2 = M2C_FIELD(&g_2dded0, f32 *, 0);
                M2C_FIELD(arg0, f32 *, 0x18) = (f32) (temp_f20_2 + GRandInRange(&D_FLT_002BDA58, M2C_FIELD(&D_FLT_002BDA58, f32 *, 0), M2C_FIELD(&D_FLT_002BDA58, f32 *, 4)));
            }
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf5x */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf3, $vf6x */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf2, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf1x */);
        }
    } else {
        temp_f2 = M2C_FIELD(arg2, f32 *, 0x1070);
        temp_f0_2 = M2C_FIELD(arg2, f32 *, 0x1074);
        if (temp_f2 > 0.0f) {

        }
        if (temp_f0_2 > 0.0f) {

        }
        temp_f2_2 = fabsf(temp_f2);
        temp_f2_3 = M2C_FIELD(&D_FLT_002BDA10, f32 *, 0) + (temp_f2_2 * (M2C_FIELD(&D_FLT_002BDA10, f32 *, 4) + (temp_f2_2 * M2C_FIELD(&D_FLT_002BDA10, f32 *, 8))));
        if (!(temp_f2_3 < M2C_FIELD(&D_FLT_002BDA20, f32 *, 0)) && (M2C_FIELD(&D_FLT_002BDA20, f32 *, 4) < temp_f2_3)) {

        }
        temp_f2_4 = fabsf(temp_f0_2);
        temp_f0_3 = M2C_FIELD(&D_FLT_002BDA30, f32 *, 0) + (temp_f2_4 * (M2C_FIELD(&D_FLT_002BDA30, f32 *, 4) + (temp_f2_4 * M2C_FIELD(&D_FLT_002BDA30, f32 *, 8))));
        if (temp_f0_3 < M2C_FIELD(&D_FLT_002BDA40, f32 *, 0)) {

        } else if (M2C_FIELD(&D_FLT_002BDA40, f32 *, 4) < temp_f0_3) {

        }
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf0, $vf0 */);
        M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    func_0012D108(M2C_FIELD(arg0, s32 *, 0x14), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($s1) */);
    SetCmPosMat(&B_002DDF40, M2C_FIELD(arg0, s32 *, 0x10) + 0x40);
}
