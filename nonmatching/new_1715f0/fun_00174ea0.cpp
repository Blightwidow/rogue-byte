typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_001EEFA0(s8 *);                          /* extern */

s32 func_00174EA0(s8 *arg0) {
    s32 result;
    s32 temp_v1;
    s32 var_v0;
    s8 *temp_a1;

    temp_a1 = M2C_FIELD(arg0, s8 **, 0x40);
    if (M2C_FIELD(temp_a1, s32 *, 0) == 2) {
        temp_v1 = M2C_FIELD(M2C_FIELD(temp_a1, s8 **, 8), s32 *, 0x10);
        var_v0 = 7;
        if (temp_v1 != 0) {
            if ((temp_v1 >= 0) && (temp_v1 < 5)) {
                var_v0 = 1;
                if (temp_v1 >= 3) {
                    return 7;
                }
                /* Duplicate return node #8. Try simplifying control flow for better match */
                { result = var_v0; goto done; }
            }
            { result = 1; goto done; }
        }
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = func_001EEFA0(arg0);
    { result = var_v0; goto done; }
done:
    return result;
}

}
