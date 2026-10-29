typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AttachCyl_GetParam {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 PosLoWorld(s128);                               /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
void AttachCyl_GetParam(s8 *arg0, s8 *arg1, f32 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK temp_v0;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(*M2C_FIELD(arg1, s128 **, 0x218))));
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf1, vf2");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    s64 vu_2;
    asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_v0));
    *arg2 = atan2f(vu_2, temp_v0) * M2C_FIELD(arg0, f32 *, 0x10C);
}
}
