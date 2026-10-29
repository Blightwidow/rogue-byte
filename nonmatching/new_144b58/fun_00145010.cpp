typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001EEF68();                            /* extern */

void func_00145010(s8 *arg0) {
    func_001EEF68();
    M2C_FIELD(arg0, s32 *, 0x60) = -1;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.25f;
    M2C_FIELD(arg0, f32 *, 0x78) = 1.2f;
    M2C_FIELD(arg0, f32 *, 0x70) = 350.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x6C) = 250.0f;
}

}
