typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_001B0078();                                /* extern */

s32 func_001B0108(void) {
    s32 result;
    s32 temp_v0;

    temp_v0 = func_001B0078();
    if (temp_v0 != 0x19) {
        if (temp_v0 >= 0x19) {
            if (temp_v0 < 0x20) {
                if (temp_v0 >= 0x1E) {
                    goto block_4;
                }
                /* Duplicate return node #6. Try simplifying control flow for better match */
                { result = 0; goto done; }
            }
            /* Duplicate return node #6. Try simplifying control flow for better match */
            { result = 0; goto done; }
        }
        return 0;
    }
block_4:
    return 1;
done:
    return result;
}

}
