typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PredictXfLocal {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ char pad70[0xC0];
};                                                  /* size = 0x130 */
#define sp0 (*(s128 *)(sp + 0x000))
#define sp40 (*(s128 *)(sp + 0x040))
#define sp50 (*(s128 *)(sp + 0x050))
M2C_UNK BuildXfAngularRateMatrix(s128 *, s8 *, s8 *, s128); /* extern */
M2C_UNK BuildXfLinearRateMatrix(...); /* extern */
M2C_UNK BuildXfLocalMatrix(s128 *, s8 *, s128);   /* extern */
M2C_UNK BuildXfSpinRateMatrix(s128 *, s8 *, s8 *, s128); /* extern */
s32 FXfKindHasVelocity(s16, s8 *);                /* extern */
s32 GetXfDofValue(s8 *, s8 *);                  /* extern */
M2C_UNK LoadRotateMatrix(s128 *, M2C_UNK);          /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s8 *, s128);     /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
void PredictXfLocal(s8 *arg0, s8 *arg1, s8 *arg2, f32 fparg0) {
    s8 sp[0x90] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp60;
    s128 var_a0;
    s128 var_a1;
    s128 var_v0;
    s128 var_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s8 *temp_a3;
    s8 *temp_v1;
    temp_a3 = M2C_FIELD(arg0, s8 **, 0x90);
    if (temp_a3 != NULL) {
        temp_v1 = M2C_FIELD(temp_a3, s8 **, 0x18);
        M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, s8 *, s128 *, s8 *), 0x2C)(temp_a3 + M2C_FIELD(temp_v1, s16 *, 0x28), sp, &sp10, temp_a3);
        BuildXfLocalMatrix(&sp20, arg0, sp0);
        M2C_FIELD(arg1, s128 *, 0) = sp20;
        M2C_FIELD(arg1, s128 *, 0x10) = sp30;
        M2C_FIELD(arg1, s128 *, 0x20) = sp40;
        M2C_FIELD(arg1, s128 *, 0x30) = sp50;
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x94);
        if (temp_v1_2 < 8) {
            if (temp_v1_2 >= 6) {
                BuildXfAngularRateMatrix(&sp20, arg0, arg1, sp0);
                var_v1 = sp20;
                var_a0 = sp30;
                var_a1 = sp40;
                var_v0 = sp50;
            } else {
                goto block_5;
            }
        } else {
block_5:
            BuildXfLinearRateMatrix(&sp20, arg0, sp10);
            var_v1 = sp20;
            var_a0 = sp30;
            var_a1 = sp40;
            var_v0 = sp50;
        }
        goto block_14;
    }
    if (FXfKindHasVelocity(M2C_FIELD(arg0, s16 *, 0x98), temp_a3) == 0) {
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
        M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
        M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x30);
        memset(arg2, 0, 0x40);
        return;
    }
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x94);
    if (temp_v1_3 < 8) {
        if (temp_v1_3 >= 6) {
            asm volatile("qmtc2.ni %0, vf2" : : "r"(fparg0));
            asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(arg0));
            asm volatile("vmulx.xyzw vf3, vf1, vf2x");
            asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
            LoadRotateMatrix(&sp60, vu_1);
            asm volatile("lqc2 vf4, (%0)" : : "r"(arg0));
            asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(arg0));
            asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
            asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(arg0));
            asm volatile("vmulax.xyz ACC, vf2, vf4x");
            asm volatile("vmadday.xyz ACC, vf3, vf4y");
            asm volatile("vmaddz.xyz vf4, vf1, vf4z");
            asm volatile("vmulax.xyz ACC, vf2, vf5x");
            asm volatile("vmadday.xyz ACC, vf3, vf5y");
            asm volatile("vmaddz.xyz vf5, vf1, vf5z");
            asm volatile("vmulax.xyz ACC, vf2, vf6x");
            asm volatile("vmadday.xyz ACC, vf3, vf6y");
            asm volatile("vmaddz.xyz vf2, vf1, vf6z");
            asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0xb0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0xc0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(sp));
            __as__6VECTORG9VU_VECTOR(arg1 + 0x30, M2C_FIELD(arg0, s128 *, 0x30));
            M2C_FIELD(arg1, s128 *, 0x10) = sp10;
            M2C_FIELD(arg1, s128 *, 0x20) = sp20;
            M2C_FIELD(arg1, s128 *, 0) = sp0;
            M2C_FIELD(arg1, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(arg1, s32 *, 0x2C) = 0;
            M2C_FIELD(arg1, s32 *, 0x1C) = 0;
            M2C_FIELD(arg1, s32 *, 0xC) = 0;
            BuildXfSpinRateMatrix(&sp30, arg0, arg1, M2C_FIELD(arg0, s128 *, 0xB0));
            var_v1 = sp30;
            var_a0 = sp40;
            var_a1 = sp50;
            var_v0 = sp60;
        } else {
            goto block_13;
        }
    } else {
block_13:
        asm volatile("qmtc2.ni %0, vf4" : : "r"(GetXfDofValue(arg0, arg0)));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(fparg0));
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(arg0));
        asm volatile("vadda.xyzw ACC, vf0, vf4");
        asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
        asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
        BuildXfLocalMatrix(&sp10, arg0, vu_2);
        M2C_FIELD(arg1, s128 *, 0x30) = sp40;
        M2C_FIELD(arg1, s128 *, 0x20) = sp30;
        M2C_FIELD(arg1, s128 *, 0) = sp10;
        M2C_FIELD(arg1, s128 *, 0x10) = sp20;
        BuildXfLinearRateMatrix(&sp10, arg0, M2C_FIELD(arg0, s128 *, 0xB0), sp20);
        var_v1 = sp10;
        var_a0 = sp20;
        var_a1 = sp30;
        var_v0 = sp40;
    }
block_14:
    M2C_FIELD(arg2, s128 *, 0) = var_v1;
    M2C_FIELD(arg2, s128 *, 0x30) = var_v0;
    M2C_FIELD(arg2, s128 *, 0x10) = var_a0;
    M2C_FIELD(arg2, s128 *, 0x20) = var_a1;
}
}
