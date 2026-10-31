typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C3A08 {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ M2C_UNK sp30;                        /* inferred */
    /* 0x30 */ char pad30[0x60];
};                                                  /* size = 0x90 */
M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(M2C_UNK); /* extern */
M2C_UNK GetPathPosFromS(s32, M2C_UNK *, M2C_UNK, f32); /* extern */
extern s32 g_2c0d04;
void func_001C3A08(s32 arg0, s32 arg2, f32 fparg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp30;
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(1);
    GetPathPosFromS(arg0, &sp30, 0, fparg0);
    if (arg2 != 0) {
        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(g_2c0d04));
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf2");
        asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
        asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, (%0)" : : "r"(arg2));
    }
}
}
