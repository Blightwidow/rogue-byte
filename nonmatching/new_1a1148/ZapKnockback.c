#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32); /* extern */
M2C_UNK PmatLoWorld(void *);                        /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK SetJtZapState(void *, M2C_UNK);             /* extern */
s128 bevy_camera_follow_track_heading_weight(void *, void *, s128); /* extern */
extern s128 D_002BFAE0;
extern s128 D_002BFAF0;
extern f32 D_FLT_002BFAD4;

void ZapKnockback(void *arg0) {
    M2C_UNK unksp18;
    M2C_UNK unksp8;
    s128 sp0;
    s128 sp10;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 *var_v0;
    s32 temp_a0;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v1;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x3C);
    sp0 = M2C_FIELD(arg0, s128 *, 0x60);
    switch (temp_a0) {                              /* irregular */
    case 0x40:
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x30), 0x36) != 0) {
            temp_s0 = M2C_FIELD(arg0, void **, 0x30);
            sp30 = PosLoWorld(M2C_FIELD(arg0, void **, 0));
            sp40 = PosLoWorld(temp_s0);
            sp50 = 0xC3160000;
            sp10 = 0xC3160000;
            PmatLoWorld(temp_s0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
            bevy_camera_follow_track_heading_weight(NULL, temp_s0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
            if (M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */) > 0.0f) {
                var_v0 = &D_002BFAE0;
            } else {
                var_v0 = &D_002BFAF0;
            }
            sp0 = bevy_camera_follow_track_heading_weight(temp_s0, NULL, *var_v0);
        }
        break;
    case 0x200:
    case 0x8000:
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x30), 0x33) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            sp0 = LimitVectorLength__FP6VECTORfT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), D_FLT_002BFAD4);
            unksp8 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f1 */);
        }
        break;
    case 0x100:
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x30), 0x4F) != 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0x30);
            if (FIsBasicDerivedFrom(temp_s0_2, 0x51) != 0) {
                temp_v1 = M2C_FIELD(temp_s0_2, void **, 0xC);
                sp10 = *M2C_FIELD(temp_v1, s128 *(**)(void *), 0xFC)(temp_s0_2 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            } else {
                sp60 = PosLoWorld(M2C_FIELD(arg0, void **, 0));
                PosLoWorld(temp_s0_2);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            }
            unksp18 = 0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f)) {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf3, $q */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf4, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        }
        break;
    }
    temp_a2 = M2C_FIELD(arg0, void **, 0);
    temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x118), sp0, temp_a2);
    SetJtZapState(arg0, 7);
}
