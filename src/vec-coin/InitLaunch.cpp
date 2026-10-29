typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void InitLo();

void InitLaunch(s8 *arg0) {
    s8 *temp_v0;
    s8 *temp_v1;

    InitLo();
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    temp_v1 = arg0 + 0x70;
    temp_v0 = arg0 + 0x90;
    M2C_FIELD(temp_v1, s32 *, 4) = 0;
    M2C_FIELD(temp_v1, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, f32 *, 0x84) = 3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    M2C_FIELD(temp_v0, f32 *, 4) = 1.0f;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(arg0, f32 *, 0xB0) = 0.5f;
    M2C_FIELD(arg0, f32 *, 0xA4) = 3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0xA0) = 0;
}

}
