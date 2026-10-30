typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EnsureOptionClq {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x40];
};                                                  /* size = 0x50 */

M2C_UNK CRef_ConstructClq(M2C_UNK *, s32);          /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK RefEnsureOption__FP5BASICiP4CRef(M2C_UNK *, s32, s32, M2C_UNK *); /* extern */

void EnsureOptionClq(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x20] __attribute__((aligned(16)));
#define sp10 (*(M2C_UNK *)(sp + 0x10))

    CRef_ConstructClq((M2C_UNK *)(sp), arg2);
    RefEnsureOption__FP5BASICiP4CRef(&sp10, arg0, arg1, (M2C_UNK *)(sp));
    CRef_Destruct(&sp10);
    CRef_Destruct((M2C_UNK *)(sp));
}

}
