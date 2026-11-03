#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(); /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
s32 FStgSwitchDone();                         /* extern */
s32 FSwHandsOff();                         /* extern */
f32 GRandInRange();                         /* extern */
s32 NRandInRange();                     /* extern */
s128 PosLoWorld();                      /* extern */
void *PpoSwFocusBase();                    /* extern */
f32 RadBetweenVectors__FP6VECTORN20(); /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(); /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(); /* extern */
f32 atan2f();                       /* extern */
M2C_UNK func_00208540();              /* extern */
extern M2C_UNK B_003DD490;
extern void *B_003E1450;
extern f32 g_2bd460;
extern M2C_UNK g_2bd468;
extern f32 g_2bd470;
extern f32 g_2bd474;
extern f32 g_2bd478;
extern f32 g_2bd47c;
extern f32 g_2dded0;

void func_0014A4D0(void *arg0) {
    char sp[0x400];
    M2C_UNK sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 var_f22;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    void **var_a0;
    void **var_a2_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_3;
    void *var_s1;

    temp_v0 = PpoSwFocusBase(&B_003DD490);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
    temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    sp50 = M2C_FIELD(temp_v1, s128 (**)(void *, s128), 0x10C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x108), PosLoWorld(M2C_FIELD(arg0, void **, 0x10), PosLoWorld(temp_v0)));
    var_v1 = 1;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (!(g_2bd460 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
    }
    temp_f20 = g_2dded0 - M2C_FIELD(arg0, f32 *, 0x48);
    if ((GRandInRange(M2C_FIELD(&g_2bd468, f32 *, 0), M2C_FIELD(&g_2bd468, f32 *, 4)) < temp_f20) && (FSwHandsOff(&B_003DD490) == 0)) {
        if ((FIsBasicDerivedFrom(temp_v0, 0x34) != 0) && (M2C_FIELD(temp_v0, s32 *, 0x2DC) == 0x11)) {
            temp_s0 = M2C_FIELD(temp_v0, void **, 0x258);
            PosLoWorld(temp_v0);
            temp_v1_2 = M2C_FIELD(temp_s0, s32 *, 0x90);
            var_a2 = temp_v1_2;
            if (temp_v1_2 > 0) {
                do {
                    if (M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $v0 */) < M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $v1 */)) {
                        M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
                    }
                    var_a2 -= 1;
                } while (var_a2 != 0);
            }
            goto block_40;
        }
        func_00208540(M2C_FIELD(arg0, void **, 0x10), temp_v0);
        return;
    }
    var_s1 = B_003E1450;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
    if (var_s1 != NULL) {
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
loop_17:
        if (FStgSwitchDone(var_s1) == 0) {
            temp_a0 = M2C_FIELD(var_s1, void **, 0xEC);
            sp60 = PosLoWorld(var_s1);
            var_f22 = g_2bd478;
            if (temp_a0 != NULL) {
                var_f22 = M2C_FIELD(temp_a0, f32 *, 0x30);
                sp60 = M2C_FIELD(temp_a0, s128 *, 0x20);
            }
            temp_v0_2 = CploFindSwObjectsByClass(&B_003DD490, 1, 0x12, var_s1);
            var_a1 = 0;
            if (temp_v0_2 > 0) {
                var_a3 = temp_v0_2;
                var_a2_2 = sp;
                var_a0 = sp;
                do {
                    temp_v1_3 = *var_a2_2;
                    var_a3 -= 1;
                    if (M2C_FIELD(temp_v1_3, s32 *, 0xE8) & 0x17E) {
                        *var_a0 = temp_v1_3;
                        var_a1 += 1;
                        var_a0 += 4;
                    }
                    var_a2_2 += 4;
                } while (var_a3 != 0);
            }
            if (var_a1 != 0) {
                temp_s0_2 = *(sp + (NRandInRange(0, var_a1 - 1) * 4));
                var_f22 = M2C_FIELD(temp_s0_2, f32 *, 0xEC);
                sp60 = PosLoWorld(temp_s0_2);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
            var_v0 = 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            if (!((g_2bd478 * g_2bd478) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                var_v0 = 0;
            }
            if (var_v0 == 0) {
                temp_f21 = GRandInRange(-3.1415927f, 3.1415927f);
                temp_f20_2 = GRandInRange(-3.1415927f, 3.1415927f);
                SetVectorSphere__FP6VECTORfff(temp_f21, temp_f20_2, GRandInRange(0.0f, var_f22));
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf4 */);
                var_v0_2 = 1;
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) {
                    var_v0_2 = 0;
                }
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
                if ((var_v0_2 == 0) && !(g_2bd47c < (fabsf(RadBetweenVectors__FP6VECTORN20(sp40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), 0)) * 57.295776f))) {
                    goto block_34;
                }
            } else {
                goto block_34;
            }
        } else {
block_34:
            var_s1 = M2C_FIELD(var_s1, void **, 0x174);
            if (var_s1 == NULL) {
                goto block_35;
            }
            goto loop_17;
        }
    } else {
block_35:
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
        var_v0_3 = 1;
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < g_2bd460)) {
            var_v0_3 = 0;
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        if (var_v0_3 != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            temp_f20_3 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */));
            sp70 = PosLoWorld(temp_v0);
            SetVectorCylind__FP6VECTORfff(GRandInRange(temp_f20_3 - 1.5707964f, temp_f20_3 + 1.5707964f), g_2bd470, g_2bd474);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        } else {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
        }
    }
block_40:
    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0x1010);
    temp_v0_3 = M2C_FIELD(temp_a2, void **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *), 0xEC)(temp_a2 + M2C_FIELD(temp_v0_3, s16 *, 0xE8), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), temp_a2);
    temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
    func_00208540(temp_a0_2, M2C_FIELD(temp_a0_2, void **, 0x1010));
}
