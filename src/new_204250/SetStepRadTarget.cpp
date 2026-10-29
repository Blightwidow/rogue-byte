typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetStepRadTarget {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0x20];
};                                                  /* size = 0x50 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp20 (*(s128 *)(sp + 0x20))
M2C_UNK LoadRotateMatrixRad(s8 *, s128);          /* extern */
extern s128 g_2a2dc0;
void SetStepRadTarget(s8 *arg0, f32 fparg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_FIELD(arg0, f32 *, 0x1A8) = fparg0;
    LoadRotateMatrixRad(sp, g_2a2dc0);
    M2C_FIELD(arg0, s128 *, 0x1B0) = sp0;
    M2C_FIELD(arg0, s128 *, 0x1C0) = sp10;
    M2C_FIELD(arg0, s128 *, 0x1D0) = sp20;
}
}
