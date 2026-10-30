typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PloFindSpawn {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
s32 CploFindSwObjectsByClass(s32, M2C_UNK, M2C_UNK, s32, M2C_UNK, s8 *); /* extern */
s32 PloFindSwObject_thunk(M2C_UNK, M2C_UNK);        /* extern */
s8 *PloFindSpawn(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK var_s0_2;
    s32 *var_a0;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_v1;
    s8 *var_s0;
    var_a3 = 0;
    var_s0_2 = 5;
    if (arg2 != -1) {
        var_a3 = PloFindSwObject_thunk(5, 0);
        var_s0_2 = (var_a3 != 0) ? 1 : 5;
    }
    var_s0 = NULL;
    temp_v0 = CploFindSwObjectsByClass(arg0, var_s0_2, 0x2A, var_a3, 0x20, sp);
    var_v1 = 0;
    if (temp_v0 > 0) {
        var_v0 = 0 * 4;
        do {
            temp_v1 = (s8 *)(*(sp + var_v0));
            if (M2C_FIELD(temp_v1, s32 *, 0x18) != arg1) {
                temp_a2 = M2C_FIELD(temp_v1, s32 *, 0x16C);
                var_a1 = 0;
                if (temp_a2 > 0) {
                    var_a0 = (s32 *)(temp_v1 + 0x170);
loop_7:
                    var_a1 += 1;
                    if (*var_a0 != arg1) {
                        var_a0 += 4;
                        if (var_a1 >= temp_a2) {
                        } else {
                            goto loop_7;
                        }
                    } else {
                        goto block_10;
                    }
                }
            } else {
block_10:
                var_s0 = temp_v1;
            }
            var_v1 += 1;
            var_v0 = var_v1 * 4;
        } while (var_v1 < temp_v0);
    }
    return var_s0;
}
}
