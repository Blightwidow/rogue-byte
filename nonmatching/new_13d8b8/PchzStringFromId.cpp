typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern M2C_UNK RO_002A4BE0;

M2C_UNK *PchzStringFromId(s8 *arg0, s32 arg1) {
    M2C_UNK * result;
    s32 *var_a0;
    s32 *var_v1;
    s32 temp_v0;
    s32 var_a2;

    if (arg1 != -1) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x4640);
        var_a2 = 0;
        if (temp_v0 > 0) {
            var_a0 = M2C_FIELD(arg0, s32 **, 0x4644);
            var_v1 = var_a0;
loop_7:
            var_a2 += 1;
            if (*var_v1 != arg1) {
                var_v1 += 8;
                var_a0 += 8;
                if (var_a2 >= temp_v0) {
                    /* Duplicate return node #9. Try simplifying control flow for better match */
                    { result = &RO_002A4BE0; goto done; }
                }
                goto loop_7;
            }
            return M2C_FIELD(var_a0, M2C_UNK **, 4);
        }
        { result = &RO_002A4BE0; goto done; }
    }
    return &RO_002A4BE0;
done:
    return result;
}

}
