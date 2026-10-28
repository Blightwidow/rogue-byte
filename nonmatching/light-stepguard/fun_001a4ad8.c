#include "m2c_macros.h"

M2C_UNK RebuildLight(s32, s32, s32 *, s32);         /* extern */
extern M2C_UNK D_002BFC60;
extern M2C_UNK g_2dea28;

void func_001A4AD8(s32 arg0, s32 arg1, s32 *arg2, void *arg3) {
    M2C_UNK *var_a3_2;
    s32 *temp_s6;
    s32 *temp_v1;
    s32 *temp_v1_3;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a1;
    s32 var_s1;
    s32 var_t0;
    void *temp_s5;
    void *var_a3;
    void *var_s0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    temp_s4 = var_a1;
    temp_s5 = var_a3;
    temp_s6 = var_a2;
    var_s1 = 0;
    M2C_FIELD(temp_s5, s32 **, 0x18) = (s32 *) M2C_FIELD(&g_2dea28, s32 **, 0xC);
    if (temp_s4 > 0) {
        do {
            temp_s0 = *((var_s1 * 4) + temp_s6);
            RebuildLight(temp_s0, var_a1, var_a2, (s32) var_a3);
            var_s0 = temp_s0 + 0x120;
            *M2C_FIELD(&g_2dea28, s32 **, 0xC) = ((var_s1 * 3) + 0x15) | 0x6C03C000;
            temp_v1 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2 = temp_v1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1;
            var_a3 = (void *)8;
loop_3:
            var_a3 -= 4;
            temp_v1_2 = M2C_FIELD(var_s0, s32 *, 4);
            temp_a0 = M2C_FIELD(var_s0, s32 *, 8);
            var_a1 = M2C_FIELD(var_s0, s32 *, 0xC);
            M2C_FIELD(var_a2, s32 *, 0) = M2C_FIELD(var_s0, s32 *, 0);
            var_s0 += 0x10;
            M2C_FIELD(var_a2, s32 *, 4) = temp_v1_2;
            M2C_FIELD(var_a2, s32 *, 8) = temp_a0;
            M2C_FIELD(var_a2, s32 *, 0xC) = var_a1;
            var_a2 += 0x10;
            if ((s32) var_a3 >= 0) {
                goto loop_3;
            }
            var_s1 += 1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
        } while (var_s1 < temp_s4);
    }
    if (var_s1 < 4) {
        do {
            var_a3_2 = &D_002BFC60;
            *M2C_FIELD(&g_2dea28, s32 **, 0xC) = ((var_s1 * 3) + 0x15) | 0x6C03C000;
            temp_v1_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2_2 = temp_v1_3;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1_3;
            var_t0 = 8;
loop_8:
            var_t0 -= 4;
            temp_v1_4 = M2C_FIELD(var_a3_2, s32 *, 4);
            temp_a0_2 = M2C_FIELD(var_a3_2, s32 *, 8);
            temp_a1 = M2C_FIELD(var_a3_2, s32 *, 0xC);
            M2C_FIELD(var_a2_2, s32 *, 0) = M2C_FIELD(var_a3_2, s32 *, 0);
            var_a3_2 += 0x10;
            M2C_FIELD(var_a2_2, s32 *, 4) = temp_v1_4;
            M2C_FIELD(var_a2_2, s32 *, 8) = temp_a0_2;
            M2C_FIELD(var_a2_2, s32 *, 0xC) = temp_a1;
            var_a2_2 += 0x10;
            if (var_t0 >= 0) {
                goto loop_8;
            }
            var_s1 += 1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
        } while (var_s1 < 4);
    }
    M2C_FIELD(temp_s5, s32 *, 0x14) = (s32) ((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - M2C_FIELD(temp_s5, s32 *, 0x18)) >> 4);
}
