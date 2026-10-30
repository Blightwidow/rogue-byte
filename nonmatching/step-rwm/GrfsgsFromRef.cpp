typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GrfsgsFromRef {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0x10];
    /* 0x50 */ s32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x3C];
};                                                  /* size = 0x90 */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 GrfsgsFromAsgs(s32, s8 *);                    /* extern */
M2C_UNK func_002013D8(M2C_UNK *, s32, M2C_UNK, M2C_UNK, s32 *, s8 *); /* extern */
s32 GrfsgsFromRef(s32 arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    M2C_UNK sp40;
    s32 sp50;
    s32 temp_s0;
    func_002013D8(&sp40, arg0, 0x1010, 0x10, &sp50, sp);
    temp_s0 = GrfsgsFromAsgs(sp50, sp);
    CRef_Destruct(&sp40);
    return temp_s0;
}
}
