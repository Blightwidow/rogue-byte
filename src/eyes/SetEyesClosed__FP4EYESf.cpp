typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetEyesClosed__FP4EYESf {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK SetEyesEyess__FP4EYES5EYESS(...); /* extern */
M2C_UNK SetSaiIframe(s8 *, s32);                  /* extern */
void SetEyesClosed__FP4EYESf(s8 *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x78) = fparg0;
    if (fparg0 >= 1.0f) {
        SetEyesEyess__FP4EYES5EYESS(arg0, 2);
    } else {
        M2C_FIELD(arg0, s32 *, 0x64) = -1;
        SetEyesEyess__FP4EYES5EYESS(arg0, 0);
    }
    SetSaiIframe(arg0, (s32) M2C_FIELD(arg0, f32 *, 0x74));
}
}
