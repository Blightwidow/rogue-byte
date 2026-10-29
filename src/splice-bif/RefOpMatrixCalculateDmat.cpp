typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct CRefLocal { s32 pad0; s32 field4; s32 pad8; s32 padC; };
void CRef_CopyConstruct(s32, CRefLocal *);
void CRef_Destruct(CRefLocal *);
void CalculateDmat4(s32, s32, s32);
void SetTag__4CRef4TAGK(CRefLocal *, s32);
s32 RefOpMatrixCalculateDmat(s32 arg0, s32 arg1, s8 *arg2) {
    CRefLocal local __attribute__((aligned(16)));
    SetTag__4CRef4TAGK(&local, 0x1B);
    CalculateDmat4(M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC), local.field4);
    CRef_CopyConstruct(arg0, &local);
    CRef_Destruct(&local);
    return arg0;
}
}
