typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_DrawMovieShapeCharacter {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
s8 *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK, s8 *); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK g_2dea28;
void DrawMovieShapeCharacter(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg3) {
    s8 sp[0x50] __attribute__((aligned(16)));
    f32 temp_f1;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_f1_2;
    s32 temp_v1;
    s32 temp_v1_2;
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
    s8 *temp_v0_4;
    s8 *var_a3;
    s8 *var_a3_2;
    memset(sp, 0, 0x40);
    if ((u16) M2C_FIELD(arg0, u16 *, 0x12) >= 2U) {
        M2C_FIELD(arg2, s32 *, 4) = 1;
    } else {
        M2C_FIELD(arg2, s32 *, 4) = 0;
    }
    M2C_FIELD(arg2, s32 *, 0xC) = 0x7FFF;
    if (arg3 != 0) {
        temp_f1 = M2C_FIELD(arg2, f32 *, 0x2C);
        M2C_FIELD(arg2, f32 *, 0x2C) = 1.0f;
        if (temp_f1 < 1.0f) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x14);
            temp_f1_2 = (s32) ((f32) temp_v1 * temp_f1);
            temp_v1_2 = (temp_f1_2 < temp_v1) ? temp_f1_2 : temp_v1;
            temp_a1 = (temp_v1_2 > 2) ? temp_v1_2 : 3;
            M2C_FIELD(arg2, s32 *, 0xC) = temp_a1;
            if ((u32) temp_a1 > 0x7FFFU) {
                M2C_FIELD(arg2, s32 *, 0xC) = 0x7FFF;
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
    M2C_FIELD(temp_v0_4, f32 *, 4) = (f32) (M2C_FIELD(arg2, f32 *, 8) + (f32) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 0xA4) << 0x12));
    M2C_FIELD(temp_v0_4, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
}
}
