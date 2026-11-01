#include "m2c_macros.h"

M2C_UNK BuildRotateVectorsMatrix(M2C_UNK *, s128, M2C_UNK); /* extern */
M2C_UNK ConvertXfVec(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *);         /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
s128 PosSmooth(s128, s128, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK func_0012D108(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_002BF598;
extern f32 D_FLT_002BF594;
extern s128 g_2a2da0;
extern s128 g_2a2dd0;
extern f32 g_2dded4;

void UpdateJtHangPose(void *arg0) {
    char sp[0x400];
    M2C_UNK sp60;
    M2C_UNK sp90;

    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x18C4));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($a1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x19C0), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
    BuildRotateVectorsMatrix(&sp60, g_2a2da0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
    LoadRotateMatrixRad(&sp90, g_2a2da0, D_FLT_002BF594);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf5z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf6z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
    DecomposeRotateMatrixEuler(sp);
    func_0012D108(M2C_FIELD(arg0, s32 *, 0x1A00), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    M2C_FIELD(arg0, s128 *, 0x1960) = PosSmooth(M2C_FIELD(arg0, s128 *, 0x1960), g_2a2dd0, &D_002BF598, 0, g_2dded4);
}
