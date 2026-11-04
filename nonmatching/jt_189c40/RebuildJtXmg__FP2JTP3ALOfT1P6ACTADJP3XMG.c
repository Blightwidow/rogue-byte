#include "m2c_macros.h"

s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK PredictAsegEffect(s32, void *, void *, s32, f32, M2C_UNK); /* extern */

s32 RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    M2C_UNK sp130;
    M2C_UNK spE0;
    M2C_UNK sp50;
    M2C_UNK sp90;
    s128 spD0;
    f32 *temp_v0;
    f32 temp_f12;
    f32 var_f21;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    void *temp_s3;
    void *temp_v0_2;
    void *var_s1;

    temp_s3 = M2C_ERROR(/* Read from unset register $t0 */);
    if (M2C_FIELD(arg0, s32 *, 0x18C8) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D8);
        if (temp_v1 >= 6) {
            if (temp_v1 < 0xA) {
                var_s1 = M2C_FIELD(arg0, void **, 0x18E0);
            } else if ((temp_v1 < 0xE) && (temp_v1 >= 0xC)) {
                var_s1 = M2C_FIELD(arg0, void **, 0x18E0);
            } else {
                goto block_8;
            }
        } else {
block_8:
            goto block_12;
        }
    } else if (M2C_FIELD(arg0, void **, 0x1034) == NULL) {
        var_s1 = M2C_FIELD(arg0, void **, 0x1030);
    } else {
block_12:
        var_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1034), void **, 0x30);
    }
    temp_v1_2 = M2C_FIELD(var_s1, s32 *, 0x14);
    var_v0 = M2C_FIELD(temp_s3, s32 *, 0);
    if (temp_v1_2 != var_v0) {
        M2C_FIELD(temp_s3, s32 *, 0) = temp_v1_2;
        var_f21 = 0.0f;
        temp_v0 = PeaFindAsegLabel(M2C_FIELD(var_s1, s32 *, 0x14), 0x16A);
        if (temp_v0 != NULL) {
            var_f21 = *temp_v0;
        }
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, arg1, M2C_FIELD(arg0, s32 *, 0x60), var_f21, 0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x130($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, arg2, M2C_FIELD(arg0, s32 *, 0x60), var_f21, 0);
        PredictAsegEffect(M2C_FIELD(var_s1, s32 *, 0x14), arg0, M2C_FIELD(M2C_FIELD(arg2, void **, 0xA8), void **, 0), M2C_FIELD(arg0, s32 *, 0x60), var_f21, 0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xa0($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf6z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf2, $vf0w */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x130($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf8 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($s3) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
        temp_v0_2 = M2C_FIELD(arg2, void **, 0xA8);
        M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x40($sp) */);
        temp_f12 = M2C_FIELD(temp_v0_2, f32 *, 0xC0) + M2C_FIELD(temp_v0_2, f32 *, 0xC4) + 10.0f;
        M2C_FIELD(temp_s3, f32 *, 8) = temp_f12;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x130($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf7x */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf8x */);
        M2C_FIELD(temp_s3, s32 *, 4) = (s32) (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), 1, temp_f12) > 0);
        M2C_FIELD(temp_s3, s128 *, 0x30) = spD0;
        M2C_FIELD(temp_s3, s128 *, 0x10) = sp130;
        M2C_FIELD(temp_s3, s128 *, 0x40) = spE0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s0) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s3) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($s3) */);
    }
    return var_v0;
}
