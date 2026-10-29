typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PgFindCrvExcludedRange(s8 *arg0, f32 fparg0) {
    s32 temp_a1;
    s32 var_v0;
    s32 var_v1;
    s8 *var_a0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xC);
    var_v1 = 0;
    if (temp_a1 > 0) {
        var_a0 = arg0 + 0x10;
loop_2:
        var_v1 += 1;
        if (M2C_FIELD(var_a0, f32 *, 0) <= fparg0) {
            var_v0 = var_v1 < temp_a1;
            if (fparg0 <= M2C_FIELD(var_a0, f32 *, 4)) {
                return var_a0;
            }
            goto block_6;
        }
        var_v0 = var_v1 < temp_a1;
block_6:
        var_a0 += 8;
        if (var_v0 == 0) {
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}

}
