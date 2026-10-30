typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0016C8E0 {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
M2C_UNK FilterColorRgba5551_1ed1a8(s8 *);         /* extern */
s8 *PvAllocStackClearImpl__Fi(s8 *, s32, s32);  /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
s8 *func_0016C8E0(s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s8 *temp_s0;
    s8 *temp_s5;
    s8 *var_s6;
    var_s6 = NULL;
    temp_v0 = U16Read__18CBinaryInputStream(arg1);
    if (temp_v0 != 0) {
        var_s1 = 0;
        var_s6 = PvAllocStackClearImpl__Fi(sp, 0xC, 0x10);
        M2C_FIELD(var_s6, s32 *, 0) = temp_v0;
        M2C_FIELD(var_s6, s8 **, 4) = PvAllocStackClearImpl__Fi(sp, temp_v0 * 8, 0x10);
        if (M2C_FIELD(var_s6, s32 *, 0) > 0) {
            do {
                temp_s5 = M2C_FIELD(var_s6, s8 **, 4) + (var_s1 * 8);
                temp_v0_2 = U16Read__18CBinaryInputStream(arg1);
                M2C_FIELD(temp_s5, s8 **, 4) = PvAllocStackClearImpl__Fi(sp, temp_v0_2 * 6, 0x10);
                if (temp_v0_2 > 0) {
                    var_s2 = temp_v0_2;
                    var_s3 = 0;
loop_5:
                    var_s2 -= 1;
                    temp_s0 = M2C_FIELD(temp_s5, s8 **, 4) + var_s3;
                    M2C_FIELD(temp_s0, s16 *, 0) = U16Read__18CBinaryInputStream(arg1);
                    var_s3 += 6;
                    M2C_FIELD(temp_s0, s16 *, 2) = U16Read__18CBinaryInputStream(arg1);
                    M2C_FIELD(temp_s0, s8 *, 4) = U8Read__18CBinaryInputStream(arg1);
                    FilterColorRgba5551_1ed1a8(temp_s0);
                    FilterColorRgba5551_1ed1a8(temp_s0 + 2);
                    if (var_s2 != 0) {
                        goto loop_5;
                    }
                }
                var_s1 += 1;
            } while (var_s1 < M2C_FIELD(var_s6, s32 *, 0));
        }
        var_s0 = 0;
        temp_v0_3 = U16Read__18CBinaryInputStream(arg1);
        M2C_FIELD(var_s6, s8 **, 8) = PvAllocStackClearImpl__Fi(sp, temp_v0_3 * 4, 0x10);
        if (temp_v0_3 > 0) {
            do {
                temp_a0 = var_s0 * 4;
                var_s0 += 1;
                *(temp_a0 + M2C_FIELD(var_s6, s8 **, 8)) = S16Read__18CBinaryInputStream(arg1);
            } while (var_s0 < temp_v0_3);
        }
    }
    return var_s6;
}
}
