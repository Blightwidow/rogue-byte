#include "m2c_macros.h"

extern M2C_UNK g_2dea28;

void EmitGlyphDma(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a3;
    s32 var_t0_3;
    s32 var_t2;
    s32 var_t2_2;
    s64 *temp_a0;
    s64 *temp_t4;
    s64 *temp_v0;
    s64 *temp_v0_2;
    s64 *temp_v0_3;
    s64 *temp_v0_4;
    s64 *temp_v1_3;
    s64 *var_a0;
    s64 *var_a0_2;
    s64 *var_a3_2;
    s64 *var_t0;
    s64 *var_t0_2;
    s64 *var_v0;
    void *var_a2;
    void *var_t1;
    void *var_t1_2;

    var_a2 = arg2;
    temp_t4 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(temp_t4, s64 *, 0) = 0x10000000;
    temp_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_a0 + 0x10);
    if (arg3 & 1) {
        var_t1 = arg1;
        M2C_FIELD(temp_a0, s32 *, 0x10) = 0x6C04C000;
        temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        var_t0 = temp_v0;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
        var_a3 = arg3 & 2;
        var_t2 = 0xC;
        do {
            var_t2 -= 4;
            temp_v1 = M2C_FIELD(var_t1, s32 *, 4);
            temp_a0_2 = M2C_FIELD(var_t1, s32 *, 8);
            temp_a1 = M2C_FIELD(var_t1, s32 *, 0xC);
            M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_FIELD(var_t1, s32 *, 0);
            var_t1 += 0x10;
            M2C_FIELD(var_t0, s32 *, 4) = temp_v1;
            M2C_FIELD(var_t0, s32 *, 8) = temp_a0_2;
            M2C_FIELD(var_t0, s32 *, 0xC) = temp_a1;
            var_t0 += 0x10;
        } while (var_t2 >= 0);
        var_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x40;
    } else {
        var_t1_2 = arg1 + 0x20;
        M2C_FIELD(temp_a0, s32 *, 0x10) = 0x6C01C002;
        temp_v0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        var_t0_2 = temp_v0_2;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_2;
        var_a3 = arg3 & 2;
        var_t2_2 = 0;
        do {
            var_t2_2 -= 4;
            temp_v1_2 = M2C_FIELD(var_t1_2, s32 *, 4);
            temp_a0_3 = M2C_FIELD(var_t1_2, s32 *, 8);
            temp_a1_2 = M2C_FIELD(var_t1_2, s32 *, 0xC);
            M2C_FIELD(var_t0_2, s32 *, 0) = (s32) M2C_FIELD(var_t1_2, s32 *, 0);
            var_t1_2 += 0x10;
            M2C_FIELD(var_t0_2, s32 *, 4) = temp_v1_2;
            M2C_FIELD(var_t0_2, s32 *, 8) = temp_a0_3;
            M2C_FIELD(var_t0_2, s32 *, 0xC) = temp_a1_2;
            var_t0_2 += 0x10;
        } while (var_t2_2 >= 0);
        var_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10;
    }
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = var_v0;
    M2C_FIELD(var_a2, s32 *, 0xC) = 0x7FFF;
    if ((u16) M2C_FIELD(arg0, u16 *, 0x12) < 2U) {
        M2C_FIELD(var_a2, s32 *, 4) = 0;
    } else {
        M2C_FIELD(var_a2, s32 *, 4) = 1;
    }
    if ((var_a3 != 0) || (M2C_FIELD(var_a2, s32 *, 4) != 0)) {
        M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x6C03C004;
        temp_v1_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        var_a3_2 = temp_v1_3;
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v1_3;
        var_t0_3 = 8;
        do {
            var_t0_3 -= 4;
            temp_v1_4 = M2C_FIELD(var_a2, s32 *, 4);
            temp_a0_4 = M2C_FIELD(var_a2, s32 *, 8);
            temp_a1_3 = M2C_FIELD(var_a2, s32 *, 0xC);
            M2C_FIELD(var_a3_2, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
            var_a2 += 0x10;
            M2C_FIELD(var_a3_2, s32 *, 4) = temp_v1_4;
            M2C_FIELD(var_a3_2, s32 *, 8) = temp_a0_4;
            M2C_FIELD(var_a3_2, s32 *, 0xC) = temp_a1_3;
            var_a3_2 += 0x10;
        } while (var_t0_3 >= 0);
        M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x30);
    }
    var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    if ((s32) var_a0 & 0xF) {
        do {
            *var_a0 = 0;
            temp_v0_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_a0 = temp_v0_3;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_3;
        } while ((s32) var_a0 & 0xF);
    }
    M2C_FIELD(temp_t4, s32 *, 0) = (s32) (M2C_FIELD(temp_t4, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_t4) >> 4) - 1));
    var_a0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    if ((s32) var_a0_2 & 0xF) {
        do {
            *var_a0_2 = 0;
            temp_v0_4 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_a0_2 = temp_v0_4;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_4;
        } while ((s32) var_a0_2 & 0xF);
    }
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = ((s64) M2C_FIELD(arg0, s32 *, 0x1C) << 0x20) | 0x50000000;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
}
