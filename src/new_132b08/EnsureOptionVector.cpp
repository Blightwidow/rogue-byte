typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void CRef_ConstructVectorValue(s8 *, s128);
void CRef_Destruct(s8 *);
void RefEnsureOption__FP5BASICiP4CRef(s8 *, s32, s32, s8 *);

void EnsureOptionVector(s32 arg0, s32 arg1, s128 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 sp10[0x10] __attribute__((aligned(16)));

    CRef_ConstructVectorValue(sp, arg2);
    RefEnsureOption__FP5BASICiP4CRef(sp10, arg0, arg1, sp);
    CRef_Destruct(sp10);
    CRef_Destruct(sp);
}

}
