typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s128 D_002BF740;

void InitJmp(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s128 *, 0xF0) = (s128) D_002BF740;
    M2C_FIELD(arg0, f32 *, 0x164) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x108) = -60.0f;
    M2C_FIELD(arg0, f32 *, 0x10C) = -50.0f;
    M2C_FIELD(arg0, f32 *, 0x114) = 50.0f;
    M2C_FIELD(arg0, f32 *, 0x118) = -150.0f;
    M2C_FIELD(arg0, f32 *, 0x110) = 75.0f;
    M2C_FIELD(arg0, f32 *, 0x11C) = 75.0f;
}

}
