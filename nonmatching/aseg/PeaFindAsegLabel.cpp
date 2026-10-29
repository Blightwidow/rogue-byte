typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PeaFindAsegLabel(s8 *arg0, s32 arg1) {
    s8 * result;
    s32 temp_v1;
    s32 var_a2;
    s8 *var_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xA0);
    var_a2 = 0;
    if (temp_v1 > 0) {
        var_a0 = M2C_FIELD(arg0, s8 **, 0xA4);
loop_2:
        var_a2 += 1;
        if ((((M2C_FIELD(var_a0, s32 *, 4) ^ 0xB) != 0) ? 0 : (M2C_FIELD(var_a0, s32 *, 8) == arg1)) != 0) {
            { result = var_a0; goto done; }
        }
        var_a0 += 0x10;
        if (var_a2 >= temp_v1) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            { result = NULL; goto done; }
        }
        goto loop_2;
    }
    return NULL;
done:
    return result;
}

}
