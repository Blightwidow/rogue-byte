typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_physics_driver_1f9e70 {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ char pad40[0x30];                   /* maybe part of sp30[4]? */
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0x60];
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ char padF0[0x90];
};                                                  /* size = 0x180 */
#define sp20 (*(s128 *)(sp + 0x020))
#define sp30 (*(s128 *)(sp + 0x030))
s128 ConvertXfVec(M2C_UNK, s32, s128);              /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK LoadRotateMatrix(M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(s128 *); /* extern */
M2C_UNK WakeXf(s8 *, s8 *);                     /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s8 *, M2C_UNK);  /* extern */
M2C_UNK func_001F4BF8(s8 *);                      /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern f32 g_2dded4;
void bevy_physics_driver_1f9e70(s8 *arg0) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    s128 sp10;
    M2C_UNK sp70;
    s128 spD0;
    s128 spE0;
    s128 temp_s0;
    s128 temp_s0_3;
    s128 temp_s0_5;
    s128 temp_s0_6;
    s128 temp_s1;
    s128 temp_s1_2;
    s128 temp_v0;
    s128 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s6;
    s8 *temp_s0_2;
    s8 *temp_s0_4;
    s8 *temp_s3;
    s8 *temp_s4;
    s8 *temp_v0_5;
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        temp_s1 = M2C_FIELD(arg0, s128 *, 0xF0);
        temp_s0 = g_2a2dd0;
        var_s6 = 0;
        temp_s4 = M2C_FIELD(arg0, s8 **, 0x58);
        temp_s3 = M2C_FIELD(arg0, s8 **, 0x5C);
        var_s5 = 0;
        s64 vu_1;
        asm volatile("prot3w %0, %1" : "=r"(vu_1) : "r"(temp_s1));
        s64 vu_2;
        asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_s0));
        if ((FFloatsNear__Ffff(temp_s0, temp_s1, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_2, vu_1, 0x38D1B717) != 0)) {
            s64 vu_3;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s1));
            s64 vu_4;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0));
            var_s5 = FFloatsNear__Ffff(vu_4, vu_3, 0x38D1B717) != 0;
        }
        if (var_s5 == 0) {
            WakeXf(arg0, temp_s4);
            temp_s0_2 = arg0 + 0xF0;
            var_s6 = 1;
            temp_v0 = ConvertXfVec(0, M2C_FIELD(temp_s4, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0xF0));
            M2C_FIELD(temp_s0_2, s32 *, 4) = 0;
            spD0 = temp_v0;
            M2C_FIELD(temp_s0_2, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0xF0) = 0;
            asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s4));
            asm volatile("lqc2 vf2, 0xd0(%0)" : : "r"(sp));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(temp_s4));
        } else {
            asm volatile("vsub.xyzw vf3, vf0, vf0");
            asm volatile("sqc2 vf3, 0xd0(%0)" : : "r"(sp));
        }
        temp_s1_2 = M2C_FIELD(arg0, s128 *, 0x100);
        temp_s0_3 = g_2a2dd0;
        var_s5_2 = 0;
        s64 vu_5;
        asm volatile("prot3w %0, %1" : "=r"(vu_5) : "r"(temp_s1_2));
        s64 vu_6;
        asm volatile("prot3w %0, %1" : "=r"(vu_6) : "r"(temp_s0_3));
        if ((FFloatsNear__Ffff(temp_s0_3, temp_s1_2, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_6, vu_5, 0x38D1B717) != 0)) {
            s64 vu_7;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(temp_s1_2));
            s64 vu_8;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(temp_s0_3));
            var_s5_2 = FFloatsNear__Ffff(vu_8, vu_7, 0x38D1B717) != 0;
        }
        if (var_s5_2 == 0) {
            WakeXf(arg0, temp_s3);
            temp_s0_4 = arg0 + 0x100;
            var_s6 = 1;
            temp_v0_2 = ConvertXfVec(0, M2C_FIELD(temp_s3, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x100));
            M2C_FIELD(temp_s0_4, s32 *, 4) = 0;
            spE0 = temp_v0_2;
            M2C_FIELD(temp_s0_4, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0x100) = 0;
            asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s3));
            asm volatile("lqc2 vf2, 0xe0(%0)" : : "r"(sp));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(temp_s3));
        } else {
            asm volatile("vsub.xyzw vf3, vf0, vf0");
            asm volatile("sqc2 vf3, 0xe0(%0)" : : "r"(sp));
        }
        if (var_s6 != 0) {
            var_s1 = 0;
            func_001F4BF8(arg0);
            temp_s0_5 = g_2a2dd0;
            s64 vu_9;
            asm volatile("prot3w %0, %0" : "=r"(vu_9) : "r"(spD0));
            s64 vu_10;
            asm volatile("prot3w %0, %1" : "=r"(vu_10) : "r"(temp_s0_5));
            if ((FFloatsNear__Ffff(temp_s0_5, spD0, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_10, vu_9, 0x38D1B717) != 0)) {
                s64 vu_11;
                asm volatile("pextuw %0, %1, %0" : "=r"(vu_11) : "r"(0), "r"(spD0));
                s64 vu_12;
                asm volatile("pextuw %0, %1, %2" : "=r"(vu_12) : "r"(0), "r"(temp_s0_5));
                var_s1 = FFloatsNear__Ffff(vu_12, vu_11, 0x38D1B717) != 0;
            }
            if (var_s1 == 0) {
                asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(temp_s4));
                asm volatile("lqc2 vf3, 0xd0(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2dded4 * 0.5f));
                asm volatile("vadda.xyzw ACC, vf0, vf2");
                asm volatile("vmaddx.xyzw vf3, vf3, vf1x");
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                s32 vu_13;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_13));
                __as__6VECTORG9VU_VECTOR(temp_s4 + 0x30, vu_13);
                M2C_FIELD(temp_s4, f32 *, 0x3C) = 1.0f;
                temp_v0_3 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_3;
                M2C_FIELD(temp_s4, s32 *, 0xA4) = temp_v0_3;
            }
            temp_s0_6 = g_2a2dd0;
            var_s1_2 = 0;
            s64 vu_14;
            asm volatile("prot3w %0, %0" : "=r"(vu_14) : "r"(spE0));
            s64 vu_15;
            asm volatile("prot3w %0, %1" : "=r"(vu_15) : "r"(temp_s0_6));
            if ((FFloatsNear__Ffff(temp_s0_6, spE0, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_15, vu_14, 0x38D1B717) != 0)) {
                s64 vu_16;
                asm volatile("pextuw %0, %1, %0" : "=r"(vu_16) : "r"(0), "r"(spE0));
                s64 vu_17;
                asm volatile("pextuw %0, %1, %2" : "=r"(vu_17) : "r"(0), "r"(temp_s0_6));
                var_s1_2 = FFloatsNear__Ffff(vu_17, vu_16, 0x38D1B717) != 0;
            }
            if (var_s1_2 == 0) {
                asm volatile("lqc2 vf2, 0xe0(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2dded4 * 0.5f));
                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                s32 vu_18;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_18));
                LoadRotateMatrix(&sp70, vu_18);
                asm volatile("lqc2 vf5, (%0)" : : "r"(temp_s3));
                asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x80(%0)" : : "r"(sp));
                asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf3, vf5x");
                asm volatile("vmadday.xyz ACC, vf6, vf5y");
                asm volatile("vmaddz.xyz vf5, vf4, vf5z");
                asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf5, 0xa0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_s3));
                asm volatile("vmulax.xyz ACC, vf3, vf2x");
                asm volatile("vmadday.xyz ACC, vf6, vf2y");
                asm volatile("vmaddz.xyz vf2, vf4, vf2z");
                asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, 0xb0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_s3));
                asm volatile("vmulax.xyz ACC, vf3, vf1x");
                asm volatile("vmadday.xyz ACC, vf6, vf1y");
                asm volatile("vmaddz.xyz vf3, vf4, vf1z");
                asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0xc0(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
                NormalizeRotateMatrix3__FP7MATRIX3(&sp10);
                M2C_FIELD(temp_s3, s128 *, 0) = sp10;
                M2C_FIELD(temp_s3, s128 *, 0x10) = sp20;
                M2C_FIELD(temp_s3, s32 *, 0x1C) = 0;
                M2C_FIELD(temp_s3, s128 *, 0x20) = sp30;
                M2C_FIELD(temp_s3, s32 *, 0x2C) = 0;
                M2C_FIELD(temp_s3, s32 *, 0xC) = 0;
                temp_v0_4 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_4;
                M2C_FIELD(temp_s3, s32 *, 0xA4) = temp_v0_4;
            }
            temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *), 0x94)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x90));
        }
    }
}
}
