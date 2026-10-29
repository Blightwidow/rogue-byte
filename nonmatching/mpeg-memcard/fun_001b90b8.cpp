typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B90B8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 func_00204E38(s8 *, s8 *, f32);             /* extern */
void func_001B90B8(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_v1;
    s8 *temp_a1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1840);
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        temp_a1 = M2C_FIELD(arg0, s8 **, 0x1030);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C))));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf3, vf1x");
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
        M2C_FIELD(arg0, f32 *, 0x180) = 1.0f;
    }
}
}
