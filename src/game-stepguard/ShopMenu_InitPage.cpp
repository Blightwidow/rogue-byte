typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern f32 g_2ddf0c;

void ShopMenu_InitPage(s8 *arg0) {
    u32 var_a2;
    s8 *var_a1;

    M2C_FIELD(arg0, s32 *, 0x40) = -1;
    var_a1 = arg0 + 0x50;
    var_a2 = 0;
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2ddf0c;
    M2C_FIELD(arg0, s32 *, 0x25C) = -1;
    M2C_FIELD(arg0, s32 *, 0x260) = -1;
    M2C_FIELD(arg0, s32 *, 0x264) = -1;
    do {
        M2C_FIELD(var_a1, s32 *, -4) = -1;
        var_a2 += 1;
        M2C_FIELD(var_a1, s32 *, 0) = -1;
        var_a1 += 8;
    } while (var_a2 < 0x40U);
}

}
