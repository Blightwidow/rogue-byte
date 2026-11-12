typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023F2D8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 func_0023F2D8(s8 *arg0, s8 *arg1) {
    s32 *var_a2;
    s32 *var_t0;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_t8;
    s32 temp_t9;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_t1;
    s32 var_t2;
    s32 var_t5;
    s8 **var_a1;
    s8 **var_a3;
    s8 **var_t3;
    s8 *temp_t6;
    var_t5 = temp_t8;
    temp_t8 = M2C_FIELD(arg1, s32 *, 4);
    if (temp_t8 != 0) {
        temp_s0 = M2C_FIELD(arg0, s32 *, 4);
        temp_a0 = temp_t8 * 4;
        temp_t9 = M2C_FIELD(arg0, s32 *, 0);
        temp_v0 = (temp_s0 * 4) - 4;
        var_a1 = (s8 **)(temp_a0 + M2C_FIELD(arg1, s32 *, 0));
        var_t2 = temp_v0;
        var_a0 = temp_a0 + temp_t9;
        var_t1 = temp_s0;
        var_t3 = (s8 **)(temp_v0 + temp_t9);
        do {
            var_a1 -= 4;
            var_a0 -= 4;
            temp_t6 = *var_a1;
            var_t5 -= 1;
            if (var_t1 != 0) {
                temp_a2 = M2C_FIELD(temp_t6, s32 *, 8);
                if ((M2C_FIELD(*var_t3, s32 *, 8) - temp_a2) > 0) {
                    var_t0 = (s32 *)((var_t1 * 4) + var_a0);
                    var_a3 = (s8 **)(var_t2 + temp_t9);
                    var_a2 = (s32 *)(var_t2 + temp_t9);
loop_5:
                    temp_v0_2 = *var_a2;
                    var_a3 -= 4;
                    var_a2 -= 4;
                    var_t3 -= 4;
                    *var_t0 = temp_v0_2;
                    var_t2 -= 4;
                    var_t1 -= 1;
                    var_t0 -= 4;
                    if (var_t1 != 0) {
                        if ((M2C_FIELD(*var_a3, s32 *, 8) - temp_a2) > 0) {
                            goto loop_5;
                        }
                    }
                }
            }
            *(s32 *)(((var_t1 + var_t5) * 4) + temp_t9) = (int)(temp_t6);
        } while (var_t5 != 0);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_s0 + temp_t8);
    }
    return temp_t8;
}
}
