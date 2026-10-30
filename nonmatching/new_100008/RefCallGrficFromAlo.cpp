typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefCallGrficFromAlo {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x38];
};                                                  /* size = 0x50 */
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK CRef_SetS32(s8 *, s32);                   /* extern */
s32 GrficFromAlo(s32, s32);                         /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(s8 *, M2C_UNK, s32, s32 *, s32 *); /* extern */
s32 RefCallGrficFromAlo(s32 arg0, s32 arg1, s32 arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    sp10 = 0x1011;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 1, arg3, &sp10, &sp14);
    CRef_SetS32(sp, GrficFromAlo(arg1, sp14));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
