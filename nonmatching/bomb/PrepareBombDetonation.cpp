typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PrepareBombDetonation {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0xA0];
};                                                  /* size = 0xD0 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp20 (*(s128 *)(sp + 0x20))
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s8 *, s128, s128); /* extern */
M2C_UNK BuildRotateVectorsMatrix(s8 *, s128, M2C_UNK); /* extern */
s128 *PmatLoWorld(s8 *);                          /* extern */
extern s128 g_2a2dc0;
void PrepareBombDetonation(s8 *arg0, s128 arg1, s32 arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK temp_s2;
    s128 *temp_v0;
    s128 *temp_v0_2;
    s128 var_a1;
    s32 temp_v1_3;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg2));
    temp_s2 = vu_1;
    if (M2C_FIELD(arg0, s32 *, 0x174) == 0) {
        M2C_FIELD(arg0, s128 *, 0x180) = arg1;
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(arg0, s32 *, 0x174) = 1;
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(arg0, s128 *, 0x1C0) = M2C_FIELD(temp_v1, s128 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x170);
        M2C_FIELD(arg0, s128 *, 0x1D0) = M2C_FIELD(temp_v1_2, s128 (**)(s8 *), 0x114)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x110));
        switch (temp_v1_3) {                        /* irregular */
        case 0:
            var_a1 = M2C_FIELD(PmatLoWorld(arg0), s128 *, 0x20);
block_13:
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s2));
            BuildRotateVectorsMatrix(sp, var_a1, vu_2);
            temp_v0 = PmatLoWorld(arg0);
            asm volatile("lqc2 vf4, (%0)" : : "r"(temp_v0));
            asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf4x");
            asm volatile("vmadday.xyz ACC, vf6, vf4y");
            asm volatile("vmaddz.xyz vf4, vf5, vf4z");
            asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf3, vf2x");
            asm volatile("vmadday.xyz ACC, vf6, vf2y");
            asm volatile("vmaddz.xyz vf2, vf5, vf2z");
            asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf3, vf1x");
            asm volatile("vmadday.xyz ACC, vf6, vf1y");
            asm volatile("vmaddz.xyz vf3, vf5, vf1z");
            asm volatile("sqc2 vf4, 0x190(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf3, 0x1b0(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf2, 0x1a0(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf3, 0x80(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
            break;
        case 1:
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, M2C_FIELD(arg0, s128 *, 0x1C0), g_2a2dc0);
            M2C_FIELD(arg0, s128 *, 0x190) = sp0;
            M2C_FIELD(arg0, s128 *, 0x1B0) = sp20;
            M2C_FIELD(arg0, s128 *, 0x1A0) = sp10;
            break;
        case 2:
            var_a1 = *PmatLoWorld(arg0);
            goto block_13;
        case 3:
            temp_v0_2 = PmatLoWorld(arg0);
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) M2C_FIELD(temp_v0_2, s128 *, 0);
            M2C_FIELD(arg0, s128 *, 0x1A0) = (s128) M2C_FIELD(temp_v0_2, s128 *, 0x10);
            M2C_FIELD(arg0, s128 *, 0x1B0) = (s128) M2C_FIELD(temp_v0_2, s128 *, 0x20);
            break;
        }
    }
}
}
