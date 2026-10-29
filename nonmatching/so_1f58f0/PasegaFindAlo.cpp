typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s8 *B_003E1218;

s8 *PasegaFindAlo(s32 arg0, s32 arg1) {
    s8 *var_a2;
    s8 *var_v0;

    var_a2 = B_003E1218;
    if (var_a2 != NULL) {
loop_2:
        if (M2C_FIELD(var_a2, s32 *, 0x18) != arg0) {
            var_a2 = M2C_FIELD(var_a2, s8 **, 0x24);
            goto block_10;
        }
        var_v0 = var_a2;
        if (arg1 != -1) {
            if (M2C_FIELD(M2C_FIELD(var_a2, s8 **, 0x14), s32 *, 0x18) != arg1) {
                var_a2 = M2C_FIELD(var_a2, s8 **, 0x24);
block_10:
                if (var_a2 == NULL) {
                    goto block_11;
                }
                goto loop_2;
            }
            return var_a2;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return var_v0;
    }
block_11:
    var_v0 = NULL;
    return var_v0;
}

}
