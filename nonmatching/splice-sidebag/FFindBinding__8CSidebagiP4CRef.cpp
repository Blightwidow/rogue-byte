typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK __as__4CRefRC4CRef(s32, s8 *);            /* extern */

s32 FFindBinding__8CSidebagiP4CRef(s8 *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s8 *var_v1;

    var_v1 = M2C_FIELD(arg0, s8 **, 8);
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, s32 *, 8) != arg1) {
            var_v1 = M2C_FIELD(var_v1, s8 **, 0x14);
            if (var_v1 == NULL) {
                goto block_7;
            }
            goto loop_1;
        }
        var_v0 = 1;
        if (arg2 != 0) {
            __as__4CRefRC4CRef(arg2, var_v1 + 0xC);
            return 1;
        }
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
block_7:
    var_v0 = 0;
    return var_v0;
}

}
