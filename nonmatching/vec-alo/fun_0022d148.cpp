typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0022D148 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ char pad90[0x30];                   /* maybe part of sp80[4]? */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0x30];                   /* maybe part of spC0[4]? */
    /* 0x100 */ s128 sp100;                         /* inferred */
    /* 0x110 */ char pad110[0xB0];
};                                                  /* size = 0x1C0 */
#define sp50 (*(s128 *)(sp + 0x050))
#define sp60 (*(s128 *)(sp + 0x060))
#define sp70 (*(s128 *)(sp + 0x070))
M2C_UNK GetXfLocalRateMatrix(s128 *, s8 *);       /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, s8 *);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, s128 *, s128 *); /* extern */
M2C_UNK memcpy(s128 *, s128 *, M2C_UNK);            /* extern */
M2C_UNK memset(M2C_UNK, M2C_UNK);                   /* extern */
s128 *func_0022D148(s128 *arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x100] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp80;
    s128 spC0;
    s128 sp100;
    s128 *var_a0;
    s128 *var_a0_2;
    s128 *var_s1;
    s128 *var_s2;
    s128 *var_v0;
    s128 *var_v0_2;
    s16 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s8 *temp_a1;
    s8 *var_s3;
    var_s3 = arg1;
    memset(0, 0x40);
    if ((s32)var_s3 != arg2) {
        var_v1 = M2C_FIELD(var_s3, s16 *, 0x98);
loop_2:
        switch (var_v1) {
        case 0:
        case 3:
        case 10:
        case 12:
        case 15:
        case 19:
            break;
        default:
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 16:
        case 17:
        case 18:
            GetXfLocalRateMatrix(&sp40, var_s3);
            temp_a1 = M2C_FIELD(var_s3, s8 **, 0xA0);
            if (temp_a1 != NULL) {
                var_s2 = &sp80;
                __ml__FRC7MATRIX4T0(&spC0, (s128 *)(temp_a1 + 0x40), (s128 *)(sp));
                InvertMatrix4Affine(&sp100, var_s3 + 0x40);
                __ml__FRC7MATRIX4T0(var_s2, &spC0, &sp100);
                var_a0 = &sp40;
                var_v0 = arg0;
                var_v1_2 = 3;
                do {
                    asm volatile("lqc2 vf2, (%0)" : : "r"(var_s2));
                    var_v1_2 -= 1;
                    asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0));
                    var_s2 += 0x10;
                    asm volatile("vadd.xyzw vf1, vf1, vf2");
                    var_v0 += 0x10;
                    asm volatile("sqc2 vf1, (%0)" : : "r"(var_a0));
                    var_a0 += 0x10;
                } while (var_v1_2 >= 0);
                memcpy(arg0, &sp40, 0x40);
            } else {
                var_s1 = &sp80;
                InvertMatrix4Affine(&spC0, var_s3 + 0x40);
                __ml__FRC7MATRIX4T0(var_s1, (s128 *)(sp), &spC0);
                var_a0_2 = &sp40;
                var_v0_2 = arg0;
                var_v1_3 = 3;
                do {
                    asm volatile("lqc2 vf2, (%0)" : : "r"(var_s1));
                    var_v1_3 -= 1;
                    asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0_2));
                    var_s1 += 0x10;
                    asm volatile("vadd.xyzw vf1, vf1, vf2");
                    var_v0_2 += 0x10;
                    asm volatile("sqc2 vf1, (%0)" : : "r"(var_a0_2));
                    var_a0_2 += 0x10;
                } while (var_v1_3 >= 0);
                memcpy(arg0, &sp40, 0x40);
            }
            break;
        }
        var_s3 = M2C_FIELD(var_s3, s8 **, 0xA0);
        if ((s32)var_s3 != arg2) {
            var_v1 = M2C_FIELD(var_s3, s16 *, 0x98);
            goto loop_2;
        }
    }
    if (arg2 != 0) {
        InvertMatrix4Affine(&sp80, (s8 *)(arg2 + 0x40));
        __ml__FRC7MATRIX4T0(&sp40, &sp80, arg0);
        memcpy(arg0, &sp40, 0x40);
    }
    return arg0;
}
}
