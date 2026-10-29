typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s128 D_002C1F50;
extern M2C_UNK RO_002A2D00;
extern f32 g_2dded0;

void InitRip__FP3RIPP6VECTORfP2SO(s8 *arg0, s128 arg1, s32 arg2, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) g_2dded0;
    M2C_FIELD(arg0, f32 *, 0x18) = 1.0f;
    M2C_FIELD(arg0, s32 *, 0xE0) = arg2;
    M2C_FIELD(arg0, f32 *, 0x20) = fparg0;
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) D_002C1F50;
    M2C_FIELD(arg0, s128 *, 0x80) = arg1;
    M2C_FIELD(arg0, s128 *, 0x70) = arg1;
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0x20);
}

}
