#include "m2c_macros.h"

M2C_UNK CalculateEmitdvMatrix(void *, void *);      /* extern */
s32 FIsZeroDv__FP6VECTOR(s128);                     /* extern */
s32 FIsZeroV__FP6VECTOR(s128);                      /* extern */
s32 FIsZeroW__FP6VECTOR(s128);                      /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, M2C_UNK, f32); /* extern */
extern M2C_UNK g_2dded0;

s32 ProjectRipTransform__FP3RIPf(void *arg0) {
    char sp[0x400];
    M2C_UNK sp50;
    f32 temp_v1;
    s32 var_s1;
    s32 var_v0;

    if (FIsZeroW__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0xD0)) == 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xd0($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xd0($s0) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
        if (temp_v1 > 0.0001f) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf4, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            LoadRotateMatrixRad(&sp50, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), temp_v1 * M2C_FIELD(&g_2dded0, f32 *, 4));
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf4z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        }
    }
    var_s1 = 0;
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
    var_v0 = FIsZeroV__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0x90));
    if ((var_v0 == 0) || (var_v0 = FIsZeroDv__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0xA0)), (var_v0 == 0))) {
        var_s1 = 1;
    }
    if (var_s1 != 0) {
        CalculateEmitdvMatrix(sp, arg0 + 0xA0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x90($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf6z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($s0) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($s0) */);
    }
    return var_v0;
}
