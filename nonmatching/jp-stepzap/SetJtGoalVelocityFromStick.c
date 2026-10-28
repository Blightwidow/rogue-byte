#include "m2c_macros.h"

M2C_UNK PmatLoWorld(void *);                        /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
s128 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK func_002046F0(void *, void *);              /* extern */
extern f32 g_2bf9f0;

void SetJtGoalVelocityFromStick(void *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    M2C_UNK unksp4;
    s128 sp0;
    s32 temp_v1_3;
    s32 var_v1;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *var_a1;

    if (arg2 != 0) {
        var_a1 = M2C_FIELD(arg0, void **, 0x10DC);
        if (var_a1 != NULL) {
            if (M2C_FIELD(arg0, s32 *, 0x10E4) == 3) {
                var_a1 = M2C_FIELD(var_a1, void **, 0x494);
            }
            func_002046F0(arg0, var_a1);
        }
        sp0 = SetVectorCylind__FP6VECTORfff(RadNormalize__Ff(fparg0 - M2C_FIELD(arg0, f32 *, 0x1A8)), fparg1, 0);
        if (!(g_2bf9f0 < unksp4)) {
            if (unksp4 < -g_2bf9f0) {
                if (M2C_FIELD(arg0, s32 *, 0x1038) != 1) {
                    var_v1 = 0;
                } else {
                    unksp4 = 0.0f;
                    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                    PmatLoWorld(arg0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
                    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
                    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
                    var_v1 = 0;
                }
            } else {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x1038);
                var_v1 = (~temp_v1_3 == 0) ? 0 : temp_v1_3;
            }
        } else if (M2C_FIELD(arg0, s32 *, 0x1038) != 0) {
            var_v1 = 1;
        } else {
            unksp4 = 0.0f;
            temp_v1_4 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x108));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
            PmatLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
            temp_v1_5 = M2C_FIELD(arg0, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
            M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
            var_v1 = 1;
        }
        if (var_v1 == 1) {
            M2C_ERROR(/* unknown instruction: min.s $f2, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xb0($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf1, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf4, $vf6x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x190($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
        } else {
            M2C_ERROR(/* unknown instruction: min.s $f3, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($s1) */);
            M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf1, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf5x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
        }
        M2C_FIELD(arg0, s32 *, 0x198) = 0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        M2C_FIELD(arg0, s32 *, 0x1038) = var_v1;
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    }
}
