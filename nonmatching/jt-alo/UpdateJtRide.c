#include "m2c_macros.h"

s32 PmatLoWorld(void *, s128, s128, s128, s128, s128, s128, s128); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK PosSmooth(M2C_UNK, s128, M2C_UNK *, s128 *, f32); /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
M2C_UNK SmoothMatrix(s32, void *, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK bevy_camera_follow_track_heading_weight(M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK D_002BF3F8;
extern M2C_UNK D_002BF408;
extern M2C_UNK g_2dded0;

void UpdateJtRide(void *arg0) {
    M2C_UNK sp80;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f4;
    s128 temp_a1_2;
    s128 temp_a2;
    s128 temp_a3;
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;

    temp_a1 = M2C_FIELD(arg0, void **, 0x18C4);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, void *(**)(void *, void *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1);
    temp_a2 = M2C_FIELD(temp_v0, s128 *, 0);
    temp_a3 = M2C_FIELD(temp_v0, s128 *, 0x10);
    temp_a1_2 = M2C_FIELD(temp_v0, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x1B0) = temp_a2;
    M2C_FIELD(arg0, s128 *, 0x1C0) = temp_a3;
    M2C_FIELD(arg0, s128 *, 0x1D0) = temp_a1_2;
    SmoothMatrix(PmatLoWorld(arg0, temp_a1_2, temp_a2, temp_a3, temp_a2, temp_a3, temp_a1_2, M2C_FIELD(temp_v0, s128 *, 0x30)), arg0 + 0x1B0, &D_002BF3F8, 0, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x120), sp40);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
    sp70 = 0xBF800000;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1fa0($s1) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
    sp60 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x80($sp) */);
    PosLoWorld(arg0);
    PosSmooth(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), sp80, &D_002BF408, &sp50, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), sp50);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $a1, $v1 */);
    M2C_ERROR(/* unknown instruction: pcpyld $v1, $a1, $v1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf3, $vf4z */);
    sp60 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
    bevy_camera_follow_track_heading_weight(0, M2C_FIELD(arg0, void **, 0x18C4), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf4x */);
    sp60 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f)) {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f4 = M2C_ERROR(/* unknown instruction: max.s $f4, $f0, $f2 */);
    M2C_FIELD(arg0, f32 *, 0x1F94) = (f32) M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */);
    temp_f1 = M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f2 */);
    temp_f0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C);
    M2C_FIELD(arg0, f32 *, 0x1F98) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x1F6C) = (f32) (temp_f1 * temp_f0);
    M2C_FIELD(arg0, f32 *, 0x1F60) = (f32) (1.0f - temp_f0);
    M2C_FIELD(arg0, f32 *, 0x1F84) = (f32) (temp_f4 * temp_f0);
    M2C_FIELD(arg0, f32 *, 0x1F78) = (f32) (((1.0f - temp_f4) - temp_f1) * temp_f0);
    ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0x1F90));
}
