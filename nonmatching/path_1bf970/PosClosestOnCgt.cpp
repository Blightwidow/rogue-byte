typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PosClosestOnCgt {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ char pad10[0x20];
};                                                  /* size = 0x30 */
#define sp0 (*(s128 *)(sp + 0x00))
M2C_UNK ClosestPointOnSegment(M2C_UNK, M2C_UNK, M2C_UNK, s8 *); /* extern */
extern M2C_UNK g_2a2dc0;
s128 PosClosestOnCgt(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    M2C_UNK var_a0;
    M2C_UNK var_a1;
    M2C_UNK var_a2;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(arg1));
    asm volatile("lqc2 vf6, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0)));
    asm volatile("lqc2 vf5, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 4)));
    asm volatile("vsub.xyzw vf1, vf4, vf6");
    asm volatile("vsub.xyzw vf9, vf5, vf6");
    asm volatile("vopmula.xyz ACC, vf1, vf9");
    asm volatile("vopmsub.xyz vf1, vf9, vf1");
    asm volatile("vmove.xyzw vf8, vf6");
    asm volatile("lqc2 vf3, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 8)));
    asm volatile("vmove.xyzw vf7, vf3");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    s64 vu_2;
    asm volatile("pextuw %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(vu_1));
    if (vu_2 > 0.0f) {
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
        var_a0 = vu_3;
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_4));
        var_a1 = vu_4;
        s32 vu_5;
        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_5));
        var_a2 = vu_5;
        goto block_6;
    }
    asm volatile("vsub.xyzw vf1, vf4, vf5");
    asm volatile("vsub.xyzw vf2, vf3, vf5");
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    s32 vu_6;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_6));
    var_a0 = vu_6;
    s32 vu_7;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_7));
    s64 vu_8;
    asm volatile("pextuw %0, %1, %0" : "=r"(vu_8) : "r"(0), "r"(vu_7));
    if (vu_8 > 0.0f) {
        s32 vu_9;
        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_9));
        var_a1 = vu_9;
        s32 vu_10;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_10));
        var_a2 = vu_10;
        goto block_6;
    }
    asm volatile("vsub.xyzw vf1, vf4, vf3");
    asm volatile("vsub.xyzw vf2, vf6, vf3");
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    s32 vu_11;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_11));
    var_a0 = vu_11;
    s32 vu_12;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_12));
    s64 vu_13;
    asm volatile("pextuw %0, %1, %0" : "=r"(vu_13) : "r"(0), "r"(vu_12));
    if (vu_13 > 0.0f) {
        s32 vu_14;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_14));
        var_a1 = vu_14;
        s32 vu_15;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_15));
        var_a2 = vu_15;
block_6:
        ClosestPointOnSegment(var_a0, var_a1, var_a2, sp);
    } else {
        asm volatile("vsub.xyzw vf1, vf7, vf8");
        asm volatile("vsub.xyzw vf2, vf8, vf4");
        asm volatile("vopmula.xyz ACC, vf9, vf1");
        asm volatile("vopmsub.xyz vf1, vf1, vf9");
        asm volatile("vmul.xyz vf2, vf2, vf1");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf3, vf2z");
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        s32 vu_16;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_16));
        s64 vu_17;
        asm volatile("pextuw %0, %1, %0" : "=r"(vu_17) : "r"(0), "r"(vu_16));
        s32 vu_18;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_18));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(vu_18 / vu_17));
        asm volatile("vadda.xyzw ACC, vf0, vf4");
        asm volatile("vmaddx.xyzw vf1, vf1, vf2x");
        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    }
    return sp0;
}
}
