typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PvFindSaveVar {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x28];
};                                                  /* size = 0x30 */
#define sp0 (*(s8 * *)(sp + 0x00))
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK FFindSaveVar(s8 *);                       /* extern */
extern M2C_UNK D_002C2D90;
s32 PvFindSaveVar(s32 arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    FFindSaveVar(sp);
    return arg2 + (M2C_FIELD(sp0, u16 *, 4) + (sp4 * *((M2C_FIELD(sp0, s8 *, 2) * 4) + &D_002C2D90)));
}
}
