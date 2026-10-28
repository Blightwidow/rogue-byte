#include "m2c_macros.h"

M2C_UNK LoadRotateMatrixPanTilt(void *, f32, f32, s128); /* extern */
M2C_UNK PosCplookAnchor(void *);                    /* extern */
extern s128 RO_002A5000;

s32 PosCplookEye(void *arg0) {
    char sp[0x400];
    LoadRotateMatrixPanTilt(sp, M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(arg0, f32 *, 0x14), RO_002A5000);
    PosCplookAnchor(arg0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
}
