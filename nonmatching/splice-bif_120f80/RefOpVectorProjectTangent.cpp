typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpVectorProjectTangent {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK CRef_ConstructVectorValue(s8 *, s128);
M2C_UNK CRef_CopyConstruct(s32, s8 *);
M2C_UNK CRef_Destruct(s8 *);
s32 RefOpVectorProjectTangent(s32 arg0, s32 arg1, s8 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 fence;
    s32 first = M2C_FIELD(arg2, s32 *, 4);
    s32 second = M2C_FIELD(arg2, s32 *, 0xC);
    asm("lqc2 vf2, (%1)\n\tlqc2 vf3, (%2)" : "=&r"(fence) : "r"(second), "r"(first));
    asm("vmul.xyz vf1, vf3, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\tvmulx.xyzw vf1, vf2, vf1x\n\tvsub.xyzw vf2, vf3, vf1" : "=r"(fence) : "r"(fence));
    s128 result;
    asm("qmfc2.ni %0, vf2" : "=r"(result) : "r"(fence));
    CRef_ConstructVectorValue(sp, result);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
