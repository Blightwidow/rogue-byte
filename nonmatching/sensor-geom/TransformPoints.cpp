typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_TransformPoints {};               /* size 0x0 */
void TransformPoints(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s32 var_a2;
    s32 var_a3;
    var_a3 = arg3;
    if (arg1 != 0) {
        asm volatile("lqc2 vf6, (%0)" : : "r"(arg2));
        var_a2 = arg2 + 0x10;
        temp_v0 = var_a3 + (arg1 * 0x10);
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, (%0)" : : "r"(arg0));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg0));
        asm volatile("vcallms 0x120");
        asm volatile("lqc2 vf5, (%0)" : : "r"(var_a2));
loop_2:
        temp_a2 = var_a2 + 0x10;
        asm volatile("vcallms 0xf0");
        asm volatile("vnop");
        asm volatile("sqc2 vf6, (%0)" : : "r"(var_a3));
        temp_a3 = var_a3 + 0x10;
        if (temp_a3 != temp_v0) {
            asm volatile("lqc2 vf6, (%0)" : : "r"(temp_a2));
            var_a2 = temp_a2 + 0x10;
            asm volatile("vcallms 0x120");
            asm volatile("vnop");
            asm volatile("sqc2 vf5, (%0)" : : "r"(temp_a3));
            var_a3 = temp_a3 + 0x10;
            if (var_a3 != temp_v0) {
                asm volatile("lqc2 vf5, (%0)" : : "r"(var_a2));
                goto loop_2;
            }
        }
    }
}
}
