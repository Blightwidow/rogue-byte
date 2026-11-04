#include "m2c_macros.h"

M2C_UNK InvalidateCrvCache(void *);                 /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK SetRopeSimLength(void *, s32, s32, void *, f32); /* extern */
M2C_UNK VelocityXfAtPos(s32, M2C_UNK, M2C_UNK);     /* extern */
extern f32 g_2dded4;

void UpdateRopeSimChain(void *arg0) {
    M2C_UNK sp10;
    f32 temp_f1;
    f32 temp_f20;
    s32 temp_a2;
    s32 temp_v1_2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s2;
    void *temp_a1;
    void *temp_a3;
    void *temp_v0;
    void *temp_v1;

    temp_f20 = g_2dded4;
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf3z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf4, $vf0w */);
    var_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0xE8);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($v1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
    VelocityXfAtPos(M2C_FIELD(arg0, s32 *, 0x40), 0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf6 */));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
    var_a3 = 1;
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, ($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x50($sp) */);
    if (var_s2 > 1) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf8 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
        do {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf8, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf2, $vf8x */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf1, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf5x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf6 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f)) {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf2, $q */);
            }
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf4, $vf7 */);
            temp_v0 = (var_a3 * 4) + M2C_FIELD(arg0, s32 *, 0x5C);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
            temp_f1 = M2C_FIELD(temp_v0, f32 *, 0) - M2C_FIELD(temp_v0, f32 *, -4);
            var_a3 += 1;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf7, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf6, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($a0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf7, ($v0) */);
        } while (var_a3 < var_s2);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) == 2) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($s1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf5, $vf0w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, -0x10($v1) */);
        temp_a2 = (var_s2 * 0x10) + M2C_FIELD(arg0, s32 *, 0x54);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, -0x10($a2) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, -0x20($a1) */);
        temp_a3 = (var_s2 * 4) + M2C_FIELD(arg0, s32 *, 0x5C);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        SetRopeSimLength(arg0, temp_a2, temp_a2, temp_a3, M2C_FIELD(temp_a3, f32 *, -8) + M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */));
        var_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0xE8);
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0x48);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    InvertMatrix4Affine(&sp10, M2C_FIELD(temp_v1, s32 (**)(void *, void *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1));
    var_a3_2 = 0;
    if (var_s2 > 0) {
        do {
            temp_v1_2 = var_a3_2 * 0x10;
            var_a3_2 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf5z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($v1) */);
        } while (var_a3_2 < var_s2);
    }
    InvalidateCrvCache(M2C_FIELD(arg0, void **, 0x48));
}
