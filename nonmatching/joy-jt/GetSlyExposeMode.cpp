typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_001409B8();                                /* extern */

s32 GetSlyExposeMode(s8 *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_001409B8();
    var_v0 = temp_v0;
    if (temp_v0 == -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x18C8);
        if (temp_a0 < 7) {
            if ((temp_a0 < 5) && (temp_a0 != 1)) {
                return -1;
            }
            goto block_6;
        }
        var_v0 = -1;
        if (temp_a0 == 9) {
block_6:
            var_v0 = 1;
        }
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

}
