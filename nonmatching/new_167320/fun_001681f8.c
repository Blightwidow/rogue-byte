#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(s128 *, void *, M2C_UNK);   /* extern */
M2C_UNK GMaxAxisScale(s128 *);                      /* extern */
void *OnGameLoad__FP4GAME(s32, M2C_UNK, s64 *, void *); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(M2C_UNK *, s128 *, s32); /* extern */
M2C_UNK memcpy(s128 *, M2C_UNK *, M2C_UNK);         /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dea28;

void func_001681F8(void *arg0) {
    char sp[0x400];
    M2C_UNK sp70;
    M2C_UNK sp80;
    M2C_UNK sp90;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    M2C_UNK spA0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v1_2;
    s32 var_s2;
    s32 var_s4;
    s32 var_t0;
    s64 *temp_s0_2;
    s64 *temp_v0;
    s64 *temp_v0_2;
    s64 *temp_v1;
    s64 *var_a0;
    s64 *var_a2;
    void *temp_s1;
    void *temp_s6;
    void *temp_v0_3;
    void *var_a3;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0) {
        do {
            var_s4 = var_s2 + 1;
            temp_s6 = M2C_FIELD(arg0, s32 *, 0x3C) + (var_s2 * 0x14);
            temp_s1 = M2C_FIELD(arg0, s32 *, 0x40) + (var_s2 * 0x28);
            if (M2C_FIELD(temp_s6, s32 *, 8) != 0) {
                if (M2C_FIELD(temp_s1, s32 *, 0xC) & 0x1000) {
                    CopyAb__FPvT0Ui(&sp20, M2C_FIELD(temp_s1, s32 *, 0x10) + 0x14, 0x40);
                } else {
                    temp_s0 = M2C_FIELD(temp_s1, s32 *, 8);
                    memcpy(&sp60, M2C_FIELD(temp_s1, s32 *, 4) + 0x40, 0x40);
                    if (temp_s0 != 0) {
                        __ml__FRC7MATRIX4T0(&spA0, &sp60, temp_s0);
                        memcpy(&sp60, &spA0, 0x40);
                    }
                    sp20 = sp60;
                    sp30 = sp70;
                    sp40 = sp80;
                    sp50 = sp90;
                }
                if (M2C_FIELD(temp_s1, void **, 0x24) == NULL) {
                    CopyAb__FPvT0Ui(&sp60, M2C_FIELD(arg0, s32 *, 0x44) + (var_s2 * 0x18), 0xC);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x60($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                    GMaxAxisScale(&sp20);
                } else {
                    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($v0) */);
                    M2C_ERROR(/* unknown instruction: ldr $v1, ($v0) */);
                    M2C_ERROR(/* unknown instruction: sdl $v1, 0x17($sp) */);
                    M2C_ERROR(/* unknown instruction: sdr $v1, 0x10($sp) */);
                }
                temp_s0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
                var_a3 = sp;
                M2C_FIELD(temp_s0_2, s64 *, 0) = 0x10000000;
                temp_v1 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_v1 + 0x10);
                M2C_FIELD(temp_v1, s32 *, 0x10) = 0x6C06C301;
                temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
                var_a2 = temp_v0;
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
                var_s4 = var_s2 + 1;
                var_t0 = 0x14;
                do {
                    var_t0 -= 4;
                    temp_v1_2 = M2C_FIELD(var_a3, s32 *, 4);
                    temp_a0 = M2C_FIELD(var_a3, s32 *, 8);
                    temp_a1 = M2C_FIELD(var_a3, s32 *, 0xC);
                    M2C_FIELD(var_a2, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
                    var_a3 += 0x10;
                    M2C_FIELD(var_a2, s32 *, 4) = temp_v1_2;
                    M2C_FIELD(var_a2, s32 *, 8) = temp_a0;
                    M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1;
                    var_a2 += 0x10;
                } while (var_t0 >= 0);
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x60);
                var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
                if ((s32) var_a0 & 0xF) {
                    do {
                        *var_a0 = 0;
                        temp_v0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
                        var_a0 = temp_v0_2;
                        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_2;
                    } while ((s32) var_a0 & 0xF);
                }
                temp_a0_2 = M2C_FIELD(temp_s0_2, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_s0_2) >> 4) - 1);
                M2C_FIELD(temp_s0_2, s32 *, 0) = temp_a0_2;
                M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x60000000;
                M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
                temp_v0_3 = OnGameLoad__FP4GAME(temp_a0_2, 0x60000000, var_a2, var_a3);
                M2C_FIELD(temp_v0_3, s64 **, 8) = temp_s0_2;
                M2C_FIELD(temp_v0_3, s32 *, 0) = 0;
                M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
                M2C_FIELD(temp_v0_3, s32 *, 0xC) = (s32) M2C_FIELD(temp_s6, s32 *, 8);
            }
            var_s2 = var_s4;
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x38));
    }
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(&B_003DD490, s32 *, 0x3D5C);
}
