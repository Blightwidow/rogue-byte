typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s8 *B_003E159C;

s8 *PsaaFromOid(s32 arg0) {
    s8 *var_v0;
    s8 *var_v1;

    if (arg0 == -1) {
        goto block_9;
    }
    var_v1 = B_003E159C;
loop_5:
    var_v0 = NULL;
    if (var_v1 != NULL) {
        if (M2C_FIELD(var_v1, s32 *, 0x30) == 0) {
            var_v0 = var_v1;
            if (M2C_FIELD(var_v1, s32 *, 0x14) != arg0) {
                var_v1 = M2C_FIELD(var_v1, s8 **, 0x40);
                goto loop_5;
            }
        } else {
block_9:
            var_v0 = NULL;
        }
    }
    return var_v0;
}

}
