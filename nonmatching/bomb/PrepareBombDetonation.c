#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *, s128, s128); /* extern */
M2C_UNK BuildRotateVectorsMatrix(void *, s128, M2C_UNK); /* extern */
s128 *PmatLoWorld(void *);                          /* extern */
extern s128 g_2a2dc0;

void PrepareBombDetonation(void *arg0, s128 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    s128 *temp_v0;
    s128 var_a1;
    s32 temp_v1_3;
    void *temp_v1;
    void *temp_v1_2;

    M2C_ERROR(/* unknown instruction: por $s2, $zero, $a2 */);
    if (M2C_FIELD(arg0, s32 *, 0x174) == 0) {
        M2C_FIELD(arg0, s128 *, 0x180) = arg1;
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, s32 *, 0x174) = 1;
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, s128 *, 0x1C0) = M2C_FIELD(temp_v1, s128 (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x170);
        M2C_FIELD(arg0, s128 *, 0x1D0) = M2C_FIELD(temp_v1_2, s128 (**)(void *), 0x114)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x110));
        switch (temp_v1_3) {                        /* irregular */
        case 0:
            var_a1 = M2C_FIELD(PmatLoWorld(arg0), s128 *, 0x20);
block_13:
            BuildRotateVectorsMatrix(sp, var_a1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s2 */));
            PmatLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf4z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x190($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x1b0($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1a0($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
            break;
        case 1:
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, M2C_FIELD(arg0, s128 *, 0x1C0), g_2a2dc0);
            M2C_FIELD(arg0, s128 *, 0x190) = sp0;
            M2C_FIELD(arg0, s128 *, 0x1B0) = sp20;
            M2C_FIELD(arg0, s128 *, 0x1A0) = sp10;
            break;
        case 2:
            var_a1 = *PmatLoWorld(arg0);
            goto block_13;
        case 3:
            temp_v0 = PmatLoWorld(arg0);
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) M2C_FIELD(temp_v0, s128 *, 0);
            M2C_FIELD(arg0, s128 *, 0x1A0) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
            M2C_FIELD(arg0, s128 *, 0x1B0) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
            break;
        }
    }
}
