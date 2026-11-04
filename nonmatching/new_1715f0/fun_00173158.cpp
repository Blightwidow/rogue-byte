typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK InitLo();                                   /* extern */

void func_00173158(s8 *arg0) {
    InitLo();
    M2C_FIELD(arg0, s32 *, 0x88) = 1;
    M2C_FIELD(arg0, f32 *, 0x80) = 5500.0f;
    M2C_FIELD(arg0, s32 *, 0x8C) = 1;
    M2C_FIELD(arg0, s32 *, 0x84) = 1;
    M2C_FIELD(arg0, f32 *, 0xA0) = 30.0f;
    M2C_FIELD(arg0, f32 *, 0xA4) = 50.0f;
}

}
