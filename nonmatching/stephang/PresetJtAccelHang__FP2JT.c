#include "m2c_macros.h"

M2C_UNK AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(void *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AddSoAcceleration(s128);                    /* extern */
M2C_UNK BuildRotateVectorsMatrix(s128 *, s128, M2C_UNK); /* extern */
M2C_UNK LoadRotateMatrixRad(s128 *, s128, s128, f32, s128, s128, s128); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
extern M2C_UNK D_002BF548;
extern s128 g_2a2dc0;

void PresetJtAccelHang__FP2JT(void *arg0) {
    M2C_UNK spC0;
    M2C_UNK spD0;
    M2C_UNK sp80;
    s128 spB0;

    AddSoAcceleration(M2C_FIELD(arg0, s128 *, 0x1910));
    PosLoWorld(M2C_FIELD(arg0, void **, 0x18C4));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x110($sp) */);
    PosLoWorld(arg0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    BuildRotateVectorsMatrix(&spB0, g_2a2dc0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */));
    LoadRotateMatrixRad(&spB0, g_2a2dc0, spD0, M2C_FIELD(arg0, f32 *, 0x1A8), spB0, spC0, spD0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf6z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf8x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf8y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf8z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf7x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf7y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf7z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xf0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xd0($sp) */);
    AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(arg0, &sp80, &D_002BF548);
}
