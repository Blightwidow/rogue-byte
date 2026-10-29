typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK InitRip__FP3RIPP6VECTORfP2SO();             /* extern */
extern s128 D_002BBB50;

void InitMatch__FP5MATCHP6VECTORfP2SO(s8 *arg0, f32 fparg0) {
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) D_002BBB50;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, f32 *, 0x20) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (1.0f - fparg0);
}

}
