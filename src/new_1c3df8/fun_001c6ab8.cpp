typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 InitDprize();                               /* extern */

void func_001C6AB8(s8 *arg0) {
    InitDprize();
    M2C_FIELD(arg0, f32 *, 0x1D8) = 35.0f;
    M2C_FIELD(arg0, f32 *, 0x1DC) = 35.0f;
    M2C_FIELD(arg0, f32 *, 0x1E4) = 0.6f;
    M2C_FIELD(arg0, f32 *, 0x1D0) = 500.0f;
    M2C_FIELD(arg0, f32 *, 0x1D4) = 250.0f;
    M2C_FIELD(arg0, f32 *, 0x1E0) = 0.6f;
    M2C_FIELD(arg0, f32 *, 0x1A0) = 0.75f;
}

}
