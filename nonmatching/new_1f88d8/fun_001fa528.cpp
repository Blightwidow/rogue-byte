typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001FA528 {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ char pad30[0x30];                   /* maybe part of sp20[4]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0xD0];
};                                                  /* size = 0x130 */
#define sp10 (*(s128 *)(sp + 0x010))
#define sp20 (*(s128 *)(sp + 0x020))
s32 ConvertXfVec(M2C_UNK, s32, s128);               /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK LoadRotateMatrix(M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK WakeXf(s8 *, s8 *);                     /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s8 *, M2C_UNK);  /* extern */
M2C_UNK func_001F4BF8(s8 *);                      /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
void func_001FA528(s8 *arg0) {
    s8 sp[0x90] __attribute__((aligned(16)));
    M2C_UNK sp60;
    M2C_UNK temp_a1;
    s128 temp_s0;
    s128 temp_s0_3;
    s128 temp_s1;
    s128 temp_s1_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    s8 *temp_s0_2;
    s8 *temp_s0_4;
    s8 *temp_s1_2;
    s8 *temp_s1_4;
    s8 *temp_v0_5;
    var_s4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        temp_s1 = M2C_FIELD(arg0, s128 *, 0xF0);
        temp_s0 = g_2a2dd0;
        var_s3 = 0;
        s64 vu_1;
        asm volatile("prot3w %0, %1" : "=r"(vu_1) : "r"(temp_s1));
        s64 vu_2;
        asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_s0));
        if ((FFloatsNear__Ffff(temp_s0, temp_s1, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_2, vu_1, 0x38D1B717) != 0)) {
            s64 vu_3;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s1));
            s64 vu_4;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0));
            var_s3 = FFloatsNear__Ffff(vu_4, vu_3, 0x38D1B717) != 0;
        }
        if (var_s3 == 0) {
            temp_s0_2 = M2C_FIELD(arg0, s8 **, 0x58);
            temp_s1_2 = arg0 + 0xF0;
            var_s4 = 1;
            WakeXf(arg0, temp_s0_2);
            temp_v0 = ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0xF0));
            M2C_FIELD(temp_s1_2, s32 *, 4) = 0;
            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_v0));
            M2C_FIELD(temp_s1_2, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0xF0) = 0;
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_s0_2));
            asm volatile("vadd.xyzw vf2, vf1, vf2");
            s32 vu_5;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_5));
            __as__6VECTORG9VU_VECTOR(temp_s0_2 + 0x30, vu_5);
            M2C_FIELD(temp_s0_2, f32 *, 0x3C) = 1.0f;
            temp_v0_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
            M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_2;
            M2C_FIELD(temp_s0_2, s32 *, 0xA4) = temp_v0_2;
        }
        temp_s1_3 = M2C_FIELD(arg0, s128 *, 0x100);
        temp_s0_3 = g_2a2dd0;
        var_s3_2 = 0;
        s64 vu_6;
        asm volatile("prot3w %0, %1" : "=r"(vu_6) : "r"(temp_s1_3));
        s64 vu_7;
        asm volatile("prot3w %0, %1" : "=r"(vu_7) : "r"(temp_s0_3));
        if ((FFloatsNear__Ffff(temp_s0_3, temp_s1_3, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_7, vu_6, 0x38D1B717) != 0)) {
            s64 vu_8;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(temp_s1_3));
            s64 vu_9;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_9) : "r"(0), "r"(temp_s0_3));
            var_s3_2 = FFloatsNear__Ffff(vu_9, vu_8, 0x38D1B717) != 0;
        }
        if (var_s3_2 == 0) {
            temp_s0_4 = M2C_FIELD(arg0, s8 **, 0x5C);
            temp_s1_4 = arg0 + 0x100;
            var_s4 = 1;
            WakeXf(arg0, temp_s0_4);
            temp_v0_3 = ConvertXfVec(0, M2C_FIELD(temp_s0_4, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x100));
            M2C_FIELD(temp_s1_4, s32 *, 4) = 0;
            s64 vu_10;
            asm volatile("por %0, %1, %2" : "=r"(vu_10) : "r"(0), "r"(temp_v0_3));
            temp_a1 = vu_10;
            M2C_FIELD(temp_s1_4, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0x100) = 0;
            LoadRotateMatrix(&sp60, temp_a1);
            asm volatile("lqc2 vf6, (%0)" : : "r"(temp_s0_4));
            asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x70(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf6x");
            asm volatile("vmadday.xyz ACC, vf5, vf6y");
            asm volatile("vmaddz.xyz vf6, vf4, vf6z");
            asm volatile("sqc2 vf6, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x90(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_s0_4));
            asm volatile("vmulax.xyz ACC, vf3, vf1x");
            asm volatile("vmadday.xyz ACC, vf5, vf1y");
            asm volatile("vmaddz.xyz vf1, vf4, vf1z");
            asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_s0_4));
            asm volatile("vmulax.xyz ACC, vf3, vf2x");
            asm volatile("vmadday.xyz ACC, vf5, vf2y");
            asm volatile("vmaddz.xyz vf3, vf4, vf2z");
            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0xb0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, (%0)" : : "r"(temp_s0_4));
            M2C_FIELD(temp_s0_4, s128 *, 0x10) = sp10;
            M2C_FIELD(temp_s0_4, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_s0_4, s128 *, 0x20) = sp20;
            M2C_FIELD(temp_s0_4, s32 *, 0x2C) = 0;
            M2C_FIELD(temp_s0_4, s32 *, 0xC) = 0;
            temp_v0_4 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
            M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_4;
            M2C_FIELD(temp_s0_4, s32 *, 0xA4) = temp_v0_4;
        }
        if (var_s4 != 0) {
            temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *), 0x94)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x90));
            func_001F4BF8(arg0);
        }
    }
}
}
