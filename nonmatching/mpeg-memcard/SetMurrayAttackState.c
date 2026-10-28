#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(); /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP();    /* extern */
void *PchnFindAseg(); /* extern */
f32 *PeaFindAsegLabel();                /* extern */
s128 PosLoWorld();                    /* extern */
f32 RadNormalize__Ff();                          /* extern */
M2C_UNK RetractAsegaHandle();                 /* extern */
M2C_UNK RetractSmaRef();                      /* extern */
M2C_UNK SetStepRadTarget();              /* extern */
f32 atan2f();                       /* extern */
M2C_UNK func_00131A90();                 /* extern */
M2C_UNK func_001431D0();                      /* extern */
extern f32 D_FLT_002C09F0;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void SetMurrayAttackState(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    f32 *temp_v0;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_s1;
    void **temp_a3;
    void **temp_t0;
    void *temp_a0;
    void *temp_a1;
    void *temp_a3_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x1810)) {
        M2C_FIELD(arg0, s32 *, 0x1810) = arg1;
        M2C_FIELD(arg0, f32 *, 0x1814) = (f32) g_2dded0;
        if (arg1 != -1) {
            M2C_FIELD(arg0, s32 *, 0x1820) = 0;
            M2C_FIELD(arg0, s32 *, 0x1818) = 0;
            M2C_FIELD(arg0, s32 *, 0x181C) = 0;
            if (M2C_FIELD(arg0, s32 *, 0x190C) != 0) {
                RetractAsegaHandle(arg0 + 0x190C);
            }
            temp_s1 = M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x17FC);
            temp_a1 = M2C_FIELD(arg0, void **, 0x10DC);
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            if ((temp_a1 != NULL) && (M2C_FIELD(arg0, s32 *, 0x10E4) >= 2) && !(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8)) {
                sp20 = PosLoWorld(temp_a1, temp_a1);
                PosLoWorld(arg0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                temp_f0 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */));
                if (fabsf(RadNormalize__Ff(temp_f0 - M2C_FIELD(arg0, f32 *, 0x1A8))) < D_FLT_002C09F0) {
                    SetStepRadTarget(arg0, temp_f0);
                    FixStepAngularVelocity__FP4STEP(arg0);
                }
            }
            var_f20 = 0.0f;
            RetractSmaRef(arg0 + 0x1034);
            ApplyAsegToHandle(temp_s1, arg0, 1, arg0 + 0x1030, 0, 0x3F800000);
            if (temp_s1 != 0) {
                temp_v0 = PeaFindAsegLabel(temp_s1, 0x1AC);
                if (temp_v0 != NULL) {
                    var_f20 = *temp_v0;
                }
            }
            if (var_f20 != 0.0f) {
                temp_a0 = M2C_FIELD(arg0, void **, 0x1030);
                func_00131A90(temp_a0, g_2dded0 + (var_f20 / M2C_FIELD(temp_a0, f32 *, 0x40)));
            }
            temp_v0_2 = M2C_FIELD(arg0, void **, 0x1030);
            if (temp_v0_2 != NULL) {
                temp_v0_3 = PchnFindAseg(M2C_FIELD(temp_v0_2, void **, 0x14), arg0, 1, 1);
                if (temp_v0_3 != NULL) {
                    temp_a3 = M2C_FIELD(temp_v0_3, void ***, 4);
                    temp_v0_4 = *temp_a3;
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *, M2C_UNK, void **, M2C_UNK, M2C_UNK), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_4, s16 *, 0x18), sp, 0, temp_a3, 0, 0);
                    temp_t0 = M2C_FIELD(temp_v0_3, void ***, 4);
                    temp_a3_2 = *temp_t0;
                    M2C_FIELD(temp_a3_2, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK, void *, f32, M2C_UNK), 0x1C)(temp_t0 + M2C_FIELD(temp_a3_2, s16 *, 0x18), &sp10, 0, temp_a3_2, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), void **, 0x14), f32 *, 0x74), 0);
                    PosLoWorld(arg0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1b0($s0) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf3z */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf3 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1830($s0) */);
                } else {
                    M2C_FIELD(arg0, s128 *, 0x1830) = PosLoWorld(arg0, sp);
                }
            }
            func_001431D0(arg0);
        }
    }
}
