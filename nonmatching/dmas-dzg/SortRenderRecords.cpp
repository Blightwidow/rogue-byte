typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SortRenderRecords {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0xB8];
};                                                  /* size = 0xC0 */
void qsort(...);
extern M2C_UNK func_00157A50;
extern M2C_UNK func_00157A98;
s32 SortRenderRecords(s32 arg0, s32 *arg1, s32 arg2, s8 *arg3, s8 *arg4) {
    s8 sp[0x60] __attribute__((aligned(16)));
    s32 sp4;
    s32 *temp_a0;
    s32 *temp_v1_2;
    s32 *var_a1;
    s32 *var_a3;
    s32 *var_a3_2;
    s32 *var_a5;
    s32 *var_v0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a2;
    s32 var_a2_3;
    s32 var_a4;
    s32 var_a4_2;
    s8 *var_a2_2;
    var_a1 = arg1;
    var_a4 = 0x19;
    var_v0 = (s32 *)(arg4 + 0x64);
    do {
        *var_v0 = 0;
        var_a4 -= 1;
        var_v0 -= 4;
    } while (var_a4 >= 0);
    var_a3 = var_a1;
    if (arg0 > 0) {
        var_a2 = arg0;
        do {
            temp_v1 = *var_a3;
            var_a2 -= 1;
            var_a3 += 0x10;
            temp_v1_2 = (s32 *)((temp_v1 * 4) + arg4);
            *temp_v1_2 += 1;
        } while (var_a2 != 0);
    }
    M2C_FIELD(arg3, s32 *, 0) = 0;
    var_a5 = &sp4;
    var_a2_2 = arg4 + 4;
    var_a3_2 = (s32 *)(arg3 + 4);
    var_a4_2 = 0x18;
    do {
        temp_v0 = M2C_FIELD(var_a2_2, s32 *, -4);
        var_a4_2 -= 1;
        *var_a3_2 = temp_v0;
        M2C_FIELD(var_a2_2, s32 *, 0) = (s32) (M2C_FIELD(var_a2_2, s32 *, 0) + temp_v0);
        var_a2_2 += 4;
        temp_v0_2 = *var_a3_2;
        var_a3_2 += 4;
        *var_a5 = temp_v0_2;
        var_a5 += 4;
    } while (var_a4_2 >= 0);
    var_a2_3 = arg0;
    if (arg0 > 0) {
        do {
            var_a2_3 -= 1;
            temp_a0 = (s32 *)(sp + (*var_a1 * 4));
            temp_v1_3 = *temp_a0;
            *(s32 *)((temp_v1_3 * 4) + arg2) = (int)(var_a1);
            *temp_a0 = temp_v1_3 + 1;
            var_a1 += 0x10;
        } while (var_a2_3 != 0);
    }
    temp_v0_3 = M2C_FIELD(arg3, s32 *, 0x14);
    qsort(arg2 + (temp_v0_3 * 4), M2C_FIELD(arg4, s32 *, 0x14) - temp_v0_3, 4, &func_00157A50, var_a4_2, var_a5);
    temp_v0_4 = M2C_FIELD(arg3, s32 *, 0x18);
    qsort(arg2 + (temp_v0_4 * 4), M2C_FIELD(arg4, s32 *, 0x18) - temp_v0_4, 4, &func_00157A50);
    temp_v0_5 = M2C_FIELD(arg3, s32 *, 0x28);
    qsort(arg2 + (temp_v0_5 * 4), M2C_FIELD(arg4, s32 *, 0x28) - temp_v0_5, 4, &func_00157A50);
    temp_v0_6 = M2C_FIELD(arg3, s32 *, 4);
    qsort(arg2 + (temp_v0_6 * 4), M2C_FIELD(arg4, s32 *, 4) - temp_v0_6, 4, &func_00157A50);
    temp_v0_7 = M2C_FIELD(arg3, s32 *, 8);
    qsort(arg2 + (temp_v0_7 * 4), M2C_FIELD(arg4, s32 *, 8) - temp_v0_7, 4, &func_00157A50);
    temp_v0_8 = M2C_FIELD(arg3, s32 *, 0x64);
    qsort(arg2 + (temp_v0_8 * 4), M2C_FIELD(arg4, s32 *, 0x64) - temp_v0_8, 4, &func_00157A50);
    temp_v0_9 = M2C_FIELD(arg3, s32 *, 0x54);
    qsort(arg2 + (temp_v0_9 * 4), M2C_FIELD(arg4, s32 *, 0x54) - temp_v0_9, 4, &func_00157A98);
    return M2C_FIELD(arg4, s32 *, 0x64);
}
}
