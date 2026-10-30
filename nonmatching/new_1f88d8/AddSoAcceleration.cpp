typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddSoAcceleration {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 ConvertXfVec(void);      /* extern */
s32 FXfKindDynamic(s8 *);                            /* extern */
void AddSoAcceleration(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK temp_a2;
    M2C_UNK temp_s1;
    s8 *temp_s0;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    temp_s1 = vu_1;
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s1));
    temp_a2 = vu_2;
    if (FXfKindDynamic(arg0) != 0) {
        temp_s0 = M2C_FIELD(arg0, s8 **, 0x58);
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(ConvertXfVec()));
        asm volatile("vadd.xyzw vf1, vf2, vf3");
        asm volatile("sqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
    }
}
}
