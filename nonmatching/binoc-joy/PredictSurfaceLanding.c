#include "m2c_macros.h"

M2C_UNK Spire_FindClosestPoint(M2C_UNK, M2C_UNK, void *, f32); /* extern */

s32 PredictSurfaceLanding(s128 arg3, f32 fparg0, f32 fparg1) {
    char sp[0x400];
    M2C_UNK sp8;
    M2C_UNK sp10;
    M2C_UNK sp20;
    s128 sp40;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf6 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
    sp40 = arg3;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf6, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x60($sp) */);
    Spire_FindClosestPoint(M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), 0, sp, fparg1 * (fparg1 * 0.5f));
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s0) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, ($s0) */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $t0 */), s32 *, 8) = sp8;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s2) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf2, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf6, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
    return 1;
}
