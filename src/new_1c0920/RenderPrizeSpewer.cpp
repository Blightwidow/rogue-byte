typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001A5EE8(s32, s32, f32, f32);  /* extern */
M2C_UNK func_001F3C70();                            /* extern */

void RenderPrizeSpewer(s8 *arg0) {
    s32 temp_a0;

    func_001F3C70();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x158);
    if (temp_a0 != 0) {
        func_001A5EE8(temp_a0, M2C_FIELD(arg0, s32 *, 0x150) + 0x40, 1.0f, 1.0f);
    }
}

}
