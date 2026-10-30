typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PredictXfTransformAdjust {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x40];
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ s128 sp100;                         /* inferred */
    /* 0x110 */ s128 sp110;                         /* inferred */
    /* 0x120 */ s128 sp120;                         /* inferred */
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ char pad150[0x30];                  /* maybe part of sp140[4]? */
    /* 0x180 */ s128 sp180;                         /* inferred */
    /* 0x190 */ char pad190[0xE0];
};                                                  /* size = 0x270 */
#define sp110 (*(s128 *)(sp + 0x110))
#define sp120 (*(s128 *)(sp + 0x120))
#define sp130 (*(s128 *)(sp + 0x130))
M2C_UNK PredictXfLocal(s8 *, M2C_UNK *, M2C_UNK *, f32); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(...); /* extern */
M2C_UNK memset(s128 *, M2C_UNK, M2C_UNK);           /* extern */
void PredictXfTransformAdjust(s8 *arg0, s32 arg1, s8 *arg2, s8 *arg3, f32 fparg0) {
    s8 sp[0x140] __attribute__((aligned(16)));
    M2C_UNK sp40;
    s128 sp80;                                      /* compiler-managed */
    s128 sp90;
    s128 spA0;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 spF0;
    s128 sp100;
    s128 sp140;
    s128 sp180;
    s128 *var_a0;
    s128 *var_a1;
    s128 *var_v0;
    s32 var_v1;
    s8 *var_s0;
    if (arg3 != NULL) {
        spC0 = M2C_FIELD(arg3, s128 *, 0);
        spD0 = M2C_FIELD(arg3, s128 *, 0x10);
        spE0 = M2C_FIELD(arg3, s128 *, 0x20);
        spF0 = M2C_FIELD(arg3, s128 *, 0x30);
    } else {
        memset(&spC0, 0, 0x40);
    }
    if (arg2 != NULL) {
        sp80 = M2C_FIELD(arg2, s128 *, 0);
        sp90 = M2C_FIELD(arg2, s128 *, 0x10);
        spA0 = M2C_FIELD(arg2, s128 *, 0x20);
        spB0 = M2C_FIELD(arg2, s128 *, 0x30);
    } else {
        memset(&sp80, 0, 0x40);
        M2C_FIELD(&sp80, f32 *, 0x14) = 1.0f;
        M2C_FIELD(&sp80, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(&sp80, f32 *, 0x28) = 1.0f;
        sp80 = 1.0f;
    }
    var_s0 = arg0;
    if ((s32)var_s0 != arg1) {
        do {
            PredictXfLocal(var_s0, (M2C_UNK *)(sp), &sp40, fparg0);
            __ml__FRC7MATRIX4T0(&sp140, (M2C_UNK *)(sp), &spC0);
            __ml__FRC7MATRIX4T0(&sp180, &sp40, (s128 *) &sp80);
            var_v0 = &sp100;
            var_a1 = &sp180;
            var_a0 = &sp140;
            var_v1 = 3;
loop_9:
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_a0));
            var_v1 -= 1;
            asm volatile("lqc2 vf2, (%0)" : : "r"(var_a1));
            var_a0 += 0x10;
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            var_a1 += 0x10;
            asm volatile("sqc2 vf1, (%0)" : : "r"(var_v0));
            var_v0 += 0x10;
            if (var_v1 >= 0) {
                goto loop_9;
            }
            spE0 = sp120;
            spF0 = sp130;
            spC0 = sp100;
            spD0 = sp110;
            __ml__FRC7MATRIX4T0(&sp100, sp, (s128 *) &sp80, sp110);
            sp80 = sp100;
            sp90 = sp110;
            spA0 = sp120;
            spB0 = sp130;
            var_s0 = M2C_FIELD(var_s0, s8 **, 0xA0);
        } while ((s32)var_s0 != arg1);
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg2, s128 *, 0) = sp80;
        M2C_FIELD(arg2, s128 *, 0x30) = spB0;
        M2C_FIELD(arg2, s128 *, 0x10) = sp90;
        M2C_FIELD(arg2, s128 *, 0x20) = spA0;
    }
    if (arg3 != NULL) {
        M2C_FIELD(arg3, s128 *, 0) = spC0;
        M2C_FIELD(arg3, s128 *, 0x30) = spF0;
        M2C_FIELD(arg3, s128 *, 0x10) = spD0;
        M2C_FIELD(arg3, s128 *, 0x20) = spE0;
    }
}
}
