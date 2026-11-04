#include "m2c_macros.h"

M2C_UNK DiscardSoXps(void *);                       /* extern */
M2C_UNK InvertMatrix3(M2C_UNK *, void *);           /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(void *, void *, s128, s128, s128); /* extern */
M2C_UNK WakeXf(void *, void *);                     /* extern */
M2C_UNK func_001F3900(void *);                      /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_003DD490;

void RotateSoToMat(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp50;
    M2C_UNK sp60;
    s32 temp_v0;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;

    temp_a1 = M2C_FIELD(arg0, void **, 0x5C);
    if (temp_a1 != NULL) {
        temp_a1_2 = M2C_FIELD(temp_a1, void **, 0xA0);
        if (temp_a1_2 != NULL) {
            temp_a1_3 = temp_a1_2 + 0x40;
            NormalizeRotateMatrix3__FP7MATRIX3(sp, temp_a1_3, M2C_FIELD(temp_a1_2, s128 *, 0x40), M2C_FIELD(temp_a1_3, s128 *, 0x10), M2C_FIELD(temp_a1_3, s128 *, 0x20));
        } else {
            memset(sp, 0, 0x30);
        }
        InvertMatrix3(&sp60, sp);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($s1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf1, $vf6z */);
        temp_a0 = M2C_FIELD(arg0, void **, 0x5C);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf5z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a0) */);
        M2C_FIELD(temp_a0, s128 *, 0x10) = sp40;
        M2C_FIELD(temp_a0, s32 *, 0xC) = 0;
        M2C_FIELD(temp_a0, s128 *, 0x20) = sp50;
        M2C_FIELD(temp_a0, s32 *, 0x2C) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x1C) = 0;
        temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0xA4) = temp_v0;
        temp_a1_4 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_a1_4, M2C_UNK (**)(void *, void *), 0x94)(arg0 + M2C_FIELD(temp_a1_4, s16 *, 0x90), temp_a1_4);
        DiscardSoXps(arg0);
        WakeXf(arg0, M2C_FIELD(arg0, void **, 0x5C));
        func_001F3900(arg0);
    }
}
