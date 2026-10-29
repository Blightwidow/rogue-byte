typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitAseg__FP4ASEG {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK InitDl__FP2DLi(s32, M2C_UNK);               /* extern */
M2C_UNK InitLo();                                   /* extern */

void InitAseg__FP4ASEG(s8 *arg0) {
    s8 *temp_v0;

    InitLo();
    InitDl__FP2DLi((int)(arg0 + 0x50), 0x2C);
    temp_v0 = arg0 + 0x80;
    M2C_FIELD(arg0, f32 *, 0x78) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x80) = 1.0f;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(arg0, f32 *, 0x94) = 1.0f;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) | 0x40);
}

}
