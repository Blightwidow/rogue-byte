#include "m2c_macros.h"

void *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK, void *); /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK g_2dea28;

void DrawMovieShapeCharacter(void *arg0, void *arg1, void *arg2, s32 arg3) {
    char sp[0x400];
    f32 temp_a1;
    f32 temp_f1;
    f32 temp_v1_2;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_t0;
    s32 var_t0_2;
    s64 *temp_a0;
    s64 *temp_s0;
    s64 *temp_v0;
    s64 *temp_v0_2;
    s64 *temp_v0_3;
    s64 *var_a0;
    s64 *var_a2;
    s64 *var_a2_2;
    void *temp_v0_4;
    void *var_a3;
    void *var_a3_2;

    memset(sp, 0, 0x40);
    if ((u16) M2C_FIELD(arg0, u16 *, 0x12) >= 2U) {
        M2C_FIELD(arg2, s32 *, 4) = 1;
    } else {
        M2C_FIELD(arg2, s32 *, 4) = 0;
    }
    M2C_FIELD(arg2, f32 *, 0xC) = 4.5916e-41f;
    if (arg3 != 0) {
        temp_f1 = M2C_FIELD(arg2, f32 *, 0x2C);
        M2C_FIELD(arg2, f32 *, 0x2C) = 1.0f;
        if (temp_f1 < 1.0f) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x14);
            temp_v1_2 = (M2C_BITWISE(s32, temp_f1) < temp_v1) ? temp_f1 : M2C_BITWISE(f32, temp_v1);
            temp_a1 = (M2C_BITWISE(s32, temp_v1_2) > 2) ? temp_v1_2 : 4e-45f;
            M2C_FIELD(arg2, f32 *, 0xC) = temp_a1;
            if (M2C_BITWISE(u32, temp_a1) > 0x7FFFU) {
                M2C_FIELD(arg2, f32 *, 0xC) = 4.5916e-41f;
            }
        }
    }
    temp_s0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    var_a3 = sp;
    M2C_FIELD(temp_s0, s64 *, 0) = 0x10000000;
    temp_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_a0 + 0x10);
    M2C_FIELD(temp_a0, s32 *, 0x10) = 0x6C04C000;
    temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    var_a2 = temp_v0;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
    var_t0 = 0xC;
    do {
        var_t0 -= 4;
        temp_v1_3 = M2C_FIELD(var_a3, s32 *, 4);
        temp_a0_2 = M2C_FIELD(var_a3, s32 *, 8);
        temp_a1_2 = M2C_FIELD(var_a3, s32 *, 0xC);
        M2C_FIELD(var_a2, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
        var_a3 += 0x10;
        M2C_FIELD(var_a2, s32 *, 4) = temp_v1_3;
        M2C_FIELD(var_a2, s32 *, 8) = temp_a0_2;
        M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1_2;
        var_a2 += 0x10;
    } while (var_t0 >= 0);
    var_a3_2 = arg2;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x40);
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x6C03C004;
    temp_v0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    var_a2_2 = temp_v0_2;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_2;
    var_t0_2 = 8;
    do {
        var_t0_2 -= 4;
        temp_v1_4 = M2C_FIELD(var_a3_2, s32 *, 4);
        temp_a0_3 = M2C_FIELD(var_a3_2, s32 *, 8);
        temp_a1_3 = M2C_FIELD(var_a3_2, s32 *, 0xC);
        M2C_FIELD(var_a2_2, s32 *, 0) = (s32) M2C_FIELD(var_a3_2, s32 *, 0);
        var_a3_2 += 0x10;
        M2C_FIELD(var_a2_2, s32 *, 4) = temp_v1_4;
        M2C_FIELD(var_a2_2, s32 *, 8) = temp_a0_3;
        M2C_FIELD(var_a2_2, s32 *, 0xC) = temp_a1_3;
        var_a2_2 += 0x10;
    } while (var_t0_2 >= 0);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x30);
    var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    if ((s32) var_a0 & 0xF) {
        do {
            *var_a0 = 0;
            temp_v0_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_a0 = temp_v0_3;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_3;
        } while ((s32) var_a0 & 0xF);
    }
    temp_a0_4 = M2C_FIELD(temp_s0, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_s0) >> 4) - 1);
    M2C_FIELD(temp_s0, s32 *, 0) = temp_a0_4;
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x60000000;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
    temp_v0_4 = OnGameLoad__FP4GAME(temp_a0_4, &g_2dea28, 0x60000000, var_a3_2);
    M2C_FIELD(temp_v0_4, s32 *, 0) = 0x15;
    M2C_FIELD(temp_v0_4, s32 *, 8) = (s32) ((s32) temp_s0 & 0x0FFFFFFF);
    M2C_FIELD(temp_v0_4, f32 *, 4) = (f32) (M2C_FIELD(arg2, f32 *, 8) + (f32) (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xA4) << 0x12));
    M2C_FIELD(temp_v0_4, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
}
