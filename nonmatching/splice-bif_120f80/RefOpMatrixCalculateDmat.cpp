typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpMatrixCalculateDmat {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x38];
};                                                  /* size = 0x40 */
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK CalculateDmat4(s32, s32, s32);              /* extern */
M2C_UNK SetTag__4CRef4TAGK(s8 *, M2C_UNK);        /* extern */
s32 RefOpMatrixCalculateDmat(s32 arg0, s8 *arg2) {
    s8 sp[0x40] __attribute__((aligned(16)));
    SetTag__4CRef4TAGK(sp, 0x1B);
    CalculateDmat4(M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC), sp4);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
