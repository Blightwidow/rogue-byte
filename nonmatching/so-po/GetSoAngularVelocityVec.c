#include "m2c_macros.h"

M2C_UNK InvertMatrix3(M2C_UNK *, void *);           /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(void *, s128, s128, s128, s128); /* extern */
M2C_UNK func_0022D148(s128 *, void *, M2C_UNK);     /* extern */
extern s128 g_2a2dd0;

s128 GetSoAngularVelocityVec(void *arg0) {
    char sp[0x400];
    s128 sp40;
    s128 sp50;
    s128 sp60;
    M2C_UNK spD0;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x5C);
    if ((temp_s2 == NULL) || (M2C_FIELD(temp_s2, s32 *, 0x94) != 6)) {
        return g_2a2dd0;
    }
    func_0022D148(&sp60, temp_s2, 0);
    temp_s1 = temp_s2 + 0x40;
    sp40 = M2C_FIELD(&sp60, s128 *, 0x10);
    sp50 = M2C_FIELD(&sp60, s128 *, 0x20);
    NormalizeRotateMatrix3__FP7MATRIX3(sp, M2C_FIELD(temp_s2, s128 *, 0x40), M2C_FIELD(temp_s1, s128 *, 0x10), M2C_FIELD(temp_s1, s128 *, 0x20), sp60);
    InvertMatrix3(&spD0, temp_s1);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf5z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xf0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf6z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf7x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf7y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf7, $vf3, $vf7z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
    sp60 = M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
}
