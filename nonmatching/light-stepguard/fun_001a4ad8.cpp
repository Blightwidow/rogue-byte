typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A4AD8 {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
void RebuildLight(s32, s32, s32 *, s32);
extern M2C_UNK D_002BFC60;
extern M2C_UNK g_2dea28;
void func_001A4AD8(s32 arg1, s32 *arg2, s8 *arg3) {
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
    s8 *temp_s5;
    s8 *var_a3;
    s8 *var_s0;
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
            var_s0 = (s8 *)(temp_s0 + 0x120);
            *M2C_FIELD(&g_2dea28, s32 **, 0xC) = ((var_s1 * 3) + 0x15) | 0x6C03C000;
            temp_v1 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2 = temp_v1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1;
            var_a3 = (s8 *)8;
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
}
