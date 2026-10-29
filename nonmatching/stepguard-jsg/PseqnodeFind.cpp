typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PseqnodeFind {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s8 *PseqnodeFind(s8 *arg0, s32 arg1, s32 arg2) {
    s8 *var_a0;
    var_a0 = M2C_FIELD(arg0, s8 **, 0x5C);
    if (var_a0 != NULL) {
loop_2:
        if ((s32)var_a0 == arg2) {
            var_a0 = M2C_FIELD(var_a0, s8 **, 0xE4);
            goto block_9;
        }
        if (M2C_FIELD(M2C_FIELD(var_a0, s8 **, 0x28), s32 *, 0x10) != arg1) {
            var_a0 = M2C_FIELD(var_a0, s8 **, 0xE4);
block_9:
            if (var_a0 == NULL) {
                goto block_10;
            }
            goto loop_2;
        }
        return var_a0;
    }
block_10:
    return NULL;
}
}
