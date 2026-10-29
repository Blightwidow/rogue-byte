typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void func_001F8BF0(s8 *arg0, s32 arg1, s128 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    s8 *temp_a0;
    s8 *temp_v0;

    temp_a0 = M2C_FIELD(arg0, s8 **, 0x24);
    if (M2C_FIELD(temp_a0, s16 *, 0x98) == 0x10) {
        f32 angle = fparg3 * 0.017453294f;
        temp_v0 = M2C_FIELD(M2C_FIELD(temp_a0, s8 **, 0xA8), s8 **, 0x60);
        M2C_FIELD(temp_v0, s32 *, 8) = arg1;
        M2C_FIELD(temp_v0, f32 *, 0xC) = fparg0;
        M2C_FIELD(temp_v0, f32 *, 0x10) = fparg1;
        M2C_FIELD(temp_v0, f32 *, 0x14) = fparg2;
        M2C_FIELD(temp_v0, f32 *, 0x18) = angle;
        M2C_FIELD(temp_v0, s128 *, 0x20) = arg2;
    }
}

}
