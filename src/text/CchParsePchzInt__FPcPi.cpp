typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 CchParsePchzInt__FPcPi(u8 *arg0, s32 *arg1) {
    s32 temp_t0;
    s32 var_a0;
    s32 var_a3;
    u8 *var_a2;
    u8 temp_a0;

    var_a2 = arg0;
    var_a0 = 0;
    temp_t0 = ((*var_a2 ^ 0x2D) == 0) ? -1 : 1;
    var_a3 = 0;
    if (temp_t0 == -1) {
        var_a2 += 1;
        var_a3 = 1;
    }
    if ((u32) (*var_a2 - 0x30) < 0xAU) {
        do {
            var_a3 += 1;
            var_a0 = var_a0 * 0xA + (*var_a2++ - 0x30);
        } while ((u32) (*var_a2 - 0x30) < 0xAU);
    }
    *arg1 = var_a0 * temp_t0;
    return var_a3;
}

}
