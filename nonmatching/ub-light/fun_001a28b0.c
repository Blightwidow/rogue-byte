#include "m2c_macros.h"

void *AddSoAcceleration(void *, s128);              /* extern */
void *AddSoWaterAcceleration(void *, s32);          /* extern */
s32 FFindWaterSurface(void *, s32, s128 *);         /* extern */
M2C_UNK GSmoothA__FffffP4SMPAPf(void *, f32 *, f32, f32, f32, f32, s128); /* extern */
M2C_UNK LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(s32, s128, M2C_UNK *, M2C_UNK *); /* extern */
s128 PosLoWorld(void *);                            /* extern */
extern M2C_UNK g_2dded0;

void *func_001A28B0(void *arg0, s32 arg1) {
    M2C_UNK sp18;
    M2C_UNK sp48;
    M2C_UNK sp60;
    M2C_UNK sp8;
    M2C_UNK unksp28;
    s128 sp20;
    M2C_UNK sp40;
    M2C_UNK sp50;
    f32 sp68;
    f32 sp80;
    s32 temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_v0;

    if (M2C_FIELD(arg0, s32 *, 0x2DC) != 5) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xDF4);
        if (temp_v1 != 7) {
            if (temp_v1 < 8) {
                if (temp_v1 != 3) {
                    goto block_11;
                }
                goto block_9;
            }
            if (temp_v1 != 0xA) {
block_11:
                var_v0 = AddSoWaterAcceleration(arg0, arg1);
                /* Duplicate return node #12. Try simplifying control flow for better match */
                return var_v0;
            }
block_9:
            var_v0 = arg0 + 0x1B0;
            if (FFindWaterSurface(arg0, arg1, &sp20) != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1b0($s1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x190($s1) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf4, $vf2z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(arg1, sp20, &sp40, &sp50);
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_2, void *(**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
                GSmoothA__FffffP4SMPAPf(arg0 + 0x10A8, &sp80, sp8 + M2C_FIELD(arg0, f32 *, 0x10A0), sp18 - sp48, unksp28, M2C_FIELD(&g_2dded0, f32 *, 4), PosLoWorld(arg0));
                sp68 = M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f2 */);
                return AddSoAcceleration(arg0, sp60);
            }
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return var_v0;
        }
    }
    temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
    var_v0 = M2C_FIELD(temp_v1_3, void *(**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x108));
    if (sp8 < 0.0f) {
        return AddSoWaterAcceleration(arg0, arg1);
    }
    return var_v0;
}
