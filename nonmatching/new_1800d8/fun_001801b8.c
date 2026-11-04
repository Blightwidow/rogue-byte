#include "m2c_macros.h"

f32 GLimitAbs__Fff(f32, f32);                       /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK UpdateSo();                                 /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
extern s128 g_2a2dc0;
extern f32 g_2dded0;
extern f32 g_2dded4;

void func_001801B8(void *arg0) {
    M2C_UNK sp30;
    M2C_UNK sp60;
    s128 spC0;
    f32 temp_f20;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    UpdateSo();
    if ((M2C_FIELD(arg0, s32 *, 0x18C) == 0) && (M2C_FIELD(arg0, f32 *, 0x1C0) <= g_2dded0)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x294)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x290), 0);
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x1D0);
    if ((temp_a0 != NULL) && (M2C_FIELD(arg0, f32 *, 0x1D4) != 0.0f)) {
        spC0 = PosLoWorld(temp_a0);
        PosLoWorld(arg0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        temp_f20 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */));
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        LoadRotateMatrixRad(&sp60, g_2a2dc0, GLimitAbs__Fff(RadNormalize__Ff(temp_f20 - atan2f(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */))), M2C_FIELD(arg0, f32 *, 0x1D4) * g_2dded4));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf3, $vf4z */);
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */));
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf1, $vf6z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf4z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
        temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xb0($sp) */);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK *), 0xF4)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0xF0), &sp30);
    }
}
