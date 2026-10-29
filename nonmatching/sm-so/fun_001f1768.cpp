typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void func_001F1768(s8 *arg0, s32 arg1) {
    s32 temp_v1;
    s8 *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x490) != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x484);
        M2C_FIELD(arg0, s32 *, 0x484) = (s32) (temp_v1 + 1);
        temp_v0 = arg0 + ((temp_v1 * 0x10) + 0x404);
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg1;
        M2C_FIELD(temp_v0, s32 *, 0) = 0x2B3;
        M2C_FIELD(temp_v0, s32 *, 8) = -1;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
    }
}

}
