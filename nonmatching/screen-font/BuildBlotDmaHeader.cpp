typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildBlotDmaHeader {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
void CopyAqw__FPvT0i(s64 *, M2C_UNK *, M2C_UNK);
s32 *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK B_002DF010;
extern M2C_UNK B_00442210;
extern M2C_UNK g_2dea28;
void BuildBlotDmaHeader(s8 *arg0) {
    s32 temp_a0;
    s64 *temp_s2;
    s64 *temp_v0;
    s64 *temp_v0_2;
    s64 *temp_v0_3;
    s64 *temp_v0_4;
    s64 *temp_v0_5;
    s64 *temp_v1;
    s64 *temp_v1_2;
    s64 *temp_v1_3;
    s64 *var_a0;
    s8 *temp_v0_6;
    temp_s2 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(temp_s2, s64 *, 0) = 0x10000000;
    temp_v1 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_v1 + 0x10);
    M2C_FIELD(temp_v1, s32 *, 0x10) = 0x11000000;
    temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
    if (((s32) temp_v0 & 0xF) != 0xC) {
        do {
            M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0;
            temp_v1_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v1_2;
        } while (((s32) temp_v1_2 & 0xF) != 0xC);
    }
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x50000003;
    temp_v0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_2;
    CopyAqw__FPvT0i(temp_v0_2, &B_00442210, 3);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x30);
    var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    if (((s32) var_a0 & 0xF) != 0xC) {
        do {
            *var_a0 = 0;
            temp_v0_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_a0 = temp_v0_3;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_3;
        } while (((s32) var_a0 & 0xF) != 0xC);
    }
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x50000025;
    temp_v0_4 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_4;
    CopyAqw__FPvT0i(temp_v0_4, &B_002DF010, 0x25);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x250);
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x11000000;
    temp_v0_5 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0_5;
    if ((s32) temp_v0_5 & 0xF) {
        do {
            M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0;
            temp_v1_3 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v1_3;
        } while ((s32) temp_v1_3 & 0xF);
    }
    temp_a0 = M2C_FIELD(temp_s2, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_s2) >> 4) - 1);
    M2C_FIELD(temp_s2, s32 *, 0) = temp_a0;
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x60000000;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
    temp_v0_6 = (s8 *)(OnGameLoad__FP4GAME(temp_a0, &g_2dea28, 0x60000000));
    M2C_FIELD(temp_v0_6, s32 *, 0) = 0x15;
    M2C_FIELD(temp_v0_6, s32 *, 8) = (s32) ((s32) temp_s2 & 0x0FFFFFFF);
    M2C_FIELD(temp_v0_6, s32 *, 0xC) = 0;
    M2C_FIELD(temp_v0_6, f32 *, 4) = (f32) (M2C_FIELD(arg0, s32 *, 0xA4) << 0x12);
}
}
