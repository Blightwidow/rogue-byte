typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FActiveCplcy(M2C_UNK *);                        /* extern */
extern M2C_UNK B_002DE2E0;
extern s32 g_2dfbc0;

s32 func_0019EEF0(s8 **arg0, s32 arg1) {
    s32 var_a0;

    if (arg1 == 3) {
        var_a0 = 0;
        if (M2C_FIELD(*arg0, s32 *, 0x12F0) != 0) {
            if (!(g_2dfbc0 & 2)) {
                return 0;
            }
            var_a0 = FActiveCplcy(&B_002DE2E0) == 0;
            goto block_6;
        }
block_6:
        return var_a0;
    }
    return 0;
}

}
