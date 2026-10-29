typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern M2C_UNK D_002C4430;

s32 VIFS_AddUnpackCommand(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_a1;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;

    var_t1 = arg1;
    if (var_t1 >= 0x10) {
        var_t1 &= 0xF;
        var_t0 = 0x60008000;
    } else {
        var_t0 = 0x6000C000;
    }
    var_t0_2 = var_t0 | (var_t1 << 0x18) | (arg2 << 0x10) | arg3;
    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        var_t0_2 |= 0x10000000;
    }
    temp_a1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a1 + 4);
    *temp_a1 = var_t0_2;
    return *((var_t1 * 4) + &D_002C4430) * arg2;
}

}
