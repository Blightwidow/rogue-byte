typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetActadjGoal {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK func_0012CF28(s8 *, s8 *);              /* extern */
void GetActadjGoal(s8 *arg0) {
    s32 temp_v0_2;
    s32 temp_v1;
    s8 *temp_a1;
    s8 *temp_v0;
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x1C);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x24)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x20), temp_a1);
        temp_v0 = M2C_FIELD(temp_a1, s8 **, 0x18);
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 8);
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(temp_v0_2));
        asm volatile("vadd.xyzw vf1, vf1, vf2");
        asm volatile("sqc2 vf1, 0xc0(%0)" : : "r"(temp_v0_2));
        temp_v1 = M2C_FIELD(arg0, s32 *, 8);
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(temp_v1));
        asm volatile("vadd.xyzw vf1, vf1, vf2");
        asm volatile("sqc2 vf1, 0xe0(%0)" : : "r"(temp_v1));
        return;
    }
    func_0012CF28(arg0, temp_a1);
}
}
