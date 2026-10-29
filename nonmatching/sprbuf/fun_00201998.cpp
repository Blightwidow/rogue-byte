typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_002417F0(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK B_003DD2C0;
extern s32 g_2c3c5c;
extern s32 g_2de5a0;

void func_00201998(void) {
    s32 temp_v1;

    func_002417F0(g_2de5a0, 0, 0);
    temp_v1 = 1 - g_2c3c5c;
    g_2c3c5c = temp_v1;
    M2C_FIELD((&B_003DD2C0 + (temp_v1 * 0x50)), s32 *, 0x4C) = 2;
}

}
