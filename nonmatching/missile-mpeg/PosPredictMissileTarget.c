#include "m2c_macros.h"

M2C_UNK PredictXfTransform(s32, M2C_UNK, M2C_UNK *, M2C_UNK, f32); /* extern */

s128 *PosPredictMissileTarget(s128 *arg0, void *arg1, f32 fparg0) {
    s128 sp0;
    M2C_UNK sp10;
    M2C_UNK sp50;
    void *temp_a2;
    void *temp_v1;

    temp_a2 = M2C_FIELD(arg1, void **, 0x210);
    if (temp_a2 != NULL) {
        temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
        PredictXfTransform(M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK *, void *), 0x104)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x100), &sp10, temp_a2), 0, &sp50, 0, fparg0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x220($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf6z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf4, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    } else {
        sp0 = M2C_FIELD(arg1, s128 *, 0x220);
    }
    *arg0 = sp0;
    return arg0;
}
