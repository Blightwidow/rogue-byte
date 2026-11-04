#include "m2c_macros.h"

M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
extern s128 g_2a2dc0;

s32 BuildJmpEdgeProbes(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    M2C_UNK sp40;
    s128 sp70;
    s128 sp80;
    f32 temp_f12;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;

    var_s1 = 8;
    temp_s0 = arg3 + 0x10;
    temp_s0_2 = temp_s0 + 0x10;
    temp_s0_3 = temp_s0_2 + 0x10;
    M2C_FIELD(arg3, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    var_s0 = temp_s0_3 + 0x10;
    M2C_FIELD(arg3, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x11C);
    M2C_FIELD(arg3, s32 *, 4) = 0;
    M2C_FIELD(arg3, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x118);
    M2C_FIELD(temp_s0, s32 *, 4) = 0;
    M2C_FIELD(temp_s0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x108);
    M2C_FIELD(temp_s0_2, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x110);
    M2C_FIELD(temp_s0_2, s32 *, 4) = 0;
    M2C_FIELD(temp_s0_3, M2C_UNK32 *, 4) = 0;
    M2C_FIELD(temp_s0_2, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x114);
    M2C_FIELD(temp_s0_3, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x11C);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    sp70 = M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    sp80 = M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    do {
        temp_f12 = (f32) (var_s1 - 4);
        var_s1 -= 1;
        LoadRotateMatrixRad(&sp40, g_2a2dc0, temp_f12 * 0.2617994f);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
        temp_v0 = var_s0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x70($sp) */);
        var_s0 = var_s0 + 0x10 + 0x10;
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf2, $vf5z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf4z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($v1) */);
    } while (var_s1 >= 0);
    var_s1_2 = arg2 - 1;
    if (var_s1_2 >= 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s0) */);
            var_s1_2 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($s2) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s0) */);
        } while (var_s1_2 >= 0);
    }
    return temp_v0;
}
