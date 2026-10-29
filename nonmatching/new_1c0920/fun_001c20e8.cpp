typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

void func_001C20E8(s8 *arg0, s32 arg1) {
    u32 temp_v1;
    s8 *temp_s1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0x50);
    if (temp_v1 < 6U) {
        M2C_FIELD(arg0, u32 *, 0x50) = (u32) (temp_v1 + 1);
        temp_s1 = arg0 + ((temp_v1 << 5) + 0x60);
        if (FIsBasicDerivedFrom(arg1, 0xA) == 0) {
            M2C_FIELD(temp_s1, s32 *, 4) = arg1;
            return;
        }
        M2C_FIELD(temp_s1, s32 *, 0) = arg1;
    }
}

}
