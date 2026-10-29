typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0019B0A8 {};                 /* size 0x0 */
s32 func_0019B0A8(s8 *arg0, s8 *arg1) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_v1;
    s8 *temp_a1;
    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000L << 0x21))) {
        temp_a1 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s8 **, 0xEC);
        if (!(M2C_FIELD(temp_a1, s64 *, 0x70) & 4)) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0);
            var_v1 = 0;
            if (temp_v0 > 0) {
                var_a0 = M2C_FIELD(arg0, s32 **, 4);
loop_7:
                var_v1 += 1;
                if ((s32)temp_a1 != *var_a0) {
                    var_a0 += 4;
                    if (var_v1 >= temp_v0) {
                        /* Duplicate return node #9. Try simplifying control flow for better match */
                        return 1;
                    }
                    goto loop_7;
                }
                /* Duplicate return node #4. Try simplifying control flow for better match */
                return 0;
            }
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
}
