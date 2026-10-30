typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateRopeSimChain {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0xB0];
};                                                  /* size = 0xC0 */
s32 InvalidateCrvCache(s8 *);
void InvertMatrix4Affine(M2C_UNK *, s32);
void SetRopeSimLength(s8 *, s32, s32, s8 *, f32);
s32 VelocityXfAtPos(s32, M2C_UNK, M2C_UNK);
extern s128 g_2a2da0;
extern f32 g_2dded4;
void UpdateRopeSimChain(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 temp_f1;
    f32 temp_f20;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a1;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s2;
    s8 *temp_a1_2;
    s8 *temp_a3;
    s8 *temp_v0_2;
    s8 *temp_v1_3;
    temp_f20 = g_2dded4;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
    temp_v0 = temp_v1 + 0x40;
    asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(temp_v1));
    asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("vmulax.xyz ACC, vf5, vf3x");
    asm volatile("vmadday.xyz ACC, vf2, vf3y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf3z");
    asm volatile("vmaddw.xyz vf6, vf4, vf0w");
    var_s2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x48), s32 *, 0xE8);
    asm volatile("sqc2 vf6, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0x54)));
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x58);
    asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_1));
    asm volatile("qmtc2.ni %0, vf7" : : "r"(VelocityXfAtPos(M2C_FIELD(arg0, s32 *, 0x40), 0, vu_1)));
    var_a3 = 1;
    asm volatile("sqc2 vf7, (%0)" : : "r"(temp_s0));
    asm volatile("lqc2 vf6, 0x50(%0)" : : "r"(sp));
    if (var_s2 > 1) {
        var_a1 = 0x10;
        asm volatile("qmtc2.ni %0, vf8" : : "r"(temp_f20));
        asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_f20 * 0.5f));
        do {
            temp_v1_2 = var_a1 + M2C_FIELD(arg0, s32 *, 0x58);
            asm volatile("qmtc2.ni %0, vf3" : : "r"(-M2C_FIELD(arg0, f32 *, 0x60)));
            asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v1_2));
            asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
            asm volatile("sqc2 vf8, (%0)" : : "r"(sp));
            asm volatile("vadda.xyzw ACC, vf0, vf2");
            asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
            asm volatile("vadda.xyzw ACC, vf0, vf1");
            asm volatile("vmaddx.xyzw vf4, vf2, vf8x");
            asm volatile("lqc2 vf2, (%0)" : : "r"(var_a1 + M2C_FIELD(arg0, s32 *, 0x54)));
            asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v1_2));
            asm volatile("vadda.xyzw ACC, vf0, vf2");
            asm volatile("vmaddax.xyzw ACC, vf1, vf5x");
            asm volatile("vmaddx.xyzw vf2, vf4, vf5x");
            asm volatile("vsub.xyzw vf2, vf2, vf6");
            asm volatile("vmul.xyz vf1, vf2, vf2");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf3, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("qmtc2.ni %0, vf3" : : "r"(g_2a2da0));
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            if (!(vu_2 < 0.0001f)) {
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf3, vf2, Q");
            }
            asm volatile("vsub.xyzw vf2, vf4, vf7");
            temp_v0_2 = (s8 *)((var_a3 * 4) + M2C_FIELD(arg0, s32 *, 0x5C));
            asm volatile("vmul.xyz vf2, vf2, vf3");
            asm volatile("vaddw.x vf1, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf1, vf2z");
            temp_f1 = M2C_FIELD(temp_v0_2, f32 *, 0) - M2C_FIELD(temp_v0_2, f32 *, -4);
            var_a3 += 1;
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(-vu_3));
            asm volatile("vadda.xyzw ACC, vf0, vf4");
            asm volatile("vmaddx.xyzw vf7, vf3, vf2x");
            asm volatile("qmtc2.ni %0, vf1" : : "r"(fabsf(temp_f1)));
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vadda.xyzw ACC, vf0, vf6");
            asm volatile("vmaddx.xyzw vf6, vf3, vf1x");
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, (%0)" : : "r"(var_a1 + M2C_FIELD(arg0, s32 *, 0x54)));
            asm volatile("sqc2 vf7, (%0)" : : "r"(var_a1 + M2C_FIELD(arg0, s32 *, 0x58)));
            var_a1 += 0x10;
        } while (var_a3 < var_s2);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) == 2) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x44);
        temp_a1 = var_s2 * 0x10;
        temp_v0_3 = temp_a0 + 0x40;
        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(temp_a0));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0_3));
        asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(temp_v0_3));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_v0_3));
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(arg0));
        asm volatile("vmulax.xyz ACC, vf2, vf4x");
        asm volatile("vmadday.xyz ACC, vf3, vf4y");
        asm volatile("vmaddaz.xyz ACC, vf1, vf4z");
        asm volatile("vmaddw.xyz vf2, vf5, vf0w");
        asm volatile("sqc2 vf2, -0x10(%0)" : : "r"(temp_a1 + M2C_FIELD(arg0, s32 *, 0x54)));
        temp_a2 = temp_a1 + M2C_FIELD(arg0, s32 *, 0x54);
        asm volatile("lqc2 vf2, -0x10(%0)" : : "r"(temp_a2));
        asm volatile("lqc2 vf1, -0x20(%0)" : : "r"(temp_a2));
        temp_a3 = (s8 *)((var_s2 * 4) + M2C_FIELD(arg0, s32 *, 0x5C));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
        SetRopeSimLength(arg0, temp_a2, temp_a2, temp_a3, M2C_FIELD(temp_a3, f32 *, -8) + vu_4);
        var_s2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x48), s32 *, 0xE8);
    }
    temp_a1_2 = M2C_FIELD(arg0, s8 **, 0x48);
    temp_v1_3 = M2C_FIELD(temp_a1_2, s8 **, 0xC);
    InvertMatrix4Affine(&sp10, M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s8 *), 0xFC)(temp_a1_2 + M2C_FIELD(temp_v1_3, s16 *, 0xF8), temp_a1_2));
    var_a3_2 = 0;
    if (var_s2 > 0) {
        do {
            temp_v1_4 = var_a3_2 * 0x10;
            var_a3_2 += 1;
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v1_4 + M2C_FIELD(arg0, s32 *, 0x54)));
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf5x");
            asm volatile("vmadday.xyz ACC, vf4, vf5y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
            asm volatile("vmaddw.xyz vf3, vf1, vf0w");
            asm volatile("sqc2 vf3, (%0)" : : "r"(temp_v1_4 + M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x48), s32 *, 0xF4)));
        } while (var_a3_2 < var_s2);
    }
    InvalidateCrvCache(M2C_FIELD(arg0, s8 **, 0x48));
}
}
