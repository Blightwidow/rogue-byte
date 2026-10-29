typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00162050 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0x10];
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0x3C];
};                                                  /* size = 0x70 */

M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 GrfOfStates(s32, s8 *);                       /* extern */
M2C_UNK func_002013D8(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */

s32 func_00162050(s32 arg0) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK sp20;
    s32 sp30;
    s32 temp_s0;

    func_002013D8(&sp20, arg0, 0x1050, 6);
    temp_s0 = GrfOfStates(sp30, sp);
    CRef_Destruct(&sp20);
    return temp_s0;
}

}
